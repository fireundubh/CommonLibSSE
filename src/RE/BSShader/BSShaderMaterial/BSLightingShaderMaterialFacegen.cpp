#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialFacegen.h"


namespace RE
{
	BSLightingShaderMaterialFacegen* BSLightingShaderMaterialFacegen::CreateMaterial()
	{
		auto material = malloc<BSLightingShaderMaterialFacegen>();
		material->ctor();
		return material;
	}


	BSLightingShaderMaterialFacegen* BSLightingShaderMaterialFacegen::ctor()
	{
		using func_t = decltype(&BSLightingShaderMaterialFacegen::ctor);
		REL::Relocation<func_t> func{ Offset::BSLightingShaderMaterialFacegen::Ctor };
		return func(this);
	}
}