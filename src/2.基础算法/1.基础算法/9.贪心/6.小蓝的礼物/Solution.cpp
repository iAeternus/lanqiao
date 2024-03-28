/**
 * https://www.lanqiao.cn/problems/3792/learning/?page=1&first_category_id=1&name=%E5%B0%8F%E8%93%9D%E7%9A%84%E7%A4%BC%E7%89%A9
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using ll = long long;

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<ll> nums(n);
    for(int i = 0; i < n; ++i)
    {
        std::cin >> nums[i];
    }
    
    std::sort(nums.begin(), nums.end());
    
    int cnt = 0;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] <= k)
        {
            k -= nums[i];
            ++cnt;
        }
        else if(nums[i] > k && ceil(nums[i] / 2) < k)
        {
            k -= ceil(nums[i] / 2);
            ++cnt;
        }
        else
        {
            break;
        }
    }

    std::cout << cnt << std::endl;

    return 0;
}