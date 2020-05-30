#include "RE/BSLightingShaderMaterialGlowmap.h"


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
		REL::Offset<func_t> func(Offset::BSLightingShaderMaterialGlowmap::Ctor);
		return func(this);
	}
}