#include <iostream>
#include <map>

int main()
{
    // 底层实现：红黑树，允许键重复
    std::multimap<std::string, int> map;

    map.insert(std::make_pair("aaa", 1));
    map.insert(std::make_pair("ccc", 3));
    map.insert(std::make_pair("ccc", 4));
    map.insert(std::make_pair("ccc", 5));
    map.insert(std::make_pair("bbb", 2));

    for(const auto& it : map)
    {
        std::cout << it.first << ' ' << it.second << std::endl;
    }

    std::cout << "map.count(\"ccc\") = " << map.count("ccc") << std::endl;

    return 0;
}