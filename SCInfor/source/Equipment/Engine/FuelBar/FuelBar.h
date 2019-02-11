//  ____________________________________
// | FuelBar.h - class definition       |
// | Jack Flower March 2014             |
// |____________________________________|
//

#ifndef H_FUEL_BAR_JACK
#define H_FUEL_BAR_JACK

#include "../../../RTTI/RTTI.h"
#include "../../../Logic/Physical/Physical.h"

using namespace logic;

namespace equipment
{

	///
	///Klasa reprezentuje wskaźnik stanu paliwa - progress bar
	///
	class FuelBar : public Physical
	{
		RTTI_DECL;
	
		///
		///Deklaracja przyjaźni
		///
		friend class CPhysicalManager;
	
		//Aby uzyskać obiekt FuelBar, należy wywołać CPhysicalManager::CreateFuelBar();

	private:

		///
		///Prywatny konstruktor domyślny - używany wyłącznie przez CPhysicalManager
		///
		///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
		///
		FuelBar(const std::wstring & uniqueId);

		///
		///Prywatny konstruktor kopiujący
		///
		///@param FuelBarCopy - stała referencja na obiekt klasy FuelBar
		///
		FuelBar(const FuelBar & FuelBarCopy);
		
		///
		///Destruktor
		///
		virtual ~FuelBar(void);


	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca nazwę obiektu
		///
		const std::string & getFuelBarName() const;

		///
		///Metoda ustawia nazwę obiektu
		///
		///@param fuelbar_name - stała referencja na obiekt klasy std::string
		///
		void setFuelBarName(const std::string & fuelbar_name);

		///
		///Metoda zwraca grubość paska
		///
		const float getThickness() const;

		///
		///Metoda ustawia grubość paska
		///
		///@param thickness - grubość paska
		///
		const void setThickness(float thickness);

		///
		///Metoda zwraca rozmiar obiektu
		///
		const sf::Vector2f & getBarSize() const;

		///
		///Metoda ustawia rozmiar obiektu
		///
		///@param size - rozmiar obiektu stała referencja na obiekt klasy sf::Vector2f
		///
		void setBarSize(const sf::Vector2f & size);

		///
		///Metoda ustawia rozmiar obiektu
		///
		///@param size_x - rozmiar obiektu - x
		///
		///@param size_y - rozmiar obiektu - y
		///
		void setBarSize(float size_x, float size_y);

		///
		///Metoda zwraca wektor kalibracji pozycji obiektu
		///
		const sf::Vector2f & getBarPositionOffset() const;

		///
		///Metoda ustawia wektor kalibracji pozycji obiektu
		///
		///@param position_offset - wektor kalibracji pozycji obiektu
		///
		void setBarPositionOffset(const sf::Vector2f & position_offset);

		///
		///Metoda ustawia wektor kalibracji pozycji obiektu
		///
		///@param position_offset_x - wektor kalibracji składowa - x
		///
		///@param position_offset_y - wektor kalibracji składowa - y
		///
		void setBarPositionOffset(float position_offset_x, float position_offset_y);

		///
		///Wirtualna metoda aktualizuje logikę obiektu
		///
		///@param dt - czas
		///
		void update(float dt);

	private:

		std::string	 m_fuelbar_name; //nazwa wskaźnika paliwa - progress bar
		float m_thickness; //grubość paska - progress bar
		sf::Vector2f m_size; //rozmiar paska - progress bar
		sf::Vector2f m_position_offset;	//wektor kalibracji położenia obiektu - progress bar

		//niech to tutaj poleży...nie wiem, czy będzie potrzebne
		//FuelBarTemplate*	p_template; //wskaźnik na obiekt klasy PhysicalTemplate

	};
}//namespace equipment
#endif //H_FUEL_BAR_JACK
