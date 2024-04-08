/**
 * https://www.lanqiao.cn/problems/4169/learning/?page=1&first_category_id=1&name=%E9%B8%A1%E5%93%A5%E7%9A%84%E8%B4%AD%E7%89%A9%E6%8C%91%E6%88%98
 */
#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int main()
{
    int n;
    std::cin >> n;
    std::vector<ll> arr(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    std::sort(arr.begin(), arr.end(), [](const ll &o1, const ll &o2) -> bool { 
        return o1 > o2; 
    });

    ll ans = 0;
    int i, len = 0;
    for(i = 0; i < arr.size(); ++i)
    {
        if(arr[i] > 0)
        {
            ans += arr[i];
            ++len;
        }
        else
        {
            break;
        }
    }

    if(len & 1)
    {
        if(i == n)
        {
            std::cout << ans - arr[n - 1] << std::endl; // 5 4 3 2 (1)
        }
        else
        {
            // 加上新的一项和减去最小一项哪个收益高
            std::cout << std::max(ans + arr[i], ans - arr[i - 1]) << std::endl;
        }
    }
    else
    {
        std::cout << ans << std::endl;
    }

    return 0;
}