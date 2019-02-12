//  __________________________________
// | Robot.h - class definition       |
// | Jack Flower - June 2016          |
// |__________________________________|
//

#ifndef H_ROBOT_JACK
#define H_ROBOT_JACK

#include "ERobotState.h"
#include "../../Unit.h"
#include "../../StrategyDuration.h"

namespace logic
{
	namespace unit
	{
		///
		///Klasa reprezetuje obiekt gry
		///
		class Robot : public Unit
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaźni
			///
			friend class PhysicalManager;

			//Aby uzyskać obiekt Robot, należy wywołać PhysicalManager::CreateRobot();

		protected:

			///
			///Chroniony konstruktor domyślny
			///
			///@param uniqueId - stała referencja na obiekt klasy std::wstring - identyfikator
			///
			Robot(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiujący
			///
			///@param RobotCopy - obiekt klasy Robot
			///
			Robot(const Robot & RobotCopy);

			///
			///Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
			///
			virtual ~Robot();

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

			///
			///Metoda zwraca stałą referencję na obiekt klasy StrategyDuration
			///
			const StrategyDuration & getStrategyDuration() const;

			///
			///Metoda ustawia referencję na obiekt klasy StrategyDuration
			///
			///@param strategy_duration - stała referencja na obiekt klasy StrategyDuration
			///
			void setStrategyDuration(const StrategyDuration & strategy_duration);

			///
			///Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu (move, attack, death, etc...)
			///
			///@param dt - czas
			///
			virtual void updateAnimations(float dt);

			///
			///Wirtualan metoda zabija obiekt klasy Actor i wywołuje odpowiednie czynności z tym związane
			///
			virtual void kill();

			///
			///Wirtualna metoda aktualizująca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		private:

			ERobotState m_robot_state; //wyliczenie stanów dla obiektu Robot
			float m_elapsed_time; //upływający czas
			StrategyDuration m_strategy_duration; //opakowanie mechanizmu zarządzania czasem stanów strategicznych
			
			void updateState(float dt); //metoda aktualizuje stan obiektu

		};
	}//namespace unit
}//namespace logic
#endif//H_ROBOT_JACK
