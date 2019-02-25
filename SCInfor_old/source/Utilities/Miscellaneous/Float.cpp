/*
 ____________________________________
| Float.cpp - class implementation |
| Jack Flower October 2013.          |
|____________________________________|

*/

#include "Float.h"

//Konstruktor
Float::Float(void)
:
	value(0.0f)
{
}

//Destruktor
Float::~Float(void)
{
	value = 0.0f;
}

//Operator przypisania "=" /umo¿liwia przypisanie obiektu Float do obiektu Float
Float &Float::operator=(const Float &right)
{
	if(&right != this)
		value = right.value;
	return *this;
}


//Operator przypisania "=" /umo¿liwia przypisanie do obiektu Float wartoœci typu int
float &Float::operator= (const float &right)
{
	value = right;
	return value;
}

//Operator dodawania "+" /umo¿liwia dodawanie obiektu Float do obiektu Float
Float &Float::operator+ (const Float& right)
{
	if(&right != this)
		value += right.value;
	return *this;
}

//Operator odejmowania "-" /umo¿liwia odejmowanie obiektu Float do obiektu Float
Float &Float::operator- (const Float& right)
{
	if(&right != this)
		value -= right.value;
	return *this;
}

//Operator mno¿enia "*" /umo¿liwia mno¿enie obiektu Float przez obiektu Float
Float &Float::operator* (const Float& right)
{
	if(&right != this)
		value *= right.value;
	return *this;
}

//Operator dzielenia "/" /umo¿liwia dzielenie obiektu Float przez obiektu Float
Float &Float::operator/ (const Float& right)
{
	if(&right != this)
		if(right.value != 0)
			value /= right.value;
	return *this;
}
