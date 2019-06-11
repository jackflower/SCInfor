//  ______________________________________________
// | SlotsRateTemplate.cpp - class implementation |
// | Jack Flower - January 2016                   |
// |______________________________________________|
//

#include "SlotsRateTemplate.h"
#include "../../../../Rendering/Animations/AnimSet.h"
#include "../../../../ResourceManager/ResourceManager.h"

namespace factory
{
	RTTI_IMPL(SlotsRateTemplate, ActorTemplate);

	//Konstruktor
	SlotsRateTemplate::SlotsRateTemplate()
	:
		ActorTemplate{}//konstruktor klasy bazowej
	{
	}

	//Destruktor wirtualny
	SlotsRateTemplate::~SlotsRateTemplate()
	{
		//~ActorTemplate()
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string SlotsRateTemplate::getType() const
	{
		return rtti.getNameClass();
	}

	//Wirtualna metoda zwalniająca zasób - implementacje w klasach pochodnych
	void SlotsRateTemplate::drop()
	{
		delete this;
	}

	//Metoda ładująca dane
	bool SlotsRateTemplate::load(const std::string & name)
	{
		Xml xml(name, "root");
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml wywoływana przez implementacje klas potomnych
	bool SlotsRateTemplate::load(Xml & xml)
	{
		//sprawdzamy, czy można załadować dane z klasy bazowej ActorTemplate
		if (!ActorTemplate::load(xml)) return false;

		//dane obiektu

		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy SlotsRate
	SlotsRate *SlotsRateTemplate::create(std::wstring id)
	{
		SlotsRate *slots_rate = gPhysicalManager.createSlotsRate(id);
		fill(slots_rate);
		return slots_rate;
	}

	//Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
	void SlotsRateTemplate::fill(SlotsRate *p_slots_rate)
	{
		if (p_slots_rate)
		{
			ActorTemplate::fill(p_slots_rate);

			//przekazanie danych

			//przekazanie zestawu animacji do obiektu, który jest wypełniany danymi wzorca
			if (p_templ_animations)
			{
				p_slots_rate->setAnimSet(p_templ_animations);

				//body
				if (p_templ_animations->getSlotsRateBody_0_Anim() != NULL)
					p_slots_rate->setAnimationBody(p_templ_animations->getSlotsRateBody_0_Anim());

				//head
				if (p_templ_animations->getSlotsRateHead_0_Anim() != NULL)
					p_slots_rate->setAnimationHead(p_templ_animations->getSlotsRateHead_0_Anim());
			}
			//decorate
			p_slots_rate->setSmoothing(true);
		}
	}
}//namespace factory
