//  ________________________________________________
// | CActorTechnicalData.h - class definition       |
// | Jack Flower - May 2016                         |
// |________________________________________________|
//

#ifndef H_ACTOR_TECHNICAL_DATA_JACK
#define H_ACTOR_TECHNICAL_DATA_JACK

#include "CPhysicsData.h"

using namespace physics;

namespace physics
{
	namespace technical
	{
		///
		///klasa reprezentuje opakowanie fizyki dla klasy Actor
		///
		class CActorTechnicalData : public CPhysicsData
		{
			RTTI_DECL;

		public:

			///
			///Konstruktor
			///
			CActorTechnicalData();

			///
			///Konstruktor kopiuj¹cy
			///
			///@param & CActorTechnicalDataCopy - sta³a referencja na obiekt klasy CActorTechnicalData
			///
			CActorTechnicalData(const CActorTechnicalData & CActorTechnicalDataCopy);

			///
			///Destruktor wirtualny
			///
			virtual ~CActorTechnicalData();

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;
		
			///
			///Metoda zwraca masê obiektu
			///
			const float getMass() const;

			///
			///Metoda ustawia masê obiektu
			///
			///@param mass - masa obiektu
			///
			const void setMass(float mass);

			///
			///Metoda zwraca temperaturê
			///
			const float getTemperature() const;

			///
			///Metoda ustawia temperaturê
			///
			///@param temperature - temperatura
			///
			const void setTemperature(float temperature);

			///
			///Metoda zwraca prêdkoœæ obiektu
			///
			const float getSpeed() const;

			///
			///Metoda ustawia prêdkoœæ obiektu
			///
			///@param speed - prêdkoœæ obiektu
			///
			const void setSpeed(float speed);

			///
			///Metoda zwraca flagê, czy obiekt mo¿e siê przemieszczaæ
			///
			const bool getIsMovabled() const;

			///
			///Metoda ustawia flagê, czy obiekt mo¿e siê przemieszczaæ
			///
			///@param movabled - parametr okreœlaj¹cy, czy obiekt mo¿e siê przemieszczaæ
			///
			const void setIsMovabled(bool movabled);

			///
			///Metoda zwraca flagê, czy obiekt siê porusza
			///
			bool const getIsMove() const;

			///
			///Metoda ustawia flagê, ¿e obiekt siê porusza
			///
			///@param is_move - flaga, czy obiekt siê porusza
			///
			const void setIsMove(bool is_move);

		private:

			float	m_mass;			//masa obiektu
			float	m_temperature;	//temperatura obiektu (zale¿na od klimatyzatora, wentylatora, otoczenia)
			float	m_speed;		//prêdkoœæ przemieszczania siê obiektu
			bool	m_movabled;		//flaga okreœla czy obiekt mo¿e siê przemieszczaæ
			bool	m_is_move;		//flaga, czy obiekt siê porusza

		};
	}//namespace technical
}//namespace physics
#endif//H_ACTOR_TECHNICAL_DATA_JACK
