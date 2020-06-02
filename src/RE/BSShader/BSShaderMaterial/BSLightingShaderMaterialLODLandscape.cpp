#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialLODLandscape.h"


namespace RE
{
	BSLightingShaderMaterialLODLandscape* BSLightingShaderMaterialLODLandscape::CreateMaterial()
	{
		auto material = malloc<BSLightingShaderMaterialLODLandscape>();
		material->ctor();
		return material;
	}


	BSLightingShaderMaterialLODLandscape* BSLightingShaderMaterialLODLandscape::ctor()
	{
		using func_t = decltype(&BSLightingShaderMaterialLODLandscape::ctor);
		REL::Offset<func_t> func(Offset::BSLightingShaderMaterialLODLandscape::Ctor);
		return func(this);
	}
}