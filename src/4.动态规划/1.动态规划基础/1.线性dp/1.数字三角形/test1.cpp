/**
 * https://www.lanqiao.cn/problems/1536/learning/?page=1&first_category_id=1&problem_id=1536
 * 
 * dp[i][j]: 第 i 行，第 j 列的元素往下走最大和为 dp[i][j]
 * dp[i][j] = a[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1])
 * get dp[1][1]
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
30
*/
#include <bits/stdc++.h>

const int N = 105;
int a[N][N], dp[N][N];
int n;

int solve()
{
    // dp
    for(int i = n; i >= 1; --i)
    {
        for(int j = i; j >= 1; --j)
        {
            dp[i][j] = a[i][j] + std::max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    return dp[1][1];
}

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

    std::cout << solve() << std::endl;

    return 0;
}