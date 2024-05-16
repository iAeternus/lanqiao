/**
 * 任何一个大于1的自然数 N,如果N不为质数，那么N可以唯一分解成有限个质数的乘积
*/
#include <bits/stdc++.h>

std::vector<std::pair<int, int>> v;

int main()
{
    int x;
    std::cin >> x;
    int num = x;

    // 枚举所有可能的质因子
    for(int i = 2; i <= num / i; ++i) {
        // 如果不能整除直接跳过
        if(num % i) continue;

        // 如果可以整除，必然是一个质因子
        int cnt = 0; // cnt 表示当前质因子的指数
        // 一直除，直到除干净
        while(num % i == 0) {
            ++cnt;
            num /= i;
        }
        v.push_back({i, cnt});
    }
    if(num > 1) {
        v.push_back({num, 1});
    }

    std::cout << x << " = " << v[0].first << "^" << v[0].second;
    for(int i = 1; i < v.size(); ++i) {
        std::cout << " * " << v[i].first << "^" << v[i].second;
    }
    std::cout << std::endl;

    return 0;
}