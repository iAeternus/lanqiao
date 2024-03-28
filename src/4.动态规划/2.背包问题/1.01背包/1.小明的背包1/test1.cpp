/**
 * https://www.lanqiao.cn/problems/1174/learning/?page=1&first_category_id=1&problem_id=1174
 * 
 * 01背包
 * dp[j]: 背包容量为 j 时能装的最大价值为 dp[j]
 * dp[j] = max(dp[j], dp[j - w[i]] + v[i])
 * dp[0] = 0
 * get dp[v]
*/
/*
sample input
5 20
1 6
2 5
3 8
5 15
3 3 
sample output
37
*/
#include <bits/stdc++.h>

const int N = 1e2 + 5;
const int V = 1e3 + 5;
int n, c, w[N], v[N], dp[V];

int main()
{
    std::cin >> n >> c;
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> w[i] >> v[i];
    }

    // dp
    for(int i = 1; i <= n; ++i)
    {
        for(int j = c; j >= w[i]; --j)
        {
            dp[j] = std::max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    std::cout << dp[c] << std::endl;

    return 0;
}