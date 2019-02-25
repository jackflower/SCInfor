//  _______________________________________
// | FixedColor.cpp - class implementation |
// | Jack Flower March 2013                |
// |_______________________________________|
//

#include "FixedColor.h"

//Konstruktor
FixedColor::FixedColor()
:
	r_low(0.0f),
	g_low(0.0f),
	b_low(0.0f),
	a_low(0.0f),
	r_high(0.0f),
	g_high(0.0f),
	b_high(0.0f),
	a_high(0.0f)
{
}

//Destruktor
FixedColor::~FixedColor()
{
	r_low = 0.0f;
	g_low = 0.0f;
	b_low = 0.0f;
	a_low = 0.0f;
	r_high = 0.0f;
	g_high = 0.0f;
	b_high = 0.0f;
	a_high = 0.0f;
}

//Metoda nadaje wartości składowym klasy
void FixedColor::setFixedColor (float r_l, float g_l, float b_l, float a_l,
	                            float r_h, float g_h, float b_h, float a_h)
{
	r_low = r_l;
	g_low = g_l;
	b_low = b_l;
	a_low = a_l;
	r_high = r_h;
	g_high = g_h;
	b_high = b_h;
	a_high = a_h;
}
