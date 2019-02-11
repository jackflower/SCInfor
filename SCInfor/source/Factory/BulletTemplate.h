//  ___________________________________________
// | BulletTemplate.h - class definition       |
// | Jack Flower - November 2012               |
// |___________________________________________|
//

#ifndef H_BULLET_TEMPLATE_JACK
#define H_BULLET_TEMPLATE_JACK

#include "ActorTemplate.h"
#include "../Logic/CPhysicalManager.h"
#include "../Logic/Bullet/Bullet.h"


///
///Forward declaration
///
namespace xml
{
	class CXml;
}

using namespace logic;

namespace factory
{
	///
	///Klasa reprezentuje wzorzec pocisku
	///
	class BulletTemplate : public ActorTemplate
	{
		RTTI_DECL;
	
	public:

		///
		///Konstruktor
		///
		BulletTemplate();

		///
		///Destruktor
		///
		~BulletTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Wirtualna metoda zwalniająca zasób
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
		///Wirtualna metoda tworzenie obiektów pochodnych klasy Physical
		///
		///implementowana przez w pełni konkretne podklasy
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		Bullet *create(std::wstring id = L"");

	protected:

		///
		///Wirtualna metoda wypełniająca danymi obiekt klasy Bullet
		///
		///@param *bullet - wskaźnik na obiekt klasy Bullet
		///
		virtual void fill(Bullet *bullet);

	private:

		//Friday, February 8, 2019
		//
		//to do:
		// - składowe tej klasy wstawić na podstawie składowych
		//   klasy Bullet (po analizie)
		//

	};
}//namespace factory
#endif//H_BULLET_TEMPLATE_JACK
