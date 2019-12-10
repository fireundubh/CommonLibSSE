#include "RE/BGSFootstepEvent.h"
#include "RE/BGSFootstepManager.h"


namespace RE
{
	BSTEventSource<BGSFootstepEvent>* BGSFootstepEvent::GetEventSource()
	{
		return BGSFootstepManager::GetSingleton();
	}
}
