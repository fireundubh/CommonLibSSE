#pragma once

#include "RE/NiLight.h"


namespace RE
{
	class NiPointLight : public NiLight
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiPointLight;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiPointLight;


		virtual ~NiPointLight();  // 00

		// override (NiLight)
		virtual const NiRTTI* GetRTTI() const override;					 // 02
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning);	 // 17
		virtual void		  LoadBinary(NiStream& a_stream) override;	 // 18
		virtual void		  SaveBinary(NiStream& a_stream) override;	 // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;		 // 1C


		// members
		float constLightAttenuation;	  // 140
		float linearLightAttenuation;	  // 144
		float quadraticLightAttenuation;  // 148
	};
	STATIC_ASSERT(sizeof(NiPointLight) == 0x150);
}
