#pragma once


namespace RE
{
    struct AITimer
    {
        float   aiTimer;    // 00
        float   timer;      // 04
    };
    STATIC_ASSERT(sizeof(AITimer) == 0x08);
}
