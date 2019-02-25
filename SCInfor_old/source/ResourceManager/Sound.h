//  __________________________________
// | Sound.h - class definition       |
// | Jack Flower - October 2013       |
// |__________________________________|
//

#ifndef H_SOUND_JACK
#define H_SOUND_JACK

#include <SFML/Audio/SoundBuffer.hpp>
#include "IResource.h"

namespace resource
{
	///
	///Klasa reprezetuje opakowanie obiektu klasy sf::Texture
	///
	class Sound: public IResource, public sf::SoundBuffer
	{
		RTTI_DECL;	//uwaga - musimy przyjąć założenie, że klasa Sound 
					//nie dziedziczy (dziedziczy po sf::SoundBuffer), ponieważ
					//klasa sf::SoundBuffer to biblioteka, której nie możemy
					//modyfikować - wykazujemy, że dziedziczy po IResource

	public:
		
		///
		///Konstruktor
		///
		Sound();

		///
		///Destruktor
		///
		~Sound();

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
#endif //H_SOUND_JACK
