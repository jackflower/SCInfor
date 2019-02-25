//  ________________________________________________
// | GroundWorkCollision.h - class definition       |
// | Jack Flower - March 2015                       |
// |________________________________________________|
//

#ifndef H_GROUND_WORK_COLLISION_JACK
#define H_GROUND_WORK_COLLISION_JACK

#include <SFML/System/Vector2.hpp>
#include "../../../RTTI/RTTI.h"
#include "GroundWork.h"
#include <vector>

namespace mapengine
{
	namespace groundwork
	{
		///
		///Klasa reprezentuje funkcjonalność pozwalającą sprawdzić, po jakim podłożu poruszają się obiekty
		///
		class GroundWorkCollision
		{
			RTTI_DECL;

		public:

			///
			///Konstruktor
			///
			GroundWorkCollision();

			///
			///Konstruktor kopiujący
			///
			///@param GroundWorkCollisionCopy - stała referencja na obiekt klasy GroundWorkCollision
			///
			GroundWorkCollision(const GroundWorkCollision & GroundWorkCollisionCopy);

			///
			///Destruktor
			///
			~GroundWorkCollision();

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

			///
			///Metoda zwraca stała referencję rozmiar mapy kolizji
			///
			inline sf::Vector2i & getSize();

		private:

			sf::Vector2i m_size; //rozmiar mapy podłoża
			std::vector<GroundWork*> m_ground_work_list; //kontener przechowujący wskaźniki na obiekty klasy GroundWork
			//flaga kolizji z tą mapą...
			//konsola ma wypisywać na jakim jestem podłożu (klaflu)...
			//std::string m_code; //nazwa kodu dla typu podłoża
								  //w zależności od tej nazwy
								  //następuje translacja, która
								  //tworzy (inicjuje) podłoże
		};
	}//namespace groundwork
}//namespace mapengine
#endif//H_GROUND_WORK_COLLISION_JACK