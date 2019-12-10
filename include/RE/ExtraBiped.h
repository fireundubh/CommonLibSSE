#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	struct Biped;


	class ExtraBiped : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraBiped;


		enum { kExtraTypeID = ExtraDataType::kBiped };


		virtual ~ExtraBiped();							// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kBiped; }


		// members
		Biped* unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraBiped) == 0x18);
}
