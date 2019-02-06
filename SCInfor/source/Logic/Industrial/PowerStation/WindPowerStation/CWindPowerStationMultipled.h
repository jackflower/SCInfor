//  _______________________________________________________
// | CWindPowerStationMultipled.h - class definition       |
// | Jack Flower - July 2014                               |
// |_______________________________________________________|
//

#ifndef H_WIND_POWER_STATION_MULTIPLED_JACK
#define H_WIND_POWER_STATION_MULTIPLED_JACK

#include "CWindPowerStation.h"
#include "../../../../Equipment/Industrial/PowerStationData/WindTurbineData.h"

using namespace equipmentpowerstationdata;

namespace logic
{
	namespace powerstation
	{
		///
		///Klasa reprezentuje funkcjonalno�� elektrowni wiatrowej - posiadaj�cej cztery turbiny wiatrowe
		///
		class CWindPowerStationMultipled : public CWindPowerStation
		{

			RTTI_DECL;

			///
			///Deklaracja przyja�ni
			///
			friend class CPhysicalManager;
				
			//Aby uzyska� obiekt CWindPowerStationMultipled, nale�y wywo�a� CPhysicalManager::CreateWindPowerStationMultipled();

		protected:

			///
			///Chroniony konstruktor domy�lny
			///
			CWindPowerStationMultipled(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj�cy
			///
			///@param CWindPowerStationMultipledCopy - obiekt klasy CWindPowerStationMultipled
			///
			CWindPowerStationMultipled(const CWindPowerStationMultipled &CWindPowerStationMultipledCopy);

			///
			///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
			///
			~CWindPowerStationMultipled();

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Wirtualna metoda aktualizuj�ca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		private:
			
			//
			//ctors, dtor, gets, sets, comments

			typedef std::vector<WindTurbineData *> WindTurbines;
			WindTurbines::iterator it_turbines;
			
			WindTurbines m_wind_turbines;
			
			//prywatna metoda aktualizuj�ca stan obiektu (uwzgl�dniaj�c stan turbin w kontenerze)
			void updateWindPowerStateMultipled(float dt);

			//prywatna metoda aktualizuje po�o�enie turbin w kontenerze wzgl�dem w�a�ciciela
			void updateWindturbineTransformation(float dt);
		};
	}//namespace powerstation
}//namespace logic
#endif//H_WIND_POWER_STATION_MULTIPLED_JACK
