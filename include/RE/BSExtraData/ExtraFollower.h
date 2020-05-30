#pragma once

#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSCore/BSPointerHandle.h"
#include "RE/BSCore/BSTArray.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class ExtraFollower : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraFollower;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kFollower;


		struct FollowerInfo
		{
			ActorHandle actor;					 // 0
			float		intendedFollowDistance;	 // 4
		};
		STATIC_ASSERT(sizeof(FollowerInfo) == 0x8);


		virtual ~ExtraFollower();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kFollower; }


		// members
		BSTArray<FollowerInfo> actorFollowers;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraFollower) == 0x28);
}
