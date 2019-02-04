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

		//Konstruktor kopiuj�cy
		CGroundWork::CGroundWork(const CGroundWork & CGroundWorkCopy)
		:
			CMapPhysical					(CGroundWorkCopy),	//konstruktor kopiuj�cy klasy bazowej
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

		//Metoda zwraca wsp�czynnik tarcia
		const float CGroundWork::getFriction() const
		{
			return m_physicsground.getFriction();
		}

		//Metoda ustawia wsp�czynnik tarcia
		void CGroundWork::setFriction(float friction)
		{
			m_physicsground.setFriction(friction);
		}

		//Metoda zwraca wsp�czynnik wilgotno�ci
		const float CGroundWork::getHumidity() const
		{
			return m_physicsground.getHumidity();
		}

		//Metoda ustawia wsp�czynnik wilgotno�ci
		void CGroundWork::setHumidity(float humidity)
		{
			m_physicsground.setHumidity(humidity);
		}

		//Metoda zwraca wsp�czynnik przenikalno�ci cieplnej
		const float CGroundWork::getThermalTransmittance() const
		{
			return m_physicsground.getThermalTransmittance();
		}

		//Metoda ustawia wsp�czynnik przenikalno�ci cieplnej
		void CGroundWork::setThermalTransmittance(float thermal_transmittance)
		{
			m_physicsground.setThermalTransmittance(thermal_transmittance);
		}

		//Wirtualna metoda aktualizuj�ca obiekt
		void CGroundWork::Update(float dt)
		{
			//nothdig to do...
		}
	}//namespace groundwork
}//namespace mapengine
