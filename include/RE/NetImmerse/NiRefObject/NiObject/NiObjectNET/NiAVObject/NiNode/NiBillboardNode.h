#pragma once

#include "RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiAVObject/NiNode/NiNode.h"


namespace RE
{
	class NiBillboardNode : public NiNode
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiBillboardNode;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiBillboardNode;


		virtual ~NiBillboardNode();	 // 00

		// override (NiNode)
		virtual const NiRTTI* GetRTTI() const override;									// 02
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;		// 17
		virtual void		  LoadBinary(NiStream& a_stream) override;					// 18
		virtual void		  LinkObject(NiStream& a_stream) override;					// 19
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;			// 1A
		virtual void		  SaveBinary(NiStream& a_stream) override;					// 1B
		virtual bool		  IsEqual(NiObject* a_object) override;						// 1C
		virtual void		  UpdateWorldBound() override;								// 2F
		virtual void		  UpdateTransformAndBounds(NiUpdateData& a_data) override;	// 31
		virtual void		  OnVisible(NiCullingProcess& a_process) override;			// 34


		// members
		std::uint16_t unk128;  // 128
		std::uint16_t pad12A;  // 12A
		std::uint32_t pad12C;  // 12C
	};
	static_assert(sizeof(NiBillboardNode) == 0x130);
}