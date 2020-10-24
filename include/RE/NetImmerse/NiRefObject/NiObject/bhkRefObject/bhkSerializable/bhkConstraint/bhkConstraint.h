#pragma once

#include "RE/NetImmerse/NiRefObject/NiObject/bhkRefObject/bhkSerializable/bhkSerializable.h"


namespace RE
{
	class bhkConstraint : public bhkSerializable
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkConstraint;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkConstraint;


		virtual ~bhkConstraint();  // 00

		// override (bhkSerializable)
		virtual const NiRTTI* GetRTTI() const override;									   // 02
		virtual void		  LoadBinary(NiStream& a_stream) override;					   // 18
		virtual void		  LinkObject(NiStream& a_stream) override;					   // 19
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;			   // 1A 
		virtual void		  SaveBinary(NiStream& a_stream) override;					   // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;						   // 1C
		virtual void		  SetReferencedObject(hkReferencedObject* a_object) override;  // 25
		virtual void		  AdjustRefCount(bool a_increment) override;				   // 26
		virtual hkpWorld*	  GetWorld1() override;										   // 27 
		virtual ahkpWorld*	  GetWorld2() override;										   // 28 
		virtual void		  Unk_29(void) override;									   // 29 
		virtual void		  Unk_2A(void) override;									   // 2A
		virtual void		  Unk_2E(void) override;									   // 2E

		// add
		virtual void	   Unk_32(void);	  // 32
		virtual void	   Unk_33(void);	  // 33
		virtual void	   Unk_34(void);	  // 34
		virtual void	   Unk_35(void);	  // 35
		virtual void	   Unk_36(void);	  // 36
	};
	static_assert(sizeof(bhkConstraint) == 0x20);
}
