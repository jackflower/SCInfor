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
		RTTI_DECL;	//uwaga - musimy przyjąć założenie, że klasa CTexture 
					//nie dziedziczy (dziedziczy po sf::Texture), ponieważ
					//klasa sf::Texture to biblioteka, której nie możemy
					//modyfikować - wykazujemy, że dziedziczy po IResource

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
		///Wirtualna metoda ładująca zasób - implementacja
		///
		///@param &file_name - stała referencja na nazwę pliku
		///
		bool load(const std::string &file_name);

		///
		///Wirtualna metoda zwalniająca zasób
		///
		void drop();

	};
}//namespace resource
#endif //H_TEXTURE_JACK
