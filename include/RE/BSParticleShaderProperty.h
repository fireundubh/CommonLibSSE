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
		virtual UInt8			 InitializeGeometry(BSGeometry* a_geometry) override;  // 27 - { particleShaderGeometry = newGeometry; }
		virtual void			 Unk_2A(void) override;								   // 2A
		virtual void			 Unk_35(void) override;								   // 35 - { return 5; }
		virtual NiSourceTexture* GetPrimaryTexture() override;						   // 37 - { return particleShaderTexture; }


		// members
		bool								useWorldSpace;					  // 88
		bool								particleGreyscaleAlpha;			  // 8A
		UInt8								unk8B;							  // 8B
		float								particleLifetime;				  // 8C
		float								particleLifetimeVariance;		  // 90
		float								initialSpeedAlongNormal;		  // 94
		float								initialSpeedAlongNormalVariance;  // 98
		float								accelerationAlongNormal;		  // 9C
		float								initialVelocity1;				  // A0
		float								initialVelocity2;				  // A4
		float								intialVelocity3;				  // A8
		float								acceleration1;					  // AC
		float								acceleration2;					  // B0
		float								acceleration3;					  // B4
		float								birthPositionOffset;			  // B8
		float								birthPositionVarianceOffset;	  // BC
		float								particleShaderInitialRotation;	  // C0
		float								intialRotationVariance;			  // C4
		float								rotationSpeed;					  // C8
		float								rotationSpeedVariance;			  // CC
		UInt32								unkD0;							  //	D0
		float								animatedStartFrame;				  // D4
		float								animatedStartFrameVariance;		  // D8
		float								animatedEndFrame;				  // DC
		float								animatedEndFrameVariance;		  // E0
		float								animatedLoopStartVariance;		  // E4
		float								animatedFrameCount;				  // E8
		float								animatedFrameCountVariance;		  // EC
		UInt32								colorScale;						  // F0
		float								colorKey1Time;					  // F4
		float								colorKey2Time;					  // F8
		float								colorKey3Time;					  // FC
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
