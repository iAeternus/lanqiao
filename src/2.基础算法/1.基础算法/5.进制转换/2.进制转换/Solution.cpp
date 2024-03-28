/*
https://www.lanqiao.cn/problems/1230/learning/?page=1&first_category_id=1&problem_id=1230
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

long long kthToTen(const std::string& num, int k)
{
    long long result = 0;
    for(char n : num)
    {
        if(n >= '0' && n <= '9')
        {
            result = result * k + (n - '0');
        }
        else
        {
            result = result * k + (n - 'A' + 10);
        }
    }
    return result;
}

std::string tenToKth(long long num, int k)
{
    std::string result;
    while(num)
    {
        int remainder = num % k;
        result += remainder < 10 ? remainder + '0' : remainder + 'A' - 10;
        num /= k;
    }

    std::reverse(result.begin(), result.end());

    return result;
}

std::string nthToMth(int n, int m, const std::string& num)
{
    return tenToKth(kthToTen(num, n), m);
}

int main()
{
    int t;
    std::cin >> t;
    for(int i = 0; i < t; ++i)
    {
        int n, m;
        std::cin >> n >> m;
        std::string num;
        std::cin >> num;
        std::cout << nthToMth(n, m, num) << std::endl;
    }
    return 0;
}