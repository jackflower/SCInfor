//  __________________________________________
// | AnimatedFrame.cpp - class implementation |
// | Jack Flower - March 2009                 |
// |__________________________________________|
//

#include "Texture.h"

namespace rendering
{
	namespace displayable
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
			if (this != & copy)
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

	}//namespace displayable
}//namespace acodemia
