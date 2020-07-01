#include "RE/FormComponents/Components/Color.h"

#include "RE/NetImmerse/NiColor.h"


namespace RE
{
	Color::Color(const NiColor& a_rhs) :
		red(static_cast<UInt8>(255.0f / a_rhs.red)),
		green(static_cast<UInt8>(255.0f / a_rhs.green)),
		blue(static_cast<UInt8>(255.0f / a_rhs.blue)),
		alpha(0)
	{}


	UInt32 Color::ColorToInt(const Color& a_rhs)
	{
		return ((a_rhs.red & 0xFF) << 16) + ((a_rhs.green & 0xFF) << 8) + (a_rhs.blue & 0xFF);
	}


	std::string Color::ColorToString(const Color& a_rhs)
	{
		char hexcol[16];
		snprintf(hexcol, sizeof(hexcol), "%02x%02x%02x", a_rhs.red, a_rhs.green, a_rhs.blue);
		return std::string(hexcol);
	}
}