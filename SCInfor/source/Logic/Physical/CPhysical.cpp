//  _______________________________________
// | CPhysical.cpp - class implementation  |
// | Jack Flower - August 2012             |
// |_______________________________________|
//

#include "CPhysical.h"
#include "../../Weather/CWeather.h"
#include "../../Rendering/Displayable/CDisplayable.h"
#include "../../Rendering/Drawable/CDrawableManager.h"
#include "../../Rendering/Animations/CAnimation.h"
#include "../../Rendering/Animations/CAnimationState.h"
#include "../../Factory/CPhysicalTemplate.h"
#include "../../Utilities/Utilities/Utilities.h"
#include <math.h>

using namespace weather;

namespace logic
{
	RTTI_IMPL_NOPARENT(CPhysical);

	//Chroniony konstruktor domyœlny - u¿ywany wy³¹cznie przez CPhysicalManager
	CPhysical::CPhysical(const std::wstring & uniqueId)
	:
		//private:
		m_physical_manager_index	(-1),
		m_physical_data				(),
		m_smooth					(false),
		
		//protected:
		m_unique_id					(uniqueId),
		m_genre						(),
		m_circle_radius				(1.0f),
		m_collision_shape			(SHAPE_CIRCLE),
		m_rect_size					(1.0f, 1.0f),
		m_rect_size_body			(1.0f, 1.0f),
		m_rect_size_head			(1.0f, 1.0f),
		p_template					(NULL),
		m_ready_for_destruction		(false),
		m_part_collision_data		(),
		m_new_anim_speed			(1.0f)
	{
	}

	//Chroniony konstruktor kopiuj¹cy
	CPhysical::CPhysical(const CPhysical & CPhysicalCopy)
	:
		//private:
		m_physical_manager_index	(CPhysicalCopy.m_physical_manager_index),
		m_physical_data				(CPhysicalCopy.m_physical_data),
		m_smooth					(CPhysicalCopy.m_smooth),
		
		//protected:
		m_unique_id					(CPhysicalCopy.m_unique_id),
		m_genre						(CPhysicalCopy.m_genre),
		m_circle_radius				(CPhysicalCopy.m_circle_radius),
		m_collision_shape			(CPhysicalCopy.m_collision_shape),
		m_rect_size					(CPhysicalCopy.m_rect_size),
		m_rect_size_body			(CPhysicalCopy.m_rect_size_body),
		m_rect_size_head			(CPhysicalCopy.m_rect_size_head),
		p_template					(CPhysicalCopy.p_template),
		m_ready_for_destruction		(CPhysicalCopy.m_ready_for_destruction),
		m_part_collision_data		(CPhysicalCopy.m_part_collision_data),
		m_new_anim_speed			(CPhysicalCopy.m_new_anim_speed)
	{
	}

	//Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
	CPhysical::~CPhysical()
	{
		//private:
		m_physical_manager_index	= 0;
		m_smooth					= false;

		//protected:
		m_unique_id					= L"";
		m_genre						= L"";
		//m_physics_data			not edit
		m_circle_radius				= 0.0f;
		m_rect_size.x				= 0.0f;
		m_rect_size.y				= 0.0f;
		m_rect_size_body.x			= 0.0f;
		m_rect_size_body.y			= 0.0f;
		m_rect_size_head.x			= 0.0f;
		m_rect_size_head.y			= 0.0f;
		p_template					= NULL;
		m_ready_for_destruction		= false;
		//m_part_collision_data		not edit
		m_new_anim_speed			= 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CPhysical::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca unikaln¹ nazwê obiektu klasy CPhysical
	const std::wstring & CPhysical::GetUniqueId() const
	{
		return m_unique_id;
	}

	//Metoda zwraca nazwê gatunku
	const std::wstring & CPhysical::GetGenre()
	{
		return m_genre; 
	}

	//Metoda zwraca wagê
	const float CPhysical::getWeight() const
	{
		return m_physical_data.getWeight();
	}

	//Metoda ustawia wagê
	void CPhysical::setWeight(float weight)
	{
		if (weight < 0) return;
		m_physical_data.setWeight(weight);
	}

	//Metoda zwraca kategorê CPhysical
	physCategory CPhysical::GetCategory()
	{
		return m_category;
	}

	//Metoda ustawia kategoriê CPhysical
	void CPhysical::SetCategory(physCategory category)
	{
		m_category = category;
	}

	//Metoda ustawia kategoriê CPhysical
	void CPhysical::SetCategory(const std::wstring & category_name)
	{
		//parsowanie kategorii na podstawie tablicy nazw kategorii
		//docelowo napisaæ jakiœ prosty translator...
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
			fprintf(stderr, "unrecognised physical category: %ls for physical %ls\n", category_name.c_str(), GetUniqueId().c_str());
	}

	//Metoda ustawia nazwê gatunku
	void CPhysical::SetGenre(const std::wstring & genre)
	{
		m_genre = genre; 
	}

	//Metoda zwraca pozycjê obiektu
	const sf::Vector2f & CPhysical::GetPosition() const
	{
		return m_physical_data.GetPosition();
	}

	//Metoda ustawia pozycjê obiektu
	void CPhysical::SetPosition(float x, float y, bool change_old_position)
	{
		m_physical_data.SetPosition(x, y);
	}

	//Metoda ustawia pozycjê obiektu
	void CPhysical::SetPosition(const sf::Vector2f & new_value, bool change_old_position)
	{
		m_physical_data.SetPosition(new_value);
	}

	//Metoda zwraca pozycjê przed aktualizacj¹ logiki m_old_position
	const sf::Vector2f & CPhysical::GetOldPosition() const
	{
		return m_physical_data.GetOldPosition();
	}

	//Metoda zwraca skalê (body)
	const sf::Vector2f & CPhysical::GetScaleBody() const
	{
		return m_physical_data.GetDisplayableBody()->getScale();
	}

	//Metoda ustawia skalê (body)
	void CPhysical::SetScaleBody(float scale_X, float scale_Y)
	{
		//zapamiêtujê skalê
		m_physical_data.SetStoredScaleBody(scale_X, scale_Y);

		//obiekt zasadniczy i cieñ zawsze maj¹ tê sam¹ skalê
		if(m_physical_data.GetDisplayableBody())
			m_physical_data.GetDisplayableBody()->setScale(scale_X, scale_Y);

		if(m_physical_data.GetDisplayableBodyShadow())
			m_physical_data.GetDisplayableBodyShadow()->setScale(scale_X, scale_Y);
	}

	//Metoda ustawia skalê (body)
	void CPhysical::SetScaleBody(const sf::Vector2f & scale_vector)
	{
		//zapamiêtujê skalê
		m_physical_data.SetStoredScaleBody(scale_vector);

		//obiekt zasadniczy i cieñ zawsze maj¹ tê sam¹ skalê
		if(m_physical_data.GetDisplayableBody())
			m_physical_data.GetDisplayableBody()->setScale(scale_vector);

		if(m_physical_data.GetDisplayableBodyShadow())
			m_physical_data.GetDisplayableBodyShadow()->setScale(scale_vector);
	}

	//Metoda zwraca skalê (body)
	const sf::Vector2f & CPhysical::GetScaleHead() const
	{
		return m_physical_data.GetDisplayableHead()->getScale();
	}

	//Metoda ustawia skalê (head)
	void CPhysical::SetScaleHead(float scale_X, float scale_Y)
	{
		//zapamiêtujê skalê
		m_physical_data.SetStoredScaleHead(scale_X, scale_Y);

		//obiekt zasadniczy i cieñ zawsze maj¹ tê sam¹ skalê
		if(m_physical_data.GetDisplayableHead())
			m_physical_data.GetDisplayableHead()->setScale(scale_X, scale_Y);

		if(m_physical_data.GetDisplayableHeadShadow())
			m_physical_data.GetDisplayableHeadShadow()->setScale(scale_X, scale_Y);
	}

	//Metoda ustawia skalê (head)
	void CPhysical::SetScaleHead(const sf::Vector2f & scale_vector)
	{
		//zapamiêtujê skalê
		m_physical_data.SetStoredScaleHead(scale_vector);

		//obiekt zasadniczy i cieñ zawsze maj¹ tê sam¹ skalê
		if(m_physical_data.GetDisplayableHead())
			m_physical_data.GetDisplayableHead()->setScale(scale_vector);

		if(m_physical_data.GetDisplayableHeadShadow())
			m_physical_data.GetDisplayableHeadShadow()->setScale(scale_vector);
	}

	//Metoda ustawia skalê (body and head)
	void CPhysical::SetScale(float scale_X, float scale_Y)
	{
		//zapamiêtujê skalê
		m_physical_data.SetStoredScaleBody(scale_X, scale_Y);

		//zapamiêtujê skalê
		m_physical_data.SetStoredScaleHead(scale_X, scale_Y);

		//obiekt zasadniczy i cieñ zawsze maj¹ tê sam¹ skalê
		if(m_physical_data.GetDisplayableBody())
			m_physical_data.GetDisplayableBody()->setScale(scale_X, scale_Y);

		if(m_physical_data.GetDisplayableBodyShadow())
			m_physical_data.GetDisplayableBodyShadow()->setScale(scale_X, scale_Y);

		//obiekt zasadniczy i cieñ zawsze maj¹ tê sam¹ skalê
		if(m_physical_data.GetDisplayableHead())
			m_physical_data.GetDisplayableHead()->setScale(scale_X, scale_Y);

		if(m_physical_data.GetDisplayableHeadShadow())
			m_physical_data.GetDisplayableHeadShadow()->setScale(scale_X, scale_Y);
	}

	//Metoda ustawia skalê (body and head)
	void CPhysical::SetScale(const sf::Vector2f & scale)
	{
		//zapamiêtujê skalê
		m_physical_data.SetStoredScaleBody(scale);
		m_physical_data.SetStoredScaleHead(scale);

		//obiekt zasadniczy i cieñ zawsze maj¹ tê sam¹ skalê
		if(m_physical_data.GetDisplayableBody())
			m_physical_data.GetDisplayableBody()->setScale(scale);

		if (m_physical_data.GetDisplayableBodyShadow())
			m_physical_data.GetDisplayableBodyShadow()->setScale(scale);

		//obiekt zasadniczy i cieñ zawsze maj¹ tê sam¹ skalê
		if(m_physical_data.GetDisplayableHead())
			m_physical_data.GetDisplayableHead()->setScale(scale);

		if (m_physical_data.GetDisplayableHeadShadow())
			m_physical_data.GetDisplayableHeadShadow()->setScale(scale);
	}

	//Metoda ustawia skalê
	void CPhysical::SetScale(float uniform)
	{
		//zapamiêtujê skalê
		m_physical_data.SetStoredScaleBody(uniform, uniform);

		//obiekt zasadniczy i cieñ zawsze maj¹ tê sam¹ skalê
		if(m_physical_data.GetDisplayableBody())
			m_physical_data.GetDisplayableBody()->setScale(uniform);

		if (m_physical_data.GetDisplayableHead())
			m_physical_data.GetDisplayableHead()->setScale(uniform);

		//obiekt zasadniczy i cieñ zawsze maj¹ tê sam¹ skalê
		if(m_physical_data.GetDisplayableBodyShadow())
			m_physical_data.GetDisplayableBodyShadow()->setScale(uniform);

		if (m_physical_data.GetDisplayableHeadShadow())
			m_physical_data.GetDisplayableHeadShadow()->setScale(uniform);
	}

	//Metoda zwraca wartoœæ obrotu obiektu w stopniach
	const float CPhysical::GetRotation() const
	{
		return m_physical_data.GetRotation();
	}

	//Metoda ustawia wartoœæ obrotu obiektu w stopniach (body and head)
	void CPhysical::SetRotation(float rotation)
	{
		m_physical_data.SetRotation(rotation);
	}

	//Metoda zwraca wartoœæ obrotu obiektu w stopniach (body)
	const float CPhysical::GetRotationBody() const
	{
		return m_physical_data.GetRotationBody();
	}

	//Metoda ustawia wartoœæ obrotu obiektu w stopniach (body)
	void CPhysical::SetRotationBody(float rotation_body)
	{
		m_physical_data.SetRotationBody(rotation_body);
	}

	//Metoda zwraca wartoœæ obrotu obiektu w stopniach (head)
	const float CPhysical::GetRotationHead() const
	{
		return m_physical_data.GetRotationHead();
	}

	//Metoda ustawia wartoœæ obrotu obiektu w stopniach (head)
	void CPhysical::SetRotationHead(float rotation_head)
	{
		m_physical_data.SetRotationHead(rotation_head);
	}

	//Metoda obraca obiekt o zadany k¹t (body)
	void CPhysical::RotateBody(float angle)
	{
		m_physical_data.RotateBody(angle);
	}

	//Metoda obraca obiekt o zadany k¹t (head)
	void CPhysical::RotateHead(float angle)
	{
		m_physical_data.RotateHead(angle);
	}

	//Metoda obraca obiekt o zadany k¹t (body and head)
	void CPhysical::Rotate(float angle)
	{
		RotateBody(angle);
		RotateHead(angle);
	}

	//Metoda zwraca prêdkoœæ obiektu
	const sf::Vector2f & CPhysical::GetVelocity() const
	{
		return m_physical_data.GetVelocity();
	}

	//Metoda ustawia prêdkoœæ obiektu
	void CPhysical::SetVelocity(const sf::Vector2f & velocity)
	{
		m_physical_data.SetVelocity(velocity);
	}

	//Metoda zwraca promieñ detekcji wykorzystywany przy liczeniu kolizji
	float CPhysical::GetCircleRadius()
	{
		return m_circle_radius;
	}

	//Metoda zwraca wyliczenie - typ liczenia kolizji
	ECollisionShape CPhysical::GetCollisionShape()
	{
		return m_collision_shape;
	}

	//Wirtualna metoda ustawiaj¹ca wartoœæ promienia detekcji wykorzystywan¹ przy liczeniu kolizji
	void CPhysical::SetBoundingCircle(float radius)
	{
		m_collision_shape = SHAPE_CIRCLE;
		m_circle_radius = radius;
		//obliczamy boki prostok¹ta (uproszczenie do kwadratu) wpisanego w okrag
		m_rect_size.x = m_rect_size.y = radius * 2.0f;
	}

	//Metoda ustawia wartoœæ obszaru prostok¹tnego detekcji wykorzystywany przy liczeniu kolizji
	void CPhysical::SetBoundingRect(const sf::Vector2f & rect_size)
	{
		m_collision_shape = SHAPE_RECT;
		m_rect_size = rect_size;
		//obliczamy przeciwprostok¹tn¹, czyli œrednicê okrêgu opisanego na prostok¹cie
		m_circle_radius =  sqrtf(rect_size.x * rect_size.x + rect_size.y * rect_size.y);
	}

	//Metoda zwraca wektor dla obszaru prostok¹tnego detekcji wykorzystywany przy liczeniu kolizji
	const sf::Vector2f & CPhysical::GetRectSize() const
	{
		return m_rect_size;
	}

	//Metoda zwraca sta³¹ referencjê na wektor wielkoœci obiektu
	//wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
	const sf::Vector2f & CPhysical::GetRectangleSizeBody() const
	{
		return m_rect_size_body;
	}

	//Metoda ustawia referencjê na wektor wielkoœci obiektu
	//wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
	void CPhysical::SetRectangleSizeBody(const sf::Vector2f & rect_size_body)
	{
		m_rect_size_body = rect_size_body;
	}

	//Metoda ustawia referencjê na wektor wielkoœci obiektu
	//wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
	void CPhysical::SetRectangleSizeBody(float rect_size_body_width, float rect_size_body_height)
	{
		m_rect_size_body.x = rect_size_body_width;
		m_rect_size_body.y = rect_size_body_height;
	}
	
	//Metoda zwraca sta³¹ referencjê na wektor wielkoœci obiektu
	//wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
	//klasy CDisplayable
	const sf::Vector2f & CPhysical::GetRectangleSizeHead() const
	{
		return m_rect_size_head;
	}

	//Metoda ustawia referencjê na wektor wielkoœci obiektu
	//wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
	//klasy CDisplayable
	void CPhysical::SetRectangleSizeHead(const sf::Vector2f & rect_size_head)
	{
		m_rect_size_head = rect_size_head;
		m_rect_size_head = rect_size_head;
	}

	//Metoda ustawia referencjê na wektor wielkoœci obiektu
	//wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
	//klasy CDisplayable
	void CPhysical::SetRectangleSizeHead(float rect_size_head_width, float rect_size_head_height)
	{
		m_rect_size_head.x = rect_size_head_width;
	}

	//Metoda ustawia referencjê na wektor wielkoœci obiektu
	//wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
	//klasy CDisplayable - body and head
	void CPhysical::SetRectangleSize(const sf::Vector2f & rect_size_uniform)
	{
		m_rect_size_body = rect_size_uniform;
		m_rect_size_head = rect_size_uniform;
	}

	//Metoda ustawia referencjê na wektor wielkoœci obiektu
	void CPhysical::SetRectangleSize(float rect_size_uniform_width, float rect_size_uniform_height)
	{
		m_rect_size_body.x = rect_size_uniform_width;
		m_rect_size_body.y = rect_size_uniform_height;
		m_rect_size_head.x = rect_size_uniform_width;
		m_rect_size_head.y = rect_size_uniform_height;
	}

	//Metoda ustawia referencjê na wektor wielkoœci obiektu
	//wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
	//klasy CDisplayable - body and head
	void CPhysical::SetRectangleSize(const sf::Vector2f & rect_size_body, const sf::Vector2f & rect_size_head)
	{
		m_rect_size_body = rect_size_body;
		m_rect_size_head = rect_size_head;
	}

	//Metoda ustawia referencjê na wektor wielkoœci obiektu
	//wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
	//klasy CDisplayable - body and head
	void CPhysical::SetRectangleSize(float rect_size_body_width, float rect_size_body_height, float rect_size_head_width, float rect_size_head_height)
	{
		m_rect_size_body.x = rect_size_body_width;
		m_rect_size_body.y = rect_size_body_height;
		m_rect_size_head.x = rect_size_head_width;
		m_rect_size_head.y = rect_size_head_height;
	}

	//Metoda zwraca wartoœæ pu³apu obiektu
	const float CPhysical::GetAltitude() const
	{
		return m_physical_data.GetAltitude();
	}

	//Metoda ustawia wartoœæ pu³apu obiektu
	void CPhysical::SetAltitude(float altitude)
	{
		if(altitude < 0) return;
		m_physical_data.SetAltitude(altitude);
	}

	//Metoda zwraca kolor obiektu - body
	const sf::Color & CPhysical::GetColor() const
	{
		return m_physical_data.GetColorBody();	//umawiamy siê, ¿e default to czêœæ body
	}

	//Metoda ustawia kolor obiektu - (body and head)
	void CPhysical::SetColor(const sf::Color & color)
	{
		m_physical_data.SetColor(color);
	}

	//Metoda zwraca kolor obiektu - body
	const sf::Color & CPhysical::GetColorBody() const
	{
		return m_physical_data.GetColorBody();
	}

	//Metoda ustawia kolor obiektu - body
	void CPhysical::SetColorBody(const sf::Color & color_body)
	{
		m_physical_data.SetColorBody(color_body);
	}

	//Metoda zwraca kolor obiektu - head
	const sf::Color & CPhysical::GetColorHead() const
	{
		return m_physical_data.GetColorHead();
	}

	//Metoda ustawia kolor obiektu - head
	void CPhysical::SetColorHead(const sf::Color & color_head)
	{
		m_physical_data.SetColorHead(color_head);
	}

	//Metoda ustawia oryginalny kolor obiektu za³adowany z tekstury - body and head
	void CPhysical::RestoreColor()
	{
		m_physical_data.RestoreColor();
	}

	//Metoda ustawia oryginalny kolor obiektu za³adowany z tekstury - body
	void CPhysical::RestoreColorBody()
	{
		m_physical_data.RestoreColorBody();
	}

	//Metoda ustawia oryginalny kolor obiektu za³adowany z tekstury - head
	void CPhysical::RestoreColorHead()
	{
		m_physical_data.RestoreColorHead();
	}

	//Metoda ustawia kolor do zapamiêtania - body
	const sf::Color & CPhysical::GetStoredColorBody() const
	{
		return m_physical_data.GetStoredColorBody();
	}

	//Metoda ustawia kolor do zapamiêtania - body
	void CPhysical::StoreColorBody(const sf::Color & color_stored_body)
	{
		m_physical_data.StoreColorBody(color_stored_body);
	}
	
	//Metoda ustawia kolor do zapamiêtania - body
	const sf::Color & CPhysical::GetStoredColorHead() const
	{
		return m_physical_data.GetStoredColorHead();
	}

	//Metoda ustawia kolor do zapamiêtania - body
	void CPhysical::StoreColorHead(const sf::Color & color_stored_head)
	{
		m_physical_data.StoreColorHead(color_stored_head);
	}

	//Metoda zwraca kolor cienia obiektu
	const sf::Color & CPhysical::GetColorShadow() const
	{
		return m_physical_data.GetColorShadow();
	}

	//Metoda ustawia kolor cienia obiektu
	void CPhysical::SetColorShadow(const sf::Color & color_shadow)
	{
		m_physical_data.SetColorShadow(color_shadow);
	}

	//Metoda zwraca wektor przesuniêcia cienia wzglêdem obiektu - body
	sf::Vector2f & CPhysical::GetShadowOffsetBody()
	{
		return m_physical_data.GetShadowOffsetBody();
	}

	//Metoda ustawia wektor przesuniêcia cienia wzglêdem obiektu - body
	void CPhysical::SetShadowOffsetBody(sf::Vector2f & shadow_offset_body)
	{
		m_physical_data.SetShadowOffsetBody(shadow_offset_body);
	}

	//Metoda zwraca wektor przesuniêcia cienia wzglêdem obiektu - head
	sf::Vector2f & CPhysical::GetShadowOffsetHead()
	{
		return m_physical_data.GetShadowOffsetHead();
	}

	//Metoda ustawia wektor przesuniêcia cienia wzglêdem obiektu - head
	void CPhysical::SetShadowOffsetHead(sf::Vector2f & shadow_offset_head)
	{
		m_physical_data.SetShadowOffsetHead(shadow_offset_head);
	}

	//Metoda zwraca flagê, czy obiekt generuje reprezentacjê graficzn¹ (body and head) /zgodnoœæ interfejsu/
	const bool CPhysical::GetUseDisplayable() const
	{
		return m_physical_data.GetUseDisplayableBody();
	}

	//Metoda zwraca flagê, czy CPhysical ma reprezentacjê graficz¹ (body)
	const bool CPhysical::GetUseDisplayableBody() const
	{
		return m_physical_data.GetUseDisplayableBody();
	}

	//Metoda zwraca flagê, czy CPhysical ma reprezentacjê graficz¹ (head)
	const bool CPhysical::GetUseDisplayableHead() const
	{
		return m_physical_data.GetUseDisplayableHead();
	}

	//Metoda ustawia flagê, czy CPhysical ma reprezentacjê graficz¹ (body and head)
	void CPhysical::SetUseDisplayable(const bool use_displayable)
	{
		m_physical_data.SetUseDisplayable(use_displayable);
	}

	//Metoda ustawia flagê, czy CPhysical ma reprezentacjê graficz¹ (body)
	void CPhysical::SetUseDisplayableBody(const bool use_displayable_body)
	{
		m_physical_data.SetUseDisplayableBody(use_displayable_body);
	}

	//Metoda ustawia flagê, czy CPhysical ma reprezentacjê graficz¹ (head)
	void CPhysical::SetUseDisplayableHead(const bool use_displayable_head)
	{
		m_physical_data.SetUseDisplayableHead(use_displayable_head);
	}

	//Metoda zwraca flagê, czy obiekt generuje cieñ (body and head) /zgodnoœæ interfejsu/
	const bool CPhysical::GetUseShadow() const
	{
		return m_physical_data.GetUseShadowBody();
	}

	//Metoda zwraca flagê, czy obiekt generuje cieñ (body)
	const bool CPhysical::GetUseShadowBody() const
	{
		return m_physical_data.GetUseShadowBody();
	}

	//Metoda zwraca flagê, czy obiekt generuje cieñ (head)
	const bool CPhysical::GetUseShadowHead() const
	{
		return m_physical_data.GetUseShadowHead();
	}

	//Metoda ustawia flagê, czy obiekt ma generowaæ cieñ (body and head) /zgodnoœæ interfejsu/
	void CPhysical::SetUseShadow(const bool use_shadow)
	{
		m_physical_data.SetUseShadow(use_shadow);
	}

	//Metoda ustawia flagê, czy obiekt ma generowaæ cieñ (body)
	void CPhysical::SetUseShadowBody(const bool use_shadow_body)
	{
		m_physical_data.SetUseShadowBody(use_shadow_body);
	}

	//Metoda ustawia flagê, czy obiekt ma generowaæ cieñ (head)
	void CPhysical::SetUseShadowHead(const bool use_shadow_head)
	{
		m_physical_data.SetUseShadowHead(use_shadow_head);
	}

	//Metoda zwraca wskaŸnik na animacjê - obiekt klasy CAnimation (body)
	CAnimation *CPhysical::GetAnimationBody()
	{
		return m_physical_data.GetAnimationBody();
	}

	//Metoda ustawia ustawia wskaŸnik na animacjê (body)
	void CPhysical::SetAnimationBody(CAnimation* p_anim_body)
	{
		m_physical_data.SetAnimationBody(p_anim_body);
	}

	//Metoda zwraca nazwê animacji (body)
	const std::string & CPhysical::GetAnimationBodyName() const
	{
		return m_physical_data.GetAnimationBodyName();
	}

	//Metoda ustawia nazwê animacji (body)
	void CPhysical::SetAnimationBody(const std::string & anim_body_name)
	{
		m_physical_data.SetAnimationBody(anim_body_name);
	}

	//Metoda zwraca wskaŸnik na animacjê - obiekt klasy CAnimation (head)
	CAnimation *CPhysical::GetAnimationHead()
	{
		return m_physical_data.GetAnimationHead();
	}

	//Metoda ustawia ustawia wskaŸnik na animacjê (head)
	void CPhysical::SetAnimationHead(CAnimation *p_anim_head)
	{
		m_physical_data.SetAnimationHead(p_anim_head);
	}

	//Metoda zwraca nazwê animacji (head)
	const std::string & CPhysical::GetAnimationHeadName() const
	{
		return m_physical_data.GetAnimationHeadName();
	}

	//Metoda ustawia nazwê animacji (head)
	void CPhysical::SetAnimationHead(const std::string & anim_head_name)
	{
		m_physical_data.SetAnimationHead(anim_head_name);
	}

	//Metoda ustawia komplet animacji
	void CPhysical::SetAnimation(CAnimation *p_anim_body, CAnimation *p_anim_head)
	{
		SetAnimationBody(p_anim_body);
		SetAnimationHead(p_anim_head);
	}

	//Metoda ustawia komplet animacji
	void CPhysical::SetAnimation(const std::string & anim_name_body, const std::string & anim_name_head)
	{
		SetAnimationBody(anim_name_body);
		SetAnimationHead(anim_name_head);
	}

	//Metoda zwraca pamiêtany wspó³czynnik prêdkoœci odtwarzania animacji (body)
	const float CPhysical::GetStoredAnimSpeedBody() const
	{
		return m_physical_data.GetStoredAnimSpeedBody();
	}

	//Metoda zwraca pamiêtany wspó³czynnik prêdkoœci odtwarzania animacji (body)
	const float CPhysical::GetStoredAnimSpeedHead() const
	{
		return m_physical_data.GetStoredAnimSpeedHead();
	}

	//Metoda zwraca wspó³czynnik prêdkoœci odtwarzania animacji 1.0f - normal speed (body)
	const float CPhysical::GetAnimSpeedBody() const
	{
		return m_physical_data.GetAnimSpeedBody();
	}

	//Metoda zwraca wspó³czynnik prêdkoœci odtwarzania animacji 1.0f - normal speed (head)
	const float CPhysical::GetAnimSpeedHead() const
	{
		return m_physical_data.GetAnimSpeedHead();
	}

	//Metoda ustawia wspó³czynnik prêdkoœci odtwarzania animacji 1.0f - normal speed (body)
	void CPhysical::SetAnimSpeedBody(float anim_speed)
	{
		m_physical_data.SetAnimSpeedBody(anim_speed);
	}

	//Metoda ustawia wspó³czynnik prêdkoœci odtwarzania animacji 1.0f - normal speed (head)
	void CPhysical::SetAnimSpeedHead(float anim_speed)
	{
		m_physical_data.SetAnimSpeedHead(anim_speed);
	}

	//Metoda ustawia wspó³czynnik prêdkoœci odtwarzania animacji 1.0f - normal speed (body and head)
	void CPhysical::SetAnimSpeed(float anim_uniform_speed)
	{
		SetAnimSpeedBody(anim_uniform_speed);
		SetAnimSpeedHead(anim_uniform_speed);
	}

	//Metoda ustawia wspó³czynnik prêdkoœci odtwarzania animacji 1.0f - normal speed (body and head)
	void CPhysical::SetAnimSpeed(float anim_speed_body, float anim_speed_head)
	{
		SetAnimSpeedBody(anim_speed_body);
		SetAnimSpeedHead(anim_speed_head);
	}

	//Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (body) /zgodnoœæ interfejsu/
	CDisplayable *CPhysical::GetDisplayable()
	{
		return m_physical_data.GetDisplayableBody();
	}

	//Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (shadow) /zgodnoœæ interfejsu/
	CDisplayable *CPhysical::GetShadow()
	{
		return m_physical_data.GetDisplayableBodyShadow();
	}

	//Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (body)
	CDisplayable *CPhysical::GetDisplayable(EPhysicalPart physical_part)
	{
		if (physical_part == BODY)
			return m_physical_data.GetDisplayableBody();
		else if (physical_part == HEAD)
			return m_physical_data.GetDisplayableHead();
		return m_physical_data.GetDisplayableBody();
	}

	//Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (shadow)
	CDisplayable *CPhysical::GetShadow(EPhysicalPart physical_part)
	{
		if (physical_part == BODY)
			return m_physical_data.GetDisplayableBodyShadow();
		else if (physical_part == HEAD)
			return m_physical_data.GetDisplayableHead();
		return m_physical_data.GetDisplayableBodyShadow();
	}

	//Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (body)
	CDisplayable *CPhysical::GetDisplayableBody()
	{
		return m_physical_data.GetDisplayableBody();
	}

	//Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (body shadow)
	CDisplayable *CPhysical::GetDisplayableBodyShadow()
	{
		return m_physical_data.GetDisplayableBodyShadow();
	}

	//Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (head)
	CDisplayable *CPhysical::GetDisplayableHead()
	{
		return m_physical_data.GetDisplayableHead();
	}

	//Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (head shadow)
	CDisplayable *CPhysical::GetDisplayableHeadShadow()
	{
		return m_physical_data.GetDisplayableHeadShadow();
	}

	//Metoda ustawia flagê dla obiektów gotowych do destrukcji
	void CPhysical::MarkForDelete()
	{
		m_ready_for_destruction = true;
	}

	//Wirtualna metoda zaznacza obiekty do destrukcji
	void CPhysical::Kill()
	{
		MarkForDelete();
	}

	//Metoda zwraca flagê, czy obiekt jest gotowy do usuniecia
	bool CPhysical::IsDead()
	{
		return m_ready_for_destruction;
	}

	//Metoda zwraca nazwê tekstury
	const std::string & CPhysical::GetTextureBody() const
	{
		return m_physical_data.GetTextureBody();
	}

	//Metoda ustatawia nazwê tekstury (body)
	void CPhysical::SetTextureBody(const std::string & texture_body)
	{
		m_physical_data.SetTextureBody(texture_body);
	}

	//Metoda zwraca nazwê tekstury (head)
	const std::string & CPhysical::GetTextureHead() const
	{
		return m_physical_data.GetTextureHead();
	}

	//Metoda ustatwia nazwê tekstury (head)
	void CPhysical::SetTextureHead(const std::string & texture_head)
	{
		m_physical_data.SetTextureHead(texture_head);
	}

	//Metoda generuje obraz tekstury
	void CPhysical::SetTextureBody(unsigned width, unsigned height, const sf::Color & color)
	{
		m_physical_data.SetTextureBody(width, height, color);
	}

	//Metoda generuje obraz tekstury
	void CPhysical::SetTextureBody(unsigned width, unsigned height, unsigned r, unsigned g, unsigned b, unsigned a)
	{
		m_physical_data.SetTextureBody(width, height, r, g, b, a);
	}

	//Metoda generuje obraz tekstury
	void CPhysical::SetTextureHead(unsigned width, unsigned height, const sf::Color & color)
	{
		m_physical_data.SetTextureHead(width, height, color);
	}

	//Metoda generuje obraz tekstury
	void CPhysical::SetTextureHead(unsigned width, unsigned height, unsigned r, unsigned g, unsigned b, unsigned a)
	{
		m_physical_data.SetTextureHead(width, height, r, g, b, a);
	}

	//Metoda zwraca tryb wyg³adzania tekstury
	const bool CPhysical::getSmoothing() const
	{
		return m_smooth;
	}

	//Metoda ustawia tryb wyg³adzania tekstury
	void CPhysical::setSmoothing(bool smooth)
	{
		m_smooth = smooth; //zapamietujê flagê wyg³adzania tekstury

		if(m_physical_data.GetDisplayableBody())
			m_physical_data.GetDisplayableBody()->setSmoothing(m_smooth);
		if(m_physical_data.GetDisplayableBodyShadow())
			m_physical_data.GetDisplayableBodyShadow()->setSmoothing(m_smooth);
		if(m_physical_data.GetDisplayableHead())
			m_physical_data.GetDisplayableHead()->setSmoothing(m_smooth);
		if(m_physical_data.GetDisplayableHeadShadow())
			m_physical_data.GetDisplayableHeadShadow()->setSmoothing(m_smooth);
	}

	//Metoda zwraca statyczny wspó³czynnik wirtualnej wysokoœci obiektu
	const float CPhysical::GetIncrease() const
	{
		return m_increase;
	}

	//Metoda ustawia statyczny wspó³czynnik wirtualnej wysokoœci obiektu
	const void CPhysical::SetIncrease(float increase) const
	{
		m_increase = increase;
	}

	//Metoda zwraca opakowanie informacji o kolidowaniu
	CPartCollisionData	& CPhysical::getPartCollisionData()
	{
		return m_part_collision_data;
	}

	//Wirtualna metoda aktualizuj¹ca obiekt
	void CPhysical::Update(float dt)
	{
		sf::Vector2f new_position;
		new_position.x = m_physical_data.GetPosition().x + (dt * m_physical_data.GetVelocity().x);
		new_position.y = m_physical_data.GetPosition().y + (dt * m_physical_data.GetVelocity().y);
		m_physical_data.SetOldPosition(m_physical_data.GetPosition());
		SetPosition(new_position);
		UpdateShadow(dt);
	}

	//implementajca metod protected:

	//Metoda zwraca wyliczony wspó³czynnik prêdkoœci animacji dla zadanego czasu trwania jednego obiegu animacji
	const float CPhysical::getCalcualtedAnimSpeed(float anim_time)
	{
		if (anim_time > 0)
		{
			//wyliczenie nowego czasu odtwarzania pe³nego obiegu animacji
			m_new_anim_speed = GetAnimSpeedHead() / anim_time;
			//im krótszy czas trwania animacji, tym wiêksza prêdkoœæ odtwarzania
			//im d³u¿szy czas trwania animacji, tym mniejsza prêdkoœæ odtwarzania
			//new_anim_speed_factor		= current_anim_speed / new_anim_total_time
			//anim_speed_factor_one		= 1 / 1.0000	=>	1.0000
			//anim_speed_factor_two		= 1 / 0.5000	=>	2.0000
			//anim_speed_factor_three	= 1 / 4.0000	=>	0.2500
			return m_new_anim_speed;
		}
		return GetAnimSpeedHead();//zwracamy nienaruszone
	}


	//Metoda zwraca indeks warstwy renderingu obiektu (body)
	const int CPhysical::GetZIndexBody() const
	{
		return m_physical_data.GetZIndexBody();
	}

	//Metoda ustawia indeks warstwy renderingu obiektu (body)
	void CPhysical::SetZIndexBody(int layer_index)
	{
		m_physical_data.SetZIndexBody(layer_index);
	}

	//Metoda zwraca indeks warstwy renderingu obiektu (body shadow)
	const int CPhysical::GetZIndexShadowBody() const
	{
		return m_physical_data.GetZIndexShadowBody();
	}
	
	//Metoda ustawia indeks warstwy renderingu obiektu (body shadow)
	void CPhysical::SetZIndexShadowBody(int layer_index)
	{
		m_physical_data.SetZIndexShadowBody(layer_index);
	}

	//Metoda zwraca indeks warstwy renderingu obiektu (head)
	const int CPhysical::GetZIndexHead() const
	{
		return m_physical_data.GetZIndexHead();
	}

	//Metoda ustawia indeks warstwy renderingu obiektu (head)
	void CPhysical::SetZIndexHead(int layer_index)
	{
		m_physical_data.SetZIndexHead(layer_index);
	}

	//Metoda zwraca indeks warstwy renderingu obiektu (head shadow)
	const int CPhysical::GetZIndexShadowHead() const
	{
		return m_physical_data.GetZIndexShadowHead();
	}

	//Metoda ustawia indeks warstwy renderingu obiektu (head shadow)
	void CPhysical::SetZIndexShadowHead(int layer_index)
	{
		m_physical_data.SetZIndexShadowHead(layer_index);
	}

	//Metoda aktualizuje cieñ rzucany przez obiekt i jego nasycenie w zale¿noœci od pory dnia
	void CPhysical::UpdateShadow(float dt)
	{
		m_physical_data.UpdateShadowTransformation();
	}


	//implementajca metod private:

	//prywatna metoda sprawdza, czy trzeba utworzyæ obiekt klasy CDisplayable
	void CPhysical::CheckDisplayableBody()
	{
		m_physical_data.CheckDisplayableBody();
	}

	//prywatna metoda sprawdza, czy trzeba utworzyæ obiekt klasy CDisplayable
	void CPhysical::CheckDisplayableHead()
	{
		m_physical_data.CheckDisplayableHead();
	}

	//prywatna metoda dobieraj¹ca przesuniêcie cienia
	//w zale¿noœci od wielkoœci obiektu - body and head
	//oraz jego nasycenie w zale¿noœci od pory dnia
	//pozycji s³oñca (Ÿród³a œwiat³a - gwiazd, etc...)
	void CPhysical::UpdateShadowTransformation()
	{
		m_physical_data.UpdateShadowTransformation();
	}

	//Metoda ustala wektor przesuniêcia cienia - body
	void CPhysical::CheckShadowOffsetBody()
	{
		m_physical_data.CheckShadowOffsetBody();
	}

	//Metoda ustala wektor przesuniêcia cienia - head
	void CPhysical::CheckShadowOffsetHead()
	{
		m_physical_data.CheckShadowOffsetHead();
	}

	//Metoda ustala wektor przesuniêcia cienia - body and head
	void CPhysical::CheckShadowOffset()
	{
		m_physical_data.CheckShadowOffsetBody();
		m_physical_data.CheckShadowOffsetHead();
	}

}//namespace logic

//Nadanie wartoœci sta³ym sk³adowym statycznym
float logic::CPhysical::m_increase		= 0.33f;	//default - wspó³czynnik wysokoœci (wzrostu) obiektu)
