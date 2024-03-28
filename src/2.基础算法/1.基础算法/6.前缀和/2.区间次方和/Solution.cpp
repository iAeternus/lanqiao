/*
https://www.lanqiao.cn/problems/3382/learning/?page=1&first_category_id=1&problem_id=3382
*/
#include <iostream>
#include <vector>
#include <cmath>

using ll = long long;
constexpr ll max = 1e9 + 7;

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<ll>> nums(6, std::vector<ll>(n + 1));
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> nums[1][i];
    }

    for(int i = 2; i <= 5; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            nums[i][j] = (nums[i - 1][j] * nums[1][j]) % max;
        }
    }

    std::vector<std::vector<ll>> prefix(6, std::vector<ll>(n + 1, 0));
    for(int i = 1; i <= 5; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            prefix[i][j] = (prefix[i][j - 1] + nums[i][j]) % max;
        }
    }

    for(int i = 0; i < m; ++i)
    {
        int l, r, k;
        std::cin >> l >> r >> k;
        std::cout << (prefix[k][r] - prefix[k][l - 1] + max) % max << std::endl;
    }

    return 0;
}