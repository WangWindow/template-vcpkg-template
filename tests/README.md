<div align="center">
  <h1>🧪 测试目录</h1>
  <p>单元测试和集成测试代码</p>
</div>

## 测试框架

本项目使用[GoogleTest](https://github.com/google/googletest)作为测试框架。

## 目录结构

测试目录按照被测组件进行组织：

```
test/
├── CMakeLists.txt           # 测试的主CMake构建脚本
├── unit/                    # 单元测试
│   ├── library1/            # 特定库的单元测试
│   │   ├── feature1_test.cpp
│   │   └── feature2_test.cpp
│   └── library2/
│       └── feature_test.cpp
├── integration/             # 集成测试
│   └── system_test.cpp
├── performance/             # 性能测试(可选)
│   └── benchmark_test.cpp
└── fixtures/                # 测试数据和固件
    └── test_data.json
```

## 编写测试

### 单元测试示例

<details>
<summary><b>基本单元测试模板</b></summary>

```cpp
#include <gtest/gtest.h>
#include "mylibrary/feature.h"  // 被测试的组件

class FeatureTest : public ::testing::Test {
protected:
    void SetUp() override {
        // 测试准备工作
    }

    void TearDown() override {
        // 测试清理工作
    }

    // 测试中使用的共享资源
    mylibrary::Feature feature{42};
};

TEST_F(FeatureTest, ReturnsCorrectValue) {
    // Arrange
    std::string input = "test";

    // Act
    std::string result = feature.process(input);

    // Assert
    EXPECT_EQ(result, "expected result");
}

TEST_F(FeatureTest, HandlesEmptyInput) {
    // 测试空输入的处理逻辑
    EXPECT_NO_THROW({
        feature.process("");
    });
}
```
</details>

### 集成测试示例

<details>
<summary><b>基本集成测试模板</b></summary>

```cpp
#include <gtest/gtest.h>
#include "library1/component1.h"
#include "library2/component2.h"

TEST(IntegrationTest, ComponentsWorkTogether) {
    // 初始化组件
    library1::Component1 comp1;
    library2::Component2 comp2;

    // 测试组件间交互
    auto result = comp2.process(comp1.getData());

    // 验证结果
    EXPECT_TRUE(result.isValid());
}
```
</details>

## 运行测试

```bash
# 在构建目录中执行
ctest                      # 运行所有测试
ctest -R unit              # 只运行单元测试
ctest -R library1          # 运行特定库的测试
ctest -V                   # 输出详细信息
```

## 测试最佳实践

- **测试独立性** - 每个测试应该独立运行，不依赖其他测试的状态
- **AAA模式** - 遵循Arrange-Act-Assert模式组织测试代码
- **边界条件** - 测试边缘情况和错误处理
- **测试命名** - 使用描述性名称，如`MethodName_StateUnderTest_ExpectedBehavior`
- **代码覆盖率** - 目标是达到高测试覆盖率(建议>80%)
- **持续集成** - 确保测试在CI系统中自动运行

## Mock和Stub

对于需要模拟外部依赖的测试，可以使用GoogleMock：

<details>
<summary><b>Mock示例</b></summary>

```cpp
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "mylibrary/database.h"

// 创建数据库访问的Mock对象
class MockDatabase : public mylibrary::Database {
public:
    MOCK_METHOD(bool, connect, (const std::string& connection_string), (override));
    MOCK_METHOD(std::vector<Record>, query, (const std::string& sql), (override));
    MOCK_METHOD(void, disconnect, (), (override));
};

TEST(DatabaseClientTest, QueryCallsDatabase) {
    // 创建Mock
    MockDatabase mock_db;

    // 设置期望
    EXPECT_CALL(mock_db, connect("test_conn"))
        .WillOnce(testing::Return(true));
    EXPECT_CALL(mock_db, query("SELECT * FROM table"))
        .WillOnce(testing::Return(std::vector<Record>{Record{1, "test"}}));
    EXPECT_CALL(mock_db, disconnect());

    // 使用mock对象
    DatabaseClient client(&mock_db);
    client.fetchRecords("test_conn", "SELECT * FROM table");

    // GoogleMock会自动验证所有预期的调用
}
```
</details>
