//  _________________________________________
// | PhysicalData.cpp - class implementation |
// | Jack Flower - June 2016                 |
// |_________________________________________|
//

#include "PhysicalData.h"
#include "../../../Rendering/Displayable/Displayable.h"
#include "../../../Rendering/Drawable/DrawableManager.h"
#include "../../../Rendering/Animations/Animation.h"
#include "../../../Rendering/Animations/AnimationState.h"
#include "../../../Weather/CWeather.h"
#include "../../../Utilities/Utilities/Utilities.h"
#include <math.h>

using namespace rendering::drawable;
using namespace weather;

namespace physicaldata
{
	RTTI_IMPL_NOPARENT(PhysicalData);

	//Konstruktor
	PhysicalData::PhysicalData()
	:
		m_physics_data(),
		m_use_displayable_body(false),
		m_use_shadow_body(false),
		m_use_displayable_head(false),
		m_use_shadow_head(false),
		p_displayable_body(NULL),
		p_displayable_body_shadow(NULL),
		p_displayable_head(NULL),
		p_displayable_head_shadow(NULL),
		m_color_body(sf::Color()),
		m_color_head(sf::Color()),
		m_color_stored_body(sf::Color()),
		m_color_stored_head(sf::Color()),
		m_color_shadow(),
		m_shadow_offset_body(0.0f, 0.0f),
		m_shadow_offset_head(0.0f, 0.0f),
		p_animation_body(NULL),
		p_animation_head(NULL),
		m_anim_speed_body(1.0f),
		m_anim_speed_head(1.0f),
		m_stored_anim_speed_body(1.0f),
		m_stored_anim_speed_head(1.0f),
		m_z_index_body(Z_PHYSICAL_BODY),
		m_z_index_shadow_body(Z_PHYSICAL_SHADOWS_BODY),
		m_z_index_head(Z_PHYSICAL_HEAD),
		m_z_index_shadow_head(Z_PHYSICAL_SHADOWS_HEAD),
		p_synthetic_texture(NULL),
		p_synthetic_image(NULL),
		m_texture_body(),
		m_texture_head()
	{
		p_synthetic_texture = new RTexture();
		p_synthetic_image = new sf::Image;
	}

	//Konstruktor kopiujący
	PhysicalData::PhysicalData(const PhysicalData & PhysicalDataCopy)
	:
		m_physics_data(PhysicalDataCopy.m_physics_data),
		m_use_displayable_body(PhysicalDataCopy.m_use_displayable_body),
		m_use_shadow_body(PhysicalDataCopy.m_use_shadow_body),
		m_use_displayable_head(PhysicalDataCopy.m_use_displayable_head),
		m_use_shadow_head(PhysicalDataCopy.m_use_shadow_head),
		p_displayable_body(PhysicalDataCopy.p_displayable_body),
		p_displayable_body_shadow(PhysicalDataCopy.p_displayable_body),
		p_displayable_head(PhysicalDataCopy.p_displayable_body),
		p_displayable_head_shadow(PhysicalDataCopy.p_displayable_body),
		m_color_body(PhysicalDataCopy.m_color_body),
		m_color_head(PhysicalDataCopy.m_color_head),
		m_color_stored_body(PhysicalDataCopy.m_color_stored_body),
		m_color_stored_head(PhysicalDataCopy.m_color_stored_head),
		m_color_shadow(PhysicalDataCopy.m_color_shadow),
		m_shadow_offset_body(PhysicalDataCopy.m_shadow_offset_body),
		m_shadow_offset_head(PhysicalDataCopy.m_shadow_offset_head),
		p_animation_body(PhysicalDataCopy.p_animation_body),
		p_animation_head(PhysicalDataCopy.p_animation_head),
		m_anim_speed_body(PhysicalDataCopy.m_anim_speed_body),
		m_anim_speed_head(PhysicalDataCopy.m_anim_speed_head),
		m_stored_anim_speed_body(PhysicalDataCopy.m_stored_anim_speed_body),
		m_stored_anim_speed_head(PhysicalDataCopy.m_stored_anim_speed_head),
		m_z_index_body(PhysicalDataCopy.m_z_index_body),
		m_z_index_shadow_body(PhysicalDataCopy.m_z_index_shadow_body),
		m_z_index_head(PhysicalDataCopy.m_z_index_head),
		m_z_index_shadow_head(PhysicalDataCopy.m_z_index_shadow_head),
		p_synthetic_texture(NULL),
		p_synthetic_image(NULL),
		m_texture_body(PhysicalDataCopy.m_texture_body),
		m_texture_head(PhysicalDataCopy.m_texture_head)
	{
		p_synthetic_texture = new RTexture();
		p_synthetic_image = new sf::Image;
	}

	//Destruktor
	PhysicalData::~PhysicalData()
	{
		//m_physics_data
		m_use_displayable_body = false;
		m_use_shadow_body = false;
		m_use_displayable_head = false;
		m_use_shadow_head = false;

		if (p_displayable_body)
			gDrawableManager.destroyDrawable(p_displayable_body);

		if (p_displayable_body_shadow)
			gDrawableManager.destroyDrawable(p_displayable_body_shadow);

		if (p_displayable_head)
			gDrawableManager.destroyDrawable(p_displayable_head);

		if (p_displayable_head_shadow)
			gDrawableManager.destroyDrawable(p_displayable_head_shadow);

		p_displayable_body = NULL;
		p_displayable_body_shadow= NULL;
		p_displayable_head = NULL;
		p_displayable_head_shadow = NULL;
		//m_color_body
		//m_color_head
		//m_color_stored_body
		//m_color_stored_head
		//m_color_shadow
		m_shadow_offset_body.x = 0.0f;
		m_shadow_offset_body.y = 0.0f;
		m_shadow_offset_head.x = 0.0f;
		m_shadow_offset_head.y = 0.0f;
		p_animation_body = NULL;
		p_animation_head = NULL;
		m_anim_speed_body = 0.0f;
		m_anim_speed_head = 0.0f;
		m_stored_anim_speed_body = 0.0f;
		m_stored_anim_speed_head = 0.0f;
		m_z_index_body = 0;
		m_z_index_shadow_body = 0;
		m_z_index_head = 0;
		m_z_index_shadow_head = 0;

		if (p_synthetic_texture)
			delete p_synthetic_texture;
		p_synthetic_texture = NULL;

		if (p_synthetic_image)
			delete p_synthetic_image;
		p_synthetic_image = NULL;

		m_texture_body = "";
		m_texture_head = "";
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string PhysicalData::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca wagę
	const float PhysicalData::getWeight() const
	{
		return m_physics_data.getWeight();
	}

	//Metoda ustawia wagę
	void PhysicalData::setWeight(float weight)
	{
		if (weight < 0) return;
		m_physics_data.setWeight(weight);
	}

	//Metoda zwraca pozycję obiektu
	const sf::Vector2f & PhysicalData::getPosition() const
	{
		return m_physics_data.getPosition();
	}

	//Metoda ustawia pozycję obiektu
	void PhysicalData::setPosition(float x, float y, bool change_old_position)
	{
		//zakładamy, że body and head ma wspólny uchwyt
		m_physics_data.setPosition(x, y);	//aktualizacja pola w klasie (składowa wektora - x i y)

		//decorate
		if (p_displayable_body)
			p_displayable_body->setPosition(m_physics_data.getPosition().x, m_physics_data.getPosition().y);

		if (p_displayable_head)
			p_displayable_head->setPosition(m_physics_data.getPosition().x, m_physics_data.getPosition().y);

		if (p_displayable_body_shadow)
			p_displayable_body_shadow->setPosition(m_physics_data.getPosition().x + m_shadow_offset_body.x, m_physics_data.getPosition().y + m_shadow_offset_body.y);

		if (p_displayable_head_shadow)
			p_displayable_head_shadow->setPosition(m_physics_data.getPosition().x + m_shadow_offset_head.x, m_physics_data.getPosition().y + m_shadow_offset_head.y);

		if (change_old_position)
			m_physics_data.setOldPosition(x, y);
	}

	//Metoda ustawia pozycję obiektu
	void PhysicalData::setPosition(const sf::Vector2f & new_value, bool change_old_position)
	{
		//zakładamy, że body and head ma wspólny uchwyt
		m_physics_data.setPosition(new_value);	//aktualizacja pola w klasie (wektor)

		//decorate
		if (p_displayable_body)
			p_displayable_body->setPosition(m_physics_data.getPosition().x, m_physics_data.getPosition().y);

		if (p_displayable_head)
			p_displayable_head->setPosition(m_physics_data.getPosition().x, m_physics_data.getPosition().y);

		if (p_displayable_body_shadow)
			p_displayable_body_shadow->setPosition(m_physics_data.getPosition().x + m_shadow_offset_body.x, m_physics_data.getPosition().y + m_shadow_offset_body.y);

		if (p_displayable_head_shadow)
			p_displayable_head_shadow->setPosition(m_physics_data.getPosition().x + m_shadow_offset_head.x, m_physics_data.getPosition().y + m_shadow_offset_head.y);

		if (change_old_position)
			m_physics_data.setOldPosition(new_value);
	}

	//Metoda zwraca pozycję przed aktualizacją logiki m_old_position
	const sf::Vector2f & PhysicalData::getOldPosition() const
	{
		return m_physics_data.getOldPosition();
	}

	//Metoda zwraca pozycję przed aktualizacją logiki m_old_position
	void PhysicalData::setOldPosition(const sf::Vector2f & old_position)
	{
		m_physics_data.setOldPosition(old_position);
	}

	//Metoda ustawia pozycję obiektu
	void PhysicalData::setOldPosition(float x, float y, bool change_old_position)
	{
		m_physics_data.setOldPosition(x, y);
	}

	//Metoda zwraca prędkość obiektu
	const sf::Vector2f & PhysicalData::getVelocity() const
	{
		return m_physics_data.getVelocity();
	}

	//Metoda ustawia prędkość obiektu
	void PhysicalData::setVelocity(const sf::Vector2f & velocity)
	{
		m_physics_data.setVelocity(velocity);
	}

	//Metoda zwraca wartość pułapu obiektu
	const float PhysicalData::getAltitude() const
	{
		return m_physics_data.getAltitude();
	}

	//Metoda ustawia wartość pułapu obiektu
	void PhysicalData::setAltitude(float altitude)
	{
		if (altitude < 0) return;
		m_physics_data.setAltitude(altitude);
	}

	//Metoda zwraca flagę, czy obiekt ma reprezentację graficzną (body and head) /zgodność interfejsu/
	const bool PhysicalData::getUseDisplayable() const
	{
		return m_use_displayable_body;
	}

	//Metoda zwraca flagę, czy obiekt ma reprezentację graficzą (body)
	const bool PhysicalData::getUseDisplayableBody() const
	{
		return m_use_displayable_body;
	}

	//Metoda zwraca flagę, czy obiekt ma reprezentację graficzą (head)
	const bool PhysicalData::getUseDisplayableHead() const
	{
		return m_use_displayable_head;
	}

	//Metoda ustawia flagę, czy obiekt ma reprezentację graficzą (body and head)
	void PhysicalData::setUseDisplayable(const bool use_displayable)
	{
		m_use_displayable_body = use_displayable;
	}

	//Metoda ustawia flagę, czy obiekt ma reprezentację graficzą (body)
	void PhysicalData::setUseDisplayableBody(const bool use_displayable_body)
	{
		m_use_displayable_body = use_displayable_body;
	}

	//Metoda ustawia flagę, czy obiekt ma reprezentację graficzą (head)
	void PhysicalData::setUseDisplayableHead(const bool use_displayable_head)
	{
		m_use_displayable_head = use_displayable_head;
	}

	//Metoda zwraca flagę, czy obiekt generuje cień (body and head) /zgodność interfejsu/
	const bool PhysicalData::getUseShadow() const
	{
		return m_use_shadow_body;
	}

	//Metoda zwraca flagę, czy obiekt generuje cień (body)
	const bool PhysicalData::getUseShadowBody() const
	{
		return m_use_shadow_body;
	}

	//Metoda zwraca flagę, czy obiekt generuje cień (head)
	const bool PhysicalData::getUseShadowHead() const
	{
		return m_use_shadow_head;
	}

	//Metoda ustawia flagę, czy obiekt ma generować cień (body and head) /zgodność interfejsu/
	void PhysicalData::setUseShadow(const bool use_shadow)
	{
		m_use_shadow_body = m_use_shadow_body = use_shadow;
	}

	//Metoda ustawia flagę, czy obiekt ma generować cień (body)
	void PhysicalData::setUseShadowBody(const bool use_shadow_body)
	{
		m_use_shadow_body = use_shadow_body;
	}

	//Metoda ustawia flagę, czy obiekt ma generować cień (head)
	void PhysicalData::setUseShadowHead(const bool use_shadow_head)
	{
		m_use_shadow_head = use_shadow_head;
	}

	//Metoda zwraca wskaźnik na obiekt klasy Displayable (body) /zgodność interfejsu/
	Displayable *PhysicalData::getDisplayable()
	{
		return p_displayable_body;
	}

	//Metoda zwraca wskaźnik na obiekt klasy Displayable (body) /zgodność interfejsu/
	void PhysicalData::setDisplayable(Displayable *displayable)
	{
		p_displayable_body = displayable;
	}

	//Metoda zwraca wskaźnik na obiekt klasy Displayable (shadow) /zgodność interfejsu/
	Displayable *PhysicalData::getShadow()
	{
		return p_displayable_body_shadow;
	}

	//Metoda ustawia wskaźnik na obiekt klasy Displayable (body) /zgodność interfejsu/
	void PhysicalData::setShadow(Displayable *displayable_shadow)
	{
		p_displayable_body_shadow = displayable_shadow;
	}

	//Metoda zwraca wskaźnik na obiekt klasy Displayable (body)
	Displayable *PhysicalData::getDisplayable(EPhysicalPart physical_part)
	{
		if (physical_part == BODY)
			return p_displayable_body;
		else if (physical_part == HEAD)
			return p_displayable_head;
		return p_displayable_body;
	}

	//Metoda zwraca wskaźnik na obiekt klasy Displayable (shadow)
	Displayable *PhysicalData::getShadow(EPhysicalPart physical_part)
	{
		if (physical_part == BODY)
			return p_displayable_body_shadow;
		else if (physical_part == HEAD)
			return p_displayable_head_shadow;
		return p_displayable_body_shadow;
	}

	//Metoda zwraca wskaźnik na obiekt klasy Displayable (body)
	Displayable *PhysicalData::getDisplayableBody() const
	{
		return p_displayable_body;
	}

	//Metoda ustawia wskaźnik na obiekt klasy Displayable (body)
	void PhysicalData::setDisplayableBody(Displayable *displayable_body)
	{
		p_displayable_body = displayable_body;
	}

	//Metoda zwraca wskaźnik na obiekt klasy Displayable (body shadow)
	Displayable *PhysicalData::getDisplayableBodyShadow() const
	{
		return p_displayable_body_shadow;
	}

	//Metoda ustawia wskaźnik na obiekt klasy Displayable (body)
	void PhysicalData::setDisplayableBodyShadow(Displayable *displayable_body_shadow)
	{
		p_displayable_body_shadow = displayable_body_shadow;
	}

	//Metoda zwraca wskaźnik na obiekt klasy Displayable (head)
	Displayable *PhysicalData::getDisplayableHead() const
	{
		return p_displayable_head;
	}

	//Metoda ustawia wskaźnik na obiekt klasy Displayable (body)
	void PhysicalData::setDisplayableHead(Displayable *displayable_head)
	{
		p_displayable_head = displayable_head;
	}

	//Metoda zwraca wskaźnik na obiekt klasy Displayable (head shadow)
	Displayable *PhysicalData::getDisplayableHeadShadow() const
	{
		return p_displayable_head_shadow;
	}

	//Metoda ustawia wskaźnik na obiekt klasy Displayable (body)
	void PhysicalData::setDisplayableHeadShadow(Displayable *displayable_head_shadow)
	{
		p_displayable_head_shadow = displayable_head_shadow;
	}

	//Metoda zwraca kolor obiektu - body
	const sf::Color & PhysicalData::getColor() const
	{
		return m_color_body;	//umawiamy się, że default to część body
	}

	//Metoda ustawia kolor obiektu - (body and head)
	void PhysicalData::setColor(const sf::Color & color)
	{
		//przekazanie wartości koloru (body and head)
		m_color_body = color;
		m_color_head = color;

		//decorate
		if (p_displayable_body)
			p_displayable_body->setColor(color);

		//decorate
		if (p_displayable_head)
			p_displayable_head->setColor(color);
	}

	//Metoda zwraca kolor obiektu - body
	const sf::Color & PhysicalData::getColorBody() const
	{
		return m_color_body;
	}

	//Metoda ustawia kolor obiektu - body
	void PhysicalData::setColorBody(const sf::Color & color_body)
	{
		//przekazanie wartości koloru (body)
		m_color_body = color_body;

		//decorate
		if (p_displayable_body)
			p_displayable_body->setColor(color_body);
	}

	//Metoda zwraca kolor obiektu - head
	const sf::Color & PhysicalData::getColorHead() const
	{
		return m_color_head;
	}

	//Metoda ustawia kolor obiektu - head
	void PhysicalData::setColorHead(const sf::Color & color_head)
	{
		//przekazanie wartości koloru (head)
		m_color_head = color_head;

		//decorate
		if (p_displayable_head)
			p_displayable_head->setColor(color_head);
	}

	//Metoda ustawia oryginalny kolor obiektu załadowany z tekstury - body and head
	void PhysicalData::restoreColor()
	{
		m_color_body = m_color_stored_body;
		m_color_head = m_color_stored_head;

		//decorate
		if (p_displayable_body)
			p_displayable_body->setColor(m_color_body);

		//decorate
		if (p_displayable_head)
			p_displayable_head->setColor(m_color_head);
	}

	//Metoda ustawia oryginalny kolor obiektu załadowany z tekstury - body
	void PhysicalData::restoreColorBody()
	{
		m_color_body = m_color_stored_body;

		//decorate
		if (p_displayable_body)
			p_displayable_body->setColor(m_color_body);
	}

	//Metoda ustawia oryginalny kolor obiektu załadowany z tekstury - head
	void PhysicalData::restoreColorHead()
	{
		m_color_body = m_color_stored_body;

		//decorate
		if (p_displayable_head)
			p_displayable_head->setColor(m_color_body);
	}

	//Metoda ustawia kolor do zapamiętania - body
	const sf::Color & PhysicalData::getStoredColorBody() const
	{
		return m_color_stored_body;
	}

	//Metoda ustawia kolor do zapamiętania - body
	const sf::Color & PhysicalData::getStoredColorHead() const
	{
		return m_color_stored_head;
	}

	//Metoda ustawia kolor do zapamiętania - body
	void PhysicalData::storeColorBody(const sf::Color & color_stored_body)
	{
		m_color_stored_body = color_stored_body;
	}

	//Metoda ustawia kolor do zapamiętania - body
	void PhysicalData::storeColorHead(const sf::Color & color_stored_head)
	{
		m_color_stored_head = color_stored_head;
	}

	//Metoda zwraca kolor cienia obiektu
	const sf::Color & PhysicalData::getColorShadow() const
	{
		return m_color_shadow;
	}

	//Metoda ustawia kolor cienia obiektu
	void PhysicalData::setColorShadow(const sf::Color & color_shadow)
	{
		m_color_shadow = color_shadow;
	}

	//Metoda zwraca wektor przesunięcia cienia względem obiektu - body
	sf::Vector2f & PhysicalData::getShadowOffsetBody()
	{
		return m_shadow_offset_body;
	}

	//Metoda ustawia wektor przesunięcia cienia względem obiektu - body
	void PhysicalData::setShadowOffsetBody(sf::Vector2f & shadow_offset_body)
	{
		m_shadow_offset_body = shadow_offset_body;
	}

	//Metoda ustawia wektor przesunięcia cienia względem obiektu - body
	void PhysicalData::setShadowOffsetBody(float shadow_offset_body_x, float shadow_offset_body_y)
	{
		m_shadow_offset_body.x = shadow_offset_body_x;
		m_shadow_offset_body.y = shadow_offset_body_y;
	}

	//Metoda zwraca wektor przesunięcia cienia względem obiektu - head
	sf::Vector2f & PhysicalData::getShadowOffsetHead()
	{
		return m_shadow_offset_head;
	}

	//Metoda ustawia wektor przesunięcia cienia względem obiektu - head
	void PhysicalData::setShadowOffsetHead(sf::Vector2f & shadow_offset_head)
	{
		m_shadow_offset_head = shadow_offset_head;
	}

	//Metoda ustawia wektor przesunięcia cienia względem obiektu - hrad
	void PhysicalData::setShadowOffsetHead(float shadow_offset_head_x, float shadow_offset_head_y)
	{
		m_shadow_offset_head.x = shadow_offset_head_x;
		m_shadow_offset_head.y = shadow_offset_head_y;
	}
	
	//Metoda zwraca indeks warstwy renderingu obiektu (body)
	const int PhysicalData::getZIndexBody() const
	{
		return m_z_index_body;
	}

	//Metoda ustawia indeks warstwy renderingu obiektu (body)
	void PhysicalData::setZIndexBody(int layer_index)
	{
		//metoda rejestruje obiekt tylko wtedy, gdy parametr (int layer_index),
		//indeks warstwy, zmieniamy na inny niż w tej klasie (default jest to Z_PHYSICAL_BODY)
		//co może (powinno) być zaimplementowane w klasach pochodnych
		//oraz gdy wskaźnik jest zainicjowany
		if ((m_z_index_body != layer_index) && (p_displayable_body != NULL))
			gDrawableManager.registerDrawable(p_displayable_body, layer_index);
		
		//przekazanie
		m_z_index_body = layer_index;
		//decorate
		if (p_displayable_body)
			p_displayable_body->setLayerIndex(layer_index);
	}

	//Metoda zwraca indeks warstwy renderingu obiektu (body shadow)
	const int PhysicalData::getZIndexShadowBody() const
	{
		return m_z_index_shadow_body;
	}

	//Metoda ustawia indeks warstwy renderingu obiektu (body shadow)
	void PhysicalData::setZIndexShadowBody(int layer_index)
	{
		//metoda rejestruje obiekt tylko wtedy, gdy parametr (int layer_index),
		//indeks warstwy, zmieniamy na inny niż w tej klasie (default jest to Z_PHYSICAL_SHADOWS_BODY)
		//co może (powinno) być zaimplementowane w klasach pochodnych
		//oraz gdy wskaźnik jest zainicjowany
		if ((m_z_index_shadow_body != layer_index) && (p_displayable_body_shadow != NULL))
			gDrawableManager.registerDrawable(p_displayable_body_shadow, layer_index);
		
		//przekazanie
		m_z_index_shadow_body = layer_index;
		//decorate
		if (p_displayable_body_shadow)
			p_displayable_body_shadow->setLayerIndex(layer_index);
	}

	//Metoda zwraca indeks warstwy renderingu obiektu (head)
	const int PhysicalData::getZIndexHead() const
	{
		return m_z_index_head;
	}

	//Metoda ustawia indeks warstwy renderingu obiektu (head)
	void PhysicalData::setZIndexHead(int layer_index)
	{
		//metoda rejestruje obiekt tylko wtedy, gdy parametr (int layer_index),
		//indeks warstwy, zmieniamy na inny niż w tej klasie (default jest to Z_PHYSICAL_HEAD)
		//co może (powinno) być zaimplementowane w klasach pochodnych
		//oraz gdy wskaźnik jest zainicjowany
		if ((m_z_index_head != layer_index) && (p_displayable_head != NULL))
			gDrawableManager.registerDrawable(p_displayable_head, layer_index);

		//przekazanie
		m_z_index_head = layer_index;
		//decorate
		if (p_displayable_head)
			p_displayable_head->setLayerIndex(layer_index);
	}

	//Metoda zwraca indeks warstwy renderingu obiektu (head shadow)
	const int PhysicalData::getZIndexShadowHead() const
	{
		return m_z_index_shadow_head;
	}

	//Metoda ustawia indeks warstwy renderingu obiektu (head shadow)
	void PhysicalData::setZIndexShadowHead(int layer_index)
	{
		//metoda rejestruje obiekt tylko wtedy, gdy parametr (int layer_index),
		//indeks warstwy, zmieniamy na inny niż w tej klasie (default jest to Z_PHYSICAL_SHADOWS_HEAD)
		//co może (powinno) być zaimplementowane w klasach pochodnych
		//oraz gdy wskaźnik jest zainicjowany
		if ((m_z_index_shadow_head != layer_index) && (p_displayable_head_shadow != NULL))
			gDrawableManager.registerDrawable(p_displayable_head_shadow, layer_index);

		//przekazanie
		m_z_index_shadow_head = layer_index;
		//decorate
		if (p_displayable_head_shadow)
			p_displayable_head_shadow->setLayerIndex(layer_index);
	}

	//Metoda zwraca zapamiętaną skalę (body)
	const sf::Vector2f & PhysicalData::getStoredScaleBody() const
	{
		return m_physics_data.getStoredScaleBody();
	}

	//Metoda ustawia zapamiętaną skalę (body)
	void PhysicalData::setStoredScaleBody(float stored_scale_X, float stored_scale_Y)
	{
		m_physics_data.setStoredScaleBody(stored_scale_X, stored_scale_Y);
	}

	//Metoda ustawia zapamiętaną skalę (body)
	void PhysicalData::setStoredScaleBody(const sf::Vector2f & stored_scale_vector)
	{
		m_physics_data.setStoredScaleBody(stored_scale_vector);
	}

	//Metoda zwraca zapamiętaną skalę (body)
	const sf::Vector2f & PhysicalData::getStoredScaleHead() const
	{
		return m_physics_data.getStoredScaleHead();
	}

	//Metoda ustawia zapamiętaną skalę (head)
	void PhysicalData::setStoredScaleHead(float stored_scale_X, float stored_scale_Y)
	{
		m_physics_data.setStoredScaleHead(stored_scale_X, stored_scale_Y);
	}

	//Metoda ustawia zapamiętaną skalę (head)
	void PhysicalData::setStoredScaleHead(const sf::Vector2f & stored_scale_vector)
	{
		m_physics_data.setStoredScaleHead(stored_scale_vector);
	}

	//Metoda ustawia zapamiętaną skalę (body and head)
	void PhysicalData::setStoredScale(float stored_scale_X, float stored_scale_Y)
	{
		m_physics_data.setStoredScaleBody(stored_scale_X, stored_scale_Y);
		m_physics_data.setStoredScaleHead(stored_scale_X, stored_scale_Y);
	}

	//Metoda ustawia zapamiętaną skalę (body and head)
	void PhysicalData::setStoredScale(const sf::Vector2f & stored_scale)
	{
		m_physics_data.setStoredScaleBody(stored_scale);
		m_physics_data.setStoredScaleHead(stored_scale);
	}

	//Metoda ustawia zapamiętaną skalę (body and head)
	void PhysicalData::setStoredScale(float stored_uniform)
	{
		m_physics_data.setStoredScaleBody(stored_uniform, stored_uniform);
		m_physics_data.setStoredScaleHead(stored_uniform, stored_uniform);
	}

	//Metoda zwraca wartość obrotu obiektu w stopniach
	const float PhysicalData::getRotation() const
	{
		return m_physics_data.getRotation();
	}

	//Metoda ustawia wartość obrotu obiektu w stopniach (body and head)
	void PhysicalData::setRotation(float rotation)
	{
		m_physics_data.setRotation(rotation);
	}

	//Metoda zwraca wartość obrotu obiektu w stopniach (body)
	const float PhysicalData::getRotationBody() const
	{
		return m_physics_data.getRotationBody();
	}

	//Metoda ustawia wartość obrotu obiektu w stopniach (body)
	void PhysicalData::setRotationBody(float rotation_body)
	{
		m_physics_data.setRotationBody(rotation_body);

		//decorate
		if (p_displayable_body)
			p_displayable_body->setRotation(rotation_body);

		//decorate
		if (p_displayable_body_shadow)
			p_displayable_body_shadow->setRotation(rotation_body);
	}

	//Metoda zwraca wartość obrotu obiektu w stopniach (head)
	const float PhysicalData::getRotationHead() const
	{
		return m_physics_data.getRotationHead();
	}

	//Metoda ustawia wartość obrotu obiektu w stopniach (head)
	void PhysicalData::setRotationHead(float rotation_head)
	{
		m_physics_data.setRotationHead(rotation_head);

		//decorate
		if (p_displayable_head)
			p_displayable_head->setRotation(rotation_head);

		//decorate
		if (p_displayable_head_shadow)
			p_displayable_head_shadow->setRotation(rotation_head);
	}

	//Metoda obraca obiekt o zadany kąt (body)
	void PhysicalData::rotateBody(float angle)
	{
		m_physics_data.setRotationBody(angle);

		//decorate
		if (p_displayable_body)
			p_displayable_body->rotate(angle);

		//decorate
		if (p_displayable_body_shadow)
			p_displayable_body_shadow->rotate(angle);
	}

	//Metoda obraca obiekt o zadany kąt (head)
	void PhysicalData::rotateHead(float angle)
	{
		m_physics_data.setRotationHead(angle);

		//decorate
		if (p_displayable_head)
			p_displayable_head->rotate(angle);

		//decorate
		if (p_displayable_head_shadow)
			p_displayable_head_shadow->rotate(angle);
	}

	//Metoda obraca obiekt o zadany kąt (body and head)
	void PhysicalData::rotate(float angle)
	{
		rotateBody(angle);
		rotateHead(angle);
	}

	//Metoda zwraca wskaźnik na animację - obiekt klasy Animation (body)
	Animation *PhysicalData::getAnimationBody()
	{
		return p_animation_body;
	}

	//Metoda ustawia ustawia wskaźnik na animację (body)
	void PhysicalData::setAnimationBody(Animation* p_anim_body)
	{
		checkDisplayableBody();
		p_animation_body = p_anim_body;

		if (p_displayable_body)
			p_displayable_body->setAnimation(p_animation_body);

		if (p_displayable_body_shadow)
			p_displayable_body_shadow->setAnimation(p_animation_body);
	}

	//Metoda zwraca nazwę animacji (body)
	const std::string & PhysicalData::getAnimationBodyName() const
	{
		return p_displayable_body->getAnimationState()->getAnimation()->getAnimationName();
	}

	//Metoda ustawia nazwę animacji (body)
	void PhysicalData::setAnimationBody(const std::string & anim_body_name)
	{
		checkDisplayableBody();

		if (p_displayable_body)
			p_displayable_body->setAnimation(anim_body_name);

		if (p_displayable_body_shadow)
			p_displayable_body_shadow->setAnimation(anim_body_name);

		//po załadowaniu animacji (parametr std::string), aktualizacja wskaźnika
		if (p_displayable_body)
			p_animation_body = p_displayable_body->getAnimationState()->getAnimation();
	}

	//Metoda zwraca wskaźnik na animację - obiekt klasy Animation (head)
	Animation *PhysicalData::getAnimationHead()
	{
		return p_animation_head;
	}

	//Metoda ustawia ustawia wskaźnik na animację (head)
	void PhysicalData::setAnimationHead(Animation *p_anim_head)
	{
		checkDisplayableHead();

		p_animation_head = p_anim_head;

		if (p_displayable_head)
			p_displayable_head->setAnimation(p_animation_head);

		if (p_displayable_head_shadow)
			p_displayable_head_shadow->setAnimation(p_animation_head);
	}

	//Metoda zwraca nazwę animacji (head)
	const std::string & PhysicalData::getAnimationHeadName() const
	{
		return p_displayable_head->getAnimationState()->getAnimation()->getAnimationName();
	}

	//Metoda ustawia nazwę animacji (head)
	void PhysicalData::setAnimationHead(const std::string & anim_head_name)
	{
		checkDisplayableHead();

		if (p_displayable_head)
			p_displayable_head->setAnimation(anim_head_name);

		if (p_displayable_head_shadow)
			p_displayable_head_shadow->setAnimation(anim_head_name);

		//po załadowaniu animacji (parametr std::string), aktualizacja wskaźnika
		if (p_displayable_head)
			p_animation_head = p_displayable_head->getAnimationState()->getAnimation();
	}

	//Metoda ustawia komplet animacji
	void PhysicalData::setAnimation(Animation *p_anim_body, Animation *p_anim_head)
	{
		setAnimationBody(p_anim_body);
		setAnimationHead(p_anim_head);
	}

	//Metoda ustawia komplet animacji
	void PhysicalData::setAnimation(const std::string & anim_name_body, const std::string & anim_name_head)
	{
		setAnimationBody(anim_name_body);
		setAnimationHead(anim_name_head);
	}

	//Metoda zwraca pamiętany współczynnik prędkości odtwarzania animacji (body)
	const float PhysicalData::getStoredAnimSpeedBody() const
	{
		return m_stored_anim_speed_body;
	}

	//Metoda zwraca pamiętany współczynnik prędkości odtwarzania animacji (body)
	const float PhysicalData::getStoredAnimSpeedHead() const
	{
		return m_stored_anim_speed_head;
	}

	//Metoda zwraca współczynnik prędkości odtwarzania animacji 1.0f - normal speed (body)
	const float PhysicalData::getAnimSpeedBody() const
	{
		return m_anim_speed_body;
	}

	//Metoda zwraca współczynnik prędkości odtwarzania animacji 1.0f - normal speed (head)
	const float PhysicalData::getAnimSpeedHead() const
	{
		return m_anim_speed_head;
	}

	//Metoda ustawia współczynnik prędkości odtwarzania animacji 1.0f - normal speed (body)
	void PhysicalData::setAnimSpeedBody(float anim_speed)
	{
		m_anim_speed_body = anim_speed;
		if (p_displayable_body)
			p_displayable_body->getAnimationState()->setAnimSpeed(m_anim_speed_body);
		if (p_displayable_body_shadow)
			p_displayable_body_shadow->getAnimationState()->setAnimSpeed(m_anim_speed_head);
	}

	//Metoda ustawia współczynnik prędkości odtwarzania animacji 1.0f - normal speed (head)
	void PhysicalData::setAnimSpeedHead(float anim_speed)
	{
		m_anim_speed_head = anim_speed;
		if (p_displayable_head)
			p_displayable_head->getAnimationState()->setAnimSpeed(m_anim_speed_head);
		if(p_displayable_head_shadow)
			p_displayable_head_shadow->getAnimationState()->setAnimSpeed(m_anim_speed_head);
	}

	//Metoda ustawia współczynnik prędkości odtwarzania animacji 1.0f - normal speed (body and head)
	void PhysicalData::setAnimSpeed(float anim_uniform_speed)
	{
		setAnimSpeedBody(anim_uniform_speed);
		setAnimSpeedHead(anim_uniform_speed);
	}

	//Metoda ustawia współczynnik prędkości odtwarzania animacji 1.0f - normal speed (body and head)
	void PhysicalData::setAnimSpeed(float anim_speed_body, float anim_speed_head)
	{
		setAnimSpeedBody(anim_speed_body);
		setAnimSpeedHead(anim_speed_head);
	}

	//Metoda sprawdza, czy trzeba utworzyć obiekt klasy Displayable (body)
	//np. gdy chcemy dodać obrazek, animację, etc...
	void PhysicalData::checkDisplayableBody()
	{
		//body - oryginal
		if ((m_use_displayable_body) && (!p_displayable_body))
		{
			p_displayable_body = gDrawableManager.createDisplayable(getZIndexBody());
			if (!p_displayable_body)
			{
				fprintf(stderr, "error: PhysicalData::CheckDisplayable, p_displayable_body null, returning\n");
				return;
			}

			//transformacja
			p_displayable_body->setPosition(m_physics_data.getPosition());
			p_displayable_body->setRotation(m_physics_data.getRotationBody());
			p_displayable_body->setColor(p_displayable_body->getColor());
			p_displayable_body->setScale(m_physics_data.getStoredScaleBody());
			//zapamiętujemy oryginalny kolor
			m_color_stored_body = p_displayable_body->getColor();
		}

		//body - shadow
		if ((m_use_shadow_body) && (!p_displayable_body_shadow))
		{
			p_displayable_body_shadow = gDrawableManager.createDisplayable(getZIndexShadowBody());
			if (!p_displayable_body_shadow)
			{
				fprintf(stderr, "error: PhysicalData::CheckDisplayable, p_displayable_body_shadow null, returning\n");
				return;
			}

			//transformacja
			p_displayable_body_shadow->setPosition
			(
				m_physics_data.getPosition().x + m_shadow_offset_body.x,
				m_physics_data.getPosition().y + m_shadow_offset_body.y
			);

			p_displayable_body_shadow->setRotation(m_physics_data.getRotationBody());
			p_displayable_body_shadow->setColor(gWeather.GetShadowColor());
			p_displayable_body_shadow->setScale(m_physics_data.getStoredScaleBody());
		}
	}

	//Metoda sprawdza, czy trzeba utworzyć obiekt klasy Displayable (head)
	//np. gdy chcemy dodać obrazek, animację, etc...
	void PhysicalData::checkDisplayableHead()
	{
		//head - oryginal
		if ((m_use_displayable_head) && (!p_displayable_head))
		{
			p_displayable_head = gDrawableManager.createDisplayable(getZIndexHead());
			if (!p_displayable_head)
			{
				fprintf(stderr, "error: PhysicalData::CheckDisplayable, p_displayable_head null, returning\n");
				return;
			}

			//transformacja
			p_displayable_head->setPosition(m_physics_data.getPosition());
			p_displayable_head->setRotation(m_physics_data.getRotationHead());
			p_displayable_head->setColor(p_displayable_head->getColor());
			p_displayable_head->setScale(m_physics_data.getStoredScaleHead());
			//zapamiętujemy oryginalny kolor
			m_color_stored_head = p_displayable_head->getColor();
		}

		//head - shadow
		if ((m_use_shadow_head) && (!p_displayable_head_shadow))
		{
			p_displayable_head_shadow = gDrawableManager.createDisplayable(getZIndexShadowHead());
			if (!p_displayable_head_shadow)
			{
				fprintf(stderr, "error: PhysicalData::CheckDisplayable, p_displayable_head_shadow null, returning\n");
				return;
			}

			//transformacja
			p_displayable_head_shadow->setPosition
			(
				m_physics_data.getPosition().x + m_shadow_offset_head.x,
				m_physics_data.getPosition().y + m_shadow_offset_head.y
			);

			p_displayable_head_shadow->setRotation(m_physics_data.getRotationHead());
			p_displayable_head_shadow->setColor(gWeather.GetShadowColor());
			p_displayable_head_shadow->setScale(m_physics_data.getStoredScaleHead());
		}
	}

	//Metoda ustala wektor przesunięcia cienia - body
	void PhysicalData::checkShadowOffsetBody()
	{
		if (m_use_shadow_body)
		{
			//wektor przesunięcia cienia - body
			m_shadow_offset_body.x = p_displayable_body->getLocalBounds().width;
			m_shadow_offset_body.y = p_displayable_body->getLocalBounds().height;

			//wybieram krótszą składową wektora do obliczeń
			if (m_shadow_offset_body.x >= m_shadow_offset_body.y)
				m_shadow_offset_body.x = m_shadow_offset_body.y;
			else
				m_shadow_offset_body.y = m_shadow_offset_body.x;

			//transformacja
			setShadowOffsetBody
			(
				m_shadow_offset_body.x
				* PhysicalData::m_shadow_init
				* m_physics_data.getAltitude() * p_displayable_body->getScale().x,
				m_shadow_offset_body.y
				* PhysicalData::m_shadow_init
				* m_physics_data.getAltitude() * p_displayable_body->getScale().y
			);
		}
	}

	//Metoda ustala wektor przesunięcia cienia - head
	void PhysicalData::checkShadowOffsetHead()
	{
		if (m_use_shadow_head)
		{
			//wektor przesunięcia cienia - head
			m_shadow_offset_head.x = p_displayable_head->getLocalBounds().width;
			m_shadow_offset_head.y = p_displayable_head->getLocalBounds().height;

			//wybieram krótszą składową wektora do obliczeń
			if (m_shadow_offset_head.x >= m_shadow_offset_head.y)
				m_shadow_offset_head.x = m_shadow_offset_head.y;
			else
				m_shadow_offset_head.y = m_shadow_offset_head.x;

			//transformacja
			setShadowOffsetHead
			(
				m_shadow_offset_head.x
				* PhysicalData::m_shadow_init
				* m_physics_data.getAltitude() * p_displayable_head->getScale().x,
				m_shadow_offset_head.y
				* PhysicalData::m_shadow_init
				* m_physics_data.getAltitude() * p_displayable_head->getScale().y
			);
		}
	}

	//Metoda ustala wektor przesunięcia cienia - body and head
	void PhysicalData::checkShadowOffset()
	{
		checkShadowOffsetBody();
		checkShadowOffsetHead();
	}

	//Metoda aktualizuje transformację cienia
	void PhysicalData::updateShadowTransformation()
	{
		//ustawiamy kolor cienia
		setColorShadow(gWeather.GetShadowColor());

		//offset body
		if (p_displayable_body)
		{
			//shadow position body
			if (m_use_displayable_body)
				if (p_displayable_body_shadow)
				{
					checkShadowOffsetBody();//aktualizacja shadow offset - body
					p_displayable_body_shadow->setPosition
					(
						p_displayable_body->getPosition().x
						+ (m_shadow_offset_body.x
						* cos(gWeather.getAngleSun()
						* (float)RADIANS_PER_DEGREE)),
						p_displayable_body->getPosition().y
						+ (m_shadow_offset_body.y
						* sin(gWeather.getAngleSun()
						* (float)RADIANS_PER_DEGREE))
					);
					//shadow color body
					p_displayable_body_shadow->setColor(getColorShadow());
				}
		}

		//offset head
		if (p_displayable_head)
		{
			//shadow position head
			if (m_use_displayable_head)
				if (p_displayable_head_shadow)
				{
					checkShadowOffsetHead();//aktualizacja shadow offset - head
					p_displayable_head_shadow->setPosition
					(
						p_displayable_head->getPosition().x
						+ (m_shadow_offset_head.x
						* cos(gWeather.getAngleSun()
						* (float)RADIANS_PER_DEGREE)),
						p_displayable_head->getPosition().y
						+ (m_shadow_offset_head.y
						* sin(gWeather.getAngleSun()
						* (float)RADIANS_PER_DEGREE))
					);
					//shadow color head
					p_displayable_head_shadow->setColor(getColorShadow());
				}
		}
	}

	//Metoda zwraca nazwę tekstury
	const std::string & PhysicalData::getTextureBody() const
	{
		return m_texture_body;
	}

	//Metoda ustatawia nazwę tekstury (body)
	void PhysicalData::setTextureBody(const std::string & texture_body)
	{
		m_texture_body = texture_body;

		checkDisplayableBody();

		if (p_displayable_body)
			p_displayable_body->setTexture(m_texture_body);

		if (p_displayable_body_shadow)
			p_displayable_body_shadow->setTexture(m_texture_body);
	}

	//Metoda zwraca nazwę tekstury (head)
	const std::string & PhysicalData::getTextureHead() const
	{
		return m_texture_head;
	}

	//Metoda ustatwia nazwę tekstury (head)
	void PhysicalData::setTextureHead(const std::string & texture_head)
	{
		m_texture_head = texture_head;

		checkDisplayableHead();

		if (p_displayable_head)
			p_displayable_head->setTexture(texture_head);

		if (p_displayable_head_shadow)
			p_displayable_head_shadow->setTexture(texture_head);
	}

	//Metoda generuje obraz tekstury
	void PhysicalData::setTextureBody(unsigned width, unsigned height, const sf::Color & color)
	{
		checkDisplayableBody();
		if (p_displayable_body)
			p_displayable_body->setTexture(width, height, color);
	}

	//Metoda generuje obraz tekstury
	void PhysicalData::setTextureBody(unsigned width, unsigned height, unsigned r, unsigned g, unsigned b, unsigned a)
	{
		checkDisplayableBody();
		if (p_displayable_body)
			p_displayable_body->setTexture(width, height, r, g, b, a);
	}

	//Metoda generuje obraz tekstury
	void PhysicalData::setTextureHead(unsigned width, unsigned height, const sf::Color & color)
	{
		checkDisplayableHead();
		if (p_displayable_head)
			p_displayable_head->setTexture(width, height, color);
	}

	//Metoda generuje obraz tekstury
	void PhysicalData::setTextureHead(unsigned width, unsigned height, unsigned r, unsigned g, unsigned b, unsigned a)
	{
		checkDisplayableHead();
		if (p_displayable_head)
			p_displayable_head->setTexture(width, height, r, g, b, a);
	}

}//namespace physicaldata

//Nadanie wartości stałym składowym statycznym
float physicaldata::PhysicalData::m_shadow_init = 0.125f;	//default - współczynnik przesunięcia cienia obiektu (offset)
