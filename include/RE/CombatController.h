#pragma once

#include "RE/NiPoint3.h"
#include "RE/BSPointerHandle.h"
#include "RE/CombatGroup.h"
#include "RE/CombatTargetSelectorStandard.h"
#include "RE/CombatAreaStandard.h"
#include "RE/CombatControllerData08.h"
#include "RE/TESCombatStyle.h"


namespace RE
{
    class CombatController
    {
    public:

        typedef CombatControllerData08 Data08;

        struct Data10
        {

        };

        struct Data18
        {

        };

        struct Data20
        {

        };


        // members
        CombatGroup*                            combatGroup;            // 00
        Data08*                                 data08;                 // 08
        Data10*                                 data10;                 // 10    
        Data18*                                 data18;                 // 18
        Data20*                                 data20;                 // 20
        ActorHandle                             actorHandle;            // 28
        ActorHandle                             currentTarget;          // 2C
        ActorHandle                             target;                 // 30
        UInt8                                   unk34;                  // 34
        UInt8                                   unk35;                  // 34
        UInt8                                   unk36;                  // 36
        UInt8                                   unk37;                  // 37
        TESCombatStyle*                         combatStyle;            // 38
        bool                                    combatStopped;          // 40
        bool                                    unk41;                  // 41
        bool                                    ignoringCombat;         // 42
        bool                                    unk43;                  // 43
        AITimer                                 unk44;                  // 44
        float                                   unk4C;                  // 4C
        BSTArray<void*>                         unk50;                  // 50
        UInt64                                  unk68;                  // 68
        UInt64                                  unk70;                  // 70
        BSTArray<CombatAreaStandard*>           areas;                  // 78
        CombatAreaStandard*                     currentArea;            // 90
        BSTArray<CombatTargetSelectorStandard*> targetSelectors;        // 98
        CombatTargetSelectorStandard*           currentTargetSelector;  // B0
        UInt64                                  unkB8;                  // B8
        UInt32                                  unkC0;                  // C0
        SInt32                                  unkC4;                  // C4
        UInt64                                  unkC8;                  // C8
        UInt64                                  unkD0;                  // D0

    };
    STATIC_ASSERT(sizeof(CombatController) == 0xD8);
}

