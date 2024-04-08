/**
 * https://www.lanqiao.cn/problems/3683/learning/?page=1&first_category_id=1&problem_id=3683
*/
#include <iostream>
#include <algorithm>

using ll = long long;
const int N = 1e5 + 9;

int m, n;
ll nums[N];

// 最大的最近间隔为mid时能种多少棵树
int check(int mid)
{
    int cnt = 0, prev = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(prev && nums[i] - nums[prev] < mid)
        {
            continue;
        }
        prev = i;
        ++cnt;
    }
    return cnt;
}

int main()
{
    std::cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> nums[i];
    }

    std::sort(nums + 1, nums + n + 1);

    ll left = 0, right = 1e9 + 5;
    while(left + 1 != right)
    {
        ll mid = left - ((left - right) >> 1);
        if(check(mid) >= m)
        {
            // mid 偏小
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