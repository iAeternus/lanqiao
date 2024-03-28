/**
 * https://www.luogu.com.cn/problem/P2440
*/
/*
sample input
3 7
232
124
456
sample output
114
*/
#include <bits/stdc++.h>

const int N = 1e5 + 9;
int a[N], n, k, max_a, sum;

bool check(int mid) // 这里的 mid 就相当于切出来小段木头的长度
{
    int sum = 0; // 段数
    for(int i = 1; i <= n; ++i)
    {
        sum += a[i] / mid;
    }
    if(sum >= k) return true; // 段数够了
    return false;
}

int main()
{
    std::cin >> n >> k;
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        sum += a[i];
        max_a = std::max(max_a, a[i]);
    }

    if(sum < k) // sum < k * 1(cm)
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    // 求最大值
    int l = 1, r = max_a; // 二分到最后 l 即最大值
    while(l < r)
    {
        int mid = (l + r + 1) >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }

    std::cout << l << std::endl;

    return 0;
}