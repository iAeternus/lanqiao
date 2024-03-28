/**
 * https://www.lanqiao.cn/problems/4059/learning/?page=1&first_category_id=1&problem_id=4059
 */
/*
sample input
5 20
20 16 4
2 4 16
10 18 6
18 14 14
18 17 5
sample output
40
*/
#include <bits/stdc++.h>

const int N = 1e3 + 5;
const int V = 2e4 + 5;
int n, c, w[N], v[N], s[N], dp[V];

int main() 
{
    std::cin >> n >> c;
    for (int i = 1; i <= n; ++i) 
    {
        std::cin >> w[i] >> v[i] >> s[i];
    }

    // dp 二进制模型优化，O(n * log2(c) * V)
    for (int i = 1; i <= n; ++i) 
    {
        for(int k = 1; k <= s[i]; s[i] -= k, k *= 2) // 多重背包，一个物品有 s 件，拆分成 1/2/4/8 ... 件相同的物品，退化为 01背包
        {
            for (int j = c; j >= k * w[i]; --j) // 这里要乘 k
            {
                dp[j] = std::max(dp[j], dp[j - k * w[i]] + k * v[i]);
            }
        }
        // 跑剩下的
        for (int j = c; j >= s[i] * w[i]; --j) 
        {
            dp[j] = std::max(dp[j], dp[j - s[i] * w[i]] + s[i] * v[i]);
        }
    }

    std::cout << dp[c] << std::endl;

    return 0;
}