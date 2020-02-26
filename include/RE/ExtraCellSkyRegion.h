#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class TESRegion;


	class ExtraCellSkyRegion : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraCellSkyRegion;


		enum { kExtraTypeID = ExtraDataType::kCellSkyRegion };


		virtual ~ExtraCellSkyRegion();													// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kCellSkyRegion; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return skyRegion != a_rhs->skyRegion; }


		// members
		TESRegion* skyRegion;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraCellSkyRegion) == 0x18);
}
