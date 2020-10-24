#include "RE/NetImmerse/NiRefObject/NiObject/NiExtraData/NiIntegersExtraData.h"

#include "RE/NetImmerse/NiTCollection.h"


namespace RE
{
	NiIntegersExtraData* NiIntegersExtraData::Create(const BSFixedString& a_name, const std::vector<std::int32_t>& a_integers)
	{
		REL::Relocation<std::uintptr_t> vtbl{ RE::Offset::NiIntegersExtraData::Vtbl };

		auto data = NiExtraData::Create<NiIntegersExtraData>(vtbl.address());
		if (data) {
			data->name = a_name;
			data->size = static_cast<std::uint32_t>(a_integers.size());

			data->value = NiAlloc<std::int32_t>(a_integers.size());
			memcpy(data->value, a_integers.data(), a_integers.size() * sizeof(std::int32_t));
		}

		return data;
	}


	std::optional<std::uint32_t> NiIntegersExtraData::GetIndexOf(std::int32_t a_element) const
	{
		for (std::uint32_t i = 0; i < size; i++) {
			if (value[i] == a_element) {
				return i;
			}
		}

		return std::nullopt;
	}


	bool NiIntegersExtraData::InsertElement(std::int32_t a_element)
	{
		auto index = GetIndexOf(a_element);

		if (index == std::nullopt) {
			auto oldData = value;
			value = NiAlloc<std::int32_t>(++size);

			if (oldData) {
				for (std::uint32_t i = 0; i < size - 1; i++) {
					value[i] = oldData[i];
				}
				NiFree(oldData);
				oldData = nullptr;
			}
			value[size - 1] = a_element;

			return true;
		}

		return false;
	}


	bool NiIntegersExtraData::RemoveElement(std::int32_t a_element)
	{
		auto index = GetIndexOf(a_element);

		if (index != std::nullopt) {
			auto oldData = value;
			value = NiAlloc<std::int32_t>(--size);

			for (std::uint32_t i = 0; i < size + 1; i++) {
				if (i != index) {
					value[i] = oldData[i];
				}
			}
			NiFree(oldData);
			oldData = nullptr;

			return true;
		}

		return false;
	}
}