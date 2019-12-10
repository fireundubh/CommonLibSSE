#pragma once


namespace RE
{
	class Actor;
	class TESObjectREFR;


	class BGSOpenCloseForm
	{
	public:
		inline static const void* RTTI = RTTI_BGSOpenCloseForm;


		virtual ~BGSOpenCloseForm();												// 00

		// add
		virtual void	ProcessOpen(TESObjectREFR* a_target, Actor* a_activator);	// 01 - { return; }
		virtual void	ProcessClose(TESObjectREFR* a_target, Actor* a_activator);	// 02 - { return; }
		virtual bool	CanProcessOpenClose();										// 03 - { return false; }
	};
	STATIC_ASSERT(sizeof(BGSOpenCloseForm) == 0x8);
}
