/*
 _______________________________________
| CUniverse.h - definicja klasy.        |
| Jack Flower - May 2014.               |
|_______________________________________|

*/

#ifndef H_UNIVERSE_JACK
#define H_UNIVERSE_JACK

#include <map>
#include <string>
#include "../Utilities/Singleton/CSingleton.h"
#include "Galaxy/CGalaxy.h"

using namespace universe::galaxy;

#define gUniverse CUniverse::GetSingleton()


namespace universe
{
	///
	///Klasa repezentuje root wszechœwiata - singleton - wszechœwiat jest jeden
	///
	class CUniverse : public CSingleton<CUniverse>
	{
	public:

		///
		///Konstruktor
		///
		CUniverse(void);

		///
		///Destruktor wirtualny
		///
		virtual ~CUniverse(void);

		///
		///Wirtualny interfejs - implementacja
		///
		virtual void Cleanup();

		///
		///Metoda na podstawie nazwy zwraca z kontenera wskaŸnik na galaktykê
		///
		///@param &animation_name - nazwa animacji
		///
		CGalaxy* GetGalaxy(const std::string& galaxy_name);

		///
		///Metoda tworzy galaktykê
		///
		///@param &galaxy_name - nazwa galaktyki
		///
		//CGalaxy* CreateGalaxy(const std::string& galaxy_name);

		///
		///Metoda tworzy galaktykê
		///
		///@param *p_galaxy - wskaŸnik na obiekt klasy CGalaxy
		///
		//CGalaxy* CreateGalaxy(CGalaxy *p_galaxy);

		///
		///Metoda usuwa galaktykê
		///
		///@param *p_galaxy - wskaŸnik na obiekt klasy CGalaxy
		///
		//void DestroyGalaxy(CGalaxy* p_galaxy);

//Metoda usuwa zasób na podstawie identyfikatora
//void CAnimManager::ReleaseAnimation(std::string anim_type_string)//const & string
//{
//	AnimStringMap::iterator it = m_anim_string_map.find(anim_type_string);
//	if (it != m_anim_string_map.end())
//	{
//		delete m_anim_string_map.begin()->second;
//		m_anim_string_map.erase(anim_type_string);
//	}
//}


	private:

		//metoda ³aduje dane (wszystkie obiekty wszechœwiata) z pliku xml (wywo³ywana w konstruktorze)
		//
		//@param &file_name - nazwa pliku - sta³a referencja na obiekt klasy std::string
		//
		//@param &node_name - nazwa wêz³a xml - sta³a referencja na obiekt klasy std::string
		//
		void LoadUniverse(const std::string &file_name, const std::string &node_name);

		//poprawiæ nazwy, ctor, dtor, set, get, ma czytaæ parent'a,
		//ma zwracaæ ca³e kontenery, ma byæ lepiej i czytelniej, etc...
		typedef std::map<std::string, CGalaxy*>	GalaxyMap;		//definicja typu - kontener (mapa) - galaktyki
		GalaxyMap								m_galaxy;		//kontener (mapa) na galaktyki
	};
}//namespace universe
#endif//H_UNIVERSE_JACK
