//  ____________________________________________
// | CEntityTranslator.h - class definition     |
// | Jack Flower April 2016                     |
// |____________________________________________|
//

#ifndef H_ENTITY_TRANSLATOR_JACK
#define H_ENTITY_TRANSLATOR_JACK

#include <map>
#include <string>
#include "../../Utilities/Singleton/CSingleton.h"
#include "../../Equipment/Weapon/ECaliber.h"

#define gEntityTranslator CEntityTranslator::GetSingleton()

using namespace equipment::weapon;

///
///Klasa reprezentuje translator std::string => Entity (np. typ wyliczeniowy)
///
class CEntityTranslator : public CSingleton<CEntityTranslator>
{

public:

	///
	///Konstruktor domyœlny
	///
	CEntityTranslator(void);

	///
	///Destruktor
	///
	~CEntityTranslator(void);

	///
	///Metoda rejestruje w translatorze obiekty ECaliber
	///
	///@param & string_caliber_entity - sta³a referencja na obiekt klasy std::string - nazwa klucza
	///
	///@param & caliber_entity - sta³a referencja na wyliczenie ECaliber
	///
	bool RegisterCaliberEntity (const std::string & string_caliber_entity, const ECaliber & caliber_entity);

	///
	///Metoda zwraca typ ECaliber z kontenera na podstawie klucza
	///
	///@param &string_caliber_entity - nazwa skojarzona z typem
	///
	ECaliber TranslateToCaliberEntity (const std::string &string_caliber_entity);

	///
	///Metoda usuwa z translatora zarejestrowane obiekty
	///
	const void ReleaseTranslateEntity(void);

protected:

	///
	///Wirtualna metoda czyszcz¹ca singleton
	///
	virtual void Cleanup();

private:

	typedef std::map <std::string, ECaliber> CaliberEntityMap;	//definicja typu pojemnika asocjacyjnego
	CaliberEntityMap m_caliber_entity_map;						//pojemnik
};
#endif //H_ENTITY_TRANSLATOR_JACK
