//  _________________________________________
// | IInformation.h - class definition       |
// | Jack Flower - April 2015                |
// |_________________________________________|
//

#ifndef H_IINFORMATION_JACK
#define H_IINFORMATION_JACK

#include "../RTTI/RTTI.h"
#include <string>

namespace infologic
{
	class CInfoManager;
}

using namespace infologic;

namespace information
{
	///
	///Klasa bazowa reprezentuj¹ca informacjê
	///
	class IInformation
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaŸni
		///
		friend class CInfoManager;
		
	protected:

		///
		///Chroniony konstruktor domyœlny
		///
		///@param & uniqueId - unikalny identyfikator (nadawany w CInfoManager)
		///
		IInformation(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj¹cy
		///
		///@param IInformationCopy - parametr - obiekt klasy IInformation
		///
		IInformation(const IInformation &IInformationCopy);

		///
		///Chroniony destruktor wirtualny
		///
		virtual ~IInformation();

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca unikaln¹ nazwê obiektu
		///
		const std::wstring & GetUniqueId() const;

		///
		///Metoda ustawia flagê dla obiektów gotowych do destrukcji
		///
		virtual void MarkForDelete();

		///
		///Wirtualna metoda aktualizuj¹ca obiekt
		///
		///@param dt - czas
		///
		virtual void Update(float dt);

	protected:

		std::wstring			m_unique_id;					//unikalny identyfikator (nadawany w CInfoManager)
		int						m_map_information_manager_index;//wyliczony indeks w CInfoManager
		bool					m_ready_for_destruction;		//flaga ustawia obiekty gotowe do destrukcji
	};
}//namespace information
#endif//H_IINFORMATION_JACK
