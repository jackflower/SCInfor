/*
 ____________________________________
| Integer.h - class definition       |
| Jack Flower October 2013.          |
|____________________________________|

*/

#ifndef _H_INTEGER_JACK
#define _H_INTEGER_JACK

///
///Klasa reprezentuje opakowanie typu int wraz z kompletem operatorów
///
class Integer
{
public:

	///
	///Konstruktor
	///
	Integer(void);

	///
	///Destruktor
	///
	~Integer(void);

	///
	///Operator przypisania "=" /umo¿liwia przypisanie obiektu Integer do obiektu Integer
	///
	///@param &right - sta³a referencja na obiekt klasy Integer
	///
	Integer &operator= (const Integer& right);

	///
	///Operator przypisania "=" /umo¿liwia przypisanie do obiektu Integer wartoœci typu int
	///
	///@param &right - sta³a referencja na obiekt typu int
	///
	int &operator= (const int &right);

	///
	///Operator dodawania "+" /umo¿liwia dodawanie obiektu Integer do obiektu Integer
	///
	///@param &right - sta³a referencja na obiekt klasy Integer
	///
	Integer &operator+ (const Integer& right);

	///
	///Operator odejmowania "-" /umo¿liwia odejmowanie obiektu Integer do obiektu Integer
	///
	///@param &right - sta³a referencja na obiekt klasy Integer
	///
	Integer &operator- (const Integer& right);

	///
	///Operator mno¿enia "*" /umo¿liwia mno¿enie obiektu Integer przez obiektu Integer
	///
	///@param &right - sta³a referencja na obiekt klasy Integer
	///
	Integer &operator* (const Integer& right);

	///
	///Operator dzielenia "/" /umo¿liwia dzielenie obiektu Integer przez obiektu Integer
	///
	///@param &right - sta³a referencja na obiekt klasy Integer
	///
	Integer &operator/ (const Integer& right);

private:

	int value;
};

#endif //_H_INTEGER_JACK
