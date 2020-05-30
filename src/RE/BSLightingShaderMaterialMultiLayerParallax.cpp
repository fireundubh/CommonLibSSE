#include "RE/BSLightingShaderMaterialMultiLayerParallax.h"


namespace RE
{
	BSLightingShaderMaterialMultiLayerParallax* BSLightingShaderMaterialMultiLayerParallax::CreateMaterial()
	{
		auto material = malloc<BSLightingShaderMaterialMultiLayerParallax>();
		material->ctor();
		return material;
	}


	BSLightingShaderMaterialMultiLayerParallax* BSLightingShaderMaterialMultiLayerParallax::ctor()
	{
		using func_t = decltype(&BSLightingShaderMaterialMultiLayerParallax::ctor);
		REL::Offset<func_t> func(Offset::BSLightingShaderMaterialMultiLayerParallax::Ctor);
		return func(this);
	}
}