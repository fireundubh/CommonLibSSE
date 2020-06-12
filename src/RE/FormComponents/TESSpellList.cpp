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


	SInt32 TESSpellList::SpellData::GetIndex(SpellItem* a_spell)
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


	SInt32 TESSpellList::SpellData::GetIndex(TESShout* a_shout)
	{
		SInt32 index = -1;
		if (numShouts > 0) {
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