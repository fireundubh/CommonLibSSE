#pragma once

#include "RE/GridArray.h"
#include "RE/TESObjectCELL.h"

namespace RE
{
	class GridCellArray : public GridArray
	{
	public:
		inline static const void* RTTI = RTTI_GridCellArray;

		virtual ~GridCellArray();	// 00

		UInt32			unk08;		// 1000
		UInt32			unk0C;		// -1000
		UInt32			length;		// 010 - takes value from uGridsToLoad
		UInt32			pad14;		// 014
		TESObjectCELL**	cells;		// 018 - (memory allocated using 0x8 * numGrids * numGrids)
		NiPoint3		unk20;
		bool			unk2C;		// init - 0

		TESObjectCELL* GetCell(UInt32 x, UInt32 y)
		{ 
			if (x >= length || y >= length)
			{
				return nullptr;
			}
			return cells[(x * length) + y];
		};
	};
	static_assert(sizeof(GridCellArray) == 0x30);
};