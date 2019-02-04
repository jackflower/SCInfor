//  _______________________________________________
// | CPartCollisionData.h - class definition       |
// | Jack Flower - June 2016                       |
// |_______________________________________________|
//

#ifndef H_COLLISION_DATA_JACK
#define H_COLLISION_DATA_JACK

#include "../../../RTTI/RTTI.h"

namespace collisiondata
{
	///
	///Klasa reprezentuje opakowanie informacji o kolidowaniu
	///
	class CPartCollisionData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CPartCollisionData();

		///
		///Konstruktor kopiuj¹cy
		///
		///@param & CPartCollisionDataCopy - sta³a referencja na obiekt klasy CPartCollisionData
		///
		CPartCollisionData(const CPartCollisionData & CPartCollisionDataCopy);

		///
		///Destruktor
		///
		~CPartCollisionData();

		///
		///Metoda zwraca flagê, czy obiekt koliduje - body
		///
		const bool getCollidingBody() const;

		///
		///Metoda ustawia flagê, czy obiekt koliduje - body
		///
		///@param colliding_body - flaga kolidowania - body
		///
		void setCollidingBody(const bool colliding_body);

		///
		///Metoda zwraca flagê, czy obiekt koliduje - body shadow
		///
		const bool getCollidingBodyShadow() const;

		///
		///Metoda ustawia flagê, czy obiekt koliduje -  body shadow
		///
		///@param colliding_body_shadow - flaga kolidowania -  body shadow
		///
		void setCollidingBodyShadow(const bool colliding_body_shadow);

		///
		///Metoda zwraca flagê, czy obiekt koliduje - head
		///
		const bool getCollidingHead() const;

		///
		///Metoda ustawia flagê, czy obiekt koliduje -  head
		///
		///@param colliding_head - flaga kolidowania -  head
		///
		void setCollidingHead(const bool colliding_head);

		///
		///Metoda zwraca flagê, czy obiekt koliduje - head shadow
		///
		const bool getCollidingHeadShadow() const;

		///
		///Metoda ustawia flagê, czy obiekt koliduje - head shadow
		///
		///@param colliding_head_shadow - flaga kolidowania - head shadow
		///
		void setCollidingHeadShadow(const bool colliding_head_shadow);

	private:

		bool m_colliding_body;			//flaga kolidowania - body
		bool m_colliding_body_shadow;	//flaga kolidowania - body shadow
		bool m_colliding_head;			//flaga kolidowania - head
		bool m_colliding_head_shadow;	//flaga kolidowania - head shadow

	};
}//namespace collisiondata
#endif//H_COLLISION_DATA_JACK


