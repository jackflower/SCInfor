//  ________________________________
// | Map.cpp - class implementation |
// | Jack Flower October 2012       |
// |________________________________|
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Map.h"
#include "../ResourceManager/CResourceManager.h"
#include "../Rendering/Displayable/Displayable.h"
#include "../Rendering/Drawable/CDrawableManager.h"
#include "../Rendering/Drawable/Layers.h"
#include "../Weather/CWeather.h"
#include "../Utilities/StringUtils/StringUtils.h"

using namespace rapidxml;
using namespace resource;
using namespace mapengine;
using namespace rendering::displayable;
using namespace weather;
using namespace stringutils;

namespace mapengine
{
	RTTI_IMPL(Map, IResource);

	//Konstruktor
	Map::Map()
	:
		m_map_filename(""),
		m_map_header(NULL),
		m_size(0,0),
		m_view_rectangle(0,0,0,0),
		p_fields(NULL),
		m_map_tile_types(NULL),
		m_map_object_types(NULL),
		m_map_object_descriptors(NULL),
		m_use_wind(false),
		m_max_living_monsters(MAX_MONSTERS_DEFAULT),
		str_data()
	{
		fprintf(stderr, "Map::Map()\n");
	}

	//Konstruktor kopiujący
	Map::Map(const Map & MapCopy)
	:
		m_map_filename(MapCopy.m_map_filename),
		m_map_header(MapCopy.m_map_header),
		m_size(MapCopy.m_size),
		m_view_rectangle(MapCopy.m_view_rectangle),
		p_fields(MapCopy.p_fields),
		m_map_tile_types(MapCopy.m_map_tile_types),
		m_map_object_types(MapCopy.m_map_object_types),
		m_map_object_descriptors(MapCopy.m_map_object_descriptors),
		m_use_wind(MapCopy.m_use_wind),
		m_max_living_monsters(MapCopy.m_max_living_monsters),
		str_data(MapCopy.str_data)
	{
		fprintf(stderr, "Map::Map(const Map& CMapCopy)\n");
	}

	//Destruktor
	Map::~Map(void)
	{
		m_map_filename = "";
		m_map_header = NULL;
		m_size.x = 0;
		m_size.y = 0;
		//m_view_rectangle
		//p_map_physical_types
		//p_map_physical_descriptors
		p_fields = NULL;
		//m_map_tile_types
		//m_map_object_types
		//m_map_object_descriptors
		m_use_wind = false;
		m_max_living_monsters = MAX_MONSTERS_DEFAULT;
		str_data = "";

		fprintf(stderr, "Map::~Map(void)\n");
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string Map::getType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniająca zasób - implementacje w klasach pochodnych
	void Map::drop()
	{
		fprintf(stderr, "Map::drop()\n");
		
		size_t tileCount = p_fields->size();
		for(size_t i = 0; i < tileCount; i++)
		{
			delete (*p_fields)[i];
			(*p_fields)[i]=NULL;
		}
		
		p_fields->clear();
		delete p_fields;
		delete m_map_header;
		ClearTiles();
		ClearMapObjects();
		//ClearDoodahs();
		delete this;
	}

	//Metoda rozmieszcza na mapie obiekty wczytane z pliku
	void Map::respawnMapObjects(bool load_complete_map)
	{
		//póki co, przy wywołaniu metody flagę należy ustawić na true
        for (unsigned int i = 0; i < m_map_object_descriptors.size(); i++)
        {
            if (load_complete_map)
                m_map_object_descriptors[i]->create();
        }
	}

	//Metoda ładująca dane
	bool Map::load(const std::string &filename)
	{
		fprintf(stderr, "map %s loaded...\n", filename.c_str());
		//wszystkie pliki xml z mapami - mają nagłówek root <map>
		CXml xml(filename, "map" );
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml
	bool Map::load(CXml &xml)
	{
		m_map_filename = xml.GetFilename();				//nazwa pliku xml mapy
		p_fields = new std::vector<Tile*>();			//inicjujemy wskaźnik na wektor wskaźników do obiektów klasy Tile - kafli
        m_map_header = new MapHeader();					//tworzymy nagłówek mapy

		//konfiguracja mapy - lokacji
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "map_header_config"))
		{
			//wypełniamy danymi strukturę opisującą mapę

			//sprawdzamy, czy wersja mapy jest poprawna
			m_map_header->m_map_version = xml.GetInt(node, "version" );
			if(m_map_header->m_map_version != CURRENT_MAP_VERSION)
			{
				fprintf(stderr, "Invalid map version (%d, expected %d) for map %s", m_map_header->m_map_version, CURRENT_MAP_VERSION, m_map_filename.c_str());
				return false;
			}

			//odczyt z pliku xml rozmiaru mapy w kaflach
			m_map_header->m_map_width_in_tile = xml.GetInt(node, "width" );
			m_map_header->m_map_height_in_tile = xml.GetInt(node, "height" );

			//przypisanie rozmiaru do wektora z rozmiarem mapy
			m_size.x = m_map_header->m_map_width_in_tile;
			m_size.y = m_map_header->m_map_height_in_tile;

			//maksymalna ilosc zywych potworow - jeśli nie odczytano z xml - default
			m_max_living_monsters = xml.GetInt(node, "max_living_monsters" );

			if(m_max_living_monsters < 0)//kara za próbę wpisania ujemnej liczby potworów
				m_max_living_monsters = MAX_MONSTERS_DEFAULT;
		}
		else
		{
			fprintf(stderr, "error map loading... for map filename:  %s\n", xml.GetFilename().c_str());
			return false;
		}

		//ładowanie danych dla zjawisk pogodowych
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "weather_data"))
		{
			std::string filename = xml.GetString(node, "weather_data_filename"); 
			gWeather.load(filename);
			//po załadowaniu pogody, przekazuję flagę do mapy, czy na danej mapie jest wiatr...
			m_use_wind = gWeather.getUseWind();
		}

		//typy fabryczne kafli używanych na mapie
		MapTileType *p_map_tile_type;//wskaźnik na obiekt klasy - opakowanie informacji o kaflu
		
		for (xml_node<> *node = xml.GetChild(xml.GetRootNode(),"tiletype"); node; node=xml.GetSibling(node,"tiletype"))
		{
			p_map_tile_type = new MapTileType();

			p_map_tile_type->setCode(xml.GetString(node,"code"));
			p_map_tile_type->setImageFileName(xml.GetString(node,"image"));
			p_map_tile_type->setImageNumberInAtlas(xml.GetInt(node,"index"));

			if(gResourceManager.LoadTexture(p_map_tile_type->getImageFileName()) == false)
			{
				fprintf(stderr, "Cannot load tile image file: %s", p_map_tile_type->getImageFileName().c_str());
				ClearTiles();
				delete p_map_tile_type;
				return false;
				//uwaga - w takim wypadku, reszta obiektów mapy nie zostanie załadowana
			}
			m_map_tile_types.push_back(p_map_tile_type);
		}

        //rozmieszczenie kafli
        if(xml_node<> *node = xml.GetChild(xml.GetRootNode(),"tiles"))//odczytuję do węzła tablicę kafli
		{
			const std::string &cdata = xml.GetString(node);	//odczytany łańcuch zawierający tablicę kafli
			std::stringstream ss(cdata);					//przekazanie tablicy kafli do strumienia
			//obliczamy ilość kafli, które należy wygenerować na mapie
			int tilesNum = m_map_header->m_map_width_in_tile *  m_map_header->m_map_height_in_tile;
			
			for(int i = 0; i < tilesNum; i++)
			{
				ss >> str_data;								//strumień przekazuje dane z tablicy kafli
				Tile * tile = new Tile(str_data);			//na podstawie tych danych tworzony jest kafel
				int imageIndex = getTileTypeIndex(str_data);//indeks obrazu, gdyby ładowania miało miejsce z atlasu

				//inicjujemy kafel danymi
				tile->initializeTile(m_map_tile_types[imageIndex]->getImageFileName(), m_map_tile_types[imageIndex]->getImageNumberInAtlas());
				//pozycja kafla względem tablicy mapy w pliku xml
				tile->setPosition((i % m_map_header->m_map_width_in_tile) + 0.5f, (i/m_map_header->m_map_width_in_tile) + 0.5f);
				//zamiana pozycji na współrzędne świata
				tile->setPosition(tile->getPosition().x * TILE_SIZE, tile->getPosition().y * TILE_SIZE);
				//atrapa - widoczne - docelowo po załadowaniu mapy, wywoływana metoda wyświetlająca kafle w oku kamery
				tile->setVisible(true);
				//wstawianie gotowego kafle do wektora
				p_fields->push_back(tile);
			}
		}
		else
		{
			//fprintf(stderr, "failed to load tiles for map %s", p_map_tile_type->GetImageFileName().c_str());
			return false;
		}

		//typy fabryczne dla physicali na danej mapie
		MapObjectType* p_map_object_type;

		for (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "objtype"); node; node = xml.GetSibling(node, "objtype"))
		{
			str_data = xml.GetString(node, "file");
			if(gResourceManager.LoadPhysicalTemplate(str_data) == false)
			{
				fprintf(stderr, "Cannot load object template file: %s", str_data.c_str());
				return false;
			}
			p_map_object_type = new MapObjectType();
			p_map_object_type->setCode(xml.GetString(node, "code"));
			p_map_object_type->setTemplate(gResourceManager.GetPhysicalTemplate(str_data));
			m_map_object_types.push_back(p_map_object_type);
        }

		//physical's (potwory, drzewka, domki, to co potrafimy utworzyć)
		MapObjectDescriptor *p_map_object;
		for (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "obj"); node; node = xml.GetSibling(node, "obj"))
		{
			str_data = xml.GetString(node, "code");
			int i = getMapObjectTypeIndex(str_data);//pobieramy indeks wzorca fabrycznego na podstawie nazwy
			if (i < 0)			//jeśli nie ma wzorców fabrycznych
				return false;	//wychodzimy z pętli
			p_map_object = new MapObjectDescriptor();

			p_map_object->setCode(str_data);//nazwa wzorca (fabryczna)
			p_map_object->setName(xml.GetString(node, "name"));//nazwa obiektu
			p_map_object->setXPosition(xml.GetFloat(node, "x"));
			p_map_object->setYPosition(xml.GetFloat(node, "y"));
			p_map_object->setRotationBody(xml.GetFloat(node, "rotation_body"));
			p_map_object->setRotationHead(xml.GetFloat(node, "rotation_head"));
			p_map_object->setSmooth(xml.GetBool(node, "smooth"));
			p_map_object->setTemplate(m_map_object_types[i]->getTemplate());
			//wstawiamy do kontenera opakowania danych do utworzenia physical's
			m_map_object_descriptors.push_back(p_map_object);
		}
        return true;//jeśli pomyślnie zostały załadowane dane - zwracamy true
	}

	//Metoda usuwa z wektora wskaźniki na obiekty klasy MapTileType i dane pod tymi wskaźnikami
	void Map::ClearTiles()
	{
		for(unsigned int i=0;i<m_map_tile_types.size();i++)
		{
     		delete m_map_tile_types[i];
		}
        
		m_map_tile_types.clear();
	}

	//Metoda usuwa z wektora wskaźniki na obiekty klasy MapObjectDescriptor i dane pod tymi wskaźnikami
	void Map::ClearMapObjects()
	{
		//obiekty
		for (unsigned i = 0; i < m_map_object_descriptors.size(); i++)
			delete m_map_object_descriptors[i];
		m_map_object_descriptors.clear();
	}

	//Metoda zwraca indeks wzorca na podstawie nazwy
	int Map::getMapObjectTypeIndex(const std::string &map_object_type_name)
	{
		for (unsigned int i = 0; i < m_map_object_types.size(); i++)
			if (m_map_object_types[i]->getCode() == map_object_type_name)
				return i;
		// zwraca -1, wiec to chyba nie jest niezbedne?
		// tego nie analizować, ja Jack Flower - męczyłem się
		// i nawet nie pamiętam, czy ten temat "zamiotłem"?
		fprintf(stderr, "failed to find object template code %s\n",map_object_type_name.c_str());
		return -1;
	}

	//Metoda zwraca na podstawie nazwy indeks kafla w tablicy
    int Map::getTileTypeIndex(const std::string &map_tile_type_name)
	{
        for (unsigned int i = 0; i < m_map_tile_types.size(); i++)
			if (m_map_tile_types[i]->getCode() == map_tile_type_name)
                return i;
        fprintf(stderr, "failed to find image code %s\n",map_tile_type_name.c_str());
        return 0;
    }

	//Metoda zwraca nazwę pliku z mapą
	const std::string& Map::getFilename()
	{
		return m_map_filename;
	}

	//Metoda zwraca wektor z rozmiarem mapy w kaflach
	sf::Vector2<int> Map::getSize()
	{
		return m_size;
	}

	//Metoda zwraca wersję mapy
	int Map::getVersion()
	{
		return m_map_header->m_map_version;
	}
	
	//Metoda zwraca flagę, czy na mapie będzie generowany wiatr
	const bool Map::getUseWind() const
	{
		return m_use_wind;
	}

	//Metoda ustawia flagę, czy na mapie będzie generowany wiatr
	void Map::setUseWind(bool use_wind)
	{
		m_use_wind = use_wind;
	}

	//Metoda zwraca maksymalną ilość powtorów żyjących na mapie
	const int Map::getMaxLivingMonsters() const
	{
		return m_max_living_monsters; 
	}

	//Metoda zapisuje mapę do pliku
	bool Map::save(const std::string & filename)
	{
        // plik tymczasowy, strumień, do którego przekazywana jest
		// zserializoana postać danych, która zostaną zapisane
		// w pliku xml, reprezentującycm mapę, poziom, świat, etc...
		std::stringstream serialized_string; //serialized object
        serialize(serialized_string);

		std::fstream file;
		file.open(filename.c_str(),std::ios::out);
		if(file.good())
		{
			file << serialized_string.str();
			file.close();
			fprintf(stderr, "map saved to file %s\n", filename.c_str());
			return true;
		}
		fprintf(stderr, "failed to save map file %s\n",filename.c_str());
		return false;
	}

	//Metoda serializuje obiekt
	void Map::serialize(std::stringstream &serialized_object)
	{
		//in xml description
		serialized_object << "<!--mapa zapisana w pliku xml - wezel root = map-->" << "\n";
        serialized_object << "<map>\n";

		//in xml description
		serialized_object << "\t" << "<!--wersja mapy-->" << "\n";
		serialized_object << "\t" << "<!--szerokosc mapy w kaflach-->" << "\n";
		serialized_object << "\t" << "<!--wysokosc mapy w kaflach-->" << "\n";
		serialized_object << "\t" << "<!--ilosc potworow  na mapie-->" << "\n";

		//in xml description
		serialized_object
			<< "\t<map_header_config\n\t\t"
			<< "version = \""	<< m_map_header->m_map_version			<< "\"\n\t\t"
			<< "width = \""		<< m_map_header->m_map_width_in_tile	<< "\"\n\t\t"
			<< "height = \""	<< m_map_header->m_map_height_in_tile	<< "\"\n\t\t"
			<< "max_living_monsters = \"" << m_max_living_monsters		<< "\"\n"
			<< "\t/>\n";
		serialized_object << "\n";

		//in xml description
		serialized_object << "\t" << "<!--plik z szablonem konfiguracyjmym zjawisk pogodowych-->" << "\n";
		serialized_object
			<< "\t<weather_data\n\t\t"
			<< "weather_data_filename = \"" << gWeather.getClimateFileName()
			<< "\"\n\t/>\n";
		serialized_object << "\n";

		//typy kafli używanych na mapie
		//in xml description
		serialized_object << "\t" << "<!--typy wzorcow kafli dostepnych na mapie-->" << "\n";
		serialized_object << "\t" << "<!--code unikalna nazwa wzorca kafla -->" << "\n";
		serialized_object << "\t" << "<!--image - nazwa pliku z tekstura kafla-->" << "\n";
		for (unsigned int i = 0; i < m_map_tile_types.size(); i++)
		{
			serialized_object
				<< "\t<tiletype code = \""
				<< m_map_tile_types[i]->getCode()
				<< "\" image = \""
				<< m_map_tile_types[i]->getImageFileName()
				<< "\"/>\n";
		}
		serialized_object << "\n";
        
		//kafle
		serialized_object << "\t<tiles>";
        for (unsigned int i = 0; i < p_fields->size(); i++)
		{
			if (i % getSize().x == 0)
				serialized_object << "\n\t\t";
			serialized_object << p_fields->at(i)->getCode() << " ";
		}
        serialized_object<< "\n\t</tiles>\n";
		serialized_object << "\n";
        
		//typy wzorców physical's dostępnych na mapie-->
		//in xml description
		serialized_object << "\t" << "<!--typy wzorcow physical's dostepnych na mapie-->" << "\n";
		serialized_object << "\t" << "<!--code - nazwa wzorca-->" << "\n";
		serialized_object << "\t" << "<!--file - nazwa pliku xml-->" << "\n";
        for (unsigned int i = 0; i < m_map_object_types.size(); i++){
			if (m_map_object_types[i]->getTemplate())
				serialized_object
					<< "\t<objtype code = \""
					<< m_map_object_types[i]->getCode()
					<< "\" file = \""
					<< m_map_object_types[i]->getTemplate()->getFilename()
					<< "\"/>\n";
            else
                fprintf(stderr, "ERROR: null objtype template pointer @ Map::Serialize!\n");
        }
		serialized_object << "\n";

		//obiekty - physical's
		//in xml description
		serialized_object << "\t" << "<!--obiekty umieszczone na mapie - physicals-->" << "\n";
		serialized_object << "\t" << "<!--code - nazwa wzorca dla obiektu na mapie-->" << "\n";
		serialized_object << "\t" << "<!--name - nazwa obiektu na mapie-->" << "\n";
		serialized_object << "\t" << "<!--x - wspolrzedna x pozycji obiektu na mapie-->" << "\n";
		serialized_object << "\t" << "<!--y - wspolrzedna y pozycji obiektu na mapie-->" << "\n";
		serialized_object << "\t" << "<!--rotation_body - wartosc rotacji poczatkowej obiektu na mapie body-->" << "\n";
		serialized_object << "\t" << "<!--rotation_head - wartosc rotacji poczatkowej obiektu na mapie head-->" << "\n";
		serialized_object << "\t" << "<!--smooth - flaga filtru graficznego smooth obiektu na mapie-->" << "\n";
        for (unsigned int i = 0; i < m_map_object_descriptors.size(); i++)
		{
			serialized_object
				<< "\t<obj code = \""		<< m_map_object_descriptors[i]->getCode()
				<< "\" name = \""			<< m_map_object_descriptors[i]->getName()
				<< "\" x = \""				<< m_map_object_descriptors[i]->getXPosition()
				<< "\" y = \""				<< m_map_object_descriptors[i]->getYPosition()
				<< "\" rotation_body = \""	<< m_map_object_descriptors[i]->getRotationBody()
				<< "\" rotation_head = \""	<< m_map_object_descriptors[i]->getRotationHead()
				<< "\" smooth = \""			<< BoolToString(m_map_object_descriptors[i]->getSmooth())
				<< "\"/>\n";


			//param - zupełnie mi obcy obszar wiedzy...
			//z czym to jeść...?

            //if (m_map_object_descriptors[i]->param != NULL)
			//{
            //    out << ">\n";
			//if (m_map_object_descriptors[i]->GetTemplate())
            //        m_map_object_descriptors[i]->GetTemplate()->SerializeParam(out, mMapObjectDescriptors[i]->param, 1);
            //    else
            //        fprintf(stderr, "ERROR: null object descriptor's template pointer @ Map::Serialize!\n");
            //    out << "\t</obj>\n";
            //}
			//else 
			//{
            //    out << "/>\n";
            //}
        }

        // regiony
        /*  <region name="exit" x="6.0" y="43.5">
  	        <next-map>data/maps/level2.xml</next-map>
  	        <next-map-region>entry</next-map-region>
            </region> */
        //for (unsigned int i = 0; i < mRegionDescriptors.size(); i++)
		//{
        //    mRegionDescriptors[i]->Serialize(out, 1);
        //}

		//nad tym ewentualnie mogę popracować...będzie niekoniecnzie wygodnie
		//z kolejnością w pliku xml, ale za to będzie produkcja...
        // doodahy
        // <sprite out="data/maps/doodahs/tree2.png"           x="0.27" y="40.8" z="foreground" scale="1.4" rot="35" />
        //for (unsigned int i = 0; i < mDoodahDescriptors.size(); i++)
		//{
        //    out << "\t<sprite file=\"" << mDoodahDescriptors[i]->file << "\" x=\"" << mDoodahDescriptors[i]->x
        //        << "\" y=\"" << mDoodahDescriptors[i]->y << "\" z=\""
        //        << (mDoodahDescriptors[i]->zindex == Z_MAPSPRITE_FG ? "foreground" : "background")
        //        << "\" scale=\"" << mDoodahDescriptors[i]->scale << "\" rot=\"" << mDoodahDescriptors[i]->rotation << "\"/>\n";
		//}
        serialized_object << "</map>";
		serialized_object << "\n";
	}
} //namespace mapengine
