#pragma once

#include "RE/BSCore/BSTArray.h"
#include "RE/BSScript/Variable.h"
#include "RE/Memory/MemoryManager.h"


namespace RE
{
	namespace BSScript
	{
		class IFunctionArguments
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSScript__IFunctionArguments;


			IFunctionArguments() = default;
			virtual ~IFunctionArguments() = default;  // 00

			// add
			virtual bool operator()(BSScrapArray<Variable>& a_dst) const = 0;  // 01

			TES_HEAP_REDEFINE_NEW();
		};
		static_assert(sizeof(IFunctionArguments) == 0x8);
	}
}
