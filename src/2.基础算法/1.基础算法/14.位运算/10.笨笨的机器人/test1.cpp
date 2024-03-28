/**
 * https://www.lanqiao.cn/problems/3262/learning/?page=1&first_category_id=1&name=%E7%AC%A8%E7%AC%A8%E7%9A%84%E6%9C%BA%E5%99%A8%E4%BA%BA
 * 
 * 假设向左为 0，向右为 1
 * 样本空间为 2^n
 * 看成二进制数 00001 ~ 11111
 * 只需模拟过程即可
 * 
 * 状态压缩
*/
/*
sample input
5
1 2 3 4 5
sample output
0.1250
*/
#include <bits/stdc++.h>

const int N = 20;

int a[N];

int main()
{
    int n;
    std::cin >> n;
    for(int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }

    double sum = pow(2, n);
    double ans = 0;

    for(int i = 1; i <= sum; ++i) // 00001 ~ 11111
    {
        int res = 0;
        for(int j = 0; j < n; ++j)
        {
            if((i >> j) & 1)
            {
                res += a[j];
            }
            else
            {
                res -= a[j];
            }
            res %= 7;
        }

        if(res % 7 == 0)
        {
            ++ans;
        }
    }

    printf("%.4f\n", round(ans / sum * 10000.0) / 10000.0);

    return 0;
}