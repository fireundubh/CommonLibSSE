#pragma once


namespace RE
{
	constexpr float NI_INFINITY = FLT_MAX;
	constexpr float NI_PI = static_cast<float>(3.1415926535897932);
	constexpr float NI_HALF_PI = 0.5 * NI_PI;
	constexpr float NI_TWO_PI = 2.0 * NI_PI;


	inline float degToRad(float a_degrees)
	{
		return a_degrees == 0.0f ? 0.0f : a_degrees * NI_PI / 180.0f;
	}
	inline float radToDeg(float a_radians)
	{
		return a_radians == 0.0f ? 0.0f : a_radians * 180.0f / NI_PI;
	}

	float NiAbs(float a_value);
	float NiASin(float a_value);
	float NiFastATan2(float a_y, float a_x);
}
