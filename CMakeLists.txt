# 设置CMake的最小版本
cmake_minimum_required(VERSION 3.30)

# VCPKG集成 - 通过清单模式自动处理依赖
if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      CACHE STRING "VCPKG Toolchain File")
  message(STATUS "VCPKG Toolchain file set to: ${CMAKE_TOOLCHAIN_FILE}")
endif()

# 设置项目名称和版本
project(cmake_project VERSION 1.0 LANGUAGES CXX)

# 定义应用程序和测试的名称
set(EXE_NAME "cmake_app")

# 设置全局编译选项
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 启用测试
include(CTest)
enable_testing()

# 收集所有源文件
file(GLOB_RECURSE SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
# 收集所有头文件
file(GLOB_RECURSE HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")

# 添加主要可执行文件
add_executable(${EXE_NAME} ${SOURCE_FILES} ${HEADER_FILES})

# 设置包含目录（使用现代CMake方式）
target_include_directories(${EXE_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 查找并链接依赖库
find_package(indicators CONFIG REQUIRED)
target_link_libraries(${EXE_NAME} PRIVATE indicators::indicators)

# 处理测试
add_subdirectory(tests)
