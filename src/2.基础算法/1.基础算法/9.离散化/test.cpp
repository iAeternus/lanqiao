/**
 * 给定数组，求离散化数组
 */
#include <iostream>
#include <vector>
#include <algorithm>

// 获取目标值下标
int get_index(const std::vector<int> &arr, int target)
{
    return std::lower_bound(arr.begin(), arr.end(), target) - arr.begin();
}

// 离散化
void discretization(std::vector<int> &arr)
{
    std::sort(arr.begin(), arr.end()); // 排序
    arr.erase(std::unique(arr.begin(), arr.end()), arr.end()); // 去重
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < arr.size(); ++i)
    {
        std::cin >> arr[i];
    }

    discretization(arr);

    for(int i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "====================\n";

    int target;
    std::cin >> target;
    std::cout << "arr[" << get_index(arr, target) << "] = " << target << std::endl;

    return 0;
}