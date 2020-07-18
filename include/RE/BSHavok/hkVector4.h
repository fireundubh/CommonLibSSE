#pragma once

#include "hkSseMathTypes.h"


namespace RE
{
	class hkVector4
	{
	public:
		hkVector4();
		hkVector4(float a_value);
		hkVector4(float a_x, float a_y, float a_z, float a_w);
		hkVector4(const hkQuadReal& a_rhs);
		
		hkVector4& operator=(const hkVector4& a_rhs);
		hkVector4  operator+(const hkVector4& a_rhs) const;
		hkVector4  operator-(const hkVector4& a_rhs) const;
		hkVector4  operator*(const hkVector4& a_rhs) const;
		hkVector4  operator/(const hkVector4& a_rhs) const;


		// member
		hkQuadReal quad;  // 00
	};
	static_assert(sizeof(hkVector4) == 0x10);
}
