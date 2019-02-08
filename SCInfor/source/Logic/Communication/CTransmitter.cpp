//  _________________________________________
// | CTransmitter.cpp - class implementation |
// | Jack Flower - July 2015                 |
// |_________________________________________|
//

#include "CTransmitter.h"

namespace logic
{
	namespace communication
	{
		RTTI_IMPL(CTransmitter, Actor);

		//Chroniony konstruktor domyœlny
		CTransmitter::CTransmitter(const std::wstring& uniqueId)
		:
			Actor(uniqueId)//konstruktor klasy bazowej
		{
		}
			
		//Chroniony konstruktor kopiuj¹cy
		CTransmitter::CTransmitter(const CTransmitter &CTransmitterCopy)
		:
			Actor (CTransmitterCopy)//konstruktor kopiujacy klasy bazowej
		{
		}

		//Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
		CTransmitter::~CTransmitter()
		{
			//Actor				not edit
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CTransmitter::GetType() const
		{
			return rtti.GetNameClass();
		}

		//Wirtualna metoda aktualizuj¹ca obiekt
		void CTransmitter::update(float dt)
		{
		}
	}//namespace communication
}//namespace logic
