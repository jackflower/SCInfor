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
		///Klasa reprezentuje funkcjonalność elektrowni wiatrowej - posiadającej cztery turbiny wiatrowe
		///
		class CWindPowerStationMultipled : public CWindPowerStation
		{

			RTTI_DECL;

			///
			///Deklaracja przyjaźni
			///
			friend class CPhysicalManager;
				
			//Aby uzyskać obiekt CWindPowerStationMultipled, należy wywołać CPhysicalManager::CreateWindPowerStationMultipled();

		protected:

			///
			///Chroniony konstruktor domyślny
			///
			CWindPowerStationMultipled(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiujący
			///
			///@param CWindPowerStationMultipledCopy - obiekt klasy CWindPowerStationMultipled
			///
			CWindPowerStationMultipled(const CWindPowerStationMultipled &CWindPowerStationMultipledCopy);

			///
			///Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
			///
			~CWindPowerStationMultipled();

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Wirtualna metoda aktualizująca obiekt
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
			
			//prywatna metoda aktualizująca stan obiektu (uwzględniając stan turbin w kontenerze)
			void updateWindPowerStateMultipled(float dt);

			//prywatna metoda aktualizuje położenie turbin w kontenerze względem właściciela
			void updateWindturbineTransformation(float dt);
		};
	}//namespace powerstation
}//namespace logic
#endif//H_WIND_POWER_STATION_MULTIPLED_JACK
