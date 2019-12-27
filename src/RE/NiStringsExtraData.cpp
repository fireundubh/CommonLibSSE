#include "RE/NiStringsExtraData.h"
#include "RE/NiTCollection.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	NiStringsExtraData* NiStringsExtraData::Create(const BSFixedString& name, BSFixedString* stringData, UInt32 size)
	{
		REL::Offset<std::uintptr_t> vtbl(RE::Offset::NiStringsExtraData::Vtbl);

		NiStringsExtraData* data = (NiStringsExtraData*)NiExtraData::Create(sizeof(NiStringsExtraData), vtbl.GetAddress());
		if (data)
		{
			data->name = name;
			data->value = NiAlloc<char*>(size);
			data->size = size;

			for (int i = 0; i < size; i++)
			{
				auto string = stringData[i].c_str();

				if (string && *string != '\0')
				{
					UInt32 strLength = strlen(string) + 1;
					data->value[i] = NiAlloc<char>(strLength);
					memcpy(data->value[i], string, sizeof(char) * strLength);
				}
			}
		}

		return data;
	}

	SInt32 NiStringsExtraData::GetIndexOf(const char* element)
	{
		if (element && *element != '\0')
		{
			for (UInt32 i = 0; i < size; i++)
			{
				if (strcmp(value[i], element) == 0)
				{
					return i;
				}
			}
		}

		return -1;
	}

	bool NiStringsExtraData::InsertElement(const char* element)
	{
		SInt32 index = GetIndexOf(element);

		if (index == -1)
		{
			auto oldValue = value;
			auto oldSize = size;

			value = NiAlloc<char*>(oldSize + 1);

			for (UInt32 i = 0; i < oldSize; i++)
			{
				value[i] = oldValue[i];

				NiFree(oldValue[i]);
				oldValue[i] = nullptr;
			}

			UInt32 strLength = strlen(element) + 1;
			value[size] = NiAlloc<char>(strLength);
			memcpy(value[size], element, sizeof(char) * strLength);

			NiFree(oldValue);
			oldValue = nullptr;

			size++;

			return true;
		}

		return false;
	}

	bool NiStringsExtraData::RemoveElement(const char* element)
	{
		SInt32 index = GetIndexOf(const_cast<char*>(element));

		if (index != -1)
		{
			auto oldData = value;
			auto oldSize = size;

			value = NiAlloc<char*>(oldSize - 1);

			for (SInt32 i = 0; i < oldSize; i++)
			{
				if (i != index)
				{
					value[i] = oldData[i];
				}
				NiFree(oldData[i]);
				oldData[i] = nullptr;
			}

			NiFree(oldData);
			oldData = nullptr;

			size--;

			return true;
		}

		return false;
	}
}