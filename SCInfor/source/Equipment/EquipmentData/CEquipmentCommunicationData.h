//  ________________________________________________________
// | CEquipmentCommunicationData.h - class definition       |
// | Jack Flower - May 2016                                 |
// |________________________________________________________|
//

#ifndef H_EQUIPMENT_COMMUNICATION_DATA_JACK
#define H_EQUIPMENT_COMMUNICATION_DATA_JACK

#include "EquipmentData.h"

///
///Forward declaration
///
namespace logic
{
	namespace communication
	{
		class CCommunication;
	}
}

using namespace logic::communication;

namespace equipmentdata
{
	///
	///Klasa reprezentuje funkcjonalno�� obiektu b�d�cego wyposa�aniem - modu� komunikacyjny
	///
	class CEquipmentCommunicationData : public EquipmentData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CEquipmentCommunicationData();

		///
		///Konstruktor kopiuj�cy
		///
		///@param & CEquipmentCommunicationDataCopy - sta�a referencja na obiekt klasy CEquipmentCommunicationData
		///
		CEquipmentCommunicationData(const CEquipmentCommunicationData & CEquipmentCommunicationDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~CEquipmentCommunicationData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca wska�nik na obiekt klasy CCommunication
		///
		CCommunication* getCommunication();

		///
		///Metoda ustawia wska�nik na obiekt klasy CCommunication
		///
		///@param *communication - wska�nik na obiekt klasy CCommunication
		///
		void setCommunication(CCommunication* communication);

	private:

		CCommunication*	p_communication;	//wska�nik na klas� CCommunication - modu� komunikacyjny
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_COMMUNICATION_DATA_JACK

