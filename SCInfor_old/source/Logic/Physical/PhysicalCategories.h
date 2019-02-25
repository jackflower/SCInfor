//  _________________________________________
// | PhysicalCategories.h - definition       |
// | Jack Flower October 2012                |
// |_________________________________________|
//

#ifndef H_PHYSICAL_CATEGORIES_JACK
#define H_PHYSICAL_CATEGORIES_JACK

#include <string>

//wydzielenie kategorii Physical,
//rozbudowane filtry,
//parsowanie std::string (przy wczytywaniu z Xml),
//kolejność i zależność - obiekty porusząjace się sa na początku

namespace logic
{
	///
	///Wyliczenie kategorii Physical
	///
	enum physCategory			
	{							
		PHYSICAL_DETECTOR			= 1,	//1
		PHYSICAL_PLAYER				= 2,	//2
		PHYSICAL_MONSTER			= 4,	//3
		PHYSICAL_NPC				= 8,	//4
		PHYSICAL_BULLET				= 16,	//5
		PHYSICAL_LAIR				= 32,	//6
		PHYSICAL_WALL				= 64,	//7
		PHYSICAL_ITEM				= 128,	//8
		PHYSICAL_DOOR				= 256,	//9
		PHYSICAL_TRAP				= 512,	//10
		PHYSICAL_REGION				= 1024,	//11
		PHYSICAL_OBSTACLE			= 2048,	//12
		PHYSICAL_HOOK				= 4096,	//13
		PHYSICAL_POWERSTATION		= 8192,	//14
		PHYSICAL_WINDPOWERSTATION	= 16384	//15
	};

	//Dodając nową kategorię, należy zaktualizować ich ilość
	const int PHYSICAL_CATEGORIES_COUNT = 15;

	//Dodając nowy typ , należy zaktualizować tablice nazw i filtrów PhysicalCategories.cpp
	const int PHYSICAL_HOSTILES			= PHYSICAL_MONSTER	| PHYSICAL_LAIR;
	const int PHYSICAL_FRIENDLY			= PHYSICAL_PLAYER	| PHYSICAL_NPC;
	const int PHYSICAL_ACTORS			= PHYSICAL_HOSTILES | PHYSICAL_FRIENDLY;
	const int PHYSICAL_STATIC			= PHYSICAL_BULLET	| PHYSICAL_WALL | PHYSICAL_ITEM | PHYSICAL_DOOR | PHYSICAL_HOOK;
	const int PHYSICAL_MOVING			= PHYSICAL_DETECTOR | PHYSICAL_PLAYER	| PHYSICAL_MONSTER	| PHYSICAL_NPC	| PHYSICAL_BULLET;
	const int PHYSICAL_NONMOVING		= PHYSICAL_LAIR		| PHYSICAL_WALL		| PHYSICAL_ITEM		| PHYSICAL_DOOR | PHYSICAL_HOOK;
	const int PHYSICAL_PATHBLOCKER		= PHYSICAL_WALL		| PHYSICAL_DOOR		| PHYSICAL_OBSTACLE;
	const int PHYSICAL_DESTRUCTIBLE		= PHYSICAL_ACTORS	| PHYSICAL_OBSTACLE;
	const int PHYSICAL_NONE				= 0;

	const int PHYSICAL_SUMMONBLOCKER	= PHYSICAL_ACTORS | PHYSICAL_PATHBLOCKER;

	const int PHYSICAL_ANY				= (1 << PHYSICAL_CATEGORIES_COUNT) - 1;

	///
	///Metoda zwraca indeks filtra Physical na podstawie nazwy filtru
	///
	///@param input - stała referencja na std::string
	///
	int ParsePhysicalFilter(const std::string & input);

	///
	///Metoda zwraca nazwę filtru Physical na podstawie numeru filtru
	///
	///@param filter - numer filtru
	///
	std::string SerializePhysicalFilter(int filter);

}//namespace logic
#endif //H_PHYSICAL_CATEGORIES_JACK
