#pragma once

#include "RE/Memory/MemoryManager.h"


namespace RE
{
	class TESForm;
	class TESGlobal;


	struct ContainerItemExtra  // COED
	{
	public:
		union Conditional
		{
			Conditional();
			~Conditional() = default;
			
			TESGlobal* global;
			SInt32	   rank;
		};
		STATIC_ASSERT(sizeof(Conditional) == 0x8);

		ContainerItemExtra();
		~ContainerItemExtra() = default;

		TES_HEAP_REDEFINE_NEW();

		// members
		TESForm*	owner;		  // 00
		Conditional conditional;  // 08
		float		healthMult;	  // 10
		UInt32		pad14;		  // 14
	};
	STATIC_ASSERT(sizeof(ContainerItemExtra) == 0x18);
}
