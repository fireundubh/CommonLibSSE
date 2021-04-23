#pragma once

#include "RE/NetImmerse/NiPoint3.h"


namespace RE
{
	class NiMatrix3
	{
	public:
		NiMatrix3() {}
		NiMatrix3(const NiPoint3& a_col0, const NiPoint3& a_col1, const NiPoint3& a_col2)
		{
			SetCol(0, a_col0);
			SetCol(1, a_col1);
			SetCol(2, a_col2);
		}

		void GetRow(std::uint32_t a_row, NiPoint3& a_pt) const
		{
			a_pt.x = entry[a_row][0];
			a_pt.y = entry[a_row][1];
			a_pt.z = entry[a_row][2];
		}
		void GetRow(std::uint32_t a_row, float& a_f0, float& a_f1, float& a_f2) const
		{
			a_f0 = entry[a_row][0];
			a_f1 = entry[a_row][1];
			a_f2 = entry[a_row][2];
		}
		void SetRow(std::uint32_t a_row, const NiPoint3& a_pt)
		{
			entry[a_row][0] = a_pt.x;
			entry[a_row][1] = a_pt.y;
			entry[a_row][2] = a_pt.z;
		}
		void SetRow(std::uint32_t a_row, float a_f0, float a_f1, float a_f2)
		{
			entry[a_row][0] = a_f0;
			entry[a_row][1] = a_f1;
			entry[a_row][2] = a_f2;
		}
		void GetCol(std::uint32_t a_col, NiPoint3& a_pt) const
		{
			a_pt.x = entry[0][a_col];
			a_pt.y = entry[1][a_col];
			a_pt.z = entry[2][a_col];
		}
		void GetCol(std::uint32_t a_col, float& a_f0, float& a_f1, float& a_f2) const
		{
			a_f0 = entry[0][a_col];
			a_f1 = entry[1][a_col];
			a_f2 = entry[2][a_col];
		}
		void SetCol(std::uint32_t a_col, const NiPoint3& a_pt)
		{
			entry[0][a_col] = a_pt.x;
			entry[1][a_col] = a_pt.y;
			entry[2][a_col] = a_pt.z;
		}
		void SetCol(std::uint32_t a_col, float a_f0, float a_f1, float a_f2)
		{
			entry[0][a_col] = a_f0;
			entry[1][a_col] = a_f1;
			entry[2][a_col] = a_f2;
		}


		float GetEntry(std::size_t a_row, std::size_t a_col) const
		{
			return entry[a_row][a_col];
		}

		void SetEntry(std::size_t a_row, std::size_t a_col, float f)
		{
			entry[a_row][a_col] = f;
		}

		float& operator()(std::size_t a_row, std::size_t a_col)
		{
			return entry[a_row][a_col];
		}

		const float& operator()(std::size_t a_row, std::size_t a_col) const
		{
			return entry[a_row][a_col];
		}

		bool       operator==(const NiMatrix3& a_mat) const;
		bool       operator!=(const NiMatrix3& a_mat) const;
		NiMatrix3  operator+(const NiMatrix3& a_mat) const;
		NiMatrix3  operator-(const NiMatrix3& a_mat) const;
		NiMatrix3  operator*(const NiMatrix3& a_rhs) const;
		NiPoint3   operator*(const NiPoint3& a_pt) const;
		NiMatrix3  operator+(float a_scalar) const;
		NiMatrix3  operator*(float a_scalar) const;
		NiMatrix3& operator+=(float a_scalar);
		NiMatrix3& operator*=(float a_scalar);

		void EulerAnglesToAxesZXY(const NiPoint3& a_angle);
		void EulerAnglesToAxesZXY(float a_xAngle, float a_yAngle, float a_zAngle);

		void Zero();
		void Identity();
		void SetEulerAnglesXYZ(float a_xAngle, float a_yAngle, float a_zAngle);
		void SetEulerAnglesXYZ(const NiPoint3& a_point);
		bool ToEulerAnglesXYZ(NiPoint3& a_angle) const;
		bool ToEulerAnglesXYZ(float& a_xAngle, float& a_yAngle, float& a_zAngle) const;


		// members
		float entry[3][3];	// 00
	};
	static_assert(sizeof(NiMatrix3) == 0x24);
}
