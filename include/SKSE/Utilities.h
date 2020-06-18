#pragma once


namespace SKSE
{
	class RNG
	{
	public:
		static RNG* GetSingleton()
		{
			static RNG singleton;
			return &singleton;
		}

		UInt32 GenerateRandomInt(UInt32 a_min, UInt32 a_max);
		float  GenerateRandomFloat(float a_min, float a_max);

	private:
		RNG() :
			twister(std::random_device{}())
		{
		}
		RNG(RNG const&) = delete;
		RNG(RNG&&) = delete;
		~RNG() = default;

		RNG& operator=(RNG const&) = delete;
		RNG& operator=(RNG&&) = delete;

		std::mt19937 twister;
	};

	const std::string&		 GetRuntimeDirectory();
	const std::string&		 GetPluginFolderPath();
	std::string				 GetPluginConfigPath(const char* modName);
	std::vector<std::string> GetAllConfigPaths(const std::string& a_folder, const std::string& a_suffix);
}
