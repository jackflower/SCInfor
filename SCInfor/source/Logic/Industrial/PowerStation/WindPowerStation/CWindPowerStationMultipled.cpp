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

		//Chroniony konstruktor domyœlny
		CWindPowerStationMultipled::CWindPowerStationMultipled(const std::wstring& uniqueId)
		:
			CWindPowerStation	(uniqueId)//,//konstruktor klasy bazowej
		{
		}

		//Chroniony konstruktor kopiuj¹cy
		CWindPowerStationMultipled::CWindPowerStationMultipled(const CWindPowerStationMultipled &CWindPowerStationMultipledCopy)
		:
			CWindPowerStation	(CWindPowerStationMultipledCopy)//,//konstruktor kopiuj¹cy klasy bazowej
		{
		}

		//Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
		CWindPowerStationMultipled::~CWindPowerStationMultipled()
		{
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CWindPowerStationMultipled::GetType() const
		{
			return rtti.GetNameClass();
		}

		//Wirtualna metoda aktualizuj¹ca obiekt
		void CWindPowerStationMultipled::update(float dt)
		{
			//aktualizacja shadow engine
			CPhysical::UpdateShadow(dt);

			//Wywo³anie z klasy bazowej - AI logowania do systemu...
			CPowerStation::update(dt);

			//jeœli urz¹dzenie jest w³¹czone
			if (m_unit_controller.getState())
			{
				updateWindPowerStateMultipled(dt);
				updateAnimations(dt);
			}

			//jeœli flaga jest ustawiona na true - obraca siê modu³ - korpus (HEAD)
			if (m_use_rotation_head)
				RotateHead(m_speed_rotation_head);
			//transformacja
			updateWindturbineTransformation(dt);
		}

		//prywatna metoda aktualizuj¹ca stan obiektu (uwzglêdniaj¹c stan turbin w kontenerze)
		void CWindPowerStationMultipled::updateWindPowerStateMultipled(float dt)
		{
			//bêdzie wt³oczony kod, który przeliczy kondensacjê energii elektrowni,
			//uwzglêdniaj¹c iloœæ turin w kontenerze...
			//czyli pobranie size() z kontenera...
			//(kiedy wykluczyæ turbinê z elektrowni...?)
			//
			//wt³oczyæ kod z klasy bazowej...
			//
			//bêdzie koniecznoœæ poruszanie siê po kontenerze...for(...)
		}

		//prywatna metoda aktualizuje sk³adowe transformacji wzglêdem w³aœciciela
		void CWindPowerStationMultipled::updateWindturbineTransformation(float dt)
		{
			for (it_turbines = m_wind_turbines.begin(); it_turbines != m_wind_turbines.end(); it_turbines++)
			{
				(*it_turbines)->Transform(this, (*it_turbines)->getTurbine());
			}
		}

	}//namespace powerstation
}//namespace logic
