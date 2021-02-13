#pragma once

#include "RE/FormComponents/BaseFormComponent.h"
#include "RE/FormComponents/Components/ContainerItemExtra.h"


namespace RE
{
	class TESBoundObject;
	class TESForm;


	struct ContainerObject
	{
	public:
		ContainerObject();
		ContainerObject(TESBoundObject* a_obj, std::int32_t a_count);

		~ContainerObject() = default;

		TES_HEAP_REDEFINE_NEW();

		// members
		std::int32_t		count;		// 00 - CNTO~
		std::uint32_t		pad04;		// 04
		TESBoundObject*		obj;		// 08 - ~CNTO
		ContainerItemExtra* itemExtra;	// 10 - COED
	};
	static_assert(sizeof(ContainerObject) == 0x18);


	class TESContainer : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESContainer;


		virtual ~TESContainer();  // 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01 - { return; }
		virtual void ClearDataComponent() override;						// 02
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03


		inline void ForEachContainerObject(std::function<bool(ContainerObject&)> a_fn) const
		{
			for (std::uint32_t i = 0; i < numContainerObjects; ++i) {
				auto entry = containerObjects[i];
				if (entry) {
					if (!a_fn(*entry)) {
						break;
					}
				}
			}
		}

		bool							AddObjectToContainer(TESBoundObject* a_obj, std::int32_t a_count, TESForm* a_owner);
		std::optional<ContainerObject*> GetContainerObjectAt(std::uint32_t a_idx) const;
		std::int32_t					CountObjectsInContainer(TESBoundObject* a_object) const;
		void							RemoveObjectFromContainer(TESBoundObject* a_obj, std::int32_t a_count);


		// members
		ContainerObject** containerObjects;		// 08
		std::uint32_t	  numContainerObjects;	// 10
		std::uint32_t	  pad14;				// 14
	};
	static_assert(sizeof(TESContainer) == 0x18);
}
