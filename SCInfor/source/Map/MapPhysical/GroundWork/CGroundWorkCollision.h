//  _________________________________________________
// | CGroundWorkCollision.h - class definition       |
// | Jack Flower - March 2015                        |
// |_________________________________________________|
//

#ifndef H_GROUND_WORK_COLLISION_JACK
#define H_GROUND_WORK_COLLISION_JACK

#include <SFML/System/Vector2.hpp>
#include "../../../RTTI/RTTI.h"
#include "CGroundWork.h"
#include <vector>

namespace mapengine
{
	namespace groundwork
	{
		///
		///Klasa reprezentuje funkcjonalno�� pozwalaj�c� sprawdzi�, po jakim pod�o�u poruszaj� si� obiekty
		///
		class CGroundWorkCollision
		{
			RTTI_DECL;

		public:

			///
			///Konstruktor
			///
			CGroundWorkCollision();

			///
			///Konstruktor kopiuj�cy
			///
			///@param CGroundWorkCollisionCopy - sta�a referencja na obiekt klasy CGroundWorkCollision
			///
			CGroundWorkCollision(const CGroundWorkCollision & CGroundWorkCollisionCopy);

			///
			///Destruktor
			///
			~CGroundWorkCollision();

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Metoda zwraca rozmiar mapy kolizji
			///
			inline sf::Vector2i GetSize() { return m_size; }

		private:

			sf::Vector2i				m_size;					//rozmiar mapy pod�o�a
			std::vector<CGroundWork*>	m_ground_work_list;		//kontener przechowuj�cy wska�niki na obiekty klasy CGroundWork
			//flaga kolizji z t� map�...
			//konsola ma wypisywa� na jakim jestem pod�o�u (klaflu)...
			//std::string		m_code;		//nazwa kodu dla typu pod�o�a
											//w zale�no�ci od tej nazwy
											//nast�puje translacja, kt�ra
											//tworzy (inicjuje) pod�o�e
		};
	}//namespace groundwork
}//namespace mapengine
#endif//H_GROUND_WORK_COLLISION_JACK