//  __________________________________________________
// | CPhysicalInfoTemplate.cpp - class implementation |
// | Jack Flower - April 2014                         |
// |__________________________________________________|
//

#include "CPhysicalInfoTemplate.h"
#include "../Rendering/Drawable/Layers.h"
#include "../Rendering/Drawable/CDrawableManager.h"
#include <SFML/Graphics/RectangleShape.hpp>

using namespace rendering;
using namespace rendering::primitives;

namespace factory
{
	RTTI_IMPL(CPhysicalInfoTemplate, CPhysicalTemplate);


	//Konstruktor
	CPhysicalInfoTemplate::CPhysicalInfoTemplate()
	:
		CPhysicalTemplate					(),//konstruktor klasy bazowej
		m_templ_physical_info_name			(""),
		m_templ_z_index_rectangle			(Z_PHYSICAL_INFO_STATUS_BAR),
		m_templ_use_status_bar_energy		(false),
		m_templ_use_status_bar_fuel			(false),
		m_templ_color_bar_energy			(),
		m_templ_color_bar_fuel				(),
		m_templ_size_energy					(0.0f, 0.0f),
		m_templ_size_fuel					(0.0f, 0.0f),
		m_templ_position_offset_energy		(0.0f, 0.0f),
		m_templ_position_offset_fuel		(0.0f, 0.0f),
		p_templ_status_bar_energy			(NULL),
		p_templ_status_bar_fuel				(NULL),
		m_templ_use_animation				(false),
		m_templ_use_texture					(false),
		m_templ_animation_name				(),
		m_templ_texture_name				()
	{
	}
	
	//Destruktor wirtualny
	CPhysicalInfoTemplate::~CPhysicalInfoTemplate()
	{
		if(p_templ_status_bar_energy)
			gDrawableManager.DestroyDrawable(p_templ_status_bar_energy);
		if(p_templ_status_bar_fuel)
			gDrawableManager.DestroyDrawable(p_templ_status_bar_fuel);

		m_templ_physical_info_name			= "";
		m_templ_z_index_rectangle			= 0;
		m_templ_use_status_bar_energy		= false;
		m_templ_use_status_bar_fuel			= false;
		//m_templ_color_bar_energy			not edit
		//m_templ_color_bar_fuel			not edit
		m_templ_size_energy.x				= 0.0f;
		m_templ_size_energy.y				= 0.0f;
		m_templ_size_fuel.x					= 0.0f;
		m_templ_size_fuel.y					= 0.0f;
		m_templ_position_offset_energy.x	= 0.0f;
		m_templ_position_offset_energy.y	= 0.0f;
		m_templ_position_offset_fuel.x		= 0.0f;
		m_templ_position_offset_fuel.y		= 0.0f;
		p_templ_status_bar_energy			= NULL;
		p_templ_status_bar_fuel				= NULL;
		m_templ_use_animation				= false;
		m_templ_use_texture					= false;
		m_templ_animation_name				= "";
		m_templ_texture_name				= "";
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CPhysicalInfoTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj¹ca zasób - implementacje w klasach pochodnych
	void CPhysicalInfoTemplate::drop()
	{
		delete this;
	}

	//Metoda ³aduj¹ca dane
	bool CPhysicalInfoTemplate::load(const std::string &name)
	{
		CXml xml(name, "root" );
		return load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml
	bool CPhysicalInfoTemplate::load(CXml &xml)
	{
		//³adowanie danych klasy bazowej CPhysical
		if (!CPhysicalTemplate::load(xml)) return false;

		//odczytanie danych animacji - owner(this) body part
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "unit_animation"))
		{
			m_templ_use_animation = xml.GetBool(node, "use_animation");
			m_templ_animation_name = xml.GetString(node, "animation_name");
		}

		//odczytanie danych static image - owner(this) body part
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "unit_texture"))
		{
			m_templ_use_texture = xml.GetBool(node, "use_texture");
			m_templ_texture_name = xml.GetString(node, "texture_name");
		}

		//przepisanie do klasy danych z pliku xml
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "physical_info_config"))
		{
			m_templ_physical_info_name = xml.GetString(node, "physical_info_name");
			m_templ_use_status_bar_energy = xml.GetBool(node, "use_status_bar_energy");
			m_templ_use_status_bar_fuel = xml.GetBool(node, "use_status_bar_fuel");
			m_templ_color_bar_energy.r = xml.GetInt(node, "energy_bar_color_red");
			m_templ_color_bar_energy.g = xml.GetInt(node, "energy_bar_color_green");
			m_templ_color_bar_energy.b = xml.GetInt(node, "energy_bar_color_blue");
			m_templ_color_bar_energy.a = xml.GetInt(node, "energy_bar_color_alpha");
			m_templ_color_bar_fuel.r = xml.GetInt(node, "fuel_bar_color_red");
			m_templ_color_bar_fuel.g = xml.GetInt(node, "fuel_bar_color_green");
			m_templ_color_bar_fuel.b = xml.GetInt(node, "fuel_bar_color_blue");
			m_templ_color_bar_fuel.a = xml.GetInt(node, "fuel_bar_color_alpha");
			m_templ_size_energy.x = xml.GetFloat(node, "size_energy_x");
			m_templ_size_energy.y = xml.GetFloat(node, "size_energy_y");
			m_templ_size_fuel.x = xml.GetFloat(node, "size_fuel_x");
			m_templ_size_fuel.y = xml.GetFloat(node, "size_fuel_y");
			m_templ_position_offset_energy.x = xml.GetFloat(node, "position_offset_energy_x");
			m_templ_position_offset_energy.y = xml.GetFloat(node, "position_offset_energy_y");
			m_templ_position_offset_fuel.x = xml.GetFloat(node, "position_offset_fuel_x");
			m_templ_position_offset_fuel.y = xml.GetFloat(node, "position_offset_fuel_y");
		}
		//wszystkie podklasy sprawdzaj¹, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy CPhysicalInfo
	CPhysicalInfo* CPhysicalInfoTemplate::create(std::wstring id)
	{
		CPhysicalInfo* physical_info = gPhysicalManager.CreatePhysicalInfo(id);
		fill(physical_info);
		return physical_info;
	}

	//Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
	void CPhysicalInfoTemplate::fill(CPhysicalInfo *p_physical_info)
	{
		if(p_physical_info)
		{
			CPhysicalTemplate::fill(p_physical_info);
			//sk³adowe tej klasy			
			p_physical_info->SetPhysicalInfoName(m_templ_physical_info_name);
			p_physical_info->SetZIndexRectangle(m_templ_z_index_rectangle);
			p_physical_info->setUseStatusBarEnergy(m_templ_use_status_bar_energy);
			p_physical_info->setUseStatusBarFuel(m_templ_use_status_bar_fuel);

			//animacja/tekstura - owner(this) body part
			if(m_templ_use_animation)
				p_physical_info->SetAnimationBody(m_templ_animation_name);

			//tekstura/animacja - owner(this) body part
			if(m_templ_use_texture)
				p_physical_info->SetTextureBody(m_templ_texture_name);

			//wskaŸnik energii
			if(m_templ_use_status_bar_energy)
			{
				//wymuszam utworzenie obiektu
				p_physical_info->InitStatusBarEnergy();
				//kolor status progress bar (energia-¿ycie)
				p_physical_info->setFillColorEnergy(m_templ_color_bar_energy);
				//rozmiar paska - progress bar (energia-¿ycie)
				p_physical_info->SetEnergyStatusBarSize(m_templ_size_energy);
				//wektor kalibracji po³o¿enia obiektu - progress bar (energia-¿ycie)
				p_physical_info->SetEnergyPositionStatusBarOffset(m_templ_position_offset_energy);
			}

			//wskaŸnik paliwa
			if(m_templ_use_status_bar_fuel)
			{
				//wymuszam utworzenie obiektu
				p_physical_info->InitStatusBarFuel();
				//kolor status progress bar (energia-¿ycie)
				p_physical_info->setFillColorFuel(m_templ_color_bar_fuel);
				//rozmiar paska - progress bar (energia-¿ycie)
				p_physical_info->SetFuelStatusBarSize(m_templ_size_fuel);
				//wektor kalibracji po³o¿enia obiektu - progress bar (energia-¿ycie)
				p_physical_info->SetFuelPositionStatusBarOffset(m_templ_position_offset_fuel);
			}
		}
	}
}//namespace factory
