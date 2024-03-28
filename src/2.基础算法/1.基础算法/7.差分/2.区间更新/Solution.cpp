/*
https://www.lanqiao.cn/problems/3291/learning/?page=1&first_category_id=1&problem_id=3291
*/
#include <iostream>
#include <vector>

void getDiff(const std::vector<int>& nums, std::vector<int>& diff)
{
    diff.assign(nums.size() + 1, 0);
    for(int i = 1; i <= nums.size(); ++i)
    {
        diff[i] = nums[i] - nums[i - 1];
    }
}

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

void solve(int n, int m)
{
    std::vector<int> nums(n + 1);
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> nums[i];
    }

    std::vector<int> diff;
    getDiff(nums, diff);

    int x, y, z;
    for(int i = 0; i < m; ++i)
    {
        std::cin >> x >> y >> z;
        add(diff, x, y, z);
    }

    getPrefix(diff, nums);

    std::cout << nums[1];
    for(int i = 2; i <= n; ++i)
    {
        std::cout << ' ' << nums[i];
    }
    std::cout << std::endl;
}

int main()
{
    int n, m;

    while(std::cin >> n >> m)
    {
        solve(n, m);
    }

    return 0;
}