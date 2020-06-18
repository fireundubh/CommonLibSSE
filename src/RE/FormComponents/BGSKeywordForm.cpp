#include "RE/FormComponents/BGSKeywordForm.h"

#include "RE/FormComponents/TESForm/BGSKeyword/BGSKeyword.h"


namespace RE
{
	bool BGSKeywordForm::AddKeyword(BGSKeyword* a_keyword)
	{
		if (GetKeywordIndex(a_keyword) == -1) {
			auto oldData = keywords;
			keywords = calloc<BGSKeyword*>(++numKeywords);
			if (oldData) {
				for (UInt32 i = 0; i < numKeywords - 1; ++i) {
					keywords[i] = oldData[i];
				}
				free(oldData);
				oldData = nullptr;
			}
			keywords[numKeywords - 1] = a_keyword;
			return true;
		}
		return false;
	}


	bool BGSKeywordForm::HasKeyword(FormID a_formID) const
	{
		if (keywords) {
			for (UInt32 idx = 0; idx < numKeywords; ++idx) {
				if (keywords[idx] && keywords[idx]->formID == a_formID) {
					return true;
				}
			}
		}

		return false;
	}


	bool BGSKeywordForm::HasKeyword(const char* a_formEditorID) const
	{
		if (keywords) {
			for (UInt32 idx = 0; idx < numKeywords; ++idx) {
				if (keywords[idx] && keywords[idx]->formEditorID == a_formEditorID) {
					return true;
				}
			}
		}

		return false;
	}


	std::optional<BGSKeyword*> BGSKeywordForm::GetKeywordAt(UInt32 a_idx) const
	{
		if (a_idx < numKeywords) {
			return std::make_optional(keywords[a_idx]);
		} else {
			return std::nullopt;
		}
	}


	SInt32 BGSKeywordForm::GetKeywordIndex(BGSKeyword* a_keyword) const
	{
		SInt32 index = -1;
		if (keywords) {
			for (UInt32 i = 0; i < numKeywords; ++i) {
				if (keywords[i] && keywords[i] == a_keyword) {
					index = i;
					break;
				}
			}
		}
		return index;
	}


	UInt32 BGSKeywordForm::GetNumKeywords() const
	{
		return numKeywords;
	}


	bool BGSKeywordForm::RemoveKeyword(BGSKeyword* a_keyword)
	{
		auto index = GetKeywordIndex(a_keyword);
		if (index != -1) {
			auto oldData = keywords;
			if (oldData) {
				keywords = calloc<BGSKeyword*>(--numKeywords);
				for (UInt32 i = 0; i < numKeywords + 1; ++i) {
					if (index != i) {
						keywords[i] = oldData[i];
					}
				}
				free(oldData);
				oldData = nullptr;
				return true;
			}
		}
		return false;
	}
}
