#pragma once

#include "RE/NetImmerse/NiRefObject/NiObject/NiExtraData/NiExtraData.h"


namespace RE
{
	class NiIntegersExtraData : public NiExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiIntegersExtraData;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiIntegersExtraData;


		virtual ~NiIntegersExtraData();	 // 00

		// override (NiExtraData)
		virtual const NiRTTI* GetRTTI() const override;							  // 02
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;  // 17
		virtual void		  LoadBinary(NiStream& a_stream) override;			  // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			  // 19 - { NiExtraData::LinkObject(a_stream); }
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	  // 1A - { return NiExtraData::RegisterStreamables(a_stream); }
		virtual void		  SaveBinary(NiStream& a_stream) override;			  // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;				  // 1C

		static NiIntegersExtraData* Create(const BSFixedString& a_name, const std::vector<std::int32_t>& a_integers);

		std::int32_t GetIndexOf(std::int32_t a_element) const;
		bool		 InsertElement(std::int32_t a_element);
		bool		 RemoveElement(std::int32_t a_element);


		// members
		std::uint32_t size;	  // 18
		std::uint32_t pad;	  // 1C
		std::int32_t* value;  // 20
	};
	static_assert(sizeof(NiIntegersExtraData) == 0x28);
}
