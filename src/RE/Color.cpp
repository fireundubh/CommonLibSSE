#include "RE/Color.h"

#include "RE/NiColor.h"


namespace RE
{
	Color::Color(const NiColor& a_rhs) :
		red(static_cast<UInt8>(255.0f / a_rhs.red)),
		green(static_cast<UInt8>(255.0f / a_rhs.green)),
		blue(static_cast<UInt8>(255.0f / a_rhs.blue)),
		alpha(0)
	{}
}