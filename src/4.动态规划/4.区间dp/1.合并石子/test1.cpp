/**
 * https://www.lanqiao.cn/problems/1233/learning/?page=1&first_category_id=1&problem_id=1233
 * 
 * dp[i][j]: 区间 [i, j] 合并的最小花费
 * 
 * dp[i][j] = min(dp[i][k] + dp[k + 1][j] + sum(i, k) + sum(k, j))
 *      sum 可用前缀和优化
 *      先枚举区间长度，再枚举区间左端点，最后枚举分界点
 * 
 * get dp[1][n]
*/
#include <bits/stdc++.h>

const int N = 205;
int n, a[N], prefix[N], dp[N][N];

int sum(int i, int j)
{
    return prefix[j] - prefix[i - 1];
}

int main()
{
    std::cin >> n;

    // base case 将 dp 设置为无穷大
    memset(dp, 127, sizeof(dp));

    for(int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        // base case
        dp[i][i] = 0;
        // 计算前缀和
        prefix[i] = prefix[i - 1] + a[i];
    }

    for(int len = 2; len <= n; ++len) // 枚举区间长度
    {
        for(int i = 1; i + len - 1 <= n; ++i) // 枚举左端点
        {
            int j = i + len - 1; // 右端点
            for(int k = i; k < j; ++k)
            {
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum(i, j));
            }
        }
    }

    std::cout << dp[1][n] << std::endl;

    return 0;
}
