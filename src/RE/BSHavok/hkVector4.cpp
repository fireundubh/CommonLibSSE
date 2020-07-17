#include "RE/BSHavok/hkVector4.h"


namespace RE
{
	hkVector4::hkVector4() :
		quad(_mm_set1_ps(0.0f))
	{}


	hkVector4::hkVector4(float a_x) :
		quad(_mm_set1_ps(a_x))
	{}


	hkVector4::hkVector4(float a_x, float a_y, float a_z, float a_w) :
		quad(_mm_set_ps(a_x, a_y, a_z, a_w))
	{}


	hkVector4::hkVector4(const hkQuadReal& a_rhs) :
		quad(a_rhs)
	{}


	hkVector4& hkVector4::operator=(const hkVector4& a_rhs)
	{
		quad = a_rhs.quad;
		return *this;
	}


	hkVector4 hkVector4::operator+(const hkVector4& a_rhs) const
	{
		return _mm_add_ps(quad, a_rhs.quad);
	}


	hkVector4 hkVector4::operator-(const hkVector4& a_rhs) const
	{
		return _mm_sub_ps(quad, a_rhs.quad);
	}


	hkVector4 hkVector4::operator*(const hkVector4& a_rhs) const
	{
		return _mm_mul_ps(quad, a_rhs.quad);
	}


	hkVector4 hkVector4::operator/(const hkVector4& a_rhs) const
	{
		return _mm_div_ps(quad, a_rhs.quad);
	}
}