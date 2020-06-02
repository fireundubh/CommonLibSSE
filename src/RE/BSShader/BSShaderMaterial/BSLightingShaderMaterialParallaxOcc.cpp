#include "RE/BSLightingShaderMaterialParallaxOcc.h"


namespace RE
{
	BSLightingShaderMaterialParallaxOcc* BSLightingShaderMaterialParallaxOcc::CreateMaterial()
	{
		auto material = malloc<BSLightingShaderMaterialParallaxOcc>();
		material->ctor();
		return material;
	}


	BSLightingShaderMaterialParallaxOcc* BSLightingShaderMaterialParallaxOcc::ctor()
	{
		using func_t = decltype(&BSLightingShaderMaterialParallaxOcc::ctor);
		REL::Offset<func_t> func(Offset::BSLightingShaderMaterialParallaxOcc::Ctor);
		return func(this);
	}
}