//  _______________________________________________________
// | EquipmentCommunicationData.h - class definition       |
// | Jack Flower - May 2016                                |
// |_______________________________________________________|
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
		class Communication;
	}
}

using namespace logic::communication;

namespace equipmentdata
{
	///
	///Klasa reprezentuje funkcjonalność obiektu będącego wyposażaniem - moduł komunikacyjny
	///
	class EquipmentCommunicationData : public EquipmentData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		EquipmentCommunicationData();

		///
		///Konstruktor kopiujący
		///
		///@param EquipmentCommunicationDataCopy - stała referencja na obiekt klasy EquipmentCommunicationData
		///
		EquipmentCommunicationData(const EquipmentCommunicationData & EquipmentCommunicationDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~EquipmentCommunicationData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca wskaźnik na obiekt klasy Communication
		///
		Communication *getCommunication();

		///
		///Metoda ustawia wskaźnik na obiekt klasy Communication
		///
		///@param *communication - wskaźnik na obiekt klasy Communication
		///
		void setCommunication(Communication *communication);

	private:

		Communication *p_communication; //wskaźnik na klasę Communication - moduł komunikacyjny
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_COMMUNICATION_DATA_JACK

