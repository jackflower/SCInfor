//  _____________________________________________
// | FuelTankTemplate.h - class definition       |
// | Jack Flower - November 2013                 |
// |_____________________________________________|
//

#ifndef H_FUEL_TANK_TEMPLATE_JACK
#define H_FUEL_TANK_TEMPLATE_JACK

#include "../../../../ResourceManager/Resource.h"
#include "../../../../Factory/ActorTemplate.h"
#include "../../../../XML/CXml.h"
#include "../../../../RTTI/RTTI.h"
#include "../../../../Equipment/Engine/FuelTank/FuelTank.h"

using namespace logic;
using namespace resource;
using namespace xml;
using namespace equipment;

namespace factory
{
	///
	///Klasa reprezentuje wzorzec zbiornika paliwa
	///
	class FuelTankTemplate : public ActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		FuelTankTemplate();

		///
		///Destruktor
		///
		~FuelTankTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Wirtualna metoda zwalniająca zasób
		///
		void drop();

		///
		///Wirtualna metoda ładująca dane
		///
		///@param name - stała referencja na std::string
		///
		bool load(const std::string & name);

		///
		///Wirtualna metoda ładująca dane z xml wywoływana przez implementacje klas potomnych
		///
		///@param xml - referencja na obiekt klasy CXml
		///
		virtual bool load(CXml & xml);

		///
		///Metoda tworzy obiekt klasy FuelTank
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		FuelTank *create(std::wstring id = L"");

		///
		///Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
		///
		///@param *p_fueltank - wskaźnik na obiekt klasy FuelTank
		///
		virtual void fill(FuelTank *p_fueltank);


		//metody  p o m o c n i c z e

		inline void setFuelTankName(const std::string& templ_fuel_tank_name)
		{
			m_templ_fuel_tank_name = templ_fuel_tank_name;
		}
		inline void setFuelTankCapacity(float templ_fuel_tank_capacity)
		{
			m_templ_fuel_tank_capacity = templ_fuel_tank_capacity;
		}
		inline void setFuel(float templ_fuel)
		{
			m_templ_fuel = templ_fuel;
		}
		inline const std::string getFuelTankName() const
		{
			return m_templ_fuel_tank_name;
		}
		inline const float getFuelTankCapacity() const
		{
			return m_templ_fuel_tank_capacity;
		}
		inline const float getFuel() const
		{
			return m_templ_fuel;
		}

	private:

		std::string m_templ_fuel_tank_name; //nazwa zbiornika paliwa w szablonie
		float m_templ_fuel_tank_capacity; //pojemność zbiornika paliwa (materiał pędny) w szablonie
		float m_templ_fuel; //ilość paliwa - (materiału pędnego) w szablonie
	};
}//namespace factory
#endif//H_FUEL_TANK_TEMPLATE_JACK
