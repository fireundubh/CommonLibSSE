#pragma once

#include "RE/NetImmerse/NiRefObject/NiObject/bhkRefObject/bhkSerializable/bhkShape/bhkShape.h"


namespace RE
{
	class bhkBvTreeShape : public bhkShape
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkBvTreeShape;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkBvTreeShape;


		virtual ~bhkBvTreeShape();	// 00

		// override (bhkShape)
		virtual const NiRTTI* GetRTTI() const override;							 // 02
		virtual void		  LoadBinary(NiStream& a_stream) override;			 // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			 // 19 - { bhkSerializable::LinkObject(a_stream); }
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	 // 1A - { return bhkSerializable::RegisterStreamables(a_stream); }
		virtual void		  SaveBinary(NiStream& a_stream) override;			 // 1B
		virtual void		  AdjustRefCount(bool a_increment) override;		 // 26
		virtual void		  Unk_32(void) override;							 // 32
		virtual void		  Unk_34(void) override;							 // 34 
		virtual void		  Unk_35(void) override;							 // 35
	};
	static_assert(sizeof(bhkBvTreeShape) == 0x28);
}
