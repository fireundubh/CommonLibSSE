#include "REL/Relocation.h"

#include "RE/RTTI.h"

#include "SKSE/Logger.h"


namespace REL
{
	namespace Impl
	{
		void kmp_table(const span<std::uint8_t> W, span<std::size_t> T)
		{
			std::size_t pos = 1;
			std::size_t cnd = 0;

			T[0] = NPOS;

			while (pos < W.size()) {
				if (W[pos] == W[cnd]) {
					T[pos] = T[cnd];
				} else {
					T[pos] = cnd;
					cnd = T[cnd];
					while (cnd != NPOS && W[pos] != W[cnd]) {
						cnd = T[cnd];
					}
				}
				++pos;
				++cnd;
			}

			T[pos] = cnd;
		}


		void kmp_table(const span<std::uint8_t> W, const span<bool> M, span<std::size_t> T)
		{
			std::size_t pos = 1;
			std::size_t cnd = 0;

			T[0] = NPOS;

			while (pos < W.size()) {
				if (!M[pos] || !M[cnd] || W[pos] == W[cnd]) {
					T[pos] = T[cnd];
				} else {
					T[pos] = cnd;
					cnd = T[cnd];
					while (cnd != NPOS && M[pos] && M[cnd] && W[pos] != W[cnd]) {
						cnd = T[cnd];
					}
				}
				++pos;
				++cnd;
			}

			T[pos] = cnd;
		}


		std::size_t kmp_search(const span<std::uint8_t> S, const span<std::uint8_t> W)
		{
			std::size_t j = 0;
			std::size_t k = 0;
			std::vector<std::size_t> T(W.size() + 1);
			kmp_table(W, span(T.data(), T.size()));

			while (j < S.size()) {
				if (W[k] == S[j]) {
					++j;
					++k;
					if (k == W.size()) {
						return j - k;
					}
				} else {
					k = T[k];
					if (k == NPOS) {
						++j;
						++k;
					}
				}
			}

			return 0xDEADBEEF;
		}


		std::size_t kmp_search(const span<std::uint8_t> S, const span<std::uint8_t> W, const span<bool> M)
		{
			std::size_t j = 0;
			std::size_t k = 0;
			std::vector<std::size_t> T(W.size() + 1);
			kmp_table(W, M, span(T.data(), T.size()));

			while (j < S.size()) {
				if (!M[k] || W[k] == S[j]) {
					++j;
					++k;
					if (k == W.size()) {
						return j - k;
					}
				} else {
					k = T[k];
					if (k == NPOS) {
						++j;
						++k;
					}
				}
			}

			return 0xDEADBEEF;
		}
	}


	std::uint32_t Module::Section::RVA() const
	{
		assert(rva != 0xDEADBEEF);
		return rva;
	}


	std::uintptr_t Module::Section::BaseAddr() const
	{
		assert(addr != 0xDEADBEEF);
		return addr;
	}


	std::size_t Module::Section::Size() const
	{
		assert(size != 0xDEADBEEF);
		return size;
	}


	std::uintptr_t Module::BaseAddr()
	{
		const auto* singleton = GetSingleton();
		return singleton->_base;
	}


	std::size_t Module::Size()
	{
		const auto* singleton = GetSingleton();
		return singleton->_size;
	}


	auto Module::GetSection(ID a_id)
		-> Section
	{
		assert(a_id < ID::kTotal);
		const auto* singleton = GetSingleton();
		return singleton->_sections.arr[a_id].section;
	}


	Version Module::GetVersion()
	{
		const auto* singleton = GetSingleton();
		return singleton->_version;
	}


	Module::Module() :
		_handle(GetModuleHandleA("SkyrimSE.exe")),
		_base(0),
		_sections(),
		_size(0),
		_version()
	{
		if (!_handle) {
			_FATALERROR("Failed to get handle to module!");
			assert(false);
			throw std::exception();
		}

		_base = reinterpret_cast<std::uintptr_t>(_handle);
		_natvis = _base;

		auto dosHeader = reinterpret_cast<const IMAGE_DOS_HEADER*>(_base);
		auto ntHeader = adjust_pointer<IMAGE_NT_HEADERS64>(dosHeader, dosHeader->e_lfanew);
		_size = ntHeader->OptionalHeader.SizeOfCode;

		const auto sectionHeader = IMAGE_FIRST_SECTION(ntHeader);
		for (std::size_t i = 0; i < ntHeader->FileHeader.NumberOfSections; ++i) {
			const auto& section = sectionHeader[i];
			for (auto& elem : _sections.arr) {
				auto length = std::min<std::size_t>(elem.name.length(), IMAGE_SIZEOF_SHORT_NAME);
				if (std::memcmp(elem.name.data(), section.Name, length) == 0 && (section.Characteristics & elem.flags) == elem.flags) {
					elem.section.rva = section.VirtualAddress;
					elem.section.addr = _base + section.VirtualAddress;
					elem.section.size = section.Misc.VirtualSize;
					break;
				}
			}
		}

		BuildVersionInfo();
	}


	Module* Module::GetSingleton()
	{
		static Module singleton;
		return std::addressof(singleton);
	}


	void Module::BuildVersionInfo()
	{
		char fileName[MAX_PATH];
		if (!GetModuleFileNameA(_handle, fileName, MAX_PATH)) {
			assert(false);
			return;
		}

		DWORD dummy;
		std::vector<char> buf(GetFileVersionInfoSizeA(fileName, &dummy));
		if (buf.size() == 0) {
			assert(false);
			return;
		}

		if (!GetFileVersionInfoA(fileName, 0, static_cast<DWORD>(buf.size()), buf.data())) {
			assert(false);
			return;
		}

		LPVOID verBuf;
		UINT verLen;
		if (!VerQueryValueA(buf.data(), "\\StringFileInfo\\040904B0\\ProductVersion", &verBuf, &verLen)) {
			assert(false);
			return;
		}

		std::istringstream ss(static_cast<const char*>(verBuf));
		std::string token;
		for (std::size_t i = 0; i < 4 && std::getline(ss, token, '.'); ++i) {
			_version[i] = static_cast<std::uint16_t>(std::stoi(token));
		}
	}


#ifdef _DEBUG
	std::uint64_t IDDatabase::OffsetToID(std::uint64_t a_address)
	{
		auto singleton = GetSingleton();
		return singleton->OffsetToIDImpl(a_address);
	}
#endif


	std::uint64_t IDDatabase::IDToOffset(std::uint64_t a_id)
	{
		auto singleton = GetSingleton();
		return singleton->IDToOffsetImpl(a_id);
	}


	void IDDatabase::Header::Read(IStream& a_input)
	{
		_part1.Read(a_input);
		_moduleName.resize(_part1.nameLen);
		a_input->read(_moduleName.data(), _moduleName.size());
		_part2.Read(a_input);
	}


	void IDDatabase::Header::Part1::Read(IStream& a_input)
	{
		a_input->read(reinterpret_cast<char*>(this), sizeof(Part1));
		if (format != 1) {
			throw std::runtime_error("Unexpected format");
		}
	}


	void IDDatabase::Header::Part2::Read(IStream& a_input)
	{
		a_input->read(reinterpret_cast<char*>(this), sizeof(Part2));
	}


	IDDatabase::IDDatabase() :
		_header(),
		_offsets()
#ifdef _DEBUG
		,
		_ids()
#endif
	{
		if (!Load()) {
			_FATALERROR("Failed to load ID database!");
			assert(false);
			throw std::exception();
		}
	}


	IDDatabase* IDDatabase::GetSingleton()
	{
		static IDDatabase singleton;
		return std::addressof(singleton);
	}


	bool IDDatabase::Load()
	{
		auto version = Module::GetVersion();
		return Load(std::move(version));
	}


	bool IDDatabase::Load(std::uint16_t a_major, std::uint16_t a_minor, std::uint16_t a_revision, std::uint16_t a_build)
	{
		Version version(a_major, a_minor, a_revision, a_build);
		return Load(std::move(version));
	}


	bool IDDatabase::Load(Version a_version)
	{
		std::string fileName = "Data/SKSE/Plugins/version-";
		fileName += std::to_string(a_version[0]);
		fileName += '-';
		fileName += std::to_string(a_version[1]);
		fileName += '-';
		fileName += std::to_string(a_version[2]);
		fileName += '-';
		fileName += std::to_string(a_version[3]);
		fileName += ".bin";

		std::error_code ec;
		std::filesystem::path path(fileName);
		if (!std::filesystem::exists(path, ec) || ec) {
			assert(false);
			return false;
		}

		std::ifstream file(path, std::ios_base::in | std::ios_base::binary);
		file.exceptions(std::ios_base::badbit | std::ios_base::failbit | std::ios_base::eofbit);
		if (!file.is_open()) {
			assert(false);
			return false;
		}

		try {
			IStream input(file);
			return DoLoad(input, a_version);
		} catch (std::exception& e) {
			_ERROR("%s", e.what());
			assert(false);
			return false;
		}
	}


	bool IDDatabase::DoLoad(IStream& a_input, const Version& a_version)
	{
		_header.Read(a_input);

		if (Module::GetVersion() != _header.GetVersion()) {
			assert(false);
			return false;
		}

		std::vector<std::uint64_t> buffer;
		buffer.reserve(_header.AddrCount());
#ifdef _DEBUG
		_ids.reserve(_header.AddrCount());
#endif

		bool success = true;
		try {
			DoLoadImpl(a_input, buffer);
		} catch (std::exception& e) {
			assert(false);
			_ERROR("%s in ID database", e.what());
			success = false;
		}

		std::string name = "CommonLibSSEOffsets-";
		name += a_version.GetString();
		if (!_offsets.try_open(name.c_str(), buffer.size())) {
			_offsets.open(name.c_str(), buffer.size());
			_offsets = buffer;
		}
		_natvis = _offsets.data();

		return success;
	}


	void IDDatabase::DoLoadImpl(IStream& a_input, std::vector<std::uint64_t>& a_buf)
	{
		std::uint8_t type = 0;
		std::uint64_t id = 0;
		std::uint64_t offset = 0;
		std::uint64_t prevID = 0;
		std::uint64_t prevOffset = 0;
		for (std::size_t i = 0; i < _header.AddrCount(); ++i) {
			a_input.readin(type);
			const std::uint8_t lo = type & 0xF;
			const std::uint8_t hi = type >> 4;

			switch (lo) {
			case 0:
				a_input.readin(id);
				break;
			case 1:
				id = prevID + 1;
				break;
			case 2:
				id = prevID + a_input.readout<std::uint8_t>();
				break;
			case 3:
				id = prevID - a_input.readout<std::uint8_t>();
				break;
			case 4:
				id = prevID + a_input.readout<std::uint16_t>();
				break;
			case 5:
				id = prevID - a_input.readout<std::uint16_t>();
				break;
			case 6:
				id = a_input.readout<std::uint16_t>();
				break;
			case 7:
				id = a_input.readout<std::uint32_t>();
				break;
			default:
				throw std::runtime_error("Unhandled type");
			}

			const std::uint64_t tmp = (hi & 8) != 0 ? (prevOffset / _header.PSize()) : prevOffset;

			switch (hi & 7) {
			case 0:
				a_input.readin(offset);
				break;
			case 1:
				offset = tmp + 1;
				break;
			case 2:
				offset = tmp + a_input.readout<std::uint8_t>();
				break;
			case 3:
				offset = tmp - a_input.readout<std::uint8_t>();
				break;
			case 4:
				offset = tmp + a_input.readout<std::uint16_t>();
				break;
			case 5:
				offset = tmp - a_input.readout<std::uint16_t>();
				break;
			case 6:
				offset = a_input.readout<std::uint16_t>();
				break;
			case 7:
				offset = a_input.readout<std::uint32_t>();
				break;
			default:
				throw std::runtime_error("Unhandled type");
			}

			if ((hi & 8) != 0) {
				offset *= _header.PSize();
			}

			if (id >= a_buf.size()) {
				a_buf.resize(id + 1, 0);
			}
			a_buf[id] = offset;
#ifdef _DEBUG
			_ids[offset] = id;
#endif

			prevOffset = offset;
			prevID = id;
		}
	}


#ifdef _DEBUG
	std::uint64_t IDDatabase::OffsetToIDImpl(std::uint64_t a_address)
	{
		auto it = _ids.find(a_address);
		if (it != _ids.end()) {
			return it->second;
		} else {
			throw std::runtime_error("Failed to find address in ID database");
		}
	}
#endif


	std::uint64_t IDDatabase::IDToOffsetImpl(std::uint64_t a_id)
	{
		return _offsets[a_id];
	}


	std::uint64_t ID::operator*() const
	{
		return offset();
	}


	std::uint64_t ID::address() const
	{
		return Module::BaseAddr() + offset();
	}


	std::uint64_t ID::offset() const
	{
		return IDDatabase::IDToOffset(_id);
	}


	std::uint64_t ID::GetAddress() const
	{
		return address();
	}


	std::uint64_t ID::GetOffset() const
	{
		return offset();
	}
}