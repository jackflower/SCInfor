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

#include "Texture.h"

namespace acodemia
{
	namespace rendering
	{

		//Konstruktor
		Texture::Texture()
		:
			sf::Texture()//konstruktor klasy bazowej
		{
		}

		//Konstruktor kopiujący
		Texture::Texture(const Texture & copy)
		:
			sf::Texture(copy)//konstruktor kopiujący klasy bazowej
		{
		}

		//Konstruktor przenoszący
		Texture::Texture(Texture && other)
		:
			sf::Texture(std::move(other))
		{
		}

		//Destruktor
		Texture::~Texture()
		{
		}

		//Przeciążony operator przypisania kopiowania
		Texture & Texture::operator=(const Texture & copy)
		{
			if (this != &copy)
				sf::Texture::operator=(copy);
			return *this;
		}

		//Przeciążony operator przypisania przenoszenia
		Texture & Texture::operator=(Texture && other)
		{
			if (this != &other)
				sf::Texture::operator=(other);
			return *this;
		}

		//Metoda wczytuje teksturę z pliku
		bool Texture::Load(const std::string & file_name)
		{
			//jeśli dane zostały załadowane
			if (sf::Texture::loadFromFile(file_name))
				return true;	//zwracamy flagę true (ok)
			return false;		//false, jeśli program nie załadował pliku
		}

	}//namespace rendering
}//namespace acodemia
