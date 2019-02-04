//  _____________________________________
// | CFuelBar.h - class definition       |
// | Jack Flower March 2014              |
// |_____________________________________|
//

#ifndef H_FUEL_BAR_JACK
#define H_FUEL_BAR_JACK

#include "../../../RTTI/RTTI.h"
#include "../../../Logic/Physical/CPhysical.h"

using namespace logic;

namespace equipment
{

	///
	///Klasa reprezentuje wska�nik stanu paliwa - progress bar
	///
	class CFuelBar : public CPhysical
	{
		RTTI_DECL;
	
		///
		///Deklaracja przyja�ni
		///
		friend class CPhysicalManager;
	
		//Aby uzyska� obiekt CFuelBar, nale�y wywo�a� CPhysicalManager::CreateFuelBar();

	private:

		///
		///Prywatny konstruktor domy�lny - u�ywany wy��cznie przez CPhysicalManager
		///
		CFuelBar(const std::wstring& uniqueId);

		///
		///Prywatny konstruktor kopiuj�cy
		///
		///@param &CFuelBarCopy - obiekt klasy CFuelBar
		///
		CFuelBar(const CFuelBar& CFuelBarCopy);
		
		///
		///Destruktor
		///
		virtual ~CFuelBar(void);


	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca nazw� obiektu
		///
		const std::string &GetFuelBarName() const;

		///
		///Metoda ustawia nazw� obiektu
		///
		///@param & fuelbar_name - sta�a referencja na obiekt klasy std::string
		///
		void SetFuelBarName(const std::string & fuelbar_name);

		///
		///Metoda zwraca grubo�� paska
		///
		const float GetThickness() const;

		///
		///Metoda ustawia grubo�� paska
		///
		///@param thickness - grubo�� paska
		///
		const void SetThickness(float thickness);

		///
		///Metoda zwraca rozmiar obiektu
		///
		const sf::Vector2f & GetBarSize() const;

		///
		///Metoda ustawia rozmiar obiektu
		///
		///@param size - rozmiar obiektu
		///
		void SetBarSize(const sf::Vector2f& size);

		///
		///Metoda ustawia rozmiar obiektu
		///
		///@param size_x - rozmiar obiektu - x
		///
		///@param size_y - rozmiar obiektu - y
		///
		void SetBarSize(float size_x, float size_y);

		///
		///Metoda zwraca wektor kalibracji pozycji obiektu
		///
		const sf::Vector2f & GetBarPositionOffset() const;

		///
		///Metoda ustawia wektor kalibracji pozycji obiektu
		///
		///@param position_offset - wektor kalibracji pozycji obiektu
		///
		void SetBarPositionOffset(const sf::Vector2f& position_offset);

		///
		///Metoda ustawia wektor kalibracji pozycji obiektu
		///
		///@param position_offset_x - wektor kalibracji sk�adowa - x
		///
		///@param position_offset_y - wektor kalibracji sk�adowa - y
		///
		void SetBarPositionOffset(float position_offset_x, float position_offset_y);

		///
		///Wirtualna metoda aktualizuje logik� obiektu
		///
		///@param dt - czas
		///
		void update(float dt);

	private:

		std::string		m_fuelbar_name;		//nazwa wska�nika paliwa - progress bar
		float			m_thickness;		//grubo�� paska - progress bar
		sf::Vector2f	m_size;				//rozmiar paska - progress bar
		sf::Vector2f	m_position_offset;	//wektor kalibracji po�o�enia obiektu - progress bar

		//CFuelBarTemplate*	p_template;					//wska�nik na obiekt klasy CPhysicalTemplate

	};
}//namespace equipment
#endif //H_FUEL_BAR_JACK
