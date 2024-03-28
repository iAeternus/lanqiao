#include <iostream>
#include <queue>

// 修改比较函数的方法 仿函数
struct Comparator1
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int main()
{
    /**
     * @brief std::queue 没什么好说的，这里介绍 std::priority_queue 优先队列
     * @brief std::priority_queue<T, Container, Compare>
     * @param T 数据类型
     * @param Container 底层容器的类型，默认为 vector
     * @param Compare 比较器
    */

    // 修改比较函数的方法
    std::priority_queue<int, std::vector<int>, Comparator1> q1;

    /**
     * @brief deque 双端队列
    */
    std::deque<int> q3;

    q3.push_back(10);
    q3.pop_back();
    q3.push_front(10);
    q3.pop_front();
    
    return 0;
}