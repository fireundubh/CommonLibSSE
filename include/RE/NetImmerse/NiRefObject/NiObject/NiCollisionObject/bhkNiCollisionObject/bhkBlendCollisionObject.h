#pragma once

#include "RE/NetImmerse/NiRefObject/NiObject/NiCollisionObject/bhkNiCollisionObject/bhkCollisionObject.h"


namespace RE
{
	class bhkBlendCollisionObject : public bhkCollisionObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkBlendCollisionObject;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkBlendCollisionObject;


		virtual ~bhkBlendCollisionObject();	 // 00

		// override (bhkNiCollisionObject)
		virtual const NiRTTI* GetRTTI() const override;							  // 02
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;  // 17
		virtual void		  LoadBinary(NiStream& a_stream) override;			  // 18 - { bhkNiCollisionObject::LoadBinary(a_stream); }
		virtual void		  LinkObject(NiStream& a_stream) override;			  // 19 - { bhkNiCollisionObject::LinkObject(a_stream); }
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	  // 1A - { return bhkNiCollisionObject::RegisterStreamables(a_stream); }
		virtual void		  SaveBinary(NiStream& a_stream) override;			  // 1B - { bhkNiCollisionObject::SaveBinary(a_stream); }
		virtual void		  Unk_26(void) override;							  // 26
		virtual void		  Unk_2A(void) override;							  // 2A
		virtual void		  Unk_2B(void) override;							  // 2B
		virtual void		  Unk_2C(void) override;							  // 2C
		virtual void		  Unk_2D(void) override;							  // 2D
		virtual void		  Unk_2E(void) override;							  // 2E
		virtual void		  Unk_2F(void) override;							  // 2F


		// members
		float		  heirGain;	 // 24
		float		  velGain;	 // 28
		std::uint32_t unk30;	 // 30
		std::uint32_t pad34;	 // 34
		std::uint64_t unk38;	 // 38
		std::uint32_t unk40;	 // 40
	};
	static_assert(sizeof(bhkBlendCollisionObject) == 0x48);
}