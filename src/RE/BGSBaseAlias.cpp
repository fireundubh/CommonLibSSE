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
		return (flags & FLAGS::kEssential) != FLAGS::kNone;
	}


	bool BGSBaseAlias::IsProtected() const
	{
		return (flags & FLAGS::kProtected) != FLAGS::kNone;
	}


	void BGSBaseAlias::SetEssential()
	{
		flags |= FLAGS::kEssential;
	}


	void BGSBaseAlias::SetUnessential()
	{
		flags &= ~FLAGS::kEssential;
	}


	void BGSBaseAlias::SetProtected()
	{
		flags |= FLAGS::kProtected;
	}


	void BGSBaseAlias::SetUnprotected()
	{
		flags &= ~FLAGS::kProtected;
	}
}
