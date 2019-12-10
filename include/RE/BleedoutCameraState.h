#pragma once

#include "RE/NiPoint3.h"  // NiPoint3
#include "RE/ThirdPersonState.h" // ThuirdPersonState
#include "RE/TESCameraState.h"  // TESCameraState
#include "RE/PlayerInputHandler.h"  // PlayerInputHandler


namespace RE
{
	class NiNode;


	class BleedoutCameraState : public ThirdPersonState
	{
	public:
		virtual ~BleedoutCameraState();

		// override (ThirdPersonState)
		virtual void	SetCameraHandle(RefHandle& a_handle) override;								// 09 - { return; }
		virtual void	Unk_0A(void) override;														// 0A - { return; }
		virtual void	UpdatePosOffset(bool a_weaponDrawn) override;								// 0B
		virtual bool	IsInCustomMode() override;													// 0C
		virtual void	ProcessCameraAngle(bool a_weaponSheathed) override;							// 0D
		virtual void	Unk_0E(void) override;														// 0E
		virtual void	ProcessIdleCameraRot(NiPoint2* a_rot) override;								// 0F

		// override (TESCameraState)
		virtual void	OnStateStart() override;													// 01
		virtual void	OnStateEnd() override;														// 02
		virtual void	OnUpdate(BSTSmartPointer<TESCameraState>& a_newState) override;				// 03
		virtual void	GetRotation(NiQuaternion* a_rot) override;									// 04
		virtual void	GetPosition(NiPoint3* a_pos) override;										// 05
		virtual void	Unk_06(void) override;														// 06
		virtual void	LoadCameraState(BGSLoadGameBuffer* a_buf) override;							// 07
		virtual void	Unk_08(void) override;														// 08

		// override (PlayerInputHandler)
		virtual	bool	CanProcess(InputEvent* a_event) override;									// 01
		virtual	void	ProcessButton(ButtonEvent* a_event, MovementData* a_movementData) override;	// 04

		// members
		float	unkE8[8];	// E8
		UInt32	unk108;		// 108
		float	unk10C;		// 10C - init'd to 200
		float	unk110;		// 110 - init'd to 0.523599 (PI/6)
		UInt32	unk114;		// 114
		float	unk118;		// 118
		UInt32	pad11C;		// 11C
		UInt64	unk120;		// 120
		UInt32	unk128;		// 128 - init'd to FFFFFFFF
		UInt8	unk12C;		// 12C
		UInt8	pad12D[3];	// 12D
		UInt32	unk130;		// 130
		UInt8	unk134;		// 134
		UInt8	pad135[3];	// 135
	};
}
