#pragma once

#include "RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiAVObject/BSGeometry/BSTriShape/BSTriShape.h"


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
		void*			   dynamicData;	 // 160
		mutable BSSpinLock lock;		 // 168
		std::uint32_t	   dataSize;	 // 170
		std::uint32_t	   frameCount;	 // 174
		std::uint32_t	   unk178;		 // 178
		std::uint32_t	   unk17C;		 // 17C
	};
	static_assert(sizeof(BSDynamicTriShape) == 0x180);
}