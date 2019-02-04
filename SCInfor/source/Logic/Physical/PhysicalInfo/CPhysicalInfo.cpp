/*
 _________________________________________
| CPhysicalInfo.cpp - implementacja klasy |
| Jack Flower - April 2014.               |
|_________________________________________|

 */

#include "CPhysicalInfo.h"
#include "../../../Rendering/Drawable/Layers.h"
#include "../../../Rendering/Drawable/CDrawableManager.h"
#include <SFML/Graphics/RectangleShape.hpp>

namespace logic
{
	RTTI_IMPL(CPhysicalInfo, CPhysical);

	//Chroniony konstruktor domyœlny - u¿ywany wy³¹cznie przez CPhysicalManager
	CPhysicalInfo::CPhysicalInfo(const std::wstring& uniqueId)
	:
		CPhysical						(uniqueId),//konstruktor klasy bazowej
		m_physical_info_name			(""),
		m_z_index_rectangle				(Z_PHYSICAL_INFO_STATUS_BAR),
		m_use_status_bar_energy			(true),
		m_use_status_bar_fuel			(true),
		m_color_bar_energy				(),
		m_color_bar_fuel				(),
		m_position_status_bar_energy	(0.0f, 0.0f),
		m_position_status_bar_fuel		(0.0f, 0.0f),
		m_size_energy					(0.0f, 0.0f),
		m_size_fuel						(0.0f, 0.0f),
		m_position_offset_energy		(0.0f, 0.0f),
		m_position_offset_fuel			(0.0f, 0.0f),
		p_status_bar_energy				(NULL),
		p_status_bar_fuel				(NULL)
	{
		//zak³adam, ¿e wykorzystujê tylko czêœæ body, ale routing ligiki pozostaje elastyczny
		SetZIndexBody(Z_PHYSICAL_INFO_BODY);
		SetZIndexShadowBody(Z_PHYSICAL_INFO_BODY_SHADOW);
		SetZIndexHead(Z_PHYSICAL_INFO_HEAD);
		SetZIndexShadowHead(Z_PHYSICAL_INFO_HEAD_SHADOW);
	}

	//Chroniony konstruktor kopiuj¹cy
	CPhysicalInfo::CPhysicalInfo(const CPhysicalInfo &CPhysicalInfoCopy)
	:
		CPhysical						(CPhysicalInfoCopy),//konstruktor kopiuj¹cy klasy bazowej
		m_physical_info_name			(CPhysicalInfoCopy.m_physical_info_name),
		m_z_index_rectangle				(CPhysicalInfoCopy.m_z_index_rectangle),
		m_use_status_bar_energy			(CPhysicalInfoCopy.m_use_status_bar_energy),
		m_use_status_bar_fuel			(CPhysicalInfoCopy.m_use_status_bar_fuel),
		m_color_bar_energy				(CPhysicalInfoCopy.m_color_bar_energy),
		m_color_bar_fuel				(CPhysicalInfoCopy.m_color_bar_fuel),
		m_position_status_bar_energy	(CPhysicalInfoCopy.m_position_status_bar_energy),
		m_position_status_bar_fuel		(CPhysicalInfoCopy.m_position_status_bar_fuel),
		m_size_energy					(CPhysicalInfoCopy.m_size_energy),
		m_size_fuel						(CPhysicalInfoCopy.m_size_fuel),
		m_position_offset_energy		(CPhysicalInfoCopy.m_position_offset_energy),
		m_position_offset_fuel			(CPhysicalInfoCopy.m_position_offset_fuel),
		p_status_bar_energy				(CPhysicalInfoCopy.p_status_bar_energy),
		p_status_bar_fuel				(CPhysicalInfoCopy.p_status_bar_fuel)
	{
		//zak³adam, ¿e wykorzystujê tylko czêœæ body, ale routing ligiki pozostaje elastyczny
		SetZIndexBody(Z_PHYSICAL_INFO_BODY);
		SetZIndexShadowBody(Z_PHYSICAL_INFO_BODY_SHADOW);
		SetZIndexHead(Z_PHYSICAL_INFO_HEAD);
		SetZIndexShadowHead(Z_PHYSICAL_INFO_HEAD_SHADOW);
	}

	//Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
	CPhysicalInfo::~CPhysicalInfo()
	{
		if (p_status_bar_energy)
			gDrawableManager.DestroyDrawable(p_status_bar_energy);
		if (p_status_bar_fuel)
			gDrawableManager.DestroyDrawable(p_status_bar_fuel);

		//CPhysical						not edit
		m_physical_info_name			= "";
		m_z_index_rectangle				= 0;
		m_use_status_bar_energy			= false;
		m_use_status_bar_fuel			= false;
		//m_color_bar_energy			not edit
		//m_color_bar_fuel				not edit
		m_position_status_bar_energy.x	= 0.0f;
		m_position_status_bar_energy.y	= 0.0f;
		m_position_status_bar_fuel.x	= 0.0f;
		m_position_status_bar_fuel.y	= 0.0f;
		m_size_energy.x					= 0.0f;
		m_size_energy.y					= 0.0f;
		m_size_fuel.x					= 0.0f;
		m_size_fuel.y					= 0.0f;
		m_position_offset_energy.x		= 0.0f;
		m_position_offset_energy.y		= 0.0f;
		m_position_offset_fuel.x		= 0.0f;
		m_position_offset_fuel.y		= 0.0f;
		p_status_bar_energy				= NULL;
		p_status_bar_fuel				= NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CPhysicalInfo::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca nazwê obiektu
	const std::string &CPhysicalInfo::GetPhysicalInfoName() const
	{
		return m_physical_info_name;
	}

	//Metoda ustawia nazwê obiektu
	void CPhysicalInfo::SetPhysicalInfoName(const std::string & physical_info_name)
	{
		m_physical_info_name = physical_info_name;
	}

	//Metoda ustawia indeks warstwy renderingu obiektu
	void CPhysicalInfo::SetZIndexRectangle(int z_index_rectangle)
	{
		m_z_index_rectangle = z_index_rectangle;
	}

	//Metoda zwraca flagê, czy obiekt posiada progress bar (energia-¿ycie)
	const bool CPhysicalInfo::getUseStatusBarEnergy() const
	{
		return m_use_status_bar_energy;
	}

	//Metoda ustawia flagê, czy obiekt posiada progress bar (energia-¿ycie)
	void CPhysicalInfo::setUseStatusBarEnergy(bool use_status_bar_energy)
	{
		m_use_status_bar_energy = use_status_bar_energy;
	}

	//Metoda zwraca flagê, czy obiekt posiada progress bar (paliwo/tlen)
	const bool CPhysicalInfo::getUseStatusBarFuel() const
	{
		return m_use_status_bar_fuel;
	}

	//Metoda ustawia flagê, czy obiekt posiada progress bar (paliwo/tlen)
	void CPhysicalInfo::setUseStatusBarFuel(bool use_status_bar_fuel)
	{
		m_use_status_bar_fuel = use_status_bar_fuel;
	}

	//Metoda zwraca kolor status progress bar (energia-¿ycie)
	const sf::Color& CPhysicalInfo::getFillColorEnergy() const
	{
		return m_color_bar_energy;
	}

	//Metoda ustawia kolor status progress bar (energia-¿ycie)
	void CPhysicalInfo::setFillColorEnergy(const sf::Color& color_bar_energy)
	{
		if (p_status_bar_energy)
		{
			m_color_bar_energy = color_bar_energy;
			p_status_bar_energy->getRectangleShape()->setFillColor(m_color_bar_energy);

		}
	}

	//Metoda zwraca kolor status progress bar (paliwo/tlen)
	const sf::Color& CPhysicalInfo::getFillColorFuel() const
	{
		return m_color_bar_fuel;
	}

	//Metoda ustawia kolor status progress bar (paliwo/tlen)
	void CPhysicalInfo::setFillColorFuel(const sf::Color& color_bar_fuel)
	{
		if (p_status_bar_fuel)
		{
			m_color_bar_fuel = color_bar_fuel;
			p_status_bar_fuel->getRectangleShape()->setFillColor(m_color_bar_fuel);

		}
	}

	//Metoda zwraca wektor pozycji paska - progress bar (energia-¿ycie)
	const sf::Vector2f& CPhysicalInfo::getPositionStatusBarEnergy() const
	{
		return m_position_status_bar_energy;
	}

	//Metoda zwraca wektor pozycji paska - progress bar (energia-¿ycie)
	void CPhysicalInfo::setPositionStatusBarEnergy(const sf::Vector2f & position_status_bar_energy)
	{
		if(p_status_bar_energy)
		{
			m_position_status_bar_energy = position_status_bar_energy;
			p_status_bar_energy->getRectangleShape()->setPosition(m_position_status_bar_energy);
		}
	}

	//Metoda zwraca wektor pozycji paska - progress bar (energia-¿ycie)
	void CPhysicalInfo::setPositionStatusBarEnergy(float position_status_bar_energy_x, float position_status_bar_energy_y)
	{
		if(p_status_bar_energy)
		{
			m_position_status_bar_energy.x = position_status_bar_energy_x;
			m_position_status_bar_energy.y = position_status_bar_energy_y;
			p_status_bar_energy->getRectangleShape()->setPosition(m_position_status_bar_energy.x, m_position_status_bar_energy.y);
		}
	}

	//Metoda zwraca wektor pozycji paska - progress bar (paliwo/tlen)
	const sf::Vector2f& CPhysicalInfo::getPositionStatusBarFuel() const
	{
		return m_position_status_bar_fuel;
	}

	//Metoda zwraca wektor pozycji paska - progress bar (paliwo/tlen)
	void CPhysicalInfo::setPositionStatusBarFuel(const sf::Vector2f & position_status_bar_fuel)
	{
		if(p_status_bar_fuel)
		{
			m_position_status_bar_fuel = position_status_bar_fuel;
			p_status_bar_fuel->getRectangleShape()->setPosition(m_position_status_bar_fuel);
		}
	}

	//Metoda zwraca wektor pozycji paska - progress bar (paliwo/tlen)
	void CPhysicalInfo::setPositionStatusBarFuel(float position_status_bar_fuel_x, float position_status_bar_fuel_y)
	{
		if(p_status_bar_fuel)
		{
			m_position_status_bar_fuel.x = position_status_bar_fuel_x;
			m_position_status_bar_fuel.y = position_status_bar_fuel_y;
			p_status_bar_fuel->getRectangleShape()->setPosition(m_position_status_bar_fuel.x, m_position_status_bar_fuel.y);
		}
	}

	//Metoda zwraca rozmiar obiektu - rozmiar paska - progress bar (energia-¿ycie)
	const sf::Vector2f & CPhysicalInfo::GetEnergyStatusBarSize() const
	{
		return m_size_energy;
	}

	//Metoda ustawia rozmiar obiektu - rozmiar paska - progress bar (energia-¿ycie)
	void CPhysicalInfo::SetEnergyStatusBarSize(const sf::Vector2f& size_energy)
	{
		if (p_status_bar_energy)
		{
			m_size_energy = size_energy;
			p_status_bar_energy->getRectangleShape()->setSize(m_size_energy);
		}
	}

	//Metoda ustawia rozmiar obiektu - rozmiar paska - progress bar (energia-¿ycie)
	void CPhysicalInfo::SetEnergyStatusBarSize(float size_energy_x, float size_energy_y)
	{
		m_size_energy.x = size_energy_x;
		m_size_energy.y = size_energy_y;
	}

	//Metoda zwraca rozmiar obiektu - rozmiar paska - progress bar (paliwo/tlen)
	const sf::Vector2f & CPhysicalInfo::GetFuelStatusBarSize() const
	{
		return m_size_fuel;
	}

	//Metoda ustawia rozmiar obiektu - rozmiar paska - progress bar (paliwo/tlen)
	void CPhysicalInfo::SetFuelStatusBarSize(const sf::Vector2f& size_fuel)
	{
		if (p_status_bar_fuel)
		{
			m_size_fuel = size_fuel;
			p_status_bar_fuel->getRectangleShape()->setSize(m_size_fuel);
		}
	}

	//Metoda ustawia rozmiar obiektu - rozmiar paska - progress bar (paliwo/tlen)
	void CPhysicalInfo::SetFuelStatusBarSize(float size_fuel_x, float size_fuel_y)
	{
		m_size_fuel.x = size_fuel_x;
		m_size_fuel.y = size_fuel_y;
	}

	//Metoda zwraca wektor przesuniêcia pozycji obiektu wzglêdem w³aœciciela - (energia-¿ycie)
	const sf::Vector2f & CPhysicalInfo::GetEnergyPositionStatusBarOffset() const
	{
		return m_position_offset_energy;
	}

	//Metoda ustawia wektor przesuniêcia pozycji obiektu wzglêdem w³aœciciela - (energia-¿ycie)
	void CPhysicalInfo::SetEnergyPositionStatusBarOffset(const sf::Vector2f& position_offset_energy)
	{
		m_position_offset_energy = position_offset_energy;
	}

	//Metoda ustawia wektor przesuniêcia pozycji obiektu wzglêdem w³aœciciela - (energia-¿ycie)
	void CPhysicalInfo::SetEnergyPositionStatusBarOffset(float position_offset_energy_x, float position_offset_energy_y)
	{
		m_position_offset_energy.x = position_offset_energy_x;
		m_position_offset_energy.y = position_offset_energy_y;
	}

	//Metoda zwraca wektor przesuniêcia pozycji obiektu wzglêdem w³aœciciela - (paliwo/tlen)
	const sf::Vector2f & CPhysicalInfo::GetFuelPositionStatusBarOffset() const
	{
		return m_position_offset_fuel;
	}

	//Metoda ustawia wektor przesuniêcia pozycji obiektu wzglêdem w³aœciciela - (paliwo/tlen)
	void CPhysicalInfo::SetFuelPositionStatusBarOffset(const sf::Vector2f& position_offset_fuel)
	{
		m_position_offset_fuel = position_offset_fuel;
	}

	//Metoda ustawia wektor przesuniêcia pozycji obiektu wzglêdem w³aœciciela - (paliwo/tlen)
	void CPhysicalInfo::SetFuelPositionStatusBarOffset(float position_offset_fuel_x, float position_offset_fuel_y)
	{
		m_position_offset_fuel.x = position_offset_fuel_x;
		m_position_offset_fuel.y = position_offset_fuel_y;
	}

	//Wirtualna metoda aktualizuj¹ca obiekt
	void CPhysicalInfo::Update(float dt)
	{
		if(p_status_bar_energy)
			setPositionStatusBarEnergy(GetPosition().x - m_position_offset_energy.x, GetPosition().y - m_position_offset_energy.y);

		if(p_status_bar_fuel)
			setPositionStatusBarFuel(GetPosition().x - m_position_offset_fuel.x, GetPosition().y - m_position_offset_fuel.y);
	}

	//Metoda sprawdza, czy trzeba utworzyæ obiekt klasy CRectangle (energia-¿ycie)
	void CPhysicalInfo::InitStatusBarEnergy()
	{
		if ((m_use_status_bar_energy) && (!p_status_bar_energy))
		{
			p_status_bar_energy = gDrawableManager.CreateRectangle(GetZIndexRectangle());
			if (!p_status_bar_energy)
			{
				fprintf(stderr, "error: CPhysicalInfo::InitStatusBarEnergy, p_status_bar_energy null, returning\n");
				return;
			}
		}
	}

	//Metoda sprawdza, czy trzeba utworzyæ obiekt klasy CRectangle (paliwo/tlen)
	void CPhysicalInfo::InitStatusBarFuel()
	{
		if ((m_use_status_bar_fuel) && (!p_status_bar_fuel))
		{
			p_status_bar_fuel = gDrawableManager.CreateRectangle(GetZIndexRectangle());
			if (!p_status_bar_fuel)
			{
				fprintf(stderr, "error: CPhysicalInfo::InitStatusBarFuel, p_status_bar_fuel null, returning\n");
				return;
			}
		}
	}

}//namespace logic