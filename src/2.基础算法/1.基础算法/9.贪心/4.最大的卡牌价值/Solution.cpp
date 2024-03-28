/**
 * https://www.lanqiao.cn/problems/3250/learning/?page=1&first_category_id=1&name=%E6%9C%80%E5%A4%A7%E7%9A%84%E5%8D%A1%E7%89%8C%E4%BB%B7%E5%80%BC
 * 错两个点
*/
#include <iostream>
#include <vector>
#include <queue>

using ll = long long;

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::priority_queue<ll, std::vector<ll>> q;
    std::vector<ll> front(n);
    std::vector<ll> back(n);
    ll ans = 0;
    // 累加正面
    for(int i = 0; i < n; ++i)
    {
        std::cin >> front[i];
        ans += front[i];
    }
    for(int i = 0; i < n; ++i)
    {
        std::cin >> back[i];
        // 计算每次翻牌的收益
        q.push(back[i] - front[i]);
    }

    // 翻牌k次收益最大化
    for(int i = 0; i < k; k++)
    {
        if(q.top() > 0)
        {
            ans += q.top();
            q.pop();
        }
        else
        {
            break;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}