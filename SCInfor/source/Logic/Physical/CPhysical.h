//  _______________________________________
// | CPhysical.h - class definition        |
// | Jack Flower - August 2012             |
// |_______________________________________|
//

#ifndef H_PHYSICAL_JACK
#define H_PHYSICAL_JACK

#include "PhysicalCategories.h"
#include "ECollisionShape.h"
#include "EPhysicalPart.h"
#include "PhysicalData/CPhysicalData.h"
#include "PartCollisionData/CPartCollisionData.h"
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
	class CPhysical
	{
		RTTI_DECL;

		///
		///Deklaracja przyja�ni
		///
		friend class CPhysicalManager;

		//Aby uzyska� obiekt CPhysical, nale�y wywo�a� CPhysicalManager::CreatePhysical();

	protected:

		///
		///Chroniony konstruktor domy�lny - u�ywany wy��cznie przez CPhysicalManager
		///
		///@param & uniqueId - sta�a referencja na obiekt klasy std::wstring
		///
		CPhysical(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiuj�cy
		///
		///@param & CPhysicalCopy - parametr - obiekt klasy CPhysical
		///
		CPhysical(const CPhysical & CPhysicalCopy);

		///
		///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
		///
		virtual ~CPhysical();

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca unikaln� nazw� obiektu klasy CPhysical
		///
		const std::wstring & GetUniqueId() const;

		///
		///Metoda zwraca nazw� gatunku
		///
		const std::wstring & GetGenre();

		///
		///Metoda zwraca wag�
		///
		const float getWeight() const;

		///
		///Metoda ustawia wag�
		///
		///@param weight - waga
		///
		void setWeight(float weight);

		///
		///Metoda zwraca kategori� CPhysical
		///
		physCategory GetCategory();

		///
		///Metoda ustawia kategori� CPhysical
		///
		///@param category - wyliczenie physCategory
		///
		void SetCategory(physCategory category);

		///
		///Metoda ustawia kategori� CPhysical
		///
		///@param & category_name - sta�a referecnaj na obiekt klasy std::wstring
		///
		void SetCategory(const std::wstring & category_name);

		///
		///Metoda ustawia nazw� gatunku
		///
		///@param & genre - sta�a referencja na obiekt klasy std::wstring
		///
		void SetGenre(const std::wstring & genre);

		///
		///Metoda zwraca pozycj� obiektu
		///
		const sf::Vector2f & GetPosition() const;

		///
		///Metoda ustawia pozycj� obiektu
		///
		///@param x - wsp�rz�dna x obiektu
		///
		///@param y - wsp�rz�dna y obiektu
		///
		///@param change_old_position - flaga, czy aktualizowa� m_old_position
		///
		void SetPosition(float x, float y, bool change_old_position = false);

		///
		///Metoda ustawia pozycj� obiektu
		///
		///@param &vector - sta�a referenacja na obiekt klasy sf::Vector2f
		///
		///@param change_old_position - flaga, czy aktualizowa� m_old_position
		///
		void SetPosition(const sf::Vector2f& new_value, bool change_old_position = false);

		///
		///Metoda zwraca pozycj� przed aktualizacj� logiki m_old_position
		///
		const sf::Vector2f & GetOldPosition() const;

		///
		///Metoda zwraca skal� (body)
		///
		const sf::Vector2f & GetScaleBody() const;
		
		///
		///Metoda ustawia skal� (body)
		///
		///@param scale_X - warto�� X
		///
		///@param scale_Y - warto�� Y
		///
		void SetScaleBody(float scale_X, float scale_Y);
		
		///
		///Metoda ustawia skal� (body)
		///
		///@param & scale_vector - wektor skali - sta�a referencja na obiekt klasy sf::Vector2f
		///
		void SetScaleBody(const sf::Vector2f & scale_vector);

		///
		///Metoda zwraca skal� (head)
		///
		const sf::Vector2f & GetScaleHead() const;

		///
		///Metoda ustawia skal� (head)
		///
		///@param scale_X - warto�� X
		///
		///@param scale_Y - warto�� Y
		///
		void SetScaleHead(float scale_X, float scale_Y);

		///
		///Metoda ustawia skal� (head)
		///
		///@param & scale_vector - wektor skali - sta�a referencja na obiekt klasy sf::Vector2f
		///
		void SetScaleHead(const sf::Vector2f & scale_vector);

		///
		///Metoda ustawia skal� (body and head)
		///
		///@param scale_X - warto�� X
		///
		///@param scale_Y - warto�� Y
		///
		void SetScale(float scale_X, float scale_Y);

		///
		///Metoda ustawia skal� (body and head)
		///
		///@param &scale - wektor skali - sta�a referencja na obiekt klasy sf::Vector2f
		///
		void SetScale(const sf::Vector2f & scale);

		///
		///Metoda ustawia skal�
		///
		///@param uniform - jednolita warto�� skaluj�ca w osi x i y
		///
		void SetScale(float uniform);

		///
		///Metoda zwraca warto�� obrotu obiektu w stopniach (body and head)
		///
		const float GetRotation() const;

		///
		///Metoda ustawia warto�� obrotu obiektu w stopniach (body and head)
		///
		///@param rotation_uniform - warto�� obrotu obiektu (body and head)
		///
		void SetRotation(float rotation_uniform);

		///
		///Metoda zwraca warto�� obrotu obiektu w stopniach (body)
		///
		const float GetRotationBody() const;

		///
		///Metoda ustawia warto�� obrotu obiektu w stopniach (body)
		///
		///@param rotation_body - warto�� obrotu obiektu (body)
		///
		void SetRotationBody(float rotation_body);

		///
		///Metoda zwraca warto�� obrotu obiektu w stopniach (head)
		///
		const float GetRotationHead() const;

		///
		///Metoda ustawia warto�� obrotu obiektu w stopniach (head)
		///
		///@param rotation_head - warto�� obrotu obiektu (head)
		///
		void SetRotationHead(float rotation_head);

		///
		///Metoda obraca obiekt o zadany k�t (body)
		///
		///@param angle - warto�� obrotu
		///
		void RotateBody(float angle);

		///
		///Metoda obraca obiekt o zadany k�t (head)
		///
		///@param angle - warto�� obrotu
		///
		void RotateHead(float angle);

		///
		///Metoda obraca obiekt o zadany k�t (body and head)
		///
		///@param angle - warto�� obrotu
		///
		void Rotate(float angle);

		///
		///Metoda zwraca pr�dko�� obiektu
		///
		const sf::Vector2f & GetVelocity() const;

		///
		///Metoda ustawia pr�dko�� obiektu
		///
		///@param velocity - sta�a referencja na obiekt klasy sf::Vector2f
		///
		void SetVelocity(const sf::Vector2f & velocity);

		///
		///Metoda zwraca promie� detekcji wykorzystywany przy liczeniu kolizji
		///
		float GetCircleRadius();

		///
		///Metoda zwraca wyliczenie - typ liczenia kolizji
		///
		ECollisionShape GetCollisionShape();

		///
		///Wirtualna metoda ustawiaj�ca warto�� promienia detekcji wykorzystywan� przy liczeniu kolizji
		///
		///@param radius - promie� detekcji
		///
		virtual void SetBoundingCircle(float radius);

		///
		///Metoda ustawia warto�� obszaru prostok�tnego detekcji wykorzystywany przy liczeniu kolizji
		///
		///@param &rect_size - sta�a referencja wektor dla obszaru prostok�tnego detekcji wykorzystywany przy liczeniu kolizji
		///
		void SetBoundingRect(const sf::Vector2f & rect_size);

		///
		///Metoda zwraca wektor dla obszaru prostok�tnego detekcji wykorzystywany przy liczeniu kolizji
		///
		const sf::Vector2f & GetRectSize() const ;

		///
		///Metoda zwraca sta�� referencj� na wektor wielko�ci obiektu
		///wykorzytywana przy tworzeniu syntetyk�w - tekstur dla obiekt�w
		///klasy CDisplayable
		///
		const sf::Vector2f & GetRectangleSizeBody() const;

		///
		///Metoda ustawia referencj� na wektor wielko�ci obiektu
		///wykorzytywana przy tworzeniu syntetyk�w - tekstur dla obiekt�w
		///klasy CDisplayable
		///
		///@param & rect_size_body - sta�� referencja na obiekt klasy sf::Vector2f
		///
		void SetRectangleSizeBody(const sf::Vector2f & rect_size_body);
	
		///
		///Metoda ustawia referencj� na wektor wielko�ci obiektu
		///wykorzytywana przy tworzeniu syntetyk�w - tekstur dla obiekt�w
		///klasy CDisplayable
		///
		///@param rect_size_body_width - szeroko�c tekstury (wymaga rzutowania na typ ca�kowity)
		///
		///@param rect_size_body_height - wysoko�� tekstury (wymaga rzutowania na typ ca�kowity)
		///
		void SetRectangleSizeBody(float rect_size_body_width, float rect_size_body_height);
		
		///
		///Metoda zwraca sta�� referencj� na wektor wielko�ci obiektu
		///wykorzytywana przy tworzeniu syntetyk�w - tekstur dla obiekt�w
		///klasy CDisplayable
		///
		const sf::Vector2f & GetRectangleSizeHead() const;

		///
		///Metoda ustawia referencj� na wektor wielko�ci obiektu
		///wykorzytywana przy tworzeniu syntetyk�w - tekstur dla obiekt�w
		///klasy CDisplayable
		///
		///@param & rect_size_head - sta�� referencja na obiekt klasy sf::Vector2f
		///
		void SetRectangleSizeHead(const sf::Vector2f & rect_size_head);

		///
		///Metoda ustawia referencj� na wektor wielko�ci obiektu
		///wykorzytywana przy tworzeniu syntetyk�w - tekstur dla obiekt�w
		///klasy CDisplayable
		///
		///@param rect_size_head_width - szeroko�c tekstury (wymaga rzutowania na typ ca�kowity)
		///
		///@param rect_size_head_height - wysoko�� tekstury (wymaga rzutowania na typ ca�kowity)
		///
		void SetRectangleSizeHead(float rect_size_head_width, float rect_size_head_height);
		
		///
		///Metoda ustawia referencj� na wektor wielko�ci obiektu
		///wykorzytywana przy tworzeniu syntetyk�w - tekstur dla obiekt�w
		///klasy CDisplayable - body and head
		///
		///@param & rect_size_uniform - sta�� referencja na obiekt klasy sf::Vector2f
		///
		void SetRectangleSize(const sf::Vector2f & rect_size_uniform);

		///
		///Metoda ustawia referencj� na wektor wielko�ci obiektu
		///wykorzytywana przy tworzeniu syntetyk�w - tekstur dla obiekt�w
		///klasy CDisplayable - body and head
		///
		///@param rect_size_uniform_width - szeroko�c tekstury (wymaga rzutowania na typ ca�kowity)
		///
		///@param rect_size_uniform_height - wysoko�� tekstury (wymaga rzutowania na typ ca�kowity)
		///
		void SetRectangleSize(float rect_size_uniform_width, float rect_size_uniform_height);
		
		///
		///Metoda ustawia referencj� na wektor wielko�ci obiektu
		///wykorzytywana przy tworzeniu syntetyk�w - tekstur dla obiekt�w
		///klasy CDisplayable - body and head
		///
		///@param & rect_size_body - sta�� referencja na obiekt klasy sf::Vector2f
		///
		///@param & rect_size_head - sta�� referencja na obiekt klasy sf::Vector2f
		///
		void SetRectangleSize(const sf::Vector2f & rect_size_body, const sf::Vector2f & rect_size_head);
		
		///
		///Metoda ustawia referencj� na wektor wielko�ci obiektu
		///wykorzytywana przy tworzeniu syntetyk�w - tekstur dla obiekt�w
		///klasy CDisplayable - body and head
		///
		///@param rect_size_body_width - szeroko�c tekstury (wymaga rzutowania na typ ca�kowity)
		///
		///@param rect_size_body_height - wysoko�� tekstury (wymaga rzutowania na typ ca�kowity)
		///
		///@param rect_size_head_width - wysoko�� tekstury (wymaga rzutowania na typ ca�kowity)
		///
		///@param rect_size_head_height - wysoko�� tekstury (wymaga rzutowania na typ ca�kowity)
		///
		void SetRectangleSize(float rect_size_body_width, float rect_size_body_height, float rect_size_head_width, float rect_size_head_height);

		///
		///Metoda zwraca warto�� pu�apu obiektu
		///
		const float GetAltitude() const;

		///
		///Metoda ustawia warto�� pu�apu obiektu
		///
		///@param altitude - warto�� pu�apu obiektu
		///
		void SetAltitude(float altitude);

		///
		///Metoda zwraca kolor obiektu - body
		///
		const sf::Color & GetColor() const;

		///
		///Metoda ustawia kolor obiektu - (body and head)
		///
		///@param & color - kolor
		///
		void SetColor(const sf::Color & color);

		///
		///Metoda zwraca kolor obiektu - body
		///
		const sf::Color & GetColorBody() const;

		///
		///Metoda ustawia kolor obiektu - body
		///
		///@param & color_body - kolor obiektu
		///
		void SetColorBody(const sf::Color & color_body);

		///
		///Metoda zwraca kolor obiektu - head
		///
		const sf::Color & GetColorHead() const;

		///
		///Metoda ustawia kolor obiektu - head
		///
		///@param & color_head - kolor
		///
		void SetColorHead(const sf::Color & color_head);

		///
		///Metoda ustawia oryginalny kolor obiektu za�adowany z tekstury - body and head
		///
		void RestoreColor();

		///
		///Metoda ustawia oryginalny kolor obiektu za�adowany z tekstury - body
		///
		void RestoreColorBody();

		///
		///Metoda ustawia oryginalny kolor obiektu za�adowany z tekstury - head
		///
		void RestoreColorHead();

		///
		///Metoda ustawia kolor do zapami�tania - body
		///
		const sf::Color & GetStoredColorBody() const;

		///
		///Metoda ustawia kolor do zapami�tania - body
		///
		///@param & color_stored_body - sta�a referencja na obiekt klasy sf::Color
		///
		void StoreColorBody(const sf::Color & color_stored_body);

		///
		///Metoda ustawia kolor do zapami�tania - body
		///
		const sf::Color & GetStoredColorHead() const;

		///
		///Metoda ustawia kolor do zapami�tania - body
		///
		///@param & color_stored_head - sta�a referencja na obiekt klasy sf::Color
		///
		void StoreColorHead(const sf::Color & color_stored_head);

		///
		///Metoda zwraca kolor cienia obiektu
		///
		const sf::Color & GetColorShadow() const;

		///
		///Metoda ustawia kolor cienia obiektu
		///
		///@param & color_shadow - kolor cienia obiektu
		///
		void SetColorShadow(const sf::Color & color_shadow);

		///
		///Metoda zwraca wektor przesuni�cia cienia wzgl�dem obiektu - body
		///
		sf::Vector2f & GetShadowOffsetBody();

		///
		///Metoda ustawia wektor przesuni�cia cienia wzgl�dem obiektu - body
		///
		///@param & shadow_offset_body - sta�a referencja na wektor przesuni�cia cienia wzgl�dem obiektu
		///
		void SetShadowOffsetBody(sf::Vector2f & shadow_offset_body);

		///
		///Metoda zwraca wektor przesuni�cia cienia wzgl�dem obiektu - head
		///
		sf::Vector2f & GetShadowOffsetHead();

		///
		///Metoda ustawia wektor przesuni�cia cienia wzgl�dem obiektu - head
		///
		///@param & shadow_offset_head - sta�a referencja na wektor przesuni�cia cienia wzgl�dem obiektu
		///
		void SetShadowOffsetHead(sf::Vector2f & shadow_offset_head);
		
		///
		///Metoda zwraca flag�, czy obiekt generuje reprezentacj� graficzn� (body and head) /zgodno�� interfejsu/
		///
		const bool GetUseDisplayable() const;

		///
		///Metoda zwraca flag�, czy CPhysical ma reprezentacj� graficz� (body)
		///
		const bool GetUseDisplayableBody() const;

		///
		///Metoda zwraca flag�, czy CPhysical ma reprezentacj� graficz� (head)
		///
		const bool GetUseDisplayableHead() const;

		///
		///Metoda ustawia flag�, czy CPhysical ma reprezentacj� graficz� (body and head)
		///
		///@param use_displayable - flaga, czy obiekt ma u�ywa� reprezentacji graficznej
		///
		void SetUseDisplayable(const bool use_displayable);

		///
		///Metoda ustawia flag�, czy CPhysical ma reprezentacj� graficz� (body)
		///
		///@param use_displayable_body - flaga, czy obiekt ma u�ywa� reprezentacji graficznej
		///
		void SetUseDisplayableBody(const bool use_displayable_body);

		///
		///Metoda ustawia flag�, czy CPhysical ma reprezentacj� graficz� (head)
		///
		///@param use_displayable_head - flaga, czy obiekt ma u�ywa� reprezentacji graficznej
		///
		void SetUseDisplayableHead(const bool use_displayable_head);

		///
		///Metoda zwraca flag�, czy obiekt generuje cie� (body and head) /zgodno�� interfejsu/
		///
		const bool GetUseShadow() const;

		///
		///Metoda zwraca flag�, czy obiekt generuje cie� (body)
		///
		const bool GetUseShadowBody() const;

		///
		///Metoda zwraca flag�, czy obiekt generuje cie� (head)
		///
		const bool GetUseShadowHead() const;

		///
		///Metoda ustawia flag�, czy obiekt ma generowa� cie� (body and head) /zgodno�� interfejsu/
		///
		///@param use_shadow - flaga, czy obiekt ma generowa� cie� (body and head) /zgodno�� interfejsu/
		///
		void SetUseShadow(const bool use_shadow);

		///
		///Metoda ustawia flag�, czy obiekt ma generowa� cie� (body)
		///
		///@param use_shadow_body - flaga, czy obiekt ma generowa� cie� (body)
		///
		void SetUseShadowBody(const bool use_shadow_body);

		///
		///Metoda ustawia flag�, czy obiekt ma generowa� cie� (head)
		///
		///@param use_shadow_head - flaga, czy obiekt ma generowa� cie� (head)
		///
		void SetUseShadowHead(const bool use_shadow_head);

		///
		///Metoda zwraca wska�nik na animacj� (body)
		///
		CAnimation *GetAnimationBody();

		///
		///Metoda ustawia ustawia wska�nik na animacj� (body)
		///
		///@param *p_anim_body - wska�nik na animacj� - obiekt klasy CAnimation (body)
		///
		void SetAnimationBody(CAnimation* p_anim_body);

		///
		///Metoda zwraca nazw� animacji (body)
		///
		const std::string & GetAnimationBodyName() const;

		///
		///Metoda ustawia nazw� animacji (body)
		///
		///@param & anim_body_name - nazwa animacji (body)
		///
		void SetAnimationBody(const std::string & anim_body_name);

		///
		///Metoda zwraca wska�nik na animacj� (head)
		///
		CAnimation *GetAnimationHead();

		///
		///Metoda ustawia ustawia wska�nik na animacj� (head)
		///
		///@param *p_anim_head - wska�nik na animacj� - obiekt klasy CAnimation (head)
		///
		void SetAnimationHead(CAnimation *p_anim_head);

		///
		///Metoda zwraca nazw� animacji (head)
		///
		const std::string & GetAnimationHeadName() const;

		///
		///Metoda ustawia nazw� animacji (head)
		///
		///@param & anim_head_name - nazwa animacji (head)
		///
		void SetAnimationHead(const std::string & anim_head_name);

		///
		///Metoda ustawia komplet animacji
		///
		///@param *p_anim_body - wska�nik na obiekt klasy CAnimation (body)
		///
		///@param *p_anim_head - wska�nik na obiekt klasy CAnimation (head)
		///
		void SetAnimation(CAnimation *p_anim_body, CAnimation *p_anim_head);

		///
		///Metoda ustawia komplet animacji
		///
		///@param & anim_name_body - sta�a referencja na obiekt klasy std::string - nazwa animacji (body)
		///
		///@param & anim_name_head - sta�a referencja na obiekt klasy std::string - nazwa animacji (head)
		///
		void SetAnimation(const std::string & anim_name_body, const std::string & anim_name_head);
	    
		///
		///Metoda zwraca pami�tany wsp�czynnik pr�dko�ci odtwarzania animacji (body)
		///
		const float GetStoredAnimSpeedBody() const;

		///
		///Metoda zwraca pami�tany wsp�czynnik pr�dko�ci odtwarzania animacji (body)
		///
		const float GetStoredAnimSpeedHead() const;

		///
		///Metoda zwraca wsp�czynnik pr�dko�ci odtwarzania animacji 1.0f - normal speed (body)
		///
		const float GetAnimSpeedBody() const;

		///
		///Metoda zwraca wsp�czynnik pr�dko�ci odtwarzania animacji 1.0f - normal speed (head)
		///
		const float GetAnimSpeedHead() const;

		///
		///Metoda ustawia wsp�czynnik pr�dko�ci odtwarzania animacji 1.0f - normal speed (body)
		///
		///@param anim_speed - wsp�czynnik pr�dko�ci odtwarzania animacji
		///
		void SetAnimSpeedBody(float anim_speed);

		///
		///Metoda ustawia wsp�czynnik pr�dko�ci odtwarzania animacji 1.0f - normal speed (head)
		///
		///@param anim_speed - wsp�czynnik pr�dko�ci odtwarzania animacji
		///
		void SetAnimSpeedHead(float anim_speed);

		///
		///Metoda ustawia wsp�czynnik pr�dko�ci odtwarzania animacji 1.0f - normal speed (body and head)
		///
		///@param anim_uniform_speed - wsp�czynnik pr�dko�ci odtwarzania animacji
		///
		void SetAnimSpeed(float anim_uniform_speed);

		///
		///Metoda ustawia wsp�czynnik pr�dko�ci odtwarzania animacji 1.0f - normal speed (body and head)
		///
		///@param anim_speed_body - wsp�czynnik pr�dko�ci odtwarzania animacji (body)
		///
		///@param anim_speed_head - wsp�czynnik pr�dko�ci odtwarzania animacji (head)
		///
		void SetAnimSpeed(float anim_speed_body, float anim_speed_head);

		///
		///Metoda zwraca wska�nik na obiekt klasy CDisplayable (body) /zgodno�� interfejsu/
		///
		CDisplayable *GetDisplayable();
	    
		///
		///Metoda zwraca wska�nik na obiekt klasy CDisplayable (shadow) /zgodno�� interfejsu/
		///
		CDisplayable *GetShadow();

		///
		///Metoda zwraca wska�nik na obiekt klasy CDisplayable (body)
		///
		///@param physical_part - wyliczenie EPhysicalPart - cz�� physical
		///
		CDisplayable *GetDisplayable(EPhysicalPart physical_part);
	    
		///
		///Metoda zwraca wska�nik na obiekt klasy CDisplayable (shadow)
		///
		///@param physical_part - wyliczenie EPhysicalPart - cz�� physical
		///
		CDisplayable *GetShadow(EPhysicalPart physical_part);

		///
		///Metoda zwraca wska�nik na obiekt klasy CDisplayable (body)
		///
		CDisplayable *GetDisplayableBody();
	    
		///
		///Metoda zwraca wska�nik na obiekt klasy CDisplayable (body shadow)
		///
		CDisplayable *GetDisplayableBodyShadow();

		///
		///Metoda zwraca wska�nik na obiekt klasy CDisplayable (head)
		///
		CDisplayable *GetDisplayableHead();

		///
		///Metoda zwraca wska�nik na obiekt klasy CDisplayable (head shadow)
		///
		CDisplayable *GetDisplayableHeadShadow();

		///
		///Metoda ustawia flag� dla obiekt�w gotowych do destrukcji
		///
		void MarkForDelete();
	    
		///
		///Wirtualna metoda zaznacza obiekty do destrukcji
		///
		virtual void Kill();

		///
		///Metoda zwraca flag�, czy obiekt jest gotowy do usuniecia
		///
		virtual bool IsDead();

		///
		///Metoda zwraca nazw� tekstury (body)
		///
		const std::string & GetTextureBody() const;
		
		///
		///Metoda ustatawia nazw� tekstury (body)
		///
		///@param & texture_body - nazwa tekstury (body)
		///
		void SetTextureBody(const std::string & texture_body);

		///
		///Metoda zwraca nazw� tekstury (head)
		///
		const std::string & GetTextureHead() const;
		
		///
		///Metoda ustatwia nazw� tekstury (head)
		///
		///@param & texture_head - nazwa tekstury (head)
		///
		void SetTextureHead(const std::string & texture_head);
		
		///
		///Metoda generuje obraz tekstury
		///
		///@param width - szeroko�� tekstury (obiektu) w pikselach
		///
		///@param height - wysoko�� tekstury (obiektu) w pikselach
		///
		///@param color - & color - sta�a referencja na obiekt klasy sf::Color
		///
		void SetTextureBody(unsigned width, unsigned height, const sf::Color & color = sf::Color(0, 0, 0));

		///
		///Metoda generuje obraz tekstury
		///
		///@param width - szeroko�� tekstury (obiektu) w pikselach
		///
		///@param height - wysoko�� tekstury (obiektu) w pikselach
		///
		///@param r - sk�adowa red koloru
		///
		///@param g - sk�adowa green koloru
		///
		///@param b - sk�adowa blue koloru
		///
		///@param a - sk�adowa alpha koloru
		///
		void SetTextureBody(unsigned width, unsigned height, unsigned r, unsigned g, unsigned b, unsigned a = 255);

		///
		///Metoda generuje obraz tekstury
		///
		///@param width - szeroko�� tekstury (obiektu) w pikselach
		///
		///@param height - wysoko�� tekstury (obiektu) w pikselach
		///
		///@param color - & color - sta�a referencja na obiekt klasy sf::Color
		///
		void SetTextureHead(unsigned width, unsigned height, const sf::Color & color = sf::Color(0, 0, 0));

		///
		///Metoda generuje obraz tekstury
		///
		///@param width - szeroko�� tekstury (obiektu) w pikselach
		///
		///@param height - wysoko�� tekstury (obiektu) w pikselach
		///
		///@param r - sk�adowa red koloru
		///
		///@param g - sk�adowa green koloru
		///
		///@param b - sk�adowa blue koloru
		///
		///@param a - sk�adowa alpha koloru
		///
		void SetTextureHead(unsigned width, unsigned height, unsigned r, unsigned g, unsigned b, unsigned a = 255);

		///
		////Metoda zwraca tryb wyg�adzania tekstury
		///
		const bool getSmoothing() const;

		///
		///Metoda ustawia tryb wyg�adzania tekstury
		///
		///@param smooth - flaga wyg�adzania tekstury
		///
		void setSmoothing(bool smooth);

		///
		///Metoda zwraca statyczny wsp�czynnik wirtualnej wysoko�ci obiektu
		///
		const float GetIncrease() const;

		///
		///Metoda ustawia statyczny wsp�czynnik wirtualnej wysoko�ci obiektu
		///
		///@param increase - wirtualna wysoko�� obiektu
		///
		const void SetIncrease(float increase) const;

		///
		///Metoda zwraca wska�nik na obiekt klasy PhysicalTemplate
		///
		inline PhysicalTemplate *GetTemplate() const { return p_template; }

		///
		///Metoda ustawia wska�nik na obiekt klasy PhysicalTemplate
		///
		///@param *p_template - wska�nik na obiekt klasy PhysicalTemplate
		///
		inline void SetTemplate(PhysicalTemplate* p_template_param) { p_template = p_template_param; }

		///
		///Metoda zwraca opakowanie informacji o kolidowaniu
		///
		CPartCollisionData	& getPartCollisionData();

		///
		///Wirtualna metoda aktualizuj�ca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);

	protected:
	    
		physCategory		m_category;					//kategoria CPhysical
		std::wstring		m_unique_id;				//unikalny identyfikator (nadawany w CPhysicalManager)
		std::wstring		m_genre;					//nazwa "gatunku" obiektu (np. robot, human, gun, etc.)
		float				m_circle_radius;			//promie� detekcji kolizji
		ECollisionShape		m_collision_shape;			//wyliczenie - typ detekcji kolizji
		sf::Vector2f		m_rect_size;				//wektor przechowuj�cy rozmiar obszaru prostok�tnego
		sf::Vector2f		m_rect_size_body;			//wektor przechowuj�cy rozmiar obszaru prostok�tnego - body (wykorzystywany do tworzenia syntetyk�w)
		sf::Vector2f		m_rect_size_head;			//wektor przechowuj�cy rozmiar obszaru prostok�tnego - head (wykorzystywany do tworzenia syntetyk�w)
		PhysicalTemplate*	p_template;					//wska�nik na obiekt klasy PhysicalTemplate
		bool				m_ready_for_destruction;	//flaga ustawia obiekty gotowe do destrukcji
		CPartCollisionData	m_part_collision_data;		//opakowanie informacji o kolidowaniu
		float				m_new_anim_speed;			//wyliczony wsp�czynnik pr�dko�ci odtwarzania animacji

	private:

		int					m_physical_manager_index;	//wyliczony indeks w CPhysicalManager
		CPhysicalData		m_physical_data;			//opakowanie funkcjonalno�ci klasy CPhysical
		bool				m_smooth;					//flaga, czy obiekt wyg�adza piksele tekstury
		static float		m_increase;					//wsp�czynnik wirtualnej wysoko�ci obiektu

	protected:

		///
		///Metoda zwraca wyliczony wsp�czynnik pr�dko�ci animacji dla zadanego czasu trwania jednego obiegu animacji
		///
		///@param anim_time - czas jednego pe�nego obiegu animacji
		///
		const float getCalcualtedAnimSpeed(float anim_time);

		///
		///Metoda zwraca indeks warstwy renderingu obiektu (body)
		///
		const int GetZIndexBody() const;

		///
		///Metoda ustawia indeks warstwy renderingu obiektu (body)
		///
		///@param layer_index - indeks warstwy renderingu obiektu
		///
		void SetZIndexBody(int layer_index);

		///
		///Metoda zwraca indeks warstwy renderingu obiektu (body shadow)
		///
		const int GetZIndexShadowBody() const;

		///
		///Metoda ustawia indeks warstwy renderingu obiektu (body shadow)
		///
		///@param layer_index - indeks warstwy renderingu obiektu
		///
		void SetZIndexShadowBody(int layer_index);

		///
		///Metoda zwraca indeks warstwy renderingu obiektu (head)
		///
		const int GetZIndexHead() const;

		///
		///Metoda ustawia indeks warstwy renderingu obiektu (head)
		///
		///@param layer_index - indeks warstwy renderingu obiektu
		///
		void SetZIndexHead(int layer_index);

		///
		///Metoda zwraca indeks warstwy renderingu obiektu (head shadow)
		///
		const int GetZIndexShadowHead() const;

		///
		///Metoda ustawia indeks warstwy renderingu obiektu (head shadow)
		///
		///@param layer_index - indeks warstwy renderingu obiektu
		///
		void SetZIndexShadowHead(int layer_index);

		///
		///Metoda aktualizuje cie� rzucany przez obiekt i jego nasycenie w zale�no�ci od pory dnia
		///
		///@param dt - czas
		///
		void UpdateShadow(float dt);

	private:

		void CheckDisplayableBody();		//prywatna metoda sprawdza, czy trzeba utworzy�
											//obiekt klasy CDisplayable (body), np. gdy chcemy
											//doda� obrazek, animacj�, etc...

		void CheckDisplayableHead();		//prywatna metoda sprawdza, czy trzeba utworzy�
											//obiekt klasy CDisplayable (head), np. gdy chcemy
											//doda� obrazek, animacj�, etc...

		void UpdateShadowTransformation();	//prywatna metoda dobieraj�ca przesuni�cie cienia
											//w zale�no�ci od wielko�ci obiektu - body and head
											//oraz jego nasycenie w zale�no�ci od pory dnia
											//pozycji s�o�ca (�r�d�a �wiat�a - gwiazd, etc...)

		void CheckShadowOffsetBody();		//prywatna metoda ustala wektor przesuni�cia cienia - body
		void CheckShadowOffsetHead();		//prywatna metoda ustala wektor przesuni�cia cienia - head
		void CheckShadowOffset();			//prywatna metoda ustala wektor przesuni�cia cienia - body and head

	};
}//namespace logic
#endif //H_PHYSICAL_JACK
