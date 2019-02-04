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
	///Klasa reprezentuje opakowanie funkcjonalno�ci klasy CPhysical
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
		///Konstruktor kopiuj�cy
		///
		///@param & CPhysicalDataCopy - sta�a referencja na obiekt klasy CPhysicalData
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
		///Metoda zwraca pozycj� przed aktualizacj� logiki m_old_position
		///
		void SetOldPosition(const sf::Vector2f & old_position);

		///
		///Metoda ustawia pozycj� obiektu
		///
		///@param x - wsp�rz�dna x obiektu
		///
		///@param y - wsp�rz�dna y obiektu
		///
		///@param change_old_position - flaga, czy aktualizowa� m_old_position
		///
		void SetOldPosition(float x, float y, bool change_old_position = false);

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
		///Metoda zwraca flag�, czy obiekt ma reprezentacj� graficzn� (body and head) /zgodno�� interfejsu/
		///
		const bool GetUseDisplayable() const;

		///
		///Metoda zwraca flag�, czy obiekt ma reprezentacj� graficz� (body)
		///
		const bool GetUseDisplayableBody() const;

		///
		///Metoda zwraca flag�, czy obiekt ma reprezentacj� graficz� (head)
		///
		const bool GetUseDisplayableHead() const;

		///
		///Metoda ustawia flag�, czy obiekt ma reprezentacj� graficz� (body and head)
		///
		///@param use_displayable - flaga, czy obiekt ma u�ywa� reprezentacji graficznej
		///
		void SetUseDisplayable(const bool use_displayable);

		///
		///Metoda ustawia flag�, czy obiekt ma reprezentacj� graficz� (body)
		///
		///@param use_displayable_body - flaga, czy obiekt ma u�ywa� reprezentacji graficznej
		///
		void SetUseDisplayableBody(const bool use_displayable_body);

		///
		///Metoda ustawia flag�, czy obiekt ma reprezentacj� graficz� (head)
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
		///Metoda zwraca wska�nik na obiekt klasy CDisplayable (body) /zgodno�� interfejsu/
		///
		CDisplayable *GetDisplayable();

		///
		///Metoda ustawia wska�nik na obiekt klasy CDisplayable (body) /zgodno�� interfejsu/
		///
		///@param * displayable - wska�nika na obiekt klasy CDisplayable
		///
		void SetDisplayable(CDisplayable *displayable);

		///
		///Metoda zwraca wska�nik na obiekt klasy CDisplayable (shadow) /zgodno�� interfejsu/
		///
		CDisplayable *GetShadow();

		///
		///Metoda ustawia wska�nik na obiekt klasy CDisplayable (body) /zgodno�� interfejsu/
		///
		///@param * displayable_shadow - wska�nika na obiekt klasy CDisplayable
		///
		void SetShadow(CDisplayable *displayable_shadow);

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
		CDisplayable *GetDisplayableBody() const;

		///
		///Metoda ustawia wska�nik na obiekt klasy CDisplayable (body)
		///
		///@param * displayable_body - wska�nika na obiekt klasy CDisplayable
		///
		void SetDisplayableBody(CDisplayable *displayable_body);

		///
		///Metoda zwraca wska�nik na obiekt klasy CDisplayable (body shadow)
		///
		CDisplayable *GetDisplayableBodyShadow() const;

		///
		///Metoda ustawia wska�nik na obiekt klasy CDisplayable (body)
		///
		///@param * displayable_body_shadow - wska�nika na obiekt klasy CDisplayable
		///
		void SetDisplayableBodyShadow(CDisplayable *displayable_body_shadow);

		///
		///Metoda zwraca wska�nik na obiekt klasy CDisplayable (head)
		///
		CDisplayable *GetDisplayableHead() const;

		///
		///Metoda ustawia wska�nik na obiekt klasy CDisplayable (body)
		///
		///@param * displayable_head - wska�nika na obiekt klasy CDisplayable
		///
		void SetDisplayableHead(CDisplayable *displayable_head);

		///
		///Metoda zwraca wska�nik na obiekt klasy CDisplayable (head shadow)
		///
		CDisplayable *GetDisplayableHeadShadow() const;

		///
		///Metoda ustawia wska�nik na obiekt klasy CDisplayable (body)
		///
		///@param * displayable_head_shadow - wska�nika na obiekt klasy CDisplayable
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
		const sf::Color & GetStoredColorHead() const;

		///
		///Metoda ustawia kolor do zapami�tania - body
		///
		///@param & color_stored_body - sta�a referencja na obiekt klasy sf::Color
		///
		void StoreColorBody(const sf::Color & color_stored_body);

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
		///@param &shadow_offset_body - sta�a referencja na wektor przesuni�cia cienia wzgl�dem obiektu
		///
		void SetShadowOffsetBody(sf::Vector2f & shadow_offset_body);

		///
		///Metoda ustawia wektor przesuni�cia cienia wzgl�dem obiektu - body
		///
		///@param shadow_offset_body_x - sk�adowa X
		///
		///@param shadow_offset_body_y - sk�adowa Y
		///
		void SetShadowOffsetBody(float shadow_offset_body_x, float shadow_offset_body_y);

		///
		///Metoda zwraca wektor przesuni�cia cienia wzgl�dem obiektu - head
		///
		sf::Vector2f & GetShadowOffsetHead();

		///
		///Metoda ustawia wektor przesuni�cia cienia wzgl�dem obiektu - head
		///
		///@param &shadow_offset_head - sta�a referencja na wektor przesuni�cia cienia wzgl�dem obiektu
		///
		void SetShadowOffsetHead(sf::Vector2f & shadow_offset_head);

		///
		///Metoda ustawia wektor przesuni�cia cienia wzgl�dem obiektu - hrad
		///
		///@param shadow_offset_body_x - sk�adowa X
		///
		///@param shadow_offset_body_y - sk�adowa Y
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
		///Metoda zwraca zapami�tan� skal� (body)
		///
		const sf::Vector2f & GetStoredScaleBody() const;

		///
		///Metoda ustawia zapami�tan� skal� (body)
		///
		///@param stored_scale_X - warto�� X
		///
		///@param stored_scale_Y - warto�� Y
		///
		void SetStoredScaleBody(float stored_scale_X, float stored_scale_Y);

		///
		///Metoda ustawia zapami�tan� skal� (body)
		///
		///@param & stored_scale_vector - wektor skali - sta�a referencja na obiekt klasy sf::Vector2f
		///
		void SetStoredScaleBody(const sf::Vector2f & stored_scale_vector);

		///
		///Metoda zwraca zapami�tan� skal� (head)
		///
		const sf::Vector2f & GetStoredScaleHead() const;

		///
		///Metoda ustawia zapami�tan� skal� (head)
		///
		///@param stored_scale_X - warto�� X
		///
		///@param stored_scale_Y - warto�� Y
		///
		void SetStoredScaleHead(float stored_scale_X, float stored_scale_Y);

		///
		///Metoda ustawia zapami�tan� skal� (head)
		///
		///@param & stored_scale_vector - wektor skali - sta�a referencja na obiekt klasy sf::Vector2f
		///
		void SetStoredScaleHead(const sf::Vector2f & stored_scale_vector);

		///
		///Metoda ustawia zapami�tan� skal� (body and head)
		///
		///@param stored_scale_X - warto�� X
		///
		///@param stored_scale_Y - warto�� Y
		///
		void SetStoredScale(float stored_scale_X, float stored_scale_Y);

		///
		///Metoda ustawia zapami�tan� skal� (body and head)
		///
		///@param & stored_scale - wektor skali - sta�a referencja na obiekt klasy sf::Vector2f
		///
		void SetStoredScale(const sf::Vector2f & stored_scale);

		///
		///Metoda ustawia zapami�tan� skal�
		///
		///@param stored_uniform - jednolita warto�� skaluj�ca w osi x i y
		///
		void SetStoredScale(float stored_uniform);

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

		//wrapper = animation

		///
		///Metoda sprawdza, czy trzeba utworzy� obiekt klasy CDisplayable (body)
		///np. gdy chcemy doda� obrazek, animacj�, etc...
		///
		void CheckDisplayableBody();

		///
		///Metoda sprawdza, czy trzeba utworzy� obiekt klasy CDisplayable (head)
		///np. gdy chcemy doda� obrazek, animacj�, etc...
		///
		void CheckDisplayableHead();

		///
		///Metoda ustala wektor przesuni�cia cienia - body
		///
		void CheckShadowOffsetBody();

		///
		///Metoda ustala wektor przesuni�cia cienia - head
		///
		void CheckShadowOffsetHead();

		///
		///Metoda ustala wektor przesuni�cia cienia - body and head
		///
		void CheckShadowOffset();

		///
		///Metoda aktualizuje transformacj� cienia
		///
		void UpdateShadowTransformation();

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

	private:

		CPhysicsData		m_physics_data;				//opakowanie informacji o fizyce
		bool				m_use_displayable_body;		//flaga okre�la, czy obiekt posiada reprezentacj� graficzn� - body
		bool				m_use_shadow_body;			//flaga okre�la, czy obiekt posiada reprezentacj� graficzn� - body - cie�
		bool				m_use_displayable_head;		//flaga okre�la, czy obiekt posiada reprezentacj� graficzn� - head
		bool				m_use_shadow_head;			//flaga okre�la, czy obiekt posiada reprezentacj� graficzn� - head - cie�
		CDisplayable*		p_displayable_body;			//wska�nik na obiekt CDisplayable - body (cz�� zasadnicza)
		CDisplayable*		p_displayable_body_shadow;	//wska�nik na obiekt CDisplayable - body shadow	(cie� cz�ci zasadniczej)
		CDisplayable*		p_displayable_head;			//wska�nik na obiekt CDisplayable - head (cz�� dodatkowa)
		CDisplayable*		p_displayable_head_shadow;	//wska�nik na obiekt CDisplayable - head shadow (cie� cz�ci dodatkowej)
		sf::Color			m_color_body;				//kolor obiektu - body
		sf::Color			m_color_head;				//kolor obiektu - head
		sf::Color			m_color_stored_body;		//zapami�tany kolor obiektu
		sf::Color			m_color_stored_head;		//zapami�tany kolor obiektu
		sf::Color			m_color_shadow;				//kolor cienia
		sf::Vector2f		m_shadow_offset_body;		//wektor przesuni�cia cienia - body
		sf::Vector2f		m_shadow_offset_head;		//wektor przesuni�cia cienia - head
		CAnimation*			p_animation_body;			//wska�nik na animacj� - body (cienie - taka sama animacja)
		CAnimation*			p_animation_head;			//wska�nik na animacj� - head (cienie - taka sama animacja)
		float				m_anim_speed_body;			//pr�dko�� odtwarzania animacji (body)
		float				m_anim_speed_head;			//pr�dko�� odtwarzania animacji (head)
		float				m_stored_anim_speed_body;	//zapami�tana pr�dko�� odtwarzania animacji (body)
		float				m_stored_anim_speed_head;	//zapami�tana pr�dko�� odtwarzania animacji (head)
		int					m_z_index_body;				//indeks warstwy rysowania (body)
		int					m_z_index_shadow_body;		//indeks warstwy rysowania (body shadow)
		int					m_z_index_head;				//indeks warstwy rysowania (head)
		int					m_z_index_shadow_head;		//indeks warstwy rysowania (head shadow)
		std::string			m_texture_body;				//nazwa tekstury reprezentacji graficznej obiektu - body
		std::string			m_texture_head;				//nazwa tekstury reprezentacji graficznej obiektu - head
		CTexture*			p_synthetic_texture;		//wska�nik na obiekt klasy CTexture - wykorzytywany przy tworzeniu syntetycznej tekstury
		sf::Image*			p_synthetic_image;			//wska�nik na obiekt klasy sf::Image - wykorzytywany przy tworzeniu syntetycznego obrazu
		sf::Texture			p_texture;					//obiekt klasy sf::Texture - obiekt pomozniczy

	public:

		static float m_shadow_init;					//wsp�czynnik przesuni�cia cienia w zale�no�ci od wielko�ci obiektu
		
	};
}//namespace physicaldata
#endif//H_PHYSICAL_DATA_JACK
