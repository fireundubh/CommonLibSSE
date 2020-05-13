#pragma once


namespace RE
{
	class IMovementControllerRegisterInterface
	{
	public:
		inline static constexpr auto RTTI = RTTI_IMovementControllerRegisterInterface;


		virtual ~IMovementControllerRegisterInterface();  // 00

		// add
		virtual void Unk_01(void) = 0;									// 01
		virtual void Unk_02(const BSFixedString& a_movementState) = 0;	// 02
		virtual void Unk_03(const BSFixedString& a_movementState) = 0;	// 03
		virtual void Unk_04(void) = 0;									// 04
	};
	STATIC_ASSERT(sizeof(IMovementControllerRegisterInterface) == 0x8);
}
