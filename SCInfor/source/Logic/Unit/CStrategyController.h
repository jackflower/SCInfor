//  ________________________________________________
// | CStrategyController.h - class definition       |
// | Jack Flower - June 2016                        |
// |________________________________________________|
//

#ifndef H_STRATEGY_CONTROLLER_JACK
#define H_STRATEGY_CONTROLLER_JACK

#include "../../RTTI/RTTI.h"
#include "EStrategyState.h"

///
///Klasa reprezentuje opakowanie stanów strategii
///
class CStrategyController
{
	RTTI_DECL;

public:

	///
	///Konstruktor
	///
	CStrategyController();

	///
	///Konstruktor kopiuj¹cy
	///
	///@param & CStrategyControllerCopy - sta³a referencja na obiekt klasy CStrategyController
	///
	CStrategyController(const CStrategyController & CStrategyControllerCopy);

	///
	///Destruktor
	///
	~CStrategyController();

	///
	///Metoda zwraca typ obiektu /RTTI/
	///
	const std::string GetType() const;

	///
	///Metoda ustawia strategiê ataku
	///
	void Attack();

	///
	///Metoda ustawia strategiê obrony
	///
	void Defense();

	///
	///Metoda ustawia strategiê neutralnoœci
	///
	void Neutral();

	///
	///Metoda zwraca stan strategii
	///
	const EStrategyState & getStrategyState() const;

	///
	///Metoda ustawia stan strategii
	///
	///@param & strategy_state - wyliczenie EStrategyState
	///
	void setStrategyState(const EStrategyState & strategy_state);

private:

	EStrategyState m_strategy_state;
};

#endif//H_STRATEGY_CONTROLLER_JACK
