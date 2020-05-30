#pragma once

#include "RE/BSCore/BSFixedString.h"


namespace RE
{
	namespace Movement
	{
		enum class DIRECTION : UInt32
		{
			kInvalid = static_cast<UInt32>(-1),
			kStanding = 0,
			kDiagonallyForwardRight,
			kRight,
			kDiagonallyRight,
			kBack,
			kDiagonallyLeft,
			kLeft,
			kFront
		};


		struct SPEED_DIRECTIONS
		{
			enum SPEED_DIRECTION : UInt32
			{
				kLeft,
				kRight,
				kForward,
				kBack,
				kRotations,

				kTotal
			};
		};
		using SPEED_DIRECTION = SPEED_DIRECTIONS::SPEED_DIRECTION;


		struct MaxSpeeds
		{
		public:
			enum
			{
				kWalk,
				kRun,

				kTotal
			};


			// members
			float speeds[SPEED_DIRECTIONS::kTotal][kTotal];	 // 00
			float rotateWhileMovingRun;						 // 28
		};
		STATIC_ASSERT(sizeof(MaxSpeeds) == 0x2C);


		struct TypeData
		{
		public:
			// members
			BSFixedString typeName;		  // 00 - MNAM
			MaxSpeeds	  defaultData;	  // 08 - SPED
			float		  directional;	  // 34 - INAM~
			float		  movementSpeed;  // 38
			float		  rotationSpeed;  // 3C - ~INAM
		};
		STATIC_ASSERT(sizeof(TypeData) == 0x40);
	}
}
