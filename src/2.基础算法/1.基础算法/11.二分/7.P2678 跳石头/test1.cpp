/**
 * https://www.luogu.com.cn/problem/P2678
*/
/*
sample input
25 5 2 
2
11
14
17 
21
sample output
4
*/
#include <bits/stdc++.h>

using ll = long long;

const int N = 5e5 + 9;
const int MAX = 1e9 + 3;
int len, n, m;
ll a[N];

bool check(ll mid) //检查，是否最短距离为 mid，如果两石头间距小于 mid，不满足，移走 
{
    int cnt = 0; // 移走的石头数量
    int cur = 0; // 当期位置
    int i = 0;
    while(i <= n)
    {
        ++i;
        if(a[i] - a[cur] < mid) // 比最小还小，移走
        {
            ++cnt;
        }
        else // 满足条件，跳过来
        {
            cur = i;
        }
    }
    if(cnt <= m) return true;
    return false;
}

int main()
{
    std::cin >> len >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
    }
    a[0] = 0, a[n + 1] = len; // 首尾也有石头

    if(n == 0) // 没有石头，只能一次从头跳到尾
    {
        std::cout << len << std::endl;
        return 0;
    }

    ll l = 1, r = MAX;
    // 求最大值，使用模板二
    while(l < r)
    {
        ll mid = (l + r + 1) >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }

    std::cout << l << std::endl;

    return 0;
}