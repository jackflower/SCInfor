//  ___________________________________________
// | CEquipmentData.cpp - class implementation |
// | Jack Flower - May 2016                    |
// |___________________________________________|
//

#include "CEquipmentData.h"

namespace equipmentdata
{
	RTTI_IMPL_NOPARENT(CEquipmentData);

	//Konstruktor
	CEquipmentData::CEquipmentData()
	:
		m_use_equipment		(false),
		m_transformation	()
	{
	}

	//Konstruktor kopiujacy
	CEquipmentData::CEquipmentData(const CEquipmentData & CEquipmentDataCopy)
	:
		m_use_equipment		(CEquipmentDataCopy.m_use_equipment),
		m_transformation	(CEquipmentDataCopy.m_transformation)
	{
	}

	//Destruktor wirtualny
	CEquipmentData::~CEquipmentData()
	{
		m_use_equipment		= false;
		//m_transformation	not edit
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CEquipmentData::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca flagê, czy obiekt posiada wyposa¿enie
	const bool CEquipmentData::getUseEquipment() const
	{
		return m_use_equipment;
	}

	//Metoda ustawia flagê, czy obiekt posiada wyposa¿enie
	void CEquipmentData::setUseEquipment(bool use_equipment)
	{
		m_use_equipment = use_equipment;
	}

	//Metoda zwraca referencjê na opakowanie danych dla transformacji
	CTransformation & CEquipmentData::getTransformed()
	{
		return m_transformation;
	}

	//Metoda ustawia referencjê na opakowanie danych dla transformacji
	void CEquipmentData::setTransformed(CTransformation & transformation)
	{
		m_transformation = transformation;
	}

	//Metoda zwraca referencjê na wektora po³o¿enia emitera
	const sf::Vector2f & CEquipmentData::getEmiter() const
	{
		return m_transformation.getEmiter();
	}

	//Metoda ustawia wektor po³o¿enia emitera
	void CEquipmentData::setEmiter(sf::Vector2f & emiter)
	{
		m_transformation.setEmiter(emiter);
	}

	//Metoda ustawia wektor po³o¿enia emitera
	void CEquipmentData::setEmiter(float emiter_x, float emiter_y)
	{
		m_transformation.setEmiter(emiter_x, emiter_y);
	}

	//Metoda dokonuje transformacji skali, pozycji, obrotu
	void CEquipmentData::Transform(CActor * p_parent, CActor * p_child)
	{
		m_transformation.Transform(p_parent, p_child);
	}
}//namespace equipmentdata