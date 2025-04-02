#include <chrono>
#include <indicators/progress_bar.hpp>
#include <iostream>
#include <print>
#include <thread>
#include <vector>

// 添加一个可以被测试的函数
int add(int a, int b) {
    return a + b;
}

int main() {
    using namespace std;

    int result = add(10, 20);

    // 定义一个颜色列表
    vector<indicators::Color> colors{ indicators::Color::red,  indicators::Color::green,   indicators::Color::yellow,
                                      indicators::Color::blue, indicators::Color::magenta, indicators::Color::cyan };

    // 创建一个炫酷的进度条，初始颜色设置为列表中的第一种颜色
    indicators::ProgressBar bar{ indicators::option::BarWidth{ 50 },
                                 indicators::option::Start{ "[" },
                                 indicators::option::Fill{ "=" },
                                 indicators::option::Lead{ ">" },
                                 indicators::option::Remainder{ " " },
                                 indicators::option::End{ "]" },
                                 indicators::option::PrefixText{ "Processing:" },
                                 indicators::option::ForegroundColor{ colors[0] },
                                 indicators::option::ShowElapsedTime{ true },
                                 indicators::option::ShowRemainingTime{ true },
                                 indicators::option::MaxProgress{ 100 } };

    for (int i = 0; i <= 100; ++i) {
        // 循环使用不同的颜色
        bar.set_option(indicators::option::ForegroundColor{ colors[i % colors.size()] });
        bar.set_progress(i);
        this_thread::sleep_for(chrono::milliseconds(50));
    }

    println("Processing complete!");
    println("Result is: {}", result);

    return 0;
}
