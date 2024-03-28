/**
 * https://www.lanqiao.cn/problems/3791/learning/?page=1&first_category_id=1&name=%E7%8F%A0%E5%AE%9D%E7%9A%84%E6%9C%80%E5%A4%A7%E4%BA%A4%E6%9B%BF%E5%92%8C
*/
#include <iostream>
#include <limits>
#include <cmath>

using ll = long long;

int main()
{
    int n;
    std::cin >> n;
    
    ll num, ans = 0;
    ll min = std::numeric_limits<ll>::max();
    ll max = std::numeric_limits<ll>::min();
    for(int i = 0; i < n; ++i)
    {
        std::cin >> num;
        num = labs(num);
        // 找出奇数位的最小值和偶数位的最大值
        if(i & 1)
        {
            ans -= num;
            max = std::max(max, num);
        }
        else
        {
            ans += num;
            min = std::min(min, num);
        }
    }

    if(max > min)
    {
        ans += ((max - min) << 1);
    }
    std::cout << ans << std::endl;

    return 0;
}