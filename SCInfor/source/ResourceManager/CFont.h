//  __________________________________
// | CFont.h - class definition       |
// | Jack Flower - October 2013       |
// |__________________________________|
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
	class CFont: public IResource, public sf::Font
	{
		RTTI_DECL;	//uwaga - musimy przyj�� za�o�enie, �e klasa CFont 
					//nie dziedziczy (dziedziczy po sf::Font), poniewa�
					//klasa sf::Font to biblioteka, kt�rej nie mo�emy
					//modyfikowa� - wykazujemy, �e dziedziczy po IResource

	public:
		
		///
		///Konstruktor
		///
		CFont(void);

		///
		///Destruktor
		///
		~CFont(void);

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda �aduj�ca zas�b - implementacja
		///
		///@param &file_name - sta�a referencja na nazw� pliku
		///
		bool load(const std::string &file_name);

		///
		///Wirtualna metoda zwalniaj�ca zas�b
		///
		void drop();

	};
}//namespace resource
#endif //H_FONT_JACK
