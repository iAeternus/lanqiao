/**
 * 给定 a,b,c,q
 * 每次将 a 变成 a / b + c，持续 q 次
 * 求 a
 * 
 * 要求一个 O(logN) 的算法
 * -----------------------------------------
 * dp[i][j]: 对 i 操作 2^j 得到的结果为 dp[i][j]
 * dp[i][0] = i / b + c
 * dp[i][j] = dp[dp[i][j - 1]][j - 1]
*/
#include <bits/stdc++.h>

using ll = long long;
#define MAX_N 100050

ll dp[MAX_N][35], a, b, c, q;

ll func()
{
    if(b == 1)
        return a + c * q;

    // init
    for(int i = 0; i <= 100000; ++i)
    {
        dp[i][0] = i / b + c;
    }

    // dp
    for(int j = 1; j <= 30; ++j)
    {
        for(int i = 0; i <= 100000; ++i)
        {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }

    // query
    for(int i = 0; i <= 30; ++i)
    {
        if((q >> i) & 1)
        {
            a = dp[a][i];
        }
    }

    return a;
}

int main()
{
    std::cin >> a >> b >> c >> q;
    std::cout << func() << std::endl;
    return 0;
}