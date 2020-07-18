#pragma once

#include "RE/Scaleform/FxGameDelegate/FxDelegate.h"
#include "RE/Scaleform/FxGameDelegate/FxDelegateHandler.h"


namespace RE
{
	class AddCallbackVisitor : public FxDelegateHandler::CallbackProcessor
	{
	public:
		inline static constexpr auto RTTI = RTTI_AddCallbackVisitor;


		AddCallbackVisitor(FxDelegateHandler* a_handler, FxDelegate::CallbackHash* a_hash);
		virtual ~AddCallbackVisitor() = default;  // 00

		// override (FxDelegateHandler::CallbackProcessor)
		virtual void Process(const GString& a_methodName, FxDelegateHandler::CallbackFn* a_method) override;  // 01


		// members
		FxDelegateHandler*		  handler;	// 08
		FxDelegate::CallbackHash* hash;		// 10
	};
	static_assert(sizeof(AddCallbackVisitor) == 0x18);
}
