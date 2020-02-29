#pragma once

#include "RE/BSNiNode.h"


namespace RE
{
	class BSValueNode : public BSNiNode
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSValueNode;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSValueNode;


		virtual ~BSValueNode();														// 00

		// override (NiNode)
		virtual const NiRTTI*	GetRTTI() const override;							// 02
		virtual NiObject*		CreateClone(NiCloningProcess& a_cloning) override;	// 17


		// members
		UInt8	flags;	// 128
		UInt32	value;	// 12C
		UInt64	unk130;	// 130
	};
	STATIC_ASSERT(sizeof(BSValueNode) == 0x138);
}
