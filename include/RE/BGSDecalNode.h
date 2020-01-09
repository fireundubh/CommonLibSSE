#pragma once

#include "RE/NiNode.h"


namespace RE
{
	class BSTempEffectGeometryDecal;
	
	class BGSDecalNode : public NiNode
	{
	public:
		inline static const void* RTTI = RTTI_BGSDecalNode;
		inline static const void* Ni_RTTI = NiRTTI_BGSDecalNode;

		virtual ~BGSDecalNode();																						// 00

		// override (NiNode)
		virtual const NiRTTI*	GetRTTI() const override;																// 02
		virtual NiObject*		CreateClone(NiCloningProcess& a_cloning) override;										// 17
		virtual void			ProcessClone(NiCloningProcess& a_cloning) override;										// 1D
		virtual void			Unk_34(void) override;																	// 34

		//add
		virtual UInt8			Unk_3E();																				// 3E - { return 1; }
		virtual void			AttachGeometryDecal(BSTempEffectGeometryDecal* a_decal, bool a_firstAvail);				// 3F

		// members
		BSTArray<BSTempEffectGeometryDecal*>	geometryDecals;	// 128
		UInt8									unk140;			// 140
	};
	STATIC_ASSERT(sizeof(BGSDecalNode) == 0x148);
}