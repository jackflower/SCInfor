//  _____________________________________________
// | StrategyDuration.h - class definition       |
// | Jack Flower - July 2016                     |
// |_____________________________________________|
//

#ifndef H_STRATEGY_DURATION_JACK
#define H_STRATEGY_DURATION_JACK

#include "../../RTTI/RTTI.h"

///
///Klasa reprezentuje opakowanie czasu trwania stanów strategii
///
class StrategyDuration
{
	RTTI_DECL;

public:

	///
	///Konstruktor
	///
	StrategyDuration();

	///
	///Konstruktor kopiujący
	///
	///@param StrategyDurationCopy - stała referencja na obiekt klasy StrategyDuration
	///
	StrategyDuration(const StrategyDuration & StrategyDurationCopy);

	///
	///Destruktor
	///
	~StrategyDuration();

	///
	///Metoda zwraca typ obiektu /RTTI/
	///
	const std::string getType() const;

	///
	///Metoda zwraca czas przygotowania do stanu ataku
	///
	const float getTimeAttackPrepare() const;

	///
	///Metoda ustawia czas przygotowania do stanu ataku
	///
	///@param time_attack_prepare- czas przygotowania do stanu ataku
	///
	void setTimeAttackPrepare(const float time_attack_prepare);
	
	///
	///Metoda zwraca czas zakończenia stanu ataku
	///
	const float getTimeAttackTerminate() const;

	///
	///Metoda ustawia czas do zakończenia stanu ataku
	///
	///@param time_attack_terminate - czas do zakończenia stanu ataku
	///
	void setTimeAttackTerminate(const float time_attack_terminate);

	///
	///Metoda zwraca czas przygotowania do stanu obrony
	///
	const float getTimeDefensePrepare() const;

	///
	///Metoda ustawia czas przygotowania do stanu obrony
	///
	///@param time_defense_prepare - czas przygotowania do stanu obrony
	///
	void setTimeDefensePrepare(const float time_defense_prepare);

	///
	///Metoda zwraca czas zakończenia stanu obrony
	///
	const float getTimeDefenseTerminate() const;

	///
	///Metoda ustawia czas do zakończenia stanu obrony
	///
	///@param time_defense_terminate - czas do zakończenia stanu obrony
	///
	void setTimeDefenseTerminate(const float time_defense_terminate);

private:

	float m_time_attack_prepare; //czas przygotowania stanu ataku
	float m_time_attack_terminate; //czas zakończenia stanu ataku
	float m_time_defense_prepare; //czas przygotowania stanu obrony
	float m_time_defense_terminate; //czas zakończenia stanu obrony
};

#endif//H_STRATEGY_DURATION_JACK
