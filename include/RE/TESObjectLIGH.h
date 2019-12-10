#pragma once

#include "RE/BGSDestructibleObjectForm.h"
#include "RE/BGSEquipType.h"
#include "RE/BGSMessageIcon.h"
#include "RE/Color.h"
#include "RE/FormTypes.h"
#include "RE/TESBoundAnimObject.h"
#include "RE/TESFullName.h"
#include "RE/TESIcon.h"
#include "RE/TESModelTextureSwap.h"
#include "RE/TESValueForm.h"
#include "RE/TESWeightForm.h"


namespace RE
{
	class TESObjectLIGH :
		public TESBoundAnimObject,			// 000
		public TESFullName,					// 030
		public TESModelTextureSwap,			// 040
		public TESIcon,						// 078
		public BGSMessageIcon,				// 088
		public TESWeightForm,				// 0A0
		public TESValueForm,				// 0B0
		public BGSDestructibleObjectForm,	// 0C0
		public BGSEquipType					// 0D0
	{
	public:
		inline static const void* RTTI = RTTI_TESObjectLIGH;


		enum { kTypeID = FormType::Light };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kRandomAnimStart = 1 << 16,
				kPortalStrict = 1 << 17,
				kObstacle = 1 << 25
			};
		};


		struct Data	// DATA
		{
			enum class Flag : UInt32
			{
				kFlag_Dynamic = 0x00000001,
				kFlag_Carryable = 0x00000002,
				kFlag_Negative = 0x00000004,
				kFlag_Flicker = 0x00000008,
				kFlag_Unk00000010 = 0x00000010,
				kFlag_OffByDefault = 0x00000020,
				kFlag_FlickerSlow = 0x00000040,
				kFlag_Pulse = 0x00000080,
				kFlag_PulseSlow = 0x00000100,
				kFlag_TypeSpot = 0x00000200,
				kFlag_TypeSpotShadow = 0x00000400,
				kFlag_TypeHemiShadow = 0x00000800,
				kFlag_TypeOmniShadow = 0x00001000,
				kFlag_PortalStrict = 0x00002000,
				//
				kFlag_TypeOmni = 0,
				kFlags_Type = kFlag_TypeSpot | kFlag_TypeSpotShadow | kFlag_TypeHemiShadow | kFlag_TypeOmniShadow,
			};


			struct FlickerEffect
			{
				float GetPeriod() const;


				// members
				float	period;				// 0 - CK value * 100
				float	intensityAmplitude;	// 4
				float	movementAmplitude;	// 8
			};
			STATIC_ASSERT(sizeof(FlickerEffect) == 0xC);


			// members
			SInt32			time;			// 00
			UInt32			radius;			// 04
			Color			color;			// 08
			Flag			flags;			// 0C
			float			fallofExponent;	// 10
			float			fov;			// 14
			float			nearClip;		// 18
			FlickerEffect	flickerEffect;	// 1C
		};
		STATIC_ASSERT(sizeof(Data) == 0x28);


		virtual ~TESObjectLIGH();																																	// 00

		// override (TESBoundAnimObject)
		virtual void	InitDefaults() override;																													// 04
		virtual bool	LoadForm(TESFile* a_mod) override;																											// 06
		virtual void	SaveBuffer(BGSSaveFormBuffer* a_buf) override;																								// 0E
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf) override;																								// 0F
		virtual void	InitItem() override;																														// 13
		virtual bool	ActivateReference(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, UInt64 a_arg4, SInt32 a_targetCount) override;	// 37
		virtual void	Unk_41(void) override;																														// 41
		virtual void	Unk_47(void) override;																														// 47
		virtual void	Unk_4A(void) override;																														// 4A

		bool			CanBeCarried() const;


		// members
		Data					data;		// 0E0 - DATA
		float					fadeValue;	// 108 - FNAM
		UInt32					pad10C;		// 10C
		BGSSoundDescriptorForm*	sound;		// 110 - SNAM
		UInt64					unk118;		// 118
		UInt64					unk120;		// 120
		BGSLensFlare*			unk128;		// 128
	};
	STATIC_ASSERT(sizeof(TESObjectLIGH) == 0x130);
}
