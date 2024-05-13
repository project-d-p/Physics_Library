cmake_minimum_required(VERSION 3.1)
project(PhysX_CharacterMovment_Snippet)

set(CMAKE_CXX_STANDARD 14)
set(PHYSX_BUILD_TYPE "release")
set(PhysX_Path $ENV{PhysX})

include_directories(
    ${PhysX_Path}/include/physx
)

add_compile_definitions(_NDEBUG)

set(HEADER_DIRS
	"${CMAKE_CURRENT_SOURCE_DIR}/../../include/"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../source/movement"
)
include_directories(${HEADER_DIRS})

set(Movement_DIR
    "${CMAKE_CURRENT_SOURCE_DIR}/../../source/movement"
)

set(SRC_FILES
	"${CMAKE_CURRENT_SOURCE_DIR}/movementTest.cpp"
	"${Movement_DIR}/Movement.cpp"
)

set(HEADER_FILES
    "${Movement_DIR}/Movement.h"
    "${Movement_DIR}/character_info.h"
)

add_library(PhysicsEngine
	${SRC_FILES}
    ${HEADER_FILES}
)

link_directories(${PhysX_Path}/debug/lib)

add_executable(MovementTest
    ${SRC_FILES}
)

target_link_libraries(MovementTest
    PhysXExtensions_static_64
    PhysX_64
    PhysXPvdSDK_static_64
    PhysXCommon_64
    PhysXFoundation_64
    PhysXCharacterKinematic_static_64
)
