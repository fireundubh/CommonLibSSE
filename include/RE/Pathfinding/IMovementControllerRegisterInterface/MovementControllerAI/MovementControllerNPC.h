#pragma once

#include "RE/Animation/IAnimationSetCallbackFunctor.h"
#include "RE/BSCore/BSTArray.h"
#include "RE/Pathfinding/IMovementControllerRegisterInterface/MovementControllerAI/MovementControllerAI.h"
#include "RE/Pathfinding/IMovementInterface/IMovementDirectControl.h"
#include "RE/Pathfinding/IMovementInterface/IMovementMessageInterface.h"
#include "RE/Pathfinding/IMovementInterface/IMovementMotionDrivenControl.h"
#include "RE/Pathfinding/IMovementInterface/IMovementPlannerDirectControl.h"
#include "RE/Pathfinding/IMovementInterface/IMovementSelectIdle.h"


namespace RE
{
	class Actor;
	class MovementMessagePlayIdle;


	class MovementControllerNPC :
		public MovementControllerAI,		   // 000
		public IMovementMessageInterface,	   // 120
		public IMovementMotionDrivenControl,   // 128
		public IMovementSelectIdle,			   // 130
		public IMovementDirectControl,		   // 138
		public IMovementPlannerDirectControl,  // 140
		public IAnimationSetCallbackFunctor	   // 148
	{
	public:
		inline static constexpr auto RTTI = RTTI_MovementControllerNPC;


		virtual ~MovementControllerNPC();  // 00

		// add
		virtual void Unk_0A(void);			 // 0A
		virtual void Unk_0B(void);			 // 0B
		virtual void UnsetPlayerControls();	 // 0C
		virtual void SetPlayerControls();	 // 0D
		virtual void Unk_0E(void);			 // 0E - { return unk1C5 == 0; }
		virtual bool GetPlayerControls();	 // 0F - { return unk1C5; }
		virtual void Unk_10(void);			 // 10
		virtual void Unk_11(void);			 // 11
		virtual void Unk_12(void);			 // 12
		virtual void Unk_13(void);			 // 13
		virtual void Unk_14(void);			 // 14


		// members
		UInt64									 unk150;			// 150
		BSTArray<void*>							 unk158;			// 158
		BSTArray<void*>							 unk170;			// 170
		BSTArray<void*>							 unk188;			// 188
		BSSpinLock								 unk1A0;			// 1A0
		UInt64									 unk1A8;			// 1A8
		BSTSmartPointer<MovementMessagePlayIdle> unk1B0;			// 1B0
		Actor*									 unk1B8;			// 1B8
		UInt32									 unk1C0;			// 1C0
		UInt8									 unk1C4;			// 1C4
		bool									 playerControlled;	// 1C5
		UInt16									 unk1C6;			// 1C6
		UInt64									 unk1C8;			// 1C8
	};
	STATIC_ASSERT(sizeof(MovementControllerNPC) == 0x1D0);
}
