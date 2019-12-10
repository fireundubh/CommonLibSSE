#pragma once

namespace RE
{
	class BGSFootstep;

	struct BGSFootstepEvent
	{
		RefHandle					actorHandle;	//04

		static BSTEventSource<BGSFootstepEvent>*	GetEventSource();
	};
}
