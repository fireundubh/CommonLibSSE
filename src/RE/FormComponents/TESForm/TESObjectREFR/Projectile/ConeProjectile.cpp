#include "RE\FormComponents\TESForm\TESObjectREFR\Projectile\ConeProjectile.h"


namespace RE
{
	float ConeProjectile::GetHeight() const
	{
		return initialCollisionSphereRadius * 2;
	}
}
