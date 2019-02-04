//  ________________________________________
// | CFixedColor.h - class definition       |
// | Jack Flower March 2013                 |
// |________________________________________|
//

#ifndef H_FIXED_COLOR_JACK
#define H_FIXED_COLOR_JACK

///
///Klasa reprezentuje sk³adowe koloru dla interpolacji liniowej
///
class CFixedColor
{
public:
	
	///
	///Konstruktor
	///
	CFixedColor();

	///
	///Destruktor
	///
	~CFixedColor();

	///
	///Metoda nadaje wartoœci sk³adowym klasy
	///
	void SetFixedColor (
						float r_l,
						float g_l,
						float b_l,
						float a_l,
						float r_h,
						float g_h,
						float b_h,
						float a_h
					   );

	inline float GetInterpolateRed()	{ return r_low + (r_high - r_low); }
	inline float GetInterpolateGreen()	{ return g_low + (g_high - g_low); }
	inline float GetInterpolateBlue()	{ return b_low + (b_high - b_low); }
	inline float GetInterpolateAlpha()	{ return a_low + (a_high - a_low); }

private:

	//low value
	float r_low;
	float g_low;
	float b_low;
	float a_low;

	//high value
	float r_high;
	float g_high;
	float b_high;
	float a_high;
};
#endif //H_FIXED_COLOR_JACK