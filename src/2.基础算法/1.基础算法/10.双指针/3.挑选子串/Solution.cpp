/**
 * https://www.lanqiao.cn/problems/1621/learning/?page=1&first_category_id=1&problem_id=1621
 */
#include <iostream>
#include <vector>

using ll = long long;

int main()
{
    int n, k;
    ll m;
    std::cin >> n >> m >> k;
    std::vector<ll> nums(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> nums[i];
    }

    int ans = 0;
    int slow = 0, fast = 0, cnt = 0;
    while (slow <= fast && fast < nums.size())
    {
        if(nums[fast] >= m)
        {
            ++cnt;
        }

        while (cnt >= k)
        {
            // 找到了最小的满足条件的区间 => 后面的全部满足条件
            ans += (nums.size() - 1) - fast + 1;
            cnt -= (nums[slow] >= m);
            ++slow;
        }
        ++fast;
    }

    std::cout << ans << std::endl;

    return 0;
}