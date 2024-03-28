#include <iostream>
#include <map>

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
    // 底层实现：红黑树，不允许键重复
    std::map<std::string, int> map;

    map.insert(std::make_pair("aaa", 1));
    map.insert(std::make_pair("ccc", 3));
    map.insert(std::make_pair("bbb", 2));
    
    for(const auto& it : map)
    {
        std::cout << it.first << ' ' << it.second << std::endl;
    }

    std::cout << "========================================\n";

    std::cout << "map[\"bbb\"] = " << map["bbb"] << std::endl;

    // count() 判断键是否存在
    std::cout << "map.count(\"aaa\") = " << map.count("aaa") << std::endl;
    std::cout << "map.count(\"ddd\") = " << map.count("ddd") << std::endl;

    return 0;
}