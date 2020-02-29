#pragma once

#include "RE/OwnedController.h"


namespace RE
{
	class OwnedCameraEffectController : public OwnedController
	{
	public:
		inline static constexpr auto RTTI = RTTI_OwnedCameraEffectController;


		virtual ~OwnedCameraEffectController();	// 00

		// override (OwnedController)
		virtual bool	GetClearWhenCellIsUnloaded() override;			// 16
		virtual bool	EffectAttachesToCamera() override;				// 1A
		virtual bool	EffectRotatesWithCamera() override;				// 1B - { return false; }
		virtual void	SaveGame(BGSSaveGameBuffer* a_buf) override;	// 21 - { return; }
		virtual void	LoadGame(BGSLoadGameBuffer* a_buf) override;	// 22 - { return; }


		// members   
		UInt8	facingRotation;	// 30

	};
	STATIC_ASSERT(sizeof(OwnedCameraEffectController) == 0x38);
}