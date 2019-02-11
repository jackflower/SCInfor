//  ____________________________________
// | FuelBar.cpp - class implementation |
// | Jack Flower March 2014             |
// |____________________________________|
//

#include "FuelBar.h"

namespace equipment
{

	RTTI_IMPL(FuelBar, Physical);


	//Konstruktor
	FuelBar::FuelBar(const std::wstring & uniqueId)
	:
		Physical(uniqueId),//konstruktor klasy bazowej
		m_fuelbar_name(),
		m_thickness(0.0f),
		m_size(0.0f, 0.0f),
		m_position_offset(0.0f, 0.0f)
	{
	}

	//Konstruktor kopiujący
	FuelBar::FuelBar(const FuelBar & FuelBarCopy)
	:
		Physical(FuelBarCopy),//konstruktor kopiujący klasy bazowej
		m_fuelbar_name(FuelBarCopy.m_fuelbar_name),
		m_thickness(FuelBarCopy.m_thickness),
		m_size(FuelBarCopy.m_size),
		m_position_offset(FuelBarCopy.m_position_offset)
	{
	}

	//Destruktor
	FuelBar::~FuelBar(void)
	{
		//Physical
		m_fuelbar_name = "";
		m_thickness = 0.0f;
		m_size.x = 0.0f;
		m_size.y = 0.0f;
		m_position_offset.x	= 0.0f;
		m_position_offset.y	= 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string FuelBar::getType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca nazwę obiektu
	const std::string & FuelBar::getFuelBarName() const
	{
		return m_fuelbar_name;
	}

	//Metoda ustawia nazwę obiektu
	void FuelBar::setFuelBarName(const std::string & fuelbar_name)
	{
		m_fuelbar_name = fuelbar_name;
	}

	//Metoda zwraca grubość paska
	const float FuelBar::getThickness() const
	{
		return m_thickness;
	}

	//Metoda ustawia grubość paska
	const void FuelBar::setThickness(float thickness)
	{
		m_thickness = thickness;
	}

	//Metoda zwraca rozmiar obiektu
	const sf::Vector2f & FuelBar::getBarSize() const
	{
		return m_size;
	}

	//Metoda ustawia rozmiar obiektu
	void FuelBar::setBarSize(const sf::Vector2f & size)
	{
		m_size = size;
	}

	//Metoda ustawia rozmiar obiektu
	void FuelBar::setBarSize(float size_x, float size_y)
	{
		m_size.x = size_x;
		m_size.y = size_y;
	}

	//Metoda zwraca wektor kalibracji pozycji obiektu
	const sf::Vector2f & FuelBar::getBarPositionOffset() const
	{
		return m_position_offset;
	}

	//Metoda ustawia wektor kalibracji pozycji obiektu
	void FuelBar::setBarPositionOffset(const sf::Vector2f& position_offset)
	{
		m_position_offset = position_offset;
	}

	//Metoda ustawia wektor kalibracji pozycji obiektu
	void FuelBar::setBarPositionOffset(float position_offset_x, float position_offset_y)
	{
		m_position_offset.x = position_offset_x;
		m_position_offset.y = position_offset_y;
	}

	//Wirtualna metoda aktualizuje logikę obiektu
	void FuelBar::update(float dt)
	{
		//to do...
	}

	//Wirtualna metoda aktualizuje logikę obiektu
	//void Engine::update(float dt)
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
