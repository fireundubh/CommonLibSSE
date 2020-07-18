#include "RE/FormComponents/Components/BGSBaseAlias/BGSBaseAlias.h"

#include "RE/FormComponents/Components/BGSBaseAlias/BGSLocAlias.h"
#include "RE/FormComponents/Components/BGSBaseAlias/BGSRefAlias.h"


namespace RE
{
	const BSFixedString& BGSBaseAlias::GetTypeString() const
	{
		return QType();
	}


	VMTypeID BGSBaseAlias::GetVMTypeID() const
	{
		const auto& TYPE = GetTypeString();
		if (TYPE == "Loc") {
			return BGSLocAlias::VMTYPEID;
		} else if (TYPE == "Ref") {
			return BGSRefAlias::VMTYPEID;
		} else {
			return BGSBaseAlias::VMTYPEID;
		}
	}


	bool BGSBaseAlias::IsQuestObject() const
	{
		return flags.all(FLAGS::kQuestObject);
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
