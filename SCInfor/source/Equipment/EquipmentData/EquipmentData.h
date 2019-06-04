//  __________________________________________
// | EquipmentData.h - class definition       |
// | Jack Flower - May 2016                   |
// |__________________________________________|
//


#ifndef H_EQUIPMENT_DATA_JACK
#define H_EQUIPMENT_DATA_JACK

#include "../../Utilities/Transformation/CTransformation.h"
#include "../../RTTI/RTTI.h"

using namespace transformation;

namespace equipmentdata
{
	///
	///Klasa bazowa reprezentuje funkcjonalność obiektu będącego wyposażaniem
	///
	class EquipmentData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		EquipmentData();

		///
		///Konstruktor kopiujący
		///
		///@param EquipmentDataCopy - stała referencja na obiekt klasy EquipmentData
		///
		EquipmentData(const EquipmentData & EquipmentDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~EquipmentData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca flagę, czy obiekt posiada wyposażenie
		///
		const bool getUseEquipment() const;

		///
		///Metoda ustawia flagę, czy obiekt posiada wyposażenie
		///
		///@param use_equipment - flaga, czy obiekt posiada wyposażenie
		///
		void setUseEquipment(bool use_equipment);

		///
		///Metoda zwraca referencję na opakowanie danych dla transformacji
		///
		CTransformation & getTransformed();

		///
		///Metoda ustawia referencję na opakowanie danych dla transformacji
		///
		///@param transformation - referencja na obiekt klasy CTransformation
		///
		void setTransformed(CTransformation & transformation);

		///
		///Metoda zwraca referencję na wektora położenia emitera
		///
		const sf::Vector2f & getEmiter() const;

		///
		///Metoda ustawia wektor położenia emitera
		///
		///@param emiter - referencja na wektor emitera
		///
		void setEmiter(sf::Vector2f & emiter);

		///
		///Metoda ustawia wektor położenia emitera
		///
		///@param emiter_x - współrzedna X
		///
		///@param emiter_y - współrzedna Y
		///
		void setEmiter(float emiter_x, float emiter_y);

		///
		///Metoda dokonuje transformacji skali, pozycji, obrotu
		///
		///@param * p_parent - wskaźnik na obiekt klasy Actor
		///
		////@param * p_child - wskaźnik na obiekt klasy Actor
		///
		void Transform(Actor * p_parent, Actor * p_child);

	protected:

		bool m_use_equipment; //flaga, czy obiekt używa wyposażenia
		CTransformation m_transformation; //dane dla transformacji (pozycja, skala, obrót)

	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_DATA_JACK
