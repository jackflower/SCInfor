//  ______________________________________________
// | SlotsRateTemplate.cpp - class implementation |
// | Jack Flower - January 2016                   |
// |______________________________________________|
//

#include "SlotsRateTemplate.h"
#include "../../../../Rendering/Animations/CAnimSet.h"
#include "../../../../ResourceManager/CResourceManager.h"

namespace factory
{
	RTTI_IMPL(SlotsRateTemplate, CActorTemplate);

	//Konstruktor
	SlotsRateTemplate::SlotsRateTemplate()
	:
		CActorTemplate()//konstruktor klasy bazowej
	{
	}

	//Destruktor wirtualny
	SlotsRateTemplate::~SlotsRateTemplate()
	{
		//CActorTemplate
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string SlotsRateTemplate::getType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniająca zasób - implementacje w klasach pochodnych
	void SlotsRateTemplate::drop()
	{
		delete this;
	}

	//Metoda ładująca dane
	bool SlotsRateTemplate::load(const std::string & name)
	{
		CXml xml(name, "root");
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml wywoływana przez implementacje klas potomnych
	bool SlotsRateTemplate::load(CXml & xml)
	{
		//sprawdzamy, czy można załadować dane z klasy bazowej CActorTemplate
		if (!CActorTemplate::load(xml)) return false;

		//dane obiektu

		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy CSlotsRate
	CSlotsRate* SlotsRateTemplate::create(std::wstring id)
	{
		CSlotsRate *slots_rate = gPhysicalManager.CreateSlotsRate(id);
		fill(slots_rate);
		return slots_rate;
	}

	//Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
	void SlotsRateTemplate::fill(CSlotsRate *p_slots_rate)
	{
		if (p_slots_rate)
		{
			CActorTemplate::fill(p_slots_rate);

			//przekazanie danych

			//przekazanie zestawu animacji do obiektu, który jest wypełniany danymi wzorca
			if (p_templ_animations)
			{
				p_slots_rate->SetAnimSet(p_templ_animations);

				//body
				if (p_templ_animations->GetSlotsRateBody_0_Anim() != NULL)
					p_slots_rate->SetAnimationBody(p_templ_animations->GetSlotsRateBody_0_Anim());

				//head
				if (p_templ_animations->GetSlotsRateHead_0_Anim() != NULL)
					p_slots_rate->SetAnimationHead(p_templ_animations->GetSlotsRateHead_0_Anim());
			}
			//decorate
			p_slots_rate->setSmoothing(true);
		}
	}
}//namespace factory
