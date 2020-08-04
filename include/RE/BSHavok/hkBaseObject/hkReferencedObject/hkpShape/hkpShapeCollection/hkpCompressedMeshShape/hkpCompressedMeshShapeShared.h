#pragma once

#include "RE/BSHavok/hkBaseObject/hkReferencedObject/hkpShape/hkpShapeCollection/hkpCompressedMeshShape/hkpCompressedMeshShape.h"


namespace RE
{
	namespace
	{
		class hkpCompressedMeshShapeShared : public hkpCompressedMeshShape
		{
		public:
			inline static constexpr auto RTTI = RTTI_hkpCompressedMeshShape;


			virtual ~hkpCompressedMeshShapeShared();  // 00


			//members
			std::uint64_t unk120;  // 120
			std::uint64_t unk128;  // 128
			std::uint64_t unk130;  // 130
		};
		static_assert(sizeof(hkpCompressedMeshShapeShared) == 0x140);
	}
}
