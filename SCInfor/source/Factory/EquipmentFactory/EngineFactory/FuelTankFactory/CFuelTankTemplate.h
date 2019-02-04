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
		///Wirtualna metoda zwalniaj¹ca zasób
		///
		void Drop();

		///
		///Wirtualna metoda ³aduj¹ca dane
		///
		///@param &name - sta³a referencja na std::string
		///
		bool Load(const std::string &name);

		///
		///Wirtualna metoda ³aduj¹ca dane z xml wywo³ywana przez implementacje klas potomnych
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
		///Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
		///
		///@param *p_fueltank - wskaŸnik na obiekt klasy CFuelTank
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
		float			m_templ_fuel_tank_capacity;	//pojemnoœæ zbiornika paliwa (materia³ pêdny) w szablonie
		float			m_templ_fuel;				//iloœæ paliwa - (materia³u pêdnego) w szablonie
	};
}//namespace factory
#endif//H_FUEL_TANK_TEMPLATE_JACK
