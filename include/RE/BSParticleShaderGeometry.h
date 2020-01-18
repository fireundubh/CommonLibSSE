#pragma once

#pragma once

#include "RE/BSDynamicTriShape.h"


namespace RE
{
	//shape type == 11
	class BSParticleShaderGeometry : public BSDynamicTriShape
	{
	public:
		inline static const void* RTTI = RTTI_BSParticleShaderGeometry;
		inline static const void* Ni_RTTI = NiRTTI_BSDynamicTriShape;


		virtual ~BSParticleShaderGeometry();														// 00

		// override (BSDynamicTriShape)
		virtual void	UpdateDownwardPass(NiUpdateData& a_data, UInt32 a_arg2) override;			// 2C

	};
	STATIC_ASSERT(sizeof(BSParticleShaderGeometry) == 0x180);
}