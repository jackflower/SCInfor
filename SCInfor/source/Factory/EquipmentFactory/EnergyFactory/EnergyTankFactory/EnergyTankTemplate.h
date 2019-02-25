//  _______________________________________________
// | EnergyTankTemplate.h - class definition       |
// | Jack Flower - November 2013                   |
// |_______________________________________________|
//

#ifndef H_ENERGY_TANK_TEMPLATE_JACK
#define H_ENERGY_TANK_TEMPLATE_JACK

#include "../../../../ResourceManager/Resource.h"
#include "../../../../Factory/ActorTemplate.h"
#include "../../../../XML/CXml.h"
#include "../../../../RTTI/RTTI.h"
#include "../../../../Equipment/Energy/EnergyTank/EnergyTank.h"

using namespace logic;
using namespace resource;
using namespace xml;
using namespace equipment;

namespace factory
{
	///
	///Klasa reprezentuje wzorzec akumulatora energii
	///
	class EnergyTankTemplate : public ActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		EnergyTankTemplate();

		///
		///Destruktor
		///
		~EnergyTankTemplate();

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
		///Wirtualna metoda ładująca dane z xml
		///
		///@param xml - referencja na obiekt klasy CXml
		///
		virtual bool load(CXml & xml);

		///
		///Metoda tworzy obiekt klasy EnergyTank
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		EnergyTank *create(std::wstring id = L"");

		///
		///Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
		///
		///@param *p_energytank - wskaźnik na obiekt klasy EnergyTank
		///
		virtual void fill(EnergyTank *p_energytank);


		//metody  p o m o c n i c z e
		inline void setEnergyTankName(const std::string & templ_energy_tank_name)
		{
			m_templ_energy_tank_name = templ_energy_tank_name;
		}
		inline void setEnergyTankCapacity(float templ_energy_tank_capacity)
		{
			m_templ_energy_tank_capacity = templ_energy_tank_capacity;
		}
		inline void setEnergy(float templ_energy)
		{
			m_templ_energy = templ_energy;
		}
		inline const std::string getEnergyTankName() const
		{
			return m_templ_energy_tank_name;
		}
		inline const float getEnergyTankCapacity() const
		{
			return m_templ_energy_tank_capacity;
		}
		inline const float getEnergy() const
		{
			return m_templ_energy;
		}
		inline const float getEnergyTankRotationSpeed() const
		{
			return m_templ_energy_tank_rotation_speed;
		}

	private:

		std::string m_templ_energy_tank_name; //nazwa akumulatora energii w szablonie
		float m_templ_energy_tank_capacity;	 //pojemność akumulatora energii w szablonie
		float m_templ_energy; //ilość energii w szablonie
		float m_templ_energy_tank_rotation_speed; //prędkość wirowania wskaźnika stanu akumulatora
	};
}//namespace factory
#endif//H_ENERGY_TANK_TEMPLATE_JACK
