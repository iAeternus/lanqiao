/**
 * https://www.lanqiao.cn/problems/1155/learning/?page=1&first_category_id=1&problem_id=1155
 * 
 * 欧拉降幂
 * n^(m!) = n^(m! % phi(c)) (mod c)
*/
/*
sample input
2 3
sample output
64
*/
#include <bits/stdc++.h>

using ll = long long;
const int mod = 1e9 + 7;

ll phi(ll n) {
    ll p = n;
    for(int i = 2; i <= n / i; ++i) {
        if(n % i) continue;
        p = p / i * (i - 1);
        while(n % i == 0) n /= i;
    }
    if(n > 1) p = p / n * (n - 1);
    return p;
}

ll fact(ll n, ll mod) {
    ll ans = 1;
    for(int i = 1; i <= n; ++i) {
        ans = ans * i % mod;
    }
    return ans;
}

ll quick_pow(ll base, ll power) {
    ll ans = 1;
    while(power) {
        if(power & 1) {
            ans = ans * base % mod;
            --power;
        }
        power >>= 1;
        base = base * base % mod;
    }
    return ans;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::cout << quick_pow(n, fact(m, phi(mod))) << std::endl;
    return 0;
}