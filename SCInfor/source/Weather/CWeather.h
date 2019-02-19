//  ____________________________________
// | CWeather.h - class definition      |
// | Jack Flower - October 2010         |
// |____________________________________|
//

#ifndef H_WEATHER_JACK
#define H_WEATHER_JACK

#include "../Utilities/Singleton/CSingleton.h"
#include "../Game/Listener/IFrameListener.h"
#include <SFML/Graphics/Color.hpp>
#include "../XML/CXml.h"
#include "CShadowEngine.h"
#include "CWind.h"
#include "CTemperature.h"

using namespace xml;
using namespace listener;
using namespace weather::shadowengine;
using namespace weather::wind;
using namespace weather::temperature;

#define gWeather CWeather::GetSingleton()

namespace weather
{
	///
	///Klasa reprezentuje menad�era zjawisk pogodowych
	///
	class CWeather : public CSingleton<CWeather>, public IFrameListener
	{
	public:

		///
		///Konstruktor
		///
		CWeather(void);

		///
		///Destruktor
		///
		~CWeather(void);

		///
		///Metoda zwraca nazw� klimatu
		///
		const std::string getName() const;

		///
		///Metoda ustawia nazw� klimatu
		///
		///@param &climate_name - sta�a referencja na obiekt klasy std::string
		///
		void setName(const std::string & climate_name);

		///
		///Metoda zwraca flag�, czy ma by� generowany wiatr
		///
		const bool getUseWind() const;

		///
		///Metoda ustawia flag�, czy ma by� generowany wiatr
		///
		///@param use_wind - flaga, czy ma by� generowany wiatr
		///
		void setUseWind(bool use_wind);

		///
		///Interface zwraca k�t padania promieni s�onecznych - pozorny obieg �r�d�a �wiat�a wok� sceny
		///
		inline const float getAngleSun() const { return m_shadow_engine.getAngleSun(); }

		///
		///Interface zwraca temperatur�
		///
		inline const float getTemperature() const { return m_temperature.getTemperature(); }

		///
		///Interface zwraca pr�dko�� wiatru
		///
		inline const float GetWindSpeed() const { return m_wind.getWindSpped(); }

		///
		///Interface zwraca kolor i nasycenie cienia
		///
		inline const sf::Color& GetShadowColor() const { return m_shadow_engine.getColor(); }

		///
		///Metoda zwraca czas co jaki nast�puje aktualizacja zjawisk pogodowych
		///
		inline const float getUpdateTime() const { return m_update_time; }

		///
		///Metoda zwraca czas trwania doby
		///
		inline const float getDayDuration() const { return m_day_duration; }

		///
		///Interface zwraca referencj� do obiektu klasy CShadowEngine
		///
		inline CShadowEngine & getCShadowEngine() { return m_shadow_engine; }

		///
		///Metoda zwraca referencj� do obiektu klasy CWind
		///
		inline CWind & getWind() { return m_wind; }

		///
		///Metoda zwraca referencj� do obiektu klasy CTemperature
		///
		//inline CTemperature & getTemperature() { return m_temperature; }

		///
		///Metoda zwraca wsp�czynnik energii s�onecznej
		///
		inline const float & getSolarEnergyFactor() const { return m_shadow_engine.getSolarEnergyFactor(); }

		///
		///Metoda zwraca zakres pr�dko�ci wiatru
		///
		inline const std::pair<float, float> & getWindSpeedRange() const { return m_wind_speeds_range; }

		///
		///Metoda �aduj�ca dane pogodowe z mapy �wiata
		///
		///@param &name - sta�a referencja na std::string
		///
		bool load(const std::string &name);
		///
		///Metoda �aduj�ca dane xml pogodowe z mapy �wiata
		///
		///@param &xml - sta�a referencja na obiekt klasy CXml
		///
		bool load(CXml &xml);

		///
		///Wirtualna metoda aktualizuje obiekty w kontenerze
		///
		///@param secondsPassed - up�ywaj�cy czas
		///
		virtual void frameStarted(float secondsPassed);

		///
		///Metoda zwraca nazw� pliku wraz ze �cie�k� dost�pu, z kt�rego zosta�a za�adowana konfiguracja pogody
		///
		inline const std::string &getClimateFileName() const {return m_climate_file_name;}


	protected:

		///
		///Wirtualna metoda czyszcz�ca singleton
		///
		virtual void cleanup();

	private:

		std::string				m_climate_name;						//nazwa klimatu
		CShadowEngine			m_shadow_engine;					//pozorne �r�d�o �wiat�a - shadow engine
		CWind					m_wind;								//obiekt reprezentuj�cy funkcjonalno�� wiatru
		CTemperature			m_temperature;						//obiekt reprezentuje dynamicznie zminiaj�c� si� temperatur� [wyliczana]
		float					m_elapsed_time;						//up�ywaj�cy czas
		bool					m_use_wind;							//flaga czy ma by� generawany wiatr
		std::pair<float, float>	m_wind_duration_range;				//dane dla generatora - zakres czasu trwania wiatru
		std::pair<float, float> m_wind_speeds_range;				//dane dla generatora - zakres pr�dko�ci wiatru
		sf::Color				m_color_shadow;						//kolor cienia (mo�e np. zale�e� od pory dnia)
		float					m_update_time;						//co jaki czas ma nast�powa� aktualizacja zjawisk pogodowych
		float					m_day_duration;						//czas trwania doby
		float					m_angle_sun_increment;				//przyrost k�ta obiegu �wiat�a
		std::pair<float, float> m_absolute_temperature_range;		//dane do losowania zakres temperatury (min=>first, max=>secound)
		float					m_absolute_temperature;				//temperatura bezwgl�dna [ bazowa - dodawana podczas aktalizacji ]
		std::pair<float, float> m_temperature_fluctuations_range;	//dane do losowania (min=>first, max=>secound)
		float					m_temperature_fluctuations;			//wsp�czynnik waha� temperatury
		std::pair<float, float> m_sun_position_range;				//dane do losowania pozycja s�o�ca (min=>first, max=>secound)
		float					m_sun_position;						//losowana pozycja s�o�ca - pora doby
		float					m_alpha_base;						//warto�� sk�adowej koloru - kana� alpha - warto�� bazowa
		float					m_alpha_extra;						//warto�� sk�adowej koloru - kana� alpha - warto�� dodana gdy zawsze jest jaki� cie�...
		float					m_alpha;							//warto�� sk�adowej koloru - warto�� wyliczana wzgl�dem pozycji s�o�ca
		std::string				m_climate_file_name;				//nazwa pliku z opisem klimatu

		//metoda generuje wsp�czynnik pr�dko�ci i czasu trwania wiatru (podmuch)
		void generateWind();
	};
}//namespace weather
#endif //H_WEATHER_JACK
