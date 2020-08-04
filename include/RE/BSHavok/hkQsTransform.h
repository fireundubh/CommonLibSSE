#pragma once

#include "RE/BSHavok/hkQuaternion.h"
#include "RE/BSHavok/hkVector4.h"


namespace RE
{
	class hkQsTransform
	{
	public:
		// member
		hkVector4	 translation;  // 00
		hkQuaternion rotation;	   // 10
		hkVector4	 scale;		   // 20
	};
	static_assert(sizeof(hkQsTransform) == 0x30);
}
