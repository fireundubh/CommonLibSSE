#pragma once

#include "RE/BSCore/BSPointerHandle.h"
#include "RE/FormComponents/Components/ReferenceEffectController/ReferenceEffectController.h"
#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class NiAVObject;
	class TESEffectShader;


	class OwnedController : public ReferenceEffectController
	{
	public:
		inline static constexpr auto RTTI = RTTI_OwnedController;


		virtual ~OwnedController();	 // 00

		// override (ReferenceEffectController)
		virtual TESObjectREFR*	 GetTargetReference() override;				   // 0B
		virtual BGSArtObject*	 GetHitEffectArt() override;				   // 0C
		virtual TESEffectShader* GetHitEffectShader() override;				   // 0D
		virtual bool			 GetManagerHandlesSaveLoad() override;		   // 0E - { return 0; }
		virtual NiAVObject*		 GetAttachRoot() override;					   // 0F
		virtual bool			 EffectShouldFaceTarget() override;			   // 17
		virtual TESObjectREFR*	 GetFacingTarget() override;				   // 18
		virtual void			 SaveGame(BGSSaveGameBuffer* a_buf) override;  // 21 - { return; }
		virtual void			 LoadGame(BGSLoadGameBuffer* a_buf) override;  // 22 - { return; }


		// members
		ObjectRefHandle	  ref;			 // 08
		std::uint32_t	  pad0C;		 // 0C
		TESEffectShader*  effectShader;	 // 10
		BGSArtObject*	  artObject;	 // 18
		ObjectRefHandle	  facingRef;	 // 20
		std::uint32_t	  pad24;		 // 24
		NiPointer<NiNode> unk28;		 // 28 - weather node?
	};
	static_assert(sizeof(OwnedController) == 0x30);
}