//  ____________________________________________
// | ResourceTexture.h - class definitoin       |
// | Jack Flower - October 2013                 |
// |____________________________________________|
//

#ifndef H_RTEXTURE_JACK
#define H_RTEXTURE_JACK

#include <SFML/Graphics/Texture.hpp>
#include "Resource.h"

namespace resource
{
	///
	///Klasa reprezetuje opakowanie obiektu klasy sf::Texture
	///
	class ResourceTexture: public Resource, public sf::Texture
	{
		RTTI_DECL;	//uwaga - musimy przyjąć założenie, że klasa ResourceTexture 
					//nie dziedziczy (dziedziczy po sf::Texture), ponieważ
					//klasa sf::Texture to biblioteka, której nie możemy
					//modyfikować - wykazujemy, że dziedziczy po Resource

	public:
		
		///
		///Konstruktor
		///
		ResourceTexture();

		///
		///Destruktor
		///
		~ResourceTexture();

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
#endif //H_RTEXTURE_JACK
