#pragma once

#include "RE/ReferenceEffect.h"
#include "RE/TESEffectShader.h"

namespace RE
{
	class ShaderReferenceEffect : public ReferenceEffect
	{
	public:
		struct UnknownTypeInformation
		{
			char* type;
			UnknownTypeInformation* next;
		};
		virtual ~ShaderReferenceEffect();
		//
		virtual void Unk_01(void);
		virtual UnknownTypeInformation* GetTypeInformation(); // 02
		//
		UInt32 unk00; //00
		UInt8  unk04[(0x28 - 0x04) / sizeof(UInt8)]; // 004
		RefHandle refHandle; // 038
		UInt32 pad3C;
		UInt32 unk40; //040
		UInt8  unk41[(0xB8 - 0x44) / sizeof(UInt8)];
		BGSArtObject* artObject; // 0B8
		UInt8  unkBC[(0x104 - 0xBC) / sizeof(UInt8)];
		TESEffectShader* shader; // 108
	};
	static_assert(offsetof(ShaderReferenceEffect, refHandle) >= 0x038, "refHandle is too early!");
	static_assert(offsetof(ShaderReferenceEffect, refHandle) <= 0x038, "refHandle is too late!");

	static_assert(offsetof(ShaderReferenceEffect, unk40) >= 0x040, "refHandle is too early!");
	static_assert(offsetof(ShaderReferenceEffect, unk40) <= 0x040, "refHandle is too late!");

	static_assert(offsetof(ShaderReferenceEffect, artObject) >= 0x0B8, "art is too early!");
	static_assert(offsetof(ShaderReferenceEffect, artObject) <= 0x0B8, "art is too late!");

	static_assert(offsetof(ShaderReferenceEffect, shader) >= 0x0108, "shader is too early!");
	static_assert(offsetof(ShaderReferenceEffect, shader) <= 0x0108, "shader is too late!");
};
