#pragma once

#include "RE/OwnedController.h"

namespace RE
{
	class OwnedCameraEffectController : public OwnedController
	{
	public:
		inline static const void* RTTI = RTTI_OwnedCameraEffectController;


		virtual ~OwnedCameraEffectController();	// 00

		// override (OwnedController)
		virtual void	Unk_16(void) override;				// 16
		virtual void	Unk_1A(void) override;				// 1A
		virtual void	Unk_1B(void) override;				// 1B
		virtual void	Unk_21(void) override;				// 21
		virtual void	Unk_22(void) override;				// 22


		// members   
		UInt8			facingRotation;						//030

	};
	STATIC_ASSERT(sizeof(OwnedCameraEffectController) == 0x38);
	static_assert(offsetof(OwnedCameraEffectController, facingRotation) == 0x30);
}