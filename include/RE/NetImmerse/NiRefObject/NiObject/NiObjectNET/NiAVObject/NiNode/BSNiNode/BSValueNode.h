#pragma once

#include "RE/BSNiNode.h"

#include "RE/NiSmartPointer.h"


namespace RE
{
	class BSMasterParticleSystem;


	class BSValueNode : public BSNiNode
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSValueNode;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSValueNode;


		enum class Flag : UInt8
		{
			kBillboardWorldZ = 0,
			kUsePlayerAdjust = 1
		};


		virtual ~BSValueNode();	 // 00

		// override (BSNiNode)
		virtual const NiRTTI* GetRTTI() const override;									// 02
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;		// 17
		virtual void		  LoadBinary(NiStream& a_stream) override;					// 18 - { return; }
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;			// 1A
		virtual void		  SaveBinary(NiStream& a_stream) override;					// 1B
		virtual bool		  IsEqual(NiObject* a_object) override;						// 1C
		virtual void		  UpdateTransformAndBounds(NiUpdateData& a_data) override;	// 31

		//add
		virtual bool Unk_3E(void);	//3E


		// members
		Flag							  flags;		   // 128
		SInt32							  value;		   // 12C
		NiPointer<BSMasterParticleSystem> particleSystem;  // 130
	};
	STATIC_ASSERT(sizeof(BSValueNode) == 0x138);
}
