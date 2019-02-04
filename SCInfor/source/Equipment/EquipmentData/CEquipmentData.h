//  ___________________________________________
// | CEquipmentData.h - class definition       |
// | Jack Flower - May 2016                    |
// |___________________________________________|
//


#ifndef H_EQUIPMENT_DATA_JACK
#define H_EQUIPMENT_DATA_JACK

#include "../../Utilities/Transformation/CTransformation.h"
#include "../../RTTI/RTTI.h"

using namespace transformation;

namespace equipmentdata
{
	///
	///Klasa bazowa reprezentuje funkcjonalnoœæ obiektu bêd¹cego wyposa¿aniem
	///
	class CEquipmentData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CEquipmentData();

		///
		///Konstruktor kopiujacy
		///
		///@param & CEquipmentDataCopy - sta³a referencja na obiekt klasy CEquipmentData
		///
		CEquipmentData(const CEquipmentData & CEquipmentDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~CEquipmentData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca flagê, czy obiekt posiada wyposa¿enie
		///
		const bool getUseEquipment() const;

		///
		///Metoda ustawia flagê, czy obiekt posiada wyposa¿enie
		///
		///@param use_equipment - flaga, czy obiekt posiada wyposa¿enie
		///
		void setUseEquipment(bool use_equipment);

		///
		///Metoda zwraca referencjê na opakowanie danych dla transformacji
		///
		CTransformation & getTransformed();

		///
		///Metoda ustawia referencjê na opakowanie danych dla transformacji
		///
		///@param & transformation - referencja na obiekt klasy CTransformation
		///
		void setTransformed(CTransformation & transformation);

		///
		///Metoda zwraca referencjê na wektora po³o¿enia emitera
		///
		const sf::Vector2f & getEmiter() const;

		///
		///Metoda ustawia wektor po³o¿enia emitera
		///
		///@param emiter - referencja na wektor emitera
		///
		void setEmiter(sf::Vector2f & emiter);

		///
		///Metoda ustawia wektor po³o¿enia emitera
		///
		///@param emiter_x - wspó³rzedna X
		///
		///@param emiter_y - wspó³rzedna Y
		///
		void setEmiter(float emiter_x, float emiter_y);

		///
		///Metoda dokonuje transformacji skali, pozycji, obrotu
		///
		///@param * p_parent - wskaŸnik na obiekt klasy CActor
		///
		////@param * p_child - wskaŸnik na obiekt klasy CActor
		///
		void Transform(CActor * p_parent, CActor * p_child);

	protected:

		bool			m_use_equipment;	//flaga, czy obiekt u¿ywa wyposa¿enia
		CTransformation m_transformation;	//dane dla transformacji (pozycja, skala, obrót)

	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_DATA_JACK
