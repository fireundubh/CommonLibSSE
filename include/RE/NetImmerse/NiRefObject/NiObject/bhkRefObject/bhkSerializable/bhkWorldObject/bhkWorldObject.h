#pragma once

#include "RE/NetImmerse/NiRefObject/NiObject/bhkRefObject/bhkSerializable/bhkSerializable.h"


namespace RE
{
	class bhkWorld;


	class bhkWorldObject : public bhkSerializable
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkWorldObject;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkWorldObject;


		virtual ~bhkWorldObject();	// 00

		// override (bhkSerializable)
		virtual const NiRTTI* GetRTTI() const override;							 // 02
		virtual void		  LoadBinary(NiStream& a_stream) override;			 // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			 // 19
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	 // 1A
		virtual void		  SaveBinary(NiStream& a_stream) override;			 // 1B
		virtual void		  AdjustRefCount(bool a_increment) override;		 // 26
		virtual hkpWorld*	  GetWorld1() override;								 // 27 - { return world; }
		virtual ahkpWorld*	  GetWorld2() override;								 // 28 - { return world; }
		virtual void		  Unk_29(void) override;							 // 29

		// add
		virtual void Unk_32(void);	// 32 - { return Unk_29(); }

		bhkWorld* GetbhkWorld();


		// members
		hkpWorld* world;  // 20
	};
	static_assert(sizeof(bhkWorldObject) == 0x28);
}
