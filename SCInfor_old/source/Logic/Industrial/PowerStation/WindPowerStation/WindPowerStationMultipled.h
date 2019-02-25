//  ______________________________________________________
// | WindPowerStationMultipled.h - class definition       |
// | Jack Flower - July 2014                              |
// |______________________________________________________|
//

#ifndef H_WIND_POWER_STATION_MULTIPLED_JACK
#define H_WIND_POWER_STATION_MULTIPLED_JACK

#include "WindPowerStation.h"
#include "../../../../Equipment/Industrial/PowerStationData/WindTurbineData.h"

using namespace equipmentpowerstationdata;

namespace logic
{
	namespace powerstation
	{
		///
		///Klasa reprezentuje funkcjonalność elektrowni wiatrowej - posiadającej cztery turbiny wiatrowe
		///
		class WindPowerStationMultipled : public WindPowerStation
		{

			RTTI_DECL;

			///
			///Deklaracja przyjaźni
			///
			friend class PhysicalManager;
				
			//Aby uzyskać obiekt WindPowerStationMultipled, należy wywołać PhysicalManager::CreateWindPowerStationMultipled();

		protected:

			///
			///Chroniony konstruktor domyślny
			///
			///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
			///
			WindPowerStationMultipled(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiujący
			///
			///@param WindPowerStationMultipledCopy - stała referencja obiekt klasy WindPowerStationMultipled
			///
			WindPowerStationMultipled(const WindPowerStationMultipled & WindPowerStationMultipledCopy);

			///
			///Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
			///
			~WindPowerStationMultipled();

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

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
