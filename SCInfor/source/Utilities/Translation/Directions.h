//  _________________________________
// | Directions.h - definition       |
// | Jack Flower April 2015          |
// |_________________________________|
//

#ifndef H_DIRECTIONS_JACK
#define H_DIRECTIONS_JACK

#include <SFML/System/Vector2.hpp>

namespace translation
{
	///
	///Funckja zwraca wspó³czynnik obrotu na podstawie wektora
	///
	///@param vector - wektor - obiekt klasy sf::Vector2f
	///
	int RotationFromVector(sf::Vector2f vector);

	///
	///Funckja zamienia k¹t obrotu na wektor
	///
	///@param angle - k¹t
	///
	sf::Vector2f RotationToVector(float angle);

}//namespace translation
#endif//H_DIRECTIONS_JACK
