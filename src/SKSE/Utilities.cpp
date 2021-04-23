#include "SKSE/Utilities.h"

#include "SKSE/Logger.h"


namespace SKSE
{
	RNG * RNG::GetSingleton()
	{
		static RNG singleton;
		return &singleton;
	}


	RNG::RNG() :
		twister(std::random_device{}())
	{}


	namespace UTIL
	{
		std::vector<std::string> STRING::split(const std::string& a_str, const std::string& a_delimiter)
		{
			std::vector<std::string> list;
			std::string strCopy = a_str;
			size_t pos = 0;
			std::string token;
			while ((pos = strCopy.find(a_delimiter)) != std::string::npos) {
				token = strCopy.substr(0, pos);
				list.push_back(token);
				strCopy.erase(0, pos + a_delimiter.length());
			}
			list.push_back(strCopy);
			return list;
		}
	}


	const std::string& GetRuntimeDirectory()
	{
		static std::string s_runtimeDirectory;

		if (s_runtimeDirectory.empty()) {
			std::vector<char> buf;
			buf.reserve(MAX_PATH);
			buf.resize(MAX_PATH / 2);
			std::uint32_t result = 0;
			do {
				buf.resize(buf.size() * 2);
				result = GetModuleFileName(
					GetModuleHandleA("SkyrimSE.exe"),
					buf.data(),
					static_cast<std::uint32_t>(buf.size()));
			} while (result && result == buf.size() && buf.size() <= std::numeric_limits<std::uint32_t>::max());

			if (result && result != buf.size()) {
				std::string runtimePath(buf.data(), result);
				auto lastSlash = runtimePath.rfind('\\');
				if (lastSlash != std::string::npos) {
					s_runtimeDirectory = runtimePath.substr(0, lastSlash + 1);
				}
			}
		}

		return s_runtimeDirectory;
	}


	std::vector<std::string> GetAllConfigPaths(const std::string& a_folder, const std::string& a_suffix)
	{
		namespace fs = std::filesystem;
		std::vector<std::string> vec;

		const auto& runtimePath = GetRuntimeDirectory();
		if (!runtimePath.empty()) {
			std::string configPath = runtimePath + a_folder;
			for (const auto& entry : fs::directory_iterator(configPath)) {
				if (entry.exists() && entry.path().extension() == ".ini"sv) {
					auto path = entry.path().string();
					if (path.find(a_suffix) != std::string::npos) {
						vec.push_back(path);
					}
				}
			}
		}

		return vec;
	}
}
