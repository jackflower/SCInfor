//  ___________________________________________
// | BulletTemplate.cpp - class implementation |
// | Jack Flower - November 2012               |
// |___________________________________________|
//

#include "BulletTemplate.h"
#include "../XML/CXml.h"
#include "../Rendering/Displayable/Displayable.h"
#include "../Rendering/Animations/AnimationManager.h"
#include "../Rendering/Animations/AnimationState.h"
#include <iostream>

using namespace rapidxml;

namespace factory
{
	RTTI_IMPL(BulletTemplate, ActorTemplate);

	//Konstruktor
	BulletTemplate::BulletTemplate()
	:
		ActorTemplate()//konstruktor klasy bazowej
	{
	}

	//Destruktor
	BulletTemplate::~BulletTemplate()
	{
		//~ActorTemplate
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string BulletTemplate::getType() const
	{
		return rtti.getNameClass();
	}

	//Wirtualna metoda zwalniająca zasób
	void BulletTemplate::drop()
	{
		delete this;
	}

	//Metoda ładująca dane
	bool BulletTemplate::load(const std::string & name)
	{
		CXml xml(name, "root");
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml
	bool BulletTemplate::load(CXml & xml)
	{
		//if (!PhysicalTemplate::load(xml)) return false;
		if (!ActorTemplate::load(xml)) return false;

		//sprawdzamy, czy xml zawiera informację, że jest to bullet
		if (xml.GetString(xml.GetRootNode(), "type") != "bullet")
			return false;

		//plik xml pocisku przypomina plik physical'a
		//ewentualne ładowanie danych generycznych pocisku...


		//if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "zabawa z pociskiem..."))

		//mMinDamage = xml.GetFloat( "damage", "min" );
		//mMaxDamage = xml.GetFloat( "damage", "max" );

		//node = xml.GetChild(0, "anim");
		//if (node)
		  //  mAnimation = gAnimationManager.GetAnimation(xml.GetString(node,"name"));

		//for (node=xml.GetChild(0,"image"); node; node=xml.GetSibl(node,"image") )
		//	mImages.push_back( xml.GetString(node,"filename") );

		//for (node=xml.GetChild(0,"effect"); node; node=xml.GetSibl(node,"effect") )
		//	mEffects.push_back( xml.GetString(node,"name") );

		//for (node=xml.GetChild(0,"destroyEffect"); node; node=xml.GetSibl(node,"destroyEffect") )
		//	mDestroyEffects.push_back( xml.GetString(node,"name") );

		return true;
	}

	//Wirtualna metoda tworzenie obiektów pochodnych klasy Physical
	Bullet *BulletTemplate::create(std::wstring id)
	{
		Bullet *bullet = gPhysicalManager.createBullet();

		fill(bullet);
		
		//gdyby były jakieś pola do przekazania, należy to uczynić...
		//ale w fill(...)


		//this->fill(

		//float random =	gRand.Rndf( 0.0f, 1.0f );
		//float scale =	Lerp( mMinScale,	mMaxScale,	random );
		//float radius =	Lerp( mMinRadius,	mMaxRadius,	random );

		//bullet->SetCategory(PHYSICAL_BULLET);
		//bullet->SetBoundingCircle(radius);// atrapa, coś muszę mieć.../
		//this->m_templ_circle_radius
		//m_templ_animation_name_body
		//this->m_templ_animation_name_body...

		//if ( mImages.size() > 0 ) 
		//{
		//	int imageNo = gRand.Rnd( 0, static_cast<unsigned>(mImages.size()) );
		//	bullet->SetImage( mImages[imageNo] );
		//} else {
		//	bullet->SetUseDisplayable(false);
		//}

		//if (mAnimation)
		//	bullet->SetAnimation(mAnimation);

		//if ( bullet->GetDisplayable() )
		//	bullet->GetDisplayable()->SetScale( scale, scale );

		/* TODO:
		*  przypisywanie efektów cząsteczkowych do pocisku
		*  ( czekam na system cząsteczek z predefiniowanymi efektami identyfikowanymi po nazwie - stringu )
		*/

		return bullet;
	}

	//implementacja metod  p r o t e c e t e d:

	//Wirtualna metoda wypełniająca danymi obiekt klasy Bullet
	void BulletTemplate::fill(Bullet *bullet)
	{
		bullet->setTemplate(this);
		
		//Friday, February 8, 2019
		//ten kod jest prawdopodobnie poporawny
		//jak będą pocisku, to się przetestuje...
		ActorTemplate::fill(bullet);
		
		//to do...
	}
}//namespace factory
