#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialLandscape.h"


namespace RE
{
	BSLightingShaderMaterialLandscape* BSLightingShaderMaterialLandscape::CreateMaterial()
	{
		auto material = malloc<BSLightingShaderMaterialLandscape>();
		material->ctor();
		return material;
	}


	BSLightingShaderMaterialLandscape* BSLightingShaderMaterialLandscape::ctor()
	{
		using func_t = decltype(&BSLightingShaderMaterialLandscape::ctor);
		REL::Offset<func_t> func(Offset::BSLightingShaderMaterialLandscape::Ctor);
		return func(this);
	}
}