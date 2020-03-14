#pragma once

#include "RE/ReferenceEffectController.h"
#include "RE/TESEffectShader.h"


namespace RE
{
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
		RefHandle		 refHandle;		   // 08
		UInt32			 pad0C;			   // 0C
		TESEffectShader* effectShader;	   // 10
		BGSArtObject*	 artObject;		   // 18
		RefHandle		 facingRefHandle;  // 20
		UInt32			 pad024;		   // 24
		UInt64			 unk28;			   // 28
	};
	STATIC_ASSERT(sizeof(OwnedController) == 0x30);
}