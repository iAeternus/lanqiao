#include <iostream>

using ll = long long;
const int N = 1e6;

ll a[N], n, k;

// 验证组成的花束数 mid 是否可行
bool check(ll mid)
{
    ll cnt = 0; // 总贡献的花朵数
    for(int i = 1; i <= n; ++i)
    {
        cnt += std::min(a[i], mid);
    }
    return cnt / k >= mid;
}

int main()
{
    std::cin >> n >> k;
    ll sum = 0;
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        sum += a[i];
    }

    ll left = 0, right = sum + 1;
    while(left + 1 != right)
    {
        ll mid = left - ((left - right) >> 1);
        if(check(mid))
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