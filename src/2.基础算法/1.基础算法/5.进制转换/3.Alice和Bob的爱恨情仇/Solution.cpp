/*
https://www.lanqiao.cn/problems/3865/learning/?page=1&first_category_id=1&name=Alice%E5%92%8C
------------------------------------------------------------------------------------------------
如果饼干总和为奇数，Alice 赢；反之 Bob 赢。因为奇数总数就必然存在某一堆个数为奇数，那么 Alice 就能拿走一个小于其数量的最大值
剩下的给 Bob
*/
#include <iostream>

int main()
{
    int n, k;
    std::cin >> n >> k;
    int sum = 0, temp;
    for(int i = 0; i < n; ++i)
    {
        std::cin >> temp;
        sum += temp;
    }

    if(sum & 1)
    {
        std::cout << "Alice\n";
    }
    else
    {
        std::cout << "Bob\n";
    }

    return 0;
}


