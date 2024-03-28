/*
https://www.lanqiao.cn/problems/3260/learning/?page=1&first_category_id=1&name=%E6%9C%80%E5%A4%A7%E6%95%B0%E7%BB%84%E5%92%8C
*/
#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void getPrefix(const std::vector<ll>& values, std::vector<ll>& prefix)
{
    prefix.assign(values.size(), values[0]);
    for (int i = 1; i < values.size(); ++i)
    {
        prefix[i] = prefix[i - 1] + values[i];
    }
}

void runOnce()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<ll> values(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> values[i];
    }

    std::sort(values.begin(), values.end());

    std::vector<ll> prefix;
    getPrefix(values, prefix);

    ll result = 0;
    for (int i = 0; i <= k; ++i)
    {
        result = std::max(result, prefix[n - (k - i)] - prefix[2 * i]);
    }

    std::cout << result << std::endl;
}

int main()
{
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i)
    {
        runOnce();
    }

    return 0;
}