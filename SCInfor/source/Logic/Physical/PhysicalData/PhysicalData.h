//  _________________________________________
// | PhysicalData.h - class definition       |
// | Jack Flower - June 2016                 |
// |_________________________________________|
//

#ifndef H_PHYSICAL_DATA_JACK
#define H_PHYSICAL_DATA_JACK

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
	///Klasa reprezentuje opakowanie funkcjonalności klasy Physical
	///
	class PhysicalData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		PhysicalData();

		///
		///Konstruktor kopiujący
		///
		///@param PhysicalDataCopy - stała referencja na obiekt klasy PhysicalData
		///
		PhysicalData(const PhysicalData & PhysicalDataCopy);

		///
		///Destruktor
		///
		~PhysicalData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

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
		///Metoda zwraca pozycję przed aktualizacją logiki m_old_position
		///
		void setOldPosition(const sf::Vector2f & old_position);

		///
		///Metoda ustawia pozycję obiektu
		///
		///@param x - współrzędna x obiektu
		///
		///@param y - współrzędna y obiektu
		///
		///@param change_old_position - flaga, czy aktualizować m_old_position
		///
		void setOldPosition(float x, float y, bool change_old_position = false);

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
		///Metoda zwraca flagę, czy obiekt ma reprezentację graficzną (body and head) /zgodność interfejsu/
		///
		const bool getUseDisplayable() const;

		///
		///Metoda zwraca flagę, czy obiekt ma reprezentację graficzą (body)
		///
		const bool getUseDisplayableBody() const;

		///
		///Metoda zwraca flagę, czy obiekt ma reprezentację graficzą (head)
		///
		const bool getUseDisplayableHead() const;

		///
		///Metoda ustawia flagę, czy obiekt ma reprezentację graficzą (body and head)
		///
		///@param use_displayable - flaga, czy obiekt ma używać reprezentacji graficznej
		///
		void setUseDisplayable(const bool use_displayable);

		///
		///Metoda ustawia flagę, czy obiekt ma reprezentację graficzą (body)
		///
		///@param use_displayable_body - flaga, czy obiekt ma używać reprezentacji graficznej
		///
		void setUseDisplayableBody(const bool use_displayable_body);

		///
		///Metoda ustawia flagę, czy obiekt ma reprezentację graficzą (head)
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
		///Metoda zwraca wskaźnik na obiekt klasy CDisplayable (body) /zgodność interfejsu/
		///
		CDisplayable *getDisplayable();

		///
		///Metoda ustawia wskaźnik na obiekt klasy CDisplayable (body) /zgodność interfejsu/
		///
		///@param *displayable - wskaźnik na obiekt klasy CDisplayable
		///
		void setDisplayable(CDisplayable *displayable);

		///
		///Metoda zwraca wskaźnik na obiekt klasy CDisplayable (shadow) /zgodność interfejsu/
		///
		CDisplayable *getShadow();

		///
		///Metoda ustawia wskaźnik na obiekt klasy CDisplayable (body) /zgodność interfejsu/
		///
		///@param *displayable_shadow - wskaźnik na obiekt klasy CDisplayable
		///
		void setShadow(CDisplayable *displayable_shadow);

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
		CDisplayable *getDisplayableBody() const;

		///
		///Metoda ustawia wskaźnik na obiekt klasy CDisplayable (body)
		///
		///@param *displayable_body - wskaźnik na obiekt klasy CDisplayable
		///
		void setDisplayableBody(CDisplayable *displayable_body);

		///
		///Metoda zwraca wskaźnik na obiekt klasy CDisplayable (body shadow)
		///
		CDisplayable *getDisplayableBodyShadow() const;

		///
		///Metoda ustawia wskaźnik na obiekt klasy CDisplayable (body)
		///
		///@param *displayable_body_shadow - wskaźnik na obiekt klasy CDisplayable
		///
		void setDisplayableBodyShadow(CDisplayable *displayable_body_shadow);

		///
		///Metoda zwraca wskaźnik na obiekt klasy CDisplayable (head)
		///
		CDisplayable *getDisplayableHead() const;

		///
		///Metoda ustawia wskaźnik na obiekt klasy CDisplayable (body)
		///
		///@param *displayable_head - wskaźnik na obiekt klasy CDisplayable
		///
		void setDisplayableHead(CDisplayable *displayable_head);

		///
		///Metoda zwraca wskaźnik na obiekt klasy CDisplayable (head shadow)
		///
		CDisplayable *getDisplayableHeadShadow() const;

		///
		///Metoda ustawia wskaźnik na obiekt klasy CDisplayable (body)
		///
		///@param *displayable_head_shadow - wskaźnik na obiekt klasy CDisplayable
		///
		void setDisplayableHeadShadow(CDisplayable *displayable_head_shadow);

		///
		///Metoda zwraca kolor obiektu - body
		///
		const sf::Color & getColor() const;

		///
		///Metoda ustawia kolor obiektu - (body and head)
		///
		///@param color - kolor stała referencja na obiekt klasy sf::Color
		///
		void setColor(const sf::Color & color);

		///
		///Metoda zwraca kolor obiektu - body
		///
		const sf::Color & getColorBody() const;

		///
		///Metoda ustawia kolor obiektu - body
		///
		///@param color_body - kolor obiektu stała referencja na obiekt klasy sf::Color
		///
		void setColorBody(const sf::Color & color_body);

		///
		///Metoda zwraca kolor obiektu - head
		///
		const sf::Color & getColorHead() const;

		///
		///Metoda ustawia kolor obiektu - head
		///
		///@param color_head - kolor stała referencja na obiekt klasy sf::Color
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
		const sf::Color & getStoredColorHead() const;

		///
		///Metoda ustawia kolor do zapamiętania - body
		///
		///@param color_stored_body - stała referencja na obiekt klasy sf::Color
		///
		void storeColorBody(const sf::Color & color_stored_body);

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
		///@param color_shadow - kolor cienia obiektu stała referencja na obiekt klasy sf::Color
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
		///Metoda ustawia wektor przesunięcia cienia względem obiektu - body
		///
		///@param shadow_offset_body_x - składowa X
		///
		///@param shadow_offset_body_y - składowa Y
		///
		void setShadowOffsetBody(float shadow_offset_body_x, float shadow_offset_body_y);

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
		///Metoda ustawia wektor przesunięcia cienia względem obiektu - hrad
		///
		///@param shadow_offset_body_x - składowa X
		///
		///@param shadow_offset_body_y - składowa Y
		///
		void setShadowOffsetHead(float shadow_offset_head_x, float shadow_offset_head_y);

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

		//wrapper - physics...

		///
		///Metoda zwraca zapamiętaną skalę (body)
		///
		const sf::Vector2f & getStoredScaleBody() const;

		///
		///Metoda ustawia zapamiętaną skalę (body)
		///
		///@param stored_scale_X - wartość X
		///
		///@param stored_scale_Y - wartość Y
		///
		void setStoredScaleBody(float stored_scale_X, float stored_scale_Y);

		///
		///Metoda ustawia zapamiętaną skalę (body)
		///
		///@param stored_scale_vector - wektor skali - stała referencja na obiekt klasy sf::Vector2f
		///
		void setStoredScaleBody(const sf::Vector2f & stored_scale_vector);

		///
		///Metoda zwraca zapamiętaną skalę (head)
		///
		const sf::Vector2f & getStoredScaleHead() const;

		///
		///Metoda ustawia zapamiętaną skalę (head)
		///
		///@param stored_scale_X - wartość X
		///
		///@param stored_scale_Y - wartość Y
		///
		void setStoredScaleHead(float stored_scale_X, float stored_scale_Y);

		///
		///Metoda ustawia zapamiętaną skalę (head)
		///
		///@param stored_scale_vector - wektor skali - stała referencja na obiekt klasy sf::Vector2f
		///
		void setStoredScaleHead(const sf::Vector2f & stored_scale_vector);

		///
		///Metoda ustawia zapamiętaną skalę (body and head)
		///
		///@param stored_scale_X - wartość X
		///
		///@param stored_scale_Y - wartość Y
		///
		void setStoredScale(float stored_scale_X, float stored_scale_Y);

		///
		///Metoda ustawia zapamiętaną skalę (body and head)
		///
		///@param stored_scale - wektor skali - stała referencja na obiekt klasy sf::Vector2f
		///
		void setStoredScale(const sf::Vector2f & stored_scale);

		///
		///Metoda ustawia zapamiętaną skalę
		///
		///@param stored_uniform - jednolita wartość skalująca w osi x i y
		///
		void setStoredScale(float stored_uniform);

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
		///Metoda zwraca pamiętany współczynnik prędkości odtwarzania animacji (head)
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

		//wrapper = animation

		///
		///Metoda sprawdza, czy trzeba utworzyć obiekt klasy CDisplayable (body)
		///np. gdy chcemy dodać obrazek, animację, etc...
		///
		void checkDisplayableBody();

		///
		///Metoda sprawdza, czy trzeba utworzyć obiekt klasy CDisplayable (head)
		///np. gdy chcemy dodać obrazek, animację, etc...
		///
		void checkDisplayableHead();

		///
		///Metoda ustala wektor przesunięcia cienia - body
		///
		void checkShadowOffsetBody();

		///
		///Metoda ustala wektor przesunięcia cienia - head
		///
		void checkShadowOffsetHead();

		///
		///Metoda ustala wektor przesunięcia cienia - body and head
		///
		void checkShadowOffset();

		///
		///Metoda aktualizuje transformację cienia
		///
		void updateShadowTransformation();

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

	private:

		CPhysicsData m_physics_data; //opakowanie informacji o fizyce
		bool m_use_displayable_body; //flaga określa, czy obiekt posiada reprezentację graficzną - body
		bool m_use_shadow_body; //flaga określa, czy obiekt posiada reprezentację graficzną - body - cień
		bool m_use_displayable_head; //flaga określa, czy obiekt posiada reprezentację graficzną - head
		bool m_use_shadow_head; //flaga określa, czy obiekt posiada reprezentację graficzną - head - cień
		CDisplayable *p_displayable_body; //wskaźnik na obiekt CDisplayable - body (część zasadnicza)
		CDisplayable *p_displayable_body_shadow; //wskaźnik na obiekt CDisplayable - body shadow	(cień części zasadniczej)
		CDisplayable *p_displayable_head; //wskaźnik na obiekt CDisplayable - head (część dodatkowa)
		CDisplayable *p_displayable_head_shadow; //wskaźnik na obiekt CDisplayable - head shadow (cień części dodatkowej)
		sf::Color m_color_body; //kolor obiektu - body
		sf::Color m_color_head; //kolor obiektu - head
		sf::Color m_color_stored_body; //zapamiętany kolor obiektu
		sf::Color m_color_stored_head; //zapamiętany kolor obiektu
		sf::Color m_color_shadow; //kolor cienia
		sf::Vector2f m_shadow_offset_body; //wektor przesunięcia cienia - body
		sf::Vector2f m_shadow_offset_head; //wektor przesunięcia cienia - head
		CAnimation *p_animation_body; //wskaźnik na animację - body (cienie - taka sama animacja)
		CAnimation *p_animation_head; //wskaźnik na animację - head (cienie - taka sama animacja)
		float m_anim_speed_body; //prędkość odtwarzania animacji (body)
		float m_anim_speed_head; //prędkość odtwarzania animacji (head)
		float m_stored_anim_speed_body;	//zapamiętana prędkość odtwarzania animacji (body)
		float m_stored_anim_speed_head;	//zapamiętana prędkość odtwarzania animacji (head)
		int m_z_index_body; //indeks warstwy rysowania (body)
		int m_z_index_shadow_body; //indeks warstwy rysowania (body shadow)
		int m_z_index_head; //indeks warstwy rysowania (head)
		int m_z_index_shadow_head; //indeks warstwy rysowania (head shadow)
		std::string m_texture_body; //nazwa tekstury reprezentacji graficznej obiektu - body
		std::string m_texture_head; //nazwa tekstury reprezentacji graficznej obiektu - head
		CTexture *p_synthetic_texture; //wskaźnik na obiekt klasy CTexture - wykorzytywany przy tworzeniu syntetycznej tekstury
		sf::Image *p_synthetic_image; //wskaźnik na obiekt klasy sf::Image - wykorzytywany przy tworzeniu syntetycznego obrazu
		sf::Texture p_texture; //obiekt klasy sf::Texture - obiekt pomozniczy

	public:

		static float m_shadow_init; //współczynnik przesunięcia cienia w zależności od wielkości obiektu
		
	};
}//namespace physicaldata
#endif//H_PHYSICAL_DATA_JACK
