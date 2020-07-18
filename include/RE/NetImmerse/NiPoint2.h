#pragma once


namespace RE
{
	class NiPoint2
	{
	public:
		constexpr NiPoint2& operator=(const NiPoint2& a_rhs) noexcept
		{
			if (this != std::addressof(a_rhs)) {
				x = a_rhs.x;
				y = a_rhs.y;
			}
			return *this;
		}


		constexpr NiPoint2& operator=(NiPoint2&& a_rhs) noexcept
		{
			if (this != std::addressof(a_rhs)) {
				x = std::move(a_rhs.x);
				y = std::move(a_rhs.y);
			}
			return *this;
		}


		// members
		float x;  // 0
		float y;  // 4
	};
	static_assert(sizeof(NiPoint2) == 0x8);
}
