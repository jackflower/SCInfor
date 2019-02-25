/*
 ______________________________________
| Utilities.h - deklaracja szablonów.  |
| Jack Flower December 2009.           |
|______________________________________|

*/

#include <sstream>

#ifndef H_UTILITIES_JACK
#define H_UTILITIES_JACK

#ifdef _MSC_VER
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>
#endif


template <class T>
std::string ValueToString(T i)
{
	std::stringstream ss;
	std::string temp;
    ss << i;
    ss >> temp;
    return temp;
}

const double RADIANS_PER_DEGREE  = (M_PI/180.0f);
const double DEGREE_PER_RADIANS  = (180.0f/M_PI);

	inline float Length( sf::Vector2f vector )
	{
		return sqrtf( vector.x * vector.x + vector.y * vector.y );
	}

	inline sf::Vector2f Normalize( sf::Vector2f vector )
	{
		float vectorLength = Length( vector );
		float invLength = ( vectorLength != 0.0f ? 1.0f / vectorLength : 0.0f );

		sf::Vector2f vectorOut( vector.x * invLength, vector.y * invLength );
		return vectorOut;
	}

	inline float Lerp( float a, float b, float t )
	{ 
		return a * (1.0f - t) + b * t; 
	}

#endif//H_UTILITIES_JACK