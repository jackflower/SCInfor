//  __________________________________________
// | EquipmentData.cpp - class implementation |
// | Jack Flower - May 2016                   |
// |__________________________________________|
//

#include "EquipmentData.h"

namespace equipmentdata
{
	RTTI_IMPL_NOPARENT(EquipmentData);

	//Konstruktor
	EquipmentData::EquipmentData()
	:
		m_use_equipment(false),
		m_transformation()
	{
	}

	//Konstruktor kopiujacy
	EquipmentData::EquipmentData(const EquipmentData & EquipmentDataCopy)
	:
		m_use_equipment(EquipmentDataCopy.m_use_equipment),
		m_transformation(EquipmentDataCopy.m_transformation)
	{
	}

	//Destruktor wirtualny
	EquipmentData::~EquipmentData()
	{
		m_use_equipment = false;
		//m_transformation
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string EquipmentData::getType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca flagę, czy obiekt posiada wyposażenie
	const bool EquipmentData::getUseEquipment() const
	{
		return m_use_equipment;
	}

	//Metoda ustawia flagę, czy obiekt posiada wyposażenie
	void EquipmentData::setUseEquipment(bool use_equipment)
	{
		m_use_equipment = use_equipment;
	}

	//Metoda zwraca referencję na opakowanie danych dla transformacji
	CTransformation & EquipmentData::getTransformed()
	{
		return m_transformation;
	}

	//Metoda ustawia referencję na opakowanie danych dla transformacji
	void EquipmentData::setTransformed(CTransformation & transformation)
	{
		m_transformation = transformation;
	}

	//Metoda zwraca referencję na wektora położenia emitera
	const sf::Vector2f & EquipmentData::getEmiter() const
	{
		return m_transformation.getEmiter();
	}

	//Metoda ustawia wektor położenia emitera
	void EquipmentData::setEmiter(sf::Vector2f & emiter)
	{
		m_transformation.setEmiter(emiter);
	}

	//Metoda ustawia wektor położenia emitera
	void EquipmentData::setEmiter(float emiter_x, float emiter_y)
	{
		m_transformation.setEmiter(emiter_x, emiter_y);
	}

	//Metoda dokonuje transformacji skali, pozycji, obrotu
	void EquipmentData::Transform(Actor * p_parent, Actor * p_child)
	{
		m_transformation.Transform(p_parent, p_child);
	}
}//namespace equipmentdata
