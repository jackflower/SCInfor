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
//#include "ActorAI.h" //czy to pomoże?
// - jakkolwiek, uporządkować kod, aby nie było, aby więcej
//   jak jedna klas abyła w jednym pliku...
// 2019-06-12: generalnie - ten framework (zarządzanie schamatami zachowania AI)
// wymaga analizy i zaprojektowania na nowo

class AISchemeManager; //zapowiedź wobec powyższego...

namespace logic
{
	class ActorAI; //zapowiedź wobec powyższego...
}

class ActorAIData; //zapowiedź wobec powyższego...

using namespace logic;

namespace artificialintelligence
{
	///
	///Klasa reprezentuje skalę bazową definiującą interfejs
	///
	class AIScheme
	{
		RTTI_DECL;

	public:	

		AIScheme()
		{
			//RTTI_IMPL_NOPARENT(AIScheme);
		}
		
		virtual ~AIScheme() {};
		
		//virtual void RegisterAI(Memory::CSafePtr<ActorAI> ai) {}
		//virtual void UnregisterAI(Memory::CSafePtr<ActorAI> ai) {}

		//bez żadnych wynalazków...wskaźnik...po prostu...
		virtual void RegisterAI(ActorAI* ai) {};
		virtual void UnregisterAI(ActorAI* ai) {};


		virtual void update(float dt) {};
		virtual void UpdateAI(ActorAIData *ai, float dt) = 0;
		virtual std::string GetName() const = 0;

		virtual void Init(AISchemeManager &sm) = 0;
	};
}//namespace artificialintelligence
#endif//H_AIDEMO_JACK
