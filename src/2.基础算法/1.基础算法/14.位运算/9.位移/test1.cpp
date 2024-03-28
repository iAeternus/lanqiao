/**
 * https://www.lanqiao.cn/problems/3261/learning/?page=1&first_category_id=1&name=%E4%BD%8D%E7%A7%BB
*/
/*
sample input
5
1 20
7 7
3 5
30 254
114 514
sample output
No
Yes
No
No
No
*/
#include <bits/stdc++.h>

int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        int a, b;
        std::cin >> a >> b;
        int max, min;
        max = std::max(a, b);
        min = std::min(a, b);

        while(max > min)
        {
            max >>= 1;
            if(max == min)
            {
                std::cout << "Yes\n";
                continue;
            }
        }
        std::cout << "No\n";
    }
    return 0;
}