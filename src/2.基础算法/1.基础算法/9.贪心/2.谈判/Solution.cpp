/**
 * https://www.lanqiao.cn/problems/545/learning/?page=1&first_category_id=1&problem_id=545
*/
#include <iostream>
#include <queue>

using ll = long long;

int main()
{
    int n;
    std::cin >> n;
    std::priority_queue<ll, std::vector<ll>, std::greater<ll>> q;
    ll num;
    for(int i = 0; i < n; ++i)
    {
        std::cin >> num;
        q.push(num);
    }

    ll result = 0;
    while(q.size() > 1)
    {
        ll a = q.top(); q.pop();
        ll b = q.top(); q.pop();
        result += a + b; // 累加开销
        q.push(a + b);
    }

    std::cout << result << std::endl;

    return 0;
}