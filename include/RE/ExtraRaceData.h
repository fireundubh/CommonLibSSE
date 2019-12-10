#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraRaceData : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraRaceData;


		enum { kExtraTypeID = ExtraDataType::kRaceData };


		virtual ~ExtraRaceData();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kRaceData; }


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraRaceData) == 0x18);
}
