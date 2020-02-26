#pragma once

#include "RE/BSFixedString.h"
#include "RE/NiObject.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class NiExtraData;
	class NiTimeController;


	class NiObjectNET : public NiObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiObjectNET;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiObjectNET;


		virtual ~NiObjectNET();														// 00

		// override (NiObject)
		virtual const NiRTTI* GetRTTI() const override;							// 02
		virtual void			LoadBinary(NiStream& a_stream) override;			// 18
		virtual void			LinkObject(NiStream& a_stream) override;			// 19
		virtual bool			RegisterStreamables(NiStream& a_stream) override;	// 1A
		virtual void			SaveBinary(NiStream& a_stream) override;			// 1B
		virtual bool			IsEqual(NiObject* a_object) override;				// 1C
		virtual void			ProcessClone(NiCloningProcess& a_cloning) override;	// 1D
		virtual void			PostLinkObject(NiStream& a_stream) override;		// 1E

		bool				AddExtraData(const BSFixedString& a_key, NiExtraData* a_extra);
		bool				AddExtraData(NiExtraData* a_extra);
		void				DeleteExtraData(UInt16 a_extraDataIndex);
		NiTimeController* GetControllers() const;
		NiExtraData* GetExtraData(const BSFixedString& a_key) const;
		NiExtraData* GetExtraDataAt(UInt16 a_extraDataIndex) const;
		UInt16				GetExtraDataSize() const;
		bool				InsertExtraData(NiExtraData* a_extra);
		void				RemoveAllExtraData();
		bool				RemoveExtraData(const BSFixedString& a_key);
		bool				RemoveExtraData(NiExtraData* a_extra);
		bool				RemoveExtraDataAt(UInt16 a_extraDataIndex);
		bool				SetExtraDataSize(UInt16 a_size);


		template <class S, class B, class F, class I>
		std::tuple<S, S, B, B, F, I, std::vector<S>, std::vector<S>>GetPO3ExtraData()
		{
			std::tuple<S, S, B, B, F, I, std::vector<S>, std::vector<S>> t;

			if (!extra || extraDataSize == 0) {
				return t;
			}
			for (UInt16 i = 0; i < extraDataSize; i++) {
				auto extraData = extra[i];
				if (extraData) {
					std::string name = extraData->GetName().c_str();
					if (!name.empty()) {
						if (name == "PO3_TOGGLE") {
							std::get<0>(t) = static_cast<S>(extraData);
						}
						else if (name == "PO3_FACETXST") {
							std::get<1>(t) = static_cast<S>(extraData);
						}
						else if (name == "PO3_SKINTINT") {
							std::get<2>(t) = static_cast<B>(extraData);
						}
						else if (name == "PO3_HAIRTINT") {
							std::get<3>(t) = static_cast<B>(extraData);
						}
						else if (name == "PO3_ALPHA") {
							std::get<4>(t) = static_cast<F>(extraData);
						}
						else if (name == "PO3_HEADPARTALPHA") {
							std::get<5>(t) = static_cast<I>(extraData);
						}
						else if (name.find("PO3_TXST") != std::string::npos) {
							std::get<6>(t).push_back(static_cast<S>(extraData));
						}
						else if (name.find("PO3_SKINTXST") != std::string::npos) {
							std::get<7>(t).push_back(static_cast<S>(extraData));
						}
					}
				}
			}
			return t;
		}


		// members
		BSFixedString				name;			// 10
		NiPointer<NiTimeController>	controllers;	// 18
		NiExtraData** extra;			// 20
		UInt16						extraDataSize;	// 28
		UInt16						maxSize;		// 2A
		UInt32						pad2C;			// 2C
	};
	STATIC_ASSERT(sizeof(NiObjectNET) == 0x30);
}
