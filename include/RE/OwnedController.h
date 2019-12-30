#pragma once

#include "RE/ReferenceEffectController.h"
#include <CommonLibSSE\include\RE\TESEffectShader.h>

namespace RE
{
	class OwnedController : public ReferenceEffectController
	{
	public:
		inline static const void* RTTI = RTTI_OwnedController;


		virtual ~OwnedController();	// 00

		// override (ReferenceEffectController)
		virtual void	Unk_0B(void) override;				// 0B
		virtual void	Unk_0C(void) override;				// 0C
		virtual void	Unk_0D(void) override;				// 0D
		virtual void	Unk_0E(void) override;				// 0E - { return 0; }
		virtual void	Unk_0F(void) override;				// 0F
		virtual void	Unk_17(void) override;				// 17
		virtual void	Unk_18(void) override;				// 18
		virtual void	Unk_21(void) override;				// 21
		virtual void	Unk_22(void) override;				// 22


		// members   
		RefHandle			refHandle;				// 08
		UInt32				pad0C;					// 0C
		TESEffectShader*	effectShader;			// 10
		BGSArtObject*		artObject;				// 18
		RefHandle			facingRefHandle;		// 20
		UInt32				pad024;					// 24
		UInt64				unk28;					// 28
	};
	STATIC_ASSERT(sizeof(OwnedController) == 0x30);
}