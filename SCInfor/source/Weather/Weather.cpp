//  ___________________________________
// | Weather.cpp - class implemetation |
// | Jack Flower - October 2010        |
// |___________________________________|
//

#include "Weather.h"
#include "../Game/Game.h"
#include "../Utilities/Random/CRandom.h"
#include "../Utilities/Utilities/Utilities.h"

using namespace weather;
using namespace game;

template<> Weather* CSingleton<Weather>::m_singleton = 0;

namespace weather
{
	//Konstruktor
	Weather::Weather(void)
	:
		m_climate_name{ "" },
		m_shadow_engine{},
		m_wind{},
		m_temperature{},
		m_elapsed_time{ 0.0f },
		m_use_wind{ false },
		m_wind_duration_range{ 0.0f, 0.0f },
		m_wind_speeds_range{ 0.0f, 0.0f },
		m_color_shadow{},
		m_update_time{ 0.0f },
		m_day_duration{ 0.0f },
		m_angle_sun_increment{ 0.0f },
		m_absolute_temperature_range{ 0.0f, 0.0f },
		m_absolute_temperature{ 0.0f },
		m_temperature_fluctuations_range{ 0.0f, 0.0f },
		m_temperature_fluctuations{ 0.0f },
		m_sun_position_range{ 0.0f, 0.0f },
		m_sun_position{ 0.0f },
		m_climate_file_name{ "" }
	{
		printf("Weather::Weather()\n");
		gGame.addFrameListener(this); //dodajemy do kontenera wskaźnik na ten obiekt
									  //celem aktualizacji jego stanu i aktualizacji logiki
									  //czyli metoda frameStarted(float secondsPassed),
									  //aktualizacja zarejestrowanych zjawisk pogodowych
	}

	//Destruktor
	Weather::~Weather(void)
	{
		m_climate_name = "";
		m_shadow_engine;
		m_wind;
		m_temperature;
		m_elapsed_time = 0.0f;
		m_use_wind = false;
		m_wind_duration_range.first = 0.0f;
		m_wind_duration_range.second = 0.0f;
		m_wind_speeds_range.first = 0.0f;
		m_color_shadow;
		m_update_time = 0.0f;
		m_day_duration = 0.0f;
		m_angle_sun_increment = 0.0f;
		m_absolute_temperature_range.first = 0.0f;
		m_absolute_temperature_range.second = 0.0f;
		m_absolute_temperature = 0.0f;
		m_temperature_fluctuations_range.first = 0.0f;
		m_temperature_fluctuations_range.second = 0.0f;
		m_temperature_fluctuations = 0.0f;
		m_sun_position_range.first = 0.0f;
		m_sun_position_range.second = 0.0f;
		m_sun_position = 0.0f;
		m_climate_file_name = "";
	}

	//Metoda zwraca nazwę klimatu
	const std::string Weather::getName() const
	{
		return m_climate_name;
	}

	//Metoda ustawia nazwę klimatu
	void Weather::setName(const std::string & climate_name)
	{
		m_climate_name = climate_name;
	}

	//Metoda zwraca flagę, czy ma być generowany wiatr
	const bool Weather::getUseWind() const
	{
		return m_use_wind;
	}

	//Metoda ustawia flagę, czy ma być generowany wiatr
	void Weather::setUseWind(bool use_wind)
	{
		m_use_wind = use_wind;
	}

	//Metoda ładująca dane pogodowe z mapy świata
	bool Weather::load(const std::string & name)
	{
		fprintf(stderr, "weather configuration data %s loaded...\n", name.c_str());
		m_climate_file_name = name;	//zapamiętuję nazwę pliku wraz ze ścieżką dostępu,
									//z którego została załadowana konfiguracja pogody
		Xml xml(name, "weather");
		return load(xml);
	}

	//Metoda ładująca dane xml pogodowe z mapy świata
	bool Weather::load(Xml & xml)
	{
		//dane konfiguracyjen zjawisk pogodowych
		if (xml_node<> *node = xml.getChild(xml.getRootNode(), "weather_configuration"))
		{
			m_climate_name = xml.getString(node, "climate_name"); //nazwa klimatu
			m_use_wind = xml.getBool(node, "use_wind"); //flaga, czy generować wiatr
		}

		//wiatr
		if (xml_node<> *node = xml.getChild(xml.getRootNode(), "wind_config"))
		{
			m_wind_duration_range.first = xml.getFloat(node, "wind_duration_range_begin");
			m_wind_duration_range.second = xml.getFloat(node, "wind_duration_range_end");
			m_wind_speeds_range.first = xml.getFloat(node, "wind_speeds_range_begin");
			m_wind_speeds_range.second = xml.getFloat(node, "wind_speeds_range_end");
		}

		//kolor cienia na danej mapie świata
		if (xml_node<> *node = xml.getChild(xml.getRootNode(), "color_shadow_config"))
		{
			m_color_shadow.r = xml.getInt(node, "color_red");
			m_color_shadow.g = xml.getInt(node, "color_green");
			m_color_shadow.b = xml.getInt(node, "color_blue");
			m_color_shadow.a = xml.getInt(node, "color_alpha");
		}

		//solar_angle_engine_config
		if (xml_node<> *node = xml.getChild(xml.getRootNode(), "shadow_engine_config"))
		{
			m_update_time = xml.getFloat(node, "update_time");
			m_day_duration = xml.getFloat(node, "day_duration");

			//pozycja słońca (kąt padania promieni słonecznych) - pora dnia
			m_sun_position_range.first	= xml.getFloat(node, "sun_position_range_min");
			m_sun_position_range.second = xml.getFloat(node, "sun_position_range_max");

			//obliczamy przyrost kąta obiegu światła
			if(m_day_duration != 0)
				m_angle_sun_increment = (m_update_time * m_sun_position_range.second)/m_day_duration;
				//m_angle_sun_increment = 50;//testy

			//losowanie...
			m_sun_position = gRandom.Rndf
			(
				m_sun_position_range.first,
				m_sun_position_range.second
			);

			//wartość składowej koloru - kanał alpha - wartość bazowa
			m_alpha_base = xml.getFloat(node, "alpha_base");
			//wartość składowej koloru - kanał alpha - wartość dodana zawsze jest jakiś cień...białe noce...
			m_alpha_extra = xml.getFloat(node, "alpha_extra");
		}

		//temperatura bezwlędna na mapie świata
		if (xml_node<> *node = xml.getChild(xml.getRootNode(), "temperature_config"))
		{
			//temperatura bezwględna - ładowanie danych zakresu do losowania
			m_absolute_temperature_range.first = xml.getFloat(node, "absolute_temperature_min");
			m_absolute_temperature_range.second = xml.getFloat(node, "absolute_temperature_max");
			//losowanie...
			m_absolute_temperature = gRandom.Rndf
			(
				m_absolute_temperature_range.first,
				m_absolute_temperature_range.second
			);

			//współczynnik wahań temperatury - ładowanie danych zakresu do losowania
			m_temperature_fluctuations_range.first = xml.getFloat(node, "temperature_fluctuations_min");
			m_temperature_fluctuations_range.second = xml.getFloat(node, "temperature_fluctuations_max");
			//losowanie...
			m_temperature_fluctuations = gRandom.Rndf
			(
				m_temperature_fluctuations_range.first,
				m_temperature_fluctuations_range.second
			);
		}

		//przekazanie załadowanych danych
		m_temperature.setTemperature(m_absolute_temperature);
		m_temperature.setAbsoluteTemperature(m_absolute_temperature);
		m_temperature.setFluctuationTemperature(m_temperature_fluctuations);
		m_shadow_engine.setColor(m_color_shadow);
		m_shadow_engine.setAngleSunIncrement(m_angle_sun_increment);
		m_shadow_engine.setAngleSun(m_sun_position);
		m_shadow_engine.setColor(m_color_shadow);
		m_shadow_engine.setAlphaBase(m_alpha_base);
		m_shadow_engine.setAlphaExtra(m_alpha_extra);
		//inicjacja...
		m_shadow_engine.update(0);
		m_temperature.update(0);
		return true;
	}

	//Wirtualna metoda aktualizuje obiekty w kontenerze
	void Weather::frameStarted(float secondsPassed)
	{
		m_elapsed_time += secondsPassed;//odmierzam uływ czasu dla aktualizacji zjawisk pogodowych

		if (m_elapsed_time > m_update_time) //aktualizacja co zadany czas
		{
			m_shadow_engine.update(secondsPassed); //aktualizacja pozycji słońca
			m_temperature.update(secondsPassed); //aktualizacja temperatury
			m_elapsed_time = 0.0f;
		}

		//jeśli ma być generowany wiatr - uruchamiamy generator wiatru
		if(m_use_wind)
		{
			//zliczam upływ czasu
			m_wind.setWindDuriation(m_wind.getWindDuriation() - secondsPassed);
			//jeśli czas trwania wiatru się wyczerpał - uruchamiamy generator pseudo-losowy
			if(m_wind.getWindDuriation() <= 0)
				generateWind();
		}
	}

	//Wirtualna metoda czyszcząca singleton
	void Weather::cleanup()
	{
		printf("Weather::cleanup()\n");
		printf("Weather::cleanup() done...\n");
	}

	//implementacja metod private i proteceted:

	//metoda generuje współczynnik prędkości i czasu trwania wiatru (podmuch)
	void Weather::generateWind()
	{
		//losujemy czas trwania wiatru
		m_wind.setWindDuriation
		(
			gRandom.Rndf
			(
				m_wind_duration_range.first,
				m_wind_duration_range.second
			)
		);
		//losujemy siłę wiatru
		m_wind.setWindSpped
		(
			gRandom.Rndf
			(
				m_wind_speeds_range.first,
				m_wind_speeds_range.second
			)
		);
	}
}//namespace weather
