/*
排序
题目描述
给定一个长度为 N 的数组 A ，请你先从小到大输出它的每个元素，再从大到小输出它的每个元素。

输入描述
第一行包含一个整数 N 。
第二行包含 N 个整数a1,…, an ，表示数组 A 的元素。
1≤ N ≤5 x 10^5,-10^9≤a1≤10^9.

输出描述
输出共两行，每行包含 N 个整数，表示答案。

输入输出样例
示例1
输入
5
1 3 2 6 5
输出
1 2 3 5 6
6 5 3 2 1
*/
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for(int i = 0; i < n; ++i)
    {
        std::cin >> nums[i];
    }

    std::sort(nums.begin(), nums.end(), [](const int& a, const int& b)->bool {
        return a < b;
    });

    for(const auto& it : nums)
    {
        std::cout << it << ' ';
    }
    std::cout << '\n';

    std::sort(nums.begin(), nums.end(), [](const int& a, const int& b)->bool {
        return a > b;
    });

    for(const auto& it : nums)
    {
        std::cout << it << ' ';
    }
    std::cout << '\n';

    return 0;
}