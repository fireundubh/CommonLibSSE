#pragma once

#include "RE/NiRefObject.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class BSParticleShaderProperty;


	class BSParticleShaderEmitter : public NiRefObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSParticleShaderEmitter;


		enum class PARTICLE_EMITTER_TYPE : UInt16
		{
			kGeometry = 0,
			kCollision = 1,
			kRay = 2,
			kSnow = 3,
			kRain = 4
		};


		class TextureAnimInfo
		{
		public:
			float  currentFrame;  // 00
			UInt32 totalFrames;	  // 04
		};
		STATIC_ASSERT(sizeof(TextureAnimInfo) == 0x08);


		struct ParticleData
		{
		public:
			float XPos;			  // 00
			float YPos;			  // 04
			float ZPos;			  // 08
			float age;			  // 0C
			float XVel;			  // 10
			float YVel;			  // 14
			float ZVel;			  // 18
			float lifeAdjust;	  // 1C
			float rotationStart;  // 20
			float rotationSpeed;  // 24
			float speedMult;	  // 28
			UInt8 texCoordU;	  // 29
			UInt8 texCoordV;	  // 2A
			UInt8 vertexX;		  // 2B
			UInt8 vertexY;		  // 2C
		};
		STATIC_ASSERT(sizeof(ParticleData) == 0x30);


		virtual ~BSParticleShaderEmitter();	 // 00

		// add
		virtual void Unk_02(void);		// 02
		virtual void Unk_03(void) = 0;	// 03


		// members
		BSParticleShaderProperty* property;			 // 10
		PARTICLE_EMITTER_TYPE	  emitterType;		 // 18
		UInt16					  particleCount;	 // 1A
		float					  alpha;			 // 1C
		float					  generateReminder;	 // 20
		float					  maxParticleRatio;	 // 24
		TextureAnimInfo*		  textureAnims;		 // 28
		ParticleData			  instanceData[78];	 // 30
	};
	STATIC_ASSERT(sizeof(BSParticleShaderEmitter) == 0xED0);
};
