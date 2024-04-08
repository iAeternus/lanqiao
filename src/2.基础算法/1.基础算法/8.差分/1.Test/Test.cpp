#include <iostream>
#include <vector>

// 获取差分数组
void getDiff(const std::vector<int>& nums, std::vector<int>& diff)
{
    diff.assign(nums.size() + 1, 0);
    for(int i = 1; i <= nums.size(); ++i)
    {
        diff[i] = nums[i] - nums[i - 1];
    }
}

// 差分的性质，把区间 [l, r] 都加上 x
void add(std::vector<int>& diff, int left, int right, int x)
{
    diff[left] += x;
    diff[right + 1] -= x;
}

void getPrefix(const std::vector<int>& nums, std::vector<int>& prefix)
{
    prefix.assign(nums.size(), nums[0]);
    for(int i = 1; i < nums.size(); ++i)
    {
        prefix[i] = prefix[i - 1] + nums[i];
    }
}

int main()
{
    int n;
    std::cin >> n;

    // 为了简化计算，这里下标从 1 开始
    std::vector<int> nums(n + 1);
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> nums[i];
    }

    std::vector<int> diff;
    getDiff(nums, diff);

    for(int i = 1; i <= n; ++i)
    {
        std::cout << diff[i] << ' ';
    }
    std::cout << std::endl;

    // 差分求前缀和为原数组
    std::vector<int> prefix;
    getPrefix(diff, prefix);
    for(int i = 1; i <= n; ++i)
    {
        std::cout << prefix[i] << ' ';
    }
    std::cout << std::endl;

    // 修改原数组
    int left, right, x;
    std::cin >> left >> right >> x;
    add(diff, left, right, x);
    getPrefix(diff, prefix);
    for(int i = 1; i <= n; ++i)
    {
        std::cout << prefix[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
