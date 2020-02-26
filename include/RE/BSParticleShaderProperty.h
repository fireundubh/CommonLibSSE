#pragma once

#include "RE/BSShaderProperty.h"
#include "RE/BSTArray.h"
#include "RE/NiPoint3.h"
#include "RE/BSParticleShaderGeometry.h"


namespace RE
{
	class NiColorA;
    class NiSourceTexture;

	class BSParticleShaderProperty : public BSShaderProperty
	{
	public:
		inline static const void* RTTI = RTTI_BSParticleShaderProperty;
		inline static const void* Ni_RTTI = NiRTTI_BSParticleShaderProperty;


		virtual ~BSParticleShaderProperty();										        // 00

		// override (BSShaderProperty)
		virtual const NiRTTI*       GetRTTI() const override;						        // 02
        virtual UInt8				InitializeGeometry(BSGeometry* a_geometry) override;    // 27 - { particleShaderGeometry = newGeometry; }
        virtual void			    Unk_2A(void) override;							        // 2A
		virtual void			    Unk_35(void) override;							        // 35 - { return 5; }
        virtual NiSourceTexture*    GetPrimaryTexture() override;							// 37 - { return particleShaderTexture; }


		// members
        UInt8                       unk88;
        bool                        flags;
        bool                        kParticleGreyscaleAlpha;
        char                        unk8B;
        float                       particleLifetime;
        float                       particleLifetimeVariance;
        float                       initialSpeedAlongNormal;
        float                       initialSpeedAlongNormalVariance;
        float                       accelerationAlongNormal;
        float                       initialVelocity1;
        float                       initialVelocity2;
        float                       intialVelocity3;
        float                       acceleration1;
        float                       acceleration2;
        float                       acceleration3;
        float                       birthPositionOffset;
        float                       birthPositionVarianceOffset;
        float                       particleShaderInitialRotation;
        float                       intialRotationVariance;
        float                       rotationSpeed;
        float                       rotationSpeedVariance;
        UInt32                      unkD0;
        float                       animatedStartFrame;
        float                       animatedStartFrameVariance;
        float                       animatedEndFrame;
        float                       animatedEndFrameVariance;
        float                       animatedLoopStartVariance;
        float                       animatedFrameCount;
        float                       animatedFrameCountVariance;
        UInt32                      unkF0;
        float                       colorKey1Time;
        float                       colorKey2Time;
        float                       colorKey3Time;
        NiColorA                    colorKey1;
        NiColorA                    colorKey2;
        NiColorA                    colorKey3;
        float                       scaleKey1;
        float                       scaleKey2;
        float                       scaleKey1Time;
        float                       scaleKey2Time;
        NiPointer<NiSourceTexture>  particleShaderTexture;
        NiPointer<NiSourceTexture>  particlePaletteTexture;
        BSTArray<void*>             unk150;
        BSParticleShaderGeometry*   particleShaderGeometry;
        float                       unk170;
        float                       textureCountU;
        float                       textureCountV;
        NiPoint3                    windPoint;
        float                       explosionWindSpeed;
        UInt32                      unk18C;
        UInt64                      unk190;
	};
	static_assert(sizeof(BSParticleShaderProperty) >= 0x198, "too small");
    static_assert(sizeof(BSParticleShaderProperty) <= 0x198, "too big");
}
