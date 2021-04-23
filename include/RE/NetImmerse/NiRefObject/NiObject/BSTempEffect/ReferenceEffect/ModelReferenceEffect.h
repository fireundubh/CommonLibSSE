#pragma once

#include "RE/Animation/IAnimationGraphManagerHolder/SimpleAnimationGraphManagerHolder/SimpleAnimationGraphManagerHolder.h"
#include "RE/BSCore/BSFixedString.h"
#include "RE/BSCore/BSTEvent.h"
#include "RE/BSCore/BSTSmartPointer.h"
#include "RE/NetImmerse/Components/AttachTechniqueInput/RefAttachTechniqueInput.h"
#include "RE/NetImmerse/NiRefObject/NiObject/BSTempEffect/ReferenceEffect/ReferenceEffect.h"
#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class BGSArtObject;
	class NiAVObject;
	struct BSAnimationGraphEvent;
	class BGSArtObjectCloneTask;


	class ModelReferenceEffect :
		public ReferenceEffect,						// 00
		public SimpleAnimationGraphManagerHolder,	// 48
		public BSTEventSink<BSAnimationGraphEvent>	// 60
	{
	public:
		inline static constexpr auto RTTI = RTTI_ModelReferenceEffect;
		inline static constexpr auto Ni_RTTI = NiRTTI_ModelReferenceEffect;

		enum class Flags
		{
			kNone = 0,
			kAttached = 1 << 0,
			k3rdPersonVisible = 1 << 1
		};


		virtual ~ModelReferenceEffect();  // 00

		// override (ReferenceEffect)
		virtual const NiRTTI*	 GetRTTI() const override;								 // 02
		virtual bool			 Update(float a_arg1) override;							 // 28
		virtual NiAVObject*		 Get3D() const override;								 // 29 - { return unkC8; }
		virtual TEMP_EFFECT_TYPE GetType() const override;								 // 2C - { return 9; }
		virtual void			 SaveGame(BGSSaveGameBuffer* a_buf) override;			 // 2D
		virtual void			 LoadGame(BGSLoadGameBuffer* a_buf) override;			 // 2E
		virtual void			 Unk_36(void) override;									 // 36
		virtual void			 UpdateCellDynamicNode(BGSArtObject* a_model) override;	 // 3A
		virtual void			 UpdatePosition() override;								 // 3B
		virtual NiAVObject*		 GetAttachRoot() override;								 // 3C
		virtual bool			 IsModelAttached() override;							 // 3D - { return unkD0 & 1; }
		virtual void			 Clear() override;										 // 3E


		// members
		RefAttachTechniqueInput				   hitEffectArtData;  // 68
		std::uint64_t						   unkB0;			  // B0
		BGSArtObject*						   artObject;		  // B8
		BSTSmartPointer<BGSArtObjectCloneTask> cloneTask;		  // C0
		NiPointer<NiAVObject>				   artObject3D;		  // C8
		stl::enumeration<Flags, std::uint32_t> flags;			  // D0
		std::uint32_t						   padD4;			  // D4
	};
	static_assert(sizeof(ModelReferenceEffect) == 0xD8);
}
