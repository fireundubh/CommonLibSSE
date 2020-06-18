#pragma once

#include "REL/SafeWrite.h"
#include "REL/Version.h"


namespace RE
{
	namespace RTTI
	{
		struct CompleteObjectLocator;
		struct TypeDescriptor;
	}
}


namespace REL
{
	namespace Impl
	{
		template <class T>
		class span
		{
		public:
			using element_type = T;
			using value_type = std::remove_cv_t<T>;
			using size_type = std::size_t;
			using difference_type = std::ptrdiff_t;
			using pointer = element_type*;
			using const_pointer = const element_type*;
			using reference = element_type&;
			using const_reference = const element_type&;

			constexpr span() noexcept :
				_data(nullptr),
				_size(0)
			{}

			constexpr span(pointer a_data, size_type a_count) :
				_data(a_data),
				_size(a_count)
			{}

			constexpr span(const span& a_rhs) noexcept :
				_data(a_rhs._data),
				_size(a_rhs._size)
			{}

			~span() noexcept = default;

			[[nodiscard]] constexpr reference front() const { return operator[](0); }

			[[nodiscard]] constexpr reference back() const { return operator[](size() - 1); }

			[[nodiscard]] constexpr reference operator[](size_type a_pos) const
			{
				assert(a_pos < size());
				return data()[a_pos];
			}

			[[nodiscard]] constexpr pointer data() const noexcept { return _data; }

			[[nodiscard]] size_type size() const noexcept { return _size; }

			[[nodiscard]] constexpr bool empty() const noexcept { return size() == 0; }

		private:
			pointer	  _data;
			size_type _size;
		};

		template <class T>
		span(T* a_data, std::size_t a_count) -> span<T>;


		template <class T>
		class MemoryMap
		{
		public:
			using value_type = T;
			using size_type = std::size_t;
			using reference = value_type&;
			using const_reference = const value_type&;
			using pointer = value_type*;
			using const_pointer = const value_type*;

			MemoryMap() noexcept :
				_handle(nullptr),
				_size(0),
				_data(nullptr)
			{}

			MemoryMap(const MemoryMap&) = delete;

			MemoryMap(MemoryMap&& a_rhs) noexcept :
				_handle(std::move(a_rhs._handle)),
				_size(std::move(a_rhs._size)),
				_data(std::move(a_rhs._data))
			{
				a_rhs._handle = nullptr;
				a_rhs._size = 0;
				a_rhs._data = nullptr;
			}

			MemoryMap(const char* a_name, size_type a_size) :
				_handle(nullptr),
				_size(0),
				_data(nullptr)
			{
				open(a_name, a_size);
			}

			~MemoryMap()
			{
				close();
			}

			MemoryMap& operator=(const MemoryMap&) = delete;

			MemoryMap& operator=(MemoryMap&& a_rhs) noexcept
			{
				if (this != std::addressof(a_rhs)) {
					_handle = std::move(a_rhs._handle);
					a_rhs._handle = nullptr;

					_size = std::move(a_rhs._size);
					a_rhs._size = 0;

					_data = std::move(a_rhs._data);
					a_rhs._data = nullptr;
				}
				return *this;
			}

			MemoryMap& operator=(const std::vector<value_type>& a_rhs)
			{
				auto elemsToCopy = std::min<size_type>(size(), a_rhs.size());
				if (elemsToCopy > 0) {
					std::memcpy(data(), a_rhs.data(), elemsToCopy * sizeof(size_type));
				}
				return *this;
			}

			reference operator[](size_type a_idx) noexcept
			{
				assert(a_idx < _size);
				return _data[a_idx];
			}

			const_reference operator[](size_type a_idx) const noexcept
			{
				assert(a_idx < _size);
				return _data[a_idx];
			}

			constexpr pointer data() noexcept
			{
				return _data;
			}

			constexpr const_pointer data() const noexcept
			{
				return _data;
			}

			size_type size() const noexcept
			{
				return _size;
			}

			bool try_open(const char* a_name, size_type a_size)
			{
				close();

				LARGE_INTEGER bytes;
				bytes.QuadPart = a_size * sizeof(value_type);

				_handle = OpenFileMappingA(FILE_MAP_ALL_ACCESS, false, a_name);
				if (!_handle) {
					close();
					return false;
				}

				_data = static_cast<pointer>(MapViewOfFile(_handle, FILE_MAP_ALL_ACCESS, 0, 0, bytes.QuadPart));
				if (!_data) {
					close();
					return false;
				}

				_size = a_size;
				return true;
			}

			void open(const char* a_name, size_type a_size)
			{
				close();

				LARGE_INTEGER bytes;
				bytes.QuadPart = a_size * sizeof(value_type);

				_handle = OpenFileMappingA(FILE_MAP_ALL_ACCESS, false, a_name);
				if (!_handle) {
					_handle = CreateFileMappingA(INVALID_HANDLE_VALUE, nullptr, PAGE_READWRITE, bytes.HighPart, bytes.LowPart, a_name);
					if (!_handle) {
						throw std::runtime_error("Could not create file mapping for \"" + std::string(a_name) + "\"");
					}
				}

				_data = static_cast<pointer>(MapViewOfFile(_handle, FILE_MAP_ALL_ACCESS, 0, 0, bytes.QuadPart));
				if (!_data) {
					throw std::runtime_error("Could not map view of file for \"" + std::string(a_name) + "\"");
				}

				_size = a_size;
			}

			void close()
			{
				if (_data) {
					UnmapViewOfFile(static_cast<void*>(_data));
					_data = nullptr;
				}

				if (_handle) {
					CloseHandle(_handle);
					_handle = nullptr;
				}
			}

		private:
			HANDLE	  _handle;
			size_type _size;
			pointer	  _data;
		};


		// https://en.wikipedia.org/wiki/Knuth-Morris-Pratt_algorithm
		constexpr auto NPOS = static_cast<std::size_t>(-1);

		void kmp_table(const span<std::uint8_t> W, span<std::size_t> T);
		void kmp_table(const span<std::uint8_t> W, const span<bool> M, span<std::size_t> T);

		std::size_t kmp_search(const span<std::uint8_t> S, const span<std::uint8_t> W);
		std::size_t kmp_search(const span<std::uint8_t> S, const span<std::uint8_t> W, const span<bool> M);


		template <class T>
		struct is_any_function :
			std::disjunction<
				std::is_function<T>,
				std::is_function<
					std::remove_pointer_t<T>>,	// is_function_pointer
				std::is_member_function_pointer<T>>
		{};

		template <class T>
		inline constexpr bool is_any_function_v = is_any_function<T>::value;


		// https://docs.microsoft.com/en-us/cpp/build/x64-calling-convention

		template <class T>
		struct meets_length_req :
			std::disjunction<
				std::bool_constant<sizeof(T) == 1>,
				std::bool_constant<sizeof(T) == 2>,
				std::bool_constant<sizeof(T) == 4>,
				std::bool_constant<sizeof(T) == 8>,
				std::bool_constant<sizeof(T) == 16>,
				std::bool_constant<sizeof(T) == 32>,
				std::bool_constant<sizeof(T) == 64>>
		{};


		template <class T>
		struct meets_function_req :
			std::conjunction<
				std::is_trivially_constructible<T>,
				std::is_trivially_destructible<T>,
				std::is_trivially_copy_assignable<T>,
				std::negation<
					std::is_polymorphic<T>>>
		{};


		template <class T>
		struct meets_member_req :
			std::is_standard_layout<T>
		{};


		template <class T, class = void>
		struct is_msvc_pod :
			std::true_type
		{};

		template <class T>
		struct is_msvc_pod<
			T,
			std::enable_if_t<
				std::is_union_v<T>>> :
			std::false_type
		{};

		template <class T>
		struct is_msvc_pod<
			T,
			std::enable_if_t<
				std::is_class_v<T>>> :
			std::conjunction<
				meets_length_req<T>,
				meets_function_req<T>,
				meets_member_req<T>>
		{};

		template <class T>
		inline constexpr bool is_msvc_pod_v = is_msvc_pod<T>::value;


		template <class F>
		struct member_function_pod;

		// normal
		template <class R, class Cls, class... Args>
		struct member_function_pod<R (Cls::*)(Args...)>
		{
			using type = R(Cls*, Args...);
		};

		// const
		template <class R, class Cls, class... Args>
		struct member_function_pod<R (Cls::*)(Args...) const>
		{
			using type = R(const Cls*, Args...);
		};

		// variadic
		template <class R, class Cls, class... Args>
		struct member_function_pod<R (Cls::*)(Args..., ...)>
		{
			using type = R(Cls*, Args..., ...);
		};

		// variadic const
		template <class R, class Cls, class... Args>
		struct member_function_pod<R (Cls::*)(Args..., ...) const>
		{
			using type = R(const Cls*, Args..., ...);
		};

		template <class F>
		using member_function_pod_t = typename member_function_pod<F>::type;


		template <class F>
		struct member_function_non_pod;

		// normal
		template <class R, class Cls, class... Args>
		struct member_function_non_pod<R (Cls::*)(Args...)>
		{
			using type = R&(Cls*, void*, Args...);
		};

		// normal const
		template <class R, class Cls, class... Args>
		struct member_function_non_pod<R (Cls::*)(Args...) const>
		{
			using type = R&(const Cls*, void*, Args...);
		};

		// variadic
		template <class R, class Cls, class... Args>
		struct member_function_non_pod<R (Cls::*)(Args..., ...)>
		{
			using type = R&(Cls*, void*, Args..., ...);
		};

		// variadic const
		template <class R, class Cls, class... Args>
		struct member_function_non_pod<R (Cls::*)(Args..., ...) const>
		{
			using type = R&(const Cls*, void*, Args..., ...);
		};

		template <class F>
		using member_function_non_pod_t = typename member_function_non_pod<F>::type;


		template <class R, class F, class... Args>
		R InvokeMemberFunctionPOD(F&& a_fn, Args&&... a_args) noexcept(std::is_nothrow_invocable_v<F, Args...>)
		{
			using NF = member_function_pod_t<std::decay_t<F>>;

			auto func = unrestricted_cast<NF*>(a_fn);
			return func(std::forward<Args>(a_args)...);
		}


		// return by value on a non-pod type means caller allocates space for the object
		// and passes it in rcx, unless its a member function, in which case it passes in rdx
		// all other arguments shift over to compensate
		template <class R, class F, class T1, class... Args>
		R InvokeMemberFunctionNonPOD(F&& a_fn, T1&& a_object, Args&&... a_args) noexcept(std::is_nothrow_invocable_v<F, T1, Args...>)
		{
			using NF = member_function_non_pod_t<std::decay_t<F>>;

			auto										  func = unrestricted_cast<NF*>(a_fn);
			std::aligned_storage_t<sizeof(R), alignof(R)> result;
			return func(std::forward<T1>(a_object), &result, std::forward<Args>(a_args)...);
		}


		template <class R, class F, class... Args>
		R Invoke(F&& a_fn, Args&&... a_args) noexcept(std::is_nothrow_invocable_v<F, Args...>)
		{
			if constexpr (std::is_member_function_pointer_v<std::decay_t<F>>) {	 // the compiler chokes on member functions
				if constexpr (is_msvc_pod_v<R>) {								 // no need to shift if it's a pod type
					return InvokeMemberFunctionPOD<R>(std::forward<F>(a_fn), std::forward<Args>(a_args)...);
				} else {
					return InvokeMemberFunctionNonPOD<R>(std::forward<F>(a_fn), std::forward<Args>(a_args)...);
				}
			} else {
				return a_fn(std::forward<Args>(a_args)...);
			}
		}
	}


	// generic solution for calling relocated functions
	template <
		class F,
		class... Args,
		std::enable_if_t<
			std::is_invocable_v<
				F,
				Args...>,
			int> = 0>
	decltype(auto) Invoke(F&& a_fn, Args&&... a_args) noexcept(std::is_nothrow_invocable_v<F, Args...>)
	{
		return Impl::Invoke<std::invoke_result_t<F, Args...>>(std::forward<F>(a_fn), std::forward<Args>(a_args)...);
	}


	class Module
	{
	public:
		struct IDs
		{
			enum ID
			{
				kTextX,
				kIData,
				kRData,
				kData,
				kPData,
				kTLS,
				kTextW,
				kGFIDs,

				kTotal
			};
		};
		using ID = IDs::ID;


		class Section
		{
		public:
			constexpr Section() noexcept :
				addr(0xDEADBEEF),
				size(0xDEADBEEF),
				rva(0xDEADBEEF)
			{}


			std::uint32_t  RVA() const;
			std::uintptr_t BaseAddr() const;
			std::size_t	   Size() const;


			template <class T = void>
			inline T* BasePtr() const
			{
				return reinterpret_cast<T*>(BaseAddr());
			}

		protected:
			friend class Module;


			std::uintptr_t addr;
			std::size_t	   size;
			std::uint32_t  rva;
		};


		static std::uintptr_t BaseAddr();
		static std::size_t	  Size();
		static Section		  GetSection(ID a_id);
		static Version		  GetVersion();


		template <class T = void>
		inline static T* BasePtr()
		{
			auto singleton = GetSingleton();
			return reinterpret_cast<T*>(singleton->_base);
		}

	private:
		struct Sections
		{
			struct Elem
			{
				constexpr Elem(const char* a_name) :
					Elem(a_name, 0)
				{}


				constexpr Elem(const char* a_name, DWORD a_flags) :
					name(std::move(a_name)),
					section(),
					flags(a_flags)
				{}


				std::string_view name;
				Section			 section;
				DWORD			 flags;
			};


			constexpr Sections() :
				arr{
					Elem(".text", static_cast<DWORD>(IMAGE_SCN_MEM_EXECUTE)),
					".idata",
					".rdata",
					".data",
					".pdata",
					".tls",
					Elem(".text", static_cast<DWORD>(IMAGE_SCN_MEM_WRITE)),
					".gfids"
				}
			{}


			std::array<Elem, ID::kTotal> arr;
		};


		Module();
		Module(const Module&) = default;
		Module(Module&&) = default;
		~Module() = default;

		Module& operator=(const Module&) = default;
		Module& operator=(Module&&) = default;

		[[nodiscard]] static Module* GetSingleton();

		void BuildVersionInfo();


		static inline std::uintptr_t _natvis = 0;

		HMODULE		   _handle;
		std::uintptr_t _base;
		std::size_t	   _size;
		Sections	   _sections;
		Version		   _version;
	};


	class IDDatabase
	{
	public:
#ifdef _DEBUG
		[[nodiscard]] static std::uint64_t OffsetToID(std::uint64_t a_address);
#endif
		[[nodiscard]] static std::uint64_t IDToOffset(std::uint64_t a_id);

	private:
		class IStream
		{
		public:
			using stream_type = std::istream;
			using pointer = stream_type*;
			using const_pointer = const stream_type*;
			using reference = stream_type&;
			using const_reference = const stream_type&;

			constexpr IStream(stream_type& a_stream) :
				_stream(a_stream)
			{}

			[[nodiscard]] constexpr reference		operator*() noexcept { return _stream; }
			[[nodiscard]] constexpr const_reference operator*() const noexcept { return _stream; }

			[[nodiscard]] constexpr pointer		  operator->() noexcept { return std::addressof(_stream); }
			[[nodiscard]] constexpr const_pointer operator->() const noexcept { return std::addressof(_stream); }

			template <class T>
			inline void readin(T& a_val)
			{
				_stream.read(reinterpret_cast<char*>(std::addressof(a_val)), sizeof(T));
			}

			template <class T, typename std::enable_if_t<std::is_arithmetic_v<T>, int> = 0>
			inline T readout()
			{
				T val;
				readin(val);
				return val;
			}

		private:
			stream_type& _stream;
		};


		class Header
		{
		public:
			inline Header() noexcept :
				_moduleName(),
				_part1(),
				_part2()
			{}

			void Read(IStream& a_input);

			[[nodiscard]] constexpr decltype(auto)	   AddrCount() const noexcept { return static_cast<std::size_t>(_part2.addressCount); }
			[[nodiscard]] constexpr const std::string& ModuleName() const noexcept { return _moduleName; }
			[[nodiscard]] constexpr decltype(auto)	   PSize() const noexcept { return static_cast<std::uint64_t>(_part2.pointerSize); }
			[[nodiscard]] inline decltype(auto)		   GetVersion() const { return Version(_part1.version); }

		private:
			struct Part1
			{
				constexpr Part1() :
					format(0),
					version{ 0 },
					nameLen(0)
				{}

				void Read(IStream& a_input);

				std::int32_t format;
				std::int32_t version[4];
				std::int32_t nameLen;
			};


			struct Part2
			{
				constexpr Part2() :
					pointerSize(0),
					addressCount(0)
				{}

				void Read(IStream& a_input);

				std::int32_t pointerSize;
				std::int32_t addressCount;
			};


			std::string _moduleName;
			Part1		_part1;
			Part2		_part2;
		};


		IDDatabase();
		IDDatabase(const IDDatabase&) = default;
		IDDatabase(IDDatabase&&) = default;
		~IDDatabase() = default;

		IDDatabase& operator=(const IDDatabase&) = default;
		IDDatabase& operator=(IDDatabase&&) = default;


		[[nodiscard]] static IDDatabase* GetSingleton();

		[[nodiscard]] bool Load();
		[[nodiscard]] bool Load(std::uint16_t a_major, std::uint16_t a_minor, std::uint16_t a_revision, std::uint16_t a_build);
		[[nodiscard]] bool Load(Version a_version);

		[[nodiscard]] bool DoLoad(IStream& a_input, const Version& a_version);
		void			   DoLoadImpl(IStream& a_input, std::vector<std::uint64_t>& a_buf);

#ifdef _DEBUG
		[[nodiscard]] std::uint64_t OffsetToIDImpl(std::uint64_t a_address);
#endif
		[[nodiscard]] std::uint64_t IDToOffsetImpl(std::uint64_t a_id);

		static inline std::uint64_t* _natvis = nullptr;

		Header						   _header;
		Impl::MemoryMap<std::uint64_t> _offsets;
#ifdef _DEBUG
		std::unordered_map<std::uint64_t, std::uint64_t> _ids;
#endif
	};


	// converts an id within the database to its equivalent offset
	class ID
	{
	public:
		constexpr ID() noexcept :
			ID(static_cast<std::uint64_t>(0))
		{}

		constexpr ID(const ID& a_rhs) noexcept :
			ID(a_rhs._id)
		{}

		constexpr ID(ID&& a_rhs) noexcept :
			ID(std::move(a_rhs._id))
		{}

		explicit constexpr ID(std::uint64_t a_id) noexcept :
			_id(a_id)
		{}

		constexpr ID& operator=(const ID& a_rhs) noexcept
		{
			if (this != std::addressof(a_rhs)) {
				_id = a_rhs._id;
			}
			return *this;
		}

		constexpr ID& operator=(ID&& a_rhs) noexcept
		{
			if (this != std::addressof(a_rhs)) {
				_id = std::move(a_rhs._id);
			}
			return *this;
		}

		constexpr ID& operator=(std::uint64_t a_id) noexcept
		{
			_id = a_id;
			return *this;
		}

		[[nodiscard]] std::uint64_t operator*() const;
		[[nodiscard]] std::uint64_t address() const;
		[[nodiscard]] std::uint64_t offset() const;

		[[nodiscard, deprecated("use address")]] std::uint64_t GetAddress() const;
		[[nodiscard, deprecated("use offset")]] std::uint64_t  GetOffset() const;

	private:
		std::uint64_t _id;
	};


	// relocates the given offset in the exe and reinterprets it as the given type
	template <class T>
	class Offset
	{
	public:
		using value_type =
			std::conditional_t<
				std::is_function_v<T>,
				std::add_pointer_t<T>,
				T>;
		;

		constexpr Offset() noexcept :
			_address(0)
		{}

		constexpr Offset(const Offset& a_rhs) noexcept :
			_address(a_rhs._address)
		{}

		constexpr Offset(Offset&& a_rhs) noexcept :
			_address(std::move(a_rhs._address))
		{}

		constexpr Offset(std::uintptr_t a_offset) noexcept :
			_address(a_offset)
		{}

		Offset(ID a_id) :
			Offset(a_id.address())
		{}

		Offset(ID a_id, std::size_t a_mod) noexcept :
			_address(a_id.address() + a_mod)
		{}

		Offset(std::pair<ID, std::size_t> a_idAndMod) noexcept :
			_address(a_idAndMod.first.address() + a_idAndMod.second)
		{}

		constexpr Offset& operator=(const Offset& a_rhs) noexcept
		{
			if (this != std::addressof(a_rhs)) {
				_address = a_rhs._address;
			}
			return *this;
		}

		constexpr Offset& operator=(Offset&& a_rhs) noexcept
		{
			if (this != std::addressof(a_rhs)) {
				_address = std::move(a_rhs._address);
			}
			return *this;
		}

		constexpr Offset& operator=(std::uintptr_t a_address) noexcept
		{
			_address = a_address;
			return *this;
		}

		constexpr Offset& operator=(ID a_rhs) noexcept
		{
			_address = a_rhs.address();
			return *this;
		}

		constexpr Offset& operator=(std::pair<ID, std::size_t> a_rhs) noexcept
		{
			_address = a_rhs.first.address() + a_rhs.second;
			return *this;
		}

		template <
			class U = value_type,
			std::enable_if_t<
				std::is_reference_v<U>,
				int> = 0>
		[[nodiscard]] operator value_type() const
		{
			return type();
		}

		template <
			class U = value_type,
			std::enable_if_t<
				std::is_pointer_v<
					std::remove_reference_t<U>>,
				int> = 0>
		auto operator*() const
			-> std::add_lvalue_reference_t<
				std::remove_reference_t<
					std::remove_pointer_t<
						value_type>>>
		{
			return *type();
		}

		template <
			class U = value_type,
			std::enable_if_t<
				std::is_pointer_v<
					std::remove_reference_t<U>>,
				int> = 0>
		value_type operator->() const
		{
			return type();
		}

		template <
			class U = value_type,
			std::enable_if_t<
				std::is_pointer_v<
					std::remove_reference_t<U>>,
				int> = 0>
		[[nodiscard]] auto operator[](std::size_t a_idx) const
			-> std::add_lvalue_reference_t<
				std::remove_reference_t<
					std::remove_pointer_t<U>>>
		{
			return type()[a_idx];
		}

		template <
			class... Args,
			class F = value_type,
			std::enable_if_t<
				std::is_invocable_v<
					F,
					Args...>,
				int> = 0>
		decltype(auto) operator()(Args&&... a_args) const
		{
			return Invoke(type(), std::forward<Args>(a_args)...);
		}

		[[nodiscard]] value_type type() const
		{
			return unrestricted_cast<value_type>(address());
		}

		[[nodiscard]] constexpr std::uintptr_t address() const noexcept
		{
			return _address;
		}

		[[nodiscard]] std::uintptr_t offset() const
		{
			return address() - Module::BaseAddr();
		}

		template <
			class U = value_type,
			std::enable_if_t<
				std::is_same_v<
					U,
					std::uintptr_t>,
				int> = 0>
		std::uintptr_t write_vfunc(std::size_t a_idx, std::uintptr_t a_newFunc)
		{
			constexpr auto PSIZE = sizeof(void*);
			auto		   addr = address() + (PSIZE * a_idx);
			auto		   result = *reinterpret_cast<std::uintptr_t*>(addr);
			SafeWrite64(addr, a_newFunc);
			return result;
		}

		template <
			class F,
			class U = value_type,
			std::enable_if_t<
				std::is_same_v<
					U,
					std::uintptr_t>,
				int> = 0>
		std::uintptr_t write_vfunc(std::size_t a_idx, F a_newFunc)
		{
			return write_vfunc(a_idx, unrestricted_cast<std::uintptr_t>(a_newFunc));
		}

		[[nodiscard, deprecated("use type")]] decltype(auto) GetType() const
		{
			return type();
		}

		[[nodiscard, deprecated("use address")]] constexpr decltype(auto) GetAddress() const noexcept
		{
			return address();
		}

		[[nodiscard, deprecated("use offset")]] decltype(auto) GetOffset() const
		{
			return offset();
		}

		template <
			class U = value_type,
			std::enable_if_t<
				std::is_same_v<
					U,
					std::uintptr_t>,
				int> = 0>
		[[deprecated("use write_vfunc")]] std::uintptr_t WriteVFunc(std::size_t a_idx, std::uintptr_t a_newFunc)
		{
			constexpr auto PSIZE = sizeof(void*);
			auto		   addr = address() + (PSIZE * a_idx);
			auto		   result = *reinterpret_cast<std::uintptr_t*>(addr);
			SafeWrite64(addr, a_newFunc);
			return result;
		}

		template <
			class F,
			class U = value_type,
			std::enable_if_t<
				std::is_same_v<
					U,
					std::uintptr_t>,
				int> = 0>
		[[deprecated("use write_vfunc")]] std::uintptr_t WriteVFunc(std::size_t a_idx, F a_newFunc)
		{
			return WriteVFunc(a_idx, unrestricted_cast<std::uintptr_t>(a_newFunc));
		}

	private:
		std::uintptr_t _address;
	};


	template <class, class = void>
	class Function;


	template <class T>
	class [[deprecated("use Offset")]] Function<
		T,
		std::enable_if_t<
			Impl::is_any_function_v<
				std::decay_t<T>>>>
	{
	public:
		using function_type = std::decay_t<T>;

		constexpr Function() :
			_storage()
		{}

		constexpr Function(const Function& a_rhs) :
			_storage(a_rhs._storage)
		{}

		constexpr Function(Function && a_rhs) :
			_storage(std::move(a_rhs._storage))
		{}

		constexpr Function(const function_type& a_rhs) :
			_storage(a_rhs)
		{}

		constexpr Function(function_type && a_rhs) :
			_storage(std::move(a_rhs))
		{}

		constexpr Function(std::uintptr_t a_rhs) :
			_storage(a_rhs)
		{}

		Function(ID a_rhs) :
			_storage(a_rhs.GetAddress())
		{}

		Function(Offset<function_type> a_rhs) :
			_storage(a_rhs.GetAddress())
		{}

		Function(Offset<std::uintptr_t> a_rhs) :
			_storage(a_rhs.GetAddress())
		{}

		constexpr Function& operator=(const Function& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				_storage = a_rhs._storage;
			}
			return *this;
		}

		constexpr Function& operator=(Function&& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				_storage = std::move(a_rhs._storage);
			}
			return *this;
		}

		constexpr Function& operator=(const function_type& a_rhs)
		{
			_storage = a_rhs;
			return *this;
		}

		constexpr Function& operator=(function_type&& a_rhs)
		{
			_storage = std::move(a_rhs);
			return *this;
		}

		constexpr Function& operator=(std::uintptr_t a_rhs)
		{
			_storage = a_rhs;
			return *this;
		}

		Function& operator=(ID a_rhs)
		{
			_storage = a_rhs.GetAddress();
			return *this;
		}

		Function& operator=(Offset<function_type> a_rhs)
		{
			_storage = a_rhs.GetAddress();
			return *this;
		}

		Function& operator=(Offset<std::uintptr_t> a_rhs)
		{
			_storage = a_rhs.GetAddress();
			return *this;
		}

		[[nodiscard]] explicit operator bool() const noexcept
		{
			return !Empty();
		}

		template <class... Args, class F = function_type, typename std::enable_if_t<std::is_invocable<F, Args...>::value, int> = 0>
		std::invoke_result_t<F, Args...> operator()(Args&&... a_args) const
		{
			if (Empty()) {
				assert(false);
				throw std::bad_function_call();
			}

			return Invoke(GetFunction(), std::forward<Args>(a_args)...);
		}

	private:
		enum : std::uintptr_t
		{
			kEmpty = 0
		};

		[[nodiscard]] bool Empty() const noexcept
		{
			return GetAddress() == kEmpty;
		}

		[[nodiscard]] std::uintptr_t GetAddress() const noexcept
		{
			return _storage.address;
		}

		[[nodiscard]] const function_type& GetFunction() const noexcept
		{
			return _storage.function;
		}

		[[nodiscard]] bool InRange() const
		{
			auto xText = Module::GetSection(Module::ID::kTextX);
			return xText.BaseAddr() <= GetAddress() && GetAddress() < xText.BaseAddr() + xText.Size();
		}

		union Storage
		{
			constexpr Storage() :
				address(kEmpty)
			{}

			constexpr Storage(const Storage& a_rhs) :
				function(a_rhs.function)
			{}

			constexpr Storage(Storage&& a_rhs) :
				function(std::move(a_rhs.func))
			{}

			constexpr Storage(const function_type& a_rhs) :
				function(a_rhs)
			{}

			constexpr Storage(function_type&& a_rhs) :
				function(std::move(a_rhs))
			{}

			constexpr Storage(std::uintptr_t a_rhs) :
				address(a_rhs)
			{}

			constexpr Storage& operator=(const Storage& a_rhs)
			{
				if (this != std::addressof(a_rhs)) {
					function = a_rhs.function;
				}
				return *this;
			}

			constexpr Storage& operator=(Storage&& a_rhs)
			{
				if (this != std::addressof(a_rhs)) {
					function = std::move(a_rhs.function);
				}
				return *this;
			}

			constexpr Storage& operator=(const function_type& a_rhs)
			{
				function = a_rhs;
				return *this;
			}

			constexpr Storage& operator=(function_type&& a_rhs)
			{
				function = std::move(a_rhs);
				return *this;
			}

			constexpr Storage& operator=(std::uintptr_t a_rhs)
			{
				address = a_rhs;
				return *this;
			}

			function_type  function;
			std::uintptr_t address;
		};

		Storage _storage;
	};
}