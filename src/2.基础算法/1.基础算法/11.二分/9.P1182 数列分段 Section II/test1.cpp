/**
 * https://www.luogu.com.cn/problem/P1182
*/
/*
sample input
5 3
4 2 4 5 1
sample output
6
*/
#include <bits/stdc++.h>

const int N = 1e5 + 7;
int a[N], n, m, max, sum;

// mid 表示每段和的最大值
bool check(int mid)
{
    int sum = 0, cnt = 0;
    for(int i = 1; i <= n - 1; ++i)
    {
        sum += a[i];
        // 如果 sum 加上下一个数比最大值大了，就不能加，得分段
        if(sum + a[i + 1] > mid)
        {
            sum = 0;
            ++cnt;
        }
    }
    if(cnt + 1 <= m) return true;
    return false;
}

int main()
{
    std::cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        max = std::max(max, a[i]);
        sum += a[i];
    }

    int l = max, r = sum;
    // 求最大和的最小值，模板一
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    } 

    std::cout << l << std::endl;

    return 0;
}