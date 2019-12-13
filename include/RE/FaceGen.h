#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSTSingleton.h"

#include "RE/BSFaceGenNiNode.h"
#include "RE/TESNPC.h"
#include "RE/BGSHeadPart.h"

class BGSHeadPart;

namespace RE
{
	class FaceGen : public BSTSingletonSDM<FaceGen>
	{
	public:
		static FaceGen* GetSingleton();

		void RegenerateHead(BSFaceGenNiNode* a_headNode, BGSHeadPart* a_head, TESNPC* a_npc);

		struct Action
		{
			BSFixedString name;
			UInt32	unk04;
			float	delta;
		};

		// 40
		class MorphDatabase
		{
		public:
			UInt64	unk00;	// 00
			UInt32	unk08;	// 08
			UInt32	unk0C;	// 0C
			UInt32	unk10;	// 10
			UInt32	unk14;	// 14
			void* unk18;	// 18
			UInt64	unk20;	// 20
			UInt64	unk28;	// 28

			struct Data30
			{
				UInt32	unk00;
				UInt32	unk04;
			};

			Data30	unk30;		// 30
			UInt8	unk38;		// 38
			UInt8	pad39[7];	// 39
		};

		UInt32			unk04;						// 04
		UInt8			unk08;						// 08
		UInt8			pad09[7];					// 09
		UInt64			unk10;						// 10
		MorphDatabase	morphDatabase;				// 18
		UInt8			isReset;					// 58
		UInt8			pad59[3];					// 59
		UInt32			unk5C;						// 5C
		UInt8			unk60;						// 60
		UInt8			pad61[7];					// 61
	};
	static_assert(offsetof(FaceGen, isReset) == 0x58);
};
