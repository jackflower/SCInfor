//  ___________________________________________________________
// | MathFunctions.h   - imathematical function declaration    |
// | Jack Flower March 2012                                    |
// |___________________________________________________________|
//

#ifndef H_MATH_FUNCTIONS_JACK
#define H_MATH_FUNCTIONS_JACK

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>

#define _USE_MATH_DEFINES
#include <math.h>

///
///Modu� zawiera wybrane funkcje matematyczne
///
namespace maths
{

	//Funkcje operuj�ce na wektorach

	inline sf::Vector2f VectorZero() 
	{
		static sf::Vector2f vectorOut(0.0f, 0.0f);
		return vectorOut;
	}

	inline sf::Vector2f VectorUp()
	{
		static sf::Vector2f vectorOut(0.0f, -1.0f);
		return vectorOut;
	}

	inline sf::Vector2f VectorDown()
	{
		static sf::Vector2f vectorOut(0.0f, 1.0f);
		return vectorOut;
	}

	inline sf::Vector2f VectorLeft()
	{
		static sf::Vector2f vectorOut(-1.0f, 0.0f);
		return vectorOut;
	}

	inline sf::Vector2f VectorRight()
	{
		static sf::Vector2f vectorOut(1.0f, 0.0f);
		return vectorOut;
	}

	inline sf::Vector2f VectorOf(float x, float y)
	{
		sf::Vector2f vectorOut(x, y);
		return vectorOut;
	}

	//Funkcje zwracajace wektory prostopadle
	inline sf::Vector2f VectorRightOf(const sf::Vector2f& vector )
	{
		sf::Vector2f vectorOut( -vector.y, vector.x );
		return vectorOut;
	}

	inline sf::Vector2f VectorLeftOf(const sf::Vector2f& vector )
	{
		sf::Vector2f vectorOut( vector.y, -vector.x );
		return vectorOut;
	}

    //Obr�t wektora
    inline sf::Vector2f Rotate(sf::Vector2f &v, int rot)
	{
        float f = - rot * 2.0f * (float)M_PI / 360.0f;
        sf::Vector2f vectorOut(v.x * cosf(f) - v.y * sinf(f), v.x * sinf(f) + v.y * cosf(f));
        return vectorOut;
    }

	//Iloczyn skalarny
	inline float Dot(sf::Vector2f vector1, sf::Vector2f vector2)
	{
		return vector1.x * vector2.x + vector1.y * vector2.y;
	}

	inline int Dot(sf::Vector2i vector1, sf::Vector2i vector2)
	{
		return vector1.x * vector2.x + vector1.y * vector2.y;
	}

	//D�ugo�� wektora
	inline float Length(sf::Vector2f vector)
	{
		return sqrtf(vector.x * vector.x + vector.y * vector.y);
	}

	//Metoda zwraca odleg�o�� mi�dzy dwoma punktami
	inline float DistanceBetweenTwoPoints(sf::Vector2f p_a, sf::Vector2f p_b)
	{
		float distance = sqrtf ((p_a.x-p_b.x)*(p_a.x-p_b.x) + (p_a.y-p_b.y)*(p_a.y-p_b.y));
		return distance;
	}
	
	//Pierwiastek wektora
    inline float LengthSQ(sf::Vector2f vector)
	{
		return (vector.x * vector.x + vector.y * vector.y);
	}

	//Normalizajca wektora
	inline sf::Vector2f Normalize(sf::Vector2f vector)
	{
		float vectorLength = Length(vector);
		float invLength = (vectorLength != 0.0f ? 1.0f / vectorLength : 0.0f);

		sf::Vector2f vectorOut(vector.x * invLength, vector.y * invLength);
		return vectorOut;
	}

	//Warto�� bezwzgl�dna
	inline float Abs( float a )
	{
		return a > 0.0f ? a :-a;
	}

	//
	inline int Sgn (float a) 
	{ 
		if(Abs(a) < 0.001f)  return 0;
		return (a>0) ? (1) : (-1);
	}

	//K�t mi�dzy dwoma wektorami
	inline float AngleBetween(sf::Vector2f v1, sf::Vector2f v2)
	{
		float alpha =  acosf( Dot(Normalize(v1), Normalize(v2))) * 180.0f / 3.1415f;
		float sinsgn = Dot(VectorLeftOf(v1), v2);
		if (sinsgn > 0) alpha *= -1;
		return alpha;
	}

	//
	inline sf::Vector2f Lerp(sf::Vector2f a, sf::Vector2f b, float t)
	{ 
		return a * (1.0f - t) + b * t;
	}

	//Funkcje operuj�ce na liczbach (jaka� interpolacja_
	inline float Lerp(float a, float b, float t)
	{ 
		return a * (1.0f - t) + b * t; 
	}

	//Por�wnanie
	inline float Clamp(float a, float min = 0.0f, float max = 1.0f)
	{
		return a < min ? min : (a > max ? max : a);
	}

	//Por�wnanie
	inline int ClampInt(int a, int min, int max)
	{
		return a < min ? min : (a > max ? max : a);
	}

	//
	template <typename T>
	T clamp(const T& what, const T& a, const T& b)
	{
		return std::min(b, std::max(what, a));
	}

	//Funkcje licz�ce odleg�o�� mi�dzy figurami geometrycznymi
    float PointToSegment(const sf::Vector2f& point, const sf::Vector2f& segA, const sf::Vector2f& segB);
    float SegmentToSegment(sf::Vector2f& segA, sf::Vector2f& segB, sf::Vector2f& segC, sf::Vector2f& segD);
	float PointToRect(sf::Vector2f& point, sf::Vector2f& leftUp, sf::Vector2f& rightDown);

	//Inne funkcje geometryczne

	bool CircleInAngle(	const sf::Vector2f& angleCenter,
						const sf::Vector2f& angleBisector,
						float angularWidth,
						const sf::Vector2f& circleCenter,
						float circleRadius );

	sf::Vector2f SeparateCircles(	const sf::Vector2f& centerA, 
									float radiusA,
									const sf::Vector2f& centerB,
									float radiusB );

	sf::Vector2f SeparateRectCircle(const sf::Vector2f& centerA,
									const sf::Vector2f& sizeA,
									const sf::Vector2f& centerB,
									const sf::Vector2f& oldCenterB,
									float radiusB );

	sf::Vector2f SeparateRects(	const sf::Vector2f& centerA,
								const sf::Vector2f& sizeA,
								const sf::Vector2f& centerB,
								const sf::Vector2f& sizeB );

    //Logarytm binarny
	inline int BinaryLog(int input)
	{
		int log = 1;
		if(input <= 0)
			return 0;
		while(input != 1)
		{
			input = input >> 1;
			log++;
		}
		return log-1;
	}
    
	//
	inline int ManhatanLength(const sf::Vector2i & v)
	{
		return abs(v.x) + abs(v.y);
	}
    
	//
	inline int ManhattanDistance(const sf::Vector2i & v1, const sf::Vector2i & v2)
	{
		return ManhatanLength(v1 - v2);
	}

}//maths namespace
#endif //H_MATH_FUNCTIONS_JACK
