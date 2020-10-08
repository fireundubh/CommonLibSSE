#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/BGSProjectile.h"


namespace RE
{
	std::uint32_t BGSProjectile::GetType() const
	{	
		using Type = BGSProjectileData::Type;
		
		if (data.types.all(Type::kMissile)) {
			return 1;
		} else if (data.types.all(Type::kGrenade)) {
			return 2;
		} else if (data.types.all(Type::kBeam)) {
			return 3;
		} else if (data.types.all(Type::kFlamethrower)) {
			return 4;
		} else if (data.types.all(Type::kCone)) {
			return 5;
		} else if (data.types.all(Type::kBarrier)) {
			return 6;
		} else if (data.types.all(Type::kArrow)) {
			return 7;
		} else {
			return 0;
		}
	}
}