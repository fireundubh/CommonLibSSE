#pragma once

#include "RE/NiAVObject.h"
#include "RE/NiFrustum.h"
#include "RE/NiRect.h"


namespace RE
{
	class NiCamera : public NiAVObject
	{
	public:
		inline static const void* RTTI = RTTI_NiCamera;
		inline static const void* Ni_RTTI = NiRTTI_NiCamera;


		virtual ~NiCamera();														// 00

		// override (NiAVObject)
		virtual const NiRTTI*	GetRTTI() const override;							// 02
		virtual NiObject*		CreateClone(NiCloningProcess& a_cloning) override;	// 17 - { return this; }
		virtual void			LoadBinary(NiStream& a_stream) override;			// 18 - { return; }
		virtual void			LinkObject(NiStream& a_stream) override;			// 19 - { return; }
		virtual bool			RegisterStreamables(NiStream& a_stream) override;	// 1A
		virtual void			SaveBinary(NiStream& a_stream) override;			// 1B - { return; }
		virtual bool			IsEqual(NiObject* a_object) override;				// 1C
		virtual void			UpdateWorldBound() override;						// 2F - { return; }
		virtual void			UpdateWorldData(NiUpdateData* a_data) override;		// 30


		// members
		float			worldToCam[4][4];	// 110
		NiFrustum		viewFrustum;		// 150
		float			minNearPlaneDist;	// 16C
		float			maxFarNearRatio;	// 170
		NiRect<float>	port;				// 174
		float			lodAdjust;			// 184
	};
	STATIC_ASSERT(sizeof(NiCamera) == 0x188);
}
