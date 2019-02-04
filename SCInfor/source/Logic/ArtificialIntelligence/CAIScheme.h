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
//#include "CActorAI.h" //czy to pomo¿e?
// - jakkolwiek, uporz¹dkowaæ kod, aby nie by³ó, aby wiêcej
//   jak jedna klas aby³a w jednym pliku...

class CAISchemeManager;	//zapowiedŸ wobec powy¿szego...
namespace logic
{
	class CActorAI;			//zapowiedŸ wobec powy¿szego...
}
class CActorAIData;		//zapowiedŸ wobec powy¿szego...

using namespace logic;

namespace artificialintelligence
{
	///
	///Klasa reprezentuje skalê bazow¹ definiuj¹c¹ interfejs
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

		//bez ¿adnych wynalazków...wskaŸnik...po prostu...
		virtual void RegisterAI(CActorAI* ai);// {}
		virtual void UnregisterAI(CActorAI* ai);// {}


		virtual void update(float dt);// {}
		virtual void UpdateAI(CActorAIData *ai, float dt) = 0;
		virtual std::string GetName() const = 0;

		virtual void Init(CAISchemeManager &sm) = 0;
	};
}//namespace artificialintelligence
#endif//H_AIDEMO_JACK
