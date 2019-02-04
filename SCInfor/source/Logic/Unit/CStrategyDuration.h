//  ______________________________________________
// | CStrategyDuration.h - class definition       |
// | Jack Flower - July 2016                      |
// |______________________________________________|
//

#ifndef H_STRATEGY_DURATION_JACK
#define H_STRATEGY_DURATION_JACK

#include "../../RTTI/RTTI.h"

///
///Klasa reprezentuje opakowanie czasu trwania stan�w strategii
///
class CStrategyDuration
{
	RTTI_DECL;

public:

	///
	///Konstruktor
	///
	CStrategyDuration();

	///
	///Konstruktor kopiuj�cy
	///
	///@param & CStrategyDurationCopy - sta�a referencja na obiekt klasy CStrategyDuration
	///
	CStrategyDuration(const CStrategyDuration & CStrategyDurationCopy);

	///
	///Destruktor
	///
	~CStrategyDuration();

	///
	///Metoda zwraca typ obiektu /RTTI/
	///
	const std::string GetType() const;

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
	///Metoda zwraca czas zako�czenia stanu ataku
	///
	const float getTimeAttackTerminate() const;

	///
	///Metoda ustawia czas do zako�czenia stanu ataku
	///
	///@param time_attack_terminate - czas do zako�czenia stanu ataku
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
	///Metoda zwraca czas zako�czenia stanu obrony
	///
	const float getTimeDefenseTerminate() const;

	///
	///Metoda ustawia czas do zako�czenia stanu obrony
	///
	///@param time_defense_terminate - czas do zako�czenia stanu obrony
	///
	void setTimeDefenseTerminate(const float time_defense_terminate);

private:

	float m_time_attack_prepare;		//czas przygotowania stanu ataku
	float m_time_attack_terminate;		//czas zako�czenia stanu ataku
	float m_time_defense_prepare;		//czas przygotowania stanu obrony
	float m_time_defense_terminate;		//czas zako�czenia stanu obrony

};

#endif//H_STRATEGY_DURATION_JACK