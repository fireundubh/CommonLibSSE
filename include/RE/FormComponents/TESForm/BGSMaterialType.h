#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/TESForm.h"
#include "RE/NetImmerse/NiColor.h"


namespace RE
{
	enum class MATERIAL_ID : std::uint32_t
	{
		kNone = 0,
		kStoneBroken = 131151687,
		kBlockBlade1Hand = 165778930,
		kMeat = 220124585,
		kCarriageWheel = 322207473,
		kMetalLight = 346811165,
		kWoodLight = 365420259,
		kSnow = 398949039,
		kGravel = 428587608,
		kChainMetal = 438912228,
		kBottle = 493553910,
		kWood = 500811281,
		kAsh = 534864873,
		kSkin = 591247106,
		kBlockBlunt = 593401068,
		kDLC1DeerSkin = 617099282,
		kInsect = 668408902,
		kBarrel = 732141076,
		kCeramicMedium = 781661019,
		kBasket = 790784366,
		kIce = 873356572,
		kGlassStairs = 880200008,
		kStoneStairs = 899511101,
		kWater = 1024582599,
		kDraugrSkeleton = 1028101969,
		kBlade1Hand = 1060167844,
		kBook = 1264672850,
		kCarpet = 1286705471,
		kMetalSolid = 1288358971,
		kAxe1Hand = 1305674443,
		kBlockBlade2Hand = 1312943906,
		kOrganicLarge = 1322093133,
		kAmulet = 1440721808,
		kWoodStairs = 1461712277,
		kMud = 1486385281,
		kBoulderSmall = 1550912982,
		kSnowStairs = 1560365355,
		kStoneHeavy = 1570821952,
		kDragonSkeleton = 1574477864,
		kTrap = 1591009235,
		kBowsStaves = 1607128641,
		kAlduin = 1730220269,
		kBlockBowsStaves = 1763418903,
		kWoodAsStairs = 1803571212,
		kSteelGreatSword = 1820198263,
		kGrass = 1848600814,
		kBoulderLarge = 1885326971,
		kStoneAsStairs = 1886078335,
		kBlade2Hand = 2022742644,
		kBottleSmall = 2025794648,
		kBoneActor = 2058949504,
		kSand = 2168343821,
		kMetalHeavy = 2229413539,
		kDLC1SabreCatPelt = 2290050264,
		kIceForm = 2431524493,
		kDragon = 2518321175,
		kBlade1HandSmall = 2617944780,
		kSkinSmall = 2632367422,
		kPotsPans = 2742858142,
		kSkinSkeleton = 2821299363,
		kBlunt1Hand = 2872791301,
		kStoneStairsBroken = 2892392795,
		kSkinLarge = 2965929619,
		kOrganic = 2974920155,
		kBone = 3049421844,
		kWoodHeavy = 3070783559,
		kChain = 3074114406,
		kDirt = 3106094762,
		kGhost = 3312543676,
		kSkinMetalLarge = 3387452107,
		kBlockAxe = 3400476823,
		kArmorLight = 3424720541,
		kShieldLight = 3448167928,
		kCoin = 3589100606,
		kBlockBlunt2Hand = 3662306947,
		kShieldHeavy = 3702389584,
		kArmorHeavy = 3708432437,
		kArrow = 3725505938,
		kGlass = 3739830338,
		kStone = 3741512247,
		kWaterPuddle = 3764646153,
		kCloth = 3839073443,
		kSkinMetalSmall = 3855001958,
		kWard = 3895166727,
		kWeb = 3934839107,
		kTrailerSteelSword = 3941234649,
		kBlunt2Hand = 3969592277,
		kDLC1SwingingBridge = 4239621792,
		kBoulderMedium = 4283869410
	};


	class BGSMaterialType : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMaterialType;
		inline static constexpr auto FORMTYPE = FormType::MaterialType;


		enum class FLAG
		{
			kNone = 0,
			kStairs = 1 << 0,
			kArrowsStick = 1 << 1
		};


		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSMaterialType();	 // 00

		// override (TESForm)
		virtual void ClearData() override;			 // 04
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13

		static BGSMaterialType* GetMaterialType(MATERIAL_ID a_matID);


		// members
		BGSMaterialType*					  parentType;		   // 20 - PNAM
		BSFixedString						  materialName;		   // 28 - MNAM
		MATERIAL_ID							  materialID;		   // 30
		NiColor								  materialColor;	   // 34 - CNAM
		float								  buoyancy;			   // 40 - BNAM
		stl::enumeration<FLAG, std::uint32_t> flags;			   // 44 - FNAM
		BGSImpactDataSet*					  havokImpactDataSet;  // 48 - HNAM
	};
	static_assert(sizeof(BGSMaterialType) == 0x50);
}
