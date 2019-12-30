#pragma once

#include "RE/FormTypes.h"
#include "RE/TESCondition.h"
#include "RE/TESContainer.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSConstructibleObject : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_BGSConstructibleObject;


		enum { kTypeID = FormType::ConstructibleObject };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Item
		{
			struct Object	// CNTO
			{
				UInt32		count;	// 00
				UInt32		unk04;	// 04
				TESForm*	item;	// 08
			};
			STATIC_ASSERT(sizeof(Object) == 0x10);


			struct ExtraData
			{
				UInt64	unk00;	// 00
			};
			STATIC_ASSERT(sizeof(ExtraData) == 0x8);


			Object		object;		// 00
			ExtraData*	extraData;	// 10
		};
		STATIC_ASSERT(sizeof(Item) == 0x18);


		virtual ~BGSConstructibleObject();				// 00

		// override (TESForm)
		virtual void	InitializeData() override;		// 04
		virtual void	ClearData() override;			// 05
		virtual bool	Load(TESFile* a_mod) override;	// 06
		virtual void	InitItemImpl() override;		// 13


		// members
		TESContainer	container;			// 20
		TESCondition	conditions;			// 38
		TESForm*		createdObject;		// 40 - CNAM
		BGSKeyword*		workbenchKeyword;	// 48 - BNAM
		UInt32			createdObjectCount;	// 50 - NAM1
		UInt32			unk54;				// 54
	};
	STATIC_ASSERT(sizeof(BGSConstructibleObject) == 0x58);
}
