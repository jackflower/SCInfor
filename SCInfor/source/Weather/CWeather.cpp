//  ____________________________________
// | CWeather.cpp - class implemetation |
// | Jack Flower - October 2010         |
// |____________________________________|
//

#include "CWeather.h"
#include "../Game/Game.h"
#include "../Utilities/Random/CRandom.h"
#include "../Utilities/Utilities/Utilities.h"

using namespace weather;
using namespace game;

template<> CWeather* CSingleton<CWeather>::m_singleton = 0;

namespace weather
{
	//Konstruktor
	CWeather::CWeather(void)
	:
		m_climate_name						(""),
		m_shadow_engine						(),
		m_wind								(),
		m_temperature						(),
		m_elapsed_time						(0.0f),
		m_use_wind							(false),
		m_wind_duration_range				(0.0f, 0.0f),
		m_wind_speeds_range					(0.0f, 0.0f),
		m_color_shadow						(),
		m_update_time						(0.0f),
		m_day_duration						(0.0f),
		m_angle_sun_increment				(0.0f),
		m_absolute_temperature_range		(0.0f, 0.0f),
		m_absolute_temperature				(0.0f),
		m_temperature_fluctuations_range	(0.0f, 0.0f),
		m_temperature_fluctuations			(0.0f),
		m_sun_position_range				(0.0f, 0.0f),
		m_sun_position						(0.0f),
		m_climate_file_name					("")
	{
		printf("CWeather::CWeather()\n");
		gGame.addFrameListener(this);	//dodajemy do kontenera wska�nik na ten obiekt
										//celem aktualizacji jego stanu i aktualizacji logiki
										//czyli metoda FrameStarted(float secondsPassed),
										//aktualizacja zarejestrowanych zjawisk pogodowych
	}

	//Destruktor
	CWeather::~CWeather(void)
	{
		m_climate_name							= "";
		//m_shadow_engine						not edit
		//m_wind								not edit
		//m_temperature							not edit
		m_elapsed_time							= 0.0f;
		m_use_wind								= false;
		m_wind_duration_range.first				= 0.0f;
		m_wind_duration_range.second			= 0.0f;
		m_wind_speeds_range.first				= 0.0f;
		//m_color_shadow						not edit
		m_update_time							= 0.0f;
		m_day_duration							= 0.0f;
		m_angle_sun_increment					= 0.0f;
		m_absolute_temperature_range.first		= 0.0f;
		m_absolute_temperature_range.second		= 0.0f;
		m_absolute_temperature					= 0.0f;
		m_temperature_fluctuations_range.first	= 0.0f;
		m_temperature_fluctuations_range.second	= 0.0f;
		m_temperature_fluctuations				= 0.0f;
		m_sun_position_range.first				= 0.0f;
		m_sun_position_range.second				= 0.0f;
		m_sun_position							= 0.0f;
		m_climate_file_name						= "";
	}

	//Metoda zwraca nazw� klimatu
	const std::string CWeather::getName() const
	{
		return m_climate_name;
	}

	//Metoda ustawia nazw� klimatu
	void CWeather::setName(const std::string & climate_name)
	{
		m_climate_name = climate_name;
	}

	//Metoda zwraca flag�, czy ma by� generowany wiatr
	const bool CWeather::getUseWind() const
	{
		return m_use_wind;
	}

	//Metoda ustawia flag�, czy ma by� generowany wiatr
	void CWeather::setUseWind(bool use_wind)
	{
		m_use_wind = use_wind;
	}

	//Metoda �aduj�ca dane pogodowe z mapy �wiata
	bool CWeather::Load(const std::string &name)
	{
		fprintf(stderr, "weather configuration data %s loaded...\n", name.c_str());
		m_climate_file_name = name;	//zapami�tuj� nazw� pliku wraz ze �cie�k� dost�pu,
									//z kt�rego zosta�a za�adowana konfiguracja pogody
		CXml xml(name, "weather");
		return Load(xml);
	}

	//Metoda �aduj�ca dane xml pogodowe z mapy �wiata
	bool CWeather::Load(CXml &xml)
	{
		//dane konfiguracyjen zjawisk pogodowych
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "weather_configuration"))
		{
			m_climate_name = xml.GetString(node, "climate_name");	//nazwa klimatu
			m_use_wind = xml.GetBool(node, "use_wind");				//flaga, czy generowa� wiatr
		}

		//wiatr
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "wind_config"))
		{
			m_wind_duration_range.first = xml.GetFloat(node, "wind_duration_range_begin");
			m_wind_duration_range.second = xml.GetFloat(node, "wind_duration_range_end");
			m_wind_speeds_range.first = xml.GetFloat(node, "wind_speeds_range_begin");
			m_wind_speeds_range.second = xml.GetFloat(node, "wind_speeds_range_end");
		}

		//kolor cienia na danej mapie �wiata
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "color_shadow_config"))
		{
			m_color_shadow.r = xml.GetInt(node, "color_red");
			m_color_shadow.g = xml.GetInt(node, "color_green");
			m_color_shadow.b = xml.GetInt(node, "color_blue");
			m_color_shadow.a = xml.GetInt(node, "color_alpha");
		}

		//solar_angle_engine_config
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "shadow_engine_config"))
		{
			m_update_time			= xml.GetFloat(node, "update_time");
			m_day_duration			= xml.GetFloat(node, "day_duration");

			//pozycja s�o�ca (k�t padania promieni s�onecznych) - pora dnia
			m_sun_position_range.first	= xml.GetFloat(node, "sun_position_range_min");
			m_sun_position_range.second = xml.GetFloat(node, "sun_position_range_max");

			//obliczamy przyrost k�ta obiegu �wiat�a
			if(m_day_duration != 0)
				m_angle_sun_increment = (m_update_time * m_sun_position_range.second)/m_day_duration;
				//m_angle_sun_increment = 50;//testy

			//losowanie...
			m_sun_position = gRandom.Rndf
			(
				m_sun_position_range.first,
				m_sun_position_range.second
			);

			//warto�� sk�adowej koloru - kana� alpha - warto�� bazowa
			m_alpha_base = xml.GetFloat(node, "alpha_base");
			//warto�� sk�adowej koloru - kana� alpha - warto�� dodana zawsze jest jaki� cie�...bia�e noce...
			m_alpha_extra = xml.GetFloat(node, "alpha_extra");
		}

		//temperatura bezwl�dna na mapie �wiata
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "temperature_config"))
		{
			//temperatura bezwgl�dna - �adowanie danych zakresu do losowania
			m_absolute_temperature_range.first	= xml.GetFloat(node, "absolute_temperature_min");
			m_absolute_temperature_range.second = xml.GetFloat(node, "absolute_temperature_max");
			//losowanie...
			m_absolute_temperature = gRandom.Rndf
			(
				m_absolute_temperature_range.first,
				m_absolute_temperature_range.second
			);

			//wsp�czynnik waha� temperatury - �adowanie danych zakresu do losowania
			m_temperature_fluctuations_range.first	= xml.GetFloat(node, "temperature_fluctuations_min");
			m_temperature_fluctuations_range.second = xml.GetFloat(node, "temperature_fluctuations_max");
			//losowanie...
			m_temperature_fluctuations = gRandom.Rndf
			(
				m_temperature_fluctuations_range.first,
				m_temperature_fluctuations_range.second
			);
		}

		//przekazanie za�adowanych danych
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
		m_shadow_engine.Update(0);
		m_temperature.Update(0);
		return true;
	}

	//Wirtualna metoda aktualizuje obiekty w kontenerze
	void CWeather::FrameStarted(float secondsPassed)
	{
		m_elapsed_time += secondsPassed;//odmierzam u�yw czasu dla aktualizacji zjawisk pogodowych

		if (m_elapsed_time > m_update_time)			//aktualizacja co zadany czas
		{
			m_shadow_engine.Update(secondsPassed);	//aktualizacja pozycji s�o�ca
			m_temperature.Update(secondsPassed);	//aktualizacja temperatury
			m_elapsed_time = 0.0f;
		}

		//je�li ma by� generowany wiatr - uruchamiamy generator wiatru
		if(m_use_wind)
		{
			//zliczam up�yw czasu
			m_wind.setWindDuriation(m_wind.getWindDuriation()- secondsPassed);
			//je�li czas trwania wiatru si� wyczerpa� - uruchamiamy generator pseudo-losowy
			if(m_wind.getWindDuriation() <= 0)
				generateWind();
		}
	}

	//Wirtualna metoda czyszcz�ca singleton
	void CWeather::Cleanup()
	{
		printf("CWeather::Cleanup()\n");
		printf("CWeather::Cleanup() done...\n");
	}

	//implementacja metod private i proteceted:

	//metoda generuje wsp�czynnik pr�dko�ci i czasu trwania wiatru (podmuch)
	void CWeather::generateWind()
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
		//losujemy si�� wiatru
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
