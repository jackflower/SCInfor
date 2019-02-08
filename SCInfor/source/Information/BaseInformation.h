//  ____________________________________________
// | BaseInformation.h - class definition       |
// | Jack Flower - April 2015                   |
// |____________________________________________|
//

#ifndef H_BASEINFORMATION_JACK
#define H_BASEINFORMATION_JACK

#include "../RTTI/RTTI.h"

namespace infologic
{
	class InfoManager;
}

using namespace infologic;

namespace information
{
	///
	///Klasa bazowa reprezentująca informację
	///
	class BaseInformation
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaźni
		///
		friend class InfoManager;
		
	protected:

		///
		///Chroniony konstruktor domyślny
		///
		///@param uniqueId - unikalny identyfikator (nadawany w InfoManager)
		///
		BaseInformation(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiujący
		///
		///@param InformationCopy - parametr - obiekt klasy BaseInformation
		///
		BaseInformation(const BaseInformation & InformationCopy);

		///
		///Chroniony destruktor wirtualny
		///
		virtual ~BaseInformation();

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca unikalną nazwę obiektu
		///
		const std::wstring & getUniqueId() const;

		///
		///Metoda ustawia flagę dla obiektów gotowych do destrukcji
		///
		virtual void markForDelete();

		///
		///Wirtualna metoda aktualizująca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);

	protected:

		std::wstring m_unique_id; //unikalny identyfikator (nadawany w InfoManager)
		int m_map_information_manager_index; //wyliczony indeks w InfoManager
		bool m_ready_for_destruction; //flaga ustawia obiekty gotowe do destrukcji
	};
}//namespace information
#endif//H_BASEINFORMATION_JACK
