#pragma once

#include "RE/NetImmerse/NiRefObject/NiObject/NiObject.h"
#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class BSMultiBoundShape;
	class NiPoint3;


	class BSMultiBound : public NiObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSMultiBound;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSMultiBound;

		virtual ~BSMultiBound();  // 00

		// override (NiObject)
		virtual const NiRTTI* GetRTTI() const override;							  // 02
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;  // 17
		virtual void		  LoadBinary(NiStream& a_stream) override;			  // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			  // 19
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	  // 1A
		virtual void		  SaveBinary(NiStream& a_stream) override;			  // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;				  // 1C

		// add
		virtual bool QWithinPoint(const NiPoint3& a_pos);  // 25
		virtual void Unk_26();							   // 26

		// members
		std::uint32_t				 unk10;	 // 10
		std::uint32_t				 pad14;	 // 14
		NiPointer<BSMultiBoundShape> data;	 // 18
	};
	static_assert(sizeof(BSMultiBound) == 0x20);
}