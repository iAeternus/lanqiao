/**
 * https://www.lanqiao.cn/problems/3695/learning/?page=1&first_category_id=1&name=%E8%81%AA%E6%98%8E%E7%9A%84%E5%B0%8F%E7%BE%8A%E8%82%96%E6%81%A9
*/
#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

// 返回 nums 数组中满足两数之和 <= x 的所有数对个数
ll solve(const std::vector<ll>& nums, ll x)
{
    ll cnt = 0;
    int left = 0, right = nums.size() - 1;
    while(left < right)
    {
        while(left < right && nums[left] + nums[right] > x)
        {
            --right;
        }
        cnt += right - left;
        ++left;
    }
    return cnt;
}

int main()
{
    int n;
    ll L, R;
    std::cin >> n >> L >> R;
    std::vector<ll> nums(n);
    for(int i = 0; i < n; ++i)
    {
        std::cin >> nums[i];
    }

    std::sort(nums.begin(), nums.end());

    std::cout << solve(nums, R) - solve(nums, L - 1) << std::endl;

    return 0;
}