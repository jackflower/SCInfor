//  __________________________________________
// | CPhysicalData.h - class definition       |
// | Jack Flower - June 2016                  |
// |__________________________________________|
//

#ifndef H_PHYSICAL_DATA_JACK
#define H_PHYSICAL_DATA_JACK

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Color.hpp>
#include "../../Physics/CPhysicsData.h"
#include "../../../RTTI/RTTI.h"
#include "../../../Logic/Physical/EPhysicalPart.h"
#include "../../../ResourceManager/CTexture.h"

using namespace resource;

///
///Forward declaration
///
namespace rendering
{
	namespace displayable
	{
		class CDisplayable;
	}
}

///
///Forward declaration
///
namespace rendering
{
	namespace animation
	{
		class CAnimation;
		class CAnimationState;
	}
}

using namespace rendering::displayable;
using namespace rendering::animation;
using namespace resource;
using namespace physics;
using namespace logic;

namespace physicaldata
{
	///
	///Klasa reprezentuje opakowanie funkcjonalnoœci klasy CPhysical
	///
	class CPhysicalData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CPhysicalData();

		///
		///Konstruktor kopiuj¹cy
		///
		///@param & CPhysicalDataCopy - sta³a referencja na obiekt klasy CPhysicalData
		///
		CPhysicalData(const CPhysicalData & CPhysicalDataCopy);

		///
		///Destruktor
		///
		~CPhysicalData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

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
		///Metoda zwraca pozycjê przed aktualizacj¹ logiki m_old_position
		///
		void SetOldPosition(const sf::Vector2f & old_position);

		///
		///Metoda ustawia pozycjê obiektu
		///
		///@param x - wspó³rzêdna x obiektu
		///
		///@param y - wspó³rzêdna y obiektu
		///
		///@param change_old_position - flaga, czy aktualizowaæ m_old_position
		///
		void SetOldPosition(float x, float y, bool change_old_position = false);

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
		///Metoda zwraca flagê, czy obiekt ma reprezentacjê graficzn¹ (body and head) /zgodnoœæ interfejsu/
		///
		const bool GetUseDisplayable() const;

		///
		///Metoda zwraca flagê, czy obiekt ma reprezentacjê graficz¹ (body)
		///
		const bool GetUseDisplayableBody() const;

		///
		///Metoda zwraca flagê, czy obiekt ma reprezentacjê graficz¹ (head)
		///
		const bool GetUseDisplayableHead() const;

		///
		///Metoda ustawia flagê, czy obiekt ma reprezentacjê graficz¹ (body and head)
		///
		///@param use_displayable - flaga, czy obiekt ma u¿ywaæ reprezentacji graficznej
		///
		void SetUseDisplayable(const bool use_displayable);

		///
		///Metoda ustawia flagê, czy obiekt ma reprezentacjê graficz¹ (body)
		///
		///@param use_displayable_body - flaga, czy obiekt ma u¿ywaæ reprezentacji graficznej
		///
		void SetUseDisplayableBody(const bool use_displayable_body);

		///
		///Metoda ustawia flagê, czy obiekt ma reprezentacjê graficz¹ (head)
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
		///Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (body) /zgodnoœæ interfejsu/
		///
		CDisplayable *GetDisplayable();

		///
		///Metoda ustawia wskaŸnik na obiekt klasy CDisplayable (body) /zgodnoœæ interfejsu/
		///
		///@param * displayable - wskaŸnika na obiekt klasy CDisplayable
		///
		void SetDisplayable(CDisplayable *displayable);

		///
		///Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (shadow) /zgodnoœæ interfejsu/
		///
		CDisplayable *GetShadow();

		///
		///Metoda ustawia wskaŸnik na obiekt klasy CDisplayable (body) /zgodnoœæ interfejsu/
		///
		///@param * displayable_shadow - wskaŸnika na obiekt klasy CDisplayable
		///
		void SetShadow(CDisplayable *displayable_shadow);

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
		CDisplayable *GetDisplayableBody() const;

		///
		///Metoda ustawia wskaŸnik na obiekt klasy CDisplayable (body)
		///
		///@param * displayable_body - wskaŸnika na obiekt klasy CDisplayable
		///
		void SetDisplayableBody(CDisplayable *displayable_body);

		///
		///Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (body shadow)
		///
		CDisplayable *GetDisplayableBodyShadow() const;

		///
		///Metoda ustawia wskaŸnik na obiekt klasy CDisplayable (body)
		///
		///@param * displayable_body_shadow - wskaŸnika na obiekt klasy CDisplayable
		///
		void SetDisplayableBodyShadow(CDisplayable *displayable_body_shadow);

		///
		///Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (head)
		///
		CDisplayable *GetDisplayableHead() const;

		///
		///Metoda ustawia wskaŸnik na obiekt klasy CDisplayable (body)
		///
		///@param * displayable_head - wskaŸnika na obiekt klasy CDisplayable
		///
		void SetDisplayableHead(CDisplayable *displayable_head);

		///
		///Metoda zwraca wskaŸnik na obiekt klasy CDisplayable (head shadow)
		///
		CDisplayable *GetDisplayableHeadShadow() const;

		///
		///Metoda ustawia wskaŸnik na obiekt klasy CDisplayable (body)
		///
		///@param * displayable_head_shadow - wskaŸnika na obiekt klasy CDisplayable
		///
		void SetDisplayableHeadShadow(CDisplayable *displayable_head_shadow);

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
		const sf::Color & GetStoredColorHead() const;

		///
		///Metoda ustawia kolor do zapamiêtania - body
		///
		///@param & color_stored_body - sta³a referencja na obiekt klasy sf::Color
		///
		void StoreColorBody(const sf::Color & color_stored_body);

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
		///@param &shadow_offset_body - sta³a referencja na wektor przesuniêcia cienia wzglêdem obiektu
		///
		void SetShadowOffsetBody(sf::Vector2f & shadow_offset_body);

		///
		///Metoda ustawia wektor przesuniêcia cienia wzglêdem obiektu - body
		///
		///@param shadow_offset_body_x - sk³adowa X
		///
		///@param shadow_offset_body_y - sk³adowa Y
		///
		void SetShadowOffsetBody(float shadow_offset_body_x, float shadow_offset_body_y);

		///
		///Metoda zwraca wektor przesuniêcia cienia wzglêdem obiektu - head
		///
		sf::Vector2f & GetShadowOffsetHead();

		///
		///Metoda ustawia wektor przesuniêcia cienia wzglêdem obiektu - head
		///
		///@param &shadow_offset_head - sta³a referencja na wektor przesuniêcia cienia wzglêdem obiektu
		///
		void SetShadowOffsetHead(sf::Vector2f & shadow_offset_head);

		///
		///Metoda ustawia wektor przesuniêcia cienia wzglêdem obiektu - hrad
		///
		///@param shadow_offset_body_x - sk³adowa X
		///
		///@param shadow_offset_body_y - sk³adowa Y
		///
		void SetShadowOffsetHead(float shadow_offset_head_x, float shadow_offset_head_y);


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

		//wrapper - physics...

		///
		///Metoda zwraca zapamiêtan¹ skalê (body)
		///
		const sf::Vector2f & GetStoredScaleBody() const;

		///
		///Metoda ustawia zapamiêtan¹ skalê (body)
		///
		///@param stored_scale_X - wartoœæ X
		///
		///@param stored_scale_Y - wartoœæ Y
		///
		void SetStoredScaleBody(float stored_scale_X, float stored_scale_Y);

		///
		///Metoda ustawia zapamiêtan¹ skalê (body)
		///
		///@param & stored_scale_vector - wektor skali - sta³a referencja na obiekt klasy sf::Vector2f
		///
		void SetStoredScaleBody(const sf::Vector2f & stored_scale_vector);

		///
		///Metoda zwraca zapamiêtan¹ skalê (head)
		///
		const sf::Vector2f & GetStoredScaleHead() const;

		///
		///Metoda ustawia zapamiêtan¹ skalê (head)
		///
		///@param stored_scale_X - wartoœæ X
		///
		///@param stored_scale_Y - wartoœæ Y
		///
		void SetStoredScaleHead(float stored_scale_X, float stored_scale_Y);

		///
		///Metoda ustawia zapamiêtan¹ skalê (head)
		///
		///@param & stored_scale_vector - wektor skali - sta³a referencja na obiekt klasy sf::Vector2f
		///
		void SetStoredScaleHead(const sf::Vector2f & stored_scale_vector);

		///
		///Metoda ustawia zapamiêtan¹ skalê (body and head)
		///
		///@param stored_scale_X - wartoœæ X
		///
		///@param stored_scale_Y - wartoœæ Y
		///
		void SetStoredScale(float stored_scale_X, float stored_scale_Y);

		///
		///Metoda ustawia zapamiêtan¹ skalê (body and head)
		///
		///@param & stored_scale - wektor skali - sta³a referencja na obiekt klasy sf::Vector2f
		///
		void SetStoredScale(const sf::Vector2f & stored_scale);

		///
		///Metoda ustawia zapamiêtan¹ skalê
		///
		///@param stored_uniform - jednolita wartoœæ skaluj¹ca w osi x i y
		///
		void SetStoredScale(float stored_uniform);

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

		//wrapper = animation

		///
		///Metoda sprawdza, czy trzeba utworzyæ obiekt klasy CDisplayable (body)
		///np. gdy chcemy dodaæ obrazek, animacjê, etc...
		///
		void CheckDisplayableBody();

		///
		///Metoda sprawdza, czy trzeba utworzyæ obiekt klasy CDisplayable (head)
		///np. gdy chcemy dodaæ obrazek, animacjê, etc...
		///
		void CheckDisplayableHead();

		///
		///Metoda ustala wektor przesuniêcia cienia - body
		///
		void CheckShadowOffsetBody();

		///
		///Metoda ustala wektor przesuniêcia cienia - head
		///
		void CheckShadowOffsetHead();

		///
		///Metoda ustala wektor przesuniêcia cienia - body and head
		///
		void CheckShadowOffset();

		///
		///Metoda aktualizuje transformacjê cienia
		///
		void UpdateShadowTransformation();

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

	private:

		CPhysicsData		m_physics_data;				//opakowanie informacji o fizyce
		bool				m_use_displayable_body;		//flaga okreœla, czy obiekt posiada reprezentacjê graficzn¹ - body
		bool				m_use_shadow_body;			//flaga okreœla, czy obiekt posiada reprezentacjê graficzn¹ - body - cieñ
		bool				m_use_displayable_head;		//flaga okreœla, czy obiekt posiada reprezentacjê graficzn¹ - head
		bool				m_use_shadow_head;			//flaga okreœla, czy obiekt posiada reprezentacjê graficzn¹ - head - cieñ
		CDisplayable*		p_displayable_body;			//wskaŸnik na obiekt CDisplayable - body (czêœæ zasadnicza)
		CDisplayable*		p_displayable_body_shadow;	//wskaŸnik na obiekt CDisplayable - body shadow	(cieñ czêœci zasadniczej)
		CDisplayable*		p_displayable_head;			//wskaŸnik na obiekt CDisplayable - head (czêœæ dodatkowa)
		CDisplayable*		p_displayable_head_shadow;	//wskaŸnik na obiekt CDisplayable - head shadow (cieñ czêœci dodatkowej)
		sf::Color			m_color_body;				//kolor obiektu - body
		sf::Color			m_color_head;				//kolor obiektu - head
		sf::Color			m_color_stored_body;		//zapamiêtany kolor obiektu
		sf::Color			m_color_stored_head;		//zapamiêtany kolor obiektu
		sf::Color			m_color_shadow;				//kolor cienia
		sf::Vector2f		m_shadow_offset_body;		//wektor przesuniêcia cienia - body
		sf::Vector2f		m_shadow_offset_head;		//wektor przesuniêcia cienia - head
		CAnimation*			p_animation_body;			//wskaŸnik na animacjê - body (cienie - taka sama animacja)
		CAnimation*			p_animation_head;			//wskaŸnik na animacjê - head (cienie - taka sama animacja)
		float				m_anim_speed_body;			//prêdkoœæ odtwarzania animacji (body)
		float				m_anim_speed_head;			//prêdkoœæ odtwarzania animacji (head)
		float				m_stored_anim_speed_body;	//zapamiêtana prêdkoœæ odtwarzania animacji (body)
		float				m_stored_anim_speed_head;	//zapamiêtana prêdkoœæ odtwarzania animacji (head)
		int					m_z_index_body;				//indeks warstwy rysowania (body)
		int					m_z_index_shadow_body;		//indeks warstwy rysowania (body shadow)
		int					m_z_index_head;				//indeks warstwy rysowania (head)
		int					m_z_index_shadow_head;		//indeks warstwy rysowania (head shadow)
		std::string			m_texture_body;				//nazwa tekstury reprezentacji graficznej obiektu - body
		std::string			m_texture_head;				//nazwa tekstury reprezentacji graficznej obiektu - head
		CTexture*			p_synthetic_texture;		//wskaŸnik na obiekt klasy CTexture - wykorzytywany przy tworzeniu syntetycznej tekstury
		sf::Image*			p_synthetic_image;			//wskaŸnik na obiekt klasy sf::Image - wykorzytywany przy tworzeniu syntetycznego obrazu
		sf::Texture			p_texture;					//obiekt klasy sf::Texture - obiekt pomozniczy

	public:

		static float m_shadow_init;					//wspó³czynnik przesuniêcia cienia w zale¿noœci od wielkoœci obiektu
		
	};
}//namespace physicaldata
#endif//H_PHYSICAL_DATA_JACK
