/**
 * https://www.lanqiao.cn/problems/5035/learning/?page=1&first_category_id=1&name=%E8%AF%BE%E4%B8%8A%E5%B0%8F%E6%B8%B8%E6%88%8F
 * 
 * dp[i][j]: 区间 [i, j] 合并的最大价值为 dp[i][j]
 * 
 * dp[i][j] = max(dp[i][k] + dp[k + 1][j] + mul(i, j))
*/
/*
sample input
5
6 4 2 8 1
sample output
10
*/
#include <bits/stdc++.h>

const int N = 105;
int n;
int a[N << 1], dp[N << 1][N << 1], prefix[N << 1][N << 1];

int main()
{
    std::cin >> n;
    a[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        a[i + n] = a[i];
        prefix[i][i] = prefix[i + n][i + n] = a[i] % 10;
    }

    // init prefix
    for(int len = 2; len <= n; ++len)
    {
        for(int i = 1; i + len - 1 <= (n << 1); ++i)
        {
            int j = i + len - 1;
            prefix[i][j] = prefix[i][j - 1] * a[j] % 10;
        }
    }

    // dp
    for(int len = 2; len <= n; ++len)
    {
        for(int i = 1; i + len - 1 <= (n << 1); ++i)
        {
            int j = i + len - 1;
            for(int k = i; k < j; ++k)
            {
                dp[i][j] = std::max(dp[i][j], dp[i][k] + dp[k + 1][j] + prefix[i][k] * prefix[k + 1][j] / 10);
            }
        }
    }

    // find result
    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        ans = std::max(ans, dp[i][i + n - 1]);
    }
    std::cout << ans << std::endl;

    return 0;
}