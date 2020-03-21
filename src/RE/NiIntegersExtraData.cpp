#include "RE/NiIntegersExtraData.h"
#include "RE/NiTCollection.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	NiIntegersExtraData* NiIntegersExtraData::Create(const BSFixedString& name, const SInt32* integer, UInt32 size)
	{
		REL::Offset<std::uintptr_t> vtbl(RE::Offset::NiIntegersExtraData::Vtbl);
		NiIntegersExtraData* data = static_cast<NiIntegersExtraData*>(NiExtraData::Create(sizeof(NiIntegersExtraData), vtbl.GetAddress()));

		if (data) {
			data->name = name;
			data->size = size;

			data->value = NiAlloc<SInt32>(size);
			memcpy(data->value, integer, size * sizeof(SInt32));
		}

		return data;
	}

	SInt32 NiIntegersExtraData::GetIndexOf(SInt32 element) const
	{
		for (UInt32 i = 0; i < size; i++) {
			if (value[i] == element) {
				return i;
			}
		}

		return -1;
	}

	bool NiIntegersExtraData::InsertElement(SInt32 element)
	{
		auto index = GetIndexOf(element);

		if (index == -1) {
			auto temp = NiAlloc<SInt32>(size + 1);

			for (SInt32 i = 0; i < size; i++) {
				temp[i] = value[i];
			}

			temp[size] = element;

			NiFree(value);
			value = temp;
			size++;

			return true;
		}

		return false;
	}

	bool NiIntegersExtraData::RemoveElement(SInt32 element)
	{
		auto index = GetIndexOf(element);

		if (index != -1) {
			auto temp = NiAlloc<SInt32>(size - 1);

			for (SInt32 i = 0; i < size; i++) {
				if (i != index) {
					temp[i] = value[i];
				}
			}

			NiFree(value);
			value = temp;

			size--;

			return true;
		}

		return false;
	}
}