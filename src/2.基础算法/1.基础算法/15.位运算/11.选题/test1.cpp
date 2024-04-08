/**
 * https://www.lanqiao.cn/problems/3263/learning/?page=1&first_category_id=1&name=%E9%80%89%E9%A2%98
 *
 * 暴力
 */
/*
sample input
5 1 10 3
1 1 3 5 7
sample output
3
*/
#include <bits/stdc++.h>

const int N = 20;

int a[N];

int max3(int a, int b, int c)
{
    return std::max(std::max(a, b), c);
}

int min3(int a, int b, int c)
{
    return std::min(std::min(a, b), c);
}

int main()
{
    int n, l, r, x;
    std::cin >> n >> l >> r >> x;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }

    int ans = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                if (i != j && i != k && j != k)
                {
                    int a1 = a[i], a2 = a[j], a3 = a[k];
                    int max = max3(a1, a2, a3);
                    int min = min3(a1, a2, a3);
                    int sum = a1 + a2 + a3;
                    
                    if(max - min >= x && sum >= l && sum <= r)
                    {
                        ++ans;
                    }
                }
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
