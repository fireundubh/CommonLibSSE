#pragma once

#include <cassert>

#include "RE/BSTSingleton.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSDefaultObjectManager :
		public TESForm,											// 000
		public BSTSingletonImplicit<BGSDefaultObjectManager>	// 020
	{
	public:
		inline static const void* RTTI = RTTI_BGSDefaultObjectManager;


		enum { kTypeID = FormType::DefaultObject };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{};
		};


		struct DefaultObjects
		{
			enum DefaultObject
			{
				kWerewolfChange = 0,
				kSittingAngleLimit = 1,
				kAllowPlayerShout = 2,
				kCaps001 = 3,
				kBobbyPin = 4,
				kTG08SkeletonKey = 5,
				kPlayerFaction = 6,
				kIsGuardFaction = 7,
				kMUSExploreTestb = 8,
				kMUSCombat = 9,
				kMUSSpecialDeath = 10,
				kMUSSpecialSuccess = 11,
				kMUSDungeonCleared = 13,
				kEatPackageDefaultFood = 18,
				kLeftHand = 19,
				kRightHand = 20,
				kEitherHand = 21,
				kVoice = 22,
				kPotion = 23,
				kDefaultFootstepSet = 27,
				kMaterialDirt = 28,
				kDragonMarker = 29,
				kDragonMarkerCrashStrip = 30,
				kDefaultCombatstyle = 31,
				kDefaultMasterPackageList = 32,
				kzzzDEFAULTzzzWaitForDialogue = 33,
				kBoss = 34,
				kVirtualLocation = 35,
				kPersistAll = 36,
				kPlayerInventory = 37,
				kEncSabreCat = 38,
				kActionSwimStateChange = 43,
				kActionLook = 44,
				kActionLeftAttack = 45,
				kActionLeftReady = 46,
				kActionLeftRelease = 47,
				kActionLeftInterrupt = 48,
				kActionRightAttack = 49,
				kActionRightReady = 50,
				kActionRightRelease = 51,
				kActionRightInterrupt = 52,
				kActionDualAttack = 53,
				kActionDualRelease = 54,
				kActionActivate = 55,
				kActionJump = 56,
				kActionFall = 57,
				kActionLand = 58,
				kActionSneak = 59,
				kActionVoice = 60,
				kActionVoiceReady = 61,
				kActionVoiceRelease = 62,
				kActionVoiceInterrupt = 63,
				kActionIdle = 64,
				kActionSprintStart = 65,
				kActionSprintStop = 66,
				kActionDraw = 67,
				kActionSheath = 68,
				kActionLeftPowerAttack = 69,
				kActionRightPowerAttack = 70,
				kActionDualPowerAttack = 71,
				kActionStaggerStart = 72,
				kActionBlockHit = 73,
				kActionBlockAnticipate = 74,
				kActionRecoil = 75,
				kActionRecoilLarge = 76,
				kActionBleedoutStart = 77,
				kActionBleedoutStop = 78,
				kActionIdleStop = 79,
				kActionWardHit = 80,
				kActionForceEquip = 81,
				kActionShieldChange = 82,
				kActionPathStart = 83,
				kActionPathEnd = 84,
				kActionLargeMovementDelta = 85,
				kActionFlyStart = 86,
				kActionFlyStop = 87,
				kActionHoverStart = 88,
				kActionHoverStop = 89,
				kActionBumpedInto = 90,
				kActionSummonedStart = 91,
				kActionTalking = 92,
				kActionListen = 93,
				kActionDeath = 94,
				kActionDeathWait = 95,
				kActionIdleWarn = 96,
				kActionMoveStart = 97,
				kActionMoveStop = 98,
				kActionTurnRight = 99,
				kActionTurnLeft = 100,
				kActionTurnStop = 101,
				kActionMoveForward = 102,
				kActionMoveBackward = 103,
				kActionMoveLeft = 104,
				kActionMoveRight = 105,
				kActionResetGraph = 106,
				kActionKnockDown = 107,
				kActionGetUp = 108,
				kActionIdleStopInstant = 109,
				kActionRagdollInstant = 110,
				kActionWaterwalkStart = 111,
				kActionReload = 112,
				kITMGenericUpSD = 113,
				kITMGenericDownSD = 114,
				kITMGenericWeaponUpSD = 115,
				kITMGenericWeaponDownSD = 116,
				kITMGenericArmorUpSD = 117,
				kITMGenericArmorDownSD = 118,
				kITMGenericBookUpSD = 119,
				kITMGenericBookDownSD = 120,
				kITMGenericIngredientUpSD = 121,
				kITMGenericIngredientDownSD = 122,
				kITMGenericIngredientUpFailSD = 124,
				kMAGWardTestBreakSD = 125,
				kMAGWardTestAbsorbSD = 126,
				kMAGWardTestDeflectSD = 127,
				kMAGFailSD = 128,
				kMAGFailShoutSD = 129,
				kUIHealthHeartbeatBLPSD = 130,
				kUIHealthHeartbeatALPSD = 131,
				kLowHealthImod = 132,
				kUIActivateFail = 134,
				kAMBrWindBedWorldMapLP = 135,
				kAudioCategoryVOC = 136,
				kAudioCategoryNonVOC = 137,
				kAudioCategorySFXFadeDuringDialogue = 138,
				kAudioCategoryPausedDuringMenuFade = 139,
				kAudioCategoryPausedDuringMenu = 140,
				kAudioCategoryPausedDuringMenuLoad = 141,
				kAudioCategoryMUS = 142,
				kAudioCategoryAMBr = 143,
				k_NONE = 144,
				kAudioCategoryNPCKillMove = 146,
				kSOMDialogue3DDefault = 147,
				kSOMDialogue2D = 148,
				kSOMMono01400Player1st = 149,
				kSOMMono01400Player3rd = 150,
				kSOMUIDefault = 151,
				kDefaultReverb = 152,
				kAMBUnderwater2DLPM = 153,
				kActorTypeHorse = 155,
				kActorTypeUndead = 156,
				kActorTypeNPC = 157,
				kIsBeastRace = 158,
				kDummy = 159,
				kRaceUseGeometryEmitterForParticles = 160,
				kMustStop = 161,
				kUpdateDuringArchery = 162,
				kDLC2DremoraButlerKeyword = 163,
				kSkinHeadMaleNord = 164,
				kSkinMouth = 165,
				kSkinHeadFemaleNord = 167,
				kISMTween = 170,
				kTravel = 171,
				kMainMenuCell = 172,
				kNPC_Default_MT = 173,
				kNPC_Swimming_MT = 175,
				kNPC_Sneaking_MT = 177,
				kAIControlledNPC_Sprinting_MT = 178,
				kFurnitureSpecial = 179,
				kFurnitureForce1stPerson = 180,
				kFurnitureForce3rdPerson = 181,
				kFurntiureNoPlayerAnim = 182,
				kMAGAlterationTelekinesisGrabSD = 183,
				kMAGAlterationTelekinesisThrowSD = 184,
				kWorldMapWeather = 185,
				kHelpManualPC = 186,
				kHelpManualXBox = 187,
				kDefaultPotion = 199,
				kDefaultPoison = 200,
				kMovable = 202,
				kAbsorbSpellEffect = 203,
				kMaterialsWeapon = 204,
				kMaterialsArmor = 205,
				kMagicDisallowEnchanting = 206,
				kLocTypeHold = 208,
				kCWOwner = 209,
				kCWNeutral = 210,
				kCWSoldier = 211,
				kLocTypeClearable = 212,
				kResourceDestructibleObject = 213,
				kHairColorList = 214,
				kComplexSceneMARKER = 215,
				kReusableSoulGem = 216,
				kActorTypeAnimal = 217,
				kActorTypeDaedra = 218,
				kActorTypeDwarven = 219,
				kisNirnroot = 220,
				kCompanionsFaction = 221,
				kCollegeofWinterholdFaction = 222,
				kThievesGuildFaction = 223,
				kDarkBrotherhoodFaction = 224,
				kJobJarlFaction = 225,
				kHareFaction = 226,
				kPlayerIsVampire = 227,
				kPlayerIsWerewolf = 228,
				kRoadMarker = 229,
				kRaceToScale = 230,
				kVampire = 231,
				kCraftingSmithingForge = 232,
				kCraftingCookpot = 233,
				kCraftingSmelter = 234,
				kCraftingTanningRack = 235,
				kHelpLockpickingPC = 236,
				kHelpSmithingShort = 238,
				kHelpCookingPots = 239,
				kHelpSmeltingShort = 240,
				kHelpTanningShort = 241,
				kHelpEnchantingShort = 243,
				kHelpGrindstoneShort = 244,
				kHelpArmorBenchShort = 245,
				kHelpAlchemyShort = 246,
				kHelpBarterShortPC = 247,
				kHelpLeveling = 248,
				kHelpWorldMapShortPC = 250,
				kHelpJournalShortPC = 251,
				kHelpBarsHealthLow = 252,
				kHelpBarsMagickaLow = 253,
				kHelpBarsStaminaLow = 254,
				kHelpJailTutorial = 255,
				kHelpFollowerCommandTutorial = 256,
				kHelpRechargeShort = 257,
				kHelpFavoritesConsoleShort = 258,
				kHelpManualKinect = 259,
				kDLC2HelpDragonTargetLock = 260,
				kDLC2HelpDragonSwitchTargets = 261,
				kDLC2HelpDragonAttackTarget = 262,
				kLoadScreenIS = 263,
				kWeapMaterialDaedric = 264,
				kWeapMaterialDraugr = 265,
				kWeapMaterialDraugrHoned = 266,
				kWeapMaterialDwarven = 267,
				kWeapMaterialEbony = 268,
				kWeapMaterialElven = 269,
				kWeapMaterialFalmer = 270,
				kWeapMaterialFalmerHoned = 271,
				kWeapMaterialGlass = 272,
				kWeapMaterialImperial = 273,
				kWeapMaterialIron = 274,
				kWeapMaterialOrcish = 275,
				kWeapMaterialSteel = 276,
				kWeapMaterialWood = 277,
				kWeapTypeBoundArrow = 278,
				kArmorMaterialDaedric = 279,
				kArmorMaterialDragonplate = 280,
				kArmorMaterialDragonscale = 281,
				kDLC1WeapMaterialDragonbone = 282,
				kArmorMaterialDwarven = 283,
				kArmorMaterialEbony = 284,
				kArmorMaterialElven = 285,
				kArmorMaterialElvenGilded = 286,
				kArmorMaterialLeather = 287,
				kArmorMaterialGlass = 288,
				kArmorMaterialHide = 289,
				kArmorMaterialImperialLight = 290,
				kArmorMaterialImperialHeavy = 291,
				kArmorMaterialImperialStudded = 292,
				kArmorMaterialIron = 293,
				kArmorMaterialIronBanded = 294,
				kArmorMaterialOrcish = 295,
				kArmorMaterialScaled = 296,
				kArmorMaterialSteel = 297,
				kArmorMaterialSteelPlate = 298,
				kArmorMaterialStormcloak = 299,
				kArmorMaterialStudded = 300,
				kBYOHHouseCraftingCategoryBuilding = 301,
				kBYOHHouseCraftingCategoryContainers = 302,
				kBYOHHouseCraftingCategoryFurniture = 303,
				kBYOHHouseCraftingCategoryWeaponRacks = 304,
				kBYOHHouseCraftingCategoryShelf = 305,
				kBYOHHouseCraftingCategoryExterior = 306,
				kBYOHHouseCraftingCategorySmithing = 307,
				kDLC1LD_CraftingMaterialAetherium = 310,
				kArmorJewelry = 311,
				kArmorCuirass = 312,
				kBlackPlane01 = 313,
				kSnowLODMaterial = 314,
				kSnowLODMaterialHD = 315,
				kAshLODMaterialMtns1P = 316,
				kAshMaterialSolstheimMtns1P = 317,
				kDialogueFollower = 318,
				kPotentialFollowerFaction = 319,
				kDLC1WerewolfPerkPoints = 320,
				kDLC1VampirePerkPoints = 321,
				kSurvival_ArmorCold = 329,
				kSurvival_ArmorWarm = 330,
				kArmorGauntlets = 331,
				kClothingHands = 332,
				kArmorBoots = 333,
				kClothingFeet = 334,
				kClothingBody = 336,
				kArmorHelmet = 337,
				kClothingHead = 338,
				kWerewolfBeastRace = 339,
				kDLC1VampireBeastRace = 340,
				kDLC1VampireSpellsPowers = 341,
				kDLC2TameDragonBadLocations = 342,
				kDLC2TameDragonAllowedWorldspaces = 343,
				kDLC2DRAllowedSpells = 344,
				kDLC2DRRestrictedSpells = 345,
				kDLC2DragonMountKeyword = 346,
				kDLC1VampireLordCape = 347,
				kEncSailorNordM = 348,
				kDLC1AurielsConditionalExplosionKeyword = 349,
				kDLC1VampireFeedNoCrimeFaction = 350,
				kTamriel = 351,
				kDLC2ArmorMaterialBonemoldLight = 352,
				kDLC2ArmorMaterialChitinLight = 353,
				kDLC2ArmorMaterialNordicLight = 354,
				kDLC2ArmorMaterialStalhrimLight = 355,
				kDLC2TameDragonFastFlyingWorldspaces = 356,
				kDLC2ArmorMaterialBonemoldHeavy = 357,
				kDLC2ArmorMaterialChitinHeavy = 358,
				kDLC2ArmorMaterialNordicHeavy = 359,
				kDLC2ArmorMaterialStalhrimHeavy = 360,
				kDLC2WeaponMaterialNordic = 361,
				kDLC2WeaponMaterialStalhrim = 362,

				kTotal = 364
			};
		};
		using DefaultObject = DefaultObjects::DefaultObject;


		virtual ~BGSDefaultObjectManager();				// 00

		// override (TESForm)
		virtual bool	Load(TESFile* a_mod) override;	// 06
		virtual void	InitItemImpl() override;		// 13

		static BGSDefaultObjectManager* GetSingleton();

		TESForm*				GetObject(std::size_t a_idx);
		template <class T> T*	GetObject(std::size_t a_idx);


		// members
		TESForm*	objects[DefaultObjects::kTotal];		// 020 - DNAM
		bool		loadedStates[DefaultObjects::kTotal];	// B80
		UInt32		padCEC;									// CEC
	};
	STATIC_ASSERT(sizeof(BGSDefaultObjectManager) == 0xCF0);


	template <class T>
	inline T* BGSDefaultObjectManager::GetObject(std::size_t a_idx)
	{
		auto obj = GetObject(a_idx);
		if (obj) {
			bool isType = obj->Is(static_cast<FormType>(T::kTypeID));
			assert(isType);
			return isType ? static_cast<T*>(obj) : 0;
		} else {
			return 0;
		}
	}
}
