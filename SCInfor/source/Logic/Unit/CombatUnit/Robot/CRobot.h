//  ___________________________________
// | CRobot.h - class definition       |
// | Jack Flower - June 2016           |
// |___________________________________|
//

#ifndef H_ROBOT_JACK
#define H_ROBOT_JACK

#include "../../CUnit.h"
#include "ERobotState.h"
#include "../../CStrategyDuration.h"

namespace logic
{
	namespace unit
	{
		///
		///Klasa reprezetuje obiekt gry
		///
		class CRobot : public CUnit
		{
			RTTI_DECL;

			///
			///Deklaracja przyja�ni
			///
			friend class CPhysicalManager;

			//Aby uzyska� obiekt CRobot, nale�y wywo�a� CPhysicalManager::CreateRobot();

		protected:

			///
			///Chroniony konstruktor domy�lny
			///
			///@param & uniqueId - sta�a referencja na obiekt klasy std::wstring - identyfikator
			///
			CRobot(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiuj�cy
			///
			///@param CRobotCopy - obiekt klasy CRobot
			///
			CRobot(const CRobot & CRobotCopy);

			///
			///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
			///
			virtual ~CRobot();

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Metoda zwraca sta�� referencj� na obiekt klasy CStrategyDuration
			///
			const CStrategyDuration & getStrategyDuration() const;

			///
			///Metoda ustawia referencj� na obiekt klasy CStrategyDuration
			///
			///@param & strategy_duration - sta�a referencja na obiekt klasy CStrategyDuration
			///
			void setStrategyDuration(const CStrategyDuration & strategy_duration);

			///
			///Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu (move, attack, death, etc...)
			///
			///@param dt - czas
			///
			virtual void updateAnimations(float dt);

			///
			///Wirtualan metoda zabija obiekt klasy CActor i wywo�uje odpowiednie czynno�ci z tym zwi�zane
			///
			virtual void Kill();

			///
			///Wirtualna metoda aktualizuj�ca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		private:

			ERobotState			m_robot_state;			//wyliczenie stan�w dla obiektu CRobot
			float				m_elapsed_time;			//up�ywaj�cy czas
			CStrategyDuration	m_strategy_duration;	//opakowanie mechanizmu zarz�dzania czasem stan�w strategicznych
			
			void updateState(float dt);					//metoda aktualizuje stan obiektu

		};
	}//namespace unit
}//namespace logic
#endif//H_ROBOT_JACK
