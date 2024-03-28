/**
 * https://www.lanqiao.cn/problems/1331/learning/?page=1&first_category_id=1&problem_id=1331
*/
#include <bits/stdc++.h>

int main()
{
    unsigned num;
    std::cin >> num;
    int cnt = 0;
    while(num)
    {
        if(num & 1) ++cnt;
        num >>= 1;
    }
    std::cout << cnt << std::endl;
    return 0;
}