/**
 * https://www.lanqiao.cn/problems/4133/learning/?page=1&first_category_id=1&name=%E5%B0%8F%E6%B5%A9%E7%9A%84ABC
 * 
 * 当且仅当 X == 1 时无解
 * 
 * N = 1e6
 * 当 1 <= X <= N
 *      A = X - 1
 *      B = C = 1
 * 当 X > N
 *      A = N
 *      B = X / N
 *      C = X - X / N * N
*/
#include <bits/stdc++.h>

using ll = long long;
const ll N = 1e6;

int main()
{
    int t;
    std::cin >> t;
    ll x, a, b, c;
    for(int i = 0; i < t; ++i)
    {
        std::cin >> x;
        if(x == 1) std::cout << -1 << std::endl;
        else if(x <= N + 1) std::cout << x - 1 << " 1 1" << std::endl;
        else std::cout << N << ' ' << x / N << ' ' << x - x / N * N << std::endl;
    }
    return 0;
}