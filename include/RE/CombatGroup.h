#pragma once


#include "RE/AITimer.h"
#include "RE/AITimeStamp.h"
#include "RE/CombatLocation.h"
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
            ActorHandle     target;         // 00
            SInt32          detectLevel;    // 04 | -1000 
            float           stealthPoints;  // 08 | fCombatStealthPointMax - 1.0
            float           unk0C;          // 0C
            CombatLocation  unk10;          // 10
            CombatLocation  unk28;          // 28
            CombatLocation  unk40;          // 40
            CombatLocation  unk58;          // 58
            CombatLocation  unk70;          // 70
            AITimeStamp     unk88;          // 88
            AITimeStamp     unk8C;          // 8C
            AITimeStamp     unk90;          // 9C
            AITimeStamp     unk94;          // 94
            AITimeStamp     unk98;          // 98
            AITimeStamp     unk9C;          // 9C
            ActorHandle     attackedMember; // A0
            UInt16          unkA4;          // A4 | target count
            UInt16          unkA6;          // A6 | flags
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
            CombatLocation    unk00;  // 10
            AITimeStamp unk18;  // 18
            float       unk20;  // 20
        };	
        STATIC_ASSERT(sizeof(Data120) == 0x20);


        struct Data138
        {
            ObjectRefHandle unk00;  // 00
            ObjectRefHandle unk04;  // 04
            UInt8           unk08;  // 08
            UInt8           unk09;  // 09
            UInt8           unk0A;  // 0A    
        };
        STATIC_ASSERT(sizeof(Data138) == 0xC);
        

		// members
        UInt16                          index;                          // 000
        UInt32                          groupCount;                     // 004
        BSTArray<TargetData>            targets;                        // 008
        BSTArray<MemberData>            members;                        // 020
        CombatGroupDetectionListener*   detectionListener;              // 038
        AITimer                         unk40;                          // 040
        AITimer                         unk48;                          // 048
        AITimer                         groupStrengthUpdateTimer;       // 050
        AITimer                         dialogues[11];                  // 058
        AITimer                         unkB0;                          // 0B0
        AITimer                         musicThreatRatioTimer;          // 0B8
        AITimer                         unkC0;                          // 0C0
        float                           unkC8;                          // 0C8
        float                           unkCC;                          // 0CC
        float                           unkD0;                          // 0D0
        float                           unkD4;                          // 0D4
        UInt32                          isSearching;                    // 0D8
        UInt32                          unkDC;                          // 0DC
        BSPathingLOSGridMap*            gridMap;                        // 0E0
        AITimer                         searchUpdateTimer;              // 0E8
        AITimer                         searchAreaUpdateTimer;          // 0F0
        AITimeStamp                     unkF8;                          // 0F8
        ActorHandle                     unkFC;                          // 0FC
        CombatLocation                  searchLocation;                 // 100
        float                           searchRadius;                   // 118
        UInt32                          unk11C;                         // 11C
        BSTArray<Data120>               unk120;                         // 120
        BSTArray<Data138>               unk138;                         // 138
        UInt32                          unk150;                         // 150
        UInt32                          unk154;                         // 154
        UInt32                          unk158;                         // 158
        UInt8                           unk15C;                         // 15C
        UInt8                           unk15D;                         // 15D
        UInt8                           unk15E;                         // 15E
        UInt8                           unk15F;                         // 15F
        BSReadWriteLock                 unk160;                         // 160

	};
    STATIC_ASSERT(sizeof(CombatGroup) == 0x168);
}