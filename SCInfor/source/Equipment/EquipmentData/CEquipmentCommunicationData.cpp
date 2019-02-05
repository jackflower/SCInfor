//  ________________________________________________________
// | CEquipmentCommunicationData.cpp - class implementation |
// | Jack Flower - May 2016                                 |
// |________________________________________________________|
//

#include "CEquipmentCommunicationData.h"
#include "../../Logic/Communication/CCommunication.h"
#include "../../Logic/CPhysicalManager.h"

namespace equipmentdata
{
	RTTI_IMPL(CEquipmentCommunicationData, EquipmentData);

	//Konstruktor
	CEquipmentCommunicationData::CEquipmentCommunicationData()
	:
		EquipmentData	(),//konstruktor klasy bazowej
		p_communication	(NULL)
	{
	}

	//Konstruktor kopiujπcy
	CEquipmentCommunicationData::CEquipmentCommunicationData(const CEquipmentCommunicationData & CEquipmentCommunicationDataCopy)
		:
		EquipmentData	(CEquipmentCommunicationDataCopy),//konstruktor kopiujπcy klasy bazowej
		p_communication	(CEquipmentCommunicationDataCopy.p_communication)
	{
	}

	//Destruktor wirtualny
	CEquipmentCommunicationData::~CEquipmentCommunicationData()
	{
		//EquipmentData	not edit
		if (p_communication)
			gPhysicalManager.DestroyPhysical(p_communication);
		p_communication = NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CEquipmentCommunicationData::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca wskaünik na obiekt klasy CCommunication
	CCommunication* CEquipmentCommunicationData::getCommunication()
	{
		return p_communication;
	}

	//Metoda ustawia wskaünik na obiekt klasy CCommunication
	void CEquipmentCommunicationData::setCommunication(CCommunication* communication)
	{
		p_communication = communication;
	}
}//namespace equipmentdata
