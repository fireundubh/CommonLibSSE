#include "RE/Misc/Misc.h"

#include "RE/BSCore/BSTCreateFactoryManager.h"
#include "RE/BSCore/IBSTCreator/BSTDerivedCreator.h"
#include "RE/BSMain/Setting/Setting.h"
#include "RE/BSMain/SettingCollection/GameSettingCollection.h"
#include "RE/BSMain/SettingCollection/INIPrefSettingCollection.h"
#include "RE/BSMain/SettingCollection/INISettingCollection.h"
#include "RE/FormComponents/TESForm/TESObjectREFR/TESObjectREFR.h"
#include "RE/Menus/IUIMessageData/MessageBoxData.h"
#include "RE/Menus/InterfaceStrings.h"
#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	bool LookupReferenceByHandle_ActorImpl(const RefHandle& a_handle, NiPointer<Actor>& a_refrOut)
	{
		using func_t = decltype(&LookupReferenceByHandle_ActorImpl);
		REL::Relocation<func_t> func{ Offset::LookupReferenceByHandle };
		return func(a_handle, a_refrOut);
	}


	bool LookupReferenceByHandle_RefrImpl(const RefHandle& a_handle, NiPointer<TESObjectREFR>& a_refrOut)
	{
		using func_t = decltype(&LookupReferenceByHandle_RefrImpl);
		REL::Relocation<func_t> func{ Offset::LookupReferenceByHandle };
		return func(a_handle, a_refrOut);
	}


	void CreateRefHandle(RefHandle& a_handleOut, TESObjectREFR* a_refTo)
	{
		using func_t = decltype(&CreateRefHandle);
		REL::Relocation<func_t> func{ Offset::CreateRefHandle };
		return func(a_handleOut, a_refTo);
	}


	void DebugNotification(const char* a_notification, const char* a_soundToPlay, bool a_cancelIfAlreadyQueued)
	{
		using func_t = decltype(&DebugNotification);
		REL::Relocation<func_t> func{ Offset::DebugNotification };
		return func(a_notification, a_soundToPlay, a_cancelIfAlreadyQueued);
	}


	Setting* GetINISetting(const char* a_name)
	{
		Setting* setting = nullptr;

		auto iniPrefs = INIPrefSettingCollection::GetSingleton();
		setting = iniPrefs ? iniPrefs->GetSetting(a_name) : nullptr;
		if (!setting) {
			auto ini = INISettingCollection::GetSingleton();
			setting = ini ? ini->GetSetting(a_name) : nullptr;
		}
		return setting;
	}


	bool LookupReferenceByHandle(const RefHandle& a_handle, NiPointer<Actor>& a_refrOut)
	{
		return LookupReferenceByHandle_ActorImpl(a_handle, a_refrOut);
	}


	bool LookupReferenceByHandle(const RefHandle& a_handle, NiPointer<TESObjectREFR>& a_refrOut)
	{
		return LookupReferenceByHandle_RefrImpl(a_handle, a_refrOut);
	}


	void PlaySound(const char* a_editorID)
	{
		using func_t = decltype(&PlaySound);
		REL::Relocation<func_t> func{ Offset::PlaySound };
		return func(a_editorID);
	}


	void ShowMessageBox(const std::string& a_message)
	{
		auto factoryManager = MessageDataFactoryManager::GetSingleton();
		auto uiStrHolder = InterfaceStrings::GetSingleton();

		if (factoryManager && uiStrHolder) {
			auto factory = factoryManager->GetCreator<MessageBoxData>(uiStrHolder->messageBoxData);
			if (factory) {
				auto messageBox = factory->Create();
				if (messageBox) {
					messageBox->unk4C = 4;
					messageBox->unk38 = 10;
					messageBox->bodyText = a_message.c_str();
					auto gameSettings = GameSettingCollection::GetSingleton();
					if (gameSettings) {
						auto sOk = gameSettings->GetSetting("sOk");
						if (sOk) {
							messageBox->buttonText.push_back(sOk->GetString());
							messageBox->QueueMessage();
						}
					}
				}
			}
		}
	}


	void func2E9950()  //FEC frame hook
	{
		using func_t = decltype(&func2E9950);
		REL::Relocation<func_t> func{ REL::ID(21434) };
		return func();
	}


	namespace Util
	{
		void SanitizeTexturePath(std::string& a_path)
		{
			std::transform(a_path.begin(), a_path.end(), a_path.begin(), ::tolower);

			a_path = std::regex_replace(a_path, std::regex("/+|\\\\+"), "\\");
			a_path = std::regex_replace(a_path, std::regex("^\\\\+"), "");
			a_path = std::regex_replace(a_path, std::regex(R"(.*?[^\s]textures\\|^textures\\)", std::regex_constants::icase), "");
		}


		std::string GetTextureName(std::string& a_path)
		{
			const auto idx = a_path.find_last_of("\\/");
			if (std::string::npos != idx) {
				return a_path.substr(idx + 1);
			}
			return std::string();
		}
	}
}
