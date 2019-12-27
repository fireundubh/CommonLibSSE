#pragma once

#include "RE/NiPoint3.h"

namespace RE
{
	class GridArray
	{
	public:
		inline static const void* RTTI = RTTI_GridArray;

		virtual ~GridArray();	// 00
	};
	static_assert(sizeof(GridArray) == 0x08);
};