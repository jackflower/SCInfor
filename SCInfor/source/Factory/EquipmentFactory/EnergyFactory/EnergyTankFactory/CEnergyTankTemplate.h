//  ________________________________________________
// | CEnergyTankTemplate.h - class definition       |
// | Jack Flower - November 2013                    |
// |________________________________________________|
//

#ifndef H_ENERGY_TANK_TEMPLATE_JACK
#define H_ENERGY_TANK_TEMPLATE_JACK

#include "../../../../ResourceManager/IResource.h"
#include "../../../../Factory/CActorTemplate.h"
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
	class CEnergyTankTemplate : public CActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CEnergyTankTemplate(void);

		///
		///Destruktor
		///
		~CEnergyTankTemplate(void);

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
		///Wirtualna metoda ³aduj¹ca dane z xml
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		virtual bool Load(CXml &xml);

		///
		///Metoda tworzy obiekt klasy EnergyTank
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		EnergyTank* Create(std::wstring id = L"");

		///
		///Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
		///
		///@param *p_energytank - wskaŸnik na obiekt klasy EnergyTank
		///
		virtual void Fill(EnergyTank *p_energytank);


		//metody  p o m o c n i c z e
		inline void SetEnergyTankName(const std::string& templ_energy_tank_name)
		{
			m_templ_energy_tank_name = templ_energy_tank_name;
		}
		inline void SetEnergyTankCapacity(float templ_energy_tank_capacity)
		{
			m_templ_energy_tank_capacity = templ_energy_tank_capacity;
		}
		inline void SetEnergy(float templ_energy)
		{
			m_templ_energy = templ_energy;
		}
		inline const std::string GetEnergyTankName() const
		{
			return m_templ_energy_tank_name;
		}
		inline const float GetEnergyTankCapacity() const
		{
			return m_templ_energy_tank_capacity;
		}
		inline const float GetEnergy() const
		{
			return m_templ_energy;
		}
		inline const float GetEnergyTankRotationSpeed() const
		{
			return m_templ_energy_tank_rotation_speed;
		}

	private:

		std::string		m_templ_energy_tank_name;			//nazwa akumulatora energii w szablonie
		float			m_templ_energy_tank_capacity;		//pojemnoœæ akumulatora energii w szablonie
		float			m_templ_energy;						//iloœæ energii w szablonie
		float			m_templ_energy_tank_rotation_speed;	//prêdkoœæ wirowania wskaŸnika stanu akumulatora
	};
}//namespace factory
#endif//H_ENERGY_TANK_TEMPLATE_JACK
