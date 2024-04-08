/*
给出数列A1,A2,…,AN，并设
Bi = (A1 * A2 * A3 … AN) / Ai mod (109 + 7)
现要求把所有的Bi 算出来

Input:
输入包含多组测试数据。对于每组数据，第1 行，1 个整数N(1 ≤N≤100,000), 表示数列的长度。
第2行，N 个整数A1,A2,…,AN(1 ≤Ai≤109)，表示给出的数列。

Output:
对于每组数据，输出一行，N 个整数用空格分隔，表示算出的B1,B2,…,BN。

Sample Input:
3
1 2 3

Sample Output:
6 3 2
--------------------------------------------------------------
将 Bi 看做两个区块：即 A[1…i-1] 和 A[i+1…n] 的乘积对 MOD 取模
*/
#include <bits/stdc++.h>

#define MOD 1000000007
#define MAX_N 100002

int n, a[MAX_N], pre[MAX_N], suf[MAX_N];

int main()
{
    std::cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
    }

    pre[0] = suf[n + 1] = 1;

    for(int i = 1; i <= n; ++i)
    {
        pre[i] = (pre[i - 1] * a[i]) % MOD;
    }
    for(int i = n; i >= 1; --i)
    {
        suf[i] = (suf[i + 1] * a[i]) % MOD;
    }

    for(int i = 1; i <= n; ++i)
    {
        std::cout << pre[i - 1] * suf[i + 1] << ' ';
    }
    std::cout << std::endl;

    return 0;
}