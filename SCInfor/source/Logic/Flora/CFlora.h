//  ___________________________________
// | CFlora.h - class definition       |
// | Jack Flower - March 2014.         |
// |___________________________________|
//

#ifndef H_FLORA_JACK
#define H_FLORA_JACK

#include "../Actor/CActor.h"

namespace logic
{
	///
	///Klasa reprezentuje obiekty - roœlinnoœæ (drzewa, krzewy, etc...)
	///
	class CFlora : public CActor
	{

		///
		///Deklaracja przyjaŸni
		///
		friend class CPhysicalManager;
		
		//Aby uzyskaæ obiekt CFlora, nale¿y wywo³aæ CPhysicalManager::CreateFlora();

	protected:
		///
		///Chroniony konstruktor domyœlny
		///
		CFlora(const std::wstring& uniqueId);

		///
		///Destruktor wirtualny
		///
		virtual ~CFlora(void);

	public:

		///
		///Metoda zwraca prêdkoœæ rotacji body
		///
		const float getRotationSpeedBody() const;

		///
		///Metoda ustawia prêdkoœæ rotacji body
		///
		///@param rotation_speed_body - prêdkoœæ rotacji body
		///
		void setRotationSpeedBody(float rotation_speed_body);

		///
		///Metoda zwraca prêdkoœæ rotacji head
		///
		const float getRotationSpeedHead() const;

		///
		///Metoda ustawia prêdkoœæ rotacji head
		///
		///@param rotation_speed_head - prêdkoœæ rotacji head
		///
		void setRotationSpeedHead(float rotation_speed_head);

		///
		///Wirtualna metoda aktualizuj¹ca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);

	private:

		float m_rotation_speed_body;//prêdkoœæ rotacji body
		float m_rotation_speed_head;//prêdkoœæ rotacji head

	};
}//namespace logic
#endif//H_FLORA_JACK