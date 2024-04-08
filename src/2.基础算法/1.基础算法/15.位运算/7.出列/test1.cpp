/**
 * https://www.lanqiao.cn/problems/3223/learning/?page=1&first_category_id=1&name=%E5%87%BA%E5%88%97
 * 
 * 寻找小于 n 的最大的 2 的幂
*/
/*
sample input
7
sample output
4
*/
#include <bits/stdc++.h>

int main()
{
    int n;
    std::cin >> n;

    int cnt = 0;
    while(n != 1)
    {
        n >>= 1;
        ++cnt;
    }

    std::cout << (int)pow(2, cnt) << std::endl;

    return 0;
}