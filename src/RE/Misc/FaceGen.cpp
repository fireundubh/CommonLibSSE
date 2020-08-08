#include "RE/Misc/FaceGen.h"


namespace RE
{
	FaceGen* FaceGen::GetSingleton()
	{
		REL::Relocation<FaceGen**> singleton{ Offset::FaceGen::Singleton };
		return *singleton;
	}


	void FaceGen::RegenerateHead(BSFaceGenNiNode* a_headNode, BGSHeadPart* a_head, TESNPC* a_npc)
	{
		using func_t = decltype(&FaceGen::RegenerateHead);
		REL::Relocation<func_t> func{ Offset::FaceGen::RegenerateHead };
		return func(this, a_headNode, a_head, a_npc);
	}
}