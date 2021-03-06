#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialHairTint.h"


namespace RE
{
	BSLightingShaderMaterialHairTint* BSLightingShaderMaterialHairTint::CreateMaterial()
	{
		auto material = malloc<BSLightingShaderMaterialHairTint>();
		material->ctor();
		return material;
	}


	BSLightingShaderMaterialHairTint* BSLightingShaderMaterialHairTint::ctor()
	{
		using func_t = decltype(&BSLightingShaderMaterialHairTint::ctor);
		REL::Relocation<func_t> func{ Offset::BSLightingShaderMaterialHairTint::Ctor };
		return func(this);
	}
}