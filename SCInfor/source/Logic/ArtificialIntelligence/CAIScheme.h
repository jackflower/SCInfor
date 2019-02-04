//  __________________________________
// | CAIDemo.h - class definition     |
// | Jack Flower April 2015           |
// |__________________________________|
//

#ifndef H_AIDEMO_JACK
#define H_AIDEMO_JACK

#include <string>
#include "../../RTTI/RTTI.h"
//#include "../../Utils/Memory/CSafePtr.h"
//#include "CActorAI.h" //czy to pomo�e?
// - jakkolwiek, uporz�dkowa� kod, aby nie by��, aby wi�cej
//   jak jedna klas aby�a w jednym pliku...

class CAISchemeManager;	//zapowied� wobec powy�szego...
namespace logic
{
	class CActorAI;			//zapowied� wobec powy�szego...
}
class CActorAIData;		//zapowied� wobec powy�szego...

using namespace logic;

namespace artificialintelligence
{
	///
	///Klasa reprezentuje skal� bazow� definiuj�c� interfejs
	///
	class CAIScheme
	{
		RTTI_DECL;

	public:	

		CAIScheme();
		//{
			//RTTI_IMPL_NOPARENT(CAIScheme);
		//}
		
		virtual ~CAIScheme();// {};
		
		//virtual void RegisterAI(Memory::CSafePtr<CActorAI> ai) {}
		//virtual void UnregisterAI(Memory::CSafePtr<CActorAI> ai) {}

		//bez �adnych wynalazk�w...wska�nik...po prostu...
		virtual void RegisterAI(CActorAI* ai);// {}
		virtual void UnregisterAI(CActorAI* ai);// {}


		virtual void update(float dt);// {}
		virtual void UpdateAI(CActorAIData *ai, float dt) = 0;
		virtual std::string GetName() const = 0;

		virtual void Init(CAISchemeManager &sm) = 0;
	};
}//namespace artificialintelligence
#endif//H_AIDEMO_JACK
