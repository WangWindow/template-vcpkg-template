#include <iostream>
#include <print>

// 要测试的简单函数
int add(int a, int b) {
    return a + b;
}

// 简单的测试框架
#define TEST(name, condition)                                                                                          \
    if (!(condition)) {                                                                                                \
        std::println("Test {} failed!", name);                                                                         \
        return 1;                                                                                                      \
    } else {                                                                                                           \
        std::println("Test {} passed!", name);                                                                         \
    }

int main() {
    TEST("Addition", add(2, 3) == 5);
    TEST("Addition with negative", add(-1, 1) == 0);

    std::println("All tests passed!");
    return 0;
}
