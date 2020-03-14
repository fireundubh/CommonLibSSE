#pragma once

#include "RE/BSDynamicTriShape.h"


namespace RE
{
	class BSParticleShaderGeometry : public BSDynamicTriShape
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSParticleShaderGeometry;


		virtual ~BSParticleShaderGeometry();  // 00

		// override (BSDynamicTriShape)
		virtual void UpdateDownwardPass(NiUpdateData& a_data, UInt32 a_arg2) override;	// 2C
	};
	STATIC_ASSERT(sizeof(BSParticleShaderGeometry) == 0x180);
}