#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class DialogueItem;
	class TESTopic;


	class ExtraSayToTopicInfo : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraSayToTopicInfo;


		enum { kExtraTypeID = ExtraDataType::kSayTopicInfo };


		virtual ~ExtraSayToTopicInfo();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kSayTopicInfo; }


		// members
		TESTopic*		topic;					// 10
		UInt8			unk18;					// 18
		UInt8			pad19;					// 19
		UInt16			pad1A;					// 1A
		float			subtitleSpeechDelay;	// 1C
		void*			exclusiveBranch;		// 20
		SInt32			unk28;					// 28
		UInt8			unk2C;					// 2C
		UInt8			pad2D;					// 2D
		UInt16			pad2E;					// 2E
		UInt32			unk30;					// 30
		UInt32			pad34;					// 34
		DialogueItem*	dialogueData;			// 38
	};
	STATIC_ASSERT(sizeof(ExtraSayToTopicInfo) == 0x40);
}
