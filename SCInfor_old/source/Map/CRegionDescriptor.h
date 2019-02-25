/*
 ______________________________________________
| CRegionDescriptor.h - definicja klasy.       |
| Jack Flower June 2013.                       |
|______________________________________________|

*/

#ifndef _H_REGION_DESCRIPTOR_JACK
#define _H_REGION_DESCRIPTOR_JACK

#include <string>
#include <ostream>
#include <SFML/System/Vector2.hpp>
#include "../XML/CXml.h"
#include "../RTTI/RTTI.h"

///
///Forward declaration
///
class CCondition;
class CRegion;
class CEffectHandle;

using namespace xml;

namespace mapengine
{
	///
	///Klasa reprezentuje opakowanie danych dla regionów umieszczonych na mapie (wczytywane z xml)
	///
    class CRegionDescriptor
	{
		RTTI_DECL;

    public:

		///
		///Konstruktor
		///
		///@param &region_name - sta³a referenacja na nazwê regionu
		///
		///@param position - sta³a pozycja obiektu na mapie inicjowana na liœcie konstruktora
		///
		///@param m_scale - skala obiektu
		///
        CRegionDescriptor(const std::string & region_name, const sf::Vector2f position, float m_scale = 1.f);
        
		///
		///Destruktor wirtualny
		///
		virtual ~CRegionDescriptor();

		///
		///Metoda tworzy wskaŸnik na obiekt klasy CRegion
		///
        CRegion *Create();
        
		///
		///Metoda ³aduje dane z pliku xml
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		///@param *node - wskaŸnik na wêze³ xml xml_node<>
		///
		void Load(CXml &xml, xml_node<> *node);
        
		///
		///Metoda serializuje obiekt
		///
		///@param &out - referencja do obiektu std::ostream
		///
		///@param indent - parametr wt³oczenia tekstu do pliku xml
		///
		void Serialize(std::ostream &out, int indent);
        
		///
		///Metoda zwraca std::string zserializowanego obiektu
		///
		const std::string Serialize();

		//metody pomocnicze
		inline const std::string GetRegionDescriptorName() const { return m_region_name; }
		inline void SetRegionDescriptorName(const std::string &region_name) { m_region_name = region_name; }

		inline const sf::Vector2f GetRegionDescriptorPosition() const { return m_region_descriptor_position; }
		
		inline CCondition* GetCondition() { return p_condition; }
		inline void SetCondition(CCondition *condition ) { p_condition = condition; }

		inline const std::string GetNextMap() const { return m_next_map; }
		inline void GetNextMap(const std::string &next_map) { m_next_map = m_next_map; }

		inline const std::string GetNextRegion() const { return m_next_map_region; }
		inline void SetNextRegion(const std::string &next_map_region) { m_next_map_region = next_map_region; }

		inline const float GetRotation() const { return m_rotation; }
		inline void SetRotation(float rotation) { m_rotation = rotation; }

		inline const float GetScale() const { return m_scale; }
		inline void SetScale(float scale) { m_scale = scale; }

		inline CEffectHandle* GetCEffectHandle() { return p_effect; }
		inline void GetCEffectHandle(CEffectHandle *effect ) { p_effect = effect; }

		inline const int GetUniqueId() const { return m_uniqueId; }

	private:

		std::string			m_region_name;					//nazwa - wczytywana z xml
		const sf::Vector2f	m_region_descriptor_position;	//sta³a wartoœæ po³o¿enia obiektu na mapie
		CCondition*			p_condition;					//wskaŸnik na klasê warunku na³o¿onego na region			
		std::string			m_next_map;						//nazwa nastêpnej mapy
		std::string			m_next_map_region;				//nazwa nastêpnego regionu
		float				m_rotation;						//obrót obiektu
		float				m_scale;						//skala obiektu
		CEffectHandle*		p_effect;						//wskaŸnik na klasê efektu podpiêtego pod region
		int					m_uniqueId;						//unikalny identyfikator obiektu
    };
} //namespace mapengine
#endif//_H_REGION_DESCRIPTOR_JACK
