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
int next[N];

int main()
{
    std::cin >> p + 1; int m = strlen(p + 1);
    std::cin >> s + 1; int n = strlen(s + 1);

    // get next
    next[0] = next[1] = 0;
    for(int i = 2, j = 0; i <= m; ++i)
    {
        while(j && p[i] != p[j + 1])
        {
            j = next[j];
        }
        if(p[i] == p[j + 1])
        {
            ++j;
        }
        next[i] = j;
    }

    // KMP
    int ans = 0;
    for(int i = 1, j = 0; i <= n; ++i)
    {
        while(j && s[i] != p[j + 1])
        {
            j = next[j];
        }
        if(s[i] == p[j + 1])
        {
            ++j;
        }
        // 匹配了
        if(j == m)
        {
            ++ans;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}