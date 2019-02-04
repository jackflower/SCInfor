//  ____________________________________
// | CSwitch.h - class definition       |
// | Jack Flower June 2014              |
// |____________________________________|
//

#ifndef H_SWITCH_JACK
#define H_SWITCH_JACK

#include "../RTTI/RTTI.h"

namespace equipment
{
	///
	///Klasa reprezentuje funkcjonalnoœæ prze³¹cznika
	///
	class CSwitch
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CSwitch();

		///
		///Konstruktor
		///
		///@param state - stan
		///
		CSwitch(bool state);

		///
		///Konstruktor kopiuj¹cy
		///
		///@param & CSwitchCopy - sta³a referencja na obiekt klasy CSwitch
		///
		CSwitch(const CSwitch & CSwitchCopy);

		///
		///Destruktor
		///
		~CSwitch();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca stan urz¹dzenia
		///
		const bool getState() const;

		///
		///Metoda ustawia stan urz¹dzenia
		///
		///@param state - stan prze³¹cznika
		///
		void setState(bool state);

		///
		///Metoda zwraca czas do uruchomienia urz¹dzenia
		///
		const float getTimeToRun() const;

		///
		///Metoda ustawia czas do uruchomienia urz¹dzenia
		///
		///@param time_to_run - czas do uruchomienia urz¹dzenia
		///
		void setTimeToRun(float time_to_run);

		///
		///Metoda zwraca sta³¹ referencjê na opakowanie przechowuj¹ce zakres do losowania czasu procesu
		///
		const std::pair<float, float> & getTimeToRunRange() const;

		///
		///Metoda ustawia referencjê na opakowanie przechowuj¹ce zakres do losowania czasu procesu
		///
		///@param & range zakres do losowania czasu procesu
		///
		void  setTimeToRunRange(const std::pair<float, float> & range);

		///
		///Metoda ustawia referencjê na opakowanie przechowuj¹ce zakres do losowania czasu procesu
		///
		///@param begin - granica zakresu
		///
		///@param end - granica zakresu
		///
		void  setTimeToRunRange(float begin, float end);

		///
		///Metoda aktywuje w³¹cznik
		///
		///@param dt - czas
		///
		void updateToRun(float dt);

	private:

		bool					m_state;			//stan prze³¹cznika
		std::pair<float, float> m_time_to_run_range;//zakres do losowania czasu procesu (opóŸnienie w³¹czenia urz¹dzenia)
		float					m_time_to_run;		//czas do uruchomienia urz¹dzenia sterowanego tym prze³¹cznikiem
													//przydatne np. do wystartowania urz¹dzenie, które ze stanu
													//default po pewnym czasie przechodzi w kolejny stan automatu stanów
													//wielkoœæ bêdzie losowana z pewnego zakresu - opóŸnienie

		float					m_elapsed_time;		//czas up³ywu procesu

		static float m_time_to_run_first;	//statyczne dane dla zakresu - losowanie
		static float m_time_to_run_second;	//statyczne dane dla zakresu - losowanie
	};
}//namespace equipment
#endif//H_SWITCH_JACK
