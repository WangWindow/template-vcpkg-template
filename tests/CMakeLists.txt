# 收集所有测试文件
file(GLOB_RECURSE TEST_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# 创建统一的测试库，包含所有需要测试的代码
add_library(test_lib INTERFACE)
target_include_directories(test_lib
    INTERFACE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/src
)

# 查找谷歌测试框架（如果使用）
find_package(GTest QUIET)
if(GTest_FOUND)
    message(STATUS "Find Google Test, version: ${GTEST_VERSION}")

    # 为每个测试文件创建单独的测试可执行文件
    foreach(TEST_FILE ${TEST_FILES})
        # 从文件路径中提取文件名（不含扩展名）作为测试名称
        get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
        # 创建测试目标
        add_executable(test_${TEST_NAME} ${TEST_FILE})
        # 链接依赖
        target_link_libraries(test_${TEST_NAME}
            PRIVATE
                GTest::GTest
                GTest::Main
        )
        # 添加测试到CTest
        add_test(NAME ${TEST_NAME} COMMAND test_${TEST_NAME})
    endforeach()
else()
    # 没有找到谷歌测试框架时的简单测试配置
    foreach(TEST_FILE ${TEST_FILES})
        get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
        add_executable(test_${TEST_NAME} ${TEST_FILE})
        target_link_libraries(test_${TEST_NAME}
            PRIVATE
                test_lib
        )
        add_test(NAME ${TEST_NAME} COMMAND test_${TEST_NAME})
    endforeach()
endif()
