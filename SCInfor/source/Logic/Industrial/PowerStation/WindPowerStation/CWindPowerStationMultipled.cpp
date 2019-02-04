//  _______________________________________________________
// | CWindPowerStationMultipled.cpp - class implementation |
// | Jack Flower - July 2014                               |
// |_______________________________________________________|
//

#include "CWindPowerStationMultipled.h"
#include "../../../../Logic/CPhysicalManager.h"

namespace logic
{
	namespace powerstation
	{
		RTTI_IMPL(CWindPowerStationMultipled, CWindPowerStation);

		//Chroniony konstruktor domy�lny
		CWindPowerStationMultipled::CWindPowerStationMultipled(const std::wstring& uniqueId)
		:
			CWindPowerStation	(uniqueId)//,//konstruktor klasy bazowej
		{
		}

		//Chroniony konstruktor kopiuj�cy
		CWindPowerStationMultipled::CWindPowerStationMultipled(const CWindPowerStationMultipled &CWindPowerStationMultipledCopy)
		:
			CWindPowerStation	(CWindPowerStationMultipledCopy)//,//konstruktor kopiuj�cy klasy bazowej
		{
		}

		//Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
		CWindPowerStationMultipled::~CWindPowerStationMultipled()
		{
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CWindPowerStationMultipled::GetType() const
		{
			return rtti.GetNameClass();
		}

		//Wirtualna metoda aktualizuj�ca obiekt
		void CWindPowerStationMultipled::update(float dt)
		{
			//aktualizacja shadow engine
			CPhysical::UpdateShadow(dt);

			//Wywo�anie z klasy bazowej - AI logowania do systemu...
			CPowerStation::update(dt);

			//je�li urz�dzenie jest w��czone
			if (m_unit_controller.getState())
			{
				updateWindPowerStateMultipled(dt);
				updateAnimations(dt);
			}

			//je�li flaga jest ustawiona na true - obraca si� modu� - korpus (HEAD)
			if (m_use_rotation_head)
				RotateHead(m_speed_rotation_head);
			//transformacja
			updateWindturbineTransformation(dt);
		}

		//prywatna metoda aktualizuj�ca stan obiektu (uwzgl�dniaj�c stan turbin w kontenerze)
		void CWindPowerStationMultipled::updateWindPowerStateMultipled(float dt)
		{
			//b�dzie wt�oczony kod, kt�ry przeliczy kondensacj� energii elektrowni,
			//uwzgl�dniaj�c ilo�� turin w kontenerze...
			//czyli pobranie size() z kontenera...
			//(kiedy wykluczy� turbin� z elektrowni...?)
			//
			//wt�oczy� kod z klasy bazowej...
			//
			//b�dzie konieczno�� poruszanie si� po kontenerze...for(...)
		}

		//prywatna metoda aktualizuje sk�adowe transformacji wzgl�dem w�a�ciciela
		void CWindPowerStationMultipled::updateWindturbineTransformation(float dt)
		{
			for (it_turbines = m_wind_turbines.begin(); it_turbines != m_wind_turbines.end(); it_turbines++)
			{
				(*it_turbines)->Transform(this, (*it_turbines)->getTurbine());
			}
		}

	}//namespace powerstation
}//namespace logic
