#pragma once

#include "RE/BGSTextureSet.h"
#include "RE/BSTArray.h"
#include "RE/BSTempEffect.h"
#include "RE/NiColor.h"
#include "RE/NiFrustumPlanes.h"
#include "RE/NiMatrix3.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class NiAVObject;


	class BSTempEffectSimpleDecal : public BSTempEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSTempEffectSimpleDecal;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSTempEffectSimpleDecal;


		virtual ~BSTempEffectSimpleDecal();	 // 00

		virtual const NiRTTI* GetRTTI() const override;		  // 02
		virtual void		  Initialize() override;		  // 25
		virtual void		  Attach() override;			  // 26
		virtual bool		  Update(float a_arg1) override;  // 28
		virtual NiAVObject*	  Get3D() const override;		  // 29


		// members
		UInt8					unk30;			  // 030
		UInt8					unk31;			  // 031
		UInt8					unk32;			  // 032
		UInt16					unk36;			  // 036
		UInt64					unk38;			  // 038
		UInt32					unk40;			  // 040
		UInt32					unk44;			  // 044
		NiPointer<BSGeometry>	effectObject;	  // 048
		UInt32					unk50;			  // 050
		bool					permanentDecal;	  // 054;
		UInt8					unk55;			  // 055
		UInt8					unk56;			  // 056
		UInt8					unk57;			  // 057
		BGSTextureSet*			textureSet;		  // 058
		BGSTextureSet*			textureSet2;	  // 060
		NiPoint3				origin;			  // 068
		NiPoint3				direction;		  // 074
		NiPoint3				surfaceNormal;	  // 080
		NiPoint3				unk8C;			  // 08C
		NiFrustumPlanes			planes;			  // 098
		UInt64					unk108;			  // 108
		UInt64					unk110;			  // 110
		UInt64					unk118;			  // 118
		UInt64					unk120;			  // 120
		UInt64					unk128;			  // 128
		UInt64					unk130;			  // 130
		UInt64					unk138;			  // 138
		UInt64					unk140;			  // 140
		UInt64					unk148;			  // 148
		UInt64					unk150;			  // 150
		BSTArray<void*>			unk158;			  // 158
		NiPointer<BGSDecalNode> decalNode;		  // 170
		NiPointer<NiAVObject>	avObject;		  // 178
		float					unk180;			  // 180
		NiMatrix3				emitterRotation;  // 184
		UInt32					unk1A8;			  // 1A8
		float					width;			  // 1AC
		float					height;			  // 1B0
		float					depth;			  // 1B4;
		UInt8					subTextureIndex;  // 1B8
		UInt8					parallaxOcc;	  // 1B9
		UInt8					unk1BA;			  // 1BA
		UInt8					unk1BB;			  // 1BB
		float					parallaxScale;	  // 1BC
		UInt8					parallaxPasses;	  // 1C0
		UInt8					alphaBlending;	  // 1C1
		UInt8					enableBlending;	  // 1C2
		UInt8					unk1C3;			  // 1C3
		float					shininess;		  // 1C4
		NiColor					color;			  // 1C8
		UInt8					unk1D4;			  // 1D4
		UInt8					twoSided;		  // 1D5
		UInt8					unk1D6;			  // 1D6
		UInt8					unk1D7;			  // 1D7
		UInt32					unk1D8;			  // 1D8
		UInt32					unk1DC;			  // 1DC
	};
	STATIC_ASSERT(sizeof(BSTempEffectSimpleDecal) == 0x1E0);
};