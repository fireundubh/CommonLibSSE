#include "RE/NetImmerse/NiMatrix3.h"

#include "RE/NetImmerse/NiMath.h"


namespace RE
{
	void NiMatrix3::Identity()
	{
		SetCol(0, 1.0f, 0.0f, 0.0f);
		SetCol(1, 0.0f, 1.0f, 0.0f);
		SetCol(2, 0.0f, 0.0f, 1.0f);
	}


	void NiMatrix3::Zero()
	{
		SetCol(0, 0.0f, 0.0f, 0.0f);
		SetCol(1, 0.0f, 0.0f, 0.0f);
		SetCol(2, 0.0f, 0.0f, 0.0f);
	}


	bool NiMatrix3::operator==(const NiMatrix3& a_mat) const
	{
		return (entry[0][0] == a_mat.entry[0][0]) &&
			   (entry[0][1] == a_mat.entry[0][1]) &&
			   (entry[0][2] == a_mat.entry[0][2]) &&
			   (entry[1][0] == a_mat.entry[1][0]) &&
			   (entry[1][1] == a_mat.entry[1][1]) &&
			   (entry[1][2] == a_mat.entry[1][2]) &&
			   (entry[2][0] == a_mat.entry[2][0]) &&
			   (entry[2][1] == a_mat.entry[2][1]) &&
			   (entry[2][2] == a_mat.entry[2][2]);
	}


	bool NiMatrix3::operator!=(const NiMatrix3& mat) const
	{
		return !operator==(mat);
	}


	NiMatrix3 NiMatrix3::operator+(const NiMatrix3& a_mat) const
	{
		NiMatrix3 tmp = *this;
		tmp.entry[0][0] += a_mat.entry[0][0];
		tmp.entry[0][1] += a_mat.entry[0][1];
		tmp.entry[0][2] += a_mat.entry[0][2];
		tmp.entry[1][0] += a_mat.entry[1][0];
		tmp.entry[1][1] += a_mat.entry[1][1];
		tmp.entry[1][2] += a_mat.entry[1][2];
		tmp.entry[2][0] += a_mat.entry[2][0];
		tmp.entry[2][1] += a_mat.entry[2][1];
		tmp.entry[2][2] += a_mat.entry[2][2];
		return tmp;
	}


	NiMatrix3 NiMatrix3::operator-(const NiMatrix3& a_mat) const
	{
		NiMatrix3 tmp = *this;
		tmp.entry[0][0] -= a_mat.entry[0][0];
		tmp.entry[0][1] -= a_mat.entry[0][1];
		tmp.entry[0][2] -= a_mat.entry[0][2];
		tmp.entry[1][0] -= a_mat.entry[1][0];
		tmp.entry[1][1] -= a_mat.entry[1][1];
		tmp.entry[1][2] -= a_mat.entry[1][2];
		tmp.entry[2][0] -= a_mat.entry[2][0];
		tmp.entry[2][1] -= a_mat.entry[2][1];
		tmp.entry[2][2] -= a_mat.entry[2][2];
		return tmp;
	}


	NiMatrix3 NiMatrix3::operator*(const NiMatrix3& a_rhs) const
	{
		NiMatrix3 tmp;
		tmp.entry[0][0] =
			entry[0][0] * a_rhs.entry[0][0] +
			entry[0][1] * a_rhs.entry[1][0] +
			entry[0][2] * a_rhs.entry[2][0];

		tmp.entry[1][0] =
			entry[1][0] * a_rhs.entry[0][0] +
			entry[1][1] * a_rhs.entry[1][0] +
			entry[1][2] * a_rhs.entry[2][0];

		tmp.entry[2][0] =
			entry[2][0] * a_rhs.entry[0][0] +
			entry[2][1] * a_rhs.entry[1][0] +
			entry[2][2] * a_rhs.entry[2][0];

		tmp.entry[0][1] =
			entry[0][0] * a_rhs.entry[0][1] +
			entry[0][1] * a_rhs.entry[1][1] +
			entry[0][2] * a_rhs.entry[2][1];

		tmp.entry[1][1] =
			entry[1][0] * a_rhs.entry[0][1] +
			entry[1][1] * a_rhs.entry[1][1] +
			entry[1][2] * a_rhs.entry[2][1];

		tmp.entry[2][1] =
			entry[2][0] * a_rhs.entry[0][1] +
			entry[2][1] * a_rhs.entry[1][1] +
			entry[2][2] * a_rhs.entry[2][1];

		tmp.entry[0][2] =
			entry[0][0] * a_rhs.entry[0][2] +
			entry[0][1] * a_rhs.entry[1][2] +
			entry[0][2] * a_rhs.entry[2][2];

		tmp.entry[1][2] =
			entry[1][0] * a_rhs.entry[0][2] +
			entry[1][1] * a_rhs.entry[1][2] +
			entry[1][2] * a_rhs.entry[2][2];

		tmp.entry[2][2] =
			entry[2][0] * a_rhs.entry[0][2] +
			entry[2][1] * a_rhs.entry[1][2] +
			entry[2][2] * a_rhs.entry[2][2];

		return tmp;
	}


	NiMatrix3 NiMatrix3::operator*(float a_scalar) const
	{
		NiMatrix3 result;
		result.entry[0][0] = entry[0][0] * a_scalar;
		result.entry[0][1] = entry[0][1] * a_scalar;
		result.entry[0][2] = entry[0][2] * a_scalar;
		result.entry[1][0] = entry[1][0] * a_scalar;
		result.entry[1][1] = entry[1][1] * a_scalar;
		result.entry[1][2] = entry[1][2] * a_scalar;
		result.entry[2][0] = entry[2][0] * a_scalar;
		result.entry[2][1] = entry[2][1] * a_scalar;
		result.entry[2][2] = entry[2][2] * a_scalar;
		return result;
	}


	NiPoint3 NiMatrix3::operator*(const NiPoint3& a_pt) const
	{
		return NiPoint3(
			entry[0][0] * a_pt.x + entry[0][1] * a_pt.y + entry[0][2] * a_pt.z,
			entry[1][0] * a_pt.x + entry[1][1] * a_pt.y + entry[1][2] * a_pt.z,
			entry[2][0] * a_pt.x + entry[2][1] * a_pt.y + entry[2][2] * a_pt.z);
	}


	void NiMatrix3::SetEulerAnglesXYZ(float a_x, float a_y, float a_z)
	{
		float sinX = std::sinf(a_x);
		float sinY = std::sinf(a_y);
		float sinZ = std::sinf(a_z);

		float cosX = std::cosf(a_x);
		float cosY = std::cosf(a_y);
		float cosZ = std::cosf(a_z);

		entry[0][0] = cosY * cosZ;
		entry[0][1] = cosY * sinZ;
		entry[0][2] = -sinY;
		entry[1][0] = sinX * sinY * cosZ - cosX * sinZ;
		entry[1][1] = sinX * sinY * sinZ + cosX * cosZ;
		entry[1][2] = sinX * cosY;
		entry[2][0] = cosX * sinY * cosZ + sinX * sinZ;
		entry[2][1] = cosX * sinY * sinZ - sinX * cosZ;
		entry[2][2] = cosX * cosY;
	}


	bool NiMatrix3::ToEulerAnglesXYZ(NiPoint3& a_angle) const
	{
		return ToEulerAnglesXYZ(a_angle.x, a_angle.y, a_angle.z);
	}


	bool NiMatrix3::ToEulerAnglesXYZ(float& a_xAngle, float& a_yAngle, float& a_zAngle) const
	{
		a_yAngle = -NiASin(entry[0][2]);
		if (a_yAngle < NI_HALF_PI) {
			if (a_yAngle > -NI_HALF_PI) {
				a_xAngle = -NiFastATan2(-entry[1][2], entry[2][2]);
				a_zAngle = -NiFastATan2(-entry[0][1], entry[0][0]);
				return true;
			} else {
				float rmY = NiFastATan2(entry[1][0], entry[1][1]);
				a_zAngle = 0.0;
				a_xAngle = rmY - a_zAngle;
				return false;
			}
		} else {
			float rpY = NiFastATan2(entry[1][0], entry[1][1]);
			a_zAngle = 0.0;
			a_xAngle = a_zAngle - rpY;
			return false;
		}
	}
}
