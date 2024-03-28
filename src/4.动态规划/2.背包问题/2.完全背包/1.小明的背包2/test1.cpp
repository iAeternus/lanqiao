/**
 * https://www.lanqiao.cn/problems/1175/learning/?page=1&first_category_id=1&problem_id=1175
 * 
 * 完全背包
 * 将01背包中遍历背包容量的循环改为正向迭代即可，即允许物品使用多次
*/
/*
sample input
5 20
1 6
2 5
3 8
5 15
3 3 
sample output
120
*/
#include <bits/stdc++.h>

const int N = 1e3 + 5;
const int V = 1e3 + 5;
int n, c, w[N], v[N], dp[V];

int main()
{
    std::cin >> n >> c;
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> w[i] >> v[i];
    }

    // dp
    for(int i = 1; i <= n; ++i)
    {
        for(int j = w[i]; j <= c; ++j)
        {
            dp[j] = std::max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    std::cout << dp[c] << std::endl;

    return 0;
}