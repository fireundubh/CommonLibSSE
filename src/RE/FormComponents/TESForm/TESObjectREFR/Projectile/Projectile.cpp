#include "RE/FormComponents/TESForm/TESObjectREFR/Projectile/Projectile.h"

#include "RE/FormComponents/Components/FormTraits.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/BGSProjectile.h"


namespace RE
{
	float Projectile::GetHeight() const
	{
		auto obj = GetObjectReference();
		auto projectile = obj ? obj->As<BGSProjectile>() : nullptr;
		return projectile ? projectile->data.collisionRadius * 2 : 0.0f;
	}
}
