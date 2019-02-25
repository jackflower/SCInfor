//  __________________________________________
// | AnimatedFrame.h - class definition       |
// | Jack Flower - March 2009                 |
// |__________________________________________|
//

#ifndef H_TEXTURE_JACK
#define H_TEXTURE_JACK

#include <SFML/Graphics/Texture.hpp>

namespace rendering
{
	namespace displayable
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
	}//namespace displayable
}//namespace rendering
#endif //H_TEXTURE_JACK
