/*
sample input
5000
sample output
976496506
*/
#include <bits/stdc++.h>

using ll = long long;
const ll p = 1e9 + 7;
const ll inf = 1e9, N = 1e5 + 3;

ll dp[N];

ll fib(int n)
{
    if(n <= 2) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = (fib(n - 1) + fib(n - 2)) % p;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    std::cin >> n;
    std::cout << fib(n) << std::endl;
    return 0;
}