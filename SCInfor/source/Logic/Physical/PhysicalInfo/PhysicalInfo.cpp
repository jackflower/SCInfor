//  _________________________________________
// | PhysicalInfo.cpp - class implementation |
// | Jack Flower - April 2014                |
// |_________________________________________|
//

#include "PhysicalInfo.h"
#include "../../../Rendering/Drawable/Layers.h"
#include "../../../Rendering/Drawable/CDrawableManager.h"
#include <SFML/Graphics/RectangleShape.hpp>

namespace logic
{
	RTTI_IMPL(PhysicalInfo, Physical);

	//Chroniony konstruktor domyślny - używany wyłącznie przez PhysicalManager
	PhysicalInfo::PhysicalInfo(const std::wstring & uniqueId)
	:
		Physical(uniqueId),//konstruktor klasy bazowej
		m_physical_info_name(""),
		m_z_index_rectangle(Z_PHYSICAL_INFO_STATUS_BAR),
		m_use_status_bar_energy(true),
		m_use_status_bar_fuel(true),
		m_color_bar_energy(),
		m_color_bar_fuel(),
		m_position_status_bar_energy(0.0f, 0.0f),
		m_position_status_bar_fuel(0.0f, 0.0f),
		m_size_energy(0.0f, 0.0f),
		m_size_fuel(0.0f, 0.0f),
		m_position_offset_energy(0.0f, 0.0f),
		m_position_offset_fuel(0.0f, 0.0f),
		p_status_bar_energy(NULL),
		p_status_bar_fuel(NULL)
	{
		//zakładam, że wykorzystuję tylko część body, ale routing ligiki pozostaje elastyczny
		setZIndexBody(Z_PHYSICAL_INFO_BODY);
		setZIndexShadowBody(Z_PHYSICAL_INFO_BODY_SHADOW);
		setZIndexHead(Z_PHYSICAL_INFO_HEAD);
		setZIndexShadowHead(Z_PHYSICAL_INFO_HEAD_SHADOW);
	}

	//Chroniony konstruktor kopiujący
	PhysicalInfo::PhysicalInfo(const PhysicalInfo & PhysicalInfoCopy)
	:
		Physical(PhysicalInfoCopy),//konstruktor kopiujący klasy bazowej
		m_physical_info_name(PhysicalInfoCopy.m_physical_info_name),
		m_z_index_rectangle(PhysicalInfoCopy.m_z_index_rectangle),
		m_use_status_bar_energy(PhysicalInfoCopy.m_use_status_bar_energy),
		m_use_status_bar_fuel(PhysicalInfoCopy.m_use_status_bar_fuel),
		m_color_bar_energy(PhysicalInfoCopy.m_color_bar_energy),
		m_color_bar_fuel(PhysicalInfoCopy.m_color_bar_fuel),
		m_position_status_bar_energy(PhysicalInfoCopy.m_position_status_bar_energy),
		m_position_status_bar_fuel(PhysicalInfoCopy.m_position_status_bar_fuel),
		m_size_energy(PhysicalInfoCopy.m_size_energy),
		m_size_fuel(PhysicalInfoCopy.m_size_fuel),
		m_position_offset_energy(PhysicalInfoCopy.m_position_offset_energy),
		m_position_offset_fuel(PhysicalInfoCopy.m_position_offset_fuel),
		p_status_bar_energy(PhysicalInfoCopy.p_status_bar_energy),
		p_status_bar_fuel(PhysicalInfoCopy.p_status_bar_fuel)
	{
		//zakładam, że wykorzystuję tylko część body, ale routing ligiki pozostaje elastyczny
		setZIndexBody(Z_PHYSICAL_INFO_BODY);
		setZIndexShadowBody(Z_PHYSICAL_INFO_BODY_SHADOW);
		setZIndexHead(Z_PHYSICAL_INFO_HEAD);
		setZIndexShadowHead(Z_PHYSICAL_INFO_HEAD_SHADOW);
	}

	//Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
	PhysicalInfo::~PhysicalInfo()
	{
		if (p_status_bar_energy)
			gDrawableManager.DestroyDrawable(p_status_bar_energy);
		if (p_status_bar_fuel)
			gDrawableManager.DestroyDrawable(p_status_bar_fuel);

		//~Physical()
		m_physical_info_name = "";
		m_z_index_rectangle = 0;
		m_use_status_bar_energy = false;
		m_use_status_bar_fuel = false;
		//m_color_bar_energy
		//m_color_bar_fuel
		m_position_status_bar_energy.x = 0.0f;
		m_position_status_bar_energy.y = 0.0f;
		m_position_status_bar_fuel.x = 0.0f;
		m_position_status_bar_fuel.y = 0.0f;
		m_size_energy.x = 0.0f;
		m_size_energy.y = 0.0f;
		m_size_fuel.x = 0.0f;
		m_size_fuel.y = 0.0f;
		m_position_offset_energy.x = 0.0f;
		m_position_offset_energy.y = 0.0f;
		m_position_offset_fuel.x = 0.0f;
		m_position_offset_fuel.y = 0.0f;
		p_status_bar_energy = NULL;
		p_status_bar_fuel = NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string PhysicalInfo::getType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca nazwę obiektu
	const std::string & PhysicalInfo::getPhysicalInfoName() const
	{
		return m_physical_info_name;
	}

	//Metoda ustawia nazwę obiektu
	void PhysicalInfo::setPhysicalInfoName(const std::string & physical_info_name)
	{
		m_physical_info_name = physical_info_name;
	}

	//Metoda zwraca indeks warstwy renderingu obiektu
	int PhysicalInfo::getZIndexRectangle()
	{
		return m_z_index_rectangle;
	}

	//Metoda ustawia indeks warstwy renderingu obiektu
	void PhysicalInfo::setZIndexRectangle(int z_index_rectangle)
	{
		m_z_index_rectangle = z_index_rectangle;
	}

	//Metoda zwraca flagę, czy obiekt posiada progress bar (energia-życie)
	const bool PhysicalInfo::getUseStatusBarEnergy() const
	{
		return m_use_status_bar_energy;
	}

	//Metoda ustawia flagę, czy obiekt posiada progress bar (energia-życie)
	void PhysicalInfo::setUseStatusBarEnergy(bool use_status_bar_energy)
	{
		m_use_status_bar_energy = use_status_bar_energy;
	}

	//Metoda zwraca flagę, czy obiekt posiada progress bar (paliwo/tlen)
	const bool PhysicalInfo::getUseStatusBarFuel() const
	{
		return m_use_status_bar_fuel;
	}

	//Metoda ustawia flagę, czy obiekt posiada progress bar (paliwo/tlen)
	void PhysicalInfo::setUseStatusBarFuel(bool use_status_bar_fuel)
	{
		m_use_status_bar_fuel = use_status_bar_fuel;
	}

	//Metoda zwraca kolor status progress bar (energia-życie)
	const sf::Color & PhysicalInfo::getFillColorEnergy() const
	{
		return m_color_bar_energy;
	}

	//Metoda ustawia kolor status progress bar (energia-życie)
	void PhysicalInfo::setFillColorEnergy(const sf::Color & color_bar_energy)
	{
		if (p_status_bar_energy)
		{
			m_color_bar_energy = color_bar_energy;
			p_status_bar_energy->getRectangleShape()->setFillColor(m_color_bar_energy);

		}
	}

	//Metoda zwraca kolor status progress bar (paliwo/tlen)
	const sf::Color & PhysicalInfo::getFillColorFuel() const
	{
		return m_color_bar_fuel;
	}

	//Metoda ustawia kolor status progress bar (paliwo/tlen)
	void PhysicalInfo::setFillColorFuel(const sf::Color & color_bar_fuel)
	{
		if (p_status_bar_fuel)
		{
			m_color_bar_fuel = color_bar_fuel;
			p_status_bar_fuel->getRectangleShape()->setFillColor(m_color_bar_fuel);

		}
	}

	//Metoda zwraca wektor pozycji paska - progress bar (energia-życie)
	const sf::Vector2f & PhysicalInfo::getPositionStatusBarEnergy() const
	{
		return m_position_status_bar_energy;
	}

	//Metoda zwraca wektor pozycji paska - progress bar (energia-życie)
	void PhysicalInfo::setPositionStatusBarEnergy(const sf::Vector2f & position_status_bar_energy)
	{
		if(p_status_bar_energy)
		{
			m_position_status_bar_energy = position_status_bar_energy;
			p_status_bar_energy->getRectangleShape()->setPosition(m_position_status_bar_energy);
		}
	}

	//Metoda zwraca wektor pozycji paska - progress bar (energia-życie)
	void PhysicalInfo::setPositionStatusBarEnergy(float position_status_bar_energy_x, float position_status_bar_energy_y)
	{
		if(p_status_bar_energy)
		{
			m_position_status_bar_energy.x = position_status_bar_energy_x;
			m_position_status_bar_energy.y = position_status_bar_energy_y;
			p_status_bar_energy->getRectangleShape()->setPosition(m_position_status_bar_energy.x, m_position_status_bar_energy.y);
		}
	}

	//Metoda zwraca wektor pozycji paska - progress bar (paliwo/tlen)
	const sf::Vector2f & PhysicalInfo::getPositionStatusBarFuel() const
	{
		return m_position_status_bar_fuel;
	}

	//Metoda zwraca wektor pozycji paska - progress bar (paliwo/tlen)
	void PhysicalInfo::setPositionStatusBarFuel(const sf::Vector2f & position_status_bar_fuel)
	{
		if(p_status_bar_fuel)
		{
			m_position_status_bar_fuel = position_status_bar_fuel;
			p_status_bar_fuel->getRectangleShape()->setPosition(m_position_status_bar_fuel);
		}
	}

	//Metoda zwraca wektor pozycji paska - progress bar (paliwo/tlen)
	void PhysicalInfo::setPositionStatusBarFuel(float position_status_bar_fuel_x, float position_status_bar_fuel_y)
	{
		if(p_status_bar_fuel)
		{
			m_position_status_bar_fuel.x = position_status_bar_fuel_x;
			m_position_status_bar_fuel.y = position_status_bar_fuel_y;
			p_status_bar_fuel->getRectangleShape()->setPosition(m_position_status_bar_fuel.x, m_position_status_bar_fuel.y);
		}
	}

	//Metoda zwraca rozmiar obiektu - rozmiar paska - progress bar (energia-życie)
	const sf::Vector2f & PhysicalInfo::getEnergyStatusBarSize() const
	{
		return m_size_energy;
	}

	//Metoda ustawia rozmiar obiektu - rozmiar paska - progress bar (energia-życie)
	void PhysicalInfo::setEnergyStatusBarSize(const sf::Vector2f & size_energy)
	{
		if (p_status_bar_energy)
		{
			m_size_energy = size_energy;
			p_status_bar_energy->getRectangleShape()->setSize(m_size_energy);
		}
	}

	//Metoda ustawia rozmiar obiektu - rozmiar paska - progress bar (energia-życie)
	void PhysicalInfo::setEnergyStatusBarSize(float size_energy_x, float size_energy_y)
	{
		m_size_energy.x = size_energy_x;
		m_size_energy.y = size_energy_y;
	}

	//Metoda zwraca rozmiar obiektu - rozmiar paska - progress bar (paliwo/tlen)
	const sf::Vector2f & PhysicalInfo::getFuelStatusBarSize() const
	{
		return m_size_fuel;
	}

	//Metoda ustawia rozmiar obiektu - rozmiar paska - progress bar (paliwo/tlen)
	void PhysicalInfo::setFuelStatusBarSize(const sf::Vector2f & size_fuel)
	{
		if (p_status_bar_fuel)
		{
			m_size_fuel = size_fuel;
			p_status_bar_fuel->getRectangleShape()->setSize(m_size_fuel);
		}
	}

	//Metoda ustawia rozmiar obiektu - rozmiar paska - progress bar (paliwo/tlen)
	void PhysicalInfo::setFuelStatusBarSize(float size_fuel_x, float size_fuel_y)
	{
		m_size_fuel.x = size_fuel_x;
		m_size_fuel.y = size_fuel_y;
	}

	//Metoda zwraca wektor przesunięcia pozycji obiektu względem właściciela - (energia-życie)
	const sf::Vector2f & PhysicalInfo::getEnergyPositionStatusBarOffset() const
	{
		return m_position_offset_energy;
	}

	//Metoda ustawia wektor przesunięcia pozycji obiektu względem właściciela - (energia-życie)
	void PhysicalInfo::setEnergyPositionStatusBarOffset(const sf::Vector2f & position_offset_energy)
	{
		m_position_offset_energy = position_offset_energy;
	}

	//Metoda ustawia wektor przesunięcia pozycji obiektu względem właściciela - (energia-życie)
	void PhysicalInfo::setEnergyPositionStatusBarOffset(float position_offset_energy_x, float position_offset_energy_y)
	{
		m_position_offset_energy.x = position_offset_energy_x;
		m_position_offset_energy.y = position_offset_energy_y;
	}

	//Metoda zwraca wektor przesunięcia pozycji obiektu względem właściciela - (paliwo/tlen)
	const sf::Vector2f & PhysicalInfo::getFuelPositionStatusBarOffset() const
	{
		return m_position_offset_fuel;
	}

	//Metoda ustawia wektor przesunięcia pozycji obiektu względem właściciela - (paliwo/tlen)
	void PhysicalInfo::setFuelPositionStatusBarOffset(const sf::Vector2f & position_offset_fuel)
	{
		m_position_offset_fuel = position_offset_fuel;
	}

	//Metoda ustawia wektor przesunięcia pozycji obiektu względem właściciela - (paliwo/tlen)
	void PhysicalInfo::setFuelPositionStatusBarOffset(float position_offset_fuel_x, float position_offset_fuel_y)
	{
		m_position_offset_fuel.x = position_offset_fuel_x;
		m_position_offset_fuel.y = position_offset_fuel_y;
	}

	//Metoda zwraca wskaźnik na obiekt klasy CRectangle - graficzna reprezentacja (energia-życie)
	CRectangle *PhysicalInfo::getStatusBarEnergy()
	{
		return p_status_bar_energy;
	}

	//Metoda zwraca wskaźnik na obiekt klasy CRectangle - graficzna reprezentacja (paliwo/tlen)
	CRectangle *PhysicalInfo::getStatusBarFuel()
	{
		return	p_status_bar_fuel;
	}

	//Wirtualna metoda aktualizująca obiekt
	void PhysicalInfo::update(float dt)
	{
		if(p_status_bar_energy)
			setPositionStatusBarEnergy(getPosition().x - m_position_offset_energy.x, getPosition().y - m_position_offset_energy.y);

		if(p_status_bar_fuel)
			setPositionStatusBarFuel(getPosition().x - m_position_offset_fuel.x, getPosition().y - m_position_offset_fuel.y);
	}

	//Metoda sprawdza, czy trzeba utworzyć obiekt klasy CRectangle (energia-życie)
	void PhysicalInfo::initStatusBarEnergy()
	{
		if ((m_use_status_bar_energy) && (!p_status_bar_energy))
		{
			p_status_bar_energy = gDrawableManager.CreateRectangle(getZIndexRectangle());
			if (!p_status_bar_energy)
			{
				fprintf(stderr, "error: PhysicalInfo::InitStatusBarEnergy, p_status_bar_energy null, returning\n");
				return;
			}
		}
	}

	//Metoda sprawdza, czy trzeba utworzyć obiekt klasy CRectangle (paliwo/tlen)
	void PhysicalInfo::initStatusBarFuel()
	{
		if ((m_use_status_bar_fuel) && (!p_status_bar_fuel))
		{
			p_status_bar_fuel = gDrawableManager.CreateRectangle(getZIndexRectangle());
			if (!p_status_bar_fuel)
			{
				fprintf(stderr, "error: PhysicalInfo::InitStatusBarFuel, p_status_bar_fuel null, returning\n");
				return;
			}
		}
	}
}//namespace logic
