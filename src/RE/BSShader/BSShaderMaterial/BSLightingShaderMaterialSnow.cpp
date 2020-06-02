#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialSnow.h"


namespace RE
{
	BSLightingShaderMaterialSnow* BSLightingShaderMaterialSnow::CreateMaterial()
	{
		auto material = malloc<BSLightingShaderMaterialSnow>();
		material->ctor();
		return material;
	}


	BSLightingShaderMaterialSnow* BSLightingShaderMaterialSnow::ctor()
	{
		using func_t = decltype(&BSLightingShaderMaterialSnow::ctor);
		REL::Offset<func_t> func(Offset::BSLightingShaderMaterialSnow::Ctor);
		return func(this);
	}
}