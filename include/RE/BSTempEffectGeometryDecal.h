#pragma once

#include "RE/BSTempEffect.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
    class BSGeometry;
    class NiAVObject;


    class BSTempEffectGeometryDecal : public BSTempEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSTempEffectGeometryDecal;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSTempEffectGeometryDecal;


		virtual ~BSTempEffectGeometryDecal();			                    // 00

        virtual const NiRTTI*       GetRTTI() const override;	            // 02
        virtual void			    Initialize() override;	                // 25 
        virtual void			    Attach() override;		                // 26
        virtual bool			    Update(float a_arg1) override;          // 28
        virtual NiAVObject*         Get3D() const override;	                // 29
        virtual TEMP_EFFECT_TYPE    GetType() const override;				// 2C - { return kGeometryDecal; }


		// members
        NiPointer<BSGeometry>   decal;
        NiPointer<BSGeometry>   attachedGeometry;   // 038
        NiPointer<NiAVObject>   unk40;
        NiPointer<NiNode>       decalNode;
        UInt64                  queuedTempEffect;   // 050
        UInt64                  unk58;
        UInt64                  unk60;
        UInt32                  unk68;
        UInt32                  unk6C;
        UInt32                  unk70;
        UInt32                  unk74;
        UInt32                  unk78;
        UInt32                  unk7C;
        UInt32                  unk80;
        UInt32                  unk84;
        UInt32                  unk88;
        UInt32                  unk8C;
        UInt32                  unk90;
        UInt32                  unk94;
        UInt32                  unk98;
        UInt32                  unk9C;
        UInt32                  unkA0;
        UInt32                  unkA4;
        UInt32                  unkA8;
        UInt32                  unkAC;
        bool                    unkB0;
	};
	STATIC_ASSERT(sizeof(BSTempEffectGeometryDecal) == 0xB8);
}