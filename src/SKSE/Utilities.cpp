#include "SKSE/Utilities.h"

#include "SKSE/Logger.h"


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


	const std::string& GetPluginPath()
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


	const char* GetConfigPath(const char* modName)
	{
		static std::string s_configPath;

		if (s_configPath.empty()) {
			const auto& pluginPath = GetPluginPath();
			if (!pluginPath.empty()) {
				s_configPath = pluginPath + modName + R"(.ini)";
				_MESSAGE("config path = %s", s_configPath.c_str());
			} else {
				_MESSAGE("couldn't get plugin path!");
			}
		}

		return s_configPath.c_str();
	}
}
