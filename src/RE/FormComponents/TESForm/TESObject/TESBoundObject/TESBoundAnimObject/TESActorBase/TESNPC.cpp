#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundAnimObject/TESActorBase/TESNPC.h"

#include "RE/FormComponents/TESForm/TESRace.h"
#include "RE/FormComponents/TESSpellList.h"


namespace RE
{
	TESNPC::HeadRelatedData::HeadRelatedData() :
		hairColor(nullptr),
		faceDetails(nullptr)
	{}


	void TESNPC::ChangeHeadPart(BGSHeadPart* a_target)
	{
		using func_t = decltype(&TESNPC::ChangeHeadPart);
		REL::Offset<func_t> func(Offset::TESNPC::ChangeHeadPart);
		return func(this, a_target);
	}


	BGSHeadPart** TESNPC::GetBaseOverlays() const
	{
		using func_t = decltype(&TESNPC::GetBaseOverlays);
		REL::Offset<func_t> func(Offset::TESNPC::GetBaseOverlays);
		return func(this);
	}


	SInt32 TESNPC::GetBasePerkIndex(BGSPerk* a_perk)
	{
		SInt32 index = -1;
		if (perkCount > 0) {
			for (UInt32 i = 0; i < perkCount; i++) {
				if (perks[i].perk && perks[i].perk == a_perk) {
					index = i;
					break;
				}
			}
		}
		return index;
	}


	BGSHeadPart* TESNPC::GetCurrentHeadPartByType(HeadPartType a_type)
	{
		return HasOverlays() ? GetHeadPartOverlayByType(a_type) : GetHeadPartByType(a_type);
	}


	BGSHeadPart* TESNPC::GetHeadPartByType(HeadPartType a_type)
	{
		if (headParts) {
			for (SInt8 i = 0; i < numHeadParts; ++i) {
				if (headParts[i] && headParts[i]->type == a_type) {
					return headParts[i];
				}
			}
		}
		return nullptr;
	}


	BGSHeadPart* TESNPC::GetHeadPartOverlayByType(HeadPartType a_type)
	{
		const auto numOverlays = GetNumBaseOverlays();
		auto overlays = GetBaseOverlays();
		if (overlays) {
			for (UInt32 i = 0; i < numOverlays; ++i) {
				if (overlays[i]->type == a_type) {
					return overlays[i];
				}
			}
		}
		return nullptr;
	}


	float TESNPC::GetHeight() const
	{
		if (!race) {
			return height;
		}

		const auto sex = GetSex();
		switch (sex) {
		case SEX::kMale:
		case SEX::kFemale:
			return race->data.height[sex] * height;
		default:
			return 0.0;
		}
	}


	UInt32 TESNPC::GetNumBaseOverlays() const
	{
		using func_t = decltype(&TESNPC::GetNumBaseOverlays);
		REL::Offset<func_t> func(Offset::TESNPC::GetNumBaseOverlays);
		return func(this);
	}


	TESSpellList::SpellData* TESNPC::GetOrCreateSpellList()
	{
		if (!actorEffects) {
			actorEffects = new TESSpellList::SpellData();
		}
		return actorEffects;
	}


	TESRace* TESNPC::GetRace()
	{
		return race;
	}


	TESNPC* TESNPC::GetRootFaceNPC()
	{
		auto iter = this;
		while (iter->faceNPC) {
			iter = iter->faceNPC;
		}
		return iter;
	}


	const TESNPC* TESNPC::GetRootFaceNPC() const
	{
		auto iter = this;
		while (iter->faceNPC) {
			iter = iter->faceNPC;
		}
		return iter;
	}


	SEX TESNPC::GetSex() const
	{
		return IsFemale() ? SEX::kFemale : SEX::kMale;
	}


	float TESNPC::Layer::GetInterpolationValue() const
	{
		return static_cast<float>(interpolationValue) / static_cast<float>(100.0);
	}


	bool TESNPC::IsInClass(TESClass* a_class) const
	{
		return npcClass ? npcClass == a_class : false;
	}


	bool TESNPC::HasOverlays()
	{
		using func_t = decltype(&TESNPC::HasOverlays);
		REL::Offset<func_t> func(Offset::TESNPC::HasOverlays);
		return func(this);
	}


	bool TESNPC::HasKeyword(const char* a_formEditorID)
	{
		auto keywordForm = As<BGSKeywordForm>();
		if (keywordForm) {
			bool hasKeyword = keywordForm->HasKeyword(a_formEditorID);
			if (!hasKeyword && race) {
				hasKeyword = race->HasKeyword(a_formEditorID);
			}
			return hasKeyword;
		}
		return false;
	}


	void TESNPC::SetFaceTexture(BGSTextureSet* a_textureSet)
	{
		if (!headRelatedData && a_textureSet) {
			headRelatedData = new HeadRelatedData();
		}

		if (headRelatedData) {
			headRelatedData->faceDetails = a_textureSet;
		}
	}


	void TESNPC::SetHairColor(BGSColorForm* a_hairColor)
	{
		if (!headRelatedData && a_hairColor) {
			headRelatedData = new HeadRelatedData();
		}

		if (headRelatedData) {
			headRelatedData->hairColor = a_hairColor;
		}
	}


	void TESNPC::SetSkinFromTint(NiColorA* a_result, TintMask* a_tintMask, bool a_fromTint)
	{
		using func_t = decltype(&TESNPC::SetSkinFromTint);
		REL::Offset<func_t> func(Offset::TESNPC::SetSkinFromTint);
		return func(this, a_result, a_tintMask, a_fromTint);
	}


	void TESNPC::UpdateNeck(BSFaceGenNiNode* a_faceNode)
	{
		using func_t = decltype(&TESNPC::UpdateNeck);
		REL::Offset<func_t> func(Offset::TESNPC::UpdateNeck);
		return func(this, a_faceNode);
	}
}
