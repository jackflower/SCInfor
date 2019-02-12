//  ______________________________________
// | Physical.h - class definition        |
// | Jack Flower - August 2012            |
// |______________________________________|
//

#ifndef H_PHYSICAL_JACK
#define H_PHYSICAL_JACK

#include "PhysicalCategories.h"
#include "ECollisionShape.h"
#include "EPhysicalPart.h"
#include "PhysicalData/PhysicalData.h"
#include "PartCollisionData/PartCollisionData.h"
#include "../../RTTI/RTTI.h"

///
///Forward declaration
///
namespace factory
{
	class PhysicalTemplate;
}

using namespace resource;
using namespace factory;
using namespace physicaldata;
using namespace collisiondata;

namespace logic
{
	///
	///Klasa reprezentuje behawioralne cechy fizyczne i logiczne
	///
	class Physical
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaźni
		///
		friend class PhysicalManager;

		//Aby uzyskać obiekt Physical, należy wywołać PhysicalManager::CreatePhysical();

		///
		///Chroniony konstruktor domyślny - używany wyłącznie przez PhysicalManager
		///
		///@param uniqueId - stała referencja na obiekt klasy std::wstring
		///
		Physical(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiujący
		///
		///@param PhysicalCopy - stała referencja na obiekt klasy Physical
		///
		Physical(const Physical & PhysicalCopy);

		///
		///Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
		///
		virtual ~Physical();

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca unikalną nazwę obiektu klasy Physical
		///
		const std::wstring & getUniqueId() const;

		///
		///Metoda zwraca nazwę gatunku
		///
		const std::wstring & getGenre();

		///
		///Metoda zwraca wagę
		///
		const float getWeight() const;

		///
		///Metoda ustawia wagę
		///
		///@param weight - waga
		///
		void setWeight(float weight);

		///
		///Metoda zwraca kategorię Physical
		///
		physCategory getCategory();

		///
		///Metoda ustawia kategorię Physical
		///
		///@param category - stała referencja na wyliczenie physCategory
		///
		void setCategory(const physCategory & category);

		///
		///Metoda ustawia kategorię Physical
		///
		///@param category_name - stała referencja na obiekt klasy std::wstring
		///
		void setCategory(const std::wstring & category_name);

		///
		///Metoda ustawia nazwę gatunku
		///
		///@param genre - stała referencja na obiekt klasy std::wstring
		///
		void setGenre(const std::wstring & genre);

		///
		///Metoda zwraca pozycję obiektu
		///
		const sf::Vector2f & getPosition() const;

		///
		///Metoda ustawia pozycję obiektu
		///
		///@param x - współrzędna x obiektu
		///
		///@param y - współrzędna y obiektu
		///
		///@param change_old_position - flaga, czy aktualizować m_old_position
		///
		void setPosition(float x, float y, bool change_old_position = false);

		///
		///Metoda ustawia pozycję obiektu
		///
		///@param vector - stała referenacja na obiekt klasy sf::Vector2f
		///
		///@param change_old_position - flaga, czy aktualizować m_old_position
		///
		void setPosition(const sf::Vector2f & new_value, bool change_old_position = false);

		///
		///Metoda zwraca pozycję przed aktualizacją logiki m_old_position
		///
		const sf::Vector2f & getOldPosition() const;

		///
		///Metoda zwraca skalę (body)
		///
		const sf::Vector2f & getScaleBody() const;
		
		///
		///Metoda ustawia skalę (body)
		///
		///@param scale_X - wartość X
		///
		///@param scale_Y - wartość Y
		///
		void setScaleBody(float scale_X, float scale_Y);
		
		///
		///Metoda ustawia skalę (body)
		///
		///@param scale_vector - wektor skali - stała referencja na obiekt klasy sf::Vector2f
		///
		void setScaleBody(const sf::Vector2f & scale_vector);

		///
		///Metoda zwraca skalę (head)
		///
		const sf::Vector2f & getScaleHead() const;

		///
		///Metoda ustawia skalę (head)
		///
		///@param scale_X - wartość X
		///
		///@param scale_Y - wartość Y
		///
		void setScaleHead(float scale_X, float scale_Y);

		///
		///Metoda ustawia skalę (head)
		///
		///@param scale_vector - wektor skali - stała referencja na obiekt klasy sf::Vector2f
		///
		void setScaleHead(const sf::Vector2f & scale_vector);

		///
		///Metoda ustawia skalę (body and head)
		///
		///@param scale_X - wartość X
		///
		///@param scale_Y - wartość Y
		///
		void setScale(float scale_X, float scale_Y);

		///
		///Metoda ustawia skalę (body and head)
		///
		///@param scale - wektor skali - stała referencja na obiekt klasy sf::Vector2f
		///
		void setScale(const sf::Vector2f & scale);

		///
		///Metoda ustawia skalę
		///
		///@param uniform - jednolita wartość skalująca w osi x i y
		///
		void setScale(float uniform);

		///
		///Metoda zwraca wartość obrotu obiektu w stopniach (body and head)
		///
		const float getRotation() const;

		///
		///Metoda ustawia wartość obrotu obiektu w stopniach (body and head)
		///
		///@param rotation_uniform - wartość obrotu obiektu (body and head)
		///
		void setRotation(float rotation_uniform);

		///
		///Metoda zwraca wartość obrotu obiektu w stopniach (body)
		///
		const float getRotationBody() const;

		///
		///Metoda ustawia wartość obrotu obiektu w stopniach (body)
		///
		///@param rotation_body - wartość obrotu obiektu (body)
		///
		void setRotationBody(float rotation_body);

		///
		///Metoda zwraca wartość obrotu obiektu w stopniach (head)
		///
		const float getRotationHead() const;

		///
		///Metoda ustawia wartość obrotu obiektu w stopniach (head)
		///
		///@param rotation_head - wartość obrotu obiektu (head)
		///
		void setRotationHead(float rotation_head);

		///
		///Metoda obraca obiekt o zadany kąt (body)
		///
		///@param angle - wartość obrotu
		///
		void rotateBody(float angle);

		///
		///Metoda obraca obiekt o zadany kąt (head)
		///
		///@param angle - wartość obrotu
		///
		void rotateHead(float angle);

		///
		///Metoda obraca obiekt o zadany kąt (body and head)
		///
		///@param angle - wartość obrotu
		///
		void rotate(float angle);

		///
		///Metoda zwraca prędkość obiektu
		///
		const sf::Vector2f & getVelocity() const;

		///
		///Metoda ustawia prędkość obiektu
		///
		///@param velocity - stała referencja na obiekt klasy sf::Vector2f
		///
		void setVelocity(const sf::Vector2f & velocity);

		///
		///Metoda zwraca promień detekcji wykorzystywany przy liczeniu kolizji
		///
		float getCircleRadius();

		///
		///Metoda zwraca referencję na wyliczenie - typ liczenia kolizji
		///
		ECollisionShape & getCollisionShape();

		///
		///Wirtualna metoda ustawiająca wartość promienia detekcji wykorzystywaną przy liczeniu kolizji
		///
		///@param radius - promień detekcji
		///
		virtual void setBoundingCircle(float radius);

		///
		///Metoda ustawia wartość obszaru prostokątnego detekcji wykorzystywany przy liczeniu kolizji
		///
		///@param rect_size - stała referencja wektor dla obszaru prostokątnego detekcji wykorzystywany przy liczeniu kolizji
		///
		void setBoundingRect(const sf::Vector2f & rect_size);

		///
		///Metoda zwraca wektor dla obszaru prostokątnego detekcji wykorzystywany przy liczeniu kolizji
		///
		const sf::Vector2f & getRectSize() const ;

		///
		///Metoda zwraca stałą referencję na wektor wielkości obiektu
		///wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
		///klasy CDisplayable
		///
		const sf::Vector2f & getRectangleSizeBody() const;

		///
		///Metoda ustawia referencję na wektor wielkości obiektu
		///wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
		///klasy CDisplayable
		///
		///@param rect_size_body - stałą referencja na obiekt klasy sf::Vector2f
		///
		void setRectangleSizeBody(const sf::Vector2f & rect_size_body);
	
		///
		///Metoda ustawia referencję na wektor wielkości obiektu
		///wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
		///klasy CDisplayable
		///
		///@param rect_size_body_width - szerokośc tekstury (wymaga rzutowania na typ całkowity)
		///
		///@param rect_size_body_height - wysokość tekstury (wymaga rzutowania na typ całkowity)
		///
		void setRectangleSizeBody(float rect_size_body_width, float rect_size_body_height);
		
		///
		///Metoda zwraca stałą referencję na wektor wielkości obiektu
		///wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
		///klasy CDisplayable
		///
		const sf::Vector2f & getRectangleSizeHead() const;

		///
		///Metoda ustawia referencję na wektor wielkości obiektu
		///wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
		///klasy CDisplayable
		///
		///@param rect_size_head - stałą referencja na obiekt klasy sf::Vector2f
		///
		void setRectangleSizeHead(const sf::Vector2f & rect_size_head);

		///
		///Metoda ustawia referencję na wektor wielkości obiektu
		///wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
		///klasy CDisplayable
		///
		///@param rect_size_head_width - szerokośc tekstury (wymaga rzutowania na typ całkowity)
		///
		///@param rect_size_head_height - wysokość tekstury (wymaga rzutowania na typ całkowity)
		///
		void setRectangleSizeHead(float rect_size_head_width, float rect_size_head_height);
		
		///
		///Metoda ustawia referencję na wektor wielkości obiektu
		///wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
		///klasy CDisplayable - body and head
		///
		///@param rect_size_uniform - stała referencja na obiekt klasy sf::Vector2f
		///
		void setRectangleSize(const sf::Vector2f & rect_size_uniform);

		///
		///Metoda ustawia referencję na wektor wielkości obiektu
		///wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
		///klasy CDisplayable - body and head
		///
		///@param rect_size_uniform_width - szerokośc tekstury (wymaga rzutowania na typ całkowity)
		///
		///@param rect_size_uniform_height - wysokość tekstury (wymaga rzutowania na typ całkowity)
		///
		void setRectangleSize(float rect_size_uniform_width, float rect_size_uniform_height);
		
		///
		///Metoda ustawia referencję na wektor wielkości obiektu
		///wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
		///klasy CDisplayable - body and head
		///
		///@param rect_size_body - stałą referencja na obiekt klasy sf::Vector2f
		///
		///@param rect_size_head - stałą referencja na obiekt klasy sf::Vector2f
		///
		void setRectangleSize(const sf::Vector2f & rect_size_body, const sf::Vector2f & rect_size_head);
		
		///
		///Metoda ustawia referencję na wektor wielkości obiektu
		///wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
		///klasy CDisplayable - body and head
		///
		///@param rect_size_body_width - szerokośc tekstury (wymaga rzutowania na typ całkowity)
		///
		///@param rect_size_body_height - wysokość tekstury (wymaga rzutowania na typ całkowity)
		///
		///@param rect_size_head_width - wysokość tekstury (wymaga rzutowania na typ całkowity)
		///
		///@param rect_size_head_height - wysokość tekstury (wymaga rzutowania na typ całkowity)
		///
		void setRectangleSize(float rect_size_body_width, float rect_size_body_height, float rect_size_head_width, float rect_size_head_height);

		///
		///Metoda zwraca wartość pułapu obiektu
		///
		const float getAltitude() const;

		///
		///Metoda ustawia wartość pułapu obiektu
		///
		///@param altitude - wartość pułapu obiektu
		///
		void setAltitude(float altitude);

		///
		///Metoda zwraca kolor obiektu - body
		///
		const sf::Color & getColor() const;

		///
		///Metoda ustawia kolor obiektu - (body and head)
		///
		///@param color - kolor
		///
		void setColor(const sf::Color & color);

		///
		///Metoda zwraca kolor obiektu - body
		///
		const sf::Color & getColorBody() const;

		///
		///Metoda ustawia kolor obiektu - body
		///
		///@param color_body - kolor obiektu
		///
		void setColorBody(const sf::Color & color_body);

		///
		///Metoda zwraca kolor obiektu - head
		///
		const sf::Color & getColorHead() const;

		///
		///Metoda ustawia kolor obiektu - head
		///
		///@param color_head - kolor
		///
		void setColorHead(const sf::Color & color_head);

		///
		///Metoda ustawia oryginalny kolor obiektu załadowany z tekstury - body and head
		///
		void restoreColor();

		///
		///Metoda ustawia oryginalny kolor obiektu załadowany z tekstury - body
		///
		void restoreColorBody();

		///
		///Metoda ustawia oryginalny kolor obiektu załadowany z tekstury - head
		///
		void restoreColorHead();

		///
		///Metoda ustawia kolor do zapamiętania - body
		///
		const sf::Color & getStoredColorBody() const;

		///
		///Metoda ustawia kolor do zapamiętania - body
		///
		///@param color_stored_body - stała referencja na obiekt klasy sf::Color
		///
		void storeColorBody(const sf::Color & color_stored_body);

		///
		///Metoda ustawia kolor do zapamiętania - body
		///
		const sf::Color & getStoredColorHead() const;

		///
		///Metoda ustawia kolor do zapamiętania - body
		///
		///@param color_stored_head - stała referencja na obiekt klasy sf::Color
		///
		void storeColorHead(const sf::Color & color_stored_head);

		///
		///Metoda zwraca kolor cienia obiektu
		///
		const sf::Color & getColorShadow() const;

		///
		///Metoda ustawia kolor cienia obiektu
		///
		///@param color_shadow - kolor cienia obiektu
		///
		void setColorShadow(const sf::Color & color_shadow);

		///
		///Metoda zwraca wektor przesunięcia cienia względem obiektu - body
		///
		sf::Vector2f & getShadowOffsetBody();

		///
		///Metoda ustawia wektor przesunięcia cienia względem obiektu - body
		///
		///@param shadow_offset_body - stała referencja na wektor przesunięcia cienia względem obiektu
		///
		void setShadowOffsetBody(sf::Vector2f & shadow_offset_body);

		///
		///Metoda zwraca wektor przesunięcia cienia względem obiektu - head
		///
		sf::Vector2f & getShadowOffsetHead();

		///
		///Metoda ustawia wektor przesunięcia cienia względem obiektu - head
		///
		///@param shadow_offset_head - stała referencja na wektor przesunięcia cienia względem obiektu
		///
		void setShadowOffsetHead(sf::Vector2f & shadow_offset_head);
		
		///
		///Metoda zwraca flagę, czy obiekt generuje reprezentację graficzną (body and head) /zgodność interfejsu/
		///
		const bool getUseDisplayable() const;

		///
		///Metoda zwraca flagę, czy Physical ma reprezentację graficzą (body)
		///
		const bool getUseDisplayableBody() const;

		///
		///Metoda zwraca flagę, czy Physical ma reprezentację graficzą (head)
		///
		const bool getUseDisplayableHead() const;

		///
		///Metoda ustawia flagę, czy Physical ma reprezentację graficzą (body and head)
		///
		///@param use_displayable - flaga, czy obiekt ma używać reprezentacji graficznej
		///
		void setUseDisplayable(const bool use_displayable);

		///
		///Metoda ustawia flagę, czy Physical ma reprezentację graficzą (body)
		///
		///@param use_displayable_body - flaga, czy obiekt ma używać reprezentacji graficznej
		///
		void setUseDisplayableBody(const bool use_displayable_body);

		///
		///Metoda ustawia flagę, czy Physical ma reprezentację graficzą (head)
		///
		///@param use_displayable_head - flaga, czy obiekt ma używać reprezentacji graficznej
		///
		void setUseDisplayableHead(const bool use_displayable_head);

		///
		///Metoda zwraca flagę, czy obiekt generuje cień (body and head) /zgodność interfejsu/
		///
		const bool getUseShadow() const;

		///
		///Metoda zwraca flagę, czy obiekt generuje cień (body)
		///
		const bool getUseShadowBody() const;

		///
		///Metoda zwraca flagę, czy obiekt generuje cień (head)
		///
		const bool getUseShadowHead() const;

		///
		///Metoda ustawia flagę, czy obiekt ma generować cień (body and head) /zgodność interfejsu/
		///
		///@param use_shadow - flaga, czy obiekt ma generować cień (body and head) /zgodność interfejsu/
		///
		void setUseShadow(const bool use_shadow);

		///
		///Metoda ustawia flagę, czy obiekt ma generować cień (body)
		///
		///@param use_shadow_body - flaga, czy obiekt ma generować cień (body)
		///
		void setUseShadowBody(const bool use_shadow_body);

		///
		///Metoda ustawia flagę, czy obiekt ma generować cień (head)
		///
		///@param use_shadow_head - flaga, czy obiekt ma generować cień (head)
		///
		void setUseShadowHead(const bool use_shadow_head);

		///
		///Metoda zwraca wskaźnik na animację (body)
		///
		CAnimation *getAnimationBody();

		///
		///Metoda ustawia ustawia wskaźnik na animację (body)
		///
		///@param *p_anim_body - wskaźnik na animację - obiekt klasy CAnimation (body)
		///
		void setAnimationBody(CAnimation *p_anim_body);

		///
		///Metoda zwraca nazwę animacji (body)
		///
		const std::string & getAnimationBodyName() const;

		///
		///Metoda ustawia nazwę animacji (body)
		///
		///@param anim_body_name - nazwa animacji (body)
		///
		void setAnimationBody(const std::string & anim_body_name);

		///
		///Metoda zwraca wskaźnik na animację (head)
		///
		CAnimation *getAnimationHead();

		///
		///Metoda ustawia ustawia wskaźnik na animację (head)
		///
		///@param *p_anim_head - wskaźnik na animację - obiekt klasy CAnimation (head)
		///
		void setAnimationHead(CAnimation *p_anim_head);

		///
		///Metoda zwraca nazwę animacji (head)
		///
		const std::string & getAnimationHeadName() const;

		///
		///Metoda ustawia nazwę animacji (head)
		///
		///@param anim_head_name - nazwa animacji (head)
		///
		void setAnimationHead(const std::string & anim_head_name);

		///
		///Metoda ustawia komplet animacji
		///
		///@param *p_anim_body - wskaźnik na obiekt klasy CAnimation (body)
		///
		///@param *p_anim_head - wskaźnik na obiekt klasy CAnimation (head)
		///
		void setAnimation(CAnimation *p_anim_body, CAnimation *p_anim_head);

		///
		///Metoda ustawia komplet animacji
		///
		///@param anim_name_body - stała referencja na obiekt klasy std::string - nazwa animacji (body)
		///
		///@param anim_name_head - stała referencja na obiekt klasy std::string - nazwa animacji (head)
		///
		void setAnimation(const std::string & anim_name_body, const std::string & anim_name_head);
	    
		///
		///Metoda zwraca pamiętany współczynnik prędkości odtwarzania animacji (body)
		///
		const float getStoredAnimSpeedBody() const;

		///
		///Metoda zwraca pamiętany współczynnik prędkości odtwarzania animacji (body)
		///
		const float getStoredAnimSpeedHead() const;

		///
		///Metoda zwraca współczynnik prędkości odtwarzania animacji 1.0f - normal speed (body)
		///
		const float getAnimSpeedBody() const;

		///
		///Metoda zwraca współczynnik prędkości odtwarzania animacji 1.0f - normal speed (head)
		///
		const float getAnimSpeedHead() const;

		///
		///Metoda ustawia współczynnik prędkości odtwarzania animacji 1.0f - normal speed (body)
		///
		///@param anim_speed - współczynnik prędkości odtwarzania animacji
		///
		void setAnimSpeedBody(float anim_speed);

		///
		///Metoda ustawia współczynnik prędkości odtwarzania animacji 1.0f - normal speed (head)
		///
		///@param anim_speed - współczynnik prędkości odtwarzania animacji
		///
		void setAnimSpeedHead(float anim_speed);

		///
		///Metoda ustawia współczynnik prędkości odtwarzania animacji 1.0f - normal speed (body and head)
		///
		///@param anim_uniform_speed - współczynnik prędkości odtwarzania animacji
		///
		void setAnimSpeed(float anim_uniform_speed);

		///
		///Metoda ustawia współczynnik prędkości odtwarzania animacji 1.0f - normal speed (body and head)
		///
		///@param anim_speed_body - współczynnik prędkości odtwarzania animacji (body)
		///
		///@param anim_speed_head - współczynnik prędkości odtwarzania animacji (head)
		///
		void setAnimSpeed(float anim_speed_body, float anim_speed_head);

		///
		///Metoda zwraca wskaźnik na obiekt klasy CDisplayable (body) /zgodność interfejsu/
		///
		CDisplayable *getDisplayable();
	    
		///
		///Metoda zwraca wskaźnik na obiekt klasy CDisplayable (shadow) /zgodność interfejsu/
		///
		CDisplayable *getShadow();

		///
		///Metoda zwraca wskaźnik na obiekt klasy CDisplayable (body)
		///
		///@param physical_part - wyliczenie EPhysicalPart - część physical
		///
		CDisplayable *getDisplayable(EPhysicalPart physical_part);
	    
		///
		///Metoda zwraca wskaźnik na obiekt klasy CDisplayable (shadow)
		///
		///@param physical_part - wyliczenie EPhysicalPart - część physical
		///
		CDisplayable *getShadow(EPhysicalPart physical_part);

		///
		///Metoda zwraca wskaźnik na obiekt klasy CDisplayable (body)
		///
		CDisplayable *getDisplayableBody();
	    
		///
		///Metoda zwraca wskaźnik na obiekt klasy CDisplayable (body shadow)
		///
		CDisplayable *getDisplayableBodyShadow();

		///
		///Metoda zwraca wskaźnik na obiekt klasy CDisplayable (head)
		///
		CDisplayable *getDisplayableHead();

		///
		///Metoda zwraca wskaźnik na obiekt klasy CDisplayable (head shadow)
		///
		CDisplayable *getDisplayableHeadShadow();

		///
		///Metoda ustawia flagę dla obiektów gotowych do destrukcji
		///
		void markForDelete();
	    
		///
		///Wirtualna metoda zaznacza obiekty do destrukcji
		///
		virtual void kill();

		///
		///Metoda zwraca flagę, czy obiekt jest gotowy do usuniecia
		///
		virtual bool isDead();

		///
		///Metoda zwraca nazwę tekstury (body)
		///
		const std::string & getTextureBody() const;
		
		///
		///Metoda ustatawia nazwę tekstury (body)
		///
		///@param texture_body - nazwa tekstury (body)
		///
		void setTextureBody(const std::string & texture_body);

		///
		///Metoda zwraca nazwę tekstury (head)
		///
		const std::string & getTextureHead() const;
		
		///
		///Metoda ustatwia nazwę tekstury (head)
		///
		///@param texture_head - nazwa tekstury (head)
		///
		void setTextureHead(const std::string & texture_head);
		
		///
		///Metoda generuje obraz tekstury
		///
		///@param width - szerokość tekstury (obiektu) w pikselach
		///
		///@param height - wysokość tekstury (obiektu) w pikselach
		///
		///@param color - color - stała referencja na obiekt klasy sf::Color
		///
		void setTextureBody(unsigned width, unsigned height, const sf::Color & color = sf::Color(0, 0, 0));

		///
		///Metoda generuje obraz tekstury
		///
		///@param width - szerokość tekstury (obiektu) w pikselach
		///
		///@param height - wysokość tekstury (obiektu) w pikselach
		///
		///@param r - składowa red koloru
		///
		///@param g - składowa green koloru
		///
		///@param b - składowa blue koloru
		///
		///@param a - składowa alpha koloru
		///
		void setTextureBody(unsigned width, unsigned height, unsigned r, unsigned g, unsigned b, unsigned a = 255);

		///
		///Metoda generuje obraz tekstury
		///
		///@param width - szerokość tekstury (obiektu) w pikselach
		///
		///@param height - wysokość tekstury (obiektu) w pikselach
		///
		///@param color - color - stała referencja na obiekt klasy sf::Color
		///
		void setTextureHead(unsigned width, unsigned height, const sf::Color & color = sf::Color(0, 0, 0));

		///
		///Metoda generuje obraz tekstury
		///
		///@param width - szerokość tekstury (obiektu) w pikselach
		///
		///@param height - wysokość tekstury (obiektu) w pikselach
		///
		///@param r - składowa red koloru
		///
		///@param g - składowa green koloru
		///
		///@param b - składowa blue koloru
		///
		///@param a - składowa alpha koloru
		///
		void setTextureHead(unsigned width, unsigned height, unsigned r, unsigned g, unsigned b, unsigned a = 255);

		///
		////Metoda zwraca tryb wygładzania tekstury
		///
		const bool getSmoothing() const;

		///
		///Metoda ustawia tryb wygładzania tekstury
		///
		///@param smooth - flaga wygładzania tekstury
		///
		void setSmoothing(bool smooth);

		///
		///Metoda zwraca statyczny współczynnik wirtualnej wysokości obiektu
		///
		const float getIncrease() const;

		///
		///Metoda ustawia statyczny współczynnik wirtualnej wysokości obiektu
		///
		///@param increase - wirtualna wysokość obiektu
		///
		const void setIncrease(float increase) const;

		///
		///Metoda zwraca wskaźnik na obiekt klasy PhysicalTemplate
		///
		PhysicalTemplate *getTemplate() const;

		///
		///Metoda ustawia wskaźnik na obiekt klasy PhysicalTemplate
		///
		///@param *p_template - wskaźnik na obiekt klasy PhysicalTemplate
		///
		void setTemplate(PhysicalTemplate *p_template_param);

		///
		///Metoda zwraca opakowanie informacji o kolidowaniu
		///
		PartCollisionData & getPartCollisionData();

		///
		///Wirtualna metoda aktualizująca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);

	protected:
	    
		physCategory m_category; //kategoria Physical
		std::wstring m_unique_id; //unikalny identyfikator (nadawany w PhysicalManager)
		std::wstring m_genre; //nazwa "gatunku" obiektu (np. robot, human, gun, etc.)
		float m_circle_radius; //promień detekcji kolizji
		ECollisionShape m_collision_shape; //wyliczenie - typ detekcji kolizji
		sf::Vector2f m_rect_size; //wektor przechowujący rozmiar obszaru prostokątnego
		sf::Vector2f m_rect_size_body; //wektor przechowujący rozmiar obszaru prostokątnego - body (wykorzystywany do tworzenia syntetyków)
		sf::Vector2f m_rect_size_head; //wektor przechowujący rozmiar obszaru prostokątnego - head (wykorzystywany do tworzenia syntetyków)
		PhysicalTemplate *p_template; //wskaźnik na obiekt klasy PhysicalTemplate
		bool m_ready_for_destruction; //flaga ustawia obiekty gotowe do destrukcji
		PartCollisionData m_part_collision_data; //opakowanie informacji o kolidowaniu
		float m_new_anim_speed; //wyliczony współczynnik prędkości odtwarzania animacji

	private:

		int m_physical_manager_index; //wyliczony indeks w PhysicalManager
		PhysicalData m_physical_data; //opakowanie funkcjonalności klasy Physical
		bool m_smooth; //flaga, czy obiekt wygładza piksele tekstury
		static float m_increase; //współczynnik wirtualnej wysokości obiektu

	protected:

		///
		///Metoda zwraca wyliczony współczynnik prędkości animacji dla zadanego czasu trwania jednego obiegu animacji
		///
		///@param anim_time - czas jednego pełnego obiegu animacji
		///
		const float getCalcualtedAnimSpeed(float anim_time);

		///
		///Metoda zwraca indeks warstwy renderingu obiektu (body)
		///
		const int getZIndexBody() const;

		///
		///Metoda ustawia indeks warstwy renderingu obiektu (body)
		///
		///@param layer_index - indeks warstwy renderingu obiektu
		///
		void setZIndexBody(int layer_index);

		///
		///Metoda zwraca indeks warstwy renderingu obiektu (body shadow)
		///
		const int getZIndexShadowBody() const;

		///
		///Metoda ustawia indeks warstwy renderingu obiektu (body shadow)
		///
		///@param layer_index - indeks warstwy renderingu obiektu
		///
		void setZIndexShadowBody(int layer_index);

		///
		///Metoda zwraca indeks warstwy renderingu obiektu (head)
		///
		const int getZIndexHead() const;

		///
		///Metoda ustawia indeks warstwy renderingu obiektu (head)
		///
		///@param layer_index - indeks warstwy renderingu obiektu
		///
		void setZIndexHead(int layer_index);

		///
		///Metoda zwraca indeks warstwy renderingu obiektu (head shadow)
		///
		const int getZIndexShadowHead() const;

		///
		///Metoda ustawia indeks warstwy renderingu obiektu (head shadow)
		///
		///@param layer_index - indeks warstwy renderingu obiektu
		///
		void setZIndexShadowHead(int layer_index);

		///
		///Metoda aktualizuje cień rzucany przez obiekt i jego nasycenie w zależności od pory dnia
		///
		///@param dt - czas
		///
		void updateShadow(float dt);

	private:

		void checkDisplayableBody();		//prywatna metoda sprawdza, czy trzeba utworzyć
											//obiekt klasy CDisplayable (body), np. gdy chcemy
											//dodać obrazek, animację, etc...

		void checkDisplayableHead();		//prywatna metoda sprawdza, czy trzeba utworzyć
											//obiekt klasy CDisplayable (head), np. gdy chcemy
											//dodać obrazek, animację, etc...

		void updateShadowTransformation();	//prywatna metoda dobierająca przesunięcie cienia
											//w zależności od wielkości obiektu - body and head
											//oraz jego nasycenie w zależności od pory dnia
											//pozycji słońca (źródła światła - gwiazd, etc...)

		void checkShadowOffsetBody();		//prywatna metoda ustala wektor przesunięcia cienia - body
		void checkShadowOffsetHead();		//prywatna metoda ustala wektor przesunięcia cienia - head
		void checkShadowOffset();			//prywatna metoda ustala wektor przesunięcia cienia - body and head

	};
}//namespace logic
#endif //H_PHYSICAL_JACK
