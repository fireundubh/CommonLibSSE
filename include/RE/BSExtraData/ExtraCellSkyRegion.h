#pragma once

#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class TESRegion;


	class ExtraCellSkyRegion : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraCellSkyRegion;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kCellSkyRegion;


		virtual ~ExtraCellSkyRegion();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kCellSkyRegion; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return skyRegion != a_rhs->skyRegion; }


		// members
		TESRegion* skyRegion;  // 10
	};
	STATIC_ASSERT(sizeof(ExtraCellSkyRegion) == 0x18);
}
