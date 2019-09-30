#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraLightData

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraLightData : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraLightData;


		enum { kExtraTypeID = ExtraDataType::kLightData };


		ExtraLightData();
		virtual ~ExtraLightData();														// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kLightData; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		float	modFOV;     // 10
		UInt32	modFade;	// 14
		UInt32	unk18;		// 18
		float	depthBias;	// 1C
		UInt8	unk20;		// 20
		UInt32	pad24;		// 24
	};
	STATIC_ASSERT(sizeof(ExtraLightData) == 0x28);
}
