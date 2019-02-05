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
	///Klasa reprezentuje funkcjonalnoúÊ obiektu bÍdπcego wyposaøaniem - modu≥ komunikacyjny
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
		///Konstruktor kopiujπcy
		///
		///@param & CEquipmentCommunicationDataCopy - sta≥a referencja na obiekt klasy CEquipmentCommunicationData
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
		///Metoda zwraca wskaünik na obiekt klasy CCommunication
		///
		CCommunication* getCommunication();

		///
		///Metoda ustawia wskaünik na obiekt klasy CCommunication
		///
		///@param *communication - wskaünik na obiekt klasy CCommunication
		///
		void setCommunication(CCommunication* communication);

	private:

		CCommunication*	p_communication;	//wskaünik na klasÍ CCommunication - modu≥ komunikacyjny
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_COMMUNICATION_DATA_JACK

