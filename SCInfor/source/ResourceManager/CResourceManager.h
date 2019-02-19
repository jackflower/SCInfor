//  _____________________________________________
// | CResourceManager.h - class definition       |
// | Jack Flower - September 2012                |
// |_____________________________________________|
//

#ifndef H_RESOURCE_MANAGER_JACK
#define H_RESOURCE_MANAGER_JACK

#include "../Utilities/Singleton/CSingleton.h"
#include "IResource.h"
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
	class CTexture;	//opakowanie sf::Texture 
	class CMusic;	//opakowanie sf::Music
	class CSound;	//opakowanie sf::SoundBuffer
	class CFont;	//opakowanie sf::Font
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

#define gResourceManager CResourceManager::GetSingleton()

namespace resource
{
	///
	///Klasa reprezentuje menagera zasobów
	///
	class CResourceManager : public CSingleton<CResourceManager>
	{
	public:

		///
		///Konstruktor domyślny
		///
		CResourceManager();

		///
		///Destruktor wirtualny
		///
		virtual ~CResourceManager();



		//Metody  ł a d u j ą c e  zasoby

		///
		///Metoda ładuje zasób CTexture
		///
		///@param name - stała referencja na nazwę zasobu
		///
		ResourceHandle LoadTexture(const std::string & name);

		///
		///Metoda ładuje zasób CMusic
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		ResourceHandle LoadMusic(const std::string& name);

		///
		///Metoda ładuje zasób CSound
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		ResourceHandle LoadSound(const std::string& name);

		///
		///Metoda ładuje zasób CFont
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		ResourceHandle LoadFont(const std::string& name);

		///
		///Metoda ładuje zasób PhysicalTemplate
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		ResourceHandle LoadPhysicalTemplate(const std::string& name);

		///
		///Metoda ładuje zasób MapPhysicalTemplate
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		ResourceHandle LoadMapPhysicalTemplate(const std::string& name);

		///
		///Metoda ładuje zasób Map
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		ResourceHandle LoadMap(const std::string& name);

		///
		///Metoda ładuje zasób GroundWorkTemplate
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		ResourceHandle LoadGroundWorkTemplate(const std::string& name);

		///
		///Metoda ładuje zasób InformationTemplate
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		ResourceHandle LoadInformationTemplate(const std::string& name);

		///
		///Metoda ładuje zasób PresentationTemplate
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		ResourceHandle LoadPresentationTemplate(const std::string& name);

		//Metody  z w r a c a j ą c e  zasoby

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy CTexture
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		CTexture* GetTexture(const std::string& name);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy CMusic
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		CMusic* GetMusic(const std::string& name);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy CSound
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		CSound* GetSound(const std::string& name);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy CFont
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		CFont* GetFont(const std::string& name);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy PhysicalTemplate
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		PhysicalTemplate* GetPhysicalTemplate(const std::string& name);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy MapPhysicalTemplate
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		MapPhysicalTemplate* GetMapPhysicalTemplate(const std::string& name);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy Map
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		Map* GetMap(const std::string& name);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy Ground
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		GroundTemplate* GetGround(const std::string& name);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy GroundWorkTemplate
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		GroundWorkTemplate* GetGroundWorkTemplate(const std::string& name);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy InformationTemplate
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		InformationTemplate* GetInformationTemplate(const std::string& name);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy GetPresentationTemplate
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		PresentationTemplate* GetPresentationTemplate(const std::string& name);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy PowerRelayStationTemplate
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		PowerRelayStationTemplate* GetPowerRelayStationTemplate(const std::string& name);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy CTexture
		///
		///@param &handle - uchwyt zasobu
		///
		CTexture* GetTexture(ResourceHandle handle);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy CMusic
		///
		///@param &handle - uchwyt zasobu
		///
		CMusic* GetMusic(ResourceHandle handle);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy CSound
		///
		///@param &handle - uchwyt zasobu
		///
		CSound* GetSound(ResourceHandle handle);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy CFont
		///
		///@param &handle - uchwyt zasobu
		///
		CFont* GetFont(ResourceHandle handle);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy PhysicalTemplate
		///
		///@param &handle - uchwyt zasobu
		///
		PhysicalTemplate* GetPhysicalTemplate(ResourceHandle handle);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy CmapPhysicalTemplate
		///
		///@param &handle - uchwyt zasobu
		///
		MapPhysicalTemplate* GetMapPhysicalTemplate(ResourceHandle handle);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy Map
		///
		///@param &handle - uchwyt zasobu
		///
		Map* GetMap(ResourceHandle handle);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy GroundTemplate
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		GroundTemplate* GetGroundTemplate(ResourceHandle handle);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy GroundWorkTemplate
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		GroundWorkTemplate* GetGroundWorkTemplate(ResourceHandle handle);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy InformationTemplate
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		InformationTemplate* GetInformationTemplate(ResourceHandle handle);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy PresentationTemplate
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		PresentationTemplate* GetPresentationTemplate(ResourceHandle handle);

		///
		///Metoda zwraca wskaźnik na zasób - obiekt klasy PowerRelayStationTemplate
		///
		///@param &name - stała referencja na nazwę zasobu
		///
		PowerRelayStationTemplate* GetPowerRelayStationTemplate(ResourceHandle handle);

		///
		///Metoda księguje zarejstrowane nazwy załadowanych zasobów
		///
		void GetAllStartingWith(const std::string &path, const std::string &type, std::vector<std::string> &out);

		///
		///Metoda zwraca numer (kod) błędu
		///
		inline int GetErrorsOccured() { return m_errors_occured; }

		///
		///Metoda usuwa zasób na podstawie nazwy std::string
		///
		///@param &name - stała referencja na nazwę zasoby std::string
		///
		void DropResource(const std::string& name);
		
		///
		///Metoda usuwa wszystkie zasoby z kontenera
		///
		void Clear();

		///
		///Wirtualny interfejs - implementacja
		///
		virtual void cleanup();
		
	private:

		static unsigned long long				m_resource_enumerator;	//licznik zasobów
		std::map<ResourceHandle, IResource*>	m_resources;			//kontener <map> przechowujący wskaźniki na zasoby
																		//key - ResourceHandle (wygenrowana liczba - uchwyt)
																		//value - wskaźnik na zasób

		std::vector<std::string>				m_loaded_resource_names;//wektor załadowanych nazw zasobów
		int										m_errors_occured;		//numer (kod) błędu
		
		///
		///Szablon prywatnej metody zwracającej wskaźnik na zasób na podstawie nazwy std::string
		///
		///@param &name - stała referencja na nazwę zasobu std::string
		///
		template <typename T> T* GetResource(const std::string& name);

		///
		///Szablon metody zwracającej zasób na podstawie nazwy std::string
		///
		///@param handle - uchwyt zasobu
		///
		template <typename T> T* GetResource(ResourceHandle handle);

		///
		///Szablon prywatnej metody ładującej zasób
		///
		///@param &name - stała referencja na zasób std::string
		///
		template <typename T> ResourceHandle LoadResource(const std::string& name);

		///
		///Szablon prywatnej metody ładujące zasoby (wzorce danych dla obiektów gry)
		///
		///@param &name - stała referencja na zasób std::string
		///
		template <> ResourceHandle LoadResource<PhysicalTemplate>(const std::string& name);

		///
		///Szablon prywatnej metody ładujące zasoby (wzorce danych dla obiektów gry)
		///
		///@param &name - stała referencja na zasób std::string
		///
		template <> ResourceHandle LoadResource<MapPhysicalTemplate>(const std::string& name);

		///
		///Metoda parsuje i zwraca uchwyt zasobu
		///
		///@param &name - stała referencja na zasób std::string
		///
		ResourceHandle ParseHandle(const std::string& name);

	};
}//namespace resource
#endif //H_RESOURCE_MANAGER_JACK
