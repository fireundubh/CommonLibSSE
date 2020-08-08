#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialGlowmap.h"


namespace RE
{
	BSLightingShaderMaterialGlowmap* BSLightingShaderMaterialGlowmap::CreateMaterial()
	{
		auto material = malloc<BSLightingShaderMaterialGlowmap>();
		material->ctor();
		return material;
	}


	BSLightingShaderMaterialGlowmap* BSLightingShaderMaterialGlowmap::ctor()
	{
		using func_t = decltype(&BSLightingShaderMaterialGlowmap::ctor);
		REL::Relocation<func_t> func{ Offset::BSLightingShaderMaterialGlowmap::Ctor };
		return func(this);
	}
}