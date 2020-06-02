#include "RE/NetImmerse/NiRefObject/NiObject/NiExtraData/NiStringsExtraData.h"

#include "RE/NetImmerse/NiTCollection.h"


namespace RE
{
	NiStringsExtraData* NiStringsExtraData::Create(const std::string& a_name, const std::vector<std::string>& a_strings)
	{
		REL::Offset<std::uintptr_t> vtbl(RE::Offset::NiStringsExtraData::Vtbl);

		NiStringsExtraData* data = static_cast<NiStringsExtraData*>(NiExtraData::Create(sizeof(NiStringsExtraData), vtbl.GetAddress()));
		if (data) {		
			data->name = a_name.c_str();
			data->size = static_cast<UInt32>(a_strings.size());
			data->value = NiAlloc<char*>(a_strings.size());
		
			for (size_t i = 0; i < a_strings.size(); i++) {
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


	SInt32 NiStringsExtraData::GetIndexOf(const std::string& a_element) const
	{
		for (UInt32 i = 0; i < size; i++) {
			if (a_element == value[i]) {
				return i;
			}
		}

		return -1;
	}


	bool NiStringsExtraData::InsertElement(const std::string& a_element)
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
				memcpy(value[size - 1], a_element.c_str(), sizeof(char) * strLength);

				return true;
			}
		}

		return false;
	}


	bool NiStringsExtraData::RemoveElement(const std::string& a_element)
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