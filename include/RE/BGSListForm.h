#pragma once

#include "RE/BSTArray.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSListForm : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_BGSListForm;


		enum { kTypeID = FormType::FormList };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSListForm();											// 00

		// override (TESForm)
		virtual void	ClearData() override;							// 05
		virtual bool	Load(TESFile* a_mod) override;					// 06
		virtual void	SaveGame(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void	LoadGame(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void	Revert(void* a_arg1) override;					// 12
		virtual void	InitItemImpl() override;						// 13

		void	AddForm(TESForm* a_form);
		
		bool	HasForm(const TESForm* a_form) const;
		bool	HasForm(FormID a_formID) const;

		// members
		BSTArray<TESForm*>	forms;			// 20 - LNAM
		BSTArray<FormID>*	formIDs;		// 38 - holds references and generated form ids
		UInt32				numAddedForms;	// 40
		UInt32				pad44;			// 44
	};
	STATIC_ASSERT(sizeof(BGSListForm) == 0x48);
}
