#include "RE/FormComponents/BGSKeywordForm.h"

#include "RE/FormComponents/TESForm/BGSKeyword/BGSKeyword.h"


namespace RE
{
	bool BGSKeywordForm::AddKeyword(BGSKeyword* a_keyword)
	{
		if (GetKeywordIndex(a_keyword) == std::nullopt) {
			auto oldData = keywords;
			keywords = calloc<BGSKeyword*>(++numKeywords);
			if (oldData) {
				for (std::uint32_t i = 0; i < numKeywords - 1; ++i) {
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
			stl::span<RE::BGSKeyword*> span(keywords, numKeywords);
			for (auto& keyword : span) {
				if (keyword && keyword->formID == a_formID) {
					return true;
				}
			}
		}

		return false;
	}


	bool BGSKeywordForm::HasKeywordString(const char* a_formEditorID) const
	{
		if (keywords) {
			stl::span<RE::BGSKeyword*> span(keywords, numKeywords);
			for (auto& keyword : span) {
				if (keyword && keyword->formEditorID == a_formEditorID) {
					return true;
				}
			}
		}

		return false;
	}


	std::optional<BGSKeyword*> BGSKeywordForm::GetKeywordAt(std::uint32_t a_idx) const
	{
		if (a_idx < numKeywords) {
			return std::make_optional(keywords[a_idx]);
		} else {
			return std::nullopt;
		}
	}


	std::optional<std::uint32_t> BGSKeywordForm::GetKeywordIndex(BGSKeyword* a_keyword) const
	{
		std::optional<std::uint32_t> index = std::nullopt;
		if (keywords) {
			for (std::uint32_t i = 0; i < numKeywords; ++i) {
				if (keywords[i] && keywords[i] == a_keyword) {
					index = i;
					break;
				}
			}
		}
		return index;
	}


	std::uint32_t BGSKeywordForm::GetNumKeywords() const
	{
		return numKeywords;
	}


	bool BGSKeywordForm::RemoveKeyword(BGSKeyword* a_keyword)
	{
		auto index = GetKeywordIndex(a_keyword);
		if (index != std::nullopt) {
			auto oldData = keywords;
			if (oldData) {
				keywords = calloc<BGSKeyword*>(--numKeywords);
				for (std::uint32_t i = 0; i < numKeywords + 1; ++i) {
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
