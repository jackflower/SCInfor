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
	///Klasa reprezentuje menad¿era zjawisk pogodowych
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
		///Metoda zwraca nazwê klimatu
		///
		const std::string getName() const;

		///
		///Metoda ustawia nazwê klimatu
		///
		///@param &climate_name - sta³a referencja na obiekt klasy std::string
		///
		void setName(const std::string & climate_name);

		///
		///Metoda zwraca flagê, czy ma byæ generowany wiatr
		///
		const bool getUseWind() const;

		///
		///Metoda ustawia flagê, czy ma byæ generowany wiatr
		///
		///@param use_wind - flaga, czy ma byæ generowany wiatr
		///
		void setUseWind(bool use_wind);

		///
		///Interface zwraca k¹t padania promieni s³onecznych - pozorny obieg Ÿród³a œwiat³a wokó³ sceny
		///
		inline const float getAngleSun() const { return m_shadow_engine.getAngleSun(); }

		///
		///Interface zwraca temperaturê
		///
		inline const float getTemperature() const { return m_temperature.getTemperature(); }

		///
		///Interface zwraca prêdkoœæ wiatru
		///
		inline const float GetWindSpeed() const { return m_wind.getWindSpped(); }

		///
		///Interface zwraca kolor i nasycenie cienia
		///
		inline const sf::Color& GetShadowColor() const { return m_shadow_engine.getColor(); }

		///
		///Metoda zwraca czas co jaki nastêpuje aktualizacja zjawisk pogodowych
		///
		inline const float getUpdateTime() const { return m_update_time; }

		///
		///Metoda zwraca czas trwania doby
		///
		inline const float getDayDuration() const { return m_day_duration; }

		///
		///Interface zwraca referencjê do obiektu klasy CShadowEngine
		///
		inline CShadowEngine & getCShadowEngine() { return m_shadow_engine; }

		///
		///Metoda zwraca referencjê do obiektu klasy CWind
		///
		inline CWind & getWind() { return m_wind; }

		///
		///Metoda zwraca referencjê do obiektu klasy CTemperature
		///
		//inline CTemperature & getTemperature() { return m_temperature; }

		///
		///Metoda zwraca wspó³czynnik energii s³onecznej
		///
		inline const float & getSolarEnergyFactor() const { return m_shadow_engine.getSolarEnergyFactor(); }

		///
		///Metoda zwraca zakres prêdkoœci wiatru
		///
		inline const std::pair<float, float> & getWindSpeedRange() const { return m_wind_speeds_range; }

		///
		///Metoda ³aduj¹ca dane pogodowe z mapy œwiata
		///
		///@param &name - sta³a referencja na std::string
		///
		bool load(const std::string &name);
		///
		///Metoda ³aduj¹ca dane xml pogodowe z mapy œwiata
		///
		///@param &xml - sta³a referencja na obiekt klasy CXml
		///
		bool load(CXml &xml);

		///
		///Wirtualna metoda aktualizuje obiekty w kontenerze
		///
		///@param secondsPassed - up³ywaj¹cy czas
		///
		virtual void frameStarted(float secondsPassed);

		///
		///Metoda zwraca nazwê pliku wraz ze œcie¿k¹ dostêpu, z którego zosta³a za³adowana konfiguracja pogody
		///
		inline const std::string &getClimateFileName() const {return m_climate_file_name;}


	protected:

		///
		///Wirtualna metoda czyszcz¹ca singleton
		///
		virtual void cleanup();

	private:

		std::string				m_climate_name;						//nazwa klimatu
		CShadowEngine			m_shadow_engine;					//pozorne Ÿród³o œwiat³a - shadow engine
		CWind					m_wind;								//obiekt reprezentuj¹cy funkcjonalnoœæ wiatru
		CTemperature			m_temperature;						//obiekt reprezentuje dynamicznie zminiaj¹c¹ siê temperaturê [wyliczana]
		float					m_elapsed_time;						//up³ywaj¹cy czas
		bool					m_use_wind;							//flaga czy ma byæ generawany wiatr
		std::pair<float, float>	m_wind_duration_range;				//dane dla generatora - zakres czasu trwania wiatru
		std::pair<float, float> m_wind_speeds_range;				//dane dla generatora - zakres prêdkoœci wiatru
		sf::Color				m_color_shadow;						//kolor cienia (mo¿e np. zale¿eæ od pory dnia)
		float					m_update_time;						//co jaki czas ma nastêpowaæ aktualizacja zjawisk pogodowych
		float					m_day_duration;						//czas trwania doby
		float					m_angle_sun_increment;				//przyrost k¹ta obiegu œwiat³a
		std::pair<float, float> m_absolute_temperature_range;		//dane do losowania zakres temperatury (min=>first, max=>secound)
		float					m_absolute_temperature;				//temperatura bezwglêdna [ bazowa - dodawana podczas aktalizacji ]
		std::pair<float, float> m_temperature_fluctuations_range;	//dane do losowania (min=>first, max=>secound)
		float					m_temperature_fluctuations;			//wspó³czynnik wahañ temperatury
		std::pair<float, float> m_sun_position_range;				//dane do losowania pozycja s³oñca (min=>first, max=>secound)
		float					m_sun_position;						//losowana pozycja s³oñca - pora doby
		float					m_alpha_base;						//wartoœæ sk³adowej koloru - kana³ alpha - wartoœæ bazowa
		float					m_alpha_extra;						//wartoœæ sk³adowej koloru - kana³ alpha - wartoœæ dodana gdy zawsze jest jakiœ cieñ...
		float					m_alpha;							//wartoœæ sk³adowej koloru - wartoœæ wyliczana wzglêdem pozycji s³oñca
		std::string				m_climate_file_name;				//nazwa pliku z opisem klimatu

		//metoda generuje wspó³czynnik prêdkoœci i czasu trwania wiatru (podmuch)
		void generateWind();
	};
}//namespace weather
#endif //H_WEATHER_JACK
