#include "RE/FormComponents/TESSpellList.h"


namespace RE
{
	TESSpellList::SpellData::SpellData() :
		spells(nullptr),
		levSpells(nullptr),
		shouts(nullptr),
		numSpells(0),
		numlevSpells(0),
		numShouts(0),
		pad24(0)
	{
	}


	bool TESSpellList::SpellData::AddLevSpell(TESLevSpell* a_levSpell)
	{
		if (GetIndex(a_levSpell) == -1) {
			auto oldData = levSpells;
			levSpells = calloc<TESLevSpell*>(++numlevSpells);
			if (oldData) {
				for (UInt32 i = 0; i < numlevSpells - 1; i++) {
					levSpells[i] = oldData[i];
				}
				free(oldData);
				oldData = nullptr;
			}
			levSpells[numlevSpells - 1] = a_levSpell;
			return true;
		}
		return false;
	}


	bool TESSpellList::SpellData::AddShout(TESShout* a_shout)
	{
		if (GetIndex(a_shout) == -1) {
			auto oldData = shouts;
			shouts = calloc<TESShout*>(++numShouts);
			if (oldData) {
				for (UInt32 i = 0; i < numShouts - 1; i++) {
					shouts[i] = oldData[i];
				}
				free(oldData);
				oldData = nullptr;
			}
			shouts[numShouts - 1] = a_shout;
			return true;
		}
		return false;
	}


	bool TESSpellList::SpellData::AddSpell(SpellItem* a_spell)
	{
		if (GetIndex(a_spell) == -1) {
			auto oldData = spells;
			spells = calloc<SpellItem*>(++numSpells);
			if (oldData) {
				for (UInt32 i = 0; i < numSpells - 1; i++) {
					spells[i] = oldData[i];
				}
				free(oldData);
				oldData = nullptr;
			}
			spells[numSpells - 1] = a_spell;
			return true;
		}
		return false;
	}


	SInt32 TESSpellList::SpellData::GetIndex(SpellItem* a_spell)
	{
		SInt32 index = -1;
		if (spells) {
			for (UInt32 i = 0; i < numSpells; i++) {
				if (spells[i] && spells[i] == a_spell) {
					index = i;
					break;
				}
			}
		}
		return index;
	}


	SInt32 TESSpellList::SpellData::GetIndex(TESLevSpell* a_lvlSpell)
	{
		SInt32 index = -1;
		if (levSpells) {
			for (UInt32 i = 0; i < numlevSpells; i++) {
				if (levSpells[i] && levSpells[i] == a_lvlSpell) {
					index = i;
					break;
				}
			}
		}
		return index;
	}


	SInt32 TESSpellList::SpellData::GetIndex(TESShout* a_shout)
	{
		SInt32 index = -1;
		if (shouts) {
			for (UInt32 i = 0; i < numShouts; i++) {
				if (shouts[i] && shouts[i] == a_shout) {
					index = i;
					break;
				}
			}
		}
		return index;
	}
}