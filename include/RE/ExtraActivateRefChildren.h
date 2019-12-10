#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraActivateRefChildren : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraActivateRefChildren;


		enum { kExtraTypeID = ExtraDataType::kActivateRefChildren };


		virtual ~ExtraActivateRefChildren();			// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kActivateRefChildren; }


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
		UInt64	unk20;	// 20
	};
	STATIC_ASSERT(sizeof(ExtraActivateRefChildren) == 0x28);
}
