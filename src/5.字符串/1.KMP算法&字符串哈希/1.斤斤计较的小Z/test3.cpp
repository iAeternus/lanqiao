/**
 * https://www.lanqiao.cn/problems/2047/learning/?page=1&first_category_id=1&name=%E6%96%A4%E6%96%A4%E8%AE%A1%E8%BE%83%E7%9A%84%E5%B0%8FZ
*/
/*
sample input1
LQYK
LQYK
sample output1
1

sample input2
LQYK
LQYKLQYKLQYKLQYK
sample output
4

sample input3
AADSDFGADSWADADADD
WSAD
sample output
0
*/
#include <bits/stdc++.h>

const int N = 1e6 + 9;
char s[N], p[N];
using ull = unsigned long long;
const ull base = 131;
ull h1[N], h2[N], b[N];

ull getHash(ull h[], int l, int r)
{
    return h[r] - h[l - 1] * b[r - l + 1];
}

int main()
{
    std::cin >> p + 1; int m = strlen(p + 1);
    std::cin >> s + 1; int n = strlen(s + 1);

    b[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        b[i] = b[i - 1] * base;
        h1[i] = h1[i - 1] * base + (int) p[i];
        h2[i] = h2[i - 1] * base + (int) s[i];
    }

    int ans = 0;
    for(int i = 1; i + m - 1 <= n; ++i)
    {
        if(getHash(h1, 1, m) == getHash(h2, i, i + m - 1))
        {
            ++ans;
        }
    }
    std::cout << ans << std::endl;

    return 0;
}