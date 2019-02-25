//  ____________________________________________
// | CEntityTranslator.h - class implementation |
// | Jack Flower April 2016                     |
// |____________________________________________|
//

#include "CEntityTranslator.h"

template<> CEntityTranslator* CSingleton<CEntityTranslator>::m_singleton = 0;

CEntityTranslator::CEntityTranslator(void)
:
	m_caliber_entity_map()
{
	//CALIBER_FIREARM			= 0,	ka¿da broñ palna	"caliber_firearm"
	//CALIBER_SMALL_ARMS		= 1,	broñ rêczna			"caliber_small_arms"
	//CALIBER_AUTOMATIC_WEAPONS	= 2,	broñ automatyczna	"caliber_automatic_weapons"
	//CALIBER_RIFLE				= 3,	strzelba/karabin	"caliber_rifle"
	//CALIBER_ROCKET			= 4,	rakieta				"caliber_rocket"
	//CALIBER_GUN				= 5,	pistolet			"caliber_gun"
	//CALIBER_REVOLVER			= 6,	rewolwer			"caliber_revolver"
	//CALIBER_MINE				= 7,	mina				"caliber_mine"
	//CALIBER_CANNON			= 8,	armata				"caliber_cannon"
	//CALIBER_MORTAR			= 9		moŸdzierz			"caliber_mortar"

	RegisterCaliberEntity("caliber_firearm",			ECaliber::CALIBER_FIREARM);
	RegisterCaliberEntity("caliber_small_arms",			ECaliber::CALIBER_SMALL_ARMS);
	RegisterCaliberEntity("caliber_automatic_weapons",	ECaliber::CALIBER_AUTOMATIC_WEAPONS);
	RegisterCaliberEntity("caliber_rifle",				ECaliber::CALIBER_RIFLE);
	RegisterCaliberEntity("caliber_rocket",				ECaliber::CALIBER_ROCKET);
	RegisterCaliberEntity("caliber_gun",				ECaliber::CALIBER_GUN);
	RegisterCaliberEntity("caliber_revolver",			ECaliber::CALIBER_REVOLVER);
	RegisterCaliberEntity("caliber_mine",				ECaliber::CALIBER_MINE);
	RegisterCaliberEntity("caliber_cannon",				ECaliber::CALIBER_CANNON);
	RegisterCaliberEntity("caliber_mortar",				ECaliber::CALIBER_MORTAR);
}

CEntityTranslator::~CEntityTranslator(void)
{
	cleanup();
}

//Metoda rejestruje w translatorze obiekty ECaliber
bool CEntityTranslator::RegisterCaliberEntity(const std::string & string_caliber_entity, const ECaliber & caliber_entity)
{
	CaliberEntityMap::iterator it = m_caliber_entity_map.find(string_caliber_entity);
	if (it != m_caliber_entity_map.end())
		return false;

	m_caliber_entity_map[string_caliber_entity] = caliber_entity;
		return true;
}

//Metoda zwraca typ ECaliber z kontenera na podstawie klucza
ECaliber CEntityTranslator::TranslateToCaliberEntity(const std::string &string_caliber_entity)
{
	CaliberEntityMap::iterator it = m_caliber_entity_map.find(string_caliber_entity);

	if (it == m_caliber_entity_map.end())
		return ECaliber::CALIBER_FIREARM;//ka¿da broñ palna (brzydkie rozwi¹zanie...ale wystarczy)
	else
		return (*it).second;
}

//Metoda usuwa z translatora zarejestrowane obiekty
const void CEntityTranslator::ReleaseTranslateEntity(void)
{
	while(m_caliber_entity_map.begin() != m_caliber_entity_map.end())
		m_caliber_entity_map.erase(m_caliber_entity_map.begin());
}

//Wirtualna metoda czyszcz¹ca singleton
void CEntityTranslator::cleanup()
{
	fprintf(stderr, "CEntityTranslator::cleanup()\n");
	ReleaseTranslateEntity();
	fprintf(stderr, "CEntityTranslator::cleanup() done...\n");
}
