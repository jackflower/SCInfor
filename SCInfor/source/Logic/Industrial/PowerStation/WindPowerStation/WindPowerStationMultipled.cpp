//  ______________________________________________________
// | WindPowerStationMultipled.cpp - class implementation |
// | Jack Flower - July 2014                              |
// |______________________________________________________|
//

#include "WindPowerStationMultipled.h"
#include "../../../../Logic/CPhysicalManager.h"

namespace logic
{
	namespace powerstation
	{
		RTTI_IMPL(WindPowerStationMultipled, WindPowerStation);

		//Chroniony konstruktor domyślny
		WindPowerStationMultipled::WindPowerStationMultipled(const std::wstring& uniqueId)
		:
			WindPowerStation(uniqueId),//konstruktor klasy bazowej
			m_wind_turbines()
		{
		}

		//Chroniony konstruktor kopiujący
		WindPowerStationMultipled::WindPowerStationMultipled(const WindPowerStationMultipled & WindPowerStationMultipledCopy)
		:
			WindPowerStation( WindPowerStationMultipledCopy),//konstruktor kopiujący klasy bazowej
			m_wind_turbines(WindPowerStationMultipledCopy.m_wind_turbines)
		{
		}

		//Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
		WindPowerStationMultipled::~WindPowerStationMultipled()
		{
			//~WindPowerStation()
			//m_wind_turbines
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string WindPowerStationMultipled::getType() const
		{
			return rtti.GetNameClass();
		}

		//Wirtualna metoda aktualizująca obiekt
		void WindPowerStationMultipled::update(float dt)
		{
			//aktualizacja shadow engine
			CPhysical::UpdateShadow(dt);

			//Wywołanie z klasy bazowej - AI logowania do systemu...
			PowerStation::update(dt);

			//jeśli urządzenie jest włączone
			if (m_unit_controller.getState())
			{
				updateWindPowerStateMultipled(dt);
				updateAnimations(dt);
			}

			//jeśli flaga jest ustawiona na true - obraca się moduł - korpus (HEAD)
			if (m_use_rotation_head)
				RotateHead(m_speed_rotation_head);
			//transformacja
			updateWindturbineTransformation(dt);
		}

		//prywatna metoda aktualizująca stan obiektu (uwzględniając stan turbin w kontenerze)
		void WindPowerStationMultipled::updateWindPowerStateMultipled(float dt)
		{
			//będzie wtłoczony kod, który przeliczy kondensację energii elektrowni,
			//uwzględniając ilość turin w kontenerze...
			//czyli pobranie size() z kontenera...
			//(kiedy wykluczyć turbinę z elektrowni...?)
			//
			//wtłoczyć kod z klasy bazowej...
			//
			//będzie konieczność poruszanie się po kontenerze...for(...)
		}

		//prywatna metoda aktualizuje składowe transformacji względem właściciela
		void WindPowerStationMultipled::updateWindturbineTransformation(float dt)
		{
			for (it_turbines = m_wind_turbines.begin(); it_turbines != m_wind_turbines.end(); it_turbines++)
			{
				(*it_turbines)->Transform(this, (*it_turbines)->getTurbine());
			}
		}

	}//namespace powerstation
}//namespace logic
