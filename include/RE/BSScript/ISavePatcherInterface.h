#pragma once


namespace RE
{
	namespace BSScript
	{
		class IVirtualMachine;
		class StackFrame;


		class ISavePatcherInterface
		{
		public:
			inline static const void* RTTI = RTTI_BSScript__ISavePatcherInterface;


			virtual ~ISavePatcherInterface();														// 00

			// add
			virtual void PatchStackFrame(StackFrame* a_stackFrame, IVirtualMachine* a_vm) = 0;		// 01
		};
		STATIC_ASSERT(sizeof(ISavePatcherInterface) == 0x8);
	}
}
