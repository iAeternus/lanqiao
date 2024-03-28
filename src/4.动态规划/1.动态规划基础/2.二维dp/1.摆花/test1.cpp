/**
 * https://www.lanqiao.cn/problems/389/learning/?page=1&first_category_id=1&problem_id=389
 * 
 * dp[i][j]: 排列到第 i 种为止，第 j 个位置为止的总方案数为 dp[i][j]
 * dp[i][j] = sum(dp[i - 1][j - k]) for k in [0, a[i]]
 * dp[0][0] = 1
 * get dp[n][m]
*/
/*
sample input
2 4
3 2
sample output
2
*/
#include <bits/stdc++.h>

using ll = long long;
const int N = 105;
const ll p = 1e6 + 7;

int a[N], n, m;
ll dp[N][N];

int main()
{
    std::cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
    }

    dp[0][0] = 1;

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j <= m; ++j)
        {
            ll tmp = 0;
            for(int k = 0; k <= a[i] && k <= j; ++k)
            {
                tmp = (tmp + dp[i - 1][j - k]) % p;
            }
            dp[i][j] = tmp;
        }
    }

    std::cout << dp[n][m] << std::endl;

    return 0;
}