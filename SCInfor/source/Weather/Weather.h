//  ___________________________________
// | Weather.h - class definition      |
// | Jack Flower - October 2010        |
// |___________________________________|
//

#ifndef H_WEATHER_JACK
#define H_WEATHER_JACK

#include "../Utilities/Singleton/CSingleton.h"
#include "../Game/Listener/IFrameListener.h"
#include <SFML/Graphics/Color.hpp>
#include "../XML/Xml.h"
#include "ShadowEngine.h"
#include "Wind.h"
#include "Temperature.h"

using namespace xml;
using namespace listener;
using namespace weather::shadowengine;
using namespace weather::wind;
using namespace weather::temperature;

#define gWeather Weather::GetSingleton()

namespace weather
{
	///
	///Klasa reprezentuje menadżera zjawisk pogodowych
	///
	class Weather : public CSingleton<Weather>, public IFrameListener
	{
	public:

		///
		///Konstruktor
		///
		Weather();

		///
		///Destruktor
		///
		~Weather();

		///
		///Metoda zwraca nazwę klimatu
		///
		const std::string getName() const;

		///
		///Metoda ustawia nazwę klimatu
		///
		///@param climate_name - stała referencja na obiekt klasy std::string
		///
		void setName(const std::string & climate_name);

		///
		///Metoda zwraca flagę, czy ma być generowany wiatr
		///
		const bool getUseWind() const;

		///
		///Metoda ustawia flagę, czy ma być generowany wiatr
		///
		///@param use_wind - flaga, czy ma być generowany wiatr
		///
		void setUseWind(bool use_wind);

		///
		///Interface zwraca kąt padania promieni słonecznych - pozorny obieg źródła światła wokół sceny
		///
		inline const float getAngleSun() const { return m_shadow_engine.getAngleSun(); }

		///
		///Interface zwraca temperaturę
		///
		inline const float getTemperature() const { return m_temperature.getTemperature(); }

		///
		///Interface zwraca prędkość wiatru
		///
		inline const float getWindSpeed() const { return m_wind.getWindSpped(); }

		///
		///Interface zwraca kolor i nasycenie cienia
		///
		inline const sf::Color & getShadowColor() const { return m_shadow_engine.getColor(); }

		///
		///Metoda zwraca czas co jaki następuje aktualizacja zjawisk pogodowych
		///
		inline const float getUpdateTime() const { return m_update_time; }

		///
		///Metoda zwraca czas trwania doby
		///
		inline const float getDayDuration() const { return m_day_duration; }

		///
		///Interface zwraca referencję do obiektu klasy ShadowEngine
		///
		inline ShadowEngine & getCShadowEngine() { return m_shadow_engine; }

		///
		///Metoda zwraca referencję do obiektu klasy Wind
		///
		inline Wind & getWind() { return m_wind; }

		///
		///Metoda zwraca referencję do obiektu klasy Temperature
		///
		//inline Temperature & getTemperature() { return m_temperature; }

		///
		///Metoda zwraca współczynnik energii słonecznej
		///
		inline const float & getSolarEnergyFactor() const { return m_shadow_engine.getSolarEnergyFactor(); }

		///
		///Metoda zwraca zakres prędkości wiatru
		///
		inline const std::pair<float, float> & getWindSpeedRange() const { return m_wind_speeds_range; }

		///
		///Metoda ładująca dane pogodowe z mapy świata
		///
		///@param name - stała referencja na std::string
		///
		bool load(const std::string & name);

		///
		///Metoda ładująca dane xml pogodowe z mapy świata
		///
		///@param xml - stała referencja na obiekt klasy Xml
		///
		bool load(Xml & xml);

		///
		///Wirtualna metoda aktualizuje obiekty w kontenerze
		///
		///@param secondsPassed - upływający czas
		///
		virtual void frameStarted(float secondsPassed);

		///
		///Metoda zwraca nazwę pliku wraz ze ścieżką dostępu, z którego została załadowana konfiguracja pogody
		///
		inline const std::string & getClimateFileName() const {return m_climate_file_name;}


	protected:

		///
		///Wirtualna metoda czyszcząca singleton
		///
		virtual void cleanup();

	private:

		std::string m_climate_name; //nazwa klimatu
		ShadowEngine m_shadow_engine; //pozorne źródło światła - shadow engine
		Wind m_wind; //obiekt reprezentujący funkcjonalność wiatru
		Temperature m_temperature; //obiekt reprezentuje dynamicznie zmieniającą się temperaturę [wyliczana]
		float m_elapsed_time; //upływający czas
		bool m_use_wind; //flaga czy ma być generawany wiatr
		std::pair<float, float>	m_wind_duration_range; //dane dla generatora - zakres czasu trwania wiatru
		std::pair<float, float> m_wind_speeds_range; //dane dla generatora - zakres prędkości wiatru
		sf::Color m_color_shadow; //kolor cienia (może np. zależeć od pory dnia)
		float m_update_time; //co jaki czas ma następować aktualizacja zjawisk pogodowych
		float m_day_duration; //czas trwania doby
		float m_angle_sun_increment; //przyrost kąta obiegu światła
		std::pair<float, float> m_absolute_temperature_range; //dane do losowania zakres temperatury (min=>first, max=>secound)
		float m_absolute_temperature; //temperatura bezwględna na mapie świata [ bazowa - dodawana podczas aktalizacji ]
		std::pair<float, float> m_temperature_fluctuations_range; //dane do losowania (min=>first, max=>secound)
		float m_temperature_fluctuations; //współczynnik wahań temperatury
		std::pair<float, float> m_sun_position_range; //dane do losowania pozycja słońca (min=>first, max=>secound)
		float m_sun_position; //losowana pozycja słońca - pora doby
		float m_alpha_base; //wartość składowej koloru - kanał alpha - wartość bazowa
		float m_alpha_extra; //wartość składowej koloru - kanał alpha - wartość dodana gdy zawsze jest jakiś cień...
		float m_alpha; //wartość składowej koloru - wartość wyliczana względem pozycji słońca
		std::string m_climate_file_name; //nazwa pliku z opisem klimatu

		//metoda generuje współczynnik prędkości i czasu trwania wiatru (podmuch)
		void generateWind();
	};
}//namespace weather
#endif //H_WEATHER_JACK
