#pragma once

#include "RE/BSHavok/hkBaseObject/hkReferencedObject/hkpShape/hkpShape.h"


namespace RE
{
	class hkpSphere;


	class hkpSphereRepShape : public hkpShape
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpSphereRepShape;


		virtual ~hkpSphereRepShape();  // 00

		// add
		virtual SInt32			 GetNumCollisionSpheresImpl() = 0;						 // 0B
		virtual const hkpSphere* GetCollisionSpheresImpl(hkSphere* a_sphereBuffer) = 0;	 // 0C

	};
	STATIC_ASSERT(sizeof(hkpSphereRepShape) == 0x20);
}
