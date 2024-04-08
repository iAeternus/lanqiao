/**
 * 给定 n 个数 nums
 * 给出包含这 n 个数的最短的等差数列有几项，并输出这几项
 * 
 * sample input
 *      3
 *      2 5 7
 * sample output
 *      6
 *      2 3 4 5 6 7
 * ----------------------------------------------------------
 * gcd构造问题，先排序，对所有间隔求 gcd 即为公差，再由最小、最大值给出数列
*/
#include <bits/stdc++.h>

using ll = long long;
#define MAX_N 10000
ll nums[MAX_N];

ll gcd(ll x, ll y)
{
    return y ? gcd(y, x % y) : x;
}

int main()
{
    ll n;
    std::cin >> n;
    for(int i = 0; i < n; ++i)
    {
        std::cin >> nums[i];
    }

    std::sort(nums, nums + n);

    ll d = 0; // 公差
    ll min = nums[0], max = nums[0];
    for(int i = 1; i < n; ++i)
    {
        d = gcd(d, nums[i] - nums[i - 1]);
        min = std::min(min, nums[i]);
        max = std::max(max, nums[i]);
    }

    // 最短的等差数列项数
    std::cout << (max - min) / d + 1 << std::endl;

    for(int i = min; i <= max; i += d)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    return 0;
}
