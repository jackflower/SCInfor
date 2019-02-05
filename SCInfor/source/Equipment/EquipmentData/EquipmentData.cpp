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

	//Metoda zwraca flagê, czy obiekt posiada wyposa¿enie
	const bool EquipmentData::getUseEquipment() const
	{
		return m_use_equipment;
	}

	//Metoda ustawia flagê, czy obiekt posiada wyposa¿enie
	void EquipmentData::setUseEquipment(bool use_equipment)
	{
		m_use_equipment = use_equipment;
	}

	//Metoda zwraca referencjê na opakowanie danych dla transformacji
	CTransformation & EquipmentData::getTransformed()
	{
		return m_transformation;
	}

	//Metoda ustawia referencjê na opakowanie danych dla transformacji
	void EquipmentData::setTransformed(CTransformation & transformation)
	{
		m_transformation = transformation;
	}

	//Metoda zwraca referencjê na wektora po³o¿enia emitera
	const sf::Vector2f & EquipmentData::getEmiter() const
	{
		return m_transformation.getEmiter();
	}

	//Metoda ustawia wektor po³o¿enia emitera
	void EquipmentData::setEmiter(sf::Vector2f & emiter)
	{
		m_transformation.setEmiter(emiter);
	}

	//Metoda ustawia wektor po³o¿enia emitera
	void EquipmentData::setEmiter(float emiter_x, float emiter_y)
	{
		m_transformation.setEmiter(emiter_x, emiter_y);
	}

	//Metoda dokonuje transformacji skali, pozycji, obrotu
	void EquipmentData::Transform(CActor * p_parent, CActor * p_child)
	{
		m_transformation.Transform(p_parent, p_child);
	}
}//namespace equipmentdata
