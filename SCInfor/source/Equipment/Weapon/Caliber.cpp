//  ____________________________________
// | Caliber.cpp - class implementation |
// | Jack Flower - March 2016           |
// |____________________________________|
//

#include "Caliber.h"

namespace equipment
{
	namespace weapon
	{
		//Konstruktor
		Caliber::Caliber()
		:
			m_name{},
			m_caliber{ 0.0f },
			e_caliber{ ECaliber::CALIBER_FIREARM }
		{
		}

		//Konstruktor kopiujący
		Caliber::Caliber(const Caliber& CaliberCopy)
		:
			m_name{ CaliberCopy.m_name },
			m_caliber{ CaliberCopy.m_caliber },
			e_caliber{ CaliberCopy.e_caliber }
		{
		}

		//Destruktor
		Caliber::~Caliber()
		{
			m_name = "";
			m_caliber = 0.0f;
			e_caliber = ECaliber::CALIBER_FIREARM;
		}

		//Metoda zwraca nazwę kalibru
		const std::string & Caliber::getName() const
		{
			return m_name;
		}

		//Metoda ustawia nazwę kalibru
		void Caliber::setName(const std::string & name)
		{
			m_name = name;
		}

		///Metoda zwraca kaliber uzbrojenia
		const float Caliber::getCaliber() const
		{
			return m_caliber;
		}

		///Metoda ustawia kaliber uzbrojenia
		void Caliber::setCaliber(const float caliber)
		{
			m_caliber = caliber;
		}

		//Metoda zwraca stałą referencję na wyliczenie ECaliber
		const ECaliber & Caliber::getCaliberType() const
		{
			return e_caliber;
		}

		//Metoda ustawia referencję na wyliczenie ECaliber
		void Caliber::setCaliberType(const ECaliber & caliber)
		{
			e_caliber = caliber;
		}

	}//namespace weapon
}//namespace equipment
