/**
 * https://www.lanqiao.cn/problems/926/learning/?page=1&first_category_id=1&problem_id=926
 * 
 * dp[i][j]: 区间 [1, j] 最少涂色次数为 dp[i][j]
 * 
 * if a[i] == a[j]  dp[i][j] = min(dp[i + 1][j], dp[i][j - 1])
 * else             dp[i][j] = min(dp[i][k] + dp[k + 1][j])
 * 
 * get dp[1][n]
*/
#include <bits/stdc++.h>

const int N = 55;
std::string a;
int dp[N][N];

int main()
{
    std::cin >> a;
    int n = a.size();

    memset(dp, 127, sizeof(dp));
    for(int i = 0; i < n; ++i)
    {
        dp[i][i] = 1;
    }

    for(int len = 2; len <= n; ++len)
    {
        for(int i = 0; i + len - 1 < n; ++i)
        {
            int j = i + len - 1;
            if(a[i] == a[j])
            {
                dp[i][j] = std::min(dp[i + 1][j], dp[i][j - 1]);
            }
            else
            {
                for(int k = i; k < j; ++k)
                {
                    dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
    }

    std::cout << dp[0][n - 1] << std::endl;

    return 0;
}
