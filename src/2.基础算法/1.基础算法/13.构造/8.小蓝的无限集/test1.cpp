/**
 * https://blog.csdn.net/2301_77138117/article/details/136081301
 *
 * 考虑第一次操作
 *      1. x * a -> n = a^x + b*y (乘 x 次 a，加 y 次 b)
 *      2. x + b -> n = (1 + b) * a^x + b*y = b * (a^x + y) + a^x
 * 有
 *      n - a^x = by
 *      n - a^x = b*(a^x + y)
 *
 * 那么
 *      1. if b|(n - 1) -> Yes
 *      2. else if a == 1 -> No
 *      3. else 枚举 a^x，使 b|(n - a^x)
 */
#include <bits/stdc++.h>

using ll = long long;
#define MOD 998244353 // 经典的模数

// calculating pow(a, b)
ll ksm(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res % MOD;
}

// TODO
bool func(ll a, ll b, ll n)
{
    if((n - 1) % b == 0) return true;
    else if(a == 1) return false;
    else
    {
        ll x = 1;
        ll p = ksm(a, x++);
        while(n > p)
        {
            if((n - p) % b == 0)
            {
                return true;
            }
            p = ksm(a, x++);
        }
    }

    return false;
}

int main()
{
    int t;
    std::cin >> t;
    ll a, b, n;
    for(int i = 0; i < t; ++i)
    {
        std::cin >> a >> b >> n;
        std::cout << (func(a, b, n) ? "Yes" : "No") << std::endl;
    }
    return 0;
}