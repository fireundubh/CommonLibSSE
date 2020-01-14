#pragma once

#include "RE/BSString.h"
#include "RE/BSTArray.h"
#include "RE/BSTHashMap.h"
#include "RE/BSTList.h"
#include "RE/FormTypes.h"
#include "RE/NiPoint2.h"
#include "RE/NiSmartPointer.h"
#include "RE/NiTPointerMap.h"
#include "RE/TESForm.h"
#include "RE/TESFullName.h"
#include "RE/TESModel.h"
#include "RE/TESTexture.h"


namespace RE
{
	struct BGSTerrainManager;


	struct WORLD_MAP_DATA	// MNAM
	{
		struct CameraData
		{
			float	minHeight;		// 0
			float	maxHeight;		// 4
			float	initialPitch;	// 8
		};
		STATIC_ASSERT(sizeof(CameraData) == 0xC);


		UInt32		usableWidth;	// 00
		UInt32		usableHeight;	// 04
		SInt16		nwCellX;		// 08
		SInt16		nwCellY;		// 0A
		SInt16		seCellX;		// 0C
		SInt16		seCellY;		// 0E
		CameraData	cameraData;		// 10
	};
	STATIC_ASSERT(sizeof(WORLD_MAP_DATA) == 0x1C);


	struct WORLD_MAP_OFFSET_DATA	// ONAM
	{
		float	fMapScale;		// 00
		float	fMapOffsetX;	// 04
		float	fMapOffsetY;	// 08
		float	fMapOffsetZ;	// 0C
	};
	STATIC_ASSERT(sizeof(WORLD_MAP_OFFSET_DATA) == 0x10);


	class BGSLargeRefData   // RNAM
	{
	public:
		// RNAM format in plugins is cell x,y -> formID + cell that contains refr x,y
		// a lot of RNAM data is for refrs that are actually in adjacent cells, it is currently unknown what behavior this has in game
		BSTHashMap<UInt32, FormID*>	cellFormIDMap;			// 00 - full data merged at runtime, value is an array of FormIDs with array size as the first entry
		BSTHashMap<FormID, UInt32>	formIDCellMap;			// 30 - maps FormID to cell so opposite of above map

		// this filtered version of the full data removes all duplicate RNAM entries and also all entries where cell x,y doesn't match cell that contains refr x,y
		// this is the one actually used for loading large references on cell attach
		BSTHashMap<UInt32, FormID*>	cellFormIDMapFiltered;	// 60
	};
	STATIC_ASSERT(sizeof(BGSLargeRefData) == 0x90);


	class TESWorldSpace :
		public TESForm,		// 000
		public TESFullName,	// 020
		public TESModel		// 030
	{
	public:
		inline static const void* RTTI = RTTI_TESWorldSpace;


		enum { kTypeID = FormType::WorldSpace };


		enum class Flag : UInt8
		{
			kNone = 0,
			kSmallWorld = 1 << 0,
			kCantFastTravel = 1 << 1,
			kNoLODWater = 1 << 3,
			kNoLandscape = 1 << 4,
			kNoSky = 1 << 5,
			kFixedDimensions = 1 << 6,
			kNoGrass = 1 << 7,
		};


		enum class ParentUseFlag : UInt16
		{
			kNone = 0,
			kUseLandData = 1 << 0,
			kUseLODData = 1 << 1,
			kDontUseMapData = 1 << 2,
			kUseWaterData = 1 << 3,
			kUseClimateData = 1 << 4,
			kUseImageSpaceData = 1 << 5,	// unused
			kUseSkyCell = 1 << 6,
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kCantWait = 1 << 19
			};
		};


		struct ShortPoint
		{
			SInt16	x;
			SInt16	y;
		};
		STATIC_ASSERT(sizeof(ShortPoint) == 0x4);


		virtual ~TESWorldSpace();														// 00

		// override (TESForm)
		virtual void		InitializeData() override;									// 04
		virtual void		ClearData() override;										// 05
		virtual bool		Load(TESFile* a_mod) override;								// 06
		virtual bool		LoadPartial(TESFile* a_mod) override;						// 07
		virtual TESForm*	CreateDuplicateForm(void* a_arg1, void* a_arg2) override;	// 09
		virtual bool		FindInFileFast(TESFile* a_mod) override;					// 0C
		virtual void		InitItemImpl() override;									// 13
		virtual const char*	GetFormEditorID() const override;							// 32 - { return editorID.c_str(); }
		virtual bool		SetFormEditorID(const char* a_str) override;				// 33 - { editorID = a_str; }
		virtual bool		IsParentForm() override;									// 34 - { return true; }
		virtual bool		IsFormTypeChild(FormType a_type) override;					// 36

		bool HasMaxHeightData() const;
		TESObjectCELL* GetOrCreateUnk0F8Cell();

		// members
		BSTHashMap<SInt32, TESObjectCELL*>						cellMap;					// 058
		TESObjectCELL*											persistentCell;				// 088
		BGSTerrainManager*										terrainManager;				// 090
		TESClimate*												climate;					// 098 - CNAM
		Flag													flags;						// 0A0 - DATA
		UInt8													unk0A1;						// 0A1 - more flags
		ParentUseFlag											parentUseFlags;				// 0A2 - PNAM
		ShortPoint												fixedCenter;				// 0A4 - WCTR
		BSTHashMap<UInt32, BSTArray<NiPointer<TESObjectREFR>>>	fixedPersistentRefMap;		// 0A8
		BSTArray<NiPointer<TESObjectREFR>>						mobilePersistentRefs;		// 0D8
		NiTPointerMap<UInt32, BSSimpleList<TESObjectREFR*>*>*	overlappedMultiboundMap;	// 0F0
		TESObjectCELL*											skyCell;					// 0F8
		BSTHashMap<FormID, BGSLocation*>						locationMap;				// 100
		void*													unk130;						// 130 - smart ptr
		void*													unk138;						// 138
		void*													unk140;						// 140
		void*													unk148;						// 148 - smart ptr
		void*													unk150;						// 150 - smart ptr
		TESWorldSpace*											parentWorld;				// 158 - WNAM
		BGSLightingTemplate*									lightingTemplate;			// 160 - LTMP
		TESWaterForm*											worldWater;					// 168 - NAM2
		TESWaterForm*											lodWater;					// 170 - NAM3
		float													lodWaterHeight;				// 178 - NAM4
		UInt32													pad17C;						// 17C
		UInt64													unk180;						// 180
		WORLD_MAP_DATA											worldMapData;				// 188 - MNAM
		WORLD_MAP_OFFSET_DATA									worldMapOffsetData;			// 1A4 - ONAM
		UInt32													pad1B4;						// 1B4
		BGSMusicType*											musicType;					// 1B8 - ZNAM
		NiPoint2												minimumCoords;				// 1C0
		NiPoint2												maximumCoords;				// 1C8
		BSTHashMap<UnkKey, UnkValue>							unk1D0;						// 1D0 - BSTHashMap<TESFile*, OFFSET_DATA*> offsetDataMap?
		BSString												editorID;					// 200 - EDID
		float													defaultLandHeight;			// 210 - DNAM~
		float													defaultWaterHeight;			// 214 - ~DNAM
		float													distantLODMult;				// 218 - NAMA
		UInt32													pad21C;						// 21C
		BGSEncounterZone*										encounterZone;				// 220 - XEZN
		BGSLocation*											location;					// 228 - XLCN
		TESTexture												canopyShadowTexture;		// 230 - TNAM
		TESTexture												waterEnvMap;				// 240 - UNAM
		BGSLargeRefData											largeRefData;				// 250 - RNAM
		UInt64													unk2E0;						// 2E0
		BSTHashMap<UnkKey, UnkValue>							unk2E8;						// 2E8
		BSTHashMap<UnkKey, UnkValue>							unk318;						// 318
		float													northRotation;				// 348
		UInt32													pad34C;						// 34C
		SInt8*													maxHeightData;				// 350 - MHDT
	};
	STATIC_ASSERT(sizeof(TESWorldSpace) == 0x358);
}
