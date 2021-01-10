#include "RE/NetImmerse/NiRefObject/NiObject/NiSkinInstance/BSDismemberSkinInstance.h"


namespace RE
{
	void BSDismemberSkinInstance::UpdateDismemberPartion(std::uint16_t a_slot, bool a_enable)
	{
		if (partitions) {
			stl::span<Data> span(partitions, numPartitions);
			for (auto& data : span) {				
				if (data.slot == a_slot) {
					data.editorVisible = a_enable;
				}
			}
		}
	}


	void BSDismemberSkinInstance::UpdateDismemberPartion(bool a_enable)
	{
		if (partitions) {
			stl::span<Data> span(partitions, numPartitions);
			for (auto& data : span) {
				data.editorVisible = a_enable;
			}
		}
	}
}
