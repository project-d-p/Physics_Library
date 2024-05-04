# 최소 필요한 CMake 버전 설정
cmake_minimum_required(VERSION 3.10)

# 프로젝트 이름 설정
project(MovementTest)

option(PHYSX_BUILD_TYPE "The build type of PhysX, i.e., one of {debug, checked, profile, release}" "debug")

set(PhysX $ENV{PhysX})

# 포함할 헤더 파일 디렉토리 목록
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${PhysX}/include/physx
)

# link_directories("${PhysX}/lib")
link_directories(${PhysX}/debug/lib)
add_compile_definitions(PX_PHYSX_CHARACTER_STATIC_LIB)
# 실행 파일을 만들 소스 파일 추가
add_executable(MovementTest ./Test/movementTest.cpp ./source/movement/Movement.cpp)

# 필요한 라이브러리와 함께 링크
target_link_libraries(MovementTest
    PhysXExtensions_static_64
    PhysX_64
    PhysXPvdSDK_static_64
    PhysXCommon_64
    PhysXFoundation_64
    PhysXCharacterKinematic_static_64
)

# (선택적) CMake가 타겟에 대해 사용할 C++ 표준 버전 설정
set_target_properties(MovementTest PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
)

# 빌드 유형에 따른 조건문 설정
if(CMAKE_BUILD_TYPE AND CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("Building snippet in debug configuration")
    # add_compile_definitions(_DEBUG)
    # link_directories(${PhysX}/lib)
    # link_directories(${PhysX}/debug/bin)
# else()
#     message("Building snippet in release configuration with PhysX ${PHYSX_BUILD_TYPE} configuration")
    # add_compile_definitions(NDEBUG)
    # link_directories(${PhysX}/lib)
endif()
