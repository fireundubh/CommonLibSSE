#include "RE/NetImmerse/NiRefObject/NiObject/NiExtraData/NiStringsExtraData.h"

#include "RE/NetImmerse/NiTCollection.h"


namespace RE
{
	NiStringsExtraData* NiStringsExtraData::Create(const BSFixedString& a_name, const std::vector<BSFixedString>& a_strings)
	{
		REL::Offset<std::uintptr_t> vtbl(RE::Offset::NiStringsExtraData::Vtbl);

		auto data = NiExtraData::Create<NiStringsExtraData>(vtbl.address());
		if (data) {
			data->name = a_name;
			
			auto size = a_strings.size();
			data->size = static_cast<UInt32>(size);
			data->value = NiAlloc<char*>(size);

			for (size_t i = 0; i < size; i++) {
				auto string = a_strings[i];
				if (!string.empty()) {
					UInt32 strLength = string.length() + 1;
					data->value[i] = NiAlloc<char>(strLength);
					memcpy(data->value[i], string.c_str(), sizeof(char) * strLength);
				}
			}
		}
		return data;
	}


	SInt32 NiStringsExtraData::GetIndexOf(const BSFixedString& a_element) const
	{
		for (UInt32 i = 0; i < size; i++) {
			if (strcmp(a_element.c_str(), value[i]) == 0) {
				return i;
			}
		}

		return -1;
	}


	bool NiStringsExtraData::InsertElement(const BSFixedString& a_element)
	{
		if (!a_element.empty()) {
			auto index = GetIndexOf(a_element);

			if (index == -1) {
				auto oldData = value;
				value = NiAlloc<char*>(++size);

				for (SInt32 i = 0; i < size - 1; i++) {
					UInt32 strLength = strlen(oldData[i]) + 1;
					value[i] = NiAlloc<char>(strLength);
					memcpy(value[i], oldData[i], sizeof(char) * strLength);

					NiFree(oldData[i]);
					oldData[i] = nullptr;
				}
				NiFree(oldData);

				UInt32 strLength = a_element.length() + 1;
				value[size - 1] = NiAlloc<char>(strLength);
				memcpy(value[size - 1], a_element.data(), sizeof(char) * strLength);

				return true;
			}
		}

		return false;
	}


	bool NiStringsExtraData::RemoveElement(const BSFixedString& a_element)
	{
		if (!a_element.empty()) {
			auto index = GetIndexOf(a_element);

			if (index != -1) {
				auto oldData = value;
				value = NiAlloc<char*>(--size);

				for (SInt32 i = 0; i < size + 1; i++) {
					if (i != index) {
						UInt32 strLength = strlen(oldData[i]) + 1;
						value[i] = NiAlloc<char>(strLength);
						memcpy(value[i], oldData[i], sizeof(char) * strLength);
					}
					NiFree(oldData[i]);
					oldData[i] = nullptr;
				}
				NiFree(oldData);

				return true;
			}
		}

		return false;
	}
}