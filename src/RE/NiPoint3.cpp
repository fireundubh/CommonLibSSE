#include "RE/NiPoint3.h"

#include <cassert>


namespace RE
{
	float& NiPoint3::operator[](std::size_t a_idx)
	{
		assert(a_idx < 3);
		return std::addressof(x)[a_idx];
	}


	const float& NiPoint3::operator[](std::size_t a_idx) const
	{
		assert(a_idx < 3);
		return std::addressof(x)[a_idx];
	}


	bool NiPoint3::operator==(const NiPoint3& a_rhs) const
	{
		return (x == a_rhs.x && y == a_rhs.y && z == a_rhs.z);
	}


	bool NiPoint3::operator!=(const NiPoint3& a_rhs) const
	{
		return !operator==(a_rhs);
	}


	NiPoint3 NiPoint3::operator+(const NiPoint3& a_rhs) const
	{
		return NiPoint3(x + a_rhs.x, y + a_rhs.y, z + a_rhs.z);
	}


	NiPoint3 NiPoint3::operator-(const NiPoint3& a_rhs) const
	{
		return NiPoint3(x - a_rhs.x, y - a_rhs.y, z - a_rhs.z);
	}


	float NiPoint3::operator*(const NiPoint3& a_rhs) const
	{
		return x * a_rhs.x + y * a_rhs.y + z * a_rhs.z;
	}


	NiPoint3 NiPoint3::operator*(float a_scalar) const
	{
		return NiPoint3(x * a_scalar, y * a_scalar, z * a_scalar);
	}


	NiPoint3 NiPoint3::operator/(float a_scalar) const
	{
		return operator*(static_cast<float>(1.0) / a_scalar);
	}


	NiPoint3 NiPoint3::operator-() const
	{
		return NiPoint3(-x, -y, -z);
	}


	NiPoint3& NiPoint3::operator+=(const NiPoint3& a_rhs)
	{
		x += a_rhs.x;
		y += a_rhs.y;
		z += a_rhs.z;
		return *this;
	}


	NiPoint3& NiPoint3::operator-=(const NiPoint3& a_rhs)
	{
		x -= a_rhs.x;
		y -= a_rhs.y;
		z -= a_rhs.z;
		return *this;
	}


	NiPoint3& NiPoint3::operator*=(float a_scalar)
	{
		x *= a_scalar;
		y *= a_scalar;
		z *= a_scalar;
		return *this;
	}


	NiPoint3& NiPoint3::operator/=(float a_scalar)
	{
		return operator*=(static_cast<float>(1.0) / a_scalar);
	}


	float NiPoint3::SqrLength() const
	{
		return x * x + y * y + z * z;
	}


	float NiPoint3::Length() const
	{
		return std::sqrtf(x * x + y * y + z * z);
	}


	float NiPoint3::Unitize()
	{
		auto length = Length();
		if (!std::isnan(length)) {
			operator/=(length);
		} else {
			x = 0.0;
			y = 0.0;
			z = 0.0;
			length = 0.0;
		}
		return length;
	}


	NiPoint3 NiPoint3::Cross(const NiPoint3& a_pt) const
	{
		return NiPoint3(
			y * a_pt.z - z * a_pt.y,
			z * a_pt.x - x * a_pt.z,
			x * a_pt.y - y * a_pt.x);
	}


	NiPoint3 NiPoint3::UnitCross(const NiPoint3& a_pt) const
	{
		auto cross = Cross(a_pt);
		cross.Unitize();
		return cross;
	}


	float NiPoint3::GetArcTangent() const
	{
		float angle = 0.0;
		if (y == 0.0) {
			if (x > 0.0) {
				angle = 1.5707964;
				goto LABEL_9;
			}
			angle = 4.712389;
		} else {
			angle = atanf(x / y);
			if (y < 0.0) {
				angle = angle + 3.1415927;
			}
		}
		for (; angle < 0.0; angle = angle + 6.2831855)
			;
LABEL_9:
		while (angle > 6.2831855) {
			angle = angle + -6.2831855;
		}
		return angle;
	}
}
