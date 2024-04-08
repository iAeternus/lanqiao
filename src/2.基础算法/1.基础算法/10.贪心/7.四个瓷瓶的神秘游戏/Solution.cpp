/**
 * https://www.lanqiao.cn/problems/3974/learning/?page=1&first_category_id=1&name=%E5%9B%9B%E4%B8%AA%E7%93%B7%E7%93%B6%E7%9A%84%E7%A5%9E%E7%A7%98%E6%B8%B8%E6%88%8F
 */
#include <iostream>
#include <unordered_map>
#include <algorithm>

using ll = long long;

int equal_count(ll arr[], int size)
{
    std::unordered_map<ll, ll> map;
    int cnt = 1;

    for (int i = 0; i < size; ++i)
    {
        ++map[arr[i]];
    }

    for (const auto &pair : map)
    {
        if (pair.second > 1)
        {
            ++cnt;
        }
    }

    return cnt;
}

int solve(ll arr[4])
{
    ll max = -1;
    // 判断有几个数相同
    int equal_cnt = equal_count(arr, 4);
    if (equal_cnt > 2)
    {
        if (arr[0] != arr[1])
        {
            max = arr[0] + 2 * arr[3]; // 0 4 4 4
        }
        else
        {
            max = arr[3] + 2 * arr[0]; // 3 3 3 3
        }
        return max;
    }

    max = arr[3] + 2 * arr[0];
    arr[2] -= arr[0];
    arr[1] -= arr[0];
    arr[0] = 0;

    max += arr[1] / 3 * 3;
    if (arr[1] % 3 == 2)
    {
        max++;
    }
    return max;
}

int main()
{
    ll arr[4];
    for (int i = 0; i < 4; ++i)
    {
        std::cin >> arr[i];
    }

    std::sort(arr, arr + 4);

    std::cout << solve(arr) << std::endl;

    return 0;
}