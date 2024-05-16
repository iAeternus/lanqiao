/**
 * 欧拉函数 phi(n) 表示 <= n，且与 n 互质的数的个数
*/
#include <bits/stdc++.h>

using ll = long long;

// O(sqrt(n))
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

int main()
{
    for(int i = 1; i <= 100; ++i) {
        std::cout << phi(i) << ' ';
    }
    std::cout << std::endl;
    return 0;
}