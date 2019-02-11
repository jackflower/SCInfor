//  _____________________________________________
// | PhysicalTemplate.h - class definition       |
// | Jack Flower - November 2012                 |
// |_____________________________________________|
//

#ifndef H_PHYSICAL_TEMPLATE_JACK
#define H_PHYSICAL_TEMPLATE_JACK

#include "../ResourceManager/IResource.h"
#include "../Logic/Physical/CPhysical.h"
#include "../Logic/CPhysicalManager.h"
#include "../XML/CXml.h"
#include "../RTTI/RTTI.h"


using namespace resource;
using namespace xml;
using namespace rapidxml;
using namespace logic;

namespace factory
{
	///
	///Klasa reprezentuje prawzorzec wszystkich wzorców
	///
	class PhysicalTemplate : public IResource
	{
		RTTI_DECL;

	public:
		
		///
		///Konstruktor
		///
		PhysicalTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~PhysicalTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Wirtualna metoda zwalniająca zasób (ponowienie)
		///
		virtual void drop() = 0;

		///
		///Metoda ładująca dane
		///
		///@param name - stała referencja na std::string
		///
		bool load(const std::string & name);

		///
		///Wirtualna metoda ładująca dane z xml wywoływana przez implementacje klas potomnych
		///
		///@param xml - referencja na obiekt klasy CXml
		///
		virtual bool load(CXml & xml);

		///
		///Wirtualna metoda tworzenie obiektów pochodnych klasy CPhysical
		///
		///implementowana przez w pełni konkretne podklasy
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		virtual CPhysical *create(std::wstring id = L"") = 0 ;

		///
		///Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
		///
		///@param *physical - wskaźnik na obiekt klasy CPhysical
		///
		virtual void fill(CPhysical *physical);

		///
		///Metoda zwraca nazwę pliku zasobu
		///
		inline const std::string & getFilename() const { return m_templ_filename; }

		//metody pomocnicze - get
		inline std::wstring getGenre() { return m_templ_genre; }
		inline float getCircleRadius() { return m_templ_circle_radius; }
		inline sf::Vector2f & getRectangleSize() { return m_templ_rect_size; }
		inline sf::Vector2f & getRectangleSizeBody() { return m_templ_rect_size_body; }
		inline sf::Vector2f & getRectangleSizeHead() { return m_templ_rect_size_head; }
		inline std::string	& getTextureNameBody() { return m_templ_texture_body; }
		inline std::string	& getTextureNameHead() { return m_templ_texture_head; }
		inline float getAltitude() { return m_templ_altitude; }
		inline bool getUseDisplayableBody() { return m_templ_use_displayable_body; }
		inline bool getUseShadowBody() { return m_templ_use_shadow_body; }
		inline bool getUseDisplayableHead() { return m_templ_use_displayable_head; }
		inline bool getUseShadowHead() { return m_templ_use_shadow_head; }
		inline sf::Color & getColorBody() { return m_templ_color_body; }
		inline sf::Color & getColorHead() { return m_templ_color_head; }
		inline float getScaleBody() { return m_templ_scale_body; }
		inline float getScaleHead() { return m_templ_scale_head; }

	protected:

		std::string m_templ_filename; //nazwa pliku xml
		std::string m_templ_type; //typ obiektu odczytanego z xml'a, na podstawie którego CResourceManager tworzy zasób
		std::wstring m_templ_genre; //nazwa "gatunku" obiektu (np. robot, human, gun, etc.)
		float m_templ_circle_radius; //promień detekcji kolizji
		sf::Vector2f m_templ_rect_size; //wektor przechowujący rozmiar obszaru prostokątnego
		sf::Vector2f m_templ_rect_size_body; //wektor przechowujący rozmiar obszaru prostokątnego - body
		sf::Vector2f m_templ_rect_size_head; //wektor przechowujący rozmiar obszaru prostokątnego - head
		std::string m_templ_texture_body; //nazwa tekstury reprezentacji graficznej obiektu - body
		std::string m_templ_texture_head; //nazwa tekstury reprezentacji graficznej obiektu - head
		float m_templ_altitude; //wartość pułapu obiektu względem podłoża
		bool m_templ_use_displayable_body; //flaga określa, czy CPhysical posiada reprezentację graficzną - body
		bool m_templ_use_shadow_body; //flaga określa, czy CPhysical posiada reprezentację graficzną - body - cień
		bool m_templ_use_displayable_head; //flaga określa, czy CPhysical posiada reprezentację graficzną - head
		bool m_templ_use_shadow_head; //flaga określa, czy CPhysical posiada reprezentację graficzną - head - cień
		sf::Color m_templ_color_body; //kolor - body
		sf::Color m_templ_color_head; //kolor - head
		float m_templ_scale_body; //skala - body
		float m_templ_scale_head; //skala - head
		PartCollisionData m_templ_part_collision_data; //opakowanie informacji o kolidowaniu

	private:

	};
}//namespace factory
#endif //H_PHYSICAL_TEMPLATE_JACK
