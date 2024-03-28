/*
i 迭代 n 次，j 迭代 n / i 次
    
*/
#include <iostream>

using ll = long long;

int main()
{
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);

    int n;
    std::cin >> n;

    for(int i = 1; i <= n; ++i)
    {
        for(int j = i; j <= n; j += i)
        {
            std::cout << "Hello\n";
        }
    }

    return 0;
}