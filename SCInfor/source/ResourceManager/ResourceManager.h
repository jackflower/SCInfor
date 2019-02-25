//  ____________________________________________
// | ResourceManager.h - class definition       |
// | Jack Flower - September 2012               |
// |____________________________________________|
//

#ifndef H_RESOURCE_MANAGER_JACK
#define H_RESOURCE_MANAGER_JACK

#include "../Utilities/Singleton/CSingleton.h"
#include "Resource.h"
#include <map>
#include <string>

///
///Forward declarations
///
namespace xml
{
	class CXml;
}

///
///Forward declarations
///
namespace factory
{
	class PhysicalTemplate;
	class ActorTemplate;
	class RobotTemplate;
	class EnemyTemplate;
	class PlayerTemplate;
	class MonsterTemplate;
	class FloraTemplate;
	class FuelTankTemplate;
	class EnergyTankTemplate;
	class FuelBarTemplate;
	class BatteryTemplate;
	class SolarBatteryTemplate;
	class AirconditioningTemplate;
	class ThermalInsulationTemplate;
	class VentilatorTemplate;
	class WindTurbineTemplate;
	class SolarCellTemplate;
	class WindPowerStationTemplate;
	class WindPowerStationMultipledTemplate;
	class MapPhysicalTemplate;
	class GroundWorkTemplate;
	class PhysicalInfoTemplate;
	class InformationTemplate;
	class PresentationTemplate;
	class PowerRelayStationTemplate;
	class CommunicationTemplate;
	class SlotsRateTemplate;
	class GroundTemplate;
	class AmmoTemplate;
	class GunTemplate;
};

///
///Forward declarations
///
namespace resource
{
	class RTexture;	//opakowanie sf::Texture 
	class Music; //opakowanie sf::Music
	class Sound; //opakowanie sf::SoundBuffer
	class Font;	//opakowanie sf::Font
}

namespace mapengine
{
	class Map;
	class Ground;
}

namespace information
{
	class Information;
	namespace presentation
	{
		class Presentation;
	}
}

using namespace factory;
using namespace information;
using namespace information::presentation;
using namespace mapengine;

#define gResourceManager ResourceManager::GetSingleton()

namespace resource
{
	///
	///Klasa reprezentuje menagera zasobów
	///
	class ResourceManager : public CSingleton<ResourceManager>
	{
	public:

		///
		///Konstruktor domyślny
		///
		ResourceManager();

		///
		///Destruktor wirtualny
		///
		virtual ~ResourceManager();



		//Metody  ł a d u j ą c e  zasoby

		///
		///Metoda ładuje zasób RTexture
		///
		///@param name - stała referencja na nazwę zasobu
		///
		ResourceHandle loadTexture(const std::string & name);

		///
		///Metoda ładuje zasób Music
		///
		///@param name - stała referencja na nazwę zasobu
		///
		ResourceHandle loadMusic(const std::string & name);

		///
		///Metoda ładuje zasób Sound
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		ResourceHandle loadSound(const std::string & name);

		///
		///Metoda ładuje zasób Font
		///
		///@param name - stała referencja na nazwę zasobu
		///
		ResourceHandle loadFont(const std::string & name);

		///
		///Metoda ładuje zasób PhysicalTemplate
		///
		///@param name - stała referencja na nazwę zasobu
		///
		ResourceHandle loadPhysicalTemplate(const std::string & name);

		///
		///Metoda ładuje zasób MapPhysicalTemplate
		///
		///@param name - stała referencja na nazwę zasobu
		///
		ResourceHandle loadMapPhysicalTemplate(const std::string & name);

		///
		///Metoda ładuje zasób Map
		///
		///@param name - stała referencja na nazwę zasobu
		///
		ResourceHandle loadMap(const std::string & name);

		///
		///Metoda ładuje zasób GroundWorkTemplate
		///
		///@param name - stała referencja na nazwę zasobu
		///
		ResourceHandle loadGroundWorkTemplate(const std::string & name);

		///
		///Metoda ładuje zasób InformationTemplate
		///
		///@param name - stała referencja na nazwę zasobu
		///
		ResourceHandle loadInformationTemplate(const std::string & name);

		///
		///Metoda ładuje zasób PresentationTemplate
		///
		///@param name - stała referencja na nazwę zasobu
		///
		ResourceHandle loadPresentationTemplate(const std::string & name);

		//Metody  z w r a c a j ą c e  zasoby

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy RTexture
		///
		///@param name - stała referencja na nazwę zasobu
		///
		RTexture *getTexture(const std::string & name);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy Music
		///
		///@param name - stała referencja na nazwę zasobu
		///
		Music *getMusic(const std::string & name);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy Sound
		///
		///@param name - stała referencja na nazwę zasobu
		///
		Sound *getSound(const std::string & name);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy Font
		///
		///@param name - stała referencja na nazwę zasobu
		///
		Font *getFont(const std::string & name);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy PhysicalTemplate
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		PhysicalTemplate *getPhysicalTemplate(const std::string & name);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy MapPhysicalTemplate
		///
		///@param name - stała referencja na nazwę zasobu
		///
		MapPhysicalTemplate *getMapPhysicalTemplate(const std::string & name);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy Map
		///
		///@param name - stała referencja na nazwę zasobu
		///
		Map *getMap(const std::string & name);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy Ground
		///
		///@param name - stała referencja na nazwę zasobu
		///
		GroundTemplate *getGround(const std::string & name);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy GroundWorkTemplate
		///
		///@param name - stała referencja na nazwę zasobu
		///
		GroundWorkTemplate *getGroundWorkTemplate(const std::string & name);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy InformationTemplate
		///
		///@param name - stała referencja na nazwę zasobu
		///
		InformationTemplate *getInformationTemplate(const std::string & name);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy GetPresentationTemplate
		///
		///@param name - stała referencja na nazwę zasobu
		///
		PresentationTemplate *getPresentationTemplate(const std::string & name);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy PowerRelayStationTemplate
		///
		///@param name - stała referencja na nazwę zasobu
		///
		PowerRelayStationTemplate *getPowerRelayStationTemplate(const std::string & name);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy RTexture
		///
		///@param handle - uchwyt zasobu
		///
		RTexture *getTexture(ResourceHandle handle);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy Music
		///
		///@param handle - uchwyt zasobu
		///
		Music *getMusic(ResourceHandle handle);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy Sound
		///
		///@param handle - uchwyt zasobu
		///
		Sound *getSound(ResourceHandle handle);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy Font
		///
		///@param handle - uchwyt zasobu
		///
		Font *getFont(ResourceHandle handle);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy PhysicalTemplate
		///
		///@param handle - uchwyt zasobu
		///
		PhysicalTemplate *getPhysicalTemplate(ResourceHandle handle);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy CmapPhysicalTemplate
		///
		///@param handle - uchwyt zasobu
		///
		MapPhysicalTemplate *getMapPhysicalTemplate(ResourceHandle handle);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy Map
		///
		///@param handle - uchwyt zasobu
		///
		Map *getMap(ResourceHandle handle);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy GroundTemplate
		///
		///@param name - stała referencja na nazwę zasobu
		///
		GroundTemplate *getGroundTemplate(ResourceHandle handle);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy GroundWorkTemplate
		///
		///@param name - stała referencja na nazwę zasobu
		///
		GroundWorkTemplate *getGroundWorkTemplate(ResourceHandle handle);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy InformationTemplate
		///
		///@param name - stała referencja na nazwę zasobu
		///
		InformationTemplate *getInformationTemplate(ResourceHandle handle);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy PresentationTemplate
		///
		///@param name - stała referencja na nazwę zasobu
		///
		PresentationTemplate *getPresentationTemplate(ResourceHandle handle);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy PowerRelayStationTemplate
		///
		///@param name - stała referencja na nazwę zasobu
		///
		PowerRelayStationTemplate *getPowerRelayStationTemplate(ResourceHandle handle);

		///
		///Metoda księguje zarejstrowane nazwy załadowanych zasobów
		///
		void getAllStartingWith(const std::string & path, const std::string & type, std::vector<std::string> & out);

		///
		///Metoda zwraca numer (kod) błędu
		///
		inline int getErrorsOccured() { return m_errors_occured; }

		///
		///Metoda usuwa zasób na podstawie nazwy std::string
		///
		///@param name - stała referencja na nazwę zasoby std::string
		///
		void dropResource(const std::string & name);
		
		///
		///Metoda usuwa wszystkie zasoby z kontenera
		///
		void clear();

		///
		///Wirtualny interfejs - implementacja
		///
		virtual void cleanup();
		
	private:

		static unsigned long long m_resource_enumerator; //licznik zasobów
		std::map<ResourceHandle, Resource*>	m_resources; //kontener <map> przechowujący wskaźniki na zasoby
														 //key - ResourceHandle (wygenrowana liczba - uchwyt)
														 //value - wskaźnik na zasób

		std::vector<std::string> m_loaded_resource_names; //wektor załadowanych nazw zasobów
		int m_errors_occured; //numer (kod) błędu
		
		///
		///Szablon prywatnej metody zwracającej wskaźnik na zasób na podstawie nazwy std::string
		///
		///@param name - stała referencja na nazwę zasobu std::string
		///
		template <typename T> T *getResource(const std::string & name);

		///
		///Szablon metody zwracającej zasób na podstawie nazwy std::string
		///
		///@param handle - uchwyt zasobu
		///
		template <typename T> T *getResource(ResourceHandle handle);

		///
		///Szablon prywatnej metody ładującej zasób
		///
		///@param name - stała referencja na zasób std::string
		///
		template <typename T> ResourceHandle loadResource(const std::string & name);

		///
		///Szablon prywatnej metody ładujące zasoby (wzorce danych dla obiektów gry)
		///
		///@param &name - stała referencja na zasób std::string
		///
		template <> ResourceHandle loadResource<PhysicalTemplate>(const std::string & name);

		///
		///Szablon prywatnej metody ładujące zasoby (wzorce danych dla obiektów gry)
		///
		///@param name - stała referencja na zasób std::string
		///
		template <> ResourceHandle loadResource<MapPhysicalTemplate>(const std::string & name);

		///
		///Metoda parsuje i zwraca uchwyt zasobu
		///
		///@param name - stała referencja na zasób std::string
		///
		ResourceHandle parseHandle(const std::string & name);

	};
}//namespace resource
#endif //H_RESOURCE_MANAGER_JACK
