#include "RE/ExtraLightData.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	ExtraLightData::ExtraLightData() :
		BSExtraData(),
		modFOV(0.0),
		modFade(0.0),
		unk18(0),
		depthBias(1),
		unk20(0),
		pad24(0)
	{
		REL::Offset<std::uintptr_t> vtbl(Offset::ExtraLightData::Vtbl);
		((std::uintptr_t*)this)[0] = vtbl.GetAddress();
	}

	ExtraDataType ExtraLightData::GetType() const
	{
		return ExtraDataType::kLightData;
	}


	bool ExtraLightData::IsNotEqual(const BSExtraData* a_rhs) const
	{
		auto rhs = static_cast<const ExtraLightData*>(a_rhs);

		auto v2 = modFOV - rhs->modFOV;
		if (v2)
			return v2 != 0;
		v2 = unk18 - rhs->unk18;
		if (!v2)
			v2 = unk20 - rhs->unk20;
		return v2 != 0;
	}
}