#pragma once

#include "RE/BSTArray.h"
#include "RE/Condition.h"
#include "RE/FormTypes.h"
#include "RE/PerkRankVisitor.h"
#include "RE/TESDescription.h"
#include "RE/TESForm.h"
#include "RE/TESFullName.h"
#include "RE/TESIcon.h"


namespace RE
{
	class BGSPerkEntry;


	class BGSPerk :
		public TESForm,			// 00
		public TESFullName,		// 20
		public TESDescription,	// 30
		public TESIcon			// 40
	{
	public:
		inline static const void* RTTI = RTTI_BGSPerk;


		enum { kTypeID = FormType::Perk };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kNonPlayable = 1 << 2,
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		class FindPerkInRanksVisitor : public PerkRankVisitor
		{
		public:
			inline static const void* RTTI = RTTI_BGSPerk__FindPerkInRanksVisitor;


			virtual bool operator()(const BGSPerkRankArray::Entry* a_entry) override;	// 00
		};


		class ApplyPerksVisitor : public PerkRankVisitor
		{
		public:
			inline static const void* RTTI = RTTI_BGSPerk__ApplyPerksVisitor;


			virtual bool operator()(const BGSPerkRankArray::Entry* a_entry) override;	// 00
		};


		class AddPerkVisitor : public PerkRankVisitor
		{
		public:
			inline static const void* RTTI = RTTI_BGSPerk__AddPerkVisitor;


			virtual bool operator()(const BGSPerkRankArray::Entry* a_entry) override;	// 00
		};


		struct Data	// DATA
		{
			bool	trait;		// 0
			UInt8	level;		// 1
			UInt8	numRanks;	// 2
			bool	playable;	// 3
			bool	hidden;		// 4
			UInt8	pad5;		// 5
			UInt16	pad6;		// 6
		};
		STATIC_ASSERT(sizeof(Data) == 0x8);


		virtual ~BGSPerk();								// 00

		// override (TESForm)
		virtual void	InitializeData() override;		// 04
		virtual void	ClearData() override;			// 05
		virtual bool	Load(TESFile* a_mod) override;	// 06
		virtual void	InitItemImpl() override;		// 13


		// members
		Data					data;			// 50 - DATA
		Condition				conditions;		// 58
		BSTArray<BGSPerkEntry*>	perkEntries;	// 60
		BGSPerk*				nextPerk;		// 78 - NNAM
	};
	STATIC_ASSERT(sizeof(BGSPerk) == 0x80);
}
