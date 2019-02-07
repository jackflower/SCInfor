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
		RTTI_DECL;	//uwaga - musimy przyj¹æ za³o¿enie, ¿e klasa CFont 
					//nie dziedziczy (dziedziczy po sf::Font), poniewa¿
					//klasa sf::Font to biblioteka, której nie mo¿emy
					//modyfikowaæ - wykazujemy, ¿e dziedziczy po IResource

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
#endif //H_FONT_JACK
