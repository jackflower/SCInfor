//  _____________________________________
// | CTexture.h - class definitoin       |
// | Jack Flower - October 2013          |
// |_____________________________________|
//

#ifndef H_TEXTURE_JACK
#define H_TEXTURE_JACK

#include <SFML/Graphics/Texture.hpp>
#include "IResource.h"

namespace resource
{
	///
	///Klasa reprezetuje opakowanie obiektu klasy sf::Texture
	///
	class CTexture: public IResource, public sf::Texture
	{
		RTTI_DECL;	//uwaga - musimy przyj�� za�o�enie, �e klasa CTexture 
					//nie dziedziczy (dziedziczy po sf::Texture), poniewa�
					//klasa sf::Texture to biblioteka, kt�rej nie mo�emy
					//modyfikowa� - wykazujemy, �e dziedziczy po IResource

	public:
		
		///
		///Konstruktor
		///
		CTexture(void);

		///
		///Destruktor
		///
		~CTexture(void);

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
#endif //H_TEXTURE_JACK
