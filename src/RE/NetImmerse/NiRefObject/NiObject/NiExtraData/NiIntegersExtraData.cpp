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


	std::int32_t NiIntegersExtraData::GetIndexOf(std::int32_t a_element) const
	{
		for (std::uint32_t i = 0; i < size; i++) {
			if (value[i] == a_element) {
				return i;
			}
		}

		return -1;
	}


	bool NiIntegersExtraData::InsertElement(std::int32_t a_element)
	{
		auto index = GetIndexOf(a_element);

		if (index == -1) {
			auto temp = NiAlloc<std::int32_t>(++size);

			for (std::int32_t i = 0; i < size - 1; i++) {
				temp[i] = value[i];
			}
			temp[size - 1] = a_element;
			NiFree(value);
			value = temp;

			return true;
		}

		return false;
	}


	bool NiIntegersExtraData::RemoveElement(std::int32_t a_element)
	{
		auto index = GetIndexOf(a_element);

		if (index != -1) {
			auto temp = NiAlloc<std::int32_t>(--size);

			for (std::int32_t i = 0; i < size + 1; i++) {
				if (i != index) {
					temp[i] = value[i];
				}
			}
			NiFree(value);
			value = temp;

			return true;
		}

		return false;
	}
}