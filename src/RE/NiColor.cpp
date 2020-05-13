#include "RE/NiColor.h"
#include "RE/Color.h"


namespace RE
{
	NiColor::NiColor(const Color& a_rhs) :
		red(a_rhs.red / 255.0f),
		green(a_rhs.green / 255.0f),
		blue(a_rhs.blue / 255.0f)
	{}

	std::string NiColor::ColorToHex(const NiColor& a_rhs)
	{
		char hexcol[16];
		snprintf(hexcol, sizeof(hexcol), "%02x%02x%02x", static_cast<UInt32>((a_rhs.red * 255)), static_cast<UInt32>((a_rhs.green * 255)), static_cast<UInt32>((a_rhs.blue * 255)));
		return std::string(hexcol);
	}
}