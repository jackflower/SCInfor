//  __________________________________
// | Flora.h - class definition       |
// | Jack Flower - March 2014         |
// |__________________________________|
//

#ifndef H_FLORA_JACK
#define H_FLORA_JACK

#include "../Actor/Actor.h"

namespace logic
{
	///
	///Klasa reprezentuje obiekty - roślinność (drzewa, krzewy, etc...)
	///
	class Flora : public Actor
	{

		///
		///Deklaracja przyjaźni
		///
		friend class PhysicalManager;
		
		//Aby uzyskać obiekt Flora, należy wywołać PhysicalManager::CreateFlora();

	protected:
		///
		///Chroniony konstruktor domyślny
		///
		///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
		///
		Flora(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiujący
		///
		///@param FloraCopy - stała referencja na obiekt klasy Flora
		///
		Flora(const Flora & FloraCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~Flora(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca prędkość rotacji body
		///
		const float getRotationSpeedBody() const;

		///
		///Metoda ustawia prędkość rotacji body
		///
		///@param rotation_speed_body - prędkość rotacji body
		///
		void setRotationSpeedBody(float rotation_speed_body);

		///
		///Metoda zwraca prędkość rotacji head
		///
		const float getRotationSpeedHead() const;

		///
		///Metoda ustawia prędkość rotacji head
		///
		///@param rotation_speed_head - prędkość rotacji head
		///
		void setRotationSpeedHead(float rotation_speed_head);

		///
		///Wirtualna metoda aktualizująca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);

	private:

		float m_rotation_speed_body; //prędkość rotacji body (wizualizacja wpływu wiatru)
		float m_rotation_speed_head; //prędkość rotacji head (wizualizacja wpływu wiatru)

	};
}//namespace logic
#endif//H_FLORA_JACK
