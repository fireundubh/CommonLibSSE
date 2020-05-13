#include "RE/BSLightingShaderMaterialFacegenTint.h"

#include "RE/NiColor.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSLightingShaderMaterialFacegenTint* BSLightingShaderMaterialFacegenTint::CreateMaterial()
	{
		auto material = malloc<BSLightingShaderMaterialFacegenTint>();
		material->ctor();
		return material;
	}


	BSLightingShaderMaterialFacegenTint* BSLightingShaderMaterialFacegenTint::ctor()
	{
		using func_t = decltype(&BSLightingShaderMaterialFacegenTint::ctor);
		REL::Offset<func_t> func(Offset::BSLightingShaderMaterialFacegenTint::Ctor);
		return func(this);
	}
}
