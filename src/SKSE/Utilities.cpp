#include "SKSE/Utilities.h"

#include "SKSE/Logger.h"

#include <filesystem>


namespace SKSE
{
	const std::string& GetRuntimeDirectory()
	{
		static std::string s_runtimeDirectory;

		if (s_runtimeDirectory.empty()) {
			char runtimePathBuf[MAX_PATH];
			const UInt32 runtimePathLength = GetModuleFileName(GetModuleHandle(nullptr), runtimePathBuf, sizeof(runtimePathBuf));

			if (runtimePathLength && (runtimePathLength < sizeof(runtimePathBuf))) {
				std::string runtimePath(runtimePathBuf, runtimePathLength);

				const std::string::size_type lastSlash = runtimePath.rfind('\\');
				if (lastSlash != std::string::npos) {
					s_runtimeDirectory = runtimePath.substr(0, lastSlash + 1);
				}
			}
		}

		return s_runtimeDirectory;
	}


	const std::string& GetPluginFolderPath()
	{
		static std::string s_pluginPath;

		if (s_pluginPath.empty()) {
			const auto& runtimePath = GetRuntimeDirectory();
			if (!runtimePath.empty()) {
				s_pluginPath = runtimePath + R"(Data\SKSE\Plugins\)";
			} else {
				_MESSAGE("couldn't get runtime directory path!");
			}
		}

		return s_pluginPath;
	}


	std::string GetPluginConfigPath(const char* modName)
	{
		static std::string s_configPath;

		if (s_configPath.empty()) {
			const auto& pluginPath = GetPluginFolderPath();
			if (!pluginPath.empty()) {
				s_configPath = pluginPath + modName + R"(.ini)";
				_MESSAGE("config path = %s", s_configPath.c_str());
			} else {
				_MESSAGE("couldn't get plugin folder path!");
			}
		}

		return s_configPath;
	}


	std::vector<std::string> GetAllConfigPaths(const std::string& a_folder, const std::string& a_suffix)
	{
		namespace fs = std::filesystem;
		std::vector<std::string> vec;

		const auto& runtimePath = GetRuntimeDirectory();
		if (!runtimePath.empty()) {
			std::string configPath = runtimePath + a_folder;
			for (const auto& entry : fs::directory_iterator(configPath)) {
				if (entry.exists() && entry.path().extension() == ".ini") {
					std::string path = entry.path().string();
					if (path.find(a_suffix) != std::string::npos) {
						vec.push_back(path);
					}
				}
			}
		}

		return vec;
	}


	UInt32 RNG::GenerateRandomNumber(UInt32 a_min, UInt32 a_max)
	{
		std::uniform_int_distribution<UInt32> distr(a_min, a_max);
		return distr(twister);
	}


	float RNG::GenerateRandomNumber(float a_min, float a_max)
	{
		std::uniform_real_distribution<float> distr(a_min, a_max);
		return distr(twister);
	}
}
