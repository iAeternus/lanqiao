/*
https://www.lanqiao.cn/problems/3898/learning/?page=1&first_category_id=1&name=%E6%B3%A1%E6%BE%A1
*/
#include <iostream>
#include <vector>

using ll = long long;

const int max_n = 1e6;
ll diff[max_n];

void solve(int n, int w)
{
    ll max_t = 0;
    for (int i = 0; i < n; ++i)
    {
        ll s, t;
        ll p;
        std::cin >> s >> t >> p;
        max_t = std::max(max_t, t);

        diff[s + 1] += p;
        diff[t + 1] -= p;
    }

    // 还原原数组
    for (int i = 1; i <= max_t; ++i)
    {
        diff[i] += diff[i - 1];
        if (diff[i] > w)
        {
            std::cout << "No\n";
            return;
        }
    }
    std::cout << "Yes\n";
}

int main()
{
    ll n, w;
    std::cin >> n >> w;

    solve(n, w);

    return 0;
}