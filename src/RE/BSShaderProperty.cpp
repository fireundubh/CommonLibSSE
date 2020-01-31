#include "RE/BSShaderProperty.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"  

namespace RE
{
	void BSShaderProperty::InitializeMaterial(BSGeometry* a_geometry)
	{
		using func_t = function_type_t<decltype(&BSShaderProperty::InitializeMaterial)>;
		REL::Offset<func_t*> func(Offset::BSShaderProperty::InitializeMaterial);
		return func(this, a_geometry);
	}
	
	
	void BSShaderProperty::InitializeShader(BSGeometry* a_geometry)
	{
		using func_t = function_type_t<decltype(&BSShaderProperty::InitializeShader)>;
		REL::Offset<func_t*> func(Offset::BSShaderProperty::InitializeShader);
		return func(this, a_geometry);
	}


	void BSShaderProperty::SetMaterial(BSShaderMaterial* a_otherMaterial, bool a_unk1)
	{
		using func_t = function_type_t<decltype(&BSShaderProperty::SetMaterial)>;
		REL::Offset<func_t*> func(Offset::BSShaderProperty::SetMaterial);
		return func(this, a_otherMaterial, a_unk1);			
	}


	void BSShaderProperty::SetFlags(EShaderPropertyFlag a_flag, UInt8 a_toggle)
	{
		using func_t = function_type_t<decltype(&BSShaderProperty::SetFlags)>;
		REL::Offset<func_t*> func(Offset::BSShaderProperty::SetFlags);
		return func(this, a_flag, a_toggle);
	}


	bool BSShaderProperty::InvalidateMaterial()
	{
		using func_t = function_type_t<decltype(&BSShaderProperty::InvalidateMaterial)>;
		REL::Offset<func_t*> func(Offset::BSShaderProperty::InvalidateMaterial);
		return func(this);
	}


	void BSShaderProperty::InvalidateTextures(UInt32 unk1)
	{
		using func_t = function_type_t<decltype(&BSShaderProperty::InvalidateTextures)>;
		REL::Offset<func_t*> func(Offset::BSShaderProperty::InvalidateTextures);
		return func(this, unk1);
	}


	void BSShaderProperty::SetBSEffectShaderData(BSEffectShaderData * a_data)
	{
		using func_t = function_type_t<decltype(&BSShaderProperty::SetBSEffectShaderData)>;
		REL::Offset<func_t*> func(Offset::BSShaderProperty::SetBSEffectShaderData);
		return func(this, a_data);
	}
}