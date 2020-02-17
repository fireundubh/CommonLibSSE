#pragma once

#include "RE/NiPoint3.h"
#include "RE/BSPointerHandle.h"
#include "RE/CombatGroupDetectionListener.h"

namespace RE
{
    class BSPathingLOSGridMap;
    
    class CombatGroup
	{
	public:

        struct TargetData
        {
            ActorHandle target;         // 00
            SInt32      detectLevel;    // 04 | -1000 
            float       stealthPoints;  // 08 | fCombatStealthPointMax - 1.0
            UInt32      unk0C;          // 0C
            NiPoint3    unk10;          // 10
            UInt64      unk20;          // 20
            NiPoint3    unk28;          // 28
            UInt64      unk38;          // 38
            NiPoint3    unk40;          // 40
            UInt64      unk50;          // 50
            NiPoint3    unk58;          // 58
            UInt64      unk68;          // 68
            NiPoint3    unk70;          // 70
            UInt64      unk80;          // 80
            float       unk88;          // 88
            float       unk8C;          // 8C
            float       unk90;          // 9C
            float       unk94;          // 94
            float       unk98;          // 98
            float       unk9C;          // 9C
            ActorHandle unkA0;          // A0
            UInt16      unkA4;          // A4 | target count
            UInt8       unkA6;          // A6 | flags
            UInt8       unkA7;          // A7
        };
        STATIC_ASSERT(sizeof(TargetData) == 0xA8);


        struct MemberData
        {
            ActorHandle member; // 00
            float       unk04;  // 04
            float       unk08;  // 08
        };
        STATIC_ASSERT(sizeof(MemberData) == 0x0C);
        
        
        struct Data120
        {
            NiPoint3    unk00;  // 00
            UInt32      unk04;  // 04
            TESForm*    unk10;  // 10
            float       unk18;  // 18
            float       unk20;  // 1C
        };	
        STATIC_ASSERT(sizeof(Data120) == 0x20);
        

        virtual ~CombatGroup();	                                // 00

		// members
        UInt16                          index;                  // 000
        UInt32                          groupCount;             // 004
        BSTArray<TargetData>            targets;                // 008
        BSTArray<MemberData>            members;                // 020
        CombatGroupDetectionListener*   detectionListener;      // 038
        UInt64                          unk40;                  // 040
        UInt64                          unk48;                  // 048
        UInt64                          unk50;                  // 050
        UInt64                          unk58[11];              // 058
        float                           timer;                  // 0B0
        float                           unkB4;                  // 0B4
        UInt64                          unkB8;                  // 0B8
        UInt64                          unkC0;                  // 0C0
        float                           unkC8;                  // 0C8
        float                           unkCC;                  // 0CC
        float                           unkD0;                  // 0D0
        float                           unkD4;                  // 0D4
        UInt32                          unkD8;                  // 0D8
        UInt32                          unkDC;                  // 0DC
        BSPathingLOSGridMap*            unkE0;                  // 0E0
        UInt64                          unkE8;                  // 0E8
        UInt64                          unkF0;                  // 0F0
        float                           unkF8;                  // 0F8
        ActorHandle                     unkFC;                  // 0FC
        NiPoint3                        unk100;                 // 100
        UInt32                          unk10C;                 // 10C
        UInt64                          unk110;                 // 110
        UInt32                          unk118;                 // 118
        UInt32                          unk11C;                 // 11C
        BSTArray<Data120>               unk120;                 // 120
        BSTArray<void*>                 unk138;                 // 138
        UInt32                          unk150;                 // 150
        UInt32                          unk154;                 // 154
        UInt32                          unk158;                 // 158
        UInt8                           unk15C;                 // 15C
        UInt8                           unk15D;                 // 15D
        UInt8                           unk15E;                 // 15E
        UInt8                           unk15F;                 // 15F
        BSReadWriteLock                 unk160;                 // 160

	};
    static_assert(offsetof(CombatGroup, unk160) == 0x160);
    STATIC_ASSERT(sizeof(CombatGroup) == 0x168);
}