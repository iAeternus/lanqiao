/*
前缀和是一种对静态数组求区间和的 O(1) 的方法
sum(L, R) = prefix[R] - prefix[L - 1] 

input
5
1 2 3 4 5
1 4
output
14
*/
#include <iostream>
#include <vector>

// 预处理
void getPrefix(const std::vector<int>& nums, std::vector<int>& prefix)
{
    prefix.assign(nums.size(), nums[0]);
    for(int i = 0; i < nums.size(); ++i)
    {
        prefix[i] = prefix[i - 1] + nums[i];
    }
}

int intervalSumming(const std::vector<int>& nums, int left, int right)
{
    // 定义前缀和数组
    std::vector<int> prefix;
    getPrefix(nums, prefix);

    return prefix[right] - prefix[left - 1];
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for(int i = 0; i < n; ++i)
    {
        std::cin >> nums[i];
    }

    int left, right;
    std::cin >> left >> right;
    std::cout << intervalSumming(nums, left, right);

    return 0;
}