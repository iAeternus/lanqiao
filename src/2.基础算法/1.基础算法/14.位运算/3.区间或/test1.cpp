/**
 * https://www.lanqiao.cn/problems/3691/learning/?page=1&first_category_id=1&problem_id=3691
*/
#include <bits/stdc++.h>

const int N = 1e5 + 9;

int a[N], prefix[35][N];

/**
 * 0 0 1
 * 0 1 0
 * 0 1 1
 * 1 0 0
 * 1 0 1
 * 
 * -> 111 -> 7
 * 拆位算贡献
*/
/*
sample input
5 2
1 2 3 4 5
1 5
2 3
sample output
7
3
*/
int main()
{
    int n, q;
    std::cin >> n >> q;
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
    }

    for(int w = 0; w < 31; ++w)
    {
        for(int i = 1; i <= n; ++i)
        {
            prefix[w][i] = prefix[w][i - 1] + (a[i] >> w & 1);
        }
    }

    while(q--)
    {
        int l, r;
        std::cin >> l >> r;
        
        int ans = 0;
        for(int w = 0; w < 31; ++w)
        {
            ans += (1 << w) * (!!(prefix[w][r] - prefix[w][l - 1]));
        }

        std::cout << ans << std::endl;
    }

    return 0;
}