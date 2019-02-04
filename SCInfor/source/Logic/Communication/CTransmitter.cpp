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
		RTTI_IMPL(CTransmitter, CActor);

		//Chroniony konstruktor domy�lny
		CTransmitter::CTransmitter(const std::wstring& uniqueId)
		:
			CActor(uniqueId)//konstruktor klasy bazowej
		{
		}
			
		//Chroniony konstruktor kopiuj�cy
		CTransmitter::CTransmitter(const CTransmitter &CTransmitterCopy)
		:
			CActor (CTransmitterCopy)//konstruktor kopiujacy klasy bazowej
		{
		}

		//Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
		CTransmitter::~CTransmitter()
		{
			//CActor				not edit
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CTransmitter::GetType() const
		{
			return rtti.GetNameClass();
		}

		//Wirtualna metoda aktualizuj�ca obiekt
		void CTransmitter::update(float dt)
		{
		}
	}//namespace communication
}//namespace logic
