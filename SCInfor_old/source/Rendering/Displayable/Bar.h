//  ________________________________
// | Bar.h - class definition       |
// | Jack Flower December 2012      |
// |________________________________|
//

#ifndef H_BAR_JACK
#define H_BAR_JACK

#include "Displayable.h"
#include "../../XML/CXml.h"

///
///Forward declaration
///
namespace sf
{
    class RenderWindow;
}

using namespace rendering::displayable;
using namespace xml;

namespace displayable
{
	///
	///Klasa reprezentuje graficzną prezentację wartości - pasek stanu - progress bar
	///
	class Bar : public Displayable
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor domyślny
		///
		Bar();

		///
		///Konstruktor kopiujący
		///
		///@param BarCopy - stała referencaj na obiekt klasy Bar
		///
		Bar(const Bar & BarCopy);

		///
		///Konstruktor przenoszący
		///
		///@param other = referencja do r-wartości
		///
		Bar(Bar && other);

		///
		///Destruktor wirtualny
		///
		virtual ~Bar();

		///
		///Przeciążony operator przypisania kopiowania
		///
		///@param copy - stała referencja na obiekt klasy Bar
		///
		Bar & operator=(const Bar & copy);

		///
		///Przeciążony operator przypisania przenoszenia
		///
		///@param other -  referencja do r-wartości
		///
		Bar & operator=(Bar && other);

		///
		///Metoda zwraca wartość zasobu obiektu
		///
		const float getValue() const;

		///
		///Metoda ustawia wartość zasobu obiektu
		///
		///@param value - wartość liczbowa
		///
		const void setValue(float value);

		///
		///Metoda pobiera grubość paska
		///
		const float getThickness() const;

		///
		///Metoda ustawia grubość paska
		///
		///@param thickness - grubość paska
		///
		const void setThickness(float thickness);

		///
		///Metoda zwraca wektor kalibracji położenia obiektu
		///
		sf::Vector2f & getVectorOffset();

		///
		///Metoda ładująca dane
		///
		///@param name - stała referencja na std::string
		///
		bool load(const std::string & name);

		///
		///Metoda ładująca dane z xml
		///
		///@param xml - referencja na obiekt klasy CXml
		///
		bool load(CXml & xml);

		///
		///Wirtualna metoda rysująca obiekt
		///
		virtual void draw(sf::RenderWindow *render);

	private:

		std::string m_bar_name; //nazwa paska
		float m_value; //wartość liczbowa obiektu
		float m_thickness; //grubość paska
		sf::Vector2f m_vector_offset; //położenie obiektu względem właściciela
									 
	};
} //namespace displayable
#endif //H_BAR_JACK
