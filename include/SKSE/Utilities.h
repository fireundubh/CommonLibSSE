#pragma once


namespace SKSE
{
	const std::string&		 GetRuntimeDirectory();
	const std::string&		 GetPluginFolderPath();
	std::string				 GetPluginConfigPath(const std::string& a_modName);
	std::vector<std::string> GetAllConfigPaths(const std::string& a_folder, const std::string& a_suffix);
}
