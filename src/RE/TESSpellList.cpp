#include "RE/TESSpellList.h"


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


	SInt32 TESSpellList::SpellData::GetSpellIndex(SpellItem* a_spell)
	{
		SInt32 index = -1;
		if (numSpells > 0) {
			for (UInt32 i = 0; i < numSpells; i++) {
				if (spells[i] && spells[i] == a_spell) {
					index = i;
					break;
				}
			}
		}
		return index;
	}
}