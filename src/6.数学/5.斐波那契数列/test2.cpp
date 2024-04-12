#include <bits/stdc++.h>

#include "timer.h"

using ll = long long;
using vll = std::vector<std::vector<ll>>;

const ll mod = 1e9 + 7;

vll operator*(const vll& m1, const vll& m2) {
    vll ans(2, std::vector<ll>(2));
    for (int i = 0; i < m1.size(); ++i) {
        for (int j = 0; j < m2[0].size(); ++j) {
            for (int k = 0; k < m1[0].size(); ++k) {
                ll tmp = m1[i][k] * m2[k][j] % mod;
                ans[i][j] = (ans[i][j] + tmp) % mod;
            }
        }
    }
    return ans;
}

vll matrix_pow(vll base, ll power) {
    vll ans = {{1, 0}, {0, 1}};
    while (power) {
        if (power & 1) {
            ans = ans * base;
            --power;
        }
        power >>= 1;
        base = base * base;
    }
    return ans;
}

ll fib_logn(ll n) {
    vll A = {{1, 1}, {1, 0}};
    return matrix_pow(A, n)[1][0];
}

ll fib_n(ll n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    ll a = 1, b = 1, sum = 0;
    for (int i = 2; i < n; ++i) {
        sum = (a + b) % mod;
        a = b;
        b = sum;
    }
    return sum;
}

int main() {
    int N = 536870912; // 2^29

    for(int i = 1; i <= N; i *= 2) {
        std::cout << i << '\t' << Timer::automatic_measurement_of_time2([&]() {fib_logn(i);}, 10)
        << '\t' << Timer::automatic_measurement_of_time2([&]() {fib_n(i);}, 10) << std::endl;
    }

    return 0;
}