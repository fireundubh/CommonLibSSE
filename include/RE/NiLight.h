#pragma once

#include "RE/NiAVObject.h"


namespace RE
{
	class NiLight : public NiAVObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiLight;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiLight;


		virtual ~NiLight();																											// 00

		// override (NiAVObject)
		virtual const NiRTTI*	GetRTTI() const override;																			// 02
		virtual void			LoadBinary(NiStream& a_stream) override;															// 18
		virtual void			SaveBinary(NiStream& a_stream) override;															// 1B
		virtual bool			IsEqual(NiObject* a_object) override;																// 1C


		// members
		float	unk110;	// 110;
		float	unk114;	// 114;
		float	unk118;	// 118;
		NiColor	unk11C;	// 11C
		float	unk128;	// 128
		float	unk12C;	// 12C
		float	radius;	// 130
		float	fade;	// 134
		UInt64	unk138;	// 138
	};
	STATIC_ASSERT(sizeof(NiLight) == 0x140);
}
