#pragma once

#include "RE/BSCore/BSAtomic.h"
#include "RE/BSCore/BSTHashMap.h"
#include "RE/BSCore/BSTSingleton.h"


namespace RE
{
	template <
		class T,
		class Key,
		template <class, class> class MissPolicy,
		template <class, class> class InitializationPolicy>
	class BSTObjectDictionary :
		public MissPolicy<T, Key>,															   // 00
		public InitializationPolicy<T, Key>,												   // 08
		public BSTSingletonSDM<BSTObjectDictionary<T, Key, MissPolicy, InitializationPolicy>>  // 10
	{
	public:
		std::uint8_t	   pad11;			   // 11
		std::uint16_t	   pad12;			   // 12
		std::uint32_t	   pad14;			   // 14
		BSTHashMap<Key, T> objectDefinitions;  // 18
		BSSpinLock		   definitionLock;	   // 48
	};
	//static_assert(sizeof(BSTObjectDictionary) == 0x50);
}
