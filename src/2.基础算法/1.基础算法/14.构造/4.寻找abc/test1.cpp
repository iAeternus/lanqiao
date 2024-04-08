/*
t 次询问，每次输入 n，输出 a,b,c 满足 xor(a, b) + xor(b, c) + xor(a, c) == n
------------------------------------------------------------------------------
从奇偶性入手，因为
xor(奇, 奇) = 偶
xor(偶, 偶) = 偶
xor(奇, 偶) = 奇

1. a,b,c 全奇/全偶 -> n 偶
2. a,b,c 两奇，不妨设 a,b 奇
    偶 + 奇 + 奇 = 偶
3. a,b,c 两偶，不妨设 a,b 偶
    偶 + 奇 + 奇 = 偶

所以 n 一定是偶数，考虑 n 为偶数的情况，最简化问题
令 c = 0，原式为 xor(a, b) + b + a == n
令 a == b，原式为 0 + b + a == n
那么若 a == b == n / 2，满足题意
*/
#include <bits/stdc++.h>

using ll = long long;

bool func(ll n, ll &a, ll &b, ll &c)
{
    if (n & 1)
    {
        return false;
    }
    a = b = (n >> 1);
    c = 0;
}

bool check(ll a, ll b, ll c, ll n)
{
    return (a ^ b) + (b ^ c) + (a ^ c) == n;
}

int main()
{
    int t;
    std::cin >> t;
    ll n, a, b, c;
    for (int i = 0; i < t; ++i)
    {
        std::cin >> n;
        if (func(n, a, b, c))
        {
            printf("%lld %lld %lld check: %s\n", a, b, c, (check(a, b, c, n) ? "true" : "false"));
        }
        else
        {
            puts("No solution!");
        }
    }
    return 0;
}