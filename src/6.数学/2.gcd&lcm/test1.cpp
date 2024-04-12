/**
 * https://www.lanqiao.cn/problems/1260/learning/?page=1&first_category_id=1&problem_id=1260
*/
/*
sample input
5
2 4
3 7
5 10
6 8
7 9
sample output
2
1
5
2
1
*/
#include <bits/stdc++.h>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main()
{
    int t;
    std::cin >> t;
    for(int i = 1; i <= t; ++i) {
        int a, b;
        std::cin >> a >> b;
        std::cout << gcd(a, b) << std::endl;
    }
    return 0;
}