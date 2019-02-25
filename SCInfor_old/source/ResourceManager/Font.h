//  _________________________________
// | Font.h - class definition       |
// | Jack Flower - October 2013      |
// |_________________________________|
//

#ifndef H_FONT_JACK
#define H_FONT_JACK

#include <SFML/Graphics/Font.hpp>
#include "IResource.h"

namespace resource
{
	///
	///Klasa reprezetuje opakowanie obiektu klasy sf::Font
	///
	class Font: public IResource, public sf::Font
	{
		RTTI_DECL;	//uwaga - musimy przyjąć założenie, że klasa Font 
					//nie dziedziczy (dziedziczy po sf::Font), ponieważ
					//klasa sf::Font to biblioteka, której nie możemy
					//modyfikować - wykazujemy, że dziedziczy po IResource

	public:
		
		///
		///Konstruktor
		///
		Font();

		///
		///Konstruktor kopiujący
		///
		///@param copy - parametr - obiekt klasy Font
		///
		Font(const Font & copy);

		///
		///Konstruktor przenoszący
		///
		///@param other - referencja do r-wartości
		///
		Font(Font && other);

		///
		///Destruktor
		///
		~Font();

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
#endif //H_FONT_JACK
