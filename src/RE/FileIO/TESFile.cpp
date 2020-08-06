#include "RE/FileIO/TESFile.h"


namespace RE
{
	TESFile* TESFile::Duplicate(std::uint32_t a_cacheSize)
	{
		using func_t = decltype(&TESFile::Duplicate);
		REL::Relocation<func_t> func{ Offset::TESFile::Duplicate };
		return func(this, a_cacheSize);
	}


	std::uint32_t TESFile::GetCurrentSubRecordType()
	{
		using func_t = decltype(&TESFile::GetCurrentSubRecordType);
		REL::Relocation<func_t> func{ Offset::TESFile::GetCurrentSubRecordType };
		return func(this);
	}


	// Converts the lower bits of a FormID to a full FormID depending on plugin type
	FormID TESFile::GetFormID(std::uint32_t formLower) const
	{
		return !IsLight() ? std::uint32_t(compileIndex) << 24 | (formLower & 0xFFFFFF) : 0xFE000000 | (std::uint32_t(smallFileCompileIndex) << 12) | (formLower & 0xFFF);
	}


	FormType TESFile::GetFormType()
	{
		using func_t = decltype(&TESFile::GetFormType);
		REL::Relocation<func_t> func{ Offset::TESFile::GetFormType };
		return func(this);
	}


	// Returns either a compileIndex or a compileIndex|smallFileCompileIndex pair
	std::uint32_t TESFile::GetPartialIndex() const
	{
		return !IsLight() ? compileIndex : (0xFE000 | smallFileCompileIndex);
	}


	// Checks if a particular formID is part of the mod
	bool TESFile::IsFormInMod(FormID formID) const
	{
		if (!IsLight() && (formID >> 24) == compileIndex)
			return true;
		if (IsLight() && (formID >> 24) == 0xFE && ((formID & 0x00FFF000) >> 12) == smallFileCompileIndex)
			return true;
		return false;
	}


	void TESFile::ReadData(void* a_buf, std::uint32_t a_size)
	{
		using func_t = decltype(&TESFile::ReadData);
		REL::Relocation<func_t> func{ Offset::TESFile::ReadData };
		return func(this, a_buf, a_size);
	}


	bool TESFile::Seek(std::uint32_t a_offset)
	{
		using func_t = decltype(&TESFile::Seek);
		REL::Relocation<func_t> func{ Offset::TESFile::Seek };
		return func(this, a_offset);
	}


	bool TESFile::SeekNextSubrecord()
	{
		using func_t = decltype(&TESFile::SeekNextSubrecord);
		REL::Relocation<func_t> func{ Offset::TESFile::SeekNextSubrecord };
		return func(this);
	}
}
