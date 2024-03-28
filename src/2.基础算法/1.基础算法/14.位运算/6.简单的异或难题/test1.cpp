/**
 * https://www.lanqiao.cn/problems/3217/learning/?page=1&first_category_id=1&name=%E7%AE%80%E5%8D%95%E7%9A%84%E5%BC%82%E6%88%96%E9%9A%BE%E9%A2%98
 * 
 * 出现偶数次的数异或抵消了，所以直接前缀异或
*/
/*
sample input
6 3
2 4 5 4 7 7 
1 3
1 4
5 6
sample output
3
7
0
*/
#include <bits/stdc++.h>

using ll = long long;
const ll N = 1e5 + 9;

ll a[N], prexor[N];

int main()
{
    ll n, m;
    std::cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
    }

    for(int i = 1; i <= n; ++i)
    {
        prexor[i] = prexor[i - 1] ^ a[i];
    }

    while(m--)
    {
        ll l, r;
        std::cin >> l >> r;
        std::cout << (prexor[r] ^ prexor[l - 1]) << std::endl;
    }

    return 0;
}