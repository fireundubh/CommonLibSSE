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

        // members
        float               unk00;          // 00
        bool                unk04;          // 04
        UInt8               unk05;          // 05
        UInt8               unk06;          // 06
        UInt8               unk07;          // 07
        UInt8               unk08;          // 08
        UInt8               unk09;          // 09
        UInt8               unk0A;          // 0A
        UInt8               unk0B;          // 0B
        UInt32              unk0C;          // 0C
        NiPoint3            unk10;          // 10
        float               unk1C;          // 1C
        float               unk20;          // 20
        float               unk24;          // 24
        float               unk28;          // 28
        float               timer2C;        // 2C
        UInt32              unk30;          // 30
        float               timer34;        // 34
        UInt32              taunt;          // 38
        float               timer3C;        // 3C
        UInt32              unk40;          // 40
        float               timer44;        // 44
        UInt32              unk48;          // 48
        UInt32              unk4C;          // 4C
        BSTArray<void*>     unk50;          // 50
        float               unk68;          // 68
        UInt8               unk6C;          // 6C
        UInt8               unk6D;          // 6D
        float               confidence;     // 70     
        float               unk74;          // 74
        float               unk78;          // 78
        UInt32              unk7C;          // 7C
        BSTArray<void*>     unk80;          // 80
        CombatController*   unk98;          // 98
        UInt8               unkA0;          // A0
        float               timerA4;        // A4
        UInt32              unkA8;          // A8
        float               timerAC;        // AC
        UInt32              unkB0;          // B0
        float               timerB4;        // B4
        float               unkB8;          // B8

    };
    STATIC_ASSERT(sizeof(CombatControllerData08) == 0xC0);
}