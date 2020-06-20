#pragma once

#include "REL/Relocation.h"


namespace RE
{
	namespace Offset
	{
		namespace ActivateHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263060));
		}


		namespace ActiveEffect
		{
			inline constexpr REL::ID Dispell(static_cast<std::uint64_t>(33286));
		}


		namespace Actor
		{
			inline constexpr REL::ID AddSpell(static_cast<std::uint64_t>(37771));
			inline constexpr REL::ID DispelWornItemEnchantments(static_cast<std::uint64_t>(33828));
			inline constexpr REL::ID DoReset3D(static_cast<std::uint64_t>(39181));
			inline constexpr REL::ID Decapitate(static_cast<std::uint64_t>(36631));
			inline constexpr REL::ID EvaluatePackage(static_cast<std::uint64_t>(36407));
			inline constexpr REL::ID GetGhost(static_cast<std::uint64_t>(36286));
			inline constexpr REL::ID GetHostileToActor(static_cast<std::uint64_t>(36537));
			inline constexpr REL::ID GetLevel(static_cast<std::uint64_t>(36344));
			inline constexpr REL::ID GetSoulLevel(static_cast<std::uint64_t>(37862));
			inline constexpr REL::ID HasPerk(static_cast<std::uint64_t>(36690));
			inline constexpr REL::ID HasSpell(static_cast<std::uint64_t>(37828));
			inline constexpr REL::ID InstantKill(static_cast<std::uint64_t>(36723));
			inline constexpr REL::ID IsRunning(static_cast<std::uint64_t>(36252));
			inline constexpr REL::ID RemoveSpell(static_cast<std::uint64_t>(37772));
			inline constexpr REL::ID RequestDetectionLevel(static_cast<std::uint64_t>(36748));
			inline constexpr REL::ID StealAlarm(static_cast<std::uint64_t>(36427));
			inline constexpr REL::ID SwitchRace(static_cast<std::uint64_t>(36901));
			inline constexpr REL::ID UpdateArmorAbility(static_cast<std::uint64_t>(37802));
			inline constexpr REL::ID UpdateWeaponAbility(static_cast<std::uint64_t>(37803));
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(260538));
		}


		namespace ActorEquipManager
		{
			inline constexpr REL::ID EquipObject(static_cast<std::uint64_t>(37938));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514494));
			inline constexpr REL::ID UnequipObject(static_cast<std::uint64_t>(37945));
		}


		namespace ActorValueList
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514139));
		}


		namespace ActorValueOwner
		{
			inline constexpr REL::ID GetClampedActorValue(static_cast<std::uint64_t>(26616));
		}


		namespace AIProcess
		{
			inline constexpr REL::ID SetActorRefraction(static_cast<std::uint64_t>(38916));
			inline constexpr REL::ID SetBaseScale(static_cast<std::uint64_t>(38568));
			inline constexpr REL::ID Update3DModel(static_cast<std::uint64_t>(38404));
		}


		namespace AttackBlockHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263058));
		}


		namespace AutoMoveHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263061));
		}


		namespace BGSDecalManager
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514414));
		}


		namespace BGSDefaultObjectManager
		{
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(10878));
		}


		namespace BGSFootstepManager
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(517045));
		}


		namespace BGSImpactManager
		{
			inline constexpr REL::ID PlayImpactEffect(static_cast<std::uint64_t>(35320));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(515123));
		}


		namespace BGSListForm
		{
			inline constexpr REL::ID AddForm(static_cast<std::uint64_t>(20470));
		}


		namespace BGSSaveLoadManager
		{
			inline constexpr REL::ID Save(static_cast<std::uint64_t>(34818));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(516860));
			inline constexpr REL::ID Load(static_cast<std::uint64_t>(34819));
		}


		namespace BGSListForm
		{
			inline constexpr REL::ID AddFormToList(static_cast<std::uint64_t>(20470));
		}


		namespace BGSStoryTeller
		{
			inline constexpr REL::ID BeginShutDownQuest(static_cast<std::uint64_t>(31718));
			inline constexpr REL::ID BeginStartUpQuest(static_cast<std::uint64_t>(31717));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514316));
		}


		namespace BipedAnim
		{
			inline constexpr REL::ID Dtor(static_cast<std::uint64_t>(15491));
			inline constexpr REL::ID RemoveAllParts(static_cast<std::uint64_t>(15494));
		}


		namespace BSAudioManager
		{
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(66391));
			inline constexpr REL::ID BuildSoundDataFromDescriptor(static_cast<std::uint64_t>(66404));
		}


		namespace BSInputDeviceManager
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(516574));
		}


		namespace BSLightingShaderMaterialBase
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(100004));
		}


		namespace BSLightingShaderMaterial
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(254404));
		}


		namespace BSLightingShaderMaterialEnvmap
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(100021));
		}


		namespace BSLightingShaderMaterialEye
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(100033));
		}


		namespace BSLightingShaderMaterialFacegen
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(100077));
		}


		namespace BSLightingShaderMaterialFacegenTint
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(100087));
		}


		namespace BSLightingShaderMaterialGlowmap
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(100045));
		}


		namespace BSLightingShaderMaterialHairTint
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(100095));
		}


		namespace BSLightingShaderMaterialMultiLayerParallax
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(100125));
		}


		namespace BSLightingShaderMaterialLandscape
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(100102));
		}


		namespace BSLightingShaderMaterialLODLandscape
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(100110));
		}


		namespace BSLightingShaderMaterialParallax
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(100055));
		}


		namespace BSLightingShaderMaterialParallaxOcc
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(100065));
		}


		namespace BSLightingShaderMaterialSnow
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(100118));
		}


		namespace BSLightingShaderProperty
		{
			inline constexpr REL::ID InvalidateTextures(static_cast<std::uint64_t>(99865));
		}


		namespace BSReadWriteLock
		{
			inline constexpr REL::ID LockForRead(static_cast<std::uint64_t>(66976));
			inline constexpr REL::ID LockForWrite(static_cast<std::uint64_t>(66977));
			inline constexpr REL::ID UnlockForRead(static_cast<std::uint64_t>(66982));
			inline constexpr REL::ID UnlockForWrite(static_cast<std::uint64_t>(66983));
		}


		namespace BSResourceNiBinaryStream
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(69636));
			inline constexpr REL::ID Dtor(static_cast<std::uint64_t>(69638));
			inline constexpr REL::ID Seek(static_cast<std::uint64_t>(69640));
			inline constexpr REL::ID SetEndianSwap(static_cast<std::uint64_t>(69643));
		}


		namespace BSShaderProperty
		{
			inline constexpr REL::ID InvalidateMaterial(static_cast<std::uint64_t>(14678));
			inline constexpr REL::ID SetBSEffectShaderData(static_cast<std::uint64_t>(16981));
			inline constexpr REL::ID SetFlags(static_cast<std::uint64_t>(98893));
			inline constexpr REL::ID SetMaterial(static_cast<std::uint64_t>(98897));
		}


		namespace BSScaleformTranslator
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(291278));
		}


		namespace BSScript
		{
			namespace ObjectTypeInfo
			{
				inline constexpr REL::ID ReleaseData(static_cast<std::uint64_t>(97538));
			}


			namespace ObjectBindPolicy
			{
				inline constexpr REL::ID BindObject(static_cast<std::uint64_t>(97379));
			}


			namespace NF_util
			{
				namespace NativeFunctionBase
				{
					inline constexpr REL::ID Call(static_cast<std::uint64_t>(97923));
				}
			}


			namespace Stack
			{
				inline constexpr REL::ID Dtor(static_cast<std::uint64_t>(97742));
			}
		}


		namespace BSShaderTextureSet
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(99886));
		}


		namespace BSSoundHandle
		{
			inline constexpr REL::ID IsValid(static_cast<std::uint64_t>(66360));
			inline constexpr REL::ID Play(static_cast<std::uint64_t>(66355));
			inline constexpr REL::ID SetObjectToFollow(static_cast<std::uint64_t>(66375));
			inline constexpr REL::ID SetPosition(static_cast<std::uint64_t>(66370));
			inline constexpr REL::ID Stop(static_cast<std::uint64_t>(66358));
		}


		namespace BSString
		{
			inline constexpr REL::ID Set_CStr(static_cast<std::uint64_t>(10979));
		}


		namespace BSTaskPool
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(517228));
		}


		namespace BSTriShape
		{
			inline constexpr REL::ID Create(static_cast<std::uint64_t>(69284));
		}


		namespace BSUntypedPointerHandle
		{
			inline constexpr REL::ID NullHandle(static_cast<std::uint64_t>(514164));
		}


		namespace BucketTable
		{
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(67855));
		}


		namespace BSWin32SaveDataSystemUtility
		{
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(101884));
		}


		namespace Calendar
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514287));
		}


		namespace ChestsLooted
		{
			inline constexpr REL::ID GetEventSource(static_cast<std::uint64_t>(50257));
		}


		namespace CombatManager
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(518706));
		}


		namespace Console
		{
			inline constexpr REL::ID SelectedRef(static_cast<std::uint64_t>(519394));
			inline constexpr REL::ID SetSelectedRef(static_cast<std::uint64_t>(50164));
		}


		namespace ConsoleLog
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(515064));
			inline constexpr REL::ID VPrint(static_cast<std::uint64_t>(50180));
		}


		namespace ControlMap
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514705));
		}


		namespace CRC32Calculator
		{
			inline constexpr REL::ID SizeOf32(static_cast<std::uint64_t>(66963));
			inline constexpr REL::ID SizeOf64(static_cast<std::uint64_t>(66964));
			inline constexpr REL::ID SizeOfSize(static_cast<std::uint64_t>(66962));
		}


		namespace DialogueItem
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(34413));
		}


		namespace ExtraAliasInstanceArray
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229615));
		}


		namespace ExtraAshPileRef
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229561));
		}


		namespace ExtraCannotWear
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229540));
		}


		namespace ExtraCanTalkToPlayer
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229596));
		}


		namespace ExtraCharge
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229544));
		}


		namespace ExtraContainerChanges
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229886));
		}


		namespace ExtraCount
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229537));
		}


		namespace ExtraDataList
		{
			inline constexpr REL::ID Add(static_cast<std::uint64_t>(12176));
			inline constexpr REL::ID SetExtraFlags(static_cast<std::uint64_t>(11903));
			inline constexpr REL::ID SetInventoryChanges(static_cast<std::uint64_t>(11483));
		}


		namespace ExtraEnchantment
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229574));
		}


		namespace ExtraForcedTarget
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229629));
		}


		namespace ExtraHealth
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229541));
		}


		namespace ExtraHotkey
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229547));
		}


		namespace ExtraLightData
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229618));
		}


		namespace ExtraLock
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229527));
		}


		namespace ExtraOwnership
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229534));
		}


		namespace ExtraPoison
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229573));
		}


		namespace ExtraRank
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229536));
		}


		namespace ExtraReferenceHandle
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229549));
		}


		namespace ExtraSoul
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229890));
		}


		namespace ExtraUniqueID
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229631));
		}


		namespace FaceGen
		{
			inline constexpr REL::ID RegenerateHead(static_cast<std::uint64_t>(26259));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514182));
		}


		namespace FavoritesHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(269539));
		}


		namespace FavoritesMenu
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(268638));
		}


		namespace FirstPersonState
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(267810));
		}


		namespace GameSettingCollection
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514622));
		}


		namespace GFxLoader
		{
			inline constexpr REL::ID CreateMovie(static_cast<std::uint64_t>(80620));
		}


		namespace GFxMovieView
		{
			inline constexpr REL::ID InvokeNoReturn(static_cast<std::uint64_t>(80547));
		}


		namespace GFxValue
		{
			namespace ObjectInterface
			{
				inline constexpr REL::ID AttachMovie(static_cast<std::uint64_t>(80197));
				inline constexpr REL::ID DeleteMember(static_cast<std::uint64_t>(80207));
				inline constexpr REL::ID GetArraySize(static_cast<std::uint64_t>(80214));
				inline constexpr REL::ID GetDisplayInfo(static_cast<std::uint64_t>(80216));
				inline constexpr REL::ID GetElement(static_cast<std::uint64_t>(80218));
				inline constexpr REL::ID GetMember(static_cast<std::uint64_t>(80222));
				inline constexpr REL::ID GotoAndPlay(static_cast<std::uint64_t>(80230));
				inline constexpr REL::ID HasMember(static_cast<std::uint64_t>(80231));
				inline constexpr REL::ID Invoke(static_cast<std::uint64_t>(80233));
				inline constexpr REL::ID ObjectAddRef(static_cast<std::uint64_t>(80244));
				inline constexpr REL::ID ObjectRelease(static_cast<std::uint64_t>(80245));
				inline constexpr REL::ID PushBack(static_cast<std::uint64_t>(80248));
				inline constexpr REL::ID RemoveElements(static_cast<std::uint64_t>(80252));
				inline constexpr REL::ID SetArraySize(static_cast<std::uint64_t>(80261));
				inline constexpr REL::ID SetDisplayInfo(static_cast<std::uint64_t>(80263));
				inline constexpr REL::ID SetElement(static_cast<std::uint64_t>(80265));
				inline constexpr REL::ID SetMember(static_cast<std::uint64_t>(80268));
				inline constexpr REL::ID SetText(static_cast<std::uint64_t>(80270));
			}
		}


		namespace GMemory
		{
			inline constexpr REL::ID GlobalHeap(static_cast<std::uint64_t>(525584));
		}


		namespace GString
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(80446));
		}


		namespace hkContainerHeapAllocator
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(510713));
		}


		namespace hkReferencedObject
		{
			inline constexpr REL::ID AddReference(static_cast<std::uint64_t>(56606));
			inline constexpr REL::ID RemoveReference(static_cast<std::uint64_t>(56607));
		}


		namespace INIPrefSettingCollection
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(523673));
		}


		namespace INISettingCollection
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(524557));
		}


		namespace InterfaceStrings
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514286));
		}


		namespace Inventory
		{
			inline constexpr REL::ID GetEventSource(static_cast<std::uint64_t>(15980));
		}


		namespace InventoryChanges
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(15812));
			inline constexpr REL::ID Dtor(static_cast<std::uint64_t>(15813));
			inline constexpr REL::ID GenerateLeveledListChanges(static_cast<std::uint64_t>(15829));
			inline constexpr REL::ID GetNextUniqueID(static_cast<std::uint64_t>(15908));
			inline constexpr REL::ID SendContainerChangedEvent(static_cast<std::uint64_t>(15909));
			inline constexpr REL::ID SetUniqueID(static_cast<std::uint64_t>(15907));
			inline constexpr REL::ID TransferItemUID(static_cast<std::uint64_t>(15909));
		}


		namespace InventoryEntryData
		{
			inline constexpr REL::ID GetValue(static_cast<std::uint64_t>(15757));
			inline constexpr REL::ID IsOwnedBy(static_cast<std::uint64_t>(15782));
		}


		namespace ItemCrafted
		{
			inline constexpr REL::ID GetEventSource(static_cast<std::uint64_t>(50515));
		}


		namespace ItemList
		{
			inline constexpr REL::ID Update(static_cast<std::uint64_t>(50099));
		}


		namespace ItemsPickpocketed
		{
			inline constexpr REL::ID GetEventSource(static_cast<std::uint64_t>(50258));
		}


		namespace JournalMenu
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(271141));
		}


		namespace JumpHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263065));
		}


		namespace LocalMapCamera
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(16084));
			inline constexpr REL::ID SetNorthRotation(static_cast<std::uint64_t>(16089));
		}


		namespace LookHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263052));
		}


		namespace LooseFileStream
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(68663));
		}


		namespace MagicFavorites
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(516858));
		}


		namespace MagicItem
		{
			inline constexpr REL::ID CalculateCost(static_cast<std::uint64_t>(11213));
			inline constexpr REL::ID GetCostliestEffectItem(static_cast<std::uint64_t>(11216));
		}


		namespace MagicTarget
		{
			inline constexpr REL::ID HasMagicEffect(static_cast<std::uint64_t>(33733));
		}


		namespace Main
		{
			inline constexpr REL::ID DoFrame(static_cast<std::uint64_t>(35565));
			inline constexpr REL::ID ProcessTasks(static_cast<std::uint64_t>(35582));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(516943));
		}


		namespace MemoryManager
		{
			inline constexpr REL::ID Allocate(static_cast<std::uint64_t>(66859));
			inline constexpr REL::ID Deallocate(static_cast<std::uint64_t>(66861));
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(11045));
			inline constexpr REL::ID GetThreadScrapHeap(static_cast<std::uint64_t>(66841));
			inline constexpr REL::ID Reallocate(static_cast<std::uint64_t>(66860));
		}


		namespace MenuControls
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(515124));
		}


		namespace MenuOpenHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(269538));
		}


		namespace MessageBoxData
		{
			inline constexpr REL::ID QueueMessage(static_cast<std::uint64_t>(51422));
		}


		namespace MessageDataFactoryManager
		{
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(22843));
		}


		namespace MovementHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263056));
		}


		namespace NiBooleanExtraData
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(286420));
		}


		namespace NiAVObject
		{
			inline constexpr REL::ID SetMotionType(static_cast<std::uint64_t>(76033));
			inline constexpr REL::ID Update(static_cast<std::uint64_t>(68900));
		}


		namespace NiCamera
		{
			inline constexpr REL::ID WorldPtToScreenPt3(static_cast<std::uint64_t>(69270));
		}


		namespace NiFloatExtraData
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(286430));
		}


		namespace NiIntegerExtraData
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(286443));
		}


		namespace NiIntegersExtraData
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(286448));
		}


		namespace NiMemManager
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(523759));
		}


		namespace NiNode
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(68936));
		}


		namespace NiObject
		{
			inline constexpr REL::ID CreateDeepCopy(static_cast<std::uint64_t>(68839));
		}


		namespace NiRefObject
		{
			inline constexpr REL::ID TotalObjectCount(static_cast<std::uint64_t>(523912));
		}


		namespace NiSkinInstance
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(69804));
		}


		namespace NiSourceTexture
		{
			inline constexpr REL::ID Create(static_cast<std::uint64_t>(69335));
		}


		namespace NiStringsExtraData
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(286151));
		}


		namespace Papyrus
		{
			inline constexpr REL::ID ApplyHavokImpulse(static_cast<std::uint64_t>(55618));
		}


		namespace PlayerCamera
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514642));
			inline constexpr REL::ID UpdateThirdPerson(static_cast<std::uint64_t>(49908));
		}


		namespace PlayerCharacter
		{
			namespace PlayerSkills
			{
				inline constexpr REL::ID AdvanceLevel(static_cast<std::uint64_t>(40560));
			}


			inline constexpr REL::ID ActivatePickRef(static_cast<std::uint64_t>(39471));
			inline constexpr REL::ID AttemptPickpocket(static_cast<std::uint64_t>(39568));
			inline constexpr REL::ID GetArmorValue(static_cast<std::uint64_t>(39175));
			inline constexpr REL::ID GetDamage(static_cast<std::uint64_t>(39179));
			inline constexpr REL::ID GetNumTints(static_cast<std::uint64_t>(39614));
			inline constexpr REL::ID GetPickpocketChance(static_cast<std::uint64_t>(25822));
			inline constexpr REL::ID GetTintMask(static_cast<std::uint64_t>(39612));
			inline constexpr REL::ID PlayPickupEvent(static_cast<std::uint64_t>(39384));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(517014));
			inline constexpr REL::ID StartGrabObject(static_cast<std::uint64_t>(39475));
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(261916));
		}


		namespace PlayerControls
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(41257));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514706));
		}


		namespace ProcessLists
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514167));
			inline constexpr REL::ID StopCombatAndAlarmOnActor(static_cast<std::uint64_t>(40330));
		}


		namespace ReadyWeaponHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263059));
		}


		namespace REFR_LOCK
		{
			inline constexpr REL::ID GetLockLevel(static_cast<std::uint64_t>(12272));
		}


		namespace RunHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263063));
		}


		namespace Script
		{
			inline constexpr REL::ID CompileAndRun(static_cast<std::uint64_t>(21416));
		}


		namespace ScriptEventSourceHolder
		{
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(14108));
			inline constexpr REL::ID SendActivateEvent(static_cast<std::uint64_t>(19666));
		}


		namespace SCRIPT_FUNCTION
		{
			inline constexpr REL::ID FirstConsoleCommand(static_cast<std::uint64_t>(501797));
			inline constexpr REL::ID FirstScriptCommand(static_cast<std::uint64_t>(501789));
		}


		namespace ShoutHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263067));
		}


		namespace Sky
		{
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(13789));
		}


		namespace SkyrimScript
		{
			namespace Logger
			{
				inline constexpr REL::ID Trace(static_cast<std::uint64_t>(54752));
			}
		}


		namespace SkyrimVM
		{
			inline constexpr REL::ID QueuePostRenderCall(static_cast<std::uint64_t>(53144));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514315));
		}


		namespace SneakHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263066));
		}


		namespace SprintHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263057));
		}


		namespace TES
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(516923));
		}


		namespace TESCamera
		{
			inline constexpr REL::ID SetState(static_cast<std::uint64_t>(32290));
		}


		namespace TESDataHandler
		{
			inline constexpr REL::ID LoadScripts(static_cast<std::uint64_t>(13657));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514141));
		}


		namespace TESDescription
		{
			inline constexpr REL::ID GetDescription(static_cast<std::uint64_t>(14399));
		}


		namespace TESFile
		{
			inline constexpr REL::ID Duplicate(static_cast<std::uint64_t>(13923));
			inline constexpr REL::ID GetCurrentSubRecordType(static_cast<std::uint64_t>(13902));
			inline constexpr REL::ID GetFormType(static_cast<std::uint64_t>(13897));
			inline constexpr REL::ID ReadData(static_cast<std::uint64_t>(13904));
			inline constexpr REL::ID Seek(static_cast<std::uint64_t>(13898));
			inline constexpr REL::ID SeekNextSubrecord(static_cast<std::uint64_t>(13903));
		}


		namespace TESForm
		{
			inline constexpr REL::ID GetWeight(static_cast<std::uint64_t>(14809));
		}


		namespace TESHavokUtilities
		{
			inline constexpr REL::ID FindCollidableRef(static_cast<std::uint64_t>(25466));
		}


		namespace TESNPC
		{
			inline constexpr REL::ID ChangeHeadPart(static_cast<std::uint64_t>(24246));
			inline constexpr REL::ID GetBaseOverlays(static_cast<std::uint64_t>(24275));
			inline constexpr REL::ID GetNumBaseOverlays(static_cast<std::uint64_t>(24276));
			inline constexpr REL::ID HasOverlays(static_cast<std::uint64_t>(24274));
			inline constexpr REL::ID SetSkinFromTint(static_cast<std::uint64_t>(24206));
			inline constexpr REL::ID UpdateNeck(static_cast<std::uint64_t>(24207));
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(241857));
		}


		namespace TESObjectACTI
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(234000));
		}


		namespace TESObjectCONT
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(234148));
		}


		namespace TESObjectREFR
		{
			inline constexpr REL::ID CreateRefHandle_Native(static_cast<std::uint64_t>(19418));
			inline constexpr REL::ID InitChildActivates(static_cast<std::uint64_t>(19857));
			inline constexpr REL::ID GetDisplayFullName(static_cast<std::uint64_t>(19354));
			inline constexpr REL::ID GetLock(static_cast<std::uint64_t>(19818));
			inline constexpr REL::ID GetOwner(static_cast<std::uint64_t>(19789));
			inline constexpr REL::ID GetStealValue(static_cast<std::uint64_t>(15807));
			inline constexpr REL::ID FindReferenceFor3D(static_cast<std::uint64_t>(19323));
			inline constexpr REL::ID InitInventoryIfRequired(static_cast<std::uint64_t>(15800));
			inline constexpr REL::ID IsCrimeToActivate(static_cast<std::uint64_t>(19400));
			inline constexpr REL::ID MoveTo(static_cast<std::uint64_t>(56227));
			inline constexpr REL::ID PlayAnimation(static_cast<std::uint64_t>(14189));
		}


		namespace TESPackage
		{
			inline constexpr REL::ID CreatePackage(static_cast<std::uint64_t>(28732));
		}


		namespace TESQuest
		{
			inline constexpr REL::ID EnsureQuestStarted(static_cast<std::uint64_t>(24481));
			inline constexpr REL::ID ResetQuest(static_cast<std::uint64_t>(24486));
		}


		namespace TESWorldSpace
		{
			inline constexpr REL::ID GetOrCreateSkyCell(static_cast<std::uint64_t>(20095));
		}


		namespace ThirdPersonState
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(256647));
		}


		namespace TogglePOVHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263068));
		}


		namespace ToggleRunHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263062));
		}


		namespace UI
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514178));
		}


		namespace UIBlurManager
		{
			inline constexpr REL::ID DecrementBlurCount(static_cast<std::uint64_t>(51900));
			inline constexpr REL::ID IncrementBlurCount(static_cast<std::uint64_t>(51899));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(516871));
		}


		namespace UIMessageQueue
		{
			inline constexpr REL::ID AddMessage(static_cast<std::uint64_t>(13530));
			inline constexpr REL::ID CreateUIMessageData(static_cast<std::uint64_t>(80061));
			inline constexpr REL::ID ProcessCommands(static_cast<std::uint64_t>(80059));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514285));
		}


		namespace UserEvents
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(516458));
		}


		inline constexpr REL::ID CreateRefHandle(static_cast<std::uint64_t>(12193));
		inline constexpr REL::ID DebugNotification(static_cast<std::uint64_t>(52050));
		inline constexpr REL::ID LookupReferenceByHandle(static_cast<std::uint64_t>(12204));
		inline constexpr REL::ID PlaySound(static_cast<std::uint64_t>(52054));
		inline constexpr REL::ID RTDynamicCast(static_cast<std::uint64_t>(102238));
		inline constexpr REL::ID ShakeCamera(static_cast<std::uint64_t>(32275));
		inline constexpr REL::ID TlsIndex(static_cast<std::uint64_t>(528600));
		// FEC
		inline constexpr REL::ID func2E9950(static_cast<std::uint64_t>(21434));
	}
}
