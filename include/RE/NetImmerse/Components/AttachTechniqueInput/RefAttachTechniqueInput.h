#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/NetImmerse/Components/AttachTechniqueInput/AttachTechniqueInput.h"


namespace RE
{
	class TESRace;
	class bhkWorld;


	class RefAttachTechniqueInput : public BSAttachTechniques::AttachTechniqueInput
	{
	public:
		inline static constexpr auto RTTI = RTTI_RefAttachTechniqueInput;


		virtual ~RefAttachTechniqueInput();	 // 00

		// override (BSAttachTechniques::AttachTechniqueInput)
		virtual void Unk_01(void) override;	 // 01



		// members
		std::uint64_t unk20;		 // 20
		TESRace*	  actorRace;	 // 28
		bhkWorld*	  physicsWorld;	 // 30
		std::uint32_t unk38;		 // 38
		std::uint32_t unk3C;		 // 3C
		BSFixedString nodeName;		 // 40
	};
	static_assert(sizeof(RefAttachTechniqueInput) == 0x48);
}
