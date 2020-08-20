#pragma once

#include "RE/FormComponents/BaseFormComponent.h"


namespace RE
{
	class BGSKeyword;


	class BGSKeywordForm : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSKeywordForm;


		virtual ~BGSKeywordForm();	// 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01 - { return; }
		virtual void ClearDataComponent() override;						// 02
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual bool		HasKeyword(const BGSKeyword* a_keyword) const;	// 04
		virtual BGSKeyword* GetDefaultKeyword() const;						// 05 - { return 0; }

		bool						 AddKeyword(BGSKeyword* a_keyword);
		bool						 HasKeyword(FormID a_formID) const;
		bool						 HasKeywordString(const char* a_formEditorID) const;
		std::optional<BGSKeyword*>	 GetKeywordAt(std::uint32_t a_idx) const;
		std::uint32_t				 GetNumKeywords() const;
		std::optional<std::uint32_t> GetKeywordIndex(BGSKeyword* a_keyword) const;
		bool						 RemoveKeyword(BGSKeyword* a_keyword);


		// members
		BGSKeyword**  keywords;		// 08 - KWDA
		std::uint32_t numKeywords;	// 10 - KSIZ
		std::uint32_t pad14;		// 14
	};
	static_assert(sizeof(BGSKeywordForm) == 0x18);
}
