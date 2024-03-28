/**
 * https://www.lanqiao.cn/problems/3400/learning/?page=1&first_category_id=1&problem_id=3400
 * 
 * 因子个数为偶数 => 该数不是完全平方数
 * 正难则反：计算有多少个子数组的异或和为完全平方数，将总区间数 n * (n + 1) / 2 减去这个数即可
*/
/*
sample input
5
1 2 3 4 5
sample output
7
*/
#include <bits/stdc++.h>

const int N = 1e5 + 9;

int a[N], prexor[N], cnt[N]; // cnt 表示有多少个 j 满足 j < i 且 prexor[j] = prexor[i] ^ sq

int main()
{
    int n;
    std::cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
    }

    for(int i = 1; i <= n; ++i)
    {
        prexor[i] = (prexor[i - 1] ^ a[i]);
    }

    cnt[0] = 1;
    int ans = (n * (n + 1)) >> 1;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j <= 200; ++j)
        {
            int sq = j * j;
            ans -= cnt[prexor[i] ^ sq];
        }
        cnt[prexor[i]]++;
    }

    std::cout << ans << std::endl;

    return 0;
}