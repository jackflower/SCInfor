//  ________________________________________
// | CGroundWork.cpp - class implementation |
// | Jack Flower - March 2015               |
// |________________________________________|
//

#include "CGroundWork.h"
#include "../../../Utilities/StringUtils/StringUtils.h"

using namespace stringutils;

namespace mapengine
{
	namespace groundwork
	{
		RTTI_IMPL(CGroundWork, CMapPhysical);

		//Konstruktor
		CGroundWork::CGroundWork(const std::wstring& uniqueId)
		:
			CMapPhysical					(uniqueId),	//konstruktor klasy bazowej
			m_physicsground					()
		{
		}

		//Konstruktor kopiuj¹cy
		CGroundWork::CGroundWork(const CGroundWork & CGroundWorkCopy)
		:
			CMapPhysical					(CGroundWorkCopy),	//konstruktor kopiuj¹cy klasy bazowej
			m_physicsground					(CGroundWorkCopy.m_physicsground)
		{
		}

		//Destruktor
		CGroundWork::~CGroundWork()
		{
			//CMapPhysical					not edit
			//m_physicsground				not edit
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CGroundWork::GetType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca wspó³czynnik tarcia
		const float CGroundWork::getFriction() const
		{
			return m_physicsground.getFriction();
		}

		//Metoda ustawia wspó³czynnik tarcia
		void CGroundWork::setFriction(float friction)
		{
			m_physicsground.setFriction(friction);
		}

		//Metoda zwraca wspó³czynnik wilgotnoœci
		const float CGroundWork::getHumidity() const
		{
			return m_physicsground.getHumidity();
		}

		//Metoda ustawia wspó³czynnik wilgotnoœci
		void CGroundWork::setHumidity(float humidity)
		{
			m_physicsground.setHumidity(humidity);
		}

		//Metoda zwraca wspó³czynnik przenikalnoœci cieplnej
		const float CGroundWork::getThermalTransmittance() const
		{
			return m_physicsground.getThermalTransmittance();
		}

		//Metoda ustawia wspó³czynnik przenikalnoœci cieplnej
		void CGroundWork::setThermalTransmittance(float thermal_transmittance)
		{
			m_physicsground.setThermalTransmittance(thermal_transmittance);
		}

		//Wirtualna metoda aktualizuj¹ca obiekt
		void CGroundWork::Update(float dt)
		{
			//nothdig to do...
		}
	}//namespace groundwork
}//namespace mapengine
