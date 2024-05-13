cmake_minimum_required(VERSION 3.1)
project(PhysX_Library)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE "release")
set(PhysX_Path $ENV{PhysX})

include_directories(
    ${PhysX_Path}/include/physx
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(_DEBUG)
    message("Building library in debug configuration")
else()
    add_compile_definitions(_NDEBUG)
    message("Building library in release configuration")
endif()

set(Movement_DIR
    "${CMAKE_CURRENT_SOURCE_DIR}/../source/movement"
)

set(HEADER_DIRS
	"${CMAKE_CURRENT_SOURCE_DIR}/../include/"
    "${CMAKE_CURRENT_SOURCE_DIR}/../source/movement"
)
include_directories(${HEADER_DIRS})

set(SRC_FILES
	"${Movement_DIR}/Movement.cpp"
)

set(HEADER_FILES
    "${Movement_DIR}/Movement.h"
    "${Movement_DIR}/character_info.h"
)

add_library(PhysXCharacterMovement STATIC
	${SRC_FILES}
    ${HEADER_FILES}
)

set_target_properties(PhysXCharacterMovement PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/"
)

link_directories(${PhysX_Path}/lib)

target_link_libraries(PhysXCharacterMovement
    PhysXExtensions_static_64
    PhysX_64
    PhysXPvdSDK_static_64
    PhysXCommon_64
    PhysXFoundation_64
    PhysXCharacterKinematic_static_64
)

install(TARGETS PhysXCharacterMovement DESTINATION lib)
install(FILES ${HEADER_FILES} DESTINATION include)

# cmake --build . --config Release