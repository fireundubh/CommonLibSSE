#pragma once

#include "RE/NetImmerse/NiMatrix3.h"
#include "RE/NetImmerse/NiRefObject/NiObject/BSMultiBoundShape/BSMultiBoundAABB\BSMultiBoundAABB.h"


namespace RE
{
	class BSMultiBoundOBB : public BSMultiBoundAABB
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSMultiBoundOBB;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSMultiBoundOBB;

		virtual ~BSMultiBoundOBB();	 // 00

		// override (NiObject)
		virtual const NiRTTI* GetRTTI() const override;							  // 02
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;  // 17
		virtual void		  LoadBinary(NiStream& a_stream) override;			  // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			  // 19
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	  // 1A
		virtual void		  SaveBinary(NiStream& a_stream) override;			  // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;				  // 1C
		virtual std::uint32_t GetType() override;								  // 25 - { return 2; }
		virtual bool		  Unk_27() override;								  // 27
		virtual void		  Unk_28() override;								  // 28
		virtual bool		  Unk_29() override;								  // 29
		virtual void		  Unk_2A() override;								  // 2A
		virtual void		  Unk_2B() override;								  // 2B
		virtual bool		  WithinPoint(const NiPoint3& a_pos) override;		  // 2C
		virtual void		  Unk_2E() override;								  // 2E

		// members
		NiMatrix3	  rotation;	 // 40
		bool		  unk64;	 // 64
		std::uint8_t  pad65;	 // 65
		std::uint16_t pad66;	 // 66
	};
	static_assert(sizeof(BSMultiBoundOBB) == 0x68);
}
