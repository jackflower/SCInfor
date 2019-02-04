//  ______________________________________________
// | CFuelTankTemplate.h - class definition       |
// | Jack Flower - November 2013                  |
// |______________________________________________|
//

#ifndef H_FUEL_TANK_TEMPLATE_JACK
#define H_FUEL_TANK_TEMPLATE_JACK

#include "../../../../ResourceManager/IResource.h"
#include "../../../../Factory/CActorTemplate.h"
#include "../../../../XML/CXml.h"
#include "../../../../RTTI/RTTI.h"
#include "../../../../Equipment/Engine/FuelTank/CFuelTank.h"

using namespace logic;
using namespace resource;
using namespace xml;
using namespace equipment;

namespace factory
{
	///
	///Klasa reprezentuje wzorzec zbiornika paliwa
	///
	class CFuelTankTemplate : public CActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CFuelTankTemplate(void);

		///
		///Destruktor
		///
		~CFuelTankTemplate(void);

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda zwalniaj�ca zas�b
		///
		void Drop();

		///
		///Wirtualna metoda �aduj�ca dane
		///
		///@param &name - sta�a referencja na std::string
		///
		bool Load(const std::string &name);

		///
		///Wirtualna metoda �aduj�ca dane z xml wywo�ywana przez implementacje klas potomnych
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		virtual bool Load(CXml &xml);

		///
		///Metoda tworzy obiekt klasy CFuelTank
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CFuelTank* Create(std::wstring id = L"");

		///
		///Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
		///
		///@param *p_fueltank - wska�nik na obiekt klasy CFuelTank
		///
		virtual void Fill(CFuelTank *p_fueltank);


		//metody  p o m o c n i c z e

		inline void SetFuelTankName(const std::string& templ_fuel_tank_name)
		{
			m_templ_fuel_tank_name = templ_fuel_tank_name;
		}
		inline void SetFuelTankCapacity(float templ_fuel_tank_capacity)
		{
			m_templ_fuel_tank_capacity = templ_fuel_tank_capacity;
		}
		inline void SetFuel(float templ_fuel)
		{
			m_templ_fuel = templ_fuel;
		}
		inline const std::string GetFuelTankName() const
		{
			return m_templ_fuel_tank_name;
		}
		inline const float GetFuelTankCapacity() const
		{
			return m_templ_fuel_tank_capacity;
		}
		inline const float GetFuel() const
		{
			return m_templ_fuel;
		}

	private:

		std::string		m_templ_fuel_tank_name;		//nazwa zbiornika paliwa w szablonie
		float			m_templ_fuel_tank_capacity;	//pojemno�� zbiornika paliwa (materia� p�dny) w szablonie
		float			m_templ_fuel;				//ilo�� paliwa - (materia�u p�dnego) w szablonie
	};
}//namespace factory
#endif//H_FUEL_TANK_TEMPLATE_JACK
