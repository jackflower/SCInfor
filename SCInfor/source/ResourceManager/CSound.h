//  ___________________________________
// | CSound.h - class definition       |
// | Jack Flower - October 2013        |
// |___________________________________|
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
	class CSound: public IResource, public sf::SoundBuffer
	{
		RTTI_DECL;	//uwaga - musimy przyj¹æ za³o¿enie, ¿e klasa CSound 
					//nie dziedziczy (dziedziczy po sf::SoundBuffer), poniewa¿
					//klasa sf::SoundBuffer to biblioteka, której nie mo¿emy
					//modyfikowaæ - wykazujemy, ¿e dziedziczy po IResource

	public:
		
		///
		///Konstruktor
		///
		CSound(void);

		///
		///Destruktor
		///
		~CSound(void);

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda ³aduj¹ca zasób - implementacja
		///
		///@param &file_name - sta³a referencja na nazwê pliku
		///
		bool load(const std::string &file_name);

		///
		///Wirtualna metoda zwalniaj¹ca zasób
		///
		void drop();

	};
}//namespace resource
#endif //H_SOUND_JACK
