/**
 * https://www.lanqiao.cn/problems/3404/learning/?page=1&first_category_id=1&problem_id=3404
*/
#include <iostream>

using ll = long long;

ll n, m, k;

// 乘法表中 <= mid 的数字有多少个
ll check(ll mid)
{
    ll cnt = 0;
    for(int i = 1; i <= n; ++i)
    {
        cnt += std::min(m, mid / i);
    }
    return cnt;
}

int main()
{
    std::cin >> n >> m >> k;

    ll left = 0, right = 1e14;
    while(left + 1 != right)
    {
        ll mid = left - ((left - right) >> 1);
        if(check(mid) < k)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }

    std::cout << right << std::endl;

    return 0;
}