#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraGhost : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraGhost;


		enum { kExtraTypeID = ExtraDataType::kGhost };


		virtual ~ExtraGhost();							// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kGhost; }


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraGhost) == 0x18);
}
