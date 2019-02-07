//  ____________________________________________
// | CBulletTemplate.h - class definition       |
// | Jack Flower - November 2012                |
// |____________________________________________|
//

#ifndef H_BULLET_TEMPLATE_JACK
#define H_BULLET_TEMPLATE_JACK

#include "CPhysicalTemplate.h"
#include "../Logic/CPhysicalManager.h"
#include "../Logic/Bullet/CBullet.h"
#include <string>
#include <vector>

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
	class CBulletTemplate : public CPhysicalTemplate
	{
		RTTI_DECL;
	
	public:

		///
		///Konstruktor
		///
		CBulletTemplate();

		///
		///Destruktor
		///
		~CBulletTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda zwalniaj¹ca zasób
		///
		void drop();

		///
		///Metoda ³aduj¹ca dane
		///
		///@param &name - sta³a referencja na std::string
		///
		bool load(const std::string &name);

		///
		///Wirtualna metoda ³aduj¹ca dane z xml
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		bool load(CXml &xml);

		///
		///Wirtualna metoda tworzenie obiektów pochodnych klasy CPhysical
		///
		///implementowana przez w pe³ni konkretne podklasy
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CBullet* create(std::wstring id = L"");

	protected:

		///
		///Wirtualna metoda wype³niaj¹ca danymi obiekt klasy CBullet
		///
		///@param *bullet - wskaŸnik na obiekt klasy CBullet
		///
		virtual void fill(CBullet *bullet);

	private:

	};
}//namespace factory
#endif//H_BULLET_TEMPLATE_JACK

