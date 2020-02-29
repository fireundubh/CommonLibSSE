#pragma once

#include "RE/BSTempEffect.h"
#include "RE/NiPlane.h"
#include "RE/BGSTextureSet.h"
#include "RE/BSTArray.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
    class NiAVObject;


    class BSTempEffectSimpleDecal : public BSTempEffect
    {
    public:
        inline static constexpr auto RTTI = RTTI_BSTempEffectSimpleDecal;
        inline static constexpr auto Ni_RTTI = NiRTTI_BSTempEffectSimpleDecal;


        virtual ~BSTempEffectSimpleDecal();			                        // 00

        virtual const NiRTTI*       GetRTTI() const override;	            // 02
        virtual void				Initialize() override;	                // 25 
        virtual void				Attach() override;		                // 26
        virtual bool				Update(float a_arg1) override;          // 28
        virtual NiAVObject*         Get3D() const override;	                // 29


        // members
        UInt8                   unk30;              // 030
        UInt8                   unk31;              // 031
        UInt16                  unk32;              // 032
        UInt16                  unk36;              // 036
        UInt64                  unk38;              // 038
        UInt32                  unk40;              // 040
        UInt32                  unk44;              // 040
        NiPointer<BSGeometry>   effectGeometry;     // 048
        UInt32                  unk50;              // 050
        UInt8                   isPermanentDecal;   // 054
        UInt8                   unk55;              // 055
        UInt8                   unk56;              // 056
        UInt8                   unk57;              // 057
        BGSTextureSet*          textureSet;         // 058
        BGSTextureSet*          textureSet2;        // 060
        NiPoint3                origin;             // 068  
        NiPoint3                direction;          // 074
        NiPoint3                surfaceNormal;      // 080
        NiPoint3                unk8C;              // 08C
        NiPlane                 planes[6];          // 098
        UInt64                  unkF8;              // 0F8
        UInt64                  unk100;             // 100
        UInt64                  unk108;             // 108
        UInt64                  unk110;             // 110
        UInt64                  unk118;             // 118
        UInt64                  unk120;             // 120
        UInt64                  unk128;             // 128
        UInt64                  unk130;             // 130
        UInt64                  unk138;             // 138
        UInt64                  unk140;             // 140
        UInt64                  unk148;             // 148
        UInt64                  unk150;             // 150
        BSTArray<void*>         unk158;             // 158
        NiPointer<NiAVObject>   decalNode;          // 170
        NiPointer<NiAVObject>   avObject;           // 178
        float                   unk180;             // 180
        float                   unk184;             // 184
        UInt64                  unk188;             // 188
        UInt32                  unk190;             // 190
        float                   unk194;             // 194
        UInt64                  unk198;             // 198
        UInt32                  unk1A0;             // 1A0
        float                   unk1A4;             // 1A4
        UInt32                  unk1A8;             // 1A8
        UInt32                  unk1AC;             // 1AC
        UInt32                  unk1B0;             // 1B0
        UInt32                  unk1B4;             // 1B4
        UInt8                   unk1B8;             // 1B8
        UInt8                   hasParallaxOcc;     // 1B9
        UInt8                   unk1BA;             // 1BA
        UInt8                   unk1BB;             // 1BB
        UInt8                   unk1BC;             // 1BC
        UInt8                   unk1BD;             // 1BD
        UInt8                   unk1BE;             // 1BE
        UInt8                   unk1BF;             // 1BF
        UInt8                   unk1C0;             // 1C0
        UInt8                   enableTesting;      // 1C1
        UInt8                   enableBlending;     // 1C2
        float                   specularPower;      // 1C3
        UInt64                  unk1C8;             // 1C4
        UInt32                  unk1D0;             // 1D0
        UInt8                   unk1D4;             // 1D4
        UInt8                   isTwoSided;         // 1D5
        UInt8                   unk1D6;             // 1D6
        UInt8                   unk1D7;             // 1D7
        UInt32                  unk1D8;             // 1D8
        UInt32                  unk1DC;             // 1DC
    };
    STATIC_ASSERT(sizeof(BSTempEffectSimpleDecal) == 0x1E0);
};