//  _______________________________________________
// | StrategyController.h - class definition       |
// | Jack Flower - June 2016                       |
// |_______________________________________________|
//

#ifndef H_STRATEGY_CONTROLLER_JACK
#define H_STRATEGY_CONTROLLER_JACK

#include "EStrategyState.h"
#include "../../RTTI/RTTI.h"


///
///Klasa reprezentuje opakowanie stanów strategii
///
class StrategyController
{
	RTTI_DECL;

public:

	///
	///Konstruktor
	///
	StrategyController();

	///
	///Konstruktor kopiujący
	///
	///@param StrategyControllerCopy - stała referencja na obiekt klasy StrategyController
	///
	StrategyController(const StrategyController & StrategyControllerCopy);

	///
	///Destruktor
	///
	~StrategyController();

	///
	///Metoda zwraca typ obiektu /RTTI/
	///
	const std::string getType() const;

	///
	///Metoda ustawia strategię ataku
	///
	void attack();

	///
	///Metoda ustawia strategię obrony
	///
	void defense();

	///
	///Metoda ustawia strategię neutralności
	///
	void neutral();

	///
	///Metoda zwraca stan strategii
	///
	const EStrategyState & getStrategyState() const;

	///
	///Metoda ustawia stan strategii
	///
	///@param trategy_state - wyliczenie EStrategyState
	///
	void setStrategyState(const EStrategyState & strategy_state);

private:

	EStrategyState m_strategy_state;
};

#endif//H_STRATEGY_CONTROLLER_JACK
