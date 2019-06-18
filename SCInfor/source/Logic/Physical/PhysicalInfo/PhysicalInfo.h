//  _________________________________________
// | PhysicalInfo.h - class definition       |
// | Jack Flower - April 2014                |
// |_________________________________________|
//

#ifndef H_PHYSICAL_INFO_JACK
#define H_PHYSICAL_INFO_JACK

#include "../Physical.h"
#include "../../../RTTI/RTTI.h"
#include "../../../Rendering/Displayable/Rectangle.h"

using namespace rendering::primitives;

namespace logic
{
	///
	///Klasa reprezentuje logiczną i graficzną informację o stanie obiektu
	///
	class PhysicalInfo : public Physical
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaźni
		///
		friend class PhysicalManager;

		//Aby uzyskać obiekt PhysicalInfo, należy wywołać PhysicalManager::CreatePhysicalInfo();

	protected:

		///
		///Chroniony konstruktor domyślny - używany wyłącznie przez PhysicalManager
		///
		///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
		///
		PhysicalInfo(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiujący
		///
		///@param PhysicalInfoCopy - parametr - obiekt klasy PhysicalInfo
		///
		PhysicalInfo(const PhysicalInfo & PhysicalInfoCopy);

		///
		///Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
		///
		virtual ~PhysicalInfo();

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca nazwę obiektu
		///
		const std::string & getPhysicalInfoName() const;

		///
		///Metoda ustawia nazwę obiektu
		///
		///@param physical_info_name - stała referencja na obiekt klasy std::string
		///
		void setPhysicalInfoName(const std::string & physical_info_name);

		///
		///Metoda zwraca indeks warstwy renderingu obiektu
		///
		int getZIndexRectangle();

		///
		///Metoda ustawia indeks warstwy renderingu obiektu
		///
		///@param z_index_rectangle - indeks warstwy renderingu obiektu
		///
		void setZIndexRectangle(int z_index_rectangle);
		
		///
		///Metoda zwraca flagę, czy obiekt posiada progress bar (energia-życie)
		///
		const bool getUseStatusBarEnergy() const;

		///
		///Metoda ustawia flagę, czy obiekt posiada progress bar (energia-życie)
		///
		///@param use_status_bar_energy - flaga, czy obiekt posiada progress bar (energia-życie)
		///
		void setUseStatusBarEnergy(bool use_status_bar_energy);

		///
		///Metoda zwraca flagę, czy obiekt posiada progress bar (paliwo/tlen)
		///
		const bool getUseStatusBarFuel() const;

		///
		///Metoda ustawia flagę, czy obiekt posiada progress bar (paliwo/tlen)
		///
		///@param use_status_bar_fuel - flaga, czy obiekt posiada progress bar (energia-życie)
		///
		void setUseStatusBarFuel(bool use_status_bar_fuel);

		///
		///Metoda zwraca kolor status progress bar (energia-życie)
		///
		const sf::Color & getFillColorEnergy() const;

		///
		///Metoda ustawia kolor status progress bar (energia-życie)
		///
		///@param color_bar_energy - stała referencja na obiekt klasy sf::Color
		///
		void setFillColorEnergy(const sf::Color & color_bar_energy);

		///
		///Metoda zwraca kolor status progress bar (paliwo/tlen)
		///
		const sf::Color & getFillColorFuel() const;

		///
		///Metoda ustawia kolor status progress bar (paliwo/tlen)
		///
		///@param color_bar_fuel - stała referencja na obiekt klasy sf::Color
		///
		void setFillColorFuel(const sf::Color & color_bar_fuel);

		///
		///Metoda zwraca wektor pozycji paska - progress bar (energia-życie)
		///
		const sf::Vector2f & getPositionStatusBarEnergy() const;

		///
		///Metoda zwraca wektor pozycji paska - progress bar (energia-życie)
		///
		///@param position_status_bar_energy - wektor pozycji paska - progress bar (energia-życie)
		///
		void setPositionStatusBarEnergy(const sf::Vector2f & position_status_bar_energy);

		///
		///Metoda zwraca wektor pozycji paska - progress bar (energia-życie)
		///
		///@param position_status_bar_energy_x - skłądowa x pozycji paska - progress bar (energia-życie)
		///
		///@param position_status_bar_energy_y - skłądowa y pozycji paska - progress bar (energia-życie)
		///
		void setPositionStatusBarEnergy(float position_status_bar_energy_x, float position_status_bar_energy_y);

		///
		///Metoda zwraca wektor pozycji paska - progress bar (paliwo/tlen)
		///
		const sf::Vector2f & getPositionStatusBarFuel() const;

		///
		///Metoda zwraca wektor pozycji paska - progress bar (paliwo/tlen)
		///
		///@param position_status_bar_energy - wektor pozycji paska - progress bar (paliwo/tlen)
		///
		void setPositionStatusBarFuel(const sf::Vector2f & position_status_bar_fuel);

		///
		///Metoda zwraca wektor pozycji paska - progress bar (paliwo/tlen)
		///
		///@param position_status_bar_fuel_x - skłądowa x pozycji paska - progress bar (paliwo/tlen)
		///
		///@param position_status_bar_fuel_y - skłądowa y pozycji paska - progress bar (paliwo/tlen)
		///
		void setPositionStatusBarFuel(float position_status_bar_fuel_x, float position_status_bar_fuel_y);

		///
		///Metoda zwraca rozmiar obiektu - rozmiar paska - progress bar (energia-życie)
		///
		const sf::Vector2f & getEnergyStatusBarSize() const;

		///
		///Metoda ustawia rozmiar obiektu - rozmiar paska - progress bar (energia-życie)
		///
		///@param size_energy - rozmiar obiektu - stała referencja na obiekt klasy sf::Vector2f
		///
		void setEnergyStatusBarSize(const sf::Vector2f & size_energy);

		///
		///Metoda ustawia rozmiar obiektu - rozmiar paska - progress bar (energia-życie)
		///
		///@param size_energy_x - rozmiar obiektu - x
		///
		///@param size_energy_y - rozmiar obiektu - y
		///
		void setEnergyStatusBarSize(float size_energy_x, float size_energy_y);

		///
		///Metoda zwraca rozmiar obiektu - rozmiar paska - progress bar (paliwo/tlen)
		///
		const sf::Vector2f & getFuelStatusBarSize() const;

		///
		///Metoda ustawia rozmiar obiektu - rozmiar paska - progress bar (paliwo/tlen)
		///
		///@param size_fuel - rozmiar obiektu - stała referencja na obiekt klasy sf::Vector2f
		///
		void setFuelStatusBarSize(const sf::Vector2f & size_fuel);

		///
		///Metoda ustawia rozmiar obiektu - rozmiar paska - progress bar (paliwo/tlen)
		///
		///@param size_fuel_x - rozmiar obiektu - x
		///
		///@param size_fuel_y - rozmiar obiektu - y
		///
		void setFuelStatusBarSize(float size_fuel_x, float size_fuel_y);

		///
		///Metoda zwraca wektor przesunięcia pozycji obiektu względem właściciela - (energia-życie)
		///
		const sf::Vector2f & getEnergyPositionStatusBarOffset() const;

		///
		///Metoda ustawia wektor przesunięcia pozycji obiektu względem właściciela - (energia-życie)
		///
		///@param position_offset_energy - wektor przesunięcia pozycji obiektu względem właściciela
		///
		void setEnergyPositionStatusBarOffset(const sf::Vector2f & position_offset_energy);

		///
		///Metoda ustawia wektor przesunięcia pozycji obiektu względem właściciela - (energia-życie)
		///
		///@param position_offset_energy_x - wektor przesunięcia pozycji obiektu względem właściciela - x
		///
		///@param position_offset_energy_y - wektor przesunięcia pozycji obiektu względem właściciela - y
		///
		void setEnergyPositionStatusBarOffset(float position_offset_energy_x, float position_offset_energy_y);

		///
		///Metoda zwraca wektor przesunięcia pozycji obiektu względem właściciela - (paliwo/tlen)
		///
		const sf::Vector2f & getFuelPositionStatusBarOffset() const;

		///
		///Metoda ustawia wektor przesunięcia pozycji obiektu względem właściciela - (paliwo/tlen)
		///
		///@param position_offset_fuel - wektor przesunięcia pozycji obiektu względem właściciela
		///
		void setFuelPositionStatusBarOffset(const sf::Vector2f & position_offset_fuel);

		///
		///Metoda ustawia wektor przesunięcia pozycji obiektu względem właściciela - (paliwo/tlen)
		///
		///@param position_offset_fuel_x - wektor przesunięcia pozycji obiektu względem właściciela - x
		///
		///@param position_offset_fuel_y - wektor przesunięcia pozycji obiektu względem właściciela - y
		///
		void setFuelPositionStatusBarOffset(float position_offset_fuel_x, float position_offset_fuel_y);

		///
		///Metoda sprawdza, czy trzeba utworzyć obiekt klasy Rectangle (energia-życie)
		///
		void initStatusBarEnergy();

		///
		///Metoda sprawdza, czy trzeba utworzyć obiekt klasy Rectangle (paliwo/tlen)
		///
		void initStatusBarFuel();

		///
		///Metoda zwraca wskaźnik na obiekt klasy Rectangle - graficzna reprezentacja (energia-życie)
		///
		Rectangle *getStatusBarEnergy();

		///
		///Metoda zwraca wskaźnik na obiekt klasy Rectangle - graficzna reprezentacja (paliwo/tlen)
		///
		Rectangle *getStatusBarFuel();

		///
		///Wirtualna metoda aktualizująca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);

	private:

		std::string m_physical_info_name; //nazwa logicznej i graficznej informacji o stanie obiektu
		int m_z_index_rectangle; //indeks warstwy rysowania
		bool m_use_status_bar_energy; //flaga, czy obiekt posiada progress bar (energia-życie)
		bool m_use_status_bar_fuel; //flaga, czy obiekt posiada progress bar (paliwo/tlen)
		sf::Color m_color_bar_energy; //kolor status progress bar (energia-życie)
		sf::Color m_color_bar_fuel; //kolor status progress bar (paliwo/tlen)
		sf::Vector2f m_position_status_bar_energy; //wektor pozycji paska - progress bar (energia-życie)
		sf::Vector2f m_position_status_bar_fuel; //wektor pozycji paska - progress bar (paliwo/tlen)
		sf::Vector2f m_size_energy; //rozmiar paska - progress bar (energia-życie)
		sf::Vector2f m_size_fuel; //rozmiar paska - progress bar (paliwo/tlen)
		sf::Vector2f m_position_offset_energy; //wektor kalibracji położenia obiektu - progress bar (energia-życie)
		sf::Vector2f m_position_offset_fuel; //wektor kalibracji położenia obiektu - progress bar (paliwo/tlen)
		Rectangle *p_status_bar_energy; //wskaźnik na obiekt Rectangle (energia-życie)
		Rectangle *p_status_bar_fuel; //wskaźnik na obiekt Rectangle (paliwo/tlen)
	};
}//namespace logic
#endif//H_PHYSICAL_INFO_JACK
