#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::pair<int, std::string> a = {1, "hello"};
    std::cout << a.first << ' ' << a.second << std::endl;

    // pair 自带排序规则，先比第一个，再比第二个
    std::vector<std::pair<int, int>> arr1 = {
        {3, 2},
        {1, 4},
        {2, 1}
    };
    std::sort(arr1.begin(), arr1.end());
    for(const auto& it : arr1)
    {
        std::cout << it.first << ' ' << it.second << std::endl;
    }
    
    std::cout << "==================================================\n";

    // 当然也能自定义排序规则
    std::vector<std::pair<int, int>> arr2 = {
        {3, 2},
        {1, 4},
        {2, 1}
    };
    std::sort(arr2.begin(), arr2.end(), [](const std::pair<int, int>& x, const std::pair<int, int>& y)->bool {
        return x.first > y.first;
    });
    for(const auto& it : arr2)
    {
        std::cout << it.first << ' ' << it.second << std::endl;
    }

    return 0;
}