#pragma once

#include "RE/BSTriShape.h"


namespace RE
{
	class BSDynamicTriShape : public BSTriShape
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSDynamicTriShape;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSDynamicTriShape;


		virtual ~BSDynamicTriShape();  // 00

		// override (BSGeometry)
		virtual const NiRTTI*	   GetRTTI() const override;						   // 02
		virtual BSDynamicTriShape* AsDynamicTriShape() override;					   // 0C
		virtual NiObject*		   CreateClone(NiCloningProcess& a_cloning) override;  // 17
		virtual void			   LoadBinary(NiStream& a_stream) override;			   // 18
		virtual void			   LinkObject(NiStream& a_stream) override;			   // 19 - { BSGeometry::LinkObject(a_stream); }
		virtual bool			   RegisterStreamables(NiStream& a_stream) override;   // 1A - { return BSGeometry::RegisterStreamables(a_stream); }
		virtual void			   SaveBinary(NiStream& a_stream) override;			   // 1B
		virtual bool			   IsEqual(NiObject* a_object) override;			   // 1C - { return false; }


		// members
		void*			   pDynamicData;  // 160
		mutable BSSpinLock lock;		  // 168
		UInt32			   dataSize;	  // 170
		UInt32			   frameCount;	  // 174
		UInt32			   unk178;		  // 178
		UInt32			   unk17C;		  // 17C
	};
	STATIC_ASSERT(sizeof(BSDynamicTriShape) == 0x180);
}