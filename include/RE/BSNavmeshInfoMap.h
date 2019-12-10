#pragma once

#include "RE/BSTSingleton.h"


namespace RE
{
	class BSNavmeshInfoMap : public BSTSingletonExplicit<BSNavmeshInfoMap>
	{
	public:
		inline static const void* RTTI = RTTI_BSNavmeshInfoMap;


		virtual ~BSNavmeshInfoMap();		// 00

		// add
		virtual void	Unk_01(void) = 0;	// 01
		virtual void	Unk_02(void) = 0;	// 02
		virtual void	Unk_03(void) = 0;	// 03
		virtual void	Unk_04(void) = 0;	// 04
		virtual void	Unk_05(void) = 0;	// 05
	};
	STATIC_ASSERT(sizeof(BSNavmeshInfoMap) == 0x8);
}
