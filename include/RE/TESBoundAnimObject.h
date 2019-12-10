#pragma once

#include "RE/TESBoundObject.h"


namespace RE
{
	class TESBoundAnimObject : public TESBoundObject
	{
	public:
		inline static const void* RTTI = RTTI_TESBoundAnimObject;


		virtual ~TESBoundAnimObject();					// 00

		// override (TESBoundObject)
		virtual bool	CanAnimate() const override;	// 3C - { return true; }
		virtual void	Unk_4B(void) override;			// 4B
	};
	STATIC_ASSERT(sizeof(TESBoundAnimObject) == 0x30);
}
