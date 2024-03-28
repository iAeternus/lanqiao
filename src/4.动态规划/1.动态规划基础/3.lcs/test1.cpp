/**
 * https://www.lanqiao.cn/problems/1189/learning/?page=1&first_category_id=1&problem_id=1189
 * 
 * dp[i][j]: a[1~i] 和 b[1~j] 的最长公共子序列长度为 dp[i][j]
 * if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1
 * else             dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])
 * get dp[n][m] 
*/
/*
sample input
5 6
1 2 3 4 5
2 3 2 1 4 5
sample output
4
*/
#include <bits/stdc++.h>

const int N = 1e3 + 5;
int n, m;
int a[N], b[N], dp[N][N];

int main()
{
    std::cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
    }
    for(int j = 1; j <= m; ++j)
    {
        std::cin >> b[j];
    }

    // dp
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(a[i] == b[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    std::cout << dp[n][m] << std::endl;

    // rec
    std::vector<int> v;
    int x = n, y = m;
    while(x && y)
    {
        if(a[x] == b[y])
        {
            v.push_back(a[x]);
            --x;
            --y;
        }
        else if(dp[x - 1][y] > dp[x][y - 1]) --x;
        else --y;
    }

    std::reverse(v.begin(), v.end());

    for(const auto& it : v)
    {
        std::cout << it << ' ';
    }
    std::cout << std::endl;

    return 0;
}