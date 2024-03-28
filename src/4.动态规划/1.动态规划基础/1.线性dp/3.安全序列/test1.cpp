/**
 * https://www.lanqiao.cn/problems/3423/learning/?page=1&first_category_id=1&problem_id=3423
 * 
 * dp[i]: 以位置 i 结尾的方案总数为 dp[i]
 * dp[i] = dp[1] + dp[2] + ... + dp[i - k - 1]
 * 可以使用 prefix 优化 dp[i] = prefix[i - k - 1]
 * dp[0] = prefix[0] = 1
 * get dp[1] + dp[2] + ... + dp[n] 即 prefix[n]
*/
/*
sample input
4 2
sample output
6
*/
#include <bits/stdc++.h>

using ll = long long;
const ll N = 1e6 + 5;
const ll p = 1e9 + 7;
int n, k;
ll dp[N], prefix[N];

int main()
{
    std::cin >> n >> k;
    dp[0] = prefix[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        if(i - k - 1 < 1) dp[i] = 1;
        else dp[i] = prefix[i - k - 1];
        prefix[i] = (prefix[i - 1] + dp[i]) % p;
    }

    std::cout << prefix[n] << std::endl;

    return 0;
}
