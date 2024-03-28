/**
 * https://www.lanqiao.cn/problems/505/learning/?page=1&first_category_id=1&problem_id=505
 * 
 * 与 505 那道题的区别是左移和右移的次数之差绝对值 <= 1
 * dp[i][j][k]: 第 i 行，第 j 列的元素往下右移 k 次的最大和为 dp[i][j] （左移了 n - i - k 次）
 * dp[i][j][k] = a[i][j] + max(dp[i + 1][j][k], dp[i + 1][j + 1][k - 1])
 * dp[n][j][k] = a[n][j]
 * 根据移动次数 n - 1 的奇偶分类讨论
 *      n - 1 奇，看最后一步是左移还是右移
 *          get max(dp[1][1][floor((n - 1) / 2)], dp[1][1][(n - 1) - floor((n - 1) / 2)])
 *      else
 *          get dp[1][1][(n - 1) / 2]         
*/
/*
sample input
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
sample output
27
*/
#include <bits/stdc++.h>

const int N = 105;
int a[N][N], dp[N][N][N];
int n;

int main()
{
    std::cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= i; ++j)
        {
            std::cin >> a[i][j];
        }
    }

    // dp
    for(int i = n; i >= 1; --i)
    {
        for(int j = 1; j <= i; ++j)
        {
            for(int k = 0; k <= n - i; ++k)
            {
                if(k > 0) dp[i][j][k] = a[i][j] + std::max(dp[i + 1][j][k], dp[i + 1][j + 1][k - 1]);
                else dp[i][j][k] = a[i][j] + dp[i + 1][j][k];
            }
        }
    }

    int range = (n - 1) / 2;
    if((n - 1) & 1) // 移动次数为 n - 1
    {
        std::cout << std::max(dp[1][1][range], dp[1][1][n - 1 - range]) << std::endl;
    }
    else
    {
        std::cout << dp[1][1][range] << std::endl;
    }

    return 0;
}