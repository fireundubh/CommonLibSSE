#pragma once

#include "RE/NiProperty.h"


namespace RE
{
	class NiAlphaProperty : public NiProperty
	{
	public:
		inline static const void* RTTI = RTTI_NiAlphaProperty;
		inline static const void* Ni_RTTI = NiRTTI_NiAlphaProperty;

		virtual ~NiAlphaProperty();													// 00

		// override (NiObjectNET)
		virtual const NiRTTI*	GetRTTI() const override;							// 02
		virtual NiObject*		CreateClone(NiCloningProcess& a_cloning);			// 17 
		virtual void			LoadBinary(NiStream& a_stream) override;			// 18 - { NiObjectNET::LoadBinary(a_stream); }
		virtual void			LinkObject(NiStream& a_stream) override;			// 19 - { NiObjectNET::LinkObject(a_stream); }
		virtual bool			RegisterStreamables(NiStream& a_stream) override;	// 1A - { return NiObjectNET::RegisterStreamables(a_stream); }
		virtual void			SaveBinary(NiStream& a_stream) override;			// 1B 
		virtual bool			IsEqual(NiObject* a_object) override;				// 1C - { return NiObjectNET::IsEqual(a_object); }
		virtual void			ProcessClone(NiCloningProcess& a_cloning) override;	// 1D

		// add
		virtual Type			GetType() const override;							// 25 - { return 0; }


		//members
		UInt16	alphaFlags;			// 30
		UInt8	alphaThreshold;		// 32
	};
	static_assert(sizeof(NiAlphaProperty) == 0x38);
}