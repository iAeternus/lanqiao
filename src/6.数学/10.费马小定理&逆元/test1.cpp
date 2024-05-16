/**
 * 费马小定理: 若 p 为质数，且 gcd(a, p) = 1，则有 a^(p - 1) = 1(mod p)
 * 
 * https://www.lanqiao.cn/problems/1157/learning/?page=1&first_category_id=1&name=%E4%B9%98%E6%B3%95%E9%80%86%E5%85%83
*/
/*
sample input
5
1
2
3
4
5
sample output
1
500000004
333333336
250000002
400000003
*/
#include <bits/stdc++.h>

using ll = long long;
const int mod = 1e9 + 7;

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
    return ans % mod;
}

void solve(int n) {
    std::cout << quick_pow(n, mod - 2) << std::endl;
}

int main()
{
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        solve(n);
    }
    return 0;
}