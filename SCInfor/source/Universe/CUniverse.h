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
	///Klasa repezentuje root wszech�wiata - singleton - wszech�wiat jest jeden
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
		///Metoda na podstawie nazwy zwraca z kontenera wska�nik na galaktyk�
		///
		///@param &animation_name - nazwa animacji
		///
		CGalaxy* GetGalaxy(const std::string& galaxy_name);

		///
		///Metoda tworzy galaktyk�
		///
		///@param &galaxy_name - nazwa galaktyki
		///
		//CGalaxy* CreateGalaxy(const std::string& galaxy_name);

		///
		///Metoda tworzy galaktyk�
		///
		///@param *p_galaxy - wska�nik na obiekt klasy CGalaxy
		///
		//CGalaxy* CreateGalaxy(CGalaxy *p_galaxy);

		///
		///Metoda usuwa galaktyk�
		///
		///@param *p_galaxy - wska�nik na obiekt klasy CGalaxy
		///
		//void DestroyGalaxy(CGalaxy* p_galaxy);

//Metoda usuwa zas�b na podstawie identyfikatora
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

		//metoda �aduje dane (wszystkie obiekty wszech�wiata) z pliku xml (wywo�ywana w konstruktorze)
		//
		//@param &file_name - nazwa pliku - sta�a referencja na obiekt klasy std::string
		//
		//@param &node_name - nazwa w�z�a xml - sta�a referencja na obiekt klasy std::string
		//
		void LoadUniverse(const std::string &file_name, const std::string &node_name);

		//poprawi� nazwy, ctor, dtor, set, get, ma czyta� parent'a,
		//ma zwraca� ca�e kontenery, ma by� lepiej i czytelniej, etc...
		typedef std::map<std::string, CGalaxy*>	GalaxyMap;		//definicja typu - kontener (mapa) - galaktyki
		GalaxyMap								m_galaxy;		//kontener (mapa) na galaktyki
	};
}//namespace universe
#endif//H_UNIVERSE_JACK
