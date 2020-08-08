#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialFacegenTint.h"


namespace RE
{
	BSLightingShaderMaterialFacegenTint* BSLightingShaderMaterialFacegenTint::CreateMaterial()
	{
		auto material = malloc<BSLightingShaderMaterialFacegenTint>();
		material->ctor();
		material->tintColor = NiColor(1.0f, 1.0f, 1.0f);
		return material;
	}


	BSLightingShaderMaterialFacegenTint* BSLightingShaderMaterialFacegenTint::ctor()
	{
		using func_t = decltype(&BSLightingShaderMaterialFacegenTint::ctor);
		REL::Relocation<func_t> func{ Offset::BSLightingShaderMaterialFacegenTint::Ctor };
		return func(this);
	}
}
