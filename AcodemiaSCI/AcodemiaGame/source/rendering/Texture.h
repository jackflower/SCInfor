////////////////////////////////////////////////////////////
//
// Acodemia Copyright (C) Jacek Kwiatek
// e-mail: jackflower (at) poczta.onet.pl
// acodemia.pl
//
// To oprogramowanie dostarczane jest w postaci takiej,
// w jakiej jest, bez wyraźnych ani domniemanych gwarancji.
//
// W żadnym wypadku Autor nie ponosi odpowiedzialności
// za jakiekolwiek szkody powstałe w wyniku korzystania
// z tego oprogramowania.Zastrzega
//
// Zezwala się na korzystanie z tego oprogramowania
// w dowolnym celu, także komercyjnym. Można je zmienić
// i swobodnie rozpowszechniać.
//
// Zastrzega się następujące ograniczenia:
//
// 1. Jeśli używasz tego oprogramowania w swoich
//    produktach, potwierdzenie pochodzenia tego
//    oprogramowania w dokumentacji produktu,
//    byłoby docenione, ale nie jest wymagane.
//
////////////////////////////////////////////////////////////

#ifndef H_TEXTURE_ACODEMIA
#define H_TEXTURE_ACODEMIA

#include <SFML/Graphics/Texture.hpp>

namespace acodemia
{
	namespace rendering
	{
		///
		///Klasa reprezetuje opakowanie obiektu klasy sf::Texture
		///
		class Texture : public sf::Texture
		{
		public:

			///
			///Konstruktor
			///
			Texture();

			///
			///Konstruktor kopiujący
			///
			///@param copy - stała referencja na obiekt klasy Texture
			///
			Texture(const Texture & copy);

			///
			///Konstruktor przenoszący
			///
			///@param other = referencja do r-wartości
			///
			Texture(Texture && other);

			///
			///Destruktor
			///
			~Texture();

			///
			///Przeciążony operator przypisania kopiowania
			///
			///@param copy - stała referencja na obiekt klasy Texture
			///
			Texture & operator=(const Texture & copy);

			///
			///Przeciążony operator przypisania przenoszenia
			///
			///@param other -  referencja do r-wartości
			///
			Texture & operator=(Texture && other);

			///
			///Metoda wczytuje teksturę z pliku
			///
			///@param file_name - stała referencja na obiekt klasy std::string
			////
			bool Load(const std::string & file_name);

		};
	}//namespace rendering
}//namespace resource
#endif //H_TEXTURE_ACODEMIA
