#pragma once


namespace RE
{
	template <std::uint32_t FREE_LIST_BITS = 20, std::uint32_t AGE_SHIFT = 6>
	class BSUntypedPointerHandle
	{
	public:
		using value_type = std::uint32_t;


		enum : std::uint32_t
		{
			kFreeListBits = FREE_LIST_BITS,
			kAgeShift = AGE_SHIFT,
		};


		BSUntypedPointerHandle() :
			_handle(0)
		{
			_handle = get_null_handle();
		}


		BSUntypedPointerHandle(const BSUntypedPointerHandle& a_rhs) :
			_handle(a_rhs._handle)
		{
		}


		BSUntypedPointerHandle(BSUntypedPointerHandle&& a_rhs) :
			_handle(std::move(a_rhs._handle))
		{
			a_rhs.reset();
		}


		BSUntypedPointerHandle(value_type a_handle) :
			_handle(a_handle)
		{
		}


		~BSUntypedPointerHandle()
		{
			reset();
		}


		BSUntypedPointerHandle& operator=(const BSUntypedPointerHandle& a_rhs)
		{
			_handle = a_rhs._handle;
			return *this;
		}


		BSUntypedPointerHandle& operator=(BSUntypedPointerHandle&& a_rhs)
		{
			_handle = std::move(a_rhs._handle);
			a_rhs.reset();
			return *this;
		}


		BSUntypedPointerHandle& operator=(value_type a_rhs)
		{
			_handle = a_rhs;
			return *this;
		}


		[[nodiscard]] explicit operator bool() const
		{
			has_value();
		}


		[[nodiscard]] bool has_value() const
		{
			return _handle != get_null_handle();
		}


		[[nodiscard]] value_type value() const
		{
			return _handle;
		}


		void reset()
		{
			_handle = get_null_handle();
		}


		[[nodiscard]] friend bool operator==(const BSUntypedPointerHandle& a_lhs, const BSUntypedPointerHandle& a_rhs)
		{
			return a_lhs.value() == a_rhs.value();
		}


		[[nodiscard]] friend bool operator!=(const BSUntypedPointerHandle& a_lhs, const BSUntypedPointerHandle& a_rhs)
		{
			return !(a_lhs == a_rhs);
		}

	private:
		static std::uint32_t get_null_handle()
		{
			REL::Offset<std::uint32_t*> invalidHandle(Offset::BSUntypedPointerHandle::NullHandle);
			return *invalidHandle;
		}


		// members
		std::uint32_t _handle;	// 0
	};
	static_assert(sizeof(BSUntypedPointerHandle<>) == 0x4);
}
