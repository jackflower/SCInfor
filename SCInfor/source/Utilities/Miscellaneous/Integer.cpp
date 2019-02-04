/*
 ____________________________________
| Integer.cpp - class implementation |
| Jack Flower October 2013.          |
|____________________________________|

*/

#include "Integer.h"

//Konstruktor
Integer::Integer(void)
:
	value(0)
{
}

//Destruktor
Integer::~Integer(void)
{
	value = 0;
}

//Operator przypisania "=" /umo¿liwia przypisanie obiektu Integer do obiektu Integer
Integer &Integer::operator=(const Integer &right)
{
	if(&right != this)
		value = right.value;
	return *this;
}


//Operator przypisania "=" /umo¿liwia przypisanie do obiektu Integer wartoœci typu int
int &Integer::operator= (const int &right)
{
	value = right;
	return value;
}

//Operator dodawania "+" /umo¿liwia dodawanie obiektu Integer do obiektu Integer
Integer &Integer::operator+ (const Integer& right)
{
	if(&right != this)
		value += right.value;
	return *this;
}

//Operator odejmowania "-" /umo¿liwia odejmowanie obiektu Integer do obiektu Integer
Integer &Integer::operator- (const Integer& right)
{
	if(&right != this)
		value -= right.value;
	return *this;
}

//Operator mno¿enia "*" /umo¿liwia mno¿enie obiektu Integer przez obiektu Integer
Integer &Integer::operator* (const Integer& right)
{
	if(&right != this)
		value *= right.value;
	return *this;
}

//Operator dzielenia "/" /umo¿liwia dzielenie obiektu Integer przez obiektu Integer
Integer &Integer::operator/ (const Integer& right)
{
	if(&right != this)
		if(right.value != 0)
			value /= right.value;
	return *this;
}
