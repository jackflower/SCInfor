//  __________________________________
// | Music.h - class definition       |
// | Jack Flower - October 2013       |
// |__________________________________|
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
	class Music: public IResource, public sf::Music
	{
		RTTI_DECL;	//uwaga - musimy przyjąć założenie, że klasa Music 
					//nie dziedziczy (dziedziczy po sf::Music), ponieważ
					//klasa sf::Music to biblioteka, której nie możemy
					//modyfikować - wykazujemy, że dziedziczy po IResource

	public:
		
		///
		///Konstruktor
		///
		Music();

		///
		///Destruktor
		///
		~Music();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Wirtualna metoda ładująca zasób - implementacja
		///
		///@param file_name - stała referencja na nazwę pliku
		///
		bool load(const std::string & file_name);

		///
		///Wirtualna metoda zwalniająca zasób
		///
		void drop();

	};
}//namespace resource
#endif //H_MUSIC_JACK
