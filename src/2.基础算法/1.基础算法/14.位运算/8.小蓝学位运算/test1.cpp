/**
 * https://www.lanqiao.cn/problems/3220/learning/?page=1&first_category_id=1&name=%E5%B0%8F%E8%93%9D%E5%AD%A6%E4%BD%8D%E8%BF%90%E7%AE%97
 * 
 * 异或前缀和
*/
/*
sample input
3
5 27 17
sample output
10327500
*/
#include <bits/stdc++.h>

using ll = long long;
const int N = 1e6 + 9;
const int mod = 1e9 + 7;

ll a[N], prexor[N];

int main()
{
    int n;
    std::cin >> n;

    for(int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }

    for(int i = 0; i < n; ++i)
    {
        prexor[i] = prexor[i - 1] ^ a[i];
    }

    ll res = 1;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = i; j <= n; ++j)
        {
            ll tmp = prexor[j] ^ prexor[i - 1];
            // 一旦出现了 0，结果一定是 0
            if(!tmp)
            {
                std::cout << 0 << std::endl;
                return 0;
            }
            res = res * tmp % mod;
        }
    }

    std::cout << res % mod << std::endl;

    return 0;
}