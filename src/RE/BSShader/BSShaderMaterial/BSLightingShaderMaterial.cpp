#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterial.h"


namespace RE
{
	BSLightingShaderMaterial* BSLightingShaderMaterial::CreateMaterial()
	{
		REL::Relocation<std::uintptr_t> vtbl{ RE::Offset::BSLightingShaderMaterial::Vtbl };
		size_t size = sizeof(BSLightingShaderMaterial);

		void* memory = malloc(size);
		std::memset(memory, 0, size);
		BSLightingShaderMaterial* material = (BSLightingShaderMaterial*)memory;
		material->ctor();
		((std::uintptr_t*)memory)[0] = vtbl.address();

		return material;
	}


	BSLightingShaderMaterialBase* BSLightingShaderMaterial::ctor()
	{
		using func_t = decltype(&BSLightingShaderMaterial::ctor);
		REL::Relocation<func_t> func{ Offset::BSLightingShaderMaterialBase::Ctor };
		return func(this);
	}
}