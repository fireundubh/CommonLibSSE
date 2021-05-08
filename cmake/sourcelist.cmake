set(sources ${sources}
        src/RE/RTTI.cpp
        src/RE/Skyrim.cpp
        src/RE/AI/AIFormulas.cpp
        src/RE/AI/AIProcess.cpp
        src/RE/AI/ProcessLists.cpp
        src/RE/Animation/IAnimationGraphManagerHolder.cpp
        src/RE/BSAudio/BSAudioManager.cpp
        src/RE/BSAudio/BSSoundHandle.cpp
        src/RE/BSCore/BSAtomic.cpp
        src/RE/BSCore/BSFixedString.cpp
        src/RE/BSCore/BSPointerHandle.cpp
        src/RE/BSCore/BSStringPool.cpp
        src/RE/BSCore/BSTArray.cpp
        src/RE/BSCore/BSTCreateFactoryManager.cpp
        src/RE/BSDevices/BSInputDeviceManager.cpp
        src/RE/BSDevices/ControlMap.cpp
        src/RE/BSDevices/MenuControls.cpp
        src/RE/BSDevices/PlayerControls.cpp
        src/RE/BSDevices/UserEvents.cpp
        src/RE/BSDevices/BSIInputDevice/BSInputDevice/BSInputDevice.cpp
        src/RE/BSDevices/BSIInputDevice/BSInputDevice/BSKeyboardDevice/BSWin32KeyboardDevice.cpp
        src/RE/BSDevices/MenuEventHandler/MenuEventHandler.cpp
        src/RE/BSDevices/PlayerInputHandler/PlayerInputHandler.cpp
        src/RE/BSExtraData/BSExtraData.cpp
        src/RE/BSExtraData/ExtraAliasInstanceArray.cpp
        src/RE/BSExtraData/ExtraAshPileRef.cpp
        src/RE/BSExtraData/ExtraCannotWear.cpp
        src/RE/BSExtraData/ExtraCanTalkToPlayer.cpp
        src/RE/BSExtraData/ExtraCharge.cpp
        src/RE/BSExtraData/ExtraContainerChanges.cpp
        src/RE/BSExtraData/ExtraCount.cpp
        src/RE/BSExtraData/ExtraEnchantment.cpp
        src/RE/BSExtraData/ExtraForcedTarget.cpp
        src/RE/BSExtraData/ExtraHealth.cpp
        src/RE/BSExtraData/ExtraHotkey.cpp
        src/RE/BSExtraData/ExtraLightData.cpp
        src/RE/BSExtraData/ExtraLock.cpp
        src/RE/BSExtraData/ExtraMissingLinkedRefIDs.cpp
        src/RE/BSExtraData/ExtraNorthRotation.cpp
        src/RE/BSExtraData/ExtraOwnership.cpp
        src/RE/BSExtraData/ExtraPoison.cpp
        src/RE/BSExtraData/ExtraRank.cpp
        src/RE/BSExtraData/ExtraReferenceHandle.cpp
        src/RE/BSExtraData/ExtraSoul.cpp
        src/RE/BSExtraData/ExtraTerminalState.cpp
        src/RE/BSExtraData/ExtraTextDisplayData.cpp
        src/RE/BSExtraData/ExtraUniqueID.cpp
        src/RE/BSGraphics/State.cpp
        src/RE/BSHavok/hkBaseTypes.cpp
        src/RE/BSHavok/hkpMaterial.cpp
        src/RE/BSHavok/hkStringPtr.cpp
        src/RE/BSHavok/hkVector4.cpp
        src/RE/BSHavok/TESHavokUtilities.cpp
        src/RE/BSHavok/hkBaseObject/hkReferencedObject/hkReferencedObject.cpp
        src/RE/BSHavok/hkBaseObject/hkReferencedObject/hkpBroadPhase/hkpBroadPhase.cpp
        src/RE/BSHavok/hkBaseObject/hkReferencedObject/hkpShape/hkpSphereRepShape/hkpConvexShape/hkpBoxShape.cpp
        src/RE/BSHavok/hkBaseObject/hkReferencedObject/hkpShape/hkpSphereRepShape/hkpConvexShape/hkpConvexShape.cpp
        src/RE/BSHavok/hkBaseObject/hkReferencedObject/hkpWorldObject/hkpWorldObject.cpp
        src/RE/BSHavok/hkBaseObject/hkReferencedObject/hkpWorldObject/hkpEntity/hkpEntity.cpp
        src/RE/BSHavok/hkMemoryAllocator/hkContainerAllocators.cpp
        src/RE/BSHavok/hkpBroadPhaseHandle/hkpTypedBroadPhaseHandle.cpp
        src/RE/BSHavok/hkpBroadPhaseHandlePair/hkpTypedBroadPhaseHandlePair.cpp
        src/RE/BSHavok/hkpCdBody/hkpCdBody.cpp
        src/RE/BSHavok/hkpCdBody/hkpCollidable/hkpCollidable.cpp
        src/RE/BSHavok/hkpCharacterProxyListener/bhkCharProxyController.cpp
        src/RE/BSHavok/hkpCharacterProxyListener/hkpCharacterProxyListener.cpp
        src/RE/BSMain/BSHandleRefObject.cpp
        src/RE/BSMain/Main.cpp
        src/RE/BSMain/Setting/Setting.cpp
        src/RE/BSMain/SettingCollection/GameSettingCollection.cpp
        src/RE/BSMain/SettingCollection/INIPrefSettingCollection.cpp
        src/RE/BSMain/SettingCollection/INISettingCollection.cpp
        src/RE/BSResource/BSSystemFile.cpp
        src/RE/BSResource/Location/Location.cpp
        src/RE/BSResource/StreamBase/StreamBase.cpp
        src/RE/BSResource/StreamBase/Stream/LooseFileStream.cpp
        src/RE/BSResource/StreamBase/Stream/Stream.cpp
        src/RE/BSScript/Array.cpp
        src/RE/BSScript/IObjectHandlePolicy.cpp
        src/RE/BSScript/IStackCallbackFunctor.cpp
        src/RE/BSScript/IVirtualMachine.cpp
        src/RE/BSScript/MemoryPage.cpp
        src/RE/BSScript/Object.cpp
        src/RE/BSScript/ObjectBindPolicy.cpp
        src/RE/BSScript/ObjectTypeInfo.cpp
        src/RE/BSScript/PackUnpack.cpp
        src/RE/BSScript/Stack.cpp
        src/RE/BSScript/StackFrame.cpp
        src/RE/BSScript/TypeInfo.cpp
        src/RE/BSScript/Variable.cpp
        src/RE/BSScript/ByteCode/PackedInstructionStream.cpp
        src/RE/BSScript/IFunction/IFunction.cpp
        src/RE/BSScript/IFunction/NF_util/NativeFunctionBase.cpp
        src/RE/BSScript/IFunctionArguments/ZeroFunctionArguments.cpp
        src/RE/BSScript/Internal/VirtualMachine.cpp
        src/RE/BSShader/BSEffectShaderData.cpp
        src/RE/BSShader/BSShaderMaterial/BSLightingShaderMaterial.cpp
        src/RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase.cpp
        src/RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialEnvmap.cpp
        src/RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialEye.cpp
        src/RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialFacegen.cpp
        src/RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialFacegenTint.cpp
        src/RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialGlowmap.cpp
        src/RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialHairTint.cpp
        src/RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialLandscape.cpp
        src/RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialLODLandscape.cpp
        src/RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialMultiLayerParallax.cpp
        src/RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialParallax.cpp
        src/RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialParallaxOcc.cpp
        src/RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialSnow.cpp
        src/RE/BSSystem/BSSaveDataSystemUtility/BSWin32SaveDataSystemUtility.cpp
        src/RE/BSSystem/BSStorage/BSSystemFileStorage.cpp
        src/RE/BSSystem/IFormFactory/IFormFactory.cpp
        src/RE/Camera/TESCamera/LocalMapCamera.cpp
        src/RE/Camera/TESCamera/PlayerCamera.cpp
        src/RE/Camera/TESCamera/TESCamera.cpp
        src/RE/Camera/TESCamera/ThirdPersonState.cpp
        src/RE/Color/ColorBlending.cpp
        src/RE/Combat/CombatManager.cpp
        src/RE/Events/BGSFootstepManager.cpp
        src/RE/Events/BGSStoryEvent/ActorKill.cpp
        src/RE/Events/BGSStoryEvent/BooksRead.cpp
        src/RE/Events/BGSStoryEvent/ChestsLooted.cpp
        src/RE/Events/BGSStoryEvent/CriticalHit.cpp
        src/RE/Events/BGSStoryEvent/DisarmedEvent.cpp
        src/RE/Events/BGSStoryEvent/DragonSoulsGained.cpp
        src/RE/Events/BGSStoryEvent/Inventory.cpp
        src/RE/Events/BGSStoryEvent/ItemCrafted.cpp
        src/RE/Events/BGSStoryEvent/ItemHarvested.cpp
        src/RE/Events/BGSStoryEvent/ItemsPickpocketed.cpp
        src/RE/Events/BGSStoryEvent/LevelIncrease.cpp
        src/RE/Events/BGSStoryEvent/LocationDiscovery.cpp
        src/RE/Events/BGSStoryEvent/ShoutAttack.cpp
        src/RE/Events/BGSStoryEvent/SkillIncrease.cpp
        src/RE/Events/BGSStoryEvent/SoulsTrapped.cpp
        src/RE/Events/BGSStoryEvent/SpellsLearned.cpp
        src/RE/Events/InputEvent/InputEvent.cpp
        src/RE/Events/InputEvent/ThumbstickEvent.cpp
        src/RE/Events/ScriptEvent/ScriptEventSourceHolder.cpp
        src/RE/Events/ScriptEvent/TESHitEvent.cpp
        src/RE/FileIO/BGSSaveLoadManager.cpp
        src/RE/FileIO/TESDataHandler.cpp
        src/RE/FileIO/TESFile.cpp
        src/RE/FileIO/ICellAttachDetachEventSource/TES.cpp
        src/RE/FormComponents/BGSBipedObjectForm.cpp
        src/RE/FormComponents/BGSKeywordForm.cpp
        src/RE/FormComponents/BGSPerkRankArray.cpp
        src/RE/FormComponents/TESActorBaseData.cpp
        src/RE/FormComponents/TESAIForm.cpp
        src/RE/FormComponents/TESContainer.cpp
        src/RE/FormComponents/TESDescription.cpp
        src/RE/FormComponents/TESForm.cpp
        src/RE/FormComponents/TESLeveledList.cpp
        src/RE/FormComponents/TESSpellList.cpp
        src/RE/FormComponents/Components/ActorCause.cpp
        src/RE/FormComponents/Components/ActorValueOwner.cpp
        src/RE/FormComponents/Components/BGSOpenCloseForm.cpp
        src/RE/FormComponents/Components/BipedAnim.cpp
        src/RE/FormComponents/Components/BSResponse.cpp
        src/RE/FormComponents/Components/Color.cpp
        src/RE/FormComponents/Components/ContainerItemExtra.cpp
        src/RE/FormComponents/Components/DialogueItem.cpp
        src/RE/FormComponents/Components/Effect.cpp
        src/RE/FormComponents/Components/IHandlerFunctor.cpp
        src/RE/FormComponents/Components/MagicTarget.cpp
        src/RE/FormComponents/Components/TESCondition.cpp
        src/RE/FormComponents/Components/ActiveEffect/ActiveEffect.cpp
        src/RE/FormComponents/Components/BGSBaseAlias/BGSBaseAlias.cpp
        src/RE/FormComponents/Components/BGSBaseAlias/BGSRefAlias.cpp
        src/RE/FormComponents/Components/BGSEntryPointFunctionData/BGSEntryPointFunctionDataActivateChoice.cpp
        src/RE/FormComponents/Components/BGSPerkEntry/BGSEntryPointPerkEntry.cpp
        src/RE/FormComponents/Components/BGSPerkEntry/BGSPerkEntry.cpp
        src/RE/FormComponents/TESForm/BGSColorForm.cpp
        src/RE/FormComponents/TESForm/BGSDefaultObjectManager.cpp
        src/RE/FormComponents/TESForm/BGSHeadPart.cpp
        src/RE/FormComponents/TESForm/BGSListForm.cpp
        src/RE/FormComponents/TESForm/BGSLocation.cpp
        src/RE/FormComponents/TESForm/BGSMaterialType.cpp
        src/RE/FormComponents/TESForm/BGSSoundCategory.cpp
        src/RE/FormComponents/TESForm/EffectSetting.cpp
        src/RE/FormComponents/TESForm/Script.cpp
        src/RE/FormComponents/TESForm/TESClimate.cpp
        src/RE/FormComponents/TESForm/TESFaction.cpp
        src/RE/FormComponents/TESForm/TESObjectCELL.cpp
        src/RE/FormComponents/TESForm/TESPackage.cpp
        src/RE/FormComponents/TESForm/TESRace.cpp
        src/RE/FormComponents/TESForm/TESTopic.cpp
        src/RE/FormComponents/TESForm/TESTopicInfo.cpp
        src/RE/FormComponents/TESForm/TESWorldSpace.cpp
        src/RE/FormComponents/TESForm/BGSKeyword/BGSKeyword.cpp
        src/RE/FormComponents/TESForm/BGSStoryManagerTreeForm/TESQuest.cpp
        src/RE/FormComponents/TESForm/TESObject/TESObjectARMA.cpp
        src/RE/FormComponents/TESForm/TESObject/TESBoundObject/BGSProjectile.cpp
        src/RE/FormComponents/TESForm/TESObject/TESBoundObject/TESAmmo.cpp
        src/RE/FormComponents/TESForm/TESObject/TESBoundObject/TESObjectARMO.cpp
        src/RE/FormComponents/TESForm/TESObject/TESBoundObject/TESObjectBOOK.cpp
        src/RE/FormComponents/TESForm/TESObject/TESBoundObject/TESObjectWEAP.cpp
        src/RE/FormComponents/TESForm/TESObject/TESBoundObject/MagicItem/MagicItem.cpp
        src/RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundAnimObject/TESActorBase/TESNPC.cpp
        src/RE/FormComponents/TESForm/TESObject/TESBoundObject/TESObjectSTAT/TESObjectSTAT.cpp
        src/RE/FormComponents/TESForm/TESObjectREFR/TESObjectREFR.cpp
        src/RE/FormComponents/TESForm/TESObjectREFR/Actor/Actor.cpp
        src/RE/FormComponents/TESForm/TESObjectREFR/Actor/Character/PlayerCharacter.cpp
        src/RE/FormComponents/TESForm/TESObjectREFR/Projectile/ConeProjectile.cpp
        src/RE/FormComponents/TESForm/TESObjectREFR/Projectile/Projectile.cpp
        src/RE/Inventory/ActorEquipManager.cpp
        src/RE/Inventory/ExtraDataList.cpp
        src/RE/Inventory/Inventory3DManager.cpp
        src/RE/Inventory/InventoryChanges.cpp
        src/RE/Inventory/InventoryEntryData.cpp
        src/RE/Memory/HeapBlock.cpp
        src/RE/Memory/MemoryManager.cpp
        src/RE/Memory/IMemoryStoreBase/IMemoryStore/IMemoryStore.cpp
        src/RE/Memory/IMemoryStoreBase/IMemoryStore/ScrapHeap.cpp
        src/RE/Menus/ConsoleLog.cpp
        src/RE/Menus/InterfaceStrings.cpp
        src/RE/Menus/MagicFavorites.cpp
        src/RE/Menus/UI.cpp
        src/RE/Menus/UIBlurManager.cpp
        src/RE/Menus/UIMessageQueue.cpp
        src/RE/Menus/HUDObject/HUDObject.cpp
        src/RE/Menus/HUDObject/HUDMeter/HUDMeter.cpp
        src/RE/Menus/IMenu/Console.cpp
        src/RE/Menus/IMenu/IMenu.cpp
        src/RE/Menus/IMenu/Components/ItemList.cpp
        src/RE/Menus/IUIMessageData/MessageBoxData.cpp
        src/RE/Misc/ActorValueList.cpp
        src/RE/Misc/BGSDecalManager.cpp
        src/RE/Misc/BGSImpactManager.cpp
        src/RE/Misc/BGSWaterSystemManager.cpp
        src/RE/Misc/BSTaskPool.cpp
        src/RE/Misc/Calendar.cpp
        src/RE/Misc/FaceGen.cpp
        src/RE/Misc/FixedStrings.cpp
        src/RE/Misc/Misc.cpp
        src/RE/Misc/TaskQueueInterface.cpp
        src/RE/Misc/VATSManager.cpp
        src/RE/NetImmerse/BSVisit.cpp
        src/RE/NetImmerse/NiColor.cpp
        src/RE/NetImmerse/NiMath.cpp
        src/RE/NetImmerse/NiMatrix3.cpp
        src/RE/NetImmerse/NiMemManager.cpp
        src/RE/NetImmerse/NiPoint3.cpp
        src/RE/NetImmerse/NiSystem.cpp
        src/RE/NetImmerse/NiTCollection.cpp
        src/RE/NetImmerse/NiAnimationKey/NiAnimationKey.cpp
        src/RE/NetImmerse/NiAnimationKey/NiColorKey.cpp
        src/RE/NetImmerse/NiAnimationKey/NiFloatKey.cpp
        src/RE/NetImmerse/NiBinaryStream/BSResourceNiBinaryStream.cpp
        src/RE/NetImmerse/NiBinaryStream/NiBinaryStream.cpp
        src/RE/NetImmerse/NiRefObject/BGSAttackData.cpp
        src/RE/NetImmerse/NiRefObject/NiRefObject.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiColorData.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiFloatData.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiObject.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiSkinInstance.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiSkinPartition.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/bhkRefObject/bhkSerializable/bhkWorldObject/bhkWorldObject.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/BSTextureSet/BSShaderTextureSet.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiExtraData/BSFaceGenAnimationData.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiExtraData/NiBooleanExtraData.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiExtraData/NiExtraData.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiExtraData/NiFloatExtraData.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiExtraData/NiIntegersExtraData.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiExtraData/NiStringsExtraData.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiExtraData/NiIntegerExtraData/BSXFlags.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiExtraData/NiIntegerExtraData/NiIntegerExtraData.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiInterpolator/NiInterpolator.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiObjectNET.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiAVObject/NiAVObject.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiAVObject/NiCamera.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiAVObject/BSGeometry/BSGeometry.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiAVObject/BSGeometry/BSTrishape.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiAVObject/NiNode/NiNode.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiProperty/NiShadeProperty/BSShaderProperty/BSShaderProperty.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiProperty/BSLightingShaderProperty.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiProperty/NiAlphaProperty.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiSkinInstance/BSDismemberSkinInstance.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiTexture/NiSourceTexture.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiTexture/NiTexture.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiTimeController/NiControllerManager.cpp
        src/RE/NetImmerse/NiRefObject/NiObject/NiTimeController/NiTimeController.cpp
        src/RE/Obscript/CommandTable.cpp
        src/RE/RadiantStory/BGSStoryTeller.cpp
        src/RE/Scaleform/BS/BSScaleformManager.cpp
        src/RE/Scaleform/FxGameDelegate/AddCallbackVisitor.cpp
        src/RE/Scaleform/FxGameDelegate/FxDelegate.cpp
        src/RE/Scaleform/FxGameDelegate/FxDelegateArgs.cpp
        src/RE/Scaleform/FxGameDelegate/RemoveCallbackVisitor.cpp
        src/RE/Scaleform/GAtomic/GAtomic.cpp
        src/RE/Scaleform/GFxLoader/GFxLoader.cpp
        src/RE/Scaleform/GFxLoader/GFxState.cpp
        src/RE/Scaleform/GFxLoader/GFxStateBag.cpp
        src/RE/Scaleform/GFxLoader/GFxTranslator.cpp
        src/RE/Scaleform/GFxLog/GFxLog.cpp
        src/RE/Scaleform/GFxPlayer/GFxMovie.cpp
        src/RE/Scaleform/GFxPlayer/GFxMovieDef.cpp
        src/RE/Scaleform/GFxPlayer/GFxMovieView.cpp
        src/RE/Scaleform/GFxPlayer/GFxValue.cpp
        src/RE/Scaleform/GFxRenderConfig/GFxRenderConfig.cpp
        src/RE/Scaleform/GFxResource/GFxResource.cpp
        src/RE/Scaleform/GFxResource/GFxResourceID.cpp
        src/RE/Scaleform/GFxResource/GFxResourceKey.cpp
        src/RE/Scaleform/GFxString/GFxWStringBuffer.cpp
        src/RE/Scaleform/GFxWWHelper/GFxWWHelper.cpp
        src/RE/Scaleform/GMemory/GMemory.cpp
        src/RE/Scaleform/GMemoryHeap/GMemoryHeap.cpp
        src/RE/Scaleform/GRefCount/GRefCountImpl.cpp
        src/RE/Scaleform/GRefCount/GRefCountNTSImpl.cpp
        src/RE/Scaleform/GRenderer/GRenderer.cpp
        src/RE/Scaleform/GRenderer/GViewport.cpp
        src/RE/Scaleform/GStd/GStd.cpp
        src/RE/Scaleform/GString/GString.cpp
        src/RE/Sky/Sky.cpp
        src/RE/SkyrimScript/SkyrimVM.cpp
        src/SKSE/API.cpp
        src/SKSE/IAT.cpp
        src/SKSE/Interfaces.cpp
        src/SKSE/Logger.cpp
        src/SKSE/RegistrationMap.cpp
        src/SKSE/RegistrationMapUnique.cpp
        src/SKSE/RegistrationSet.cpp
        src/SKSE/RegistrationSetUnique.cpp
        src/SKSE/Trampoline.cpp
        src/SKSE/Utilities.cpp
        src/SKSE/Impl/PCH.cpp
)
