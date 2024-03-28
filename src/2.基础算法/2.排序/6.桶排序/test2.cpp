/**
 * https://www.lanqiao.cn/problems/1314/learning/?page=1&first_category_id=1&problem_id=1314
 */
#include <bits/stdc++.h>

const int N = 5e5 + 7;

int main()
{
    int n;
    std::cin >> n;
    int buckets[N] = {0};
    for (int i = 0; i < n; ++i)
    {
        int num;
        std::cin >> num;
        ++buckets[num];
    }

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j < buckets[i]; ++j)
        {
            std::cout << i << ' ';
        }
    }
    std::cout << std::endl;

    return 0;
}