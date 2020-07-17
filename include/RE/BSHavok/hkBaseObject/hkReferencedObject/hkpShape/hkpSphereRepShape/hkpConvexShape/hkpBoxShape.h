#pragma once

#include "RE/BSHavok/hkBaseObject/hkReferencedObject/hkpShape/hkpSphereRepShape/hkpConvexShape/hkpConvexShape.h"
#include "RE/BSHavok/hkVector4.h"


namespace RE
{
	class hkpBoxShape : public hkpConvexShape
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpBoxShape;


		virtual ~hkpBoxShape();	 // 00

		// overwrite
		virtual void			 CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override;	// 02
		virtual SInt32			 CalcSizeForSpu(const CalcSizeForSpuInput& a_input, SInt32 a_spuBufferSizeLeft) const override;		// 06 - { return 64; }
		virtual void			 GetAabbImpl(const hkTransform& a_localToWorld, float a_tolerance, hkAabb& a_out) const override;	// 07
		virtual bool			 CastRayImpl(const hkpShapeRayCastInput& a_input, hkpShapeRayCastOutput& a_output) const override;	// 08
		virtual SInt32			 GetNumCollisionSpheresImpl() override;																// 0B - { return 8; }
		virtual const hkpSphere* GetCollisionSpheresImpl(hkSphere* a_sphereBuffer) override;										// 0C
		virtual void			 GetCentreImpl(hkVector4& a_centreOut) override;													// 0D
		virtual void			 Unk_0E(void) override;																				// 0E
		virtual void			 Unk_0F(void) override;																				// 0F
		virtual void			 Unk_11(void) override;																				// 11

		void SetHalfExtents(const hkVector4& a_halfExtents);


		// members
		UInt32	  pad28;		// 28
		UInt32	  pad2C;		// 2C
		hkVector4 halfExtents;	// 30
	};
	STATIC_ASSERT(sizeof(hkpBoxShape) == 0x40);
}
