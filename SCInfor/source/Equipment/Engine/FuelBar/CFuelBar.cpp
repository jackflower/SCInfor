//  _____________________________________
// | CFuelBar.cpp - class implementation |
// | Jack Flower March 2014              |
// |_____________________________________|
//

#include "CFuelBar.h"

namespace equipment
{

	RTTI_IMPL(CFuelBar, CPhysical);


	//Konstruktor
	CFuelBar::CFuelBar(const std::wstring& uniqueId)
	:
		CPhysical			(uniqueId),//konstruktor klasy bazowej
		m_fuelbar_name		(),
		m_thickness			(0.0f),
		m_size				(0.0f, 0.0f),
		m_position_offset	(0.0f, 0.0f)
	{
	}

	//Konstruktor kopiujący
	CFuelBar::CFuelBar(const CFuelBar& CFuelBarCopy)
	:
		CPhysical			(CFuelBarCopy),//konstruktor kopiujący klasy bazowej
		m_fuelbar_name		(CFuelBarCopy.m_fuelbar_name),
		m_thickness			(CFuelBarCopy.m_thickness),
		m_size				(CFuelBarCopy.m_size),
		m_position_offset	(CFuelBarCopy.m_position_offset)
	{
	}

	//Destruktor
	CFuelBar::~CFuelBar(void)
	{
		//CPhysical			not edit
		m_fuelbar_name		= "";
		m_thickness			= 0.0f;
		m_size.x			= 0.0f;
		m_size.y			= 0.0f;
		m_position_offset.x	= 0.0f;
		m_position_offset.y	= 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CFuelBar::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca nazwę obiektu
	const std::string & CFuelBar::GetFuelBarName() const
	{
		return m_fuelbar_name;
	}

	//Metoda ustawia nazwę obiektu
	void CFuelBar::SetFuelBarName(const std::string & fuelbar_name)
	{
		m_fuelbar_name = fuelbar_name;
	}

	//Metoda zwraca grubość paska
	const float CFuelBar::GetThickness() const
	{
		return m_thickness;
	}

	//Metoda ustawia grubość paska
	const void CFuelBar::SetThickness(float thickness)
	{
		m_thickness = thickness;
	}

	//Metoda zwraca rozmiar obiektu
	const sf::Vector2f & CFuelBar::GetBarSize() const
	{
		return m_size;
	}

	//Metoda ustawia rozmiar obiektu
	void CFuelBar::SetBarSize(const sf::Vector2f& size)
	{
		m_size = size;
	}

	//Metoda ustawia rozmiar obiektu
	void CFuelBar::SetBarSize(float size_x, float size_y)
	{
		m_size.x = size_x;
		m_size.y = size_y;
	}

	//Metoda zwraca wektor kalibracji pozycji obiektu
	const sf::Vector2f & CFuelBar::GetBarPositionOffset() const
	{
		return m_position_offset;
	}

	//Metoda ustawia wektor kalibracji pozycji obiektu
	void CFuelBar::SetBarPositionOffset(const sf::Vector2f& position_offset)
	{
		m_position_offset = position_offset;
	}

	//Metoda ustawia wektor kalibracji pozycji obiektu
	void CFuelBar::SetBarPositionOffset(float position_offset_x, float position_offset_y)
	{
		m_position_offset.x = position_offset_x;
		m_position_offset.y = position_offset_y;
	}

	//Wirtualna metoda aktualizuje logikę obiektu
	void CFuelBar::update(float dt)
	{
		//to do...
		//this->ok..ok..ok...
		//this->
	}

	//Wirtualna metoda aktualizuje logikę obiektu
	//void CEngine::update(float dt)
	//{
	//	//odmiarzam czas
	//	m_timer += dt;
	//	
	//	//aktualizacja stanu paliwa ma miejsce jeśli jest paliwo
	//	if(GetFuel())
	//	{
	//		if (m_timer >= CEquipment::m_regeneration_time)		//jeśli upłynął jakiś czas
	//		{
	//			SetFuel(GetFuel() - m_fuel_consumption);		//zużywamy paliwo
	//			m_timer = 0.0f;									//zerujemy czas
	//		}
	//	}
		
	//	//warunki prezentacji engine-fuel - rezerwa paliwa lub jej brak
	//	if(GetFuel() < GetFuelTankCapacity()* m_percentage_reserve_fuel)
	//	{
	//		if(p_displayable)
	//			p_displayable->SetCanDraw(true);				//ikona widoczna
	//	}
	//	else
	//	{
	//		if(p_displayable)
	//			p_displayable->SetCanDraw(false);				//ikona niewidoczna
	//	}

	//	//aktualizacja pozycji engine(fuel) - ikona
	//	if(p_displayable)
	//	{
	//		if(p_actor)
	//		{
	//			p_displayable->SetScale(p_actor->GetDisplayable()->GetScale());	//przeskalowanie
	//			p_displayable->SetPosition
	//			(
	//				p_actor->GetPosition().x - p_actor->GetDisplayable()->GetSprite()->GetSize().x
	//				* 0.5f + CEquipment::m_vector_offset.x * p_actor->GetDisplayable()->GetScale().x,
	//				p_actor->GetPosition().y - p_actor->GetDisplayable()->GetSprite()->GetSize().y
	//				* 0.5f - CEquipment::m_vector_offset.y * p_actor->GetDisplayable()->GetScale().y
	//			);
	//		}
	//	}

	//}

}//namespace equipment
