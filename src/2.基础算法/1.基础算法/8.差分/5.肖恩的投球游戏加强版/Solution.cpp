/*
https://www.lanqiao.cn/problems/3694/learning/?page=1&first_category_id=1&name=%E8%82%96%E6%81%A9%E7%9A%84%E6%8A%95%E7%90%83%E6%B8%B8%E6%88%8F%E5%8A%A0%E5%BC%BA%E7%89%88
*/
#include <iostream>
#include <vector>

using ll = long long;

int main()
{
    int n, m, q;
    std::cin >> n >> m >> q;
    
    std::vector<std::vector<ll>> nums(n, std::vector<ll>(m));
    for(int i = 0; i < nums.size(); ++i)
    {
        for(int j = 0; j < nums[i].size(); ++j)
        {
            std::cin >> nums[i][j];
        }
    }

    std::vector<std::vector<ll>> diff(n, std::vector<ll>(m, 0));
    for(int i = 0; i < q; ++i)
    {
        int x1, y1, x2, y2;
        ll c;
        std::cin >> x1 >> y1 >> x2 >> y2 >> c;
        --x1; --x2; --y1; --y2;

        for(int j = x1; j <= x2; ++j)
        {
            diff[j][y1] += c;
            if(y2 + 1 < m)
            {
                diff[j][y2 + 1] -= c;
            }
        }
    }

    for(int i = 0; i < nums.size(); ++i)
    {
        std::cout << nums[i][0] + diff[i][0];
        for(int j = 1; j < nums[i].size(); ++j)
        {
            diff[i][j] += diff[i][j - 1]; // 差分求前缀和
            std::cout << ' ' << nums[i][j] + diff[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}