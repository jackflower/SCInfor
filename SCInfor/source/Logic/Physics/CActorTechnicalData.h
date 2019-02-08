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
			///Konstruktor kopiuj�cy
			///
			///@param & CActorTechnicalDataCopy - sta�a referencja na obiekt klasy CActorTechnicalData
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
			///Metoda zwraca mas� obiektu
			///
			const float getMass() const;

			///
			///Metoda ustawia mas� obiektu
			///
			///@param mass - masa obiektu
			///
			const void setMass(float mass);

			///
			///Metoda zwraca temperatur�
			///
			const float getTemperature() const;

			///
			///Metoda ustawia temperatur�
			///
			///@param temperature - temperatura
			///
			const void setTemperature(float temperature);

			///
			///Metoda zwraca pr�dko�� obiektu
			///
			const float getSpeed() const;

			///
			///Metoda ustawia pr�dko�� obiektu
			///
			///@param speed - pr�dko�� obiektu
			///
			const void setSpeed(float speed);

			///
			///Metoda zwraca flag�, czy obiekt mo�e si� przemieszcza�
			///
			const bool getIsMovabled() const;

			///
			///Metoda ustawia flag�, czy obiekt mo�e si� przemieszcza�
			///
			///@param movabled - parametr okre�laj�cy, czy obiekt mo�e si� przemieszcza�
			///
			const void setIsMovabled(bool movabled);

			///
			///Metoda zwraca flag�, czy obiekt si� porusza
			///
			bool const getIsMove() const;

			///
			///Metoda ustawia flag�, �e obiekt si� porusza
			///
			///@param is_move - flaga, czy obiekt si� porusza
			///
			const void setIsMove(bool is_move);

		private:

			float	m_mass;			//masa obiektu
			float	m_temperature;	//temperatura obiektu (zale�na od klimatyzatora, wentylatora, otoczenia)
			float	m_speed;		//pr�dko�� przemieszczania si� obiektu
			bool	m_movabled;		//flaga okre�la czy obiekt mo�e si� przemieszcza�
			bool	m_is_move;		//flaga, czy obiekt si� porusza

		};
	}//namespace technical
}//namespace physics
#endif//H_ACTOR_TECHNICAL_DATA_JACK
