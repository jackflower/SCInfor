//  _________________________________________
// | PhysicalCategories.cpp - implementation |
// | Jack Flower October 2012                |
// |_________________________________________|
//

#include "PhysicalCategories.h"
#include "../../Utilities/MathFunctions/MathFunctions.h"
#include "../../Utilities/stringutils/stringutils.h"
#include <string>
#include <cstdio>
#include <vector>

namespace logic
{
	//tablica kategorii Physical
	const int Categories[] =
	{
		PHYSICAL_DETECTOR,
		PHYSICAL_PLAYER,
		PHYSICAL_MONSTER,
		PHYSICAL_NPC,
		PHYSICAL_BULLET,
		PHYSICAL_LAIR,
		PHYSICAL_WALL,
		PHYSICAL_ITEM,
		PHYSICAL_DOOR,
		PHYSICAL_TRAP,
		PHYSICAL_REGION,
		PHYSICAL_OBSTACLE,
		PHYSICAL_HOOK,
		PHYSICAL_POWERSTATION
		//Aktualizacja i synchronizacja wzglêdem PhysicalCategories.h
	};

	//wyliczona iloœæ elementów tablicy kategorii
	const int CategoryCount = sizeof(Categories)/sizeof(int);

	//tablica nazw kategorii Physical
	const std::string CategoryNames[] =
	{
		"detector",
		"player",
		"monster",
		"npc",
		"bullet",
		"lair",
		"wall",
		"item",
		"door",
		"trap",
		"region",
		"obstacle",
		"hook",
		"powerstation"
		//Aktualizacja i synchronizacja wzglêdem PhysicalCategories.h
	};

	//tablica nazw filtrów kategorii Physical
	const int Filters[] =
	{
		PHYSICAL_HOSTILES,		//1
		PHYSICAL_FRIENDLY,		//2
		PHYSICAL_ACTORS,		//3
		PHYSICAL_STATIC,		//4
		PHYSICAL_MOVING,		//5
		PHYSICAL_NONMOVING,		//6
		PHYSICAL_PATHBLOCKER,	//7
		PHYSICAL_DESTRUCTIBLE,	//8
		PHYSICAL_NONE			//9
		//Aktualizacja i synchronizacja wzglêdem PhysicalCategories.h
	};

	const int FilterCount = sizeof(Filters)/sizeof(int);

	const std::string FilterNames[] = 
	{
		"hostiles",				//1
		"friendly",				//2
		"actors",				//3
		"static",				//4
		"moving",				//5
		"nonmoving",			//6
		"pathblocker",			//7
		"destructible",			//8
		"none"					//9
		//Aktualizacja i synchronizacja wzglêdem PhysicalCategories.h
	};

	//Metoda zwraca indeks filtra Physical na podstawie nazwy filtru
	int ParsePhysicalFilter(const std::string & input)
	{
		std::vector< std::string > filters = stringutils::Tokenize( input );
		int ret = 0;

		//Tokenize - tego nie mam...dodaæ i analiza co i jak?
		for ( std::vector< std::string>::const_iterator it = filters.begin(); it != filters.end(); it++ )
		{
			bool recognized = false;	//recognized (ang. uznany/zaakceptowany)
			const std::string & filter = *it;
			for (int i = 0; i < CategoryCount; i++)
				if (CategoryNames[i]==filter)
				{
					ret = ret | Categories[i];
					recognized = true;
					break;
				}
			for (int i = 0; i < FilterCount; i++)
				if (FilterNames[i]==filter)
				{
					ret = ret | Filters[i];
					recognized = true;
					break;
				}

			if (!recognized)
				fprintf(stderr,"WARNING: unrecognised physical filter: %s\n", filter.c_str());
		}
		return ret;
	}

	//Metoda zwraca nazwê filtru Physical na podstawie numeru filtru
	std::string SerializePhysicalFilter(int filter)
	{
		std::string result = "";
		for (int i = 0; i < FilterCount; i++)
		{
			if (filter == 0) break;
			if (Filters[i] & filter)
			{
				filter ^= Filters[i];
				if (result != "") result += ",";
				result += FilterNames[i];
			}
		}
		for (int i = 0; i < CategoryCount; i++)
		{
			if (filter == 0) break;
			if (Categories[i] & filter)
			{
				filter ^= Categories[i];
				if (result != "") result += ",";
				result += CategoryNames[i];
			}
		}
		return result;
	}
}//namespace logic
