#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialParallax.h"


namespace RE
{
	BSLightingShaderMaterialParallax* BSLightingShaderMaterialParallax::CreateMaterial()
	{
		auto material = malloc<BSLightingShaderMaterialParallax>();
		material->ctor();
		return material;
	}
	

	BSLightingShaderMaterialParallax* BSLightingShaderMaterialParallax::ctor()
	{
		using func_t = decltype(&BSLightingShaderMaterialParallax::ctor);
		REL::Offset<func_t> func(Offset::BSLightingShaderMaterialParallax::Ctor);
		return func(this);
	}
}