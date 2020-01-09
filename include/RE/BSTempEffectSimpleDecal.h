#pragma once

#include "RE/BSTempEffect.h"
#include "RE/NiPlane.h"
#include "RE/BGSTextureSet.h"
#include "RE/BSTArray.h"

class NiAVObject;

namespace RE
{
    class BSTempEffectSimpleDecal : public BSTempEffect
    {
    public:
        inline static const void* RTTI = RTTI_BSTempEffectSimpleDecal;
        inline static const void* Ni_RTTI = NiRTTI_BSTempEffectSimpleDecal;

        virtual ~BSTempEffectSimpleDecal();			                    // 00

        virtual const NiRTTI*   GetRTTI() const override;	            // 02
        virtual void			Unk_25(void) override;	                // 25 
        virtual void			Unk_26(void) override;		            // 26
        virtual void	        Unk_28(void) override;                  // 28
        virtual void			Unk_29(void) override;	                // 29

        // members
        UInt8           unk30;          // 030
        UInt8           unk31;          // 031
        UInt16          unk32;          // 032
        UInt16          unk36;
        UInt64          unk38;
        UInt32          unk40;
        UInt32          unk44;;
        NiAVObject* effectObject;   // 048
        UInt32          unk50;
        UInt8           unk54;
        UInt8           unk55;
        UInt8           unk56;
        UInt8           unk57;
        BGSTextureSet* textureSet;
        BGSTextureSet* textureSet2;
        NiPoint3        origin;
        NiPoint3        direction;
        NiPoint3        surfaceNormal;
        NiPoint3        unk8C;
        NiPlane         planes[6];
        UInt64          unkF8;
        UInt64          unk100;
        UInt64          unk108;
        UInt64          unk110;
        UInt64          unk118;
        UInt64          unk120;
        UInt64          unk128;
        UInt64          unk130;
        UInt64          unk138;
        UInt64          unk140;
        UInt64          unk148;
        UInt64          unk150;
        BSTArray<void*> unk158;
        NiAVObject* decalNode;      // 0170
        NiAVObject* avObject;       // 0178
        float           unk180;
        float           unk184;
        UInt64          unk188;
        UInt32          unk190;
        float           unk194;
        UInt64          unk198;
        UInt32          unk1A0;
        float           unk1A4;
        UInt32          unk1A8;
        UInt32          unk1AC;
        UInt32          unk1B0;
        UInt32          unk1B4;
        UInt32          unk1BC;
        UInt8           unk1C0;
        UInt8           unk1C1;
        UInt8           unk1C2;
        UInt8           unk1C3;
        UInt32          unk1C4;
        UInt64          unk1C8;
        UInt32          unk1D0;
        UInt8           unk1D4;
        UInt8           unk1D5;
        UInt8           unk1D6;
        UInt8           unk1D7;
        UInt32          unk1D8;
    };
    STATIC_ASSERT(sizeof(BSTempEffectSimpleDecal) == 0x1E0);
};