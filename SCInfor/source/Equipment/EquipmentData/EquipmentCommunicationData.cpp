//  _______________________________________________________
// | EquipmentCommunicationData.cpp - class implementation |
// | Jack Flower - May 2016                                |
// |_______________________________________________________|
//

#include "EquipmentCommunicationData.h"
#include "../../Logic/Communication/Communication.h"
#include "../../Logic/PhysicalManager.h"

namespace equipmentdata
{
	RTTI_IMPL(EquipmentCommunicationData, EquipmentData);

	//Konstruktor
	EquipmentCommunicationData::EquipmentCommunicationData()
	:
		EquipmentData(),//konstruktor klasy bazowej
		p_communication(NULL)
	{
	}

	//Konstruktor kopiujący
	EquipmentCommunicationData::EquipmentCommunicationData(const EquipmentCommunicationData & EquipmentCommunicationDataCopy)
		:
		EquipmentData(EquipmentCommunicationDataCopy),//konstruktor kopiujący klasy bazowej
		p_communication(EquipmentCommunicationDataCopy.p_communication)
	{
	}

	//Destruktor wirtualny
	EquipmentCommunicationData::~EquipmentCommunicationData()
	{
		//EquipmentData	not edit
		if (p_communication)
			gPhysicalManager.destroyPhysical(p_communication);
		p_communication = NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string EquipmentCommunicationData::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca wskaźnik na obiekt klasy Communication
	Communication* EquipmentCommunicationData::getCommunication()
	{
		return p_communication;
	}

	//Metoda ustawia wskaźnik na obiekt klasy Communication
	void EquipmentCommunicationData::setCommunication(Communication* communication)
	{
		p_communication = communication;
	}
}//namespace equipmentdata
