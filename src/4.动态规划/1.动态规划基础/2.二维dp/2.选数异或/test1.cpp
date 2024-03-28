/**
 * https://www.lanqiao.cn/problems/3711/learning/?page=1&first_category_id=1&problem_id=3711
 * 
 * dp[i][j]: 选到第 i 个数为止，异或和为 j 的方案总数为 dp[i][j]
 *            不选第 i 个数   选第 i 个数
 * dp[i][j] = dp[i - 1][j] + dp[i - 1][j ^ a[i]]
 * dp[0][0] = 1 不选，异或和为 0
 * get dp[n][x]
*/
/*
sample input
2 0
2 2
sample output
2
*/
#include <bits/stdc++.h>

using ll = long long;
const ll p = 998244353;
const int N = 1e5 + 9;

int n, x;
int a[N];
ll dp[N][100];

int main()
{
    std::cin >> n >> x;
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
    }

    // base case
    dp[0][0] = 1; // 不选，异或和为 0

    // dp
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 64; j >= 0; --j)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j ^ a[i]]) % p;
        }
    }

    std::cout << dp[n][x] << std::endl;

    return 0;
}
