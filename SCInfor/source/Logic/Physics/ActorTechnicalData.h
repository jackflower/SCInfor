//  _______________________________________________
// | ActorTechnicalData.h - class definition       |
// | Jack Flower - May 2016                        |
// |_______________________________________________|
//

#ifndef H_ACTOR_TECHNICAL_DATA_JACK
#define H_ACTOR_TECHNICAL_DATA_JACK

#include "PhysicsData.h"

using namespace physics;

namespace physics
{
	namespace technical
	{
		///
		///klasa reprezentuje opakowanie fizyki dla klasy Actor
		///
		class ActorTechnicalData : public PhysicsData
		{
			RTTI_DECL;

		public:

			///
			///Konstruktor
			///
			ActorTechnicalData();

			///
			///Konstruktor kopiujący
			///
			///@param ActorTechnicalDataCopy - stała referencja na obiekt klasy ActorTechnicalData
			///
			ActorTechnicalData(const ActorTechnicalData & ActorTechnicalDataCopy);

			///
			///Destruktor wirtualny
			///
			virtual ~ActorTechnicalData();

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;
		
			///
			///Metoda zwraca masę obiektu
			///
			const float getMass() const;

			///
			///Metoda ustawia masę obiektu
			///
			///@param mass - masa obiektu
			///
			const void setMass(float mass);

			///
			///Metoda zwraca temperaturę
			///
			const float getTemperature() const;

			///
			///Metoda ustawia temperaturę
			///
			///@param temperature - temperatura
			///
			const void setTemperature(float temperature);

			///
			///Metoda zwraca prędkość obiektu
			///
			const float getSpeed() const;

			///
			///Metoda ustawia prędkość obiektu
			///
			///@param speed - prędkość obiektu
			///
			const void setSpeed(float speed);

			///
			///Metoda zwraca flagę, czy obiekt może się przemieszczać
			///
			const bool getIsMovabled() const;

			///
			///Metoda ustawia flagę, czy obiekt może się przemieszczać
			///
			///@param movabled - parametr określający, czy obiekt może się przemieszczać
			///
			const void setIsMovabled(bool movabled);

			///
			///Metoda zwraca flagę, czy obiekt się porusza
			///
			bool const getIsMove() const;

			///
			///Metoda ustawia flagę, że obiekt się porusza
			///
			///@param is_move - flaga, czy obiekt się porusza
			///
			const void setIsMove(bool is_move);

		private:

			float m_mass; //masa obiektu
			float m_temperature; //temperatura obiektu (zależna od klimatyzatora, wentylatora, otoczenia)
			float m_speed; //prędkość przemieszczania się obiektu
			bool m_movabled; //flaga określa czy obiekt może się przemieszczać
			bool m_is_move; //flaga, czy obiekt się porusza

		};
	}//namespace technical
}//namespace physics
#endif//H_ACTOR_TECHNICAL_DATA_JACK
