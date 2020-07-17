#pragma once

#include "RE/NetImmerse/NiRefObject/NiObject/bhkRefObject/bhkSerializable/bhkSerializable.h"


namespace RE
{
	class bhkWorld : public bhkSerializable
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkWorld;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkWorld;


		virtual ~bhkWorld();  // 00

		// override (bhkSerializable)
		virtual const NiRTTI* GetRTTI() const override;							 // 02
		virtual void		  LoadBinary(NiStream& a_stream) override;			 // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			 // 19
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	 // 1A - { return NiObject::RegisterStreamables(a_stream); }
		virtual void		  SaveBinary(NiStream& a_stream) override;			 // 1B
		virtual void		  Unk_25(void) override;							 // 25
		virtual hkpWorld*	  GetWorld() override;								 // 27 - { return referencedObject.ptr; }
		virtual void		  Unk_28(void) override;							 // 28 - { return referencedObject.ptr; }
		virtual void		  Unk_2B(void) override;							 // 2B
		virtual void		  Unk_2C(void) override;							 // 2C - { return 1; }
		virtual void		  Unk_2E(void) override;							 // 2E
		virtual void		  Unk_2F(void);										 // 2F

		// add
		virtual void Unk_32(void);	// 32
		virtual void Unk_33(void);	// 33
		virtual void Unk_34(void);	// 34
		virtual void Unk_35(void);	// 35
		virtual void Unk_36(void);	// 36


		// members
		UInt8 unk[0xC5E0];	// 20
	};
	STATIC_ASSERT(sizeof(bhkWorld) == 0xC600);
}
