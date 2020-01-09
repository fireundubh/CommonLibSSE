#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSSoundHandle.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraSound : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraSound;


		enum { kExtraTypeID = ExtraDataType::kSound };


		virtual ~ExtraSound();							// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kSound; }


		// members
		BSSoundHandle	phandle;	// 10
		UInt32			pad1C;		// 1C
	};
	STATIC_ASSERT(sizeof(ExtraSound) == 0x20);
}
