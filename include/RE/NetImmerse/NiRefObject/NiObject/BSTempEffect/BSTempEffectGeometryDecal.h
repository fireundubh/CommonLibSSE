#pragma once

#include "RE/BSTSmartPointer.h"
#include "RE/BSTempEffect.h"
#include "RE/NiMatrix3.h"
#include "RE/NiPoint3.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class BSTriShape;
	class NiAVObject;
	class BGSTextureSet;
	class QueuedTempEffect;


	class BSTempEffectGeometryDecal : public BSTempEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSTempEffectGeometryDecal;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSTempEffectGeometryDecal;


		virtual ~BSTempEffectGeometryDecal();  // 00

		virtual const NiRTTI*	 GetRTTI() const override;		 // 02
		virtual void			 Initialize() override;			 // 25
		virtual void			 Attach() override;				 // 26
		virtual bool			 Update(float a_arg1) override;	 // 28
		virtual NiAVObject*		 Get3D() const override;		 // 29
		virtual TEMP_EFFECT_TYPE GetType() const override;		 // 2C - { return kGeometryDecal; }


		// members
		NiPointer<BSGeometry>			  skinnedDecal;			// 30
		NiPointer<BSTriShape>			  attachedShape;		// 38
		NiPointer<NiNode>				  attachedShapeParent;	// 40
		NiPointer<NiNode>				  skinnedDecalNode;		// 48
		BSTSmartPointer<QueuedTempEffect> queuedEffect;			// 50
		BGSTextureSet*					  texSet;				// 58
		BGSTextureSet*					  texSet2;				// 60
		NiMatrix3						  rotation;				// 68
		NiPoint3						  origin;				// 8C
		NiPoint3						  direction;			// 98
		float							  width;				// A4
		UInt32							  unkA8;				// A8
		UInt32							  flags;				// AC
		bool							  unkB0;				// B0
	};
	STATIC_ASSERT(sizeof(BSTempEffectGeometryDecal) == 0xB8);
}