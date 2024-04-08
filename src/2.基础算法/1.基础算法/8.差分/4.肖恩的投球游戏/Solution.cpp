/*
https://www.lanqiao.cn/problems/3693/learning/?page=1&first_category_id=1&name=%E8%82%96%E6%81%A9%E7%9A%84%E6%8A%95%E7%90%83%E6%B8%B8%E6%88%8F
*/
#include <iostream>
#include <vector>

using ll = long long;

void getDiff(const std::vector<ll>& nums, std::vector<ll>& diff)
{
    diff.assign(nums.size() + 1, 0);
    for(int i = 1; i <= nums.size(); ++i)
    {
        diff[i] = nums[i] - nums[i - 1];
    }
}

void add(std::vector<ll>& diff, int left, int right, ll x)
{
    diff[left] += x;
    diff[right + 1] -= x;
}

void getPrefix(const std::vector<ll>& nums, std::vector<ll>& prefix)
{
    prefix.assign(nums.size(), nums[0]);
    for(int i = 1; i < nums.size(); ++i)
    {
        prefix[i] = prefix[i - 1] + nums[i];
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<ll> nums(n + 1);
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> nums[i];
    }

    std::vector<ll> diff;
    getDiff(nums, diff);

    int x, y;
    ll z;
    for(int i = 0; i < m; ++i)
    {
        std::cin >> x >> y >> z;
        add(diff, x, y, z);
    }

    getPrefix(diff, nums);

    std::cout << (nums[1] >= 0 ? nums[1] : 0);
    for(int i = 2; i <= n; ++i)
    {
        std::cout << ' ' << (nums[i] >= 0 ? nums[i] : 0);
    }
    std::cout << std::endl;

    return 0;
}