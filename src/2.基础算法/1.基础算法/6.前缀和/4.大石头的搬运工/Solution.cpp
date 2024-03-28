/*
https://www.lanqiao.cn/problems/3829/learning/?page=1&first_category_id=1&name=%E5%A4%A7%E7%9F%B3%E5%A4%B4%E7%9A%84%E6%90%AC%E8%BF%90%E5%B7%A5
前缀和和后缀和之和的最小值
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

struct stone
{
    int w;
    int p;
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<stone> stones(n + 1);
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> stones[i].w >> stones[i].p;
    }

    // 按照位置升序排序
    std::sort(stones.begin(), stones.end(), [](const stone& a, const stone& b)->bool {
        return a.p < b.p;
    });

    int weight = 0;
    std::vector<long long> prefix(n + 1, 0);
    for(int i = 2; i <= n; ++i)
    {
        weight += stones[i - 1].w;
        prefix[i] = prefix[i - 1] + weight * (stones[i].p - stones[i - 1].p); 
    }

    weight = 0;
    std::vector<long long> suffix(n + 1, 0);
    for(int i = n - 1; i >= 1; --i)
    {
        weight += stones[i + 1].w;
        suffix[i] = suffix[i + 1] + weight * (stones[i + 1].p - stones[i].p);
    }

    long long result = std::numeric_limits<long long>::max();
    for(int i = 1; i <= n; ++i)
    {
        result = std::min(result, prefix[i] + suffix[i]);
    }

    std::cout << result << std::endl;

    return 0;
}