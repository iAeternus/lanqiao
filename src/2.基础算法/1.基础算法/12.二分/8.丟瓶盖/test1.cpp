/**
 * https://blog.csdn.net/Mr_dimple/article/details/114656142/
*/
/*
sample input
5 3
1 2 3 4 5
sample output
2
*/
#include <bits/stdc++.h>

const int N = 1e5 + 7;
int a[N], A, B, max;

// mid 表示拿出来的瓶盖中的最短距离
bool check(int mid)
{
    // 第一个必选，才能保证剩下的距离最大
    int i = 1, cur = 1, cnt = 1;
    while(i <= A)
    {
        ++i;
        if(a[i] - a[cur] >= mid) // 要保证拿走的瓶盖间距大于等于 mid，才拿这个瓶盖，否则不能保证 mid 为最短距离
        {
            cur = i;
            ++cnt;
        }
    }
    // 如果拿出的总个数大于等于 m，都能保证拿走的瓶盖间距大于等于 mid，那拿出来 m 个，肯定也能满足！
    if(cnt >= B) return true;
    return false;
}

int main()
{
    std::cin >> A >> B;
    for(int i = 1; i <= A; ++i)
    {
        std::cin >> a[i];
        max = std::max(max, a[i]);
    }

    // 最短距离的最大值，模板二
    int l = 0, r = max;
    while(l < r)
    {
        int mid = (l + r + 1) >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }

    std::cout << l << std::endl;

    return 0;
}