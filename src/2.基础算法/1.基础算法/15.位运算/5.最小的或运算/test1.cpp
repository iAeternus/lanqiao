/**
 * https://www.lanqiao.cn/problems/4900/learning/?page=1&first_category_id=1&name=%E6%9C%80%E5%B0%8F%E7%9A%84%E6%88%96%E8%BF%90%E7%AE%97
 * 
 * 100 | x == 101 | x
 * 
 * 100
 * 101
 * ----
 * 001
*/
#include <bits/stdc++.h>

using ll = long long;

int main()
{
    ll a, b;
    std::cin >> a >> b;
    std::cout << (a ^ b) << std::endl;
    return 0;
}