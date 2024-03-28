/**
 * 给定 n
 * 有 1/a + 1/b + 1/c = 1/n
 * 输出一组解 a b c
 * ------------------------------------------
 * n = 1      1 = 1/2 + 1/2   1/2 = 1/3 + 1/6
 * n = 2    1/2 = 1/4 + 1/4   1/4 = 1/6 + 1/12
 * n        1/n = 1/2n + 1/3n + 1/6n
 */
#include <bits/stdc++.h>

using ll = long long;

int main()
{
    ll n;
    std::cin >> n;
    printf("%lld %lld %lld", 2 * n, 3 * n, 6 * n);
    return 0;
}