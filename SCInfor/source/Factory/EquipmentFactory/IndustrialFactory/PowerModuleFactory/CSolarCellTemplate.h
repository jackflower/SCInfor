//  _______________________________________________
// | CSolarCellTemplate.h - class definition       |
// | Jack Flower - August 2014                     |
// |_______________________________________________|
//

#ifndef H_SOLAR_CELL_TEMPLATE_JACK
#define H_SOLAR_CELL_TEMPLATE_JACK

#include "../../../CActorTemplate.h"
#include "../../../../Equipment/Industrial/PowerModuleType/SolarCell.h"

namespace factory
{
	///
	///Klasa reprezentuje wzorzec fotoogniwa
	///
	class CSolarCellTemplate : public CActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CSolarCellTemplate(void);

		///
		///Destruktor wirtualny
		///
		virtual ~CSolarCellTemplate(void);

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda zwalniaj¹ca zasób - implementacje w klasach pochodnych
		///
		void Drop();

		///
		///Metoda ³aduj¹ca dane
		///
		///@param &name - sta³a referencja na std::string
		///
		bool Load(const std::string &name);

		///
		///Wirtualna metoda ³aduj¹ca dane z xml ³aduje wspólne cechy CActor
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		bool Load(CXml &xml);

	protected:
	
		///
		///Metoda tworzy obiekt klasy CSolarCellTemplate
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		SolarCell* Create(std::wstring id = L"");

		///
		///Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
		///
		///@param *p_solarcell - wskaŸnik na obiekt klasy SolarCell
		///
		virtual void Fill(SolarCell *p_solarcell);

	private:

		std::string		m_templ_solarcell_name;			//nazwa fotoogniwa
		float			m_templ_stored_energy;			//energia, która mo¿e zostaæ zgromadzona
		float			m_templ_power;					//moc
		float			m_templ_energy_duration;		//czas, co jaki nastêpuje proces ³adowania fotoogniwa
		float			m_templ_rotation_speed;			//prêdkoœæ obrotu obiektu
	};
}//namespace factory
#endif//H_SOLAR_CELL_TEMPLATE_JACK