//  ___________________________________________
// | PlayerTemplate.h - class definition       |
// | Jack Flower - May 2013                    |
// |___________________________________________|
//

#ifndef H_PLAYER_TEMPLATE_JACK
#define H_PLAYER_TEMPLATE_JACK

#include "ActorTemplate.h"
#include "../Logic/Player/CPlayer.h"

namespace factory
{
	///
	///Klasa reprezentuje generyczny wzorzec wrogiej jednostki
	///
	class PlayerTemplate : public ActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		PlayerTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~PlayerTemplate();

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
		///Wirtualna metoda ładująca dane z xml
		///
		///@param xml - referencja na obiekt klasy CXml
		///
		bool load(CXml & xml);

		///
		///Metoda tworzy obiekt klasy CPlayer
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CPlayer *create(std::wstring id = L"");

	private:

		std::vector<std::wstring> m_player_AI; //kontener nazw dostępnych schematów AI gracza...to do...
	};
}//namespace factory
#endif //H_PLAYER_TEMPLATE_JACK
