//  ______________________________________
// | Physical.cpp - class implementation  |
// | Jack Flower - August 2012            |
// |______________________________________|
//

#include "Physical.h"
#include "../../Weather/CWeather.h"
#include "../../Rendering/Displayable/Displayable.h"
#include "../../Rendering/Drawable/CDrawableManager.h"
#include "../../Rendering/Animations/Animation.h"
#include "../../Rendering/Animations/AnimationState.h"
#include "../../Factory/PhysicalTemplate.h"
#include "../../Utilities/Utilities/Utilities.h"
#include <math.h>

using namespace weather;

namespace logic
{
	RTTI_IMPL_NOPARENT(Physical);

	//Chroniony konstruktor domyślny - używany wyłącznie przez PhysicalManager
	Physical::Physical(const std::wstring & uniqueId)
	:
		//private:
		m_physical_manager_index(-1),
		m_physical_data(),
		m_smooth(false),
		
		//protected:
		m_unique_id(uniqueId),
		m_genre(),
		m_circle_radius(1.0f),
		m_collision_shape(SHAPE_CIRCLE),
		m_rect_size(1.0f, 1.0f),
		m_rect_size_body(1.0f, 1.0f),
		m_rect_size_head(1.0f, 1.0f),
		p_template(NULL),
		m_ready_for_destruction(false),
		m_part_collision_data(),
		m_new_anim_speed(1.0f)
	{
	}

	//Chroniony konstruktor kopiujący
	Physical::Physical(const Physical & PhysicalCopy)
	:
		//private:
		m_physical_manager_index(PhysicalCopy.m_physical_manager_index),
		m_physical_data(PhysicalCopy.m_physical_data),
		m_smooth(PhysicalCopy.m_smooth),
		
		//protected:
		m_unique_id(PhysicalCopy.m_unique_id),
		m_genre(PhysicalCopy.m_genre),
		m_circle_radius(PhysicalCopy.m_circle_radius),
		m_collision_shape(PhysicalCopy.m_collision_shape),
		m_rect_size(PhysicalCopy.m_rect_size),
		m_rect_size_body(PhysicalCopy.m_rect_size_body),
		m_rect_size_head(PhysicalCopy.m_rect_size_head),
		p_template(PhysicalCopy.p_template),
		m_ready_for_destruction(PhysicalCopy.m_ready_for_destruction),
		m_part_collision_data(PhysicalCopy.m_part_collision_data),
		m_new_anim_speed(PhysicalCopy.m_new_anim_speed)
	{
	}

	//Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
	Physical::~Physical()
	{
		//private:
		m_physical_manager_index = 0;
		m_smooth = false;

		//protected:
		m_unique_id = L"";
		m_genre = L"";
		//m_physics_data
		m_circle_radius = 0.0f;
		m_rect_size.x = 0.0f;
		m_rect_size.y = 0.0f;
		m_rect_size_body.x = 0.0f;
		m_rect_size_body.y = 0.0f;
		m_rect_size_head.x = 0.0f;
		m_rect_size_head.y = 0.0f;
		p_template = NULL;
		m_ready_for_destruction = false;
		//m_part_collision_data
		m_new_anim_speed = 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string Physical::getType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca unikalną nazwę obiektu klasy Physical
	const std::wstring & Physical::getUniqueId() const
	{
		return m_unique_id;
	}

	//Metoda zwraca nazwę gatunku
	const std::wstring & Physical::getGenre()
	{
		return m_genre; 
	}

	//Metoda zwraca wagę
	const float Physical::getWeight() const
	{
		return m_physical_data.getWeight();
	}

	//Metoda ustawia wagę
	void Physical::setWeight(float weight)
	{
		if (weight < 0) return;
		m_physical_data.setWeight(weight);
	}

	//Metoda zwraca kategorę Physical
	physCategory Physical::getCategory()
	{
		return m_category;
	}

	//Metoda ustawia kategorię Physical
	void Physical::setCategory(const physCategory & category)
	{
		m_category = category;
	}

	//Metoda ustawia kategorię Physical
	void Physical::setCategory(const std::wstring & category_name)
	{
		//parsowanie kategorii na podstawie tablicy nazw kategorii
		//docelowo napisać jakiś prosty translator...
		if (category_name == L"detector")
			m_category = PHYSICAL_DETECTOR;
		else if (category_name == L"player")
			m_category = PHYSICAL_PLAYER;
		else if (category_name == L"monster")
			m_category = PHYSICAL_MONSTER;
		else if (category_name == L"npc")
			m_category = PHYSICAL_NPC;
		else if (category_name == L"bullet")
			m_category = PHYSICAL_BULLET;
		else if (category_name == L"lair")
			m_category = PHYSICAL_LAIR;
		else if (category_name == L"wall")
			m_category = PHYSICAL_WALL;
		else if (category_name == L"item")
			m_category = PHYSICAL_ITEM;
		else if (category_name == L"door")
			m_category = PHYSICAL_DOOR;
		else if (category_name == L"trap")
			m_category = PHYSICAL_TRAP;
		else if (category_name == L"region")
			m_category = PHYSICAL_REGION;
		else if (category_name == L"obstacle")
			m_category = PHYSICAL_OBSTACLE;
		else if (category_name == L"hook")
			m_category = PHYSICAL_HOOK;
		else 
			fprintf(stderr, "unrecognised physical category: %ls for physical %ls\n", category_name.c_str(), getUniqueId().c_str());
	}

	//Metoda ustawia nazwę gatunku
	void Physical::setGenre(const std::wstring & genre)
	{
		m_genre = genre; 
	}

	//Metoda zwraca pozycję obiektu
	const sf::Vector2f & Physical::getPosition() const
	{
		return m_physical_data.getPosition();
	}

	//Metoda ustawia pozycję obiektu
	void Physical::setPosition(float x, float y, bool change_old_position)
	{
		m_physical_data.setPosition(x, y);
	}

	//Metoda ustawia pozycję obiektu
	void Physical::setPosition(const sf::Vector2f & new_value, bool change_old_position)
	{
		m_physical_data.setPosition(new_value);
	}

	//Metoda zwraca pozycję przed aktualizacją logiki m_old_position
	const sf::Vector2f & Physical::getOldPosition() const
	{
		return m_physical_data.getOldPosition();
	}

	//Metoda zwraca skalę (body)
	const sf::Vector2f & Physical::getScaleBody() const
	{
		return m_physical_data.getDisplayableBody()->getScale();
	}

	//Metoda ustawia skalę (body)
	void Physical::setScaleBody(float scale_X, float scale_Y)
	{
		//zapamiętuję skalę
		m_physical_data.setStoredScaleBody(scale_X, scale_Y);

		//obiekt zasadniczy i cień zawsze mają tę samą skalę
		if(m_physical_data.getDisplayableBody())
			m_physical_data.getDisplayableBody()->setScale(scale_X, scale_Y);

		if(m_physical_data.getDisplayableBodyShadow())
			m_physical_data.getDisplayableBodyShadow()->setScale(scale_X, scale_Y);
	}

	//Metoda ustawia skalę (body)
	void Physical::setScaleBody(const sf::Vector2f & scale_vector)
	{
		//zapamiętuję skalę
		m_physical_data.setStoredScaleBody(scale_vector);

		//obiekt zasadniczy i cień zawsze mają tę samą skalę
		if(m_physical_data.getDisplayableBody())
			m_physical_data.getDisplayableBody()->setScale(scale_vector);

		if(m_physical_data.getDisplayableBodyShadow())
			m_physical_data.getDisplayableBodyShadow()->setScale(scale_vector);
	}

	//Metoda zwraca skalę (body)
	const sf::Vector2f & Physical::getScaleHead() const
	{
		return m_physical_data.getDisplayableHead()->getScale();
	}

	//Metoda ustawia skalę (head)
	void Physical::setScaleHead(float scale_X, float scale_Y)
	{
		//zapamiętuję skalę
		m_physical_data.setStoredScaleHead(scale_X, scale_Y);

		//obiekt zasadniczy i cień zawsze mają tę samą skalę
		if(m_physical_data.getDisplayableHead())
			m_physical_data.getDisplayableHead()->setScale(scale_X, scale_Y);

		if(m_physical_data.getDisplayableHeadShadow())
			m_physical_data.getDisplayableHeadShadow()->setScale(scale_X, scale_Y);
	}

	//Metoda ustawia skalę (head)
	void Physical::setScaleHead(const sf::Vector2f & scale_vector)
	{
		//zapamiętuję skalę
		m_physical_data.setStoredScaleHead(scale_vector);

		//obiekt zasadniczy i cień zawsze mają tę samą skalę
		if(m_physical_data.getDisplayableHead())
			m_physical_data.getDisplayableHead()->setScale(scale_vector);

		if(m_physical_data.getDisplayableHeadShadow())
			m_physical_data.getDisplayableHeadShadow()->setScale(scale_vector);
	}

	//Metoda ustawia skalę (body and head)
	void Physical::setScale(float scale_X, float scale_Y)
	{
		//zapamiętuję skalę
		m_physical_data.setStoredScaleBody(scale_X, scale_Y);

		//zapamiętuję skalę
		m_physical_data.setStoredScaleHead(scale_X, scale_Y);

		//obiekt zasadniczy i cień zawsze mają tę samą skalę
		if(m_physical_data.getDisplayableBody())
			m_physical_data.getDisplayableBody()->setScale(scale_X, scale_Y);

		if(m_physical_data.getDisplayableBodyShadow())
			m_physical_data.getDisplayableBodyShadow()->setScale(scale_X, scale_Y);

		//obiekt zasadniczy i cień zawsze mają tę samą skalę
		if(m_physical_data.getDisplayableHead())
			m_physical_data.getDisplayableHead()->setScale(scale_X, scale_Y);

		if(m_physical_data.getDisplayableHeadShadow())
			m_physical_data.getDisplayableHeadShadow()->setScale(scale_X, scale_Y);
	}

	//Metoda ustawia skalę (body and head)
	void Physical::setScale(const sf::Vector2f & scale)
	{
		//zapamiętuję skalę
		m_physical_data.setStoredScaleBody(scale);
		m_physical_data.setStoredScaleHead(scale);

		//obiekt zasadniczy i cień zawsze mają tę samą skalę
		if(m_physical_data.getDisplayableBody())
			m_physical_data.getDisplayableBody()->setScale(scale);

		if (m_physical_data.getDisplayableBodyShadow())
			m_physical_data.getDisplayableBodyShadow()->setScale(scale);

		//obiekt zasadniczy i cień zawsze mają tę samą skalę
		if(m_physical_data.getDisplayableHead())
			m_physical_data.getDisplayableHead()->setScale(scale);

		if (m_physical_data.getDisplayableHeadShadow())
			m_physical_data.getDisplayableHeadShadow()->setScale(scale);
	}

	//Metoda ustawia skalę
	void Physical::setScale(float uniform)
	{
		//zapamiętuję skalę
		m_physical_data.setStoredScaleBody(uniform, uniform);

		//obiekt zasadniczy i cień zawsze mają tę samą skalę
		if(m_physical_data.getDisplayableBody())
			m_physical_data.getDisplayableBody()->setScale(uniform);

		if (m_physical_data.getDisplayableHead())
			m_physical_data.getDisplayableHead()->setScale(uniform);

		//obiekt zasadniczy i cień zawsze mają tę samą skalę
		if(m_physical_data.getDisplayableBodyShadow())
			m_physical_data.getDisplayableBodyShadow()->setScale(uniform);

		if (m_physical_data.getDisplayableHeadShadow())
			m_physical_data.getDisplayableHeadShadow()->setScale(uniform);
	}

	//Metoda zwraca wartość obrotu obiektu w stopniach
	const float Physical::getRotation() const
	{
		return m_physical_data.getRotation();
	}

	//Metoda ustawia wartość obrotu obiektu w stopniach (body and head)
	void Physical::setRotation(float rotation)
	{
		m_physical_data.setRotation(rotation);
	}

	//Metoda zwraca wartość obrotu obiektu w stopniach (body)
	const float Physical::getRotationBody() const
	{
		return m_physical_data.getRotationBody();
	}

	//Metoda ustawia wartość obrotu obiektu w stopniach (body)
	void Physical::setRotationBody(float rotation_body)
	{
		m_physical_data.setRotationBody(rotation_body);
	}

	//Metoda zwraca wartość obrotu obiektu w stopniach (head)
	const float Physical::getRotationHead() const
	{
		return m_physical_data.getRotationHead();
	}

	//Metoda ustawia wartość obrotu obiektu w stopniach (head)
	void Physical::setRotationHead(float rotation_head)
	{
		m_physical_data.setRotationHead(rotation_head);
	}

	//Metoda obraca obiekt o zadany kąt (body)
	void Physical::rotateBody(float angle)
	{
		m_physical_data.rotateBody(angle);
	}

	//Metoda obraca obiekt o zadany kąt (head)
	void Physical::rotateHead(float angle)
	{
		m_physical_data.rotateHead(angle);
	}

	//Metoda obraca obiekt o zadany kąt (body and head)
	void Physical::rotate(float angle)
	{
		rotateBody(angle);
		rotateHead(angle);
	}

	//Metoda zwraca prędkość obiektu
	const sf::Vector2f & Physical::getVelocity() const
	{
		return m_physical_data.getVelocity();
	}

	//Metoda ustawia prędkość obiektu
	void Physical::setVelocity(const sf::Vector2f & velocity)
	{
		m_physical_data.setVelocity(velocity);
	}

	//Metoda zwraca promień detekcji wykorzystywany przy liczeniu kolizji
	float Physical::getCircleRadius()
	{
		return m_circle_radius;
	}

	//Metoda zwraca referencję na wyliczenie - typ liczenia kolizji
	ECollisionShape & Physical::getCollisionShape()
	{
		return m_collision_shape;
	}

	//Wirtualna metoda ustawiająca wartość promienia detekcji wykorzystywaną przy liczeniu kolizji
	void Physical::setBoundingCircle(float radius)
	{
		m_collision_shape = SHAPE_CIRCLE;
		m_circle_radius = radius;
		//obliczamy boki prostokąta (uproszczenie do kwadratu) wpisanego w okrag
		m_rect_size.x = m_rect_size.y = radius * 2.0f;
	}

	//Metoda ustawia wartość obszaru prostokątnego detekcji wykorzystywany przy liczeniu kolizji
	void Physical::setBoundingRect(const sf::Vector2f & rect_size)
	{
		m_collision_shape = SHAPE_RECT;
		m_rect_size = rect_size;
		//obliczamy przeciwprostokątną, czyli średnicę okręgu opisanego na prostokącie
		m_circle_radius =  sqrtf(rect_size.x * rect_size.x + rect_size.y * rect_size.y);
	}

	//Metoda zwraca wektor dla obszaru prostokątnego detekcji wykorzystywany przy liczeniu kolizji
	const sf::Vector2f & Physical::getRectSize() const
	{
		return m_rect_size;
	}

	//Metoda zwraca stałą referencję na wektor wielkości obiektu
	//wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
	const sf::Vector2f & Physical::getRectangleSizeBody() const
	{
		return m_rect_size_body;
	}

	//Metoda ustawia referencję na wektor wielkości obiektu
	//wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
	void Physical::setRectangleSizeBody(const sf::Vector2f & rect_size_body)
	{
		m_rect_size_body = rect_size_body;
	}

	//Metoda ustawia referencję na wektor wielkości obiektu
	//wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
	void Physical::setRectangleSizeBody(float rect_size_body_width, float rect_size_body_height)
	{
		m_rect_size_body.x = rect_size_body_width;
		m_rect_size_body.y = rect_size_body_height;
	}
	
	//Metoda zwraca stałą referencję na wektor wielkości obiektu
	//wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
	//klasy Displayable
	const sf::Vector2f & Physical::getRectangleSizeHead() const
	{
		return m_rect_size_head;
	}

	//Metoda ustawia referencję na wektor wielkości obiektu
	//wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
	//klasy Displayable
	void Physical::setRectangleSizeHead(const sf::Vector2f & rect_size_head)
	{
		m_rect_size_head = rect_size_head;
		m_rect_size_head = rect_size_head;
	}

	//Metoda ustawia referencję na wektor wielkości obiektu
	//wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
	//klasy Displayable
	void Physical::setRectangleSizeHead(float rect_size_head_width, float rect_size_head_height)
	{
		m_rect_size_head.x = rect_size_head_width;
	}

	//Metoda ustawia referencję na wektor wielkości obiektu
	//wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
	//klasy Displayable - body and head
	void Physical::setRectangleSize(const sf::Vector2f & rect_size_uniform)
	{
		m_rect_size_body = rect_size_uniform;
		m_rect_size_head = rect_size_uniform;
	}

	//Metoda ustawia referencję na wektor wielkości obiektu
	void Physical::setRectangleSize(float rect_size_uniform_width, float rect_size_uniform_height)
	{
		m_rect_size_body.x = rect_size_uniform_width;
		m_rect_size_body.y = rect_size_uniform_height;
		m_rect_size_head.x = rect_size_uniform_width;
		m_rect_size_head.y = rect_size_uniform_height;
	}

	//Metoda ustawia referencję na wektor wielkości obiektu
	//wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
	//klasy Displayable - body and head
	void Physical::setRectangleSize(const sf::Vector2f & rect_size_body, const sf::Vector2f & rect_size_head)
	{
		m_rect_size_body = rect_size_body;
		m_rect_size_head = rect_size_head;
	}

	//Metoda ustawia referencję na wektor wielkości obiektu
	//wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
	//klasy Displayable - body and head
	void Physical::setRectangleSize(float rect_size_body_width, float rect_size_body_height, float rect_size_head_width, float rect_size_head_height)
	{
		m_rect_size_body.x = rect_size_body_width;
		m_rect_size_body.y = rect_size_body_height;
		m_rect_size_head.x = rect_size_head_width;
		m_rect_size_head.y = rect_size_head_height;
	}

	//Metoda zwraca wartość pułapu obiektu
	const float Physical::getAltitude() const
	{
		return m_physical_data.getAltitude();
	}

	//Metoda ustawia wartość pułapu obiektu
	void Physical::setAltitude(float altitude)
	{
		if(altitude < 0) return;
		m_physical_data.setAltitude(altitude);
	}

	//Metoda zwraca kolor obiektu - body
	const sf::Color & Physical::getColor() const
	{
		return m_physical_data.getColorBody();	//umawiamy się, że default to część body
	}

	//Metoda ustawia kolor obiektu - (body and head)
	void Physical::setColor(const sf::Color & color)
	{
		m_physical_data.setColor(color);
	}

	//Metoda zwraca kolor obiektu - body
	const sf::Color & Physical::getColorBody() const
	{
		return m_physical_data.getColorBody();
	}

	//Metoda ustawia kolor obiektu - body
	void Physical::setColorBody(const sf::Color & color_body)
	{
		m_physical_data.setColorBody(color_body);
	}

	//Metoda zwraca kolor obiektu - head
	const sf::Color & Physical::getColorHead() const
	{
		return m_physical_data.getColorHead();
	}

	//Metoda ustawia kolor obiektu - head
	void Physical::setColorHead(const sf::Color & color_head)
	{
		m_physical_data.setColorHead(color_head);
	}

	//Metoda ustawia oryginalny kolor obiektu załadowany z tekstury - body and head
	void Physical::restoreColor()
	{
		m_physical_data.restoreColor();
	}

	//Metoda ustawia oryginalny kolor obiektu załadowany z tekstury - body
	void Physical::restoreColorBody()
	{
		m_physical_data.restoreColorBody();
	}

	//Metoda ustawia oryginalny kolor obiektu załadowany z tekstury - head
	void Physical::restoreColorHead()
	{
		m_physical_data.restoreColorHead();
	}

	//Metoda ustawia kolor do zapamiętania - body
	const sf::Color & Physical::getStoredColorBody() const
	{
		return m_physical_data.getStoredColorBody();
	}

	//Metoda ustawia kolor do zapamiętania - body
	void Physical::storeColorBody(const sf::Color & color_stored_body)
	{
		m_physical_data.storeColorBody(color_stored_body);
	}
	
	//Metoda ustawia kolor do zapamiętania - body
	const sf::Color & Physical::getStoredColorHead() const
	{
		return m_physical_data.getStoredColorHead();
	}

	//Metoda ustawia kolor do zapamiętania - body
	void Physical::storeColorHead(const sf::Color & color_stored_head)
	{
		m_physical_data.storeColorHead(color_stored_head);
	}

	//Metoda zwraca kolor cienia obiektu
	const sf::Color & Physical::getColorShadow() const
	{
		return m_physical_data.getColorShadow();
	}

	//Metoda ustawia kolor cienia obiektu
	void Physical::setColorShadow(const sf::Color & color_shadow)
	{
		m_physical_data.setColorShadow(color_shadow);
	}

	//Metoda zwraca wektor przesunięcia cienia względem obiektu - body
	sf::Vector2f & Physical::getShadowOffsetBody()
	{
		return m_physical_data.getShadowOffsetBody();
	}

	//Metoda ustawia wektor przesunięcia cienia względem obiektu - body
	void Physical::setShadowOffsetBody(sf::Vector2f & shadow_offset_body)
	{
		m_physical_data.setShadowOffsetBody(shadow_offset_body);
	}

	//Metoda zwraca wektor przesunięcia cienia względem obiektu - head
	sf::Vector2f & Physical::getShadowOffsetHead()
	{
		return m_physical_data.getShadowOffsetHead();
	}

	//Metoda ustawia wektor przesunięcia cienia względem obiektu - head
	void Physical::setShadowOffsetHead(sf::Vector2f & shadow_offset_head)
	{
		m_physical_data.setShadowOffsetHead(shadow_offset_head);
	}

	//Metoda zwraca flagę, czy obiekt generuje reprezentację graficzną (body and head) /zgodność interfejsu/
	const bool Physical::getUseDisplayable() const
	{
		return m_physical_data.getUseDisplayableBody();
	}

	//Metoda zwraca flagę, czy Physical ma reprezentację graficzą (body)
	const bool Physical::getUseDisplayableBody() const
	{
		return m_physical_data.getUseDisplayableBody();
	}

	//Metoda zwraca flagę, czy Physical ma reprezentację graficzą (head)
	const bool Physical::getUseDisplayableHead() const
	{
		return m_physical_data.getUseDisplayableHead();
	}

	//Metoda ustawia flagę, czy Physical ma reprezentację graficzą (body and head)
	void Physical::setUseDisplayable(const bool use_displayable)
	{
		m_physical_data.setUseDisplayable(use_displayable);
	}

	//Metoda ustawia flagę, czy Physical ma reprezentację graficzą (body)
	void Physical::setUseDisplayableBody(const bool use_displayable_body)
	{
		m_physical_data.setUseDisplayableBody(use_displayable_body);
	}

	//Metoda ustawia flagę, czy Physical ma reprezentację graficzą (head)
	void Physical::setUseDisplayableHead(const bool use_displayable_head)
	{
		m_physical_data.setUseDisplayableHead(use_displayable_head);
	}

	//Metoda zwraca flagę, czy obiekt generuje cień (body and head) /zgodność interfejsu/
	const bool Physical::getUseShadow() const
	{
		return m_physical_data.getUseShadowBody();
	}

	//Metoda zwraca flagę, czy obiekt generuje cień (body)
	const bool Physical::getUseShadowBody() const
	{
		return m_physical_data.getUseShadowBody();
	}

	//Metoda zwraca flagę, czy obiekt generuje cień (head)
	const bool Physical::getUseShadowHead() const
	{
		return m_physical_data.getUseShadowHead();
	}

	//Metoda ustawia flagę, czy obiekt ma generować cień (body and head) /zgodność interfejsu/
	void Physical::setUseShadow(const bool use_shadow)
	{
		m_physical_data.setUseShadow(use_shadow);
	}

	//Metoda ustawia flagę, czy obiekt ma generować cień (body)
	void Physical::setUseShadowBody(const bool use_shadow_body)
	{
		m_physical_data.setUseShadowBody(use_shadow_body);
	}

	//Metoda ustawia flagę, czy obiekt ma generować cień (head)
	void Physical::setUseShadowHead(const bool use_shadow_head)
	{
		m_physical_data.setUseShadowHead(use_shadow_head);
	}

	//Metoda zwraca wskaźnik na animację - obiekt klasy Animation (body)
	Animation *Physical::getAnimationBody()
	{
		return m_physical_data.getAnimationBody();
	}

	//Metoda ustawia ustawia wskaźnik na animację (body)
	void Physical::setAnimationBody(Animation* p_anim_body)
	{
		m_physical_data.setAnimationBody(p_anim_body);
	}

	//Metoda zwraca nazwę animacji (body)
	const std::string & Physical::getAnimationBodyName() const
	{
		return m_physical_data.getAnimationBodyName();
	}

	//Metoda ustawia nazwę animacji (body)
	void Physical::setAnimationBody(const std::string & anim_body_name)
	{
		m_physical_data.setAnimationBody(anim_body_name);
	}

	//Metoda zwraca wskaźnik na animację - obiekt klasy Animation (head)
	Animation *Physical::getAnimationHead()
	{
		return m_physical_data.getAnimationHead();
	}

	//Metoda ustawia ustawia wskaźnik na animację (head)
	void Physical::setAnimationHead(Animation *p_anim_head)
	{
		m_physical_data.setAnimationHead(p_anim_head);
	}

	//Metoda zwraca nazwę animacji (head)
	const std::string & Physical::getAnimationHeadName() const
	{
		return m_physical_data.getAnimationHeadName();
	}

	//Metoda ustawia nazwę animacji (head)
	void Physical::setAnimationHead(const std::string & anim_head_name)
	{
		m_physical_data.setAnimationHead(anim_head_name);
	}

	//Metoda ustawia komplet animacji
	void Physical::setAnimation(Animation *p_anim_body, Animation *p_anim_head)
	{
		setAnimationBody(p_anim_body);
		setAnimationHead(p_anim_head);
	}

	//Metoda ustawia komplet animacji
	void Physical::setAnimation(const std::string & anim_name_body, const std::string & anim_name_head)
	{
		setAnimationBody(anim_name_body);
		setAnimationHead(anim_name_head);
	}

	//Metoda zwraca pamiętany współczynnik prędkości odtwarzania animacji (body)
	const float Physical::getStoredAnimSpeedBody() const
	{
		return m_physical_data.getStoredAnimSpeedBody();
	}

	//Metoda zwraca pamiętany współczynnik prędkości odtwarzania animacji (body)
	const float Physical::getStoredAnimSpeedHead() const
	{
		return m_physical_data.getStoredAnimSpeedHead();
	}

	//Metoda zwraca współczynnik prędkości odtwarzania animacji 1.0f - normal speed (body)
	const float Physical::getAnimSpeedBody() const
	{
		return m_physical_data.getAnimSpeedBody();
	}

	//Metoda zwraca współczynnik prędkości odtwarzania animacji 1.0f - normal speed (head)
	const float Physical::getAnimSpeedHead() const
	{
		return m_physical_data.getAnimSpeedHead();
	}

	//Metoda ustawia współczynnik prędkości odtwarzania animacji 1.0f - normal speed (body)
	void Physical::setAnimSpeedBody(float anim_speed)
	{
		m_physical_data.setAnimSpeedBody(anim_speed);
	}

	//Metoda ustawia współczynnik prędkości odtwarzania animacji 1.0f - normal speed (head)
	void Physical::setAnimSpeedHead(float anim_speed)
	{
		m_physical_data.setAnimSpeedHead(anim_speed);
	}

	//Metoda ustawia współczynnik prędkości odtwarzania animacji 1.0f - normal speed (body and head)
	void Physical::setAnimSpeed(float anim_uniform_speed)
	{
		setAnimSpeedBody(anim_uniform_speed);
		setAnimSpeedHead(anim_uniform_speed);
	}

	//Metoda ustawia współczynnik prędkości odtwarzania animacji 1.0f - normal speed (body and head)
	void Physical::setAnimSpeed(float anim_speed_body, float anim_speed_head)
	{
		setAnimSpeedBody(anim_speed_body);
		setAnimSpeedHead(anim_speed_head);
	}

	//Metoda zwraca wskaźnik na obiekt klasy Displayable (body) /zgodność interfejsu/
	Displayable *Physical::getDisplayable()
	{
		return m_physical_data.getDisplayableBody();
	}

	//Metoda zwraca wskaźnik na obiekt klasy Displayable (shadow) /zgodność interfejsu/
	Displayable *Physical::getShadow()
	{
		return m_physical_data.getDisplayableBodyShadow();
	}

	//Metoda zwraca wskaźnik na obiekt klasy Displayable (body)
	Displayable *Physical::getDisplayable(EPhysicalPart physical_part)
	{
		if (physical_part == BODY)
			return m_physical_data.getDisplayableBody();
		else if (physical_part == HEAD)
			return m_physical_data.getDisplayableHead();
		return m_physical_data.getDisplayableBody();
	}

	//Metoda zwraca wskaźnik na obiekt klasy Displayable (shadow)
	Displayable *Physical::getShadow(EPhysicalPart physical_part)
	{
		if (physical_part == BODY)
			return m_physical_data.getDisplayableBodyShadow();
		else if (physical_part == HEAD)
			return m_physical_data.getDisplayableHead();
		return m_physical_data.getDisplayableBodyShadow();
	}

	//Metoda zwraca wskaźnik na obiekt klasy Displayable (body)
	Displayable *Physical::getDisplayableBody()
	{
		return m_physical_data.getDisplayableBody();
	}

	//Metoda zwraca wskaźnik na obiekt klasy Displayable (body shadow)
	Displayable *Physical::getDisplayableBodyShadow()
	{
		return m_physical_data.getDisplayableBodyShadow();
	}

	//Metoda zwraca wskaźnik na obiekt klasy Displayable (head)
	Displayable *Physical::getDisplayableHead()
	{
		return m_physical_data.getDisplayableHead();
	}

	//Metoda zwraca wskaźnik na obiekt klasy Displayable (head shadow)
	Displayable *Physical::getDisplayableHeadShadow()
	{
		return m_physical_data.getDisplayableHeadShadow();
	}

	//Metoda ustawia flagę dla obiektów gotowych do destrukcji
	void Physical::markForDelete()
	{
		m_ready_for_destruction = true;
	}

	//Wirtualna metoda zaznacza obiekty do destrukcji
	void Physical::kill()
	{
		markForDelete();
	}

	//Metoda zwraca flagę, czy obiekt jest gotowy do usuniecia
	bool Physical::isDead()
	{
		return m_ready_for_destruction;
	}

	//Metoda zwraca nazwę tekstury
	const std::string & Physical::getTextureBody() const
	{
		return m_physical_data.getTextureBody();
	}

	//Metoda ustatawia nazwę tekstury (body)
	void Physical::setTextureBody(const std::string & texture_body)
	{
		m_physical_data.setTextureBody(texture_body);
	}

	//Metoda zwraca nazwę tekstury (head)
	const std::string & Physical::getTextureHead() const
	{
		return m_physical_data.getTextureHead();
	}

	//Metoda ustatwia nazwę tekstury (head)
	void Physical::setTextureHead(const std::string & texture_head)
	{
		m_physical_data.setTextureHead(texture_head);
	}

	//Metoda generuje obraz tekstury
	void Physical::setTextureBody(unsigned width, unsigned height, const sf::Color & color)
	{
		m_physical_data.setTextureBody(width, height, color);
	}

	//Metoda generuje obraz tekstury
	void Physical::setTextureBody(unsigned width, unsigned height, unsigned r, unsigned g, unsigned b, unsigned a)
	{
		m_physical_data.setTextureBody(width, height, r, g, b, a);
	}

	//Metoda generuje obraz tekstury
	void Physical::setTextureHead(unsigned width, unsigned height, const sf::Color & color)
	{
		m_physical_data.setTextureHead(width, height, color);
	}

	//Metoda generuje obraz tekstury
	void Physical::setTextureHead(unsigned width, unsigned height, unsigned r, unsigned g, unsigned b, unsigned a)
	{
		m_physical_data.setTextureHead(width, height, r, g, b, a);
	}

	//Metoda zwraca tryb wygładzania tekstury
	const bool Physical::getSmoothing() const
	{
		return m_smooth;
	}

	//Metoda ustawia tryb wygładzania tekstury
	void Physical::setSmoothing(bool smooth)
	{
		m_smooth = smooth; //zapamietuję flagę wygładzania tekstury

		if(m_physical_data.getDisplayableBody())
			m_physical_data.getDisplayableBody()->setSmoothing(m_smooth);
		if(m_physical_data.getDisplayableBodyShadow())
			m_physical_data.getDisplayableBodyShadow()->setSmoothing(m_smooth);
		if(m_physical_data.getDisplayableHead())
			m_physical_data.getDisplayableHead()->setSmoothing(m_smooth);
		if(m_physical_data.getDisplayableHeadShadow())
			m_physical_data.getDisplayableHeadShadow()->setSmoothing(m_smooth);
	}

	//Metoda zwraca statyczny współczynnik wirtualnej wysokości obiektu
	const float Physical::getIncrease() const
	{
		return m_increase;
	}

	//Metoda ustawia statyczny współczynnik wirtualnej wysokości obiektu
	const void Physical::setIncrease(float increase) const
	{
		m_increase = increase;
	}

	//Metoda zwraca wskaźnik na obiekt klasy PhysicalTemplate
	PhysicalTemplate *Physical::getTemplate()const
	{
		return p_template;
	}

	//Metoda ustawia wskaźnik na obiekt klasy PhysicalTemplate
	void Physical::setTemplate(PhysicalTemplate *p_template_param)
	{
		p_template = p_template_param;
	}


	//Metoda zwraca opakowanie informacji o kolidowaniu
	PartCollisionData & Physical::getPartCollisionData()
	{
		return m_part_collision_data;
	}

	//Wirtualna metoda aktualizująca obiekt
	void Physical::update(float dt)
	{
		sf::Vector2f new_position;
		new_position.x = m_physical_data.getPosition().x + (dt * m_physical_data.getVelocity().x);
		new_position.y = m_physical_data.getPosition().y + (dt * m_physical_data.getVelocity().y);
		m_physical_data.setOldPosition(m_physical_data.getPosition());
		setPosition(new_position);
		updateShadow(dt);
	}

	//implementajca metod protected:

	//Metoda zwraca wyliczony współczynnik prędkości animacji dla zadanego czasu trwania jednego obiegu animacji
	const float Physical::getCalcualtedAnimSpeed(float anim_time)
	{
		if (anim_time > 0)
		{
			//wyliczenie nowego czasu odtwarzania pełnego obiegu animacji
			m_new_anim_speed = getAnimSpeedHead() / anim_time;
			//im krótszy czas trwania animacji, tym większa prędkość odtwarzania
			//im dłuższy czas trwania animacji, tym mniejsza prędkość odtwarzania
			//new_anim_speed_factor		= current_anim_speed / new_anim_total_time
			//anim_speed_factor_one		= 1 / 1.0000	=>	1.0000
			//anim_speed_factor_two		= 1 / 0.5000	=>	2.0000
			//anim_speed_factor_three	= 1 / 4.0000	=>	0.2500
			return m_new_anim_speed;
		}
		return getAnimSpeedHead();//zwracamy nienaruszone
	}


	//Metoda zwraca indeks warstwy renderingu obiektu (body)
	const int Physical::getZIndexBody() const
	{
		return m_physical_data.getZIndexBody();
	}

	//Metoda ustawia indeks warstwy renderingu obiektu (body)
	void Physical::setZIndexBody(int layer_index)
	{
		m_physical_data.setZIndexBody(layer_index);
	}

	//Metoda zwraca indeks warstwy renderingu obiektu (body shadow)
	const int Physical::getZIndexShadowBody() const
	{
		return m_physical_data.getZIndexShadowBody();
	}
	
	//Metoda ustawia indeks warstwy renderingu obiektu (body shadow)
	void Physical::setZIndexShadowBody(int layer_index)
	{
		m_physical_data.setZIndexShadowBody(layer_index);
	}

	//Metoda zwraca indeks warstwy renderingu obiektu (head)
	const int Physical::getZIndexHead() const
	{
		return m_physical_data.getZIndexHead();
	}

	//Metoda ustawia indeks warstwy renderingu obiektu (head)
	void Physical::setZIndexHead(int layer_index)
	{
		m_physical_data.setZIndexHead(layer_index);
	}

	//Metoda zwraca indeks warstwy renderingu obiektu (head shadow)
	const int Physical::getZIndexShadowHead() const
	{
		return m_physical_data.getZIndexShadowHead();
	}

	//Metoda ustawia indeks warstwy renderingu obiektu (head shadow)
	void Physical::setZIndexShadowHead(int layer_index)
	{
		m_physical_data.setZIndexShadowHead(layer_index);
	}

	//Metoda aktualizuje cień rzucany przez obiekt i jego nasycenie w zależności od pory dnia
	void Physical::updateShadow(float dt)
	{
		m_physical_data.updateShadowTransformation();
	}


	//implementajca metod private:

	//prywatna metoda sprawdza, czy trzeba utworzyć obiekt klasy Displayable
	void Physical::checkDisplayableBody()
	{
		m_physical_data.checkDisplayableBody();
	}

	//prywatna metoda sprawdza, czy trzeba utworzyć obiekt klasy Displayable
	void Physical::checkDisplayableHead()
	{
		m_physical_data.checkDisplayableHead();
	}

	//prywatna metoda dobierająca przesunięcie cienia
	//w zależności od wielkości obiektu - body and head
	//oraz jego nasycenie w zależności od pory dnia
	//pozycji słońca (źródła światła - gwiazd, etc...)
	void Physical::updateShadowTransformation()
	{
		m_physical_data.updateShadowTransformation();
	}

	//Metoda ustala wektor przesunięcia cienia - body
	void Physical::checkShadowOffsetBody()
	{
		m_physical_data.checkShadowOffsetBody();
	}

	//Metoda ustala wektor przesunięcia cienia - head
	void Physical::checkShadowOffsetHead()
	{
		m_physical_data.checkShadowOffsetHead();
	}

	//Metoda ustala wektor przesunięcia cienia - body and head
	void Physical::checkShadowOffset()
	{
		m_physical_data.checkShadowOffsetBody();
		m_physical_data.checkShadowOffsetHead();
	}

}//namespace logic

//Nadanie wartości stałym składowym statycznym
float logic::Physical::m_increase		= 0.33f;	//default - współczynnik wysokości (wzrostu) obiektu)
