/*
 ____________________________________
| Float.h - class definition       |
| Jack Flower October 2013.          |
|____________________________________|

*/

#ifndef H_FLOAT_JACK
#define H_FLOAT_JACK

///
///Klasa reprezentuje opakowanie typu int wraz z kompletem operator�w
///
class Float
{
public:

	///
	///Konstruktor
	///
	Float(void);

	///
	///Destruktor
	///
	~Float(void);

	///
	///Operator przypisania "=" /umo�liwia przypisanie obiektu Float do obiektu Float
	///
	///@param &right - sta�a referencja na obiekt klasy Float
	///
	Float &operator= (const Float& right);

	///
	///Operator przypisania "=" /umo�liwia przypisanie do obiektu Float warto�ci typu int
	///
	///@param &right - sta�a referencja na obiekt typu int
	///
	float &operator= (const float &right);

	///
	///Operator dodawania "+" /umo�liwia dodawanie obiektu Float do obiektu Float
	///
	///@param &right - sta�a referencja na obiekt klasy Float
	///
	Float &operator+ (const Float& right);

	///
	///Operator odejmowania "-" /umo�liwia odejmowanie obiektu Float do obiektu Float
	///
	///@param &right - sta�a referencja na obiekt klasy Float
	///
	Float &operator- (const Float& right);

	///
	///Operator mno�enia "*" /umo�liwia mno�enie obiektu Float przez obiektu Float
	///
	///@param &right - sta�a referencja na obiekt klasy Float
	///
	Float &operator* (const Float& right);

	///
	///Operator dzielenia "/" /umo�liwia dzielenie obiektu Float przez obiektu Float
	///
	///@param &right - sta�a referencja na obiekt klasy Float
	///
	Float &operator/ (const Float& right);

private:

	float value;
};

#endif //H_FLOAT_JACK
