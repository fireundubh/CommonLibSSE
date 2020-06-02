#pragma once

#include "RE/BSParticleShaderEmitter.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class NiAVObject;


	class BSParticleShaderObjectEmitter : public BSParticleShaderEmitter
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSParticleShaderObjectEmitter;


		virtual ~BSParticleShaderObjectEmitter();  // 00

		// override (BSParticleShaderEmitter)
		virtual void Unk_02(void) override;	 // 02
		virtual void Unk_04(void) = 0;		 // 03
		virtual void Unk_05(void) = 0;		 // 05
		virtual void Unk_06(void) = 0;		 // 06


		// members
		NiPointer<NiAVObject> targetRoot;  // ED0
		UInt64				  unkED8;	   // ED8
	};
	STATIC_ASSERT(sizeof(BSParticleShaderObjectEmitter) == 0xEE0);
};