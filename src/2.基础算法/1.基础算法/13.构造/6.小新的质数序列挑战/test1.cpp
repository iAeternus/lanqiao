/**
 * https://www.lanqiao.cn/problems/4875/learning/?page=1&first_category_id=1&name=%E5%B0%8F%E6%96%B0%E7%9A%84%E8%B4%A8%E6%95%B0
 * 
 * 前提：
 *      (1) 若 n > 1，则要么 n 为质数，要么 n 为质数的倍数
 *      (2) 对于 n > 1，总能找到一组由 2,3 组成的序列和为 n
 * 
 * 1. gcd(a, b) > 1 时
 *      由(1) a,b 能拆出由相同的的数组成的序列，结果为 0
 * 2. gcd(a, b) == 1 时
 *      由(2) 结果为 3 - 2 = 1
*/
#include <bits/stdc++.h>

using ll = long long;

ll gcd(ll x, ll y)
{
    return y ? gcd(y, x % y) : x;
}

int main()
{
    int t;
    std::cin >> t;
    ll n, a, b;
    for(int i = 0; i < t; ++i)
    {
        std::cin >> a >> b;
        if(a == 1 || b == 1) std::cout << -1 << std::endl;
        else if(gcd(a, b) > 1) std::cout << 0 << std::endl;
        else std::cout << 1 << std::endl;
    }
    return 0;
}
