#pragma once

#include "RE/BSCore/BSPointerHandle.h"
#include "RE/BSCore/BSTArray.h"
#include "RE/NetImmerse/NiColor.h"
#include "RE/NetImmerse/NiMatrix3.h"
#include "RE/NetImmerse/NiPoint3.h"
#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class BGSTextureSet;
	class NiAVObject;
	class NiNode;
	class TESObjectCELL;


	struct DECAL_CREATION_DATA
	{
	public:
		// members
		NiPoint3			  origin;			// 00
		NiPoint3			  direction;		// 0C
		NiPoint3			  surfaceNormal;	// 18
		ObjectRefHandle		  objRef;			// 24
		NiPointer<NiAVObject> avObj;			// 28
		NiNode*				  clone;			// 30
		BGSTextureSet*		  texSet;			// 38
		BGSTextureSet*		  texSet2;			// 40
		SInt32				  unk48;			// 48; -1 for actors
		float				  width;			// 4C;
		float				  height;			// 50;
		float				  depth;			// 54;
		NiMatrix3			  rotation;			// 58;
		UInt32				  unk7C;			// 7C;
		TESObjectCELL*		  parentCell;		// 80
		float				  parallaxScale;	// 88;
		NiNode*				  unk90;			// 90;
		float				  shininess;		// 98;
		float				  angleThreshold;	// 9C;
		float				  placementRadius;	// A0;
		NiColor				  color;			// A4;
		UInt32				  flags;			// B0;
		SInt8				  subtextureIndex;	// B4;
		bool				  permanentDecal;	// B5;
		UInt8				  unkB6;			// B6;
		UInt8				  parallaxOcc;		// B7;
		bool				  alphaBlending;	// B8;
		bool				  enableBlending;	// B9;
		UInt8				  parallaxPasses;	// BA;
		UInt8				  unkBB;			// BB;
		UInt8				  unkBC;			// BC;
		bool				  twoSided;			// BD;
		UInt8				  unkBE;			// BE;
		UInt8				  unkBF;			// BF;
		UInt32				  unkC0;			// C0;
		UInt32				  padC4;			// C4;
	};
	static_assert(sizeof(DECAL_CREATION_DATA) == 0xC8);


	struct BGSDecalGroup
	{
	public:
		// members
		bool						   permanentGroup;	// 00
		bool						   manualSaveLoad;	// 01
		std::uint16_t				   pad02;			// 02
		std::uint32_t				   pad04;			// 04
		BSTArray<std::uint32_t>		   decalGroups;		// 08
		BSTArray<DECAL_CREATION_DATA*> pendingDecals;	// 20
	};
	static_assert(sizeof(BGSDecalGroup) == 0x38);
}
