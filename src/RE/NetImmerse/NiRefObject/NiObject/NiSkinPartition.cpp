#include "RE/NetImmerse/NiRefObject/NiObject/NiSkinPartition.h"


namespace RE
{
	auto NiSkinPartition::GetVertexFlags(UInt64 vertexDesc)
		-> NiSkinPartition::Vertex::Flags
	{
		return Vertex::Flags((vertexDesc & to_underlying(Vertex::Masks::kOFFSET)) >> 44);
	}


	UInt32 NiSkinPartition::GetVertexSize(UInt64 vertexDesc)
	{
		using Flags = Vertex::Flags;
		
		UInt32 vertexSize = 0;
		
		auto flags = GetVertexFlags(vertexDesc);
		if ((flags & Flags::kVertex) == Flags::kVertex) {
			vertexSize += sizeof(float) * 4;
		}
		if ((flags & Flags::kUV) == Flags::kUV) {
			vertexSize += sizeof(UInt16) * 2;
		}
		if ((flags & Flags::kUV_2) == Flags::kUV_2) {
			vertexSize += sizeof(UInt16) * 2;
		}
		if ((flags & Flags::kNormal) == Flags::kNormal) {
			vertexSize += sizeof(UInt16) * 2;
			if ((flags & Flags::kTangent) == Flags::kTangent) {
				vertexSize += sizeof(UInt16) * 2;
			}
		}
		if ((flags & Flags::kColors) == Flags::kColors) {
			vertexSize += sizeof(UInt8) * 4;
		}
		if ((flags & Flags::kSkinned) == Flags::kSkinned) {
			vertexSize += sizeof(UInt16) * 4 + sizeof(UInt8) * 4;
		}
		if ((flags & Flags::kEyeData) == Flags::kEyeData) {
			vertexSize += sizeof(float);
		}

		return vertexSize;
	}
}
