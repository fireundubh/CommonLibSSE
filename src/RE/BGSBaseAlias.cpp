#include "RE/BGSBaseAlias.h"


namespace RE
{
	const BSFixedString& BGSBaseAlias::GetTypeString() const
	{
		return QType();
	}


	bool BGSBaseAlias::IsQuestObject() const
	{
		return (flags & FLAGS::kQuestObject) != FLAGS::kNone;
	}


	bool BGSBaseAlias::IsEssential() const
	{
		return (aliasFlags.flags & AliasFlags::Flag::kEssential) != AliasFlags::Flag::kNone;
	}


	bool BGSBaseAlias::IsProtected() const
	{
		return (aliasFlags.flags & AliasFlags::Flag::kProtected) != AliasFlags::Flag::kNone;
	}


	void BGSBaseAlias::SetEssential()
	{
		aliasFlags.flags |= RE::BGSBaseAlias::AliasFlags::Flag::kEssential;
	}


	void BGSBaseAlias::SetUnessential()
	{
		aliasFlags.flags &= ~RE::BGSBaseAlias::AliasFlags::Flag::kEssential;
	}


	void BGSBaseAlias::SetProtected()
	{
		aliasFlags.flags |= RE::BGSBaseAlias::AliasFlags::Flag::kProtected;
	}

	
	void BGSBaseAlias::SetUnprotected()
	{
		aliasFlags.flags &= ~RE::BGSBaseAlias::AliasFlags::Flag::kProtected;
	}
}
