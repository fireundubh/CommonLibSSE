#include "RE/BSLightingShaderMaterialFacegenTint.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSLightingShaderMaterialFacegenTint* BSLightingShaderMaterialFacegenTint::CreateFacegenTintMaterial()
	{
		using func_t = function_type_t<decltype(&BSLightingShaderMaterialFacegenTint::CreateFacegenTintMaterial)>;
		REL::Offset<func_t*> func(Offset::BSLightingShaderMaterialFacegenTint::CreateFacegenTintMaterial);
		return func();
	}
}
