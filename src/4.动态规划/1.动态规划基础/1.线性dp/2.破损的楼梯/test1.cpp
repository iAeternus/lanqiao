/**
 * https://www.lanqiao.cn/problems/3367/learning/?page=1&first_category_id=1&problem_id=3367
 * 
 * dp[i]: 走到第 i 级台阶的走法个数为 dp[i]
 * dp[i] = dp[i - 1] + dp[i - 2]
 * dp[0] = 1
 * get dp[n]
 * 
 * 若楼梯 i 破损，则 dp[i] = 0
*/
/*
sample input
6 1
3
sample output
4
*/
#include <bits/stdc++.h>

using ll = long long;
const ll N = 1e5 + 3;
const ll p = 1e9 + 7;
int n, m;
ll dp[N];
bool broken[N];

int main()
{
    std::cin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        int x;
        std::cin >> x;
        broken[x] = true;
    }

    dp[0] = 1;
    if(!broken[1]) dp[1] = 1;
    for(int i = 2; i <= n; ++i)
    {
        if(broken[i]) continue;
        dp[i] = (dp[i - 1] + dp[i - 2]) % p;
    }

    std::cout << dp[n] << std::endl;

    return 0;
}
