/**
 * https://www.lanqiao.cn/problems/2223/learning/?page=1&first_category_id=1&problem_id=2223
 * 
 * dp[i][j]: 使用 i 次魔法，且背包容量为 j时最大价值为 dp[i][j]
 * 使用 0 次
 *      dp[0][j] = max(dp[0][j], dp[0][j - w[i]] + v[i]])
 * 使用 1 次            不选        选但不使用魔法          选且使用魔法
 *      dp[1][j] = max(dp[1][j], dp[1][j - w[i]] + v[i], dp[1][j - w[i] - k] + v[i] * 2)
 * get max(dp[0][M], dp[1][M])
*/
/*
sample input
3 10 3
5 10
4 9
3 8
sample output
26
*/
#include <bits/stdc++.h>

using ll = long long;
const ll N = 2010;
const ll C = 1e4 + 10;
int n, m, k;
ll w[N], v[N], dp[2][C];

int main()
{
    std::cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> w[i] >> v[i];
    }

    // dp
    for(int i = 1; i <= n; ++i)
    {
        for(int j = m; j >= w[i]; --j)
        {
            dp[0][j] = std::max(dp[0][j], dp[0][j - w[i]] + v[i]);
            dp[1][j] = std::max(dp[1][j], dp[1][j - w[i]] + v[i]);
            // 背包容量能承受使用魔法后的重量+k，才考虑使用魔法
            if(j >= w[i] + k)
            {
                dp[1][j] = std::max(dp[1][j], dp[1][j - w[i] - k] + v[i] * 2);
            }
        }
    }

    std::cout << std::max(dp[0][m], dp[1][m]) << std::endl;

    return 0;
}