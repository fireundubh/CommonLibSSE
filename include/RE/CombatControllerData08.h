#pragma once

#include "RE/NiPoint3.h"
#include "RE/BSPointerHandle.h"
#include "RE/CombatTargetSelectorStandard.h"
#include "RE/CombatAreaStandard.h"

namespace RE
{
    class CombatController;
    
    class CombatControllerData08
    {
    public:

        struct Data80
        {
            CombatLocation    unk00;  // 10
            AITimeStamp       unk18;  // 18
            float             unk20;  // 20
        };
        STATIC_ASSERT(sizeof(Data80) == 0x20);
        

        // members
        float               unk00;                          // 00
        bool                unk04;                          // 04
        UInt8               unk05;                          // 05
        UInt8               unk06;                          // 06
        UInt8               unk07;                          // 07
        UInt8               unk08;                          // 08
        UInt8               unk09;                          // 09
        UInt8               unk0A;                          // 0A
        UInt8               unk0B;                          // 0B
        UInt32              unk0C;                          // 0C
        NiPoint3            unk10;                          // 10
        AITimeStamp         activeCombatantLastSeenTimer;   // 1C
        AITimeStamp         unk20;                          // 20
        AITimeStamp         unk24;                          // 24
        AITimeStamp         unk28;                          // 28
        AITimer             unk2C;                          // 2C
        AITimer             tauntTimer;                     // 34
        AITimer             unk3C;                          // 3C
        AITimer             unk44;                          // 44
        UInt32              unk4C;                          // 4C
        BSTArray<void*>     unk50;                          // 50
        AITimeStamp         unk68;                          // 68
        UInt8               unk6C;                          // 6C
        UInt8               unk6D;                          // 6D
        float               confidence;                     // 70     
        float               unk74;                          // 74
        float               unk78;                          // 78
        UInt32              unk7C;                          // 7C
        BSTArray<Data80>    unk80;                          // 80
        CombatController*   unk98;                          // 98
        UInt8               unkA0;                          // A0
        AITimer             unkA4;                          // A4
        AITimer             unkAC;                          // AC
        AITimer             unkB4;                          // B4

    };    
    STATIC_ASSERT(sizeof(CombatControllerData08) == 0xC0);
}