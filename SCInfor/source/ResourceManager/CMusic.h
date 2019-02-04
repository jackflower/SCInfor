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
		RTTI_DECL;	//uwaga - musimy przyj�� za�o�enie, �e klasa CMusic 
					//nie dziedziczy (dziedziczy po sf::Music), poniewa�
					//klasa sf::Music to biblioteka, kt�rej nie mo�emy
					//modyfikowa� - wykazujemy, �e dziedziczy po IResource

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
		///Wirtualna metoda �aduj�ca zas�b - implementacja
		///
		///@param &file_name - sta�a referencja na nazw� pliku
		///
		bool Load(const std::string &file_name);

		///
		///Wirtualna metoda zwalniaj�ca zas�b
		///
		void Drop();

	};
}//namespace resource
#endif //H_MUSIC_JACK
