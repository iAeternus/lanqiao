#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> arr;
    for (int i = 0; i < 10; ++i)
    {
        arr.push_back(i % 4);
    }

    for (const auto& it : arr)
    {
        std::cout << it << std::endl;
    }

    std::cout << "=========================================\n";

    std::sort(arr.begin(), arr.end(), [](const int& a, const int& b)->bool {
        return a > b;
        });

    for (const auto& it : arr)
    {
        std::cout << it << std::endl;
    }

    std::cout << "=========================================\n";

    auto it = std::unique(arr.begin(), arr.end());
    arr.erase(it, arr.end());

    for (const auto& it : arr)
    {
        std::cout << it << std::endl;
    }

    return 0;
}