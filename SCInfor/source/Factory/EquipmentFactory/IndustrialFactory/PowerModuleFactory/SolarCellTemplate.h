//  ______________________________________________
// | SolarCellTemplate.h - class definition       |
// | Jack Flower - August 2014                    |
// |______________________________________________|
//

#ifndef H_SOLAR_CELL_TEMPLATE_JACK
#define H_SOLAR_CELL_TEMPLATE_JACK

#include "../../../ActorTemplate.h"
#include "../../../../Equipment/Industrial/PowerModuleType/SolarCell.h"

namespace factory
{
	///
	///Klasa reprezentuje wzorzec fotoogniwa
	///
	class SolarCellTemplate : public ActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		SolarCellTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~SolarCellTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Wirtualna metoda zwalniająca zasób - implementacje w klasach pochodnych
		///
		void drop();

		///
		///Metoda ładująca dane
		///
		///@param name - stała referencja na std::string
		///
		bool load(const std::string & name);

		///
		///Wirtualna metoda ładująca dane z xml ładuje wspólne cechy Actor
		///
		///@param xml - referencja na obiekt klasy Xml
		///
		bool load(Xml & xml);

	protected:
	
		///
		///Metoda tworzy obiekt klasy SolarCellTemplate
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		SolarCell *create(std::wstring id = L"");

		///
		///Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
		///
		///@param *p_solarcell - wskaźnik na obiekt klasy SolarCell
		///
		virtual void fill(SolarCell *p_solarcell);

	private:

		std::string m_templ_solarcell_name; //nazwa fotoogniwa
		float m_templ_stored_energy; //energia, która może zostać zgromadzona
		float m_templ_power; //moc
		float m_templ_energy_duration; //czas, co jaki następuje proces ładowania fotoogniwa
		float m_templ_rotation_speed; //prędkość obrotu obiektu
	};
}//namespace factory
#endif//H_SOLAR_CELL_TEMPLATE_JACK
