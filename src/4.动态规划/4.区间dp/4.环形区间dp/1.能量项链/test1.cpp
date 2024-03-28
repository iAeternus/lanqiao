/**
 * https://www.lanqiao.cn/problems/557/learning/?page=1&first_category_id=1&problem_id=557
 * 
 * 这个题本质上跟合并石子没有区别，只是环形区间需要复制区间
 * 
 * dp[i][j]: 区间 [i, j] 之间的所有珠子最优合并为一个所释放的总能量为 dp[i][j]
 * 
 * dp
 * dp[i][j] = max(dp[i][k] + dp[k + 1][j] + v[i] * v[k + 1] * v[j + 1])
 * 
 * get max(dp[i][i + n - 1])
*/
/*
sample input
4
2  3  5  10
sample output
710
*/
#include <bits/stdc++.h>

const int N = 105;
int n, v[N << 1], dp[N << 1][N << 1]; // 要复制区间所以要 * 2

int main()
{
    std::cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> v[i];
        v[i + n] = v[i]; // 复制区间
    }

    // dp
    for(int len = 2; len <= n; ++len)
    {
        for(int i = 1; i + len - 1 <= n * 2; ++i) // 注意 n * 2
        {
            int j = i + len - 1;
            for(int k = i; k < j; ++k)
            {
                dp[i][j] = std::max(dp[i][j], dp[i][k] + dp[k + 1][j] + v[i] * v[k + 1] * v[j + 1]);
            }
        }
    }

    // get 寻找一个最优的起点
    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        ans = std::max(ans, dp[i][i + n - 1]);
    }

    std::cout << ans << std::endl;

    return 0;
}