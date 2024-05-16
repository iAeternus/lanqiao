/**
 * https://www.lanqiao.cn/problems/1020/learning/?page=1&first_category_id=1&problem_id=1020
 * 
 * 通过某一数字的唯一分解，可以分解为 x = p1^k1 * p2^k2 * ... * pn^kn
 * 则 x 的正约数个数为 (k1 + 1) * (k2 + 1) * ... * (kn + 1)
*/
#include <bits/stdc++.h>

using ll = long long;
const int N = 105;
int a[N]; // 底数 i 的指数为 a[i]

void func(int n) {
    for(int i = 2; i <= n / i; ++i) {
        if(n % i) continue;
        while(n % i == 0) {
            ++a[i];
            n /= i;
        }
    }
    if(n > 1) ++a[n];
}

int main()
{
    int n = 100;
    for(int i = 1; i <= n; ++i) {
        func(i);
    }

    ll ans = 1;
    for(int i = 1; i <= n; ++i) {
        ans *= (a[i] + 1);
    }

    std::cout << ans << std::endl;

    return 0;
}