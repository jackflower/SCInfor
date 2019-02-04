//  _______________________________________________
// | CSlotsRateTemplate.cpp - class implementation |
// | Jack Flower - January 2016                    |
// |_______________________________________________|
//

#include "CSlotsRateTemplate.h"
#include "../../../../Rendering/Animations/CAnimSet.h"
#include "../../../../ResourceManager/CResourceManager.h"

namespace factory
{
	RTTI_IMPL(CSlotsRateTemplate, CActorTemplate);

	//Konstruktor
	CSlotsRateTemplate::CSlotsRateTemplate()
	:
		CActorTemplate		()//konstruktor klasy bazowej
	{
	}

	//Destruktor wirtualny
	CSlotsRateTemplate::~CSlotsRateTemplate()
	{
		//CActorTemplate	not edit
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CSlotsRateTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj¹ca zasób - implementacje w klasach pochodnych
	void CSlotsRateTemplate::Drop()
	{
		delete this;
	}

	//Metoda ³aduj¹ca dane
	bool CSlotsRateTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root");
		return Load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml wywo³ywana przez implementacje klas potomnych
	bool CSlotsRateTemplate::Load(CXml &xml)
	{
		//sprawdzamy, czy mo¿na za³adowaæ dane z klasy bazowej CActorTemplate
		if (!CActorTemplate::Load(xml)) return false;

		//dane obiektu

		//wszystkie podklasy sprawdzaj¹, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy CSlotsRate
	CSlotsRate* CSlotsRateTemplate::Create(std::wstring id)
	{
		CSlotsRate* slots_rate = gPhysicalManager.CreateSlotsRate(id);
		Fill(slots_rate);
		return slots_rate;
	}

	//Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
	void CSlotsRateTemplate::Fill(CSlotsRate *p_slots_rate)
	{
		if (p_slots_rate)
		{
			CActorTemplate::Fill(p_slots_rate);

			//przekazanie danych

			//przekazanie zestawu animacji do obiektu, który jest wype³niany danymi wzorca
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
