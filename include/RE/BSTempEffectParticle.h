#pragma once

#include "RE/BSTempEffect.h"
#include "RE/NiTransform.h"

class NiAVObject;

namespace RE
{
    class BSTempEffectParticle : public BSTempEffect
    {
    public:
        inline static const void* RTTI = RTTI_BSTempEffectParticle;
        inline static const void* Ni_RTTI = NiRTTI_BSTempEffectParticle;

        virtual ~BSTempEffectParticle();			                    // 00

        virtual const NiRTTI*       GetRTTI() const override;	            // 02
        virtual void			    Detach() override;		                // 27
        virtual bool			    Update(float a_arg1) override;          // 28
        virtual TEMP_EFFECT_TYPE    GetType() const override;				// 2C - { return kParticle; }

        // members
        UInt64          unk30;
        NiAVObject*     unk38;
        const char*     modelPath;
        UInt64          unk48;
        UInt64          unk50;
        UInt64          unk58;
        UInt64          unk60;
        UInt64          unk68;
        float           unk70;
        float           unk74;
        UInt64          unk78;
        float           unk80;
        UInt8           pad84[4];
        UInt64          unk88;
        NiTransform     nitransform90;
        UInt32          padC4;
        UInt64          unkC8;
        UInt32          unkD0;
        UInt8           unkD4;
        UInt8           padD5[3];
        UInt32          unkD8;
        UInt32          unkDC;
        UInt8           unkE0;
        UInt8           padE1[3];
        UInt32          unkE4;
        UInt8           unkE8;
    };
    STATIC_ASSERT(sizeof(BSTempEffectParticle) == 0xF0);
};