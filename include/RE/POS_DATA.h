#pragma once

#include "RE/NiPoint3.h"
#include "RE/TESForm.h"


namespace RE
{
    struct POS_DATA
    {
        NiPoint3        pos;                // 00
        TESForm* cellOrWorldSpace;   // 0C
    };
    STATIC_ASSERT(sizeof(POS_DATA) == 0x18);
}
