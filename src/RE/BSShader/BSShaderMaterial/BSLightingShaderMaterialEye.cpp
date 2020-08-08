#include "RE/BSSHader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialEye.h"


namespace RE
{
	BSLightingShaderMaterialEye* BSLightingShaderMaterialEye::CreateMaterial()
	{
		auto material = malloc<BSLightingShaderMaterialEye>();
		material->ctor();
		material->eyeCenter[0] = NiPoint3(-2.397175f, 7.572490f, 3.750610f);
		material->eyeCenter[1] = NiPoint3(2.397175f, 7.572490f, 3.750610f);
		return material;
	}


	BSLightingShaderMaterialEye* BSLightingShaderMaterialEye::ctor()
	{
		using func_t = decltype(&BSLightingShaderMaterialEye::ctor);
		REL::Relocation<func_t> func{ Offset::BSLightingShaderMaterialEye::Ctor };
		return func(this);
	}
}
