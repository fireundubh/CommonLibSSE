#pragma once

#include "hkSseMathTypes.h"


namespace RE
{
	class hkVector4
	{
	public:
		hkVector4() :
			quad(_mm_set1_ps(0.0f))
		{}


		hkVector4(float a_x, float a_y, float a_z, float a_w) :
			quad(_mm_set_ps(a_x, a_y, a_z, a_w))
		{}


		hkQuadReal quad;  // 00
	};
	STATIC_ASSERT(sizeof(hkVector4) == 0x10);
}
