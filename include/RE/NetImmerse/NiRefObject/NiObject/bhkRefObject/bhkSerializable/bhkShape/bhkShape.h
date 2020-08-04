#pragma once

#include "RE/NetImmerse/NiRefObject/NiObject/bhkRefObject/bhkSerializable/bhkSerializable.h"


namespace RE
{
	class bhkShape : public bhkSerializable
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkShape;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkShape;


		enum class HAVOK_MATERIAL : std::uint32_t
		{
			kStoneBroken = 131151687,
			kWoodLight = 365420259,
			kSnow = 398949039,
			kGravel = 428587608,
			kMetalChain = 438912228,
			kBottle = 493553910,
			kWood = 500811281,
			kSkin = 591247106,
			kSkinDeer = 617099282,
			kBarrel = 732141076,
			kCeramicMedium = 781661019,
			kBasket = 790784366,
			kIce = 873356572,
			kStoneStairs = 899511101,
			kWater = 1024582599,
			kUnknownDraugr = 1028101969,
			kBlade1Hand = 1060167844,
			kBook = 1264672850,
			kCarpet = 1286705471,
			kMetalSolid = 1288358971,
			kAxe1Hand = 1305674443,
			kAmulet = 1440721808,
			kWoodStairs = 1461712277,
			kMud = 1486385281,
			kBoulderSmall = 1550912982,
			kSnowStairs = 1560365355,
			kStoneHeavy = 1570821952,
			kUnknownDragon = 1574477864,
			kUnknownTrap = 1591009235,
			kBowsStaves = 1607128641,
			kWoodAsStairs = 1803571212,
			kGrass = 1848600814,
			kBoulderLarge = 1885326971,
			kStoneAsStairs = 1886078335,
			kBlade2Hand = 2022742644,
			kBottleSmall = 2025794648,
			kSand = 2168343821,
			kMetalHeavy = 2229413539,
			kSabreCatPelt = 2290050264,
			kDragon = 2518321175,
			kBlade1HandSmall = 2617944780,
			kSkinSmall = 2632367422,
			kStoneStairsBroken = 2892392795,
			kSkinLarge = 2965929619,
			kOrganic = 2974920155,
			kBone = 3049421844,
			kWoodHeavy = 3070783559,
			kChain = 3074114406,
			kDirt = 3106094762,
			kArmorLight = 3424720541,
			kShieldLight = 3448167928,
			kCoin = 3589100606,
			kShieldHeavy = 3702389584,
			kArmorHeavy = 3708432437,
			kArrow = 3725505938,
			kGlass = 3739830338,
			kStone = 3741512247,
			kCloth = 3839073443,
			kWard = 3895166727,
			kBlunt2Hand = 3969592277,
			kSwingingBridge = 4239621792,
			kBoulderMedium = 4283869410
		};


		virtual ~bhkShape();  // 00

		// override (bhkSerializable)
		virtual const NiRTTI* GetRTTI() const override;							 // 02
		virtual void		  LoadBinary(NiStream& a_stream) override;			 // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			 // 19 - { bhkSerializable::LinkObject(a_stream); }
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	 // 1A - { return bhkSerializable::RegisterStreamables(a_stream); }
		virtual void		  SaveBinary(NiStream& a_stream) override;			 // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;				 // 1C
		virtual void		  AdjustRefCount(bool a_increment) override;		 // 26

		// add
		virtual void Unk_32(void);	// 32
		virtual void Unk_33(void);	// 33
		virtual void Unk_34(void);	// 34 - { return 0; }
		virtual void Unk_35(void);	// 35


		// members
		HAVOK_MATERIAL material;  // 20
	};
	static_assert(sizeof(bhkShape) == 0x28);
}
