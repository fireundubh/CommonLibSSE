#pragma once

#include "hkSseMathTypes.h"


namespace RE
{
	class hkVector4
	{
	public:
		hkQuadReal quad;	// 00
	};
	STATIC_ASSERT(sizeof(hkVector4) == 0x10);
}
