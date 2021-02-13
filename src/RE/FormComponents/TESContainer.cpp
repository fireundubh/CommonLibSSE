#include "RE/FormComponents/TESContainer.h"

#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/TESForm.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundObject.h"
#include "SKSE/Logger.h"


namespace RE
{
	ContainerObject::ContainerObject() :
		count(0),
		pad04(0),
		obj(nullptr),
		itemExtra()
	{
	}


	ContainerObject::ContainerObject(TESBoundObject* a_obj, std::int32_t a_count) :
		count(a_count),
		pad04(0),
		obj(a_obj),
		itemExtra()
	{
	}


	bool TESContainer::AddObjectToContainer(TESBoundObject* a_object, std::int32_t a_count, TESForm* a_owner)
	{
		bool added = false;
		ForEachContainerObject([&](ContainerObject& a_contObj) {
			if (a_contObj.obj == a_object) {
				a_contObj.count += a_count;
				added = true;
			}
			return true;
		});
		if (!added) {
			if (const auto newObj = new ContainerObject(a_object, a_count); newObj) {
				const auto itemExtra = newObj->itemExtra;
				if (itemExtra) {
					itemExtra->owner = a_owner;
				}
				auto oldData = containerObjects;
				containerObjects = calloc<ContainerObject*>(++numContainerObjects);
				if (oldData) {
					for (std::uint32_t i = 0; i < numContainerObjects - 1; i++) {
						containerObjects[i] = oldData[i];
					}
					free(oldData);
					oldData = nullptr;
				}
				containerObjects[numContainerObjects - 1] = newObj;
				added = true;
			}
		}
		return added;
	}


	auto TESContainer::GetContainerObjectAt(std::uint32_t a_idx) const
		-> std::optional<ContainerObject*>
	{
		if (a_idx < numContainerObjects) {
			return std::make_optional(containerObjects[a_idx]);
		} else {
			return std::nullopt;
		}
	}


	std::int32_t TESContainer::CountObjectsInContainer(TESBoundObject* a_object) const
	{
		std::int32_t count = 0;
		ForEachContainerObject([&](ContainerObject& a_contObj) {
			if (a_contObj.obj == a_object) {
				count += a_contObj.count;
			}
			return true;
		});
		return count;
	}


	void TESContainer::RemoveObjectFromContainer(TESBoundObject* a_obj, std::int32_t a_count)
	{
		std::vector<std::uint32_t> indexes;

		for (std::uint32_t i = 0; i < numContainerObjects; ++i) {
			auto entry = containerObjects[i];
			if (entry && entry->obj == a_obj) {
				entry->count -= a_count;
				if (entry->count < 1) {
					indexes.push_back(i);
				}
			}
		}

		if (!indexes.empty()) {
			auto oldData = containerObjects;
			containerObjects = RE::malloc<ContainerObject*>(numContainerObjects - indexes.size());

			for (std::uint32_t i = 0; i < numContainerObjects + indexes.size(); i++) {
				if (std::none_of(indexes.begin(), indexes.end(), [i](const auto& index) { return i == index; })) {
					containerObjects[i] = oldData[i];
				}
			}
			RE::free(oldData);
			oldData = nullptr;
		}
	}
}
