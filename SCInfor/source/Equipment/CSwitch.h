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
	///Klasa reprezentuje funkcjonalno�� prze��cznika
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
		///Konstruktor kopiuj�cy
		///
		///@param & CSwitchCopy - sta�a referencja na obiekt klasy CSwitch
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
		///Metoda zwraca stan urz�dzenia
		///
		const bool getState() const;

		///
		///Metoda ustawia stan urz�dzenia
		///
		///@param state - stan prze��cznika
		///
		void setState(bool state);

		///
		///Metoda zwraca czas do uruchomienia urz�dzenia
		///
		const float getTimeToRun() const;

		///
		///Metoda ustawia czas do uruchomienia urz�dzenia
		///
		///@param time_to_run - czas do uruchomienia urz�dzenia
		///
		void setTimeToRun(float time_to_run);

		///
		///Metoda zwraca sta�� referencj� na opakowanie przechowuj�ce zakres do losowania czasu procesu
		///
		const std::pair<float, float> & getTimeToRunRange() const;

		///
		///Metoda ustawia referencj� na opakowanie przechowuj�ce zakres do losowania czasu procesu
		///
		///@param & range zakres do losowania czasu procesu
		///
		void  setTimeToRunRange(const std::pair<float, float> & range);

		///
		///Metoda ustawia referencj� na opakowanie przechowuj�ce zakres do losowania czasu procesu
		///
		///@param begin - granica zakresu
		///
		///@param end - granica zakresu
		///
		void  setTimeToRunRange(float begin, float end);

		///
		///Metoda aktywuje w��cznik
		///
		///@param dt - czas
		///
		void updateToRun(float dt);

	private:

		bool					m_state;			//stan prze��cznika
		std::pair<float, float> m_time_to_run_range;//zakres do losowania czasu procesu (op�nienie w��czenia urz�dzenia)
		float					m_time_to_run;		//czas do uruchomienia urz�dzenia sterowanego tym prze��cznikiem
													//przydatne np. do wystartowania urz�dzenie, kt�re ze stanu
													//default po pewnym czasie przechodzi w kolejny stan automatu stan�w
													//wielko�� b�dzie losowana z pewnego zakresu - op�nienie

		float					m_elapsed_time;		//czas up�ywu procesu

		static float m_time_to_run_first;	//statyczne dane dla zakresu - losowanie
		static float m_time_to_run_second;	//statyczne dane dla zakresu - losowanie
	};
}//namespace equipment
#endif//H_SWITCH_JACK
