//  ___________________________________
// | Switch.h - class definition       |
// | Jack Flower June 2014             |
// |___________________________________|
//

#ifndef H_SWITCH_JACK
#define H_SWITCH_JACK

#include "../RTTI/RTTI.h"

namespace equipment
{
	///
	///Klasa reprezentuje funkcjonalność przełącznika
	///
	class Switch
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		Switch();

		///
		///Konstruktor
		///
		///@param state - stan
		///
		Switch(bool state);

		///
		///Konstruktor kopiujący
		///
		///@param & SwitchCopy - stała referencja na obiekt klasy Switch
		///
		Switch(const Switch & SwitchCopy);

		///
		///Destruktor
		///
		~Switch();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca stan urządzenia
		///
		const bool getState() const;

		///
		///Metoda ustawia stan urządzenia
		///
		///@param state - stan przełącznika
		///
		void setState(bool state);

		///
		///Metoda zwraca czas do uruchomienia urządzenia
		///
		const float getTimeToRun() const;

		///
		///Metoda ustawia czas do uruchomienia urządzenia
		///
		///@param time_to_run - czas do uruchomienia urządzenia
		///
		void setTimeToRun(float time_to_run);

		///
		///Metoda zwraca stałą referencję na opakowanie przechowujące zakres do losowania czasu procesu
		///
		const std::pair<float, float> & getTimeToRunRange() const;

		///
		///Metoda ustawia referencję na opakowanie przechowujące zakres do losowania czasu procesu
		///
		///@param range - stała referencja na zakres do losowania czasu procesu
		///
		void  setTimeToRunRange(const std::pair<float, float> & range);

		///
		///Metoda ustawia referencję na opakowanie przechowujące zakres do losowania czasu procesu
		///
		///@param begin - granica zakresu
		///
		///@param end - granica zakresu
		///
		void  setTimeToRunRange(float begin, float end);

		///
		///Metoda aktywuje włącznik
		///
		///@param dt - czas
		///
		void updateToRun(float dt);

	private:

		bool m_state; //stan przełącznika
		std::pair<float, float> m_time_to_run_range;//zakres do losowania czasu procesu (opóźnienie włączenia urządzenia)
		//czas do uruchomienia urządzenia sterowanego tym przełącznikiem
		//przydatne np. do wystartowania urządzenie, które ze stanu
		//default po pewnym czasie przechodzi w kolejny stan automatu stanów
		//wielkość będzie losowana z pewnego zakresu - opóźnienie
		float m_time_to_run;
		float m_elapsed_time; //czas upływu procesu

		static float m_time_to_run_first; //statyczne dane dla zakresu - losowanie
		static float m_time_to_run_second; //statyczne dane dla zakresu - losowanie
	};
}//namespace equipment
#endif//H_SWITCH_JACK
