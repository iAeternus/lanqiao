#include <iostream>
#include <unordered_set>

int main()
{
    // 底层实现：哈希表
    std::unordered_set<int> set;

    set.insert(25);
    set.insert(42);
    set.insert(17);
    set.insert(39);
    set.insert(42);

    for(const auto& it : set)
    {
        std::cout << it << ' ';
    }
    std::cout << '\n';

    std::cout << *(set.find(17)) << std::endl;

    return 0;
}