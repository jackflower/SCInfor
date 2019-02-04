/*
 _________________________________________
| CPhysicalInfo.h - definicja klasy       |
| Jack Flower - April 2014.               |
|_________________________________________|

 */

#ifndef H_PHYSICAL_INFO_JACK
#define H_PHYSICAL_INFO_JACK

#include "../../../RTTI/RTTI.h"
#include "../CPhysical.h"
#include "../../../Rendering/Displayable/CRectangle.h"

using namespace rendering::primitives;

namespace logic
{
	///
	///Klasa reprezentuje logiczn� i graficzn� informacj� o stanie obiektu
	///
	class CPhysicalInfo : public CPhysical
	{
		RTTI_DECL;

		///
		///Deklaracja przyja�ni
		///
		friend class CPhysicalManager;

		//Aby uzyska� obiekt CPhysicalInfo, nale�y wywo�a� CPhysicalManager::CreatePhysicalInfo();

	protected:

		///
		///Chroniony konstruktor domy�lny - u�ywany wy��cznie przez CPhysicalManager
		///
		CPhysicalInfo(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj�cy
		///
		///@param CPhysicalInfoCopy - parametr - obiekt klasy CPhysicalInfo
		///
		CPhysicalInfo(const CPhysicalInfo &CPhysicalInfoCopy);

		///
		///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
		///
		virtual ~CPhysicalInfo();

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca nazw� obiektu
		///
		const std::string &GetPhysicalInfoName() const;

		///
		///Metoda ustawia nazw� obiektu
		///
		///@param & physical_info_name - sta�a referencja na obiekt klasy std::string
		///
		void SetPhysicalInfoName(const std::string & physical_info_name);

		///
		///Metoda zwraca indeks warstwy renderingu obiektu
		///
		inline int GetZIndexRectangle() { return m_z_index_rectangle; }

		///
		///Metoda ustawia indeks warstwy renderingu obiektu
		///
		///@param z_index_rectangle - indeks warstwy renderingu obiektu
		///
		void SetZIndexRectangle(int z_index_rectangle);
		
		///
		///Metoda zwraca flag�, czy obiekt posiada progress bar (energia-�ycie)
		///
		const bool getUseStatusBarEnergy() const;

		///
		///Metoda ustawia flag�, czy obiekt posiada progress bar (energia-�ycie)
		///
		///@param use_status_bar_energy - flaga, czy obiekt posiada progress bar (energia-�ycie)
		///
		void setUseStatusBarEnergy(bool use_status_bar_energy);

		///
		///Metoda zwraca flag�, czy obiekt posiada progress bar (paliwo/tlen)
		///
		const bool getUseStatusBarFuel() const;

		///
		///Metoda ustawia flag�, czy obiekt posiada progress bar (paliwo/tlen)
		///
		///@param use_status_bar_fuel - flaga, czy obiekt posiada progress bar (energia-�ycie)
		///
		void setUseStatusBarFuel(bool use_status_bar_fuel);

		///
		///Metoda zwraca kolor status progress bar (energia-�ycie)
		///
		const sf::Color& getFillColorEnergy() const;

		///
		///Metoda ustawia kolor status progress bar (energia-�ycie)
		///
		///@param &color_bar_energy - sta�a referencja na obiekt klasy sf::Color
		///
		void setFillColorEnergy(const sf::Color& color_bar_energy);

		///
		///Metoda zwraca kolor status progress bar (paliwo/tlen)
		///
		const sf::Color& getFillColorFuel() const;

		///
		///Metoda ustawia kolor status progress bar (paliwo/tlen)
		///
		///@param &color_bar_fuel - sta�a referencja na obiekt klasy sf::Color
		///
		void setFillColorFuel(const sf::Color& color_bar_fuel);

		///
		///Metoda zwraca wektor pozycji paska - progress bar (energia-�ycie)
		///
		const sf::Vector2f& getPositionStatusBarEnergy() const;

		///
		///Metoda zwraca wektor pozycji paska - progress bar (energia-�ycie)
		///
		///@param & position_status_bar_energy - wektor pozycji paska - progress bar (energia-�ycie)
		///
		void setPositionStatusBarEnergy(const sf::Vector2f & position_status_bar_energy);

		///
		///Metoda zwraca wektor pozycji paska - progress bar (energia-�ycie)
		///
		///@param position_status_bar_energy_x - sk��dowa x pozycji paska - progress bar (energia-�ycie)
		///
		///@param position_status_bar_energy_y - sk��dowa y pozycji paska - progress bar (energia-�ycie)
		///
		void setPositionStatusBarEnergy(float position_status_bar_energy_x, float position_status_bar_energy_y);

		///
		///Metoda zwraca wektor pozycji paska - progress bar (paliwo/tlen)
		///
		const sf::Vector2f& getPositionStatusBarFuel() const;

		///
		///Metoda zwraca wektor pozycji paska - progress bar (paliwo/tlen)
		///
		///@param & position_status_bar_energy - wektor pozycji paska - progress bar (paliwo/tlen)
		///
		void setPositionStatusBarFuel(const sf::Vector2f & position_status_bar_fuel);

		///
		///Metoda zwraca wektor pozycji paska - progress bar (paliwo/tlen)
		///
		///@param position_status_bar_fuel_x - sk��dowa x pozycji paska - progress bar (paliwo/tlen)
		///
		///@param position_status_bar_fuel_y - sk��dowa y pozycji paska - progress bar (paliwo/tlen)
		///
		void setPositionStatusBarFuel(float position_status_bar_fuel_x, float position_status_bar_fuel_y);

		///
		///Metoda zwraca rozmiar obiektu - rozmiar paska - progress bar (energia-�ycie)
		///
		const sf::Vector2f & GetEnergyStatusBarSize() const;

		///
		///Metoda ustawia rozmiar obiektu - rozmiar paska - progress bar (energia-�ycie)
		///
		///@param size_energy - rozmiar obiektu
		///
		void SetEnergyStatusBarSize(const sf::Vector2f& size_energy);

		///
		///Metoda ustawia rozmiar obiektu - rozmiar paska - progress bar (energia-�ycie)
		///
		///@param size_energy_x - rozmiar obiektu - x
		///
		///@param size_energy_y - rozmiar obiektu - y
		///
		void SetEnergyStatusBarSize(float size_energy_x, float size_energy_y);

		///
		///Metoda zwraca rozmiar obiektu - rozmiar paska - progress bar (paliwo/tlen)
		///
		const sf::Vector2f & GetFuelStatusBarSize() const;

		///
		///Metoda ustawia rozmiar obiektu - rozmiar paska - progress bar (paliwo/tlen)
		///
		///@param size_fuel - rozmiar obiektu
		///
		void SetFuelStatusBarSize(const sf::Vector2f& size_fuel);

		///
		///Metoda ustawia rozmiar obiektu - rozmiar paska - progress bar (paliwo/tlen)
		///
		///@param size_fuel_x - rozmiar obiektu - x
		///
		///@param size_fuel_y - rozmiar obiektu - y
		///
		void SetFuelStatusBarSize(float size_fuel_x, float size_fuel_y);

		///
		///Metoda zwraca wektor przesuni�cia pozycji obiektu wzgl�dem w�a�ciciela - (energia-�ycie)
		///
		const sf::Vector2f & GetEnergyPositionStatusBarOffset() const;

		///
		///Metoda ustawia wektor przesuni�cia pozycji obiektu wzgl�dem w�a�ciciela - (energia-�ycie)
		///
		///@param position_offset_energy - wektor przesuni�cia pozycji obiektu wzgl�dem w�a�ciciela
		///
		void SetEnergyPositionStatusBarOffset(const sf::Vector2f& position_offset_energy);

		///
		///Metoda ustawia wektor przesuni�cia pozycji obiektu wzgl�dem w�a�ciciela - (energia-�ycie)
		///
		///@param position_offset_energy_x - wektor przesuni�cia pozycji obiektu wzgl�dem w�a�ciciela - x
		///
		///@param position_offset_energy_y - wektor przesuni�cia pozycji obiektu wzgl�dem w�a�ciciela - y
		///
		void SetEnergyPositionStatusBarOffset(float position_offset_energy_x, float position_offset_energy_y);

		///
		///Metoda zwraca wektor przesuni�cia pozycji obiektu wzgl�dem w�a�ciciela - (paliwo/tlen)
		///
		const sf::Vector2f & GetFuelPositionStatusBarOffset() const;

		///
		///Metoda ustawia wektor przesuni�cia pozycji obiektu wzgl�dem w�a�ciciela - (paliwo/tlen)
		///
		///@param position_offset_fuel - wektor przesuni�cia pozycji obiektu wzgl�dem w�a�ciciela
		///
		void SetFuelPositionStatusBarOffset(const sf::Vector2f& position_offset_fuel);

		///
		///Metoda ustawia wektor przesuni�cia pozycji obiektu wzgl�dem w�a�ciciela - (paliwo/tlen)
		///
		///@param position_offset_fuel_x - wektor przesuni�cia pozycji obiektu wzgl�dem w�a�ciciela - x
		///
		///@param position_offset_fuel_y - wektor przesuni�cia pozycji obiektu wzgl�dem w�a�ciciela - y
		///
		void SetFuelPositionStatusBarOffset(float position_offset_fuel_x, float position_offset_fuel_y);

		///
		///Metoda sprawdza, czy trzeba utworzy� obiekt klasy CRectangle (energia-�ycie)
		///
		void InitStatusBarEnergy();

		///
		///Metoda sprawdza, czy trzeba utworzy� obiekt klasy CRectangle (paliwo/tlen)
		///
		void InitStatusBarFuel();

		///
		///Wirtualna metoda aktualizuj�ca obiekt
		///
		///@param dt - czas
		///
		virtual void Update(float dt);

		///
		///Metoda zwraca wska�nik na obiekt klasy CRectangle - graficzna reprezentacja (energia-�ycie)
		///
		inline CRectangle*	getStatusBarEnergy() { return p_status_bar_energy; }

		///
		///Metoda zwraca wska�nik na obiekt klasy CRectangle - graficzna reprezentacja (paliwo/tlen)
		///
		inline CRectangle*	getStatusBarFuel() { return	p_status_bar_fuel; }

	private:

		std::string		m_physical_info_name;			//nazwa logicznej i graficznej informacji o stanie obiektu
		int				m_z_index_rectangle;			//indeks warstwy rysowania
		bool			m_use_status_bar_energy;		//flaga, czy obiekt posiada progress bar (energia-�ycie)
		bool			m_use_status_bar_fuel;			//flaga, czy obiekt posiada progress bar (paliwo/tlen)
		sf::Color		m_color_bar_energy;				//kolor status progress bar (energia-�ycie)
		sf::Color		m_color_bar_fuel;				//kolor status progress bar (paliwo/tlen)
		sf::Vector2f	m_position_status_bar_energy;	//wektor pozycji paska - progress bar (energia-�ycie)
		sf::Vector2f	m_position_status_bar_fuel;		//wektor pozycji paska - progress bar (paliwo/tlen)
		sf::Vector2f	m_size_energy;					//rozmiar paska - progress bar (energia-�ycie)
		sf::Vector2f	m_size_fuel;					//rozmiar paska - progress bar (paliwo/tlen)
		sf::Vector2f	m_position_offset_energy;		//wektor kalibracji po�o�enia obiektu - progress bar (energia-�ycie)
		sf::Vector2f	m_position_offset_fuel;			//wektor kalibracji po�o�enia obiektu - progress bar (paliwo/tlen)
		CRectangle*		p_status_bar_energy;			//wska�nik na obiekt CRectangle (energia-�ycie)
		CRectangle*		p_status_bar_fuel;				//wska�nik na obiekt CRectangle (paliwo/tlen)
	};
}//namespace logic
#endif//H_PHYSICAL_INFO_JACK