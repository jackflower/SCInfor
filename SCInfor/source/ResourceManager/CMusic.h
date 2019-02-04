//  ___________________________________
// | CMusic.h - class definition       |
// | Jack Flower - October 2013        |
// |___________________________________|
//

#ifndef H_MUSIC_JACK
#define H_MUSIC_JACK

#include <SFML/Audio/Music.hpp>
#include "IResource.h"

namespace resource
{
	///
	///Klasa reprezetuje opakowanie obiektu klasy sf::Music
	///
	class CMusic: public IResource, public sf::Music
	{
		RTTI_DECL;	//uwaga - musimy przyj¹æ za³o¿enie, ¿e klasa CMusic 
					//nie dziedziczy (dziedziczy po sf::Music), poniewa¿
					//klasa sf::Music to biblioteka, której nie mo¿emy
					//modyfikowaæ - wykazujemy, ¿e dziedziczy po IResource

	public:
		
		///
		///Konstruktor
		///
		CMusic(void);

		///
		///Destruktor
		///
		~CMusic(void);

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda ³aduj¹ca zasób - implementacja
		///
		///@param &file_name - sta³a referencja na nazwê pliku
		///
		bool Load(const std::string &file_name);

		///
		///Wirtualna metoda zwalniaj¹ca zasób
		///
		void Drop();

	};
}//namespace resource
#endif //H_MUSIC_JACK
