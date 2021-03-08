//  _____________________________________________
// | AnimationManager.h - class definition       |
// | Jack Flower - March 2012                    |
// |_____________________________________________|
//

#ifndef H_ANIMATION_MANAGER_JACK
#define H_ANIMATION_MANAGER_JACK

#include "../../Game/Listener/IFrameListener.h"
#include "../../Utilities/Singleton/Singleton.h"

#include <string>
#include <vector>
#include <map>
#include <set>


///
///Forward declaration
///
namespace rendering
{
	namespace animation
	{
		///
		///Forward declaration
		///
		class Animation;
		class AnimationState;
	}
}

using namespace listener;

#define gAnimationManager AnimationManager::GetSingleton()

namespace rendering
{
	namespace animation
	{
		///
		///Klasa reprezentuje menadżera animacji - CSingleton
		///
		class AnimationManager: public Singleton<AnimationManager> , IFrameListener
		{
		public:

			///
			///Konstruktor domyślny
			///
			AnimationManager();
			
			///
			///Destruktor
			///
			~AnimationManager();

			///
			///Wirtualna metoda aktualizująca logikę obiektów - implementacja
			///
			virtual void frameStarted(float secondsPassed);

			///
			///Metoda zwraca animację z kontenera na podstawie nazwy
			///
			///@param animation_name - nazwa animacji
			///
			Animation *getAnimation(const std::string & animation_name);

			///
			///Metoda tworzy funkcjonalny obiekt animowany
			///
			///@param animation_name - nazwa animacji
			///
			AnimationState *createAnimationState(const std::string & animation_name);

			///
			///Metoda tworzy funkcjonalny obiekt animowany
			///
			///@param *p_animation - wskaźnik na animację
			///
			AnimationState *createAnimationState(Animation *p_animation);

			///
			///Metoda usuwa funkcjonalny obiekt animowany
			///
			///@param *p_animation_state - wskaźnik na funkcjonalny obiekt animowany
			///
			void destroyAnimationState(AnimationState *p_animation_state);
		
		private:

			//metoda ładuje dane (wszystkie animacje) z pliku xml (wywoływana w konstruktorze)
			//
			//@param file_name - nazwa pliku - stała referencja na obiekt klasy std::string
			//
			//@param node_name - nazwa węzła xml - stała referencja na obiekt klasy std::string
			//
			void loadAnimations(const std::string & file_name, const std::string & node_name);

		private:

			typedef std::map<std::string, Animation*> AnimationsMap; //definicja typu - kontener (mapa) na animacje
			typedef std::set<AnimationState*> AnimationStatesSet; //definicja typu - kontener (set) na funkcjonalne obiekty animowane
			AnimationsMap m_animations; //kontener (mapa) na animacje
			AnimationStatesSet m_animation_states; //kontener (set) na funkcjonalne obiekty animowane
		};
	}//namespace animation
}//namespace rendering
#endif //H_ANIMATION_MANAGER_JACK
