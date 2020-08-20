#pragma once

#include "hkSseMathTypes.h"


namespace RE
{
	class hkVector4
	{
	public:
		hkVector4();
		hkVector4(const float& a_value);
		hkVector4(const float& a_x, const float& a_y, const float& a_z, const float& a_w);
		hkVector4(const hkQuadReal& a_rhs);

		hkVector4& operator=(const hkVector4& a_rhs);
		hkVector4  operator+(const hkVector4& a_rhs) const;
		hkVector4  operator-(const hkVector4& a_rhs) const;
		hkVector4  operator*(const hkVector4& a_rhs) const;
		hkVector4  operator/(const hkVector4& a_rhs) const;


		// members
        hkQuadReal quad{}; // 00
	};
	static_assert(sizeof(hkVector4) == 0x10);
}
