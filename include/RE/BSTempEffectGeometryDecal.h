#pragma once

#include "RE/BSTempEffect.h"

class BSGeometry;
class NiAVObject;

namespace RE
{
	class BSTempEffectGeometryDecal : public BSTempEffect
	{
	public:
		inline static const void* RTTI = RTTI_BSTempEffectGeometryDecal;
		inline static const void* Ni_RTTI = NiRTTI_BSTempEffectGeometryDecal;

		virtual ~BSTempEffectGeometryDecal();			                // 00

        virtual const NiRTTI*   GetRTTI() const override;	            // 02
        virtual void			Unk_25(void) override;	                // 25 
        virtual void			Unk_26(void) override;		            // 26
        virtual void	        Unk_28(void) override;                  // 28
        virtual void			Unk_29(void) override;	                // 29
        virtual void	        Unk_2C(void) override;				    // 2C - { return 3; }

		// members
        BSGeometry* decal;
        BSGeometry* attachedGeometry;   // 038
        NiAVObject* unk40;              
        NiNode*     decalNode;
        UInt64      queuedTempEffect;   // 050
        UInt64      unk58;
        UInt64      unk60;
        UInt32      unk68;
        UInt32      unk6C;
        UInt32      unk70;
        UInt32      unk74;
        UInt32      unk78;
        UInt32      unk7C;
        UInt32      unk80;
        UInt32      unk84;
        UInt32      unk88;
        UInt32      unk8C;
        UInt32      unk90;
        UInt32      unk94;
        UInt32      unk98;
        UInt32      unk9C;
        UInt32      unkA0;
        UInt32      unkA4;
        UInt32      unkA8;
        UInt32      unkAC;
        bool        unkB0;
	};
	STATIC_ASSERT(sizeof(BSTempEffectGeometryDecal) == 0xB8);
}