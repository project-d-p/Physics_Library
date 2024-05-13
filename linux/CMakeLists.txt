cmake_minimum_required (VERSION 3.1)
project (PhysX_Standalone_Snippet)

set(CMAKE_CXX_STANDARD 14)
set(PHYSX_BUILD_TYPE "release")

include_directories(/home/deulee/src/PhysX/physx/include)

message("Building snippet in release configuration with PhysX ${PHYSX_BUILD_TYPE} configuration")
add_compile_definitions(NDEBUG)
link_directories("/home/deulee/src/PhysX/physx/bin/linux.clang/${PHYSX_BUILD_TYPE}") # This is the path where PhysX libraries are installed

set(SRC_FILES
	"${CMAKE_CURRENT_SOURCE_DIR}/../source/filter/projectile_gun_filter.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/../source/gun/projectile_shoot_process.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/../source/gun/hitscan_shoot_process.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/../source/common/objects.cpp"
	)
	
	set(HEADER_FILES
	"${CMAKE_CURRENT_SOURCE_DIR}/../source/gun/projectile_shoot_process.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/../source/gun/hitscan_shoot_process.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/../source/gun/source_info.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/../source/gun/target_info.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/../source/common/objects.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/../source/common/object_info.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/../source/filter/projectile_gun_filter.h"
)

set(HEADER_DIRS
	"${CMAKE_CURRENT_SOURCE_DIR}/../source/gun/"
	"${CMAKE_CURRENT_SOURCE_DIR}/../source/common/"
	"${CMAKE_CURRENT_SOURCE_DIR}/../include/"
)

add_library(PhysicsEngine
	${SRC_FILES}
	${HEADER_FILES}
)

target_include_directories(PhysicsEngine
	PUBLIC
	${HEADER_DIRS}
)

target_link_libraries(PhysicsEngine
	PhysXExtensions_static_64
	PhysX_static_64
	PhysXPvdSDK_static_64
	PhysXCommon_static_64
	PhysXFoundation_static_64

	pthread
	dl
)

# add_executable(Snippet
#     main.cpp
# )

# target_link_libraries(Snippet
# 	PhysicsEngine
#     PhysXExtensions_static_64
#     PhysX_static_64
#     PhysXPvdSDK_static_64
#     PhysXCommon_static_64
#     PhysXFoundation_static_64

#     pthread
#     dl
# )
