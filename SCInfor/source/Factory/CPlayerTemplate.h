//  ____________________________________________
// | CPlayerTemplate.h - class definition       |
// | Jack Flower - May 2013                     |
// |____________________________________________|
//

#ifndef H_PLAYER_TEMPLATE_JACK
#define H_PLAYER_TEMPLATE_JACK

#include "CActorTemplate.h"
#include "../Logic/Player/CPlayer.h"
#include <string>
#include <vector>

///
///Forward declaration
///
namespace xml
{
	class CXml;
}

namespace factory
{
	///
	///Klasa reprezentuje generyczny wzorzec wrogiej jednostki
	///
	class CPlayerTemplate : public CActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CPlayerTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~CPlayerTemplate();

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
		///Wirtualna metoda ³aduj¹ca dane z xml
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		bool Load(CXml &xml);

		///
		///Metoda tworzy obiekt klasy CPlayer
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CPlayer* Create(std::wstring id = L"");

	private:

		std::vector<std::wstring> m_player_AI;	//kontener nazw dostêpnych schematów AI gracza...to do...
	};
}//namespace factory
#endif //H_PLAYER_TEMPLATE_JACK
