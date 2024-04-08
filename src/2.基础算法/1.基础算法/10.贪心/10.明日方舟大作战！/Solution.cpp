/**
 * https://www.lanqiao.cn/problems/4049/learning/?page=1&first_category_id=1&name=%E6%98%8E%E6%97%A5%E6%96%B9%E8%88%9F%E5%A4%A7%E4%BD%9C%E6%88%98%EF%BC%81
 *
 * dp[j]: 预算为j时能打出的最大攻击力
 *
 * dp
 *      dp[j] = max(dp[j], dp[j - cost[i]] + attack[i])
 *
 * base case
 *      dp[0] = 0
 *
 * result
 *      dp[B]
 */
#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    int n, m, B;
    std::cin >> n >> m >> B;
    std::vector<int> attacks(n), costs(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> attacks[i] >> costs[i];
    }
    int max_enemy = -1; // 最厚的血量
    for(int i = 0; i < m; ++i)
    {
        int t;
        std::cin >> t;
        max_enemy = std::max(max_enemy, t);
    }

    // dp
    std::vector<int> dp(B + 1, 0);
    for(int i = 0; i < n; ++i) // 遍历干员
    {
        for(int j = B; j >= costs[i]; --j) // 遍历费用
        {
            dp[j] = std::max(dp[j], dp[j - costs[i]] + attacks[i]);
        }
    }

    int max_attack = dp[B];
    if(max_attack == 0) // 预算不够
    {
        std::cout << "-1\n";
    }
    else
    {
        // 轮数 = ceil(最大血量 / 最大伤害)
        std::cout << (int)ceil((double)max_enemy / max_attack) << std::endl;
    }
    

    return 0;
}