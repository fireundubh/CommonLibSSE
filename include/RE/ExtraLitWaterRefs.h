#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSTList.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraLitWaterRefs : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraLitWaterRefs;


		enum { kExtraTypeID = ExtraDataType::kLitWaterRefs };


		virtual ~ExtraLitWaterRefs();													// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kLitWaterRefs; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk10 != a_rhs->unk10; }


		// members
		BSSimpleList<UInt64> unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraLitWaterRefs) == 0x20);
}
