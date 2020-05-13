#pragma once

#include "RE/BSShaderProperty.h"
#include "RE/BSTArray.h"
#include "RE/NiColor.h"
#include "RE/NiPoint3.h"


namespace RE
{
	class NiSourceTexture;
	class BSParticleShaderGeometry;


	class BSParticleShaderProperty : public BSShaderProperty
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSParticleShaderProperty;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSParticleShaderProperty;


		virtual ~BSParticleShaderProperty();  // 00

		// override (BSShaderProperty)
		virtual const NiRTTI*	 GetRTTI() const override;							   // 02
		virtual bool			 InitializeGeometry(BSGeometry* a_geometry) override;  // 27 - { particleShaderGeometry = newGeometry; }
		virtual void			 Unk_2A(void) override;								   // 2A
		virtual void			 Unk_35(void) override;								   // 35 - { return 5; }
		virtual NiSourceTexture* GetPrimaryTexture() override;						   // 37 - { return particleShaderTexture; }


		// members
		bool								useWorldSpace;					  // 088
		bool								particleGreyscaleAlpha;			  // 08A
		UInt8								unk8B;							  // 08B
		float								particleLifetime;				  // 08C
		float								particleLifetimeVariance;		  // 090
		float								initialSpeedAlongNormal;		  // 094
		float								initialSpeedAlongNormalVariance;  // 098
		float								accelerationAlongNormal;		  // 09C
		float								initialVelocity1;				  // 0A0
		float								initialVelocity2;				  // 0A4
		float								intialVelocity3;				  // 0A8
		float								acceleration1;					  // 0AC
		float								acceleration2;					  // 0B0
		float								acceleration3;					  // 0B4
		float								birthPositionOffset;			  // 0B8
		float								birthPositionVarianceOffset;	  // 0BC
		float								particleShaderInitialRotation;	  // 0C0
		float								intialRotationVariance;			  // 0C4
		float								rotationSpeed;					  // 0C8
		float								rotationSpeedVariance;			  // 0CC
		UInt32								unkD0;							  // 0D0
		float								animatedStartFrame;				  // 0D4
		float								animatedStartFrameVariance;		  // 0D8
		float								animatedEndFrame;				  // 0DC
		float								animatedEndFrameVariance;		  // 0E0
		float								animatedLoopStartVariance;		  // 0E4
		float								animatedFrameCount;				  // 0E8
		float								animatedFrameCountVariance;		  // 0EC
		UInt32								colorScale;						  // 0F0
		float								colorKey1Time;					  // 0F4
		float								colorKey2Time;					  // 0F8
		float								colorKey3Time;					  // 0FC
		NiColorA							colorKey1;						  // 100
		NiColorA							colorKey2;						  // 110
		NiColorA							colorKey3;						  // 120
		float								scaleKey1;						  // 130
		float								scaleKey2;						  // 134
		float								scaleKey1Time;					  // 138
		float								scaleKey2Time;					  // 13C
		NiPointer<NiSourceTexture>			particleShaderTexture;			  // 140
		NiPointer<NiSourceTexture>			particlePaletteTexture;			  // 148
		BSTArray<void*>						unk150;							  // 150
		NiPointer<BSParticleShaderGeometry> particleShaderGeometry;			  // 168
		float								unk170;							  // 170
		float								textureCountU;					  // 174
		float								textureCountV;					  // 178
		NiPoint3							windPoint;						  // 17C
		float								explosionWindSpeed;				  // 188
		UInt32								unk18C;							  // 18C
		UInt64								unk190;							  // 190
	};
	STATIC_ASSERT(sizeof(BSParticleShaderProperty) == 0x198);
}
