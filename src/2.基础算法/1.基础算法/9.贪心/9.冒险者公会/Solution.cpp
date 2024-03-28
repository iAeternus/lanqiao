/**
 * https://www.lanqiao.cn/problems/3611/learning/?page=1&first_category_id=1&name=%E5%86%92%E9%99%A9%E8%80%85%E5%85%AC%E4%BC%9A
 */
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

int solve(int cnt, std::multiset<int> &powers, std::vector<std::priority_queue<int, std::vector<int>, std::less<int>>> &villages)
{
    int m = powers.size();
    int n = villages.size();
    if (m < cnt)
    {
        return -1;
    }

    int ans = 0;
    while (cnt--)
    {
        int hardest = 0; // 最难的任务
        int person;      // 最合适的人选
        // 找到所有任务中最难的
        for (const auto &village : villages)
        {
            if (!village.empty()) // 村庄必须有任务
            {
                hardest = std::max(hardest, village.top());
            }
        }

        // 找能搞定这个任务的人
        auto it = std::lower_bound(powers.begin(), powers.end(), hardest);
        if (it == powers.end()) // 没找到
        {
            return -1;
        }

        // 找到了，把他删除，更新代价
        person = *it;
        powers.erase(it);
        ans += person;
        // 这个人可以完成所有村庄最难的任务
        for (auto &village : villages)
        {
            if (!village.empty())
            {
                village.pop();
            }
        }
    }

    return ans;
}

int main()
{
    int m, n;
    std::cin >> m >> n;
    std::multiset<int> powers;
    for (int i = 0; i < m; ++i)
    {
        int power;
        std::cin >> power;
        powers.insert(power);
    }
    int cnt = 0; // 任务最多的村庄的任务数
    std::vector<std::priority_queue<int, std::vector<int>, std::less<int>>> villages(n);
    for (int i = 0; i < n; ++i)
    {
        int t;
        std::cin >> t;
        cnt = std::max(cnt, t);
        for (int j = 0; j < t; ++j)
        {
            int difficulty;
            std::cin >> difficulty;
            villages[i].push(difficulty);
        }
    }

    std::cout << solve(cnt, powers, villages) << std::endl;

    return 0;
}