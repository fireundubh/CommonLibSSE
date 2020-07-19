#pragma once

#include "RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiAVObject/BSGeometry/BSTriShape/BSDynamicTriShape.h"


namespace RE
{
	class BSParticleShaderGeometry : public BSDynamicTriShape
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSParticleShaderGeometry;


		virtual ~BSParticleShaderGeometry();  // 00

		// override (BSDynamicTriShape)
		virtual void UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;  // 2C
	};
	static_assert(sizeof(BSParticleShaderGeometry) == 0x180);
}