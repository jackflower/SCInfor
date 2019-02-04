//  _____________________________________
// | CCaliber.cpp - class implementation |
// | Jack Flower - March 2016            |
// |_____________________________________|
//

#include "CCaliber.h"

namespace equipment
{
	namespace weapon
	{
		//Konstruktor
		CCaliber::CCaliber()
		:
			m_name		(),
			m_caliber	(0.0f),
			e_caliber	(CALIBER_FIREARM)
		{
		}

		//Konstruktor kopiuj¹cy
		CCaliber::CCaliber(const CCaliber& CCaliberCopy)
		:
			m_name		(CCaliberCopy.m_name),
			m_caliber	(CCaliberCopy.m_caliber),
			e_caliber	(CCaliberCopy.e_caliber)
		{
		}

		//Destruktor
		CCaliber::~CCaliber()
		{
			m_name		= "";
			m_caliber	= 0.0f;
			e_caliber	= CALIBER_FIREARM;
		}

		//Metoda zwraca nazwê kalibru
		const std::string & CCaliber::getName() const
		{
			return m_name;
		}

		//Metoda ustawia nazwê kalibru
		void CCaliber::setName(const std::string & name)
		{
			m_name = name;
		}

		///Metoda zwraca kaliber uzbrojenia
		const float CCaliber::getCaliber() const
		{
			return m_caliber;
		}

		///Metoda ustawia kaliber uzbrojenia
		void CCaliber::setCaliber(const float caliber)
		{
			m_caliber = caliber;
		}

		//Metoda zwraca sta³¹ referencjê na wyliczenie ECaliber
		const ECaliber & CCaliber::getCaliberType() const
		{
			return e_caliber;
		}

		//Metoda ustawia referencjê na wyliczenie ECaliber
		void CCaliber::setCaliberType(const ECaliber & caliber)
		{
			e_caliber = caliber;
		}

	}//namespace weapon
}//namespace equipment
