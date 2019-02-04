//  _________________________________
// | Directions.cpp - implementation |
// | Jack Flower April 2015          |
// |_________________________________|
//

#include <math.h>
#include <cstdio>

#include "Directions.h"
#include "../MathFunctions/MathFunctions.h"

using namespace maths;

namespace translation
{
	//Funckja zwraca wspó³czynnik obrotu na podstawie wektora
	int RotationFromVector(sf::Vector2f vector)
	{
		vector = Normalize(vector);
		sf::Vector2f diff = vector - VectorUp();
		float s = diff.x;

		int result = int(asin(s)*180.0f/M_PI);

		if (vector.y > 0) 
			result = 180 + result;
		else
			result = 360 - result;

		if (result > 360) result -= 360;
		if (result < 0) result += 360;
		
		return result;
	}

	//Funckja zamienia k¹t obrotu na wektor
	sf::Vector2f RotationToVector(float angle)
	{
		angle = (float)M_PI * angle / 180.0f;
		return sf::Vector2f(-sinf(angle),-cosf(angle));
	}

}//namespace translation
