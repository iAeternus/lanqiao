/**
 * https://www.lanqiao.cn/problems/1176/learning/?page=1&first_category_id=1&problem_id=1176
 */
/*
sample input
3 30
1 2 3
4 5 6
7 8 9
sample output
39
*/
#include <bits/stdc++.h>

const int N = 105;
const int V = 205;
int n, c, w[N], v[N], s[N], dp[V];

int main() 
{
    std::cin >> n >> c;
    for (int i = 1; i <= n; ++i) 
    {
        std::cin >> w[i] >> v[i] >> s[i];
    }

    // dp 未优化，O(n * c * V)
    for (int i = 1; i <= n; ++i) 
    {
        while (s[i]--) // 多重背包，一个物品有 s 件，拆分成 s 件相同的物品，退化为 01背包
        {
            for (int j = c; j >= w[i]; --j) 
            {
                dp[j] = std::max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
    }

    std::cout << dp[c] << std::endl;

    return 0;
}