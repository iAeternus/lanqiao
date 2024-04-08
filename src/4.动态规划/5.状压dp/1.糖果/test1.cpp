/**
 * https://www.lanqiao.cn/problems/186/learning/?page=1&first_category_id=1&name=%E7%B3%96%E6%9E%9C
 * 
 * dp[j]: 得到状态 j 的最小包数为 dp[j]
 * 
 * dp[j | a[i]] = min(dp[j | a[i]], dp[j] + 1)
 *      解释
 *      1. j | a[i]：在状态 j 的基础上增加状态 a[i]，表示又买了一包糖果
 *      2. dp[j] + 1：包数 + 1
*/
/*
sample input
6 5 3
1 1 2
1 2 3
1 1 3
2 3 5
5 4 2
5 1 2
sample output
2
*/
#include <bits/stdc++.h>

const int N = 105;
const int len = 1 << 20;
int a[N], dp[len];
int n, m, k;

int main()
{
    std::cin >> n >> m >> k;
    // 所有状态总数，假设 k = 5，00000 ~ 11111
    int totalStatus = (1 << m) - 1;

    for(int i = 0; i < len; ++i)
    {
        dp[i] = 0x3f3f3f3f;
    }

    for(int i = 0; i < n; ++i)
    {
        int x;
        for(int j = 0; j < k; ++j)
        {
            std::cin >> x;
            // 将 a[i] 的第 x 位设置为 1，表示这包糖果里有第 x 号糖果
            a[i] |= (1 << (x - 1));
        }
        dp[a[i]] = 1;
    }
    
    // dp
    for(int i = 0; i < n; ++i)
    {
        for(int j = 1; j < totalStatus; ++j) // 遍历所有状态
        {
            dp[j | a[i]] = std::min(dp[j | a[i]], dp[j] + 1);
        }
    }

    std::cout << dp[(1 << m) - 1] << std::endl;

    return 0;
}