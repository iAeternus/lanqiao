#include <iostream>

using ll = long long;
#define MOD 998244353 // 经典的模数

// calculating pow(a, b)
ll pow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res % MOD;
}

int main()
{
    ll a, b;
    std::cin >> a >> b;
    std::cout << pow(a, b) % MOD << std::endl;
    return 0;
}