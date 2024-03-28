#include <iostream>
#include <set>

int main()
{
    // 底层实现：红黑树，允许值重复
    std::multiset<int> set;

    set.insert(1);
    set.insert(1);
    set.insert(2);
    set.insert(3);
    set.insert(3);
    set.insert(4);

    for(const auto& it : set)
    {
        std::cout << it << ' ';
    }
    std::cout << '\n';

    // erase(x) 会删除所有的 x
    set.erase(1);

    for(const auto& it : set)
    {
        std::cout << it << ' ';
    }
    std::cout << '\n';

    // 如果要只删除一个
    set.erase(set.find(3));

    for(const auto& it : set)
    {
        std::cout << it << ' ';
    }
    std::cout << '\n';

    return 0;
}