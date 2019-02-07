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
	///Klasa reprezentuje graficzn¹ prezentacjê wartoœci - pasek stanu - progress bar
	///
	class CBar : public CDisplayable
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor domyœlny
		///
		CBar();

		///
		///Konstruktor kopiuj¹cy
		///
		CBar(const CBar& CBarCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~CBar();

		///
		///Metoda zwraca wartoœæ zasobu obiektu
		///
		const float GetValue() const;

		///
		///Metoda ustawia wartoœæ zasobu obiektu
		///
		///@param value - wartoœæ liczbowa
		///
		const void SetValue(float value);

		///
		///Metoda pobiera gruboœæ paska
		///
		const float GetThickness() const;

		///
		///Metoda ustawia gruboœæ paska
		///
		///@param thickness - gruboœæ paska
		///
		const void SetThickness(float thickness);

		///
		///Metoda zwraca wektor kalibracji po³o¿enia obiektu
		///
		sf::Vector2f& GetVectorOffset();

		///
		///Metoda ³aduje dane
		///
		///@param &name - sta³a referencja na std::string
		///
		//const void LoadData(const std::string &name);

		///
		///Metoda ³aduj¹ca dane
		///
		///@param &name - sta³a referencja na std::string
		///
		//bool load(const std::string &name);

		///
		///Metoda ³aduj¹ca dane z xml
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		//bool load(CXml &xml);

		///
		///Wirtualna metoda rysuj¹ca obiekt
		///
		virtual void Draw(sf::RenderWindow* render);


	private:

		std::string		m_bar_name;			//nazwa paska
		float			m_value;			//wartoœæ liczbowa obiektu
		float			m_thickness;		//gruboœæ paska
		sf::Vector2f	m_vector_offset;	//wektor kalibracji po³o¿enia obiektu
											//wzglêdem w³aœciciela tego obiektu - CBar
	};
} //namespace displayable
#endif // _H_BAR_JACK
