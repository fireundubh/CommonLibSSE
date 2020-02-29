#include "SKSE/Utilities.h"

#include <string>


namespace SKSE
{
	const std::string& GetRuntimeDirectory()
	{
		static std::string s_runtimeDirectory;

		if (s_runtimeDirectory.empty()) {

			char	runtimePathBuf[MAX_PATH];
			UInt32	runtimePathLength = GetModuleFileName(GetModuleHandle(NULL), runtimePathBuf, sizeof(runtimePathBuf));

			if (runtimePathLength && (runtimePathLength < sizeof(runtimePathBuf))) {
				std::string	runtimePath(runtimePathBuf, runtimePathLength);

				std::string::size_type	lastSlash = runtimePath.rfind('\\');
				if (lastSlash != std::string::npos) {
					s_runtimeDirectory = runtimePath.substr(0, lastSlash + 1);
				}
			}
		}

		return s_runtimeDirectory;
	}


	const char* GetConfigPath(const char* modName)
	{
		static std::string s_configPath;

		if (s_configPath.empty()) {
			const auto& runtimePath = GetRuntimeDirectory();
			if (!runtimePath.empty()) {
				s_configPath = runtimePath + R"(Data\SKSE\Plugins\)" + modName + R"(.ini)";
				_MESSAGE("config path = %s", s_configPath.c_str());
			}
			else {
				_MESSAGE("couldn't get runtime directory path!");
			}
		}

		return s_configPath.c_str();
	}
}
