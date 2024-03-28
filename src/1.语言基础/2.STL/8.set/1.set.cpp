#include <iostream>
#include <set>

// 仿函数
struct Comp
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int main()
{
    // 底层实现：红黑树，不允许值重复
    std::set<int, std::less<int>> s1;

    s1.insert(25);
    s1.insert(42);
    s1.insert(17);
    s1.insert(39);
    s1.insert(42);

    for(const auto& it : s1)
    {
        std::cout << it << std::endl;
    }

    std::cout << "======================================\n";

    std::set<int, Comp> s2;

    s2.insert(25);
    s2.insert(42);
    s2.insert(17);
    s2.insert(39);
    s2.insert(42);

    for(const auto& it : s2)
    {
        std::cout << it << std::endl;
    }

    return 0;
}