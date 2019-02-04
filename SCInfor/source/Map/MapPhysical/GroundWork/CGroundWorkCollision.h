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
		///Klasa reprezentuje funkcjonalnoœæ pozwalaj¹c¹ sprawdziæ, po jakim pod³o¿u poruszaj¹ siê obiekty
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
			///Konstruktor kopiuj¹cy
			///
			///@param CGroundWorkCollisionCopy - sta³a referencja na obiekt klasy CGroundWorkCollision
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

			sf::Vector2i				m_size;					//rozmiar mapy pod³o¿a
			std::vector<CGroundWork*>	m_ground_work_list;		//kontener przechowuj¹cy wskaŸniki na obiekty klasy CGroundWork
			//flaga kolizji z t¹ map¹...
			//konsola ma wypisywaæ na jakim jestem pod³o¿u (klaflu)...
			//std::string		m_code;		//nazwa kodu dla typu pod³o¿a
											//w zale¿noœci od tej nazwy
											//nastêpuje translacja, która
											//tworzy (inicjuje) pod³o¿e
		};
	}//namespace groundwork
}//namespace mapengine
#endif//H_GROUND_WORK_COLLISION_JACK