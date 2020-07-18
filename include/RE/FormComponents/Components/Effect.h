#pragma once

#include "RE/FormComponents/Components/TESCondition.h"
#include "RE/Memory/MemoryManager.h"


namespace RE
{
	class EffectSetting;


	struct Effect
	{
	public:
		struct EffectItem  // EFIT
		{
		public:
			EffectItem();
			~EffectItem() = default;


			// members
			float		  magnitude;  // 0
			std::uint32_t area;		  // 4
			std::uint32_t duration;	  // 8
		};
		static_assert(sizeof(EffectItem) == 0xC);


		Effect();
		~Effect() = default;

		TES_HEAP_REDEFINE_NEW();

		bool IsMatch(EffectSetting* a_base, float a_mag, UInt32 a_area, UInt32 a_dur, float a_cost);


		// members
		EffectItem	   effectItem;	// 00 - EFIT
		std::uint32_t  pad0C;		// 0C
		EffectSetting* baseEffect;	// 10 - EFID
		float		   cost;		// 18
		std::uint32_t  pad1C;		// 1C
		TESCondition   conditions;	// 20 - CTDA
	};
	static_assert(sizeof(Effect) == 0x28);
}
