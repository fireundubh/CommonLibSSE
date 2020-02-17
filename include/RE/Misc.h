#pragma once


namespace RE
{
	class Actor;
	class NiPoint3;
	template <class T> class NiPointer;
	template <class T> class NiRect;
	class Setting;
	class TESObjectREFR;


	void		CreateRefHandle(RefHandle& a_handleOut, TESObjectREFR* a_refrTo);
	void		DebugNotification(const char* a_notification, const char* a_soundToPlay = 0, bool a_cancelIfAlreadyQueued = true);
	Setting*	GetINISetting(const char* a_name);
	bool		LookupReferenceByHandle(const RefHandle& a_handle, NiPointer<Actor>& a_refrOut);
	bool		LookupReferenceByHandle(const RefHandle& a_handle, NiPointer<TESObjectREFR>& a_refrOut);
	void		PlaySound(const char* a_editorID);
	bool		WorldPtToScreenPt3(float a_worldToCamMatrix[4][4], NiRect<float>& a_port, const NiPoint3& a_in, float& a_xOut, float& a_yOut, float& a_zOut, float a_zeroTolerance);
	void		func2E9950(); //FEC - Frame Hook
	void		ShakeCamera(float a_strength, const NiPoint3& a_pos, float a_duration);
}
