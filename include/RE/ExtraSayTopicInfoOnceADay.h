#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraSayTopicInfoOnceADay : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraSayTopicInfoOnceADay;


		enum { kExtraTypeID = ExtraDataType::kSayTopicInfoOnceADay };


		virtual ~ExtraSayTopicInfoOnceADay();			// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kSayTopicInfoOnceADay; }


		// members
		void* unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraSayTopicInfoOnceADay) == 0x18);
}
