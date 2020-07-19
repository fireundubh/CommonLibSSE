#pragma once

#include "RE/BSCore/BSAtomic.h"
#include "RE/BSCore/BSTEvent.h"
#include "RE/BSCore/BSTHashMap.h"


namespace RE
{
	namespace BSScript
	{
		struct LogEvent;


		class ErrorLogger : public BSTEventSource<LogEvent>
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSScript__ErrorLogger;


			enum class Severity
			{
				kInfo,
				kWarning,
				kError,
				kFatal
			};


			struct PerThreadErrorCounts
			{
			public:
				// members
				std::uint32_t fatalCount;	 // 0
				std::uint32_t errorCount;	 // 4
				std::uint32_t warningCount;	 // 8
			};
			static_assert(sizeof(PerThreadErrorCounts) == 0xC);


			virtual ~ErrorLogger();	 // 00

			// add
			virtual void PostErrorImpl(const char* a_message, Severity a_severity) = 0;	 // 01
			virtual void ResetImpl();													 // 02 - { return; }


			// members
			BSSpinLock										threadErrorsLock;  // 60
			BSTHashMap<std::uint32_t, PerThreadErrorCounts> threadErrors;	   // 68
		};
		static_assert(sizeof(ErrorLogger) == 0x98);
	}
}
