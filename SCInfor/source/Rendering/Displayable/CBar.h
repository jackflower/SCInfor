//  _________________________________
// | CBar.h - class definition       |
// | Jack Flower December 2012       |
// |_________________________________|
//

#ifndef _H_BAR_JACK
#define _H_BAR_JACK

#include "CDisplayable.h"
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
	///Klasa reprezentuje graficzn� prezentacj� warto�ci - pasek stanu - progress bar
	///
	class CBar : public CDisplayable
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor domy�lny
		///
		CBar();

		///
		///Konstruktor kopiuj�cy
		///
		CBar(const CBar& CBarCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~CBar();

		///
		///Metoda zwraca warto�� zasobu obiektu
		///
		const float GetValue() const;

		///
		///Metoda ustawia warto�� zasobu obiektu
		///
		///@param value - warto�� liczbowa
		///
		const void SetValue(float value);

		///
		///Metoda pobiera grubo�� paska
		///
		const float GetThickness() const;

		///
		///Metoda ustawia grubo�� paska
		///
		///@param thickness - grubo�� paska
		///
		const void SetThickness(float thickness);

		///
		///Metoda zwraca wektor kalibracji po�o�enia obiektu
		///
		sf::Vector2f& GetVectorOffset();

		///
		///Metoda �aduje dane
		///
		///@param &name - sta�a referencja na std::string
		///
		//const void LoadData(const std::string &name);

		///
		///Metoda �aduj�ca dane
		///
		///@param &name - sta�a referencja na std::string
		///
		//bool load(const std::string &name);

		///
		///Metoda �aduj�ca dane z xml
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		//bool load(CXml &xml);

		///
		///Wirtualna metoda rysuj�ca obiekt
		///
		virtual void Draw(sf::RenderWindow* render);


	private:

		std::string		m_bar_name;			//nazwa paska
		float			m_value;			//warto�� liczbowa obiektu
		float			m_thickness;		//grubo�� paska
		sf::Vector2f	m_vector_offset;	//wektor kalibracji po�o�enia obiektu
											//wzgl�dem w�a�ciciela tego obiektu - CBar
	};
} //namespace displayable
#endif // _H_BAR_JACK
