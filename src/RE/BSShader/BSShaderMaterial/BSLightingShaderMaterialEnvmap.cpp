#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialEnvmap.h"


namespace RE
{
	BSLightingShaderMaterialEnvmap* BSLightingShaderMaterialEnvmap::CreateMaterial()
	{
		auto material = malloc<BSLightingShaderMaterialEnvmap>();
		material->ctor();
		return material;
	}


	BSLightingShaderMaterialEnvmap* BSLightingShaderMaterialEnvmap::ctor()
	{
		using func_t = decltype(&BSLightingShaderMaterialEnvmap::ctor);
		REL::Relocation<func_t> func{ Offset::BSLightingShaderMaterialEnvmap::Ctor };
		return func(this);
	}
}
