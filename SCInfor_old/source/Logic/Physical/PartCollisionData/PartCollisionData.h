//  ______________________________________________
// | PartCollisionData.h - class definition       |
// | Jack Flower - June 2016                      |
// |______________________________________________|
//

#ifndef H_COLLISION_DATA_JACK
#define H_COLLISION_DATA_JACK

#include "../../../RTTI/RTTI.h"

namespace collisiondata
{
	///
	///Klasa reprezentuje opakowanie informacji o kolidowaniu
	///
	class PartCollisionData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		PartCollisionData();

		///
		///Konstruktor kopiujący
		///
		///@param PartCollisionDataCopy - stała referencja na obiekt klasy PartCollisionData
		///
		PartCollisionData(const PartCollisionData & PartCollisionDataCopy);

		///
		///Destruktor
		///
		~PartCollisionData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca flagę, czy obiekt koliduje - body
		///
		const bool getCollidingBody() const;

		///
		///Metoda ustawia flagę, czy obiekt koliduje - body
		///
		///@param colliding_body - flaga kolidowania - body
		///
		void setCollidingBody(const bool colliding_body);

		///
		///Metoda zwraca flagę, czy obiekt koliduje - body shadow
		///
		const bool getCollidingBodyShadow() const;

		///
		///Metoda ustawia flagę, czy obiekt koliduje -  body shadow
		///
		///@param colliding_body_shadow - flaga kolidowania -  body shadow
		///
		void setCollidingBodyShadow(const bool colliding_body_shadow);

		///
		///Metoda zwraca flagę, czy obiekt koliduje - head
		///
		const bool getCollidingHead() const;

		///
		///Metoda ustawia flagę, czy obiekt koliduje -  head
		///
		///@param colliding_head - flaga kolidowania -  head
		///
		void setCollidingHead(const bool colliding_head);

		///
		///Metoda zwraca flagę, czy obiekt koliduje - head shadow
		///
		const bool getCollidingHeadShadow() const;

		///
		///Metoda ustawia flagę, czy obiekt koliduje - head shadow
		///
		///@param colliding_head_shadow - flaga kolidowania - head shadow
		///
		void setCollidingHeadShadow(const bool colliding_head_shadow);

	private:

		bool m_colliding_body; //flaga kolidowania - body
		bool m_colliding_body_shadow; //flaga kolidowania - body shadow
		bool m_colliding_head; //flaga kolidowania - head
		bool m_colliding_head_shadow; //flaga kolidowania - head shadow

	};
}//namespace collisiondata
#endif//H_COLLISION_DATA_JACK
