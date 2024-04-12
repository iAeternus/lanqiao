//
// Created by lenovo on 2024/3/21.
//
/**
 * @brief 高精度基准测试计时器
 * @author Ricky
 * @date 2024/3/6
 * @version 2.0
 *
 * 使用方法<br>
 * 1. 方法一<br>
 * {<br>
 * &nbsp;&nbsp;&nbsp;&nbsp;size_t count = 10;<br>
 * &nbsp;&nbsp;&nbsp;&nbsp;Timer timer("{name}", {count});<br>
 * &nbsp;&nbsp;&nbsp;&nbsp;for(size_t i = 0; i < count; ++i) {<br>
 * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;test_function( ... );<br>
 * &nbsp;&nbsp;&nbsp;&nbsp;}<br>
 * }<br><br>
 *
 * 2. 方法二（推荐）<br>
 * Timer::automatic_measurement_of_time([&]() -> void {<br>
 * &nbsp;&nbsp;&nbsp;&nbsp;test_function( ... );<br>
 * }, "{name}", {count});<br><br>
 *
 * 3. 方法三（推荐）<br>
 * double duration_us = Timer::automatic_measurement_of_time2([&]() {<br>
 * &nbsp;&nbsp;&nbsp;&nbsp;test_function( ... );<br>
 * }, {count});<br>
 * std::cout << duration_us << std::endl;<br>
*/
#ifndef CPP_DEBUG_TIMER_H
#define CPP_DEBUG_TIMER_H


#include <iostream>
#include <chrono>
#include <functional>

#define RED             "\033[1;31m"
#define GREEN           "\033[1;32m"
#define YELLOW          "\033[1;33m"
#define DEFAULT_COLOR   "\033[0m"

class Timer {
public:
    explicit Timer(const char *name = nullptr, size_t count = 1) :
            name(name), count(count), is_Stopped(false), m_startTimePoint(std::chrono::high_resolution_clock::now()) {}

    ~Timer() {
        if (!is_Stopped) {
            Stop();
        }
    }

    void Stop() {
        auto endTimePoint = std::chrono::high_resolution_clock::now();
        // 转成微秒，更精确
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startTimePoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

        auto duration = (end - start) / count; // 计算一次的时间
        double ms = duration * 0.001; // 如果要毫秒的话

        if (name) {
            std::cout << YELLOW << '[' << name << "] " << DEFAULT_COLOR;
        }
        std::cout << GREEN << duration << DEFAULT_COLOR << "us ( ";
        std::cout << GREEN << ms << DEFAULT_COLOR << "ms )\n";
        is_Stopped = true;
    }

    static void automatic_measurement_of_time(const std::function<void()> &func, const char *name = nullptr, size_t count = 1) {
        Timer timer(name, count);
        for (int i = 0; i < count; ++i) {
            func();
        }
    }

    static double automatic_measurement_of_time2(const std::function<void()> &func, size_t count = 1) {
        auto startTimePoint = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < count; ++i) {
            func();
        }
        auto endTimePoint = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startTimePoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();
        return (end - start) / count; // 计算一次的时间
    }

private:
    const char *name; // 计时器名字
    size_t count; // 目标代码块运行的次数
    bool is_Stopped; // 计时器是否停止
    std::chrono::time_point<std::chrono::high_resolution_clock> m_startTimePoint; // 开始时刻
};


#endif //CPP_DEBUG_TIMER_H
