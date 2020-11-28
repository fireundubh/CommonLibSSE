#pragma once

#include "RE/NetImmerse/NiRefObject/NiObject/ImageSpaceModifierInstance/ImageSpaceModifierInstance.h"


namespace RE
{
	class TESImageSpaceModifier;


	class ImageSpaceModifierInstanceForm : public ImageSpaceModifierInstance
	{
	public:
		inline static constexpr auto RTTI = RTTI_ImageSpaceModifierInstance;


		virtual ~ImageSpaceModifierInstanceForm();	// 00

		// add
		virtual void Unk_25(void);		// 25 - { return 0; }
		virtual void Unk_26(void) = 0;	// 26
		virtual void Unk_27(void);		// 27 - { return 0; }
		virtual void Unk_28(void) = 0;	// 28


		// members
		TESImageSpaceModifier* imod;   // 28;
		std::uint64_t		   unk30;  // 30;
		std::uint32_t		   unk38;  // 38;
		std::uint32_t		   unk3C;  // 3C;
		std::uint64_t		   unk40;  // 40
		std::uint32_t		   unk48;  // 48
	};
	static_assert(sizeof(ImageSpaceModifierInstanceForm) == 0x50);
}
