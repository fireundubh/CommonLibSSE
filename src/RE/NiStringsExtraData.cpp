#include "RE/NiStringsExtraData.h"
#include "RE/NiTCollection.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	NiStringsExtraData* NiStringsExtraData::Create(const BSFixedString& name, const BSFixedString* stringData, UInt32 size)
	{
		REL::Offset<std::uintptr_t> vtbl(RE::Offset::NiStringsExtraData::Vtbl);

		NiStringsExtraData* data = static_cast<NiStringsExtraData*>(NiExtraData::Create(sizeof(NiStringsExtraData), vtbl.GetAddress()));
		if (data) {
			data->name = name;
			data->size = size;
			data->value = NiAlloc<char*>(size);

			for (int i = 0; i < size; i++) {
				auto string = stringData[i].c_str();

				if (string && *string != '\0') {
					UInt32 strLength = strlen(string) + 1;
					data->value[i] = NiAlloc<char>(strLength);
					memcpy(data->value[i], string, sizeof(char) * strLength);
				}
			}
		}

		return data;
	}

	SInt32 NiStringsExtraData::GetIndexOf(const char* element) const
	{
		for (UInt32 i = 0; i < size; i++) {
			if (strcmp(value[i], element) == 0) {
				return i;
			}
		}

		return -1;
	}

	bool NiStringsExtraData::InsertElement(const char* element)
	{
		if (element && *element != '\0') {
			SInt32 index = GetIndexOf(element);

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

				UInt32 strLength = strlen(element) + 1;
				value[size - 1] = NiAlloc<char>(strLength);
				memcpy(value[size - 1], element, sizeof(char) * strLength);

				return true;
			}
		}

		return false;
	}

	bool NiStringsExtraData::RemoveElement(const char* element)
	{
		if (element && *element != '\0') {
			SInt32 index = GetIndexOf(element);

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