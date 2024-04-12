/**
 * 
*/
#include <bits/stdc++.h>

const int mod = 1e9 + 7;

int getLen(int num) {
    int ans = 0;
    while(num) {
        num /= 10;
        ++ans;
    }
    return ans;
}

int quick_pow(int base, int power) {
    int ans = 1;
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

int solve(int n, int x) {
    int len = getLen(n);
    for(int i = 0; i < len; ++i) {
        int tmp = (quick_pow(10, i) + x) % mod;
        n = (n + tmp) % mod;
    }
    return n;
}

int solve(int n, int k, int x) {
    for(int i = 1; i <= k; ++i) {
        n = solve(n, x);
    }
    return n;
}

int main() {
    int t, x;
    std::cin >> t >> x;
    for(int i = 1; i <= t; ++i) {
        int n, k;
        std::cin >> n >> k;
        std::cout << solve(n, k, x) << std::endl;
    }
    return 0;
}