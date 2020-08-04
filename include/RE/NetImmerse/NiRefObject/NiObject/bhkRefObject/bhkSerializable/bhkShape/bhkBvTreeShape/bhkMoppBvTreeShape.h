#pragma once

#include "RE/NetImmerse/NiRefObject/NiObject/bhkRefObject/bhkSerializable/bhkShape/bhkBvTreeShape/bhkBvTreeShape.h"


namespace RE
{
	class bhkMoppBvTreeShape : public bhkBvTreeShape
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkMoppBvTreeShape;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkMoppBvTreeShape;


		virtual ~bhkMoppBvTreeShape();	// 00

		// override (bhkBvTreeShape)
		virtual const NiRTTI* GetRTTI() const override;							 // 02
		virtual void		  LoadBinary(NiStream& a_stream) override;			 // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			 // 19 - { bhkSerializable::LinkObject(a_stream); }
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	 // 1A - { return bhkSerializable::RegisterStreamables(a_stream); }
		virtual void		  SaveBinary(NiStream& a_stream) override;			 // 1B
		virtual void		  AdjustRefCount(bool a_increment) override;		 // 26
		virtual void		  Unk_2B(void) override;							 // 2B
		virtual void		  Unk_2C(void) override;							 // 2C
		virtual void		  Unk_2D(void) override;							 // 2D
		virtual void		  Unk_2E(void) override;							 // 2E
		virtual void		  Unk_2F(void) override;							 // 2F
		virtual void		  Unk_31(void) override;							 // 32
		virtual void		  Unk_32(void) override;							 // 32
	};
	static_assert(sizeof(bhkMoppBvTreeShape) == 0x28);
}
