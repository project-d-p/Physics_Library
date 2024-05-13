#include "projectile_gun_filter.h"

namespace filter {

physx::PxFilterFlags GunFilter::gunfilter(physx::PxFilterObjectAttributes attributes0, physx::PxFilterData filterData0,
								physx::PxFilterObjectAttributes attributes1, physx::PxFilterData filterData1,
								physx::PxPairFlags& pairFlags, const void* constantBlock, physx::PxU32 constantBlockSize)
{
	pairFlags = physx::PxPairFlag::eDETECT_DISCRETE_CONTACT 
				| physx::PxPairFlag::eNOTIFY_TOUCH_FOUND;

	return physx::PxFilterFlag::eDEFAULT;
}

}
