#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class NiRefObject;


	class ExtraEditorRef3DData : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraEditorRef3DData;


		enum { kExtraTypeID = ExtraDataType::kEditorRef3DData };


		virtual ~ExtraEditorRef3DData();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kEditorRef3DData; }


		// members
		NiPointer<NiRefObject>	unk10;	// 10
		NiPointer<NiRefObject>	unk18;	// 18
	};
	STATIC_ASSERT(sizeof(ExtraEditorRef3DData) == 0x20);
}
