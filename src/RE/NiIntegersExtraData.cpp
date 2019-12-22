#include "RE/NiIntegersExtraData.h"
#include "RE/NiTCollection.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	NiIntegersExtraData* NiIntegersExtraData::Create(const BSFixedString& name, SInt32* integer, UInt32 size)
	{
		REL::Offset<std::uintptr_t> vtbl(RE::Offset::NiIntegersExtraData::Vtbl);
		NiIntegersExtraData* data = static_cast<NiIntegersExtraData*>(NiExtraData::Create(sizeof(NiIntegersExtraData), vtbl.GetAddress()));

		if (data)
		{
			data->name = name;

			if (size > 0)
			{
				data->value = NiAlloc<SInt32>(size);
				memcpy(data->value, integer, size);
				data->size = size;
			}
			else
			{
				data->value = NULL;
				data->size = 0;
			}
		}

		return data;
	}

	SInt32 NiIntegersExtraData::GetIndexOf(SInt32 element)
	{
		for (UInt32 i = 0; i < size; i++)
		{
			if (value[i] == element)
			{
				return i;
			}
		}

		return -1;
	}

	bool NiIntegersExtraData::InsertElement(SInt32 element)
	{
		SInt32 index = GetIndexOf(element);

		if (index == -1)
		{
			auto oldValue = value;
			auto oldSize = size;

			value = NiAlloc<SInt32>(oldSize + 1);

			for (UInt32 i = 0; i < oldSize; i++)
			{
				value[i] = oldValue[i];
			}

			value[size] = element;

			NiFree(oldValue);
			oldValue = nullptr;

			size++;

			return true;
		}

		return false;
	}

	bool NiIntegersExtraData::RemoveElement(SInt32 element)
	{
		SInt32 index = GetIndexOf(element);

		if (index != -1)
		{
			auto oldValue = value;
			auto oldSize = size;

			value = NiAlloc<SInt32>(oldSize - 1);

			for (SInt32 i = 0; i < oldSize; i++)
			{
				if (i != index)
				{
					value[i] = oldValue[i];
				}
			}

			NiFree(oldValue);
			oldValue = nullptr;

			size = oldSize - 1;

			return true;
		}

		return false;
	}
}