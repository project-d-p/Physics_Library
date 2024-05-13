cmake_minimum_required (VERSION 3.1)
project (PhysX_Standalone_Snippet)

set(CMAKE_CXX_STANDARD 14)
set(PHYSX_BUILD_TYPE "release")

include_directories(/home/deulee/src/PhysX/physx/include)

message("Building snippet in release configuration with PhysX ${PHYSX_BUILD_TYPE} configuration")
add_compile_definitions(NDEBUG)
link_directories("/home/deulee/src/PhysX/physx/bin/linux.clang/${PHYSX_BUILD_TYPE}") # This is the path where PhysX libraries are installed

# 라이브러리 경로 설정
set(LIBRARY_PATH "/home/deulee/src/physics/linux/cmake-out/")
set(HEADER_PATH "/home/deulee/src/physics/include/")

# 헤더 파일 위치를 포함 경로에 추가
include_directories(${HEADER_PATH})

# 라이브러리 추가
add_library(PhysicsEngine STATIC IMPORTED)
set_property(TARGET PhysicsEngine PROPERTY IMPORTED_LOCATION ${LIBRARY_PATH}/libPhysicsEngine.a)

# 빌드 대상 설정
add_executable(hitscan
    ./hitscan/main.cpp
)

add_executable(projectile
    ./projectile/main.cpp
)   

# 빌드 대상에 라이브러리 링크
target_link_libraries(hitscan
	PhysicsEngine
    PhysXExtensions_static_64
    PhysX_static_64
    PhysXPvdSDK_static_64
    PhysXCommon_static_64
    PhysXFoundation_static_64

    pthread
    dl
)

target_link_libraries(projectile
	PhysicsEngine
    PhysXExtensions_static_64
    PhysX_static_64
    PhysXPvdSDK_static_64
    PhysXCommon_static_64
    PhysXFoundation_static_64

    pthread
    dl
)
