#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class NiRefObject;


	class ExtraLight : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraLight;


		enum { kExtraTypeID = ExtraDataType::kLight };


		struct Data
		{
			NiPointer<NiRefObject>	unk00;	// 00
			UInt64					unk08;	// 08
		};
		STATIC_ASSERT(sizeof(Data) == 0x10);


		virtual ~ExtraLight();							// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kLight; }


		// members
		Data* unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraLight) == 0x18);
}
