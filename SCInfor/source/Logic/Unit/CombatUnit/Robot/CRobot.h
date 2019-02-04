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
			///Deklaracja przyjaŸni
			///
			friend class CPhysicalManager;

			//Aby uzyskaæ obiekt CRobot, nale¿y wywo³aæ CPhysicalManager::CreateRobot();

		protected:

			///
			///Chroniony konstruktor domyœlny
			///
			///@param & uniqueId - sta³a referencja na obiekt klasy std::wstring - identyfikator
			///
			CRobot(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiuj¹cy
			///
			///@param CRobotCopy - obiekt klasy CRobot
			///
			CRobot(const CRobot & CRobotCopy);

			///
			///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
			///
			virtual ~CRobot();

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Metoda zwraca sta³¹ referencjê na obiekt klasy CStrategyDuration
			///
			const CStrategyDuration & getStrategyDuration() const;

			///
			///Metoda ustawia referencjê na obiekt klasy CStrategyDuration
			///
			///@param & strategy_duration - sta³a referencja na obiekt klasy CStrategyDuration
			///
			void setStrategyDuration(const CStrategyDuration & strategy_duration);

			///
			///Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu (move, attack, death, etc...)
			///
			///@param dt - czas
			///
			virtual void updateAnimations(float dt);

			///
			///Wirtualan metoda zabija obiekt klasy CActor i wywo³uje odpowiednie czynnoœci z tym zwi¹zane
			///
			virtual void Kill();

			///
			///Wirtualna metoda aktualizuj¹ca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		private:

			ERobotState			m_robot_state;			//wyliczenie stanów dla obiektu CRobot
			float				m_elapsed_time;			//up³ywaj¹cy czas
			CStrategyDuration	m_strategy_duration;	//opakowanie mechanizmu zarz¹dzania czasem stanów strategicznych
			
			void updateState(float dt);					//metoda aktualizuje stan obiektu

		};
	}//namespace unit
}//namespace logic
#endif//H_ROBOT_JACK
