//  __________________________________________
// | CPhysicalData.cpp - class implementation |
// | Jack Flower - June 2016                  |
// |__________________________________________|
//

#include "CPhysicalData.h"
#include "../../../Rendering/Displayable/CDisplayable.h"
#include "../../../Rendering/Drawable/CDrawableManager.h"
#include "../../../Rendering/Animations/CAnimation.h"
#include "../../../Rendering/Animations/CAnimationState.h"
#include "../../../Weather/CWeather.h"
#include "../../../Utilities/Utilities/Utilities.h"
#include <math.h>

using namespace rendering::drawable;
using namespace weather;

namespace physicaldata
{
	RTTI_IMPL_NOPARENT(CPhysicalData);

	//Konstruktor
	CPhysicalData::CPhysicalData()
	:
		m_physics_data				(),
		m_use_displayable_body		(false),
		m_use_shadow_body			(false),
		m_use_displayable_head		(false),
		m_use_shadow_head			(false),
		p_displayable_body			(NULL),
		p_displayable_body_shadow	(NULL),
		p_displayable_head			(NULL),
		p_displayable_head_shadow	(NULL),
		m_color_body				(sf::Color()),
		m_color_head				(sf::Color()),
		m_color_stored_body			(sf::Color()),
		m_color_stored_head			(sf::Color()),
		m_color_shadow				(),
		m_shadow_offset_body		(0.0f, 0.0f),
		m_shadow_offset_head		(0.0f, 0.0f),
		p_animation_body			(NULL),
		p_animation_head			(NULL),
		m_anim_speed_body			(1.0f),
		m_anim_speed_head			(1.0f),
		m_stored_anim_speed_body	(1.0f),
		m_stored_anim_speed_head	(1.0f),
		m_z_index_body				(Z_PHYSICAL_BODY),
		m_z_index_shadow_body		(Z_PHYSICAL_SHADOWS_BODY),
		m_z_index_head				(Z_PHYSICAL_HEAD),
		m_z_index_shadow_head		(Z_PHYSICAL_SHADOWS_HEAD),
		p_synthetic_texture			(NULL),
		p_synthetic_image			(NULL),
		m_texture_body				(),
		m_texture_head				()
	{
		p_synthetic_texture = new CTexture();
		p_synthetic_image = new sf::Image;
	}

	//Konstruktor kopiuj¹cy
	CPhysicalData::CPhysicalData(const CPhysicalData & CPhysicalDataCopy)
	:
		m_physics_data				(CPhysicalDataCopy.m_physics_data),
		m_use_displayable_body		(CPhysicalDataCopy.m_use_displayable_body),
		m_use_shadow_body			(CPhysicalDataCopy.m_use_shadow_body),
		m_use_displayable_head		(CPhysicalDataCopy.m_use_displayable_head),
		m_use_shadow_head			(CPhysicalDataCopy.m_use_shadow_head),
		p_displayable_body			(CPhysicalDataCopy.p_displayable_body),
		p_displayable_body_shadow	(CPhysicalDataCopy.p_displayable_body),
		p_displayable_head			(CPhysicalDataCopy.p_displayable_body),
		p_displayable_head_shadow	(CPhysicalDataCopy.p_displayable_body),
		m_color_body				(CPhysicalDataCopy.m_color_body),
		m_color_head				(CPhysicalDataCopy.m_color_head),
		m_color_stored_body			(CPhysicalDataCopy.m_color_stored_body),
		m_color_stored_head			(CPhysicalDataCopy.m_color_stored_head),
		m_color_shadow				(CPhysicalDataCopy.m_color_shadow),
		m_shadow_offset_body		(CPhysicalDataCopy.m_shadow_offset_body),
		m_shadow_offset_head		(CPhysicalDataCopy.m_shadow_offset_head),
		p_animation_body			(CPhysicalDataCopy.p_animation_body),
		p_animation_head			(CPhysicalDataCopy.p_animation_head),
		m_anim_speed_body			(CPhysicalDataCopy.m_anim_speed_body),
		m_anim_speed_head			(CPhysicalDataCopy.m_anim_speed_head),
		m_stored_anim_speed_body	(CPhysicalDataCopy.m_stored_anim_speed_body),
		m_stored_anim_speed_head	(CPhysicalDataCopy.m_stored_anim_speed_head),
		m_z_index_body				(CPhysicalDataCopy.m_z_index_body),
		m_z_index_shadow_body		(CPhysicalDataCopy.m_z_index_shadow_body),
		m_z_index_head				(CPhysicalDataCopy.m_z_index_head),
		m_z_index_shadow_head		(CPhysicalDataCopy.m_z_index_shadow_head),
		p_synthetic_texture			(NULL),
		p_synthetic_image			(NULL),
		m_texture_body				(CPhysicalDataCopy.m_texture_body),
		m_texture_head				(CPhysicalDataCopy.m_texture_head)
	{
		p_synthetic_texture = new CTexture();
		p_synthetic_image = new sf::Image;
	}

	//Destruktor
	CPhysicalData::~CPhysicalData()
	{
		//m_physics_data			not edit
		m_use_displayable_body		= false;
		m_use_shadow_body			= false;
		m_use_displayable_head		= false;
		m_use_shadow_head			= false;

		if (p_displayable_body)
			gDrawableManager.DestroyDrawable(p_displayable_body);

		if (p_displayable_body_shadow)
			gDrawableManager.DestroyDrawable(p_displayable_body_shadow);

		if (p_displayable_head)
			gDrawableManager.DestroyDrawable(p_displayable_head);

		if (p_displayable_head_shadow)
			gDrawableManager.DestroyDrawable(p_displayable_head_shadow);

		p_displayable_body			= NULL;
		p_displayable_body_shadow	= NULL;
		p_displayable_head			= NULL;
		p_displayable_head_shadow	= NULL;
		//m_color_body				not edit
		//m_color_head				not edit
		//m_color_stored_body		not edit
		//m_color_stored_head		not edit
		//m_color_shadow			not edit
		m_shadow_offset_body.x		= 0.0f;
		m_shadow_offset_body.y		= 0.0f;
		m_shadow_offset_head.x		= 0.0f;
		m_shadow_offset_head.y		= 0.0f;
		p_animation_body			= NULL;
		p_animation_head			= NULL;
		m_anim_speed_body			= 0.0f;
		m_anim_speed_head			= 0.0f;
		m_stored_anim_speed_body	= 0.0f;
		m_stored_anim_speed_head	= 0.0f;
		m_z_index_body				= 0;
		m_z_index_shadow_body		= 0;
		m_z_index_head				= 0;
		m_z_index_shadow_head		= 0;

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
	const std::string CPhysicalData::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca wagê
	const float CPhysicalData::getWeight() const
	{
		return m_physics_data.getWeight();
	}

	//Metoda ustawia wagê
	void CPhysicalData::setWeight(float weight)
	{
		if (weight < 0) return;
		m_physics_data.setWeight(weight);
	}

	//Metoda zwraca pozycjê obiektu
	const sf::Vector2f & CPhysicalData::GetPosition() const
	{
		return m_physics_data.GetPosition();
	}

	//Metoda ustawia pozycjê obiektu
	void CPhysicalData::SetPosition(float x, float y, bool change_old_position)
	{
		//zak³adamy, ¿e body and head ma wspólny uchwyt
		m_physics_data.SetPosition(x, y);	//aktualizacja pola w klasie (sk³adowa wektora - x i y)

		//decorate
		if (p_displayable_body)
			p_displayable_body->setPosition(m_physics_data.GetPosition().x, m_physics_data.GetPosition().y);

		if (p_displayable_head)
			p_displayable_head->setPosition(m_physics_data.GetPosition().x, m_physics_data.GetPosition().y);

		if (p_displayable_body_shadow)
			p_displayable_body_shadow->setPosition(m_physics_data.GetPosition().x + m_shadow_offset_body.x, m_physics_data.GetPosition().y + m_shadow_offset_body.y);

		if (p_displayable_head_shadow)
			p_displayable_head_shadow->setPosition(m_physics_data.GetPosition().x + m_shadow_offset_head.x, m_physics_data.GetPosition().y + m_shadow_offset_head.y);

		if (change_old_position)
			m_physics_data.SetOldPosition(x, y);
	}

	//Metoda ustawia pozycjê obiektu
	void CPhysicalData::SetPosition(const sf::Vector2f & new_value, bool change_old_position)
	{
		//zak³adamy, ¿e body and head ma wspólny uchwyt
		m_physics_data.SetPosition(new_value);	//aktualizacja pola w klasie (wektor)

		//decorate
		if (p_displayable_body)
			p_displayable_body->setPosition(m_physics_data.GetPosition().x, m_physics_data.GetPosition().y);

		if (p_displayable_head)
			p_displayable_head->setPosition(m_physics_data.GetPosition().x, m_physics_data.GetPosition().y);

		if (p_displayable_body_shadow)
			p_displayable_body_shadow->setPosition(m_physics_data.GetPosition().x + m_shadow_offset_body.x, m_physics_data.GetPosition().y + m_shadow_offset_body.y);

		if (p_displayable_head_shadow)
			p_displayable_head_shadow->setPosition(m_physics_data.GetPosition().x + m_shadow_offset_head.x, m_physics_data.GetPosition().y + m_shadow_offset_head.y);

		if (change_old_position)
			m_physics_data.SetOldPosition(new_value);
	}

	//Metoda zwraca pozycjê przed aktualizacj¹ logiki m_old_position
	const sf::Vector2f & CPhysicalData::GetOldPosition() const
	{
		return m_physics_data.GetOldPosition();
	}

	//Metoda zwraca pozycjê przed aktualizacj¹ logiki m_old_position
	void CPhysicalData::SetOldPosition(const sf::Vector2f & old_position)
	{
		m_physics_data.SetOldPosition(old_position);
	}

	//Metoda ustawia pozycjê obiektu
	void CPhysicalData::SetOldPosition(float x, float y, bool change_old_position)
	{
		m_physics_data.SetOldPosition(x, y);
	}

	//Metoda zwraca prêdkoœæ obiektu
	const sf::Vector2f & CPhysicalData::GetVelocity() const
	{
		return m_physics_data.GetVelocity();
	}

	//Metoda ustawia prêdkoœæ obiektu
	void CPhysicalData::SetVelocity(const sf::Vector2f & velocity)
	{
		m_physics_data.SetVelocity(velocity);
	}

	//Metoda zwraca wartoœæ pu³apu obiektu
	const float CPhysicalData::GetAltitude() const
	{
		return m_physics_data.GetAltitude();
	}

	//Metoda ustawia wartoœæ pu³apu obiektu
	void CPhysicalData::SetAltitude(float altitude)
	{
		if (altitude < 0) return;
		m_physics_data.SetAltitude(altitude);
	}

	//Metoda zwraca flagê, czy obiekt ma reprezentacjê graficzn¹ (body and head) /zgodnoœæ interfejsu/
	const bool CPhysicalData::GetUseDisplayable() const
	{
		return m_use_displayable_body;
	}

	//Metoda zwraca flagê, czy obiekt ma reprezentacjê graficz¹ (body)
	const bool CPhysicalData::GetUseDisplayableBody() const
	{
		return m_use_displayable_body;
	}

	//Metoda zwraca flagê, czy obiekt ma reprezentacjê graficz¹ (head)
	const bool CPhysicalData::GetUseDisplayableHead() const
	{
		return m_use_displayable_head;
	}

	//Metoda ustawia flagê, czy obiekt ma reprezentacjê graficz¹ (body and head)
	void CPhysicalData::SetUseDisplayable(const bool use_displayable)
	{
		m_use_displayable_body = use_displayable;
	}

	//Metoda ustawia flagê, czy obiekt ma reprezentacjê graficz¹ (body)
	void CPhysicalData::SetUseDisplayableBody(const bool use_displayable_body)
	{
		m_use_displayable_body = use_displayable_body;
	}

	//Metoda ustawia flagê, czy obiekt ma reprezentacjê graficz¹ (head)
	void CPhysicalData::SetUseDisplayableHead(const bool use_displayable_head)
	{
		m_use_displayable_head = use_displayable_head;
	}

	//Metoda zwraca flagê, czy obiekt generuje cieñ (body and head) /zgodnoœæ interfejsu/
	const bool CPhysicalData::GetUseShadow() const
	{
		return m_use_shadow_body;
	}

	//Metoda zwraca flagê, czy obiekt generuje cieñ (body)
	const bool CPhysicalData::GetUseShadowBody() const
	{
		return m_use_shadow_body;
	}

	//Metoda zwraca flagê, czy obiekt generuje cieñ (head)
	const bool CPhysicalData::GetUseShadowHead() const
	{
		return m_use_shadow_head;
	}

	//Metoda ustawia flagê, czy obiekt ma generowaæ cieñ (body and head) /zgodnoœæ interfejsu/
	void CPhysicalData::SetUseShadow(const bool use_shadow)
	{
		m_use_shadow_body = m_use_shadow_body = use_shadow;
	}

	//Metoda ustawia flagê, czy obiekt ma generowaæ cieñ (body)
	void CPhysicalData::SetUseShadowBody(const bool use_shadow_body)
	{
		m_use_shadow_body = use_shadow_body;
	}

	//Metoda ustawia flagê, czy obiekt ma generowaæ cieñ (head)
	void CPhysicalData::SetUseShadowHead(const bool use_shadow_head)
	{
		m_use_shadow_head = use_shadow_head;
	}

	//Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (body) /zgodnoœæ interfejsu/
	CDisplayable *CPhysicalData::GetDisplayable()
	{
		return p_displayable_body;
	}

	//Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (body) /zgodnoœæ interfejsu/
	void CPhysicalData::SetDisplayable(CDisplayable *displayable)
	{
		p_displayable_body = displayable;
	}

	//Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (shadow) /zgodnoœæ interfejsu/
	CDisplayable *CPhysicalData::GetShadow()
	{
		return p_displayable_body_shadow;
	}

	//Metoda ustawia wskaŸnik na obiekt klasy CDisplayable (body) /zgodnoœæ interfejsu/
	void CPhysicalData::SetShadow(CDisplayable *displayable_shadow)
	{
		p_displayable_body_shadow = displayable_shadow;
	}

	//Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (body)
	CDisplayable *CPhysicalData::GetDisplayable(EPhysicalPart physical_part)
	{
		if (physical_part == BODY)
			return p_displayable_body;
		else if (physical_part == HEAD)
			return p_displayable_head;
		return p_displayable_body;
	}

	//Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (shadow)
	CDisplayable *CPhysicalData::GetShadow(EPhysicalPart physical_part)
	{
		if (physical_part == BODY)
			return p_displayable_body_shadow;
		else if (physical_part == HEAD)
			return p_displayable_head_shadow;
		return p_displayable_body_shadow;
	}

	//Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (body)
	CDisplayable *CPhysicalData::GetDisplayableBody() const
	{
		return p_displayable_body;
	}

	//Metoda ustawia wskaŸnik na obiekt klasy CDisplayable (body)
	void CPhysicalData::SetDisplayableBody(CDisplayable *displayable_body)
	{
		p_displayable_body = displayable_body;
	}

	//Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (body shadow)
	CDisplayable *CPhysicalData::GetDisplayableBodyShadow() const
	{
		return p_displayable_body_shadow;
	}

	//Metoda ustawia wskaŸnik na obiekt klasy CDisplayable (body)
	void CPhysicalData::SetDisplayableBodyShadow(CDisplayable *displayable_body_shadow)
	{
		p_displayable_body_shadow = displayable_body_shadow;
	}

	//Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (head)
	CDisplayable *CPhysicalData::GetDisplayableHead() const
	{
		return p_displayable_head;
	}

	//Metoda ustawia wskaŸnik na obiekt klasy CDisplayable (body)
	void CPhysicalData::SetDisplayableHead(CDisplayable *displayable_head)
	{
		p_displayable_head = displayable_head;
	}

	//Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (head shadow)
	CDisplayable *CPhysicalData::GetDisplayableHeadShadow() const
	{
		return p_displayable_head_shadow;
	}

	//Metoda ustawia wskaŸnik na obiekt klasy CDisplayable (body)
	void CPhysicalData::SetDisplayableHeadShadow(CDisplayable *displayable_head_shadow)
	{
		p_displayable_head_shadow = displayable_head_shadow;
	}

	//Metoda zwraca kolor obiektu - body
	const sf::Color & CPhysicalData::GetColor() const
	{
		return m_color_body;	//umawiamy siê, ¿e default to czêœæ body
	}

	//Metoda ustawia kolor obiektu - (body and head)
	void CPhysicalData::SetColor(const sf::Color & color)
	{
		//przekazanie wartoœci koloru (body and head)
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
	const sf::Color & CPhysicalData::GetColorBody() const
	{
		return m_color_body;
	}

	//Metoda ustawia kolor obiektu - body
	void CPhysicalData::SetColorBody(const sf::Color & color_body)
	{
		//przekazanie wartoœci koloru (body)
		m_color_body = color_body;

		//decorate
		if (p_displayable_body)
			p_displayable_body->setColor(color_body);
	}

	//Metoda zwraca kolor obiektu - head
	const sf::Color & CPhysicalData::GetColorHead() const
	{
		return m_color_head;
	}

	//Metoda ustawia kolor obiektu - head
	void CPhysicalData::SetColorHead(const sf::Color & color_head)
	{
		//przekazanie wartoœci koloru (head)
		m_color_head = color_head;

		//decorate
		if (p_displayable_head)
			p_displayable_head->setColor(color_head);
	}

	//Metoda ustawia oryginalny kolor obiektu za³adowany z tekstury - body and head
	void CPhysicalData::RestoreColor()
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

	//Metoda ustawia oryginalny kolor obiektu za³adowany z tekstury - body
	void CPhysicalData::RestoreColorBody()
	{
		m_color_body = m_color_stored_body;

		//decorate
		if (p_displayable_body)
			p_displayable_body->setColor(m_color_body);
	}

	//Metoda ustawia oryginalny kolor obiektu za³adowany z tekstury - head
	void CPhysicalData::RestoreColorHead()
	{
		m_color_body = m_color_stored_body;

		//decorate
		if (p_displayable_head)
			p_displayable_head->setColor(m_color_body);
	}

	//Metoda ustawia kolor do zapamiêtania - body
	const sf::Color & CPhysicalData::GetStoredColorBody() const
	{
		return m_color_stored_body;
	}

	//Metoda ustawia kolor do zapamiêtania - body
	const sf::Color & CPhysicalData::GetStoredColorHead() const
	{
		return m_color_stored_head;
	}

	//Metoda ustawia kolor do zapamiêtania - body
	void CPhysicalData::StoreColorBody(const sf::Color & color_stored_body)
	{
		m_color_stored_body = color_stored_body;
	}

	//Metoda ustawia kolor do zapamiêtania - body
	void CPhysicalData::StoreColorHead(const sf::Color & color_stored_head)
	{
		m_color_stored_head = color_stored_head;
	}

	//Metoda zwraca kolor cienia obiektu
	const sf::Color & CPhysicalData::GetColorShadow() const
	{
		return m_color_shadow;
	}

	//Metoda ustawia kolor cienia obiektu
	void CPhysicalData::SetColorShadow(const sf::Color & color_shadow)
	{
		m_color_shadow = color_shadow;
	}

	//Metoda zwraca wektor przesuniêcia cienia wzglêdem obiektu - body
	sf::Vector2f & CPhysicalData::GetShadowOffsetBody()
	{
		return m_shadow_offset_body;
	}

	//Metoda ustawia wektor przesuniêcia cienia wzglêdem obiektu - body
	void CPhysicalData::SetShadowOffsetBody(sf::Vector2f & shadow_offset_body)
	{
		m_shadow_offset_body = shadow_offset_body;
	}

	//Metoda ustawia wektor przesuniêcia cienia wzglêdem obiektu - body
	void CPhysicalData::SetShadowOffsetBody(float shadow_offset_body_x, float shadow_offset_body_y)
	{
		m_shadow_offset_body.x = shadow_offset_body_x;
		m_shadow_offset_body.y = shadow_offset_body_y;
	}

	//Metoda zwraca wektor przesuniêcia cienia wzglêdem obiektu - head
	sf::Vector2f & CPhysicalData::GetShadowOffsetHead()
	{
		return m_shadow_offset_head;
	}

	//Metoda ustawia wektor przesuniêcia cienia wzglêdem obiektu - head
	void CPhysicalData::SetShadowOffsetHead(sf::Vector2f & shadow_offset_head)
	{
		m_shadow_offset_head = shadow_offset_head;
	}

	//Metoda ustawia wektor przesuniêcia cienia wzglêdem obiektu - hrad
	void CPhysicalData::SetShadowOffsetHead(float shadow_offset_head_x, float shadow_offset_head_y)
	{
		m_shadow_offset_head.x = shadow_offset_head_x;
		m_shadow_offset_head.y = shadow_offset_head_y;
	}
	
	//Metoda zwraca indeks warstwy renderingu obiektu (body)
	const int CPhysicalData::GetZIndexBody() const
	{
		return m_z_index_body;
	}

	//Metoda ustawia indeks warstwy renderingu obiektu (body)
	void CPhysicalData::SetZIndexBody(int layer_index)
	{
		//metoda rejestruje obiekt tylko wtedy, gdy parametr (int layer_index),
		//indeks warstwy, zmieniamy na inny ni¿ w tej klasie (default jest to Z_PHYSICAL_BODY)
		//co mo¿e (powinno) byæ zaimplementowane w klasach pochodnych
		//oraz gdy wskaŸnik jest zainicjowany
		if ((m_z_index_body != layer_index) && (p_displayable_body != NULL))
			gDrawableManager.RegisterDrawable(p_displayable_body, layer_index);
		
		//przekazanie
		m_z_index_body = layer_index;
		//decorate
		if (p_displayable_body)
			p_displayable_body->SetLayerIndex(layer_index);
	}

	//Metoda zwraca indeks warstwy renderingu obiektu (body shadow)
	const int CPhysicalData::GetZIndexShadowBody() const
	{
		return m_z_index_shadow_body;
	}

	//Metoda ustawia indeks warstwy renderingu obiektu (body shadow)
	void CPhysicalData::SetZIndexShadowBody(int layer_index)
	{
		//metoda rejestruje obiekt tylko wtedy, gdy parametr (int layer_index),
		//indeks warstwy, zmieniamy na inny ni¿ w tej klasie (default jest to Z_PHYSICAL_SHADOWS_BODY)
		//co mo¿e (powinno) byæ zaimplementowane w klasach pochodnych
		//oraz gdy wskaŸnik jest zainicjowany
		if ((m_z_index_shadow_body != layer_index) && (p_displayable_body_shadow != NULL))
			gDrawableManager.RegisterDrawable(p_displayable_body_shadow, layer_index);
		
		//przekazanie
		m_z_index_shadow_body = layer_index;
		//decorate
		if (p_displayable_body_shadow)
			p_displayable_body_shadow->SetLayerIndex(layer_index);
	}

	//Metoda zwraca indeks warstwy renderingu obiektu (head)
	const int CPhysicalData::GetZIndexHead() const
	{
		return m_z_index_head;
	}

	//Metoda ustawia indeks warstwy renderingu obiektu (head)
	void CPhysicalData::SetZIndexHead(int layer_index)
	{
		//metoda rejestruje obiekt tylko wtedy, gdy parametr (int layer_index),
		//indeks warstwy, zmieniamy na inny ni¿ w tej klasie (default jest to Z_PHYSICAL_HEAD)
		//co mo¿e (powinno) byæ zaimplementowane w klasach pochodnych
		//oraz gdy wskaŸnik jest zainicjowany
		if ((m_z_index_head != layer_index) && (p_displayable_head != NULL))
			gDrawableManager.RegisterDrawable(p_displayable_head, layer_index);

		//przekazanie
		m_z_index_head = layer_index;
		//decorate
		if (p_displayable_head)
			p_displayable_head->SetLayerIndex(layer_index);
	}

	//Metoda zwraca indeks warstwy renderingu obiektu (head shadow)
	const int CPhysicalData::GetZIndexShadowHead() const
	{
		return m_z_index_shadow_head;
	}

	//Metoda ustawia indeks warstwy renderingu obiektu (head shadow)
	void CPhysicalData::SetZIndexShadowHead(int layer_index)
	{
		//metoda rejestruje obiekt tylko wtedy, gdy parametr (int layer_index),
		//indeks warstwy, zmieniamy na inny ni¿ w tej klasie (default jest to Z_PHYSICAL_SHADOWS_HEAD)
		//co mo¿e (powinno) byæ zaimplementowane w klasach pochodnych
		//oraz gdy wskaŸnik jest zainicjowany
		if ((m_z_index_shadow_head != layer_index) && (p_displayable_head_shadow != NULL))
			gDrawableManager.RegisterDrawable(p_displayable_head_shadow, layer_index);

		//przekazanie
		m_z_index_shadow_head = layer_index;
		//decorate
		if (p_displayable_head_shadow)
			p_displayable_head_shadow->SetLayerIndex(layer_index);
	}

	//Metoda zwraca zapamiêtan¹ skalê (body)
	const sf::Vector2f & CPhysicalData::GetStoredScaleBody() const
	{
		return m_physics_data.GetStoredScaleBody();
	}

	//Metoda ustawia zapamiêtan¹ skalê (body)
	void CPhysicalData::SetStoredScaleBody(float stored_scale_X, float stored_scale_Y)
	{
		m_physics_data.SetStoredScaleBody(stored_scale_X, stored_scale_Y);
	}

	//Metoda ustawia zapamiêtan¹ skalê (body)
	void CPhysicalData::SetStoredScaleBody(const sf::Vector2f & stored_scale_vector)
	{
		m_physics_data.SetStoredScaleBody(stored_scale_vector);
	}

	//Metoda zwraca zapamiêtan¹ skalê (body)
	const sf::Vector2f & CPhysicalData::GetStoredScaleHead() const
	{
		return m_physics_data.GetStoredScaleHead();
	}

	//Metoda ustawia zapamiêtan¹ skalê (head)
	void CPhysicalData::SetStoredScaleHead(float stored_scale_X, float stored_scale_Y)
	{
		m_physics_data.SetStoredScaleHead(stored_scale_X, stored_scale_Y);
	}

	//Metoda ustawia zapamiêtan¹ skalê (head)
	void CPhysicalData::SetStoredScaleHead(const sf::Vector2f & stored_scale_vector)
	{
		m_physics_data.SetStoredScaleHead(stored_scale_vector);
	}

	//Metoda ustawia zapamiêtan¹ skalê (body and head)
	void CPhysicalData::SetStoredScale(float stored_scale_X, float stored_scale_Y)
	{
		m_physics_data.SetStoredScaleBody(stored_scale_X, stored_scale_Y);
		m_physics_data.SetStoredScaleHead(stored_scale_X, stored_scale_Y);
	}

	//Metoda ustawia zapamiêtan¹ skalê (body and head)
	void CPhysicalData::SetStoredScale(const sf::Vector2f & stored_scale)
	{
		m_physics_data.SetStoredScaleBody(stored_scale);
		m_physics_data.SetStoredScaleHead(stored_scale);
	}

	//Metoda ustawia zapamiêtan¹ skalê
	void CPhysicalData::SetStoredScale(float stored_uniform)
	{
		m_physics_data.SetStoredScaleHead(stored_uniform, stored_uniform);
	}

	//Metoda zwraca wartoœæ obrotu obiektu w stopniach
	const float CPhysicalData::GetRotation() const
	{
		return m_physics_data.GetRotation();
	}

	//Metoda ustawia wartoœæ obrotu obiektu w stopniach (body and head)
	void CPhysicalData::SetRotation(float rotation)
	{
		m_physics_data.SetRotation(rotation);
	}

	//Metoda zwraca wartoœæ obrotu obiektu w stopniach (body)
	const float CPhysicalData::GetRotationBody() const
	{
		return m_physics_data.GetRotationBody();
	}

	//Metoda ustawia wartoœæ obrotu obiektu w stopniach (body)
	void CPhysicalData::SetRotationBody(float rotation_body)
	{
		m_physics_data.SetRotationBody(rotation_body);

		//decorate
		if (p_displayable_body)
			p_displayable_body->setRotation(rotation_body);

		//decorate
		if (p_displayable_body_shadow)
			p_displayable_body_shadow->setRotation(rotation_body);
	}

	//Metoda zwraca wartoœæ obrotu obiektu w stopniach (head)
	const float CPhysicalData::GetRotationHead() const
	{
		return m_physics_data.GetRotationHead();
	}

	//Metoda ustawia wartoœæ obrotu obiektu w stopniach (head)
	void CPhysicalData::SetRotationHead(float rotation_head)
	{
		m_physics_data.SetRotationHead(rotation_head);

		//decorate
		if (p_displayable_head)
			p_displayable_head->setRotation(rotation_head);

		//decorate
		if (p_displayable_head_shadow)
			p_displayable_head_shadow->setRotation(rotation_head);
	}

	//Metoda obraca obiekt o zadany k¹t (body)
	void CPhysicalData::RotateBody(float angle)
	{
		m_physics_data.SetRotationBody(angle);

		//decorate
		if (p_displayable_body)
			p_displayable_body->rotate(angle);

		//decorate
		if (p_displayable_body_shadow)
			p_displayable_body_shadow->rotate(angle);
	}

	//Metoda obraca obiekt o zadany k¹t (head)
	void CPhysicalData::RotateHead(float angle)
	{
		m_physics_data.SetRotationHead(angle);

		//decorate
		if (p_displayable_head)
			p_displayable_head->rotate(angle);

		//decorate
		if (p_displayable_head_shadow)
			p_displayable_head_shadow->rotate(angle);
	}

	//Metoda obraca obiekt o zadany k¹t (body and head)
	void CPhysicalData::Rotate(float angle)
	{
		RotateBody(angle);
		RotateHead(angle);
	}

	//Metoda zwraca wskaŸnik na animacjê - obiekt klasy CAnimation (body)
	CAnimation *CPhysicalData::GetAnimationBody()
	{
		return p_animation_body;
	}

	//Metoda ustawia ustawia wskaŸnik na animacjê (body)
	void CPhysicalData::SetAnimationBody(CAnimation* p_anim_body)
	{
		CheckDisplayableBody();
		p_animation_body = p_anim_body;

		if (p_displayable_body)
			p_displayable_body->SetAnimation(p_animation_body);

		if (p_displayable_body_shadow)
			p_displayable_body_shadow->SetAnimation(p_animation_body);
	}

	//Metoda zwraca nazwê animacji (body)
	const std::string & CPhysicalData::GetAnimationBodyName() const
	{
		return p_displayable_body->GetAnimationState()->GetAnimation()->GetAnimationName();
	}

	//Metoda ustawia nazwê animacji (body)
	void CPhysicalData::SetAnimationBody(const std::string & anim_body_name)
	{
		CheckDisplayableBody();

		if (p_displayable_body)
			p_displayable_body->SetAnimation(anim_body_name);

		if (p_displayable_body_shadow)
			p_displayable_body_shadow->SetAnimation(anim_body_name);

		//po za³adowaniu animacji (parametr std::string), aktualizacja wskaŸnika
		if (p_displayable_body)
			p_animation_body = p_displayable_body->GetAnimationState()->GetAnimation();
	}

	//Metoda zwraca wskaŸnik na animacjê - obiekt klasy CAnimation (head)
	CAnimation *CPhysicalData::GetAnimationHead()
	{
		return p_animation_head;
	}

	//Metoda ustawia ustawia wskaŸnik na animacjê (head)
	void CPhysicalData::SetAnimationHead(CAnimation *p_anim_head)
	{
		CheckDisplayableHead();

		p_animation_head = p_anim_head;

		if (p_displayable_head)
			p_displayable_head->SetAnimation(p_animation_head);

		if (p_displayable_head_shadow)
			p_displayable_head_shadow->SetAnimation(p_animation_head);
	}

	//Metoda zwraca nazwê animacji (head)
	const std::string & CPhysicalData::GetAnimationHeadName() const
	{
		return p_displayable_head->GetAnimationState()->GetAnimation()->GetAnimationName();
	}

	//Metoda ustawia nazwê animacji (head)
	void CPhysicalData::SetAnimationHead(const std::string & anim_head_name)
	{
		CheckDisplayableHead();

		if (p_displayable_head)
			p_displayable_head->SetAnimation(anim_head_name);

		if (p_displayable_head_shadow)
			p_displayable_head_shadow->SetAnimation(anim_head_name);

		//po za³adowaniu animacji (parametr std::string), aktualizacja wskaŸnika
		if (p_displayable_head)
			p_animation_head = p_displayable_head->GetAnimationState()->GetAnimation();
	}

	//Metoda ustawia komplet animacji
	void CPhysicalData::SetAnimation(CAnimation *p_anim_body, CAnimation *p_anim_head)
	{
		SetAnimationBody(p_anim_body);
		SetAnimationHead(p_anim_head);
	}

	//Metoda ustawia komplet animacji
	void CPhysicalData::SetAnimation(const std::string & anim_name_body, const std::string & anim_name_head)
	{
		SetAnimationBody(anim_name_body);
		SetAnimationHead(anim_name_head);
	}

	//Metoda zwraca pamiêtany wspó³czynnik prêdkoœci odtwarzania animacji (body)
	const float CPhysicalData::GetStoredAnimSpeedBody() const
	{
		return m_stored_anim_speed_body;
	}

	//Metoda zwraca pamiêtany wspó³czynnik prêdkoœci odtwarzania animacji (body)
	const float CPhysicalData::GetStoredAnimSpeedHead() const
	{
		return m_stored_anim_speed_head;
	}

	//Metoda zwraca wspó³czynnik prêdkoœci odtwarzania animacji 1.0f - normal speed (body)
	const float CPhysicalData::GetAnimSpeedBody() const
	{
		return m_anim_speed_body;
	}

	//Metoda zwraca wspó³czynnik prêdkoœci odtwarzania animacji 1.0f - normal speed (head)
	const float CPhysicalData::GetAnimSpeedHead() const
	{
		return m_anim_speed_head;
	}

	//Metoda ustawia wspó³czynnik prêdkoœci odtwarzania animacji 1.0f - normal speed (body)
	void CPhysicalData::SetAnimSpeedBody(float anim_speed)
	{
		m_anim_speed_body = anim_speed;
		if (p_displayable_body)
			p_displayable_body->GetAnimationState()->SetAnimSpeed(m_anim_speed_body);
		if (p_displayable_body_shadow)
			p_displayable_body_shadow->GetAnimationState()->SetAnimSpeed(m_anim_speed_head);
	}

	//Metoda ustawia wspó³czynnik prêdkoœci odtwarzania animacji 1.0f - normal speed (head)
	void CPhysicalData::SetAnimSpeedHead(float anim_speed)
	{
		m_anim_speed_head = anim_speed;
		if (p_displayable_head)
			p_displayable_head->GetAnimationState()->SetAnimSpeed(m_anim_speed_head);
		if(p_displayable_head_shadow)
			p_displayable_head_shadow->GetAnimationState()->SetAnimSpeed(m_anim_speed_head);
	}

	//Metoda ustawia wspó³czynnik prêdkoœci odtwarzania animacji 1.0f - normal speed (body and head)
	void CPhysicalData::SetAnimSpeed(float anim_uniform_speed)
	{
		SetAnimSpeedBody(anim_uniform_speed);
		SetAnimSpeedHead(anim_uniform_speed);
	}

	//Metoda ustawia wspó³czynnik prêdkoœci odtwarzania animacji 1.0f - normal speed (body and head)
	void CPhysicalData::SetAnimSpeed(float anim_speed_body, float anim_speed_head)
	{
		SetAnimSpeedBody(anim_speed_body);
		SetAnimSpeedHead(anim_speed_head);
	}

	//Metoda sprawdza, czy trzeba utworzyæ obiekt klasy CDisplayable (body)
	//np. gdy chcemy dodaæ obrazek, animacjê, etc...
	void CPhysicalData::CheckDisplayableBody()
	{
		//body - oryginal
		if ((m_use_displayable_body) && (!p_displayable_body))
		{
			p_displayable_body = gDrawableManager.CreateDisplayable(GetZIndexBody());
			if (!p_displayable_body)
			{
				fprintf(stderr, "error: CPhysicalData::CheckDisplayable, p_displayable_body null, returning\n");
				return;
			}

			//transformacja
			p_displayable_body->setPosition(m_physics_data.GetPosition());
			p_displayable_body->setRotation(m_physics_data.GetRotationBody());
			p_displayable_body->setColor(p_displayable_body->getColor());
			p_displayable_body->setScale(m_physics_data.GetStoredScaleBody());
			//zapamiêtujemy oryginalny kolor
			m_color_stored_body = p_displayable_body->getColor();
		}

		//body - shadow
		if ((m_use_shadow_body) && (!p_displayable_body_shadow))
		{
			p_displayable_body_shadow = gDrawableManager.CreateDisplayable(GetZIndexShadowBody());
			if (!p_displayable_body_shadow)
			{
				fprintf(stderr, "error: CPhysicalData::CheckDisplayable, p_displayable_body_shadow null, returning\n");
				return;
			}

			//transformacja
			p_displayable_body_shadow->setPosition
			(
				m_physics_data.GetPosition().x +
				m_shadow_offset_body.x,
				m_physics_data.GetPosition().y +
				m_shadow_offset_body.y
			);

			p_displayable_body_shadow->setRotation(m_physics_data.GetRotationBody());
			p_displayable_body_shadow->setColor(gWeather.GetShadowColor());
			p_displayable_body_shadow->setScale(m_physics_data.GetStoredScaleBody());
		}
	}

	//Metoda sprawdza, czy trzeba utworzyæ obiekt klasy CDisplayable (head)
	//np. gdy chcemy dodaæ obrazek, animacjê, etc...
	void CPhysicalData::CheckDisplayableHead()
	{
		//head - oryginal
		if ((m_use_displayable_head) && (!p_displayable_head))
		{
			p_displayable_head = gDrawableManager.CreateDisplayable(GetZIndexHead());
			if (!p_displayable_head)
			{
				fprintf(stderr, "error: CPhysicalData::CheckDisplayable, p_displayable_head null, returning\n");
				return;
			}

			//transformacja
			p_displayable_head->setPosition(m_physics_data.GetPosition());
			p_displayable_head->setRotation(m_physics_data.GetRotationHead());
			p_displayable_head->setColor(p_displayable_head->getColor());
			p_displayable_head->setScale(m_physics_data.GetStoredScaleHead());
			//zapamiêtujemy oryginalny kolor
			m_color_stored_head = p_displayable_head->getColor();
		}

		//head - shadow
		if ((m_use_shadow_head) && (!p_displayable_head_shadow))
		{
			p_displayable_head_shadow = gDrawableManager.CreateDisplayable(GetZIndexShadowHead());
			if (!p_displayable_head_shadow)
			{
				fprintf(stderr, "error: CPhysicalData::CheckDisplayable, p_displayable_head_shadow null, returning\n");
				return;
			}

			//transformacja
			p_displayable_head_shadow->setPosition
			(
				m_physics_data.GetPosition().x +
				m_shadow_offset_head.x,
				m_physics_data.GetPosition().y +
				m_shadow_offset_head.y
			);

			p_displayable_head_shadow->setRotation(m_physics_data.GetRotationHead());
			p_displayable_head_shadow->setColor(gWeather.GetShadowColor());
			p_displayable_head_shadow->setScale(m_physics_data.GetStoredScaleHead());
		}
	}

	//Metoda ustala wektor przesuniêcia cienia - body
	void CPhysicalData::CheckShadowOffsetBody()
	{
		if (m_use_shadow_body)
		{
			//wektor przesuniêcia cienia - body
			m_shadow_offset_body.x = p_displayable_body->getLocalBounds().width;
			m_shadow_offset_body.y = p_displayable_body->getLocalBounds().height;

			//wybieram krótsz¹ sk³adow¹ wektora do obliczeñ
			if (m_shadow_offset_body.x >= m_shadow_offset_body.y)
				m_shadow_offset_body.x = m_shadow_offset_body.y;
			else
				m_shadow_offset_body.y = m_shadow_offset_body.x;

			//transformacja
			SetShadowOffsetBody
			(
				m_shadow_offset_body.x
				* CPhysicalData::m_shadow_init
				* m_physics_data.GetAltitude() * p_displayable_body->getScale().x,
				m_shadow_offset_body.y
				* CPhysicalData::m_shadow_init
				* m_physics_data.GetAltitude() * p_displayable_body->getScale().y
			);
		}
	}

	//Metoda ustala wektor przesuniêcia cienia - head
	void CPhysicalData::CheckShadowOffsetHead()
	{
		if (m_use_shadow_head)
		{
			//wektor przesuniêcia cienia - head
			m_shadow_offset_head.x = p_displayable_head->getLocalBounds().width;
			m_shadow_offset_head.y = p_displayable_head->getLocalBounds().height;

			//wybieram krótsz¹ sk³adow¹ wektora do obliczeñ
			if (m_shadow_offset_head.x >= m_shadow_offset_head.y)
				m_shadow_offset_head.x = m_shadow_offset_head.y;
			else
				m_shadow_offset_head.y = m_shadow_offset_head.x;

			//transformacja
			SetShadowOffsetHead
			(
				m_shadow_offset_head.x
				* CPhysicalData::m_shadow_init
				* m_physics_data.GetAltitude() * p_displayable_head->getScale().x,
				m_shadow_offset_head.y
				* CPhysicalData::m_shadow_init
				* m_physics_data.GetAltitude() * p_displayable_head->getScale().y
			);
		}
	}

	//Metoda ustala wektor przesuniêcia cienia - body and head
	void CPhysicalData::CheckShadowOffset()
	{
		CheckShadowOffsetBody();
		CheckShadowOffsetHead();
	}

	//Metoda aktualizuje transformacjê cienia
	void CPhysicalData::UpdateShadowTransformation()
	{
		//ustawiamy kolor cienia
		SetColorShadow(gWeather.GetShadowColor());

		//offset body
		if (p_displayable_body)
		{
			//shadow position body
			if (m_use_displayable_body)
				if (p_displayable_body_shadow)
				{
					CheckShadowOffsetBody();//aktualizacja shadow offset - body
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
					p_displayable_body_shadow->setColor(GetColorShadow());
				}
		}

		//offset head
		if (p_displayable_head)
		{
			//shadow position head
			if (m_use_displayable_head)
				if (p_displayable_head_shadow)
				{
					CheckShadowOffsetHead();//aktualizacja shadow offset - head
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
					p_displayable_head_shadow->setColor(GetColorShadow());
				}
		}
	}

	//Metoda zwraca nazwê tekstury
	const std::string & CPhysicalData::GetTextureBody() const
	{
		return m_texture_body;
	}

	//Metoda ustatawia nazwê tekstury (body)
	void CPhysicalData::SetTextureBody(const std::string & texture_body)
	{
		m_texture_body = texture_body;

		CheckDisplayableBody();

		if (p_displayable_body)
			p_displayable_body->setTexture(m_texture_body);

		if (p_displayable_body_shadow)
			p_displayable_body_shadow->setTexture(m_texture_body);
	}

	//Metoda zwraca nazwê tekstury (head)
	const std::string & CPhysicalData::GetTextureHead() const
	{
		return m_texture_head;
	}

	//Metoda ustatwia nazwê tekstury (head)
	void CPhysicalData::SetTextureHead(const std::string & texture_head)
	{
		m_texture_head = texture_head;

		CheckDisplayableHead();

		if (p_displayable_head)
			p_displayable_head->setTexture(texture_head);

		if (p_displayable_head_shadow)
			p_displayable_head_shadow->setTexture(texture_head);
	}

	//Metoda generuje obraz tekstury
	void CPhysicalData::SetTextureBody(unsigned width, unsigned height, const sf::Color & color)
	{
		CheckDisplayableBody();
		if (p_displayable_body)
			p_displayable_body->SetTexture(width, height, color);
	}

	//Metoda generuje obraz tekstury
	void CPhysicalData::SetTextureBody(unsigned width, unsigned height, unsigned r, unsigned g, unsigned b, unsigned a)
	{
		CheckDisplayableBody();
		if (p_displayable_body)
			p_displayable_body->SetTexture(width, height, r, g, b, a);
	}

	//Metoda generuje obraz tekstury
	void CPhysicalData::SetTextureHead(unsigned width, unsigned height, const sf::Color & color)
	{
		CheckDisplayableHead();
		if (p_displayable_head)
			p_displayable_head->SetTexture(width, height, color);
	}

	//Metoda generuje obraz tekstury
	void CPhysicalData::SetTextureHead(unsigned width, unsigned height, unsigned r, unsigned g, unsigned b, unsigned a)
	{
		CheckDisplayableHead();
		if (p_displayable_head)
			p_displayable_head->SetTexture(width, height, r, g, b, a);
	}

}//namespace physicaldata

//Nadanie wartoœci sta³ym sk³adowym statycznym
float physicaldata::CPhysicalData::m_shadow_init = 0.125f;	//default - wspó³czynnik przesuniêcia cienia obiektu (offset)
