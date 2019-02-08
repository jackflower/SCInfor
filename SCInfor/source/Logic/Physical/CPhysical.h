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
		///Deklaracja przyjaŸni
		///
		friend class CPhysicalManager;

		//Aby uzyskaæ obiekt CPhysical, nale¿y wywo³aæ CPhysicalManager::CreatePhysical();

	protected:

		///
		///Chroniony konstruktor domyœlny - u¿ywany wy³¹cznie przez CPhysicalManager
		///
		///@param & uniqueId - sta³a referencja na obiekt klasy std::wstring
		///
		CPhysical(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiuj¹cy
		///
		///@param & CPhysicalCopy - parametr - obiekt klasy CPhysical
		///
		CPhysical(const CPhysical & CPhysicalCopy);

		///
		///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
		///
		virtual ~CPhysical();

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca unikaln¹ nazwê obiektu klasy CPhysical
		///
		const std::wstring & GetUniqueId() const;

		///
		///Metoda zwraca nazwê gatunku
		///
		const std::wstring & GetGenre();

		///
		///Metoda zwraca wagê
		///
		const float getWeight() const;

		///
		///Metoda ustawia wagê
		///
		///@param weight - waga
		///
		void setWeight(float weight);

		///
		///Metoda zwraca kategoriê CPhysical
		///
		physCategory GetCategory();

		///
		///Metoda ustawia kategoriê CPhysical
		///
		///@param category - wyliczenie physCategory
		///
		void SetCategory(physCategory category);

		///
		///Metoda ustawia kategoriê CPhysical
		///
		///@param & category_name - sta³a referecnaj na obiekt klasy std::wstring
		///
		void SetCategory(const std::wstring & category_name);

		///
		///Metoda ustawia nazwê gatunku
		///
		///@param & genre - sta³a referencja na obiekt klasy std::wstring
		///
		void SetGenre(const std::wstring & genre);

		///
		///Metoda zwraca pozycjê obiektu
		///
		const sf::Vector2f & GetPosition() const;

		///
		///Metoda ustawia pozycjê obiektu
		///
		///@param x - wspó³rzêdna x obiektu
		///
		///@param y - wspó³rzêdna y obiektu
		///
		///@param change_old_position - flaga, czy aktualizowaæ m_old_position
		///
		void SetPosition(float x, float y, bool change_old_position = false);

		///
		///Metoda ustawia pozycjê obiektu
		///
		///@param &vector - sta³a referenacja na obiekt klasy sf::Vector2f
		///
		///@param change_old_position - flaga, czy aktualizowaæ m_old_position
		///
		void SetPosition(const sf::Vector2f& new_value, bool change_old_position = false);

		///
		///Metoda zwraca pozycjê przed aktualizacj¹ logiki m_old_position
		///
		const sf::Vector2f & GetOldPosition() const;

		///
		///Metoda zwraca skalê (body)
		///
		const sf::Vector2f & GetScaleBody() const;
		
		///
		///Metoda ustawia skalê (body)
		///
		///@param scale_X - wartoœæ X
		///
		///@param scale_Y - wartoœæ Y
		///
		void SetScaleBody(float scale_X, float scale_Y);
		
		///
		///Metoda ustawia skalê (body)
		///
		///@param & scale_vector - wektor skali - sta³a referencja na obiekt klasy sf::Vector2f
		///
		void SetScaleBody(const sf::Vector2f & scale_vector);

		///
		///Metoda zwraca skalê (head)
		///
		const sf::Vector2f & GetScaleHead() const;

		///
		///Metoda ustawia skalê (head)
		///
		///@param scale_X - wartoœæ X
		///
		///@param scale_Y - wartoœæ Y
		///
		void SetScaleHead(float scale_X, float scale_Y);

		///
		///Metoda ustawia skalê (head)
		///
		///@param & scale_vector - wektor skali - sta³a referencja na obiekt klasy sf::Vector2f
		///
		void SetScaleHead(const sf::Vector2f & scale_vector);

		///
		///Metoda ustawia skalê (body and head)
		///
		///@param scale_X - wartoœæ X
		///
		///@param scale_Y - wartoœæ Y
		///
		void SetScale(float scale_X, float scale_Y);

		///
		///Metoda ustawia skalê (body and head)
		///
		///@param &scale - wektor skali - sta³a referencja na obiekt klasy sf::Vector2f
		///
		void SetScale(const sf::Vector2f & scale);

		///
		///Metoda ustawia skalê
		///
		///@param uniform - jednolita wartoœæ skaluj¹ca w osi x i y
		///
		void SetScale(float uniform);

		///
		///Metoda zwraca wartoœæ obrotu obiektu w stopniach (body and head)
		///
		const float GetRotation() const;

		///
		///Metoda ustawia wartoœæ obrotu obiektu w stopniach (body and head)
		///
		///@param rotation_uniform - wartoœæ obrotu obiektu (body and head)
		///
		void SetRotation(float rotation_uniform);

		///
		///Metoda zwraca wartoœæ obrotu obiektu w stopniach (body)
		///
		const float GetRotationBody() const;

		///
		///Metoda ustawia wartoœæ obrotu obiektu w stopniach (body)
		///
		///@param rotation_body - wartoœæ obrotu obiektu (body)
		///
		void SetRotationBody(float rotation_body);

		///
		///Metoda zwraca wartoœæ obrotu obiektu w stopniach (head)
		///
		const float GetRotationHead() const;

		///
		///Metoda ustawia wartoœæ obrotu obiektu w stopniach (head)
		///
		///@param rotation_head - wartoœæ obrotu obiektu (head)
		///
		void SetRotationHead(float rotation_head);

		///
		///Metoda obraca obiekt o zadany k¹t (body)
		///
		///@param angle - wartoœæ obrotu
		///
		void RotateBody(float angle);

		///
		///Metoda obraca obiekt o zadany k¹t (head)
		///
		///@param angle - wartoœæ obrotu
		///
		void RotateHead(float angle);

		///
		///Metoda obraca obiekt o zadany k¹t (body and head)
		///
		///@param angle - wartoœæ obrotu
		///
		void Rotate(float angle);

		///
		///Metoda zwraca prêdkoœæ obiektu
		///
		const sf::Vector2f & GetVelocity() const;

		///
		///Metoda ustawia prêdkoœæ obiektu
		///
		///@param velocity - sta³a referencja na obiekt klasy sf::Vector2f
		///
		void SetVelocity(const sf::Vector2f & velocity);

		///
		///Metoda zwraca promieñ detekcji wykorzystywany przy liczeniu kolizji
		///
		float GetCircleRadius();

		///
		///Metoda zwraca wyliczenie - typ liczenia kolizji
		///
		ECollisionShape GetCollisionShape();

		///
		///Wirtualna metoda ustawiaj¹ca wartoœæ promienia detekcji wykorzystywan¹ przy liczeniu kolizji
		///
		///@param radius - promieñ detekcji
		///
		virtual void SetBoundingCircle(float radius);

		///
		///Metoda ustawia wartoœæ obszaru prostok¹tnego detekcji wykorzystywany przy liczeniu kolizji
		///
		///@param &rect_size - sta³a referencja wektor dla obszaru prostok¹tnego detekcji wykorzystywany przy liczeniu kolizji
		///
		void SetBoundingRect(const sf::Vector2f & rect_size);

		///
		///Metoda zwraca wektor dla obszaru prostok¹tnego detekcji wykorzystywany przy liczeniu kolizji
		///
		const sf::Vector2f & GetRectSize() const ;

		///
		///Metoda zwraca sta³¹ referencjê na wektor wielkoœci obiektu
		///wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
		///klasy CDisplayable
		///
		const sf::Vector2f & GetRectangleSizeBody() const;

		///
		///Metoda ustawia referencjê na wektor wielkoœci obiektu
		///wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
		///klasy CDisplayable
		///
		///@param & rect_size_body - sta³¹ referencja na obiekt klasy sf::Vector2f
		///
		void SetRectangleSizeBody(const sf::Vector2f & rect_size_body);
	
		///
		///Metoda ustawia referencjê na wektor wielkoœci obiektu
		///wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
		///klasy CDisplayable
		///
		///@param rect_size_body_width - szerokoœc tekstury (wymaga rzutowania na typ ca³kowity)
		///
		///@param rect_size_body_height - wysokoœæ tekstury (wymaga rzutowania na typ ca³kowity)
		///
		void SetRectangleSizeBody(float rect_size_body_width, float rect_size_body_height);
		
		///
		///Metoda zwraca sta³¹ referencjê na wektor wielkoœci obiektu
		///wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
		///klasy CDisplayable
		///
		const sf::Vector2f & GetRectangleSizeHead() const;

		///
		///Metoda ustawia referencjê na wektor wielkoœci obiektu
		///wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
		///klasy CDisplayable
		///
		///@param & rect_size_head - sta³¹ referencja na obiekt klasy sf::Vector2f
		///
		void SetRectangleSizeHead(const sf::Vector2f & rect_size_head);

		///
		///Metoda ustawia referencjê na wektor wielkoœci obiektu
		///wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
		///klasy CDisplayable
		///
		///@param rect_size_head_width - szerokoœc tekstury (wymaga rzutowania na typ ca³kowity)
		///
		///@param rect_size_head_height - wysokoœæ tekstury (wymaga rzutowania na typ ca³kowity)
		///
		void SetRectangleSizeHead(float rect_size_head_width, float rect_size_head_height);
		
		///
		///Metoda ustawia referencjê na wektor wielkoœci obiektu
		///wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
		///klasy CDisplayable - body and head
		///
		///@param & rect_size_uniform - sta³¹ referencja na obiekt klasy sf::Vector2f
		///
		void SetRectangleSize(const sf::Vector2f & rect_size_uniform);

		///
		///Metoda ustawia referencjê na wektor wielkoœci obiektu
		///wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
		///klasy CDisplayable - body and head
		///
		///@param rect_size_uniform_width - szerokoœc tekstury (wymaga rzutowania na typ ca³kowity)
		///
		///@param rect_size_uniform_height - wysokoœæ tekstury (wymaga rzutowania na typ ca³kowity)
		///
		void SetRectangleSize(float rect_size_uniform_width, float rect_size_uniform_height);
		
		///
		///Metoda ustawia referencjê na wektor wielkoœci obiektu
		///wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
		///klasy CDisplayable - body and head
		///
		///@param & rect_size_body - sta³¹ referencja na obiekt klasy sf::Vector2f
		///
		///@param & rect_size_head - sta³¹ referencja na obiekt klasy sf::Vector2f
		///
		void SetRectangleSize(const sf::Vector2f & rect_size_body, const sf::Vector2f & rect_size_head);
		
		///
		///Metoda ustawia referencjê na wektor wielkoœci obiektu
		///wykorzytywana przy tworzeniu syntetyków - tekstur dla obiektów
		///klasy CDisplayable - body and head
		///
		///@param rect_size_body_width - szerokoœc tekstury (wymaga rzutowania na typ ca³kowity)
		///
		///@param rect_size_body_height - wysokoœæ tekstury (wymaga rzutowania na typ ca³kowity)
		///
		///@param rect_size_head_width - wysokoœæ tekstury (wymaga rzutowania na typ ca³kowity)
		///
		///@param rect_size_head_height - wysokoœæ tekstury (wymaga rzutowania na typ ca³kowity)
		///
		void SetRectangleSize(float rect_size_body_width, float rect_size_body_height, float rect_size_head_width, float rect_size_head_height);

		///
		///Metoda zwraca wartoœæ pu³apu obiektu
		///
		const float GetAltitude() const;

		///
		///Metoda ustawia wartoœæ pu³apu obiektu
		///
		///@param altitude - wartoœæ pu³apu obiektu
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
		///Metoda ustawia oryginalny kolor obiektu za³adowany z tekstury - body and head
		///
		void RestoreColor();

		///
		///Metoda ustawia oryginalny kolor obiektu za³adowany z tekstury - body
		///
		void RestoreColorBody();

		///
		///Metoda ustawia oryginalny kolor obiektu za³adowany z tekstury - head
		///
		void RestoreColorHead();

		///
		///Metoda ustawia kolor do zapamiêtania - body
		///
		const sf::Color & GetStoredColorBody() const;

		///
		///Metoda ustawia kolor do zapamiêtania - body
		///
		///@param & color_stored_body - sta³a referencja na obiekt klasy sf::Color
		///
		void StoreColorBody(const sf::Color & color_stored_body);

		///
		///Metoda ustawia kolor do zapamiêtania - body
		///
		const sf::Color & GetStoredColorHead() const;

		///
		///Metoda ustawia kolor do zapamiêtania - body
		///
		///@param & color_stored_head - sta³a referencja na obiekt klasy sf::Color
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
		///Metoda zwraca wektor przesuniêcia cienia wzglêdem obiektu - body
		///
		sf::Vector2f & GetShadowOffsetBody();

		///
		///Metoda ustawia wektor przesuniêcia cienia wzglêdem obiektu - body
		///
		///@param & shadow_offset_body - sta³a referencja na wektor przesuniêcia cienia wzglêdem obiektu
		///
		void SetShadowOffsetBody(sf::Vector2f & shadow_offset_body);

		///
		///Metoda zwraca wektor przesuniêcia cienia wzglêdem obiektu - head
		///
		sf::Vector2f & GetShadowOffsetHead();

		///
		///Metoda ustawia wektor przesuniêcia cienia wzglêdem obiektu - head
		///
		///@param & shadow_offset_head - sta³a referencja na wektor przesuniêcia cienia wzglêdem obiektu
		///
		void SetShadowOffsetHead(sf::Vector2f & shadow_offset_head);
		
		///
		///Metoda zwraca flagê, czy obiekt generuje reprezentacjê graficzn¹ (body and head) /zgodnoœæ interfejsu/
		///
		const bool GetUseDisplayable() const;

		///
		///Metoda zwraca flagê, czy CPhysical ma reprezentacjê graficz¹ (body)
		///
		const bool GetUseDisplayableBody() const;

		///
		///Metoda zwraca flagê, czy CPhysical ma reprezentacjê graficz¹ (head)
		///
		const bool GetUseDisplayableHead() const;

		///
		///Metoda ustawia flagê, czy CPhysical ma reprezentacjê graficz¹ (body and head)
		///
		///@param use_displayable - flaga, czy obiekt ma u¿ywaæ reprezentacji graficznej
		///
		void SetUseDisplayable(const bool use_displayable);

		///
		///Metoda ustawia flagê, czy CPhysical ma reprezentacjê graficz¹ (body)
		///
		///@param use_displayable_body - flaga, czy obiekt ma u¿ywaæ reprezentacji graficznej
		///
		void SetUseDisplayableBody(const bool use_displayable_body);

		///
		///Metoda ustawia flagê, czy CPhysical ma reprezentacjê graficz¹ (head)
		///
		///@param use_displayable_head - flaga, czy obiekt ma u¿ywaæ reprezentacji graficznej
		///
		void SetUseDisplayableHead(const bool use_displayable_head);

		///
		///Metoda zwraca flagê, czy obiekt generuje cieñ (body and head) /zgodnoœæ interfejsu/
		///
		const bool GetUseShadow() const;

		///
		///Metoda zwraca flagê, czy obiekt generuje cieñ (body)
		///
		const bool GetUseShadowBody() const;

		///
		///Metoda zwraca flagê, czy obiekt generuje cieñ (head)
		///
		const bool GetUseShadowHead() const;

		///
		///Metoda ustawia flagê, czy obiekt ma generowaæ cieñ (body and head) /zgodnoœæ interfejsu/
		///
		///@param use_shadow - flaga, czy obiekt ma generowaæ cieñ (body and head) /zgodnoœæ interfejsu/
		///
		void SetUseShadow(const bool use_shadow);

		///
		///Metoda ustawia flagê, czy obiekt ma generowaæ cieñ (body)
		///
		///@param use_shadow_body - flaga, czy obiekt ma generowaæ cieñ (body)
		///
		void SetUseShadowBody(const bool use_shadow_body);

		///
		///Metoda ustawia flagê, czy obiekt ma generowaæ cieñ (head)
		///
		///@param use_shadow_head - flaga, czy obiekt ma generowaæ cieñ (head)
		///
		void SetUseShadowHead(const bool use_shadow_head);

		///
		///Metoda zwraca wskaŸnik na animacjê (body)
		///
		CAnimation *GetAnimationBody();

		///
		///Metoda ustawia ustawia wskaŸnik na animacjê (body)
		///
		///@param *p_anim_body - wskaŸnik na animacjê - obiekt klasy CAnimation (body)
		///
		void SetAnimationBody(CAnimation* p_anim_body);

		///
		///Metoda zwraca nazwê animacji (body)
		///
		const std::string & GetAnimationBodyName() const;

		///
		///Metoda ustawia nazwê animacji (body)
		///
		///@param & anim_body_name - nazwa animacji (body)
		///
		void SetAnimationBody(const std::string & anim_body_name);

		///
		///Metoda zwraca wskaŸnik na animacjê (head)
		///
		CAnimation *GetAnimationHead();

		///
		///Metoda ustawia ustawia wskaŸnik na animacjê (head)
		///
		///@param *p_anim_head - wskaŸnik na animacjê - obiekt klasy CAnimation (head)
		///
		void SetAnimationHead(CAnimation *p_anim_head);

		///
		///Metoda zwraca nazwê animacji (head)
		///
		const std::string & GetAnimationHeadName() const;

		///
		///Metoda ustawia nazwê animacji (head)
		///
		///@param & anim_head_name - nazwa animacji (head)
		///
		void SetAnimationHead(const std::string & anim_head_name);

		///
		///Metoda ustawia komplet animacji
		///
		///@param *p_anim_body - wskaŸnik na obiekt klasy CAnimation (body)
		///
		///@param *p_anim_head - wskaŸnik na obiekt klasy CAnimation (head)
		///
		void SetAnimation(CAnimation *p_anim_body, CAnimation *p_anim_head);

		///
		///Metoda ustawia komplet animacji
		///
		///@param & anim_name_body - sta³a referencja na obiekt klasy std::string - nazwa animacji (body)
		///
		///@param & anim_name_head - sta³a referencja na obiekt klasy std::string - nazwa animacji (head)
		///
		void SetAnimation(const std::string & anim_name_body, const std::string & anim_name_head);
	    
		///
		///Metoda zwraca pamiêtany wspó³czynnik prêdkoœci odtwarzania animacji (body)
		///
		const float GetStoredAnimSpeedBody() const;

		///
		///Metoda zwraca pamiêtany wspó³czynnik prêdkoœci odtwarzania animacji (body)
		///
		const float GetStoredAnimSpeedHead() const;

		///
		///Metoda zwraca wspó³czynnik prêdkoœci odtwarzania animacji 1.0f - normal speed (body)
		///
		const float GetAnimSpeedBody() const;

		///
		///Metoda zwraca wspó³czynnik prêdkoœci odtwarzania animacji 1.0f - normal speed (head)
		///
		const float GetAnimSpeedHead() const;

		///
		///Metoda ustawia wspó³czynnik prêdkoœci odtwarzania animacji 1.0f - normal speed (body)
		///
		///@param anim_speed - wspó³czynnik prêdkoœci odtwarzania animacji
		///
		void SetAnimSpeedBody(float anim_speed);

		///
		///Metoda ustawia wspó³czynnik prêdkoœci odtwarzania animacji 1.0f - normal speed (head)
		///
		///@param anim_speed - wspó³czynnik prêdkoœci odtwarzania animacji
		///
		void SetAnimSpeedHead(float anim_speed);

		///
		///Metoda ustawia wspó³czynnik prêdkoœci odtwarzania animacji 1.0f - normal speed (body and head)
		///
		///@param anim_uniform_speed - wspó³czynnik prêdkoœci odtwarzania animacji
		///
		void SetAnimSpeed(float anim_uniform_speed);

		///
		///Metoda ustawia wspó³czynnik prêdkoœci odtwarzania animacji 1.0f - normal speed (body and head)
		///
		///@param anim_speed_body - wspó³czynnik prêdkoœci odtwarzania animacji (body)
		///
		///@param anim_speed_head - wspó³czynnik prêdkoœci odtwarzania animacji (head)
		///
		void SetAnimSpeed(float anim_speed_body, float anim_speed_head);

		///
		///Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (body) /zgodnoœæ interfejsu/
		///
		CDisplayable *GetDisplayable();
	    
		///
		///Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (shadow) /zgodnoœæ interfejsu/
		///
		CDisplayable *GetShadow();

		///
		///Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (body)
		///
		///@param physical_part - wyliczenie EPhysicalPart - czêœæ physical
		///
		CDisplayable *GetDisplayable(EPhysicalPart physical_part);
	    
		///
		///Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (shadow)
		///
		///@param physical_part - wyliczenie EPhysicalPart - czêœæ physical
		///
		CDisplayable *GetShadow(EPhysicalPart physical_part);

		///
		///Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (body)
		///
		CDisplayable *GetDisplayableBody();
	    
		///
		///Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (body shadow)
		///
		CDisplayable *GetDisplayableBodyShadow();

		///
		///Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (head)
		///
		CDisplayable *GetDisplayableHead();

		///
		///Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (head shadow)
		///
		CDisplayable *GetDisplayableHeadShadow();

		///
		///Metoda ustawia flagê dla obiektów gotowych do destrukcji
		///
		void MarkForDelete();
	    
		///
		///Wirtualna metoda zaznacza obiekty do destrukcji
		///
		virtual void Kill();

		///
		///Metoda zwraca flagê, czy obiekt jest gotowy do usuniecia
		///
		virtual bool IsDead();

		///
		///Metoda zwraca nazwê tekstury (body)
		///
		const std::string & GetTextureBody() const;
		
		///
		///Metoda ustatawia nazwê tekstury (body)
		///
		///@param & texture_body - nazwa tekstury (body)
		///
		void SetTextureBody(const std::string & texture_body);

		///
		///Metoda zwraca nazwê tekstury (head)
		///
		const std::string & GetTextureHead() const;
		
		///
		///Metoda ustatwia nazwê tekstury (head)
		///
		///@param & texture_head - nazwa tekstury (head)
		///
		void SetTextureHead(const std::string & texture_head);
		
		///
		///Metoda generuje obraz tekstury
		///
		///@param width - szerokoœæ tekstury (obiektu) w pikselach
		///
		///@param height - wysokoœæ tekstury (obiektu) w pikselach
		///
		///@param color - & color - sta³a referencja na obiekt klasy sf::Color
		///
		void SetTextureBody(unsigned width, unsigned height, const sf::Color & color = sf::Color(0, 0, 0));

		///
		///Metoda generuje obraz tekstury
		///
		///@param width - szerokoœæ tekstury (obiektu) w pikselach
		///
		///@param height - wysokoœæ tekstury (obiektu) w pikselach
		///
		///@param r - sk³adowa red koloru
		///
		///@param g - sk³adowa green koloru
		///
		///@param b - sk³adowa blue koloru
		///
		///@param a - sk³adowa alpha koloru
		///
		void SetTextureBody(unsigned width, unsigned height, unsigned r, unsigned g, unsigned b, unsigned a = 255);

		///
		///Metoda generuje obraz tekstury
		///
		///@param width - szerokoœæ tekstury (obiektu) w pikselach
		///
		///@param height - wysokoœæ tekstury (obiektu) w pikselach
		///
		///@param color - & color - sta³a referencja na obiekt klasy sf::Color
		///
		void SetTextureHead(unsigned width, unsigned height, const sf::Color & color = sf::Color(0, 0, 0));

		///
		///Metoda generuje obraz tekstury
		///
		///@param width - szerokoœæ tekstury (obiektu) w pikselach
		///
		///@param height - wysokoœæ tekstury (obiektu) w pikselach
		///
		///@param r - sk³adowa red koloru
		///
		///@param g - sk³adowa green koloru
		///
		///@param b - sk³adowa blue koloru
		///
		///@param a - sk³adowa alpha koloru
		///
		void SetTextureHead(unsigned width, unsigned height, unsigned r, unsigned g, unsigned b, unsigned a = 255);

		///
		////Metoda zwraca tryb wyg³adzania tekstury
		///
		const bool getSmoothing() const;

		///
		///Metoda ustawia tryb wyg³adzania tekstury
		///
		///@param smooth - flaga wyg³adzania tekstury
		///
		void setSmoothing(bool smooth);

		///
		///Metoda zwraca statyczny wspó³czynnik wirtualnej wysokoœci obiektu
		///
		const float GetIncrease() const;

		///
		///Metoda ustawia statyczny wspó³czynnik wirtualnej wysokoœci obiektu
		///
		///@param increase - wirtualna wysokoœæ obiektu
		///
		const void SetIncrease(float increase) const;

		///
		///Metoda zwraca wskaŸnik na obiekt klasy PhysicalTemplate
		///
		inline PhysicalTemplate *GetTemplate() const { return p_template; }

		///
		///Metoda ustawia wskaŸnik na obiekt klasy PhysicalTemplate
		///
		///@param *p_template - wskaŸnik na obiekt klasy PhysicalTemplate
		///
		inline void SetTemplate(PhysicalTemplate* p_template_param) { p_template = p_template_param; }

		///
		///Metoda zwraca opakowanie informacji o kolidowaniu
		///
		CPartCollisionData	& getPartCollisionData();

		///
		///Wirtualna metoda aktualizuj¹ca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);

	protected:
	    
		physCategory		m_category;					//kategoria CPhysical
		std::wstring		m_unique_id;				//unikalny identyfikator (nadawany w CPhysicalManager)
		std::wstring		m_genre;					//nazwa "gatunku" obiektu (np. robot, human, gun, etc.)
		float				m_circle_radius;			//promieñ detekcji kolizji
		ECollisionShape		m_collision_shape;			//wyliczenie - typ detekcji kolizji
		sf::Vector2f		m_rect_size;				//wektor przechowuj¹cy rozmiar obszaru prostok¹tnego
		sf::Vector2f		m_rect_size_body;			//wektor przechowuj¹cy rozmiar obszaru prostok¹tnego - body (wykorzystywany do tworzenia syntetyków)
		sf::Vector2f		m_rect_size_head;			//wektor przechowuj¹cy rozmiar obszaru prostok¹tnego - head (wykorzystywany do tworzenia syntetyków)
		PhysicalTemplate*	p_template;					//wskaŸnik na obiekt klasy PhysicalTemplate
		bool				m_ready_for_destruction;	//flaga ustawia obiekty gotowe do destrukcji
		CPartCollisionData	m_part_collision_data;		//opakowanie informacji o kolidowaniu
		float				m_new_anim_speed;			//wyliczony wspó³czynnik prêdkoœci odtwarzania animacji

	private:

		int					m_physical_manager_index;	//wyliczony indeks w CPhysicalManager
		CPhysicalData		m_physical_data;			//opakowanie funkcjonalnoœci klasy CPhysical
		bool				m_smooth;					//flaga, czy obiekt wyg³adza piksele tekstury
		static float		m_increase;					//wspó³czynnik wirtualnej wysokoœci obiektu

	protected:

		///
		///Metoda zwraca wyliczony wspó³czynnik prêdkoœci animacji dla zadanego czasu trwania jednego obiegu animacji
		///
		///@param anim_time - czas jednego pe³nego obiegu animacji
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
		///Metoda aktualizuje cieñ rzucany przez obiekt i jego nasycenie w zale¿noœci od pory dnia
		///
		///@param dt - czas
		///
		void UpdateShadow(float dt);

	private:

		void CheckDisplayableBody();		//prywatna metoda sprawdza, czy trzeba utworzyæ
											//obiekt klasy CDisplayable (body), np. gdy chcemy
											//dodaæ obrazek, animacjê, etc...

		void CheckDisplayableHead();		//prywatna metoda sprawdza, czy trzeba utworzyæ
											//obiekt klasy CDisplayable (head), np. gdy chcemy
											//dodaæ obrazek, animacjê, etc...

		void UpdateShadowTransformation();	//prywatna metoda dobieraj¹ca przesuniêcie cienia
											//w zale¿noœci od wielkoœci obiektu - body and head
											//oraz jego nasycenie w zale¿noœci od pory dnia
											//pozycji s³oñca (Ÿród³a œwiat³a - gwiazd, etc...)

		void CheckShadowOffsetBody();		//prywatna metoda ustala wektor przesuniêcia cienia - body
		void CheckShadowOffsetHead();		//prywatna metoda ustala wektor przesuniêcia cienia - head
		void CheckShadowOffset();			//prywatna metoda ustala wektor przesuniêcia cienia - body and head

	};
}//namespace logic
#endif //H_PHYSICAL_JACK
