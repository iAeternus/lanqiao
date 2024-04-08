/**
 * https://www.lanqiao.cn/problems/364/learning/?page=1&first_category_id=1&problem_id=364
*/
#include <iostream>
#include <vector>

using ll = long long;
const int N = 5e4 + 9;

ll L;
int n, m;
ll D[N];

// 二分 最短跳跃距离: 需要搬走的石头数，找最短跳跃距离 == mid 时需要搬走的石头数
int check(int mid)
{
    int min = 0, prev = 0;
    for(int i = 1; i <= n; ++i)
    {
        // 不能比最短还短
        if(D[i] - D[prev] < mid)
        {
            ++min;
            continue;
        }

        prev = i;
    }

    if(L - D[prev] < mid)
    {
        return m + 1; // 非法
    }

    return min;
}

int main()
{
    std::cin >> L >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> D[i];
    }

    ll left = 0, right = 1e9 + 5;
    while(left + 1 != right)
    {
        int mid = left - ((left - right) >> 1);
        if(check(mid) <= m)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }

    std::cout << left << std::endl;

    return 0;
}