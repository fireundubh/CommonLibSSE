#include "RE/NetImmerse/NiRefObject/NiObject/NiSkinPartition.h"


namespace RE
{
	auto NiSkinPartition::GetVertexFlags(std::uint64_t vertexDesc)
		-> NiSkinPartition::Vertex::Flags
	{
		return Vertex::Flags((vertexDesc & to_underlying(Vertex::Masks::kOFFSET)) >> 44);
	}


	std::uint32_t NiSkinPartition::GetVertexSize(std::uint64_t vertexDesc)
	{
		using Flags = Vertex::Flags;

		std::uint32_t vertexSize = 0;

		auto flags = GetVertexFlags(vertexDesc);
		if ((flags & Flags::kVertex) == Flags::kVertex) {
			vertexSize += sizeof(float) * 4;
		}
		if ((flags & Flags::kUV) == Flags::kUV) {
			vertexSize += sizeof(std::uint16_t) * 2;
		}
		if ((flags & Flags::kUV_2) == Flags::kUV_2) {
			vertexSize += sizeof(std::uint16_t) * 2;
		}
		if ((flags & Flags::kNormal) == Flags::kNormal) {
			vertexSize += sizeof(std::uint16_t) * 2;
			if ((flags & Flags::kTangent) == Flags::kTangent) {
				vertexSize += sizeof(std::uint16_t) * 2;
			}
		}
		if ((flags & Flags::kColors) == Flags::kColors) {
			vertexSize += sizeof(std::uint8_t) * 4;
		}
		if ((flags & Flags::kSkinned) == Flags::kSkinned) {
			vertexSize += sizeof(std::uint16_t) * 4 + sizeof(std::uint8_t) * 4;
		}
		if ((flags & Flags::kEyeData) == Flags::kEyeData) {
			vertexSize += sizeof(float);
		}

		return vertexSize;
	}
}
