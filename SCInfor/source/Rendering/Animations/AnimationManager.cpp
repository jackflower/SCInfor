//  _____________________________________________
// | AnimationManager.cpp - class implementation |
// | Jack Flower - March 2012                    |
// |_____________________________________________|
//

#include "AnimationManager.h"
#include "AnimationState.h"
#include "Animation.h"
#include "../../Game/Game.h"
#include "../../XML/Xml.h"

using namespace rendering::animation;
using namespace game;

template<> AnimationManager* CSingleton<AnimationManager>::m_singleton = 0;

namespace rendering
{
	namespace animation
	{
		//Konstruktor domyślny
		AnimationManager::AnimationManager()
		:
			m_animations{},
			m_animation_states{}
		{
			fprintf(stderr, "AnimationManager::CAnimationsManager()\n");
			gGame.addFrameListener(this);

			//Ładowanie pliku xml - wszystkie animacje
			loadAnimations("../data/xml_data/animations/all_animations.xml", "root");
			fprintf(stderr, "AnimationManager::CAnimationsManager() all animations loaded...\n");
		}

		//Destruktor
		AnimationManager::~AnimationManager()
		{
			for (AnimationStatesSet::iterator it = m_animation_states.begin(); it != m_animation_states.end(); it++)
			{
				delete (*it);
			}
			m_animation_states.clear();

			for (AnimationsMap::iterator it = m_animations.begin(); it != m_animations.end(); it++)
			{
				delete (it->second);
			}
			m_animations.clear();
		}

		//Wirtualna metoda aktualizująca logikę obiektów - implementacja
		void AnimationManager::frameStarted(float secondsPassed)
		{
			for (AnimationStatesSet::iterator it = m_animation_states.begin(); it != m_animation_states.end(); it++)
			{
				AnimationState *state = (*it);
				if (!state->getPaused())
					state->addTime(secondsPassed);
			}
		}

		//Metoda zwraca animację z kontenera na podstawie nazwy
		Animation *AnimationManager::getAnimation(const std::string & animation_name)
		{
			Animation *animationPtr = nullptr;
			if (m_animations.find(animation_name) != m_animations.end())
				animationPtr = m_animations[animation_name];

			if (animationPtr == nullptr)
			{
				if (animation_name != "")
					fprintf(stderr, "warning: AnimationManager::GetAnimation - unable to find `%s' animation in m_animations map\n", animation_name.c_str());
				return nullptr;
			}
			return animationPtr;
		}

		//Metoda tworzy funkcjonalny obiekt animowany
		AnimationState *AnimationManager::createAnimationState(const std::string & animation_name)
		{
			Animation *animationPtr = getAnimation(animation_name);
			return createAnimationState(animationPtr);
		}

		//Metoda tworzy funkcjonalny obiekt animowany
		AnimationState *AnimationManager::createAnimationState(Animation *p_animation)
		{
			if (p_animation == nullptr)
				return nullptr;
			AnimationState* p_animation_state = new AnimationState(p_animation);
			m_animation_states.insert(p_animation_state);
			return p_animation_state;
		}

		//Metoda usuwa funkcjonalny obiekt animowany
		void AnimationManager::destroyAnimationState(AnimationState *p_animation_state)
		{
			if (!p_animation_state)
			{
				fprintf(stderr, "warning: AnimationManager::DestroyAnimationState - p_animation_state was nullptr\n");
				return;
			}

			if (m_animation_states.find(p_animation_state) != m_animation_states.end())
			{
				m_animation_states.erase(m_animation_states.find(p_animation_state));
				delete p_animation_state;
				return;
			}
			else
			{
				fprintf(stderr, "error: AnimationManager::DestroyAnimationState - p_animation_state was not found in set\n");
				return;
			}
		}

		//metoda ładuje dane z pliku xml
		void AnimationManager::loadAnimations(const std::string & file_name, const std::string & node_name)
		{
			//zmienne pomocnicze, poza pętlą, aby nie obciążać stosu
			std::string m_animation_name = "";
			float m_frame_time = 0.0f;
			float m_total_frame_time = 0.0f;
			std::string m_texture_name = "";
			sf::IntRect rectangle = sf::IntRect(0,0,0,0);

			Xml xml(file_name, node_name);
			
			for(xml_node<> *node = xml.getChild(xml.getRootNode(), "animation_name"); node; node = xml.getSibling(node, "animation_name"))
			{
				m_animation_name = xml.getString(node, "name");	//odczutuję nazwę
				Animation *animation = new Animation(); //tworzę animację
				animation->setAnimationName(m_animation_name); //nadaję nazwę animacji
				m_total_frame_time = 0; //resetujemy kumulację czasu trwania animacji

				for(xml_node<> *second_node = xml.getChild(node, "animation_frame"); second_node; second_node = xml.getSibling(second_node,"animation_frame"))
				{
					m_frame_time = xml.getFloat(second_node,"frame_time"); //odczyt czasu ekspozycji klatki animacji
					m_texture_name = xml.getString(second_node,"texture_name"); //odczyt nazwy tekstury, z której pobierany jest obraz klatki
					rectangle = sf::IntRect //odczyt koordynatów poszczególnych klatek animacji
						(
							xml.getInt(second_node,"rect_left"),
							xml.getInt(second_node,"rect_top"),
							xml.getInt(second_node,"rect_width"),
							xml.getInt(second_node,"rect_height")
						);
					//kumulacja czasów ekspozycji poszczególnych klatek animacji
					//zatem, pobierając z wektora ostatni element kontenera
					//pobieramy tym samym łączny czas trwania animacji
					//float Animation::TotalLength()
					m_total_frame_time += m_frame_time;
					m_animations[animation->getAnimationName()] = animation;
					animation->m_frames.push_back(TimedAnimationFrame(m_total_frame_time, AnimationFrame(m_texture_name, rectangle)));
				}
			}
		}
	}//namespace animation
}//namespace rendering
