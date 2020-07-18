#include "RE/BSSystem/IFormFactory/IFormFactory.h"


namespace RE
{
	std::pair<IFormFactory**, bool> IFormFactory::GetFormFactories()
	{
		struct Factories
		{
			IFormFactory* data[to_underlying(FormType::Max)];
		};

		REL::Offset<Factories*> formFactories = REL::ID(514355);
		REL::Offset<bool*> formFactoriesInitialized = REL::ID(514349);
		return std::make_pair(formFactories->data, *formFactoriesInitialized);
	}


	IFormFactory* IFormFactory::GetFormFactoryByType(FormType a_formType)
	{
		auto formFactories = GetFormFactories();
		return formFactories.second ? formFactories.first[static_cast<std::uint32_t>(a_formType)] : nullptr;
	}


	TESForm* IFormFactory::Create()
	{
		return CreateImpl();
	}
}
