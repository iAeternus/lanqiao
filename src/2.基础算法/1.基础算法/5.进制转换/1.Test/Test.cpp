#include <iostream>
#include <string>
#include <algorithm>

#define TEST_1

// 任意进制转换成10进制
long long kthToTen(const std::string &number, int k)
{
    long long res = 0;
    for (char num : number)
    {
        if (num >= '0' && num <= '9')
        {
            res = res * k + (num - '0');
        }
        else if (num >= 'A' && num <= 'Z')
        {
            res = res * k + (num - 'A' + 10);
        }
        else if (num >= 'a' && num <= 'z')
        {
            res = res * k + (num - 'a' + 10);
        }
        else
        {
            throw std::runtime_error("Illegal figures!");
        }
    }
    return res;
}

// 10进制转换为任意进制
std::string tenToKth(long long number, int k, bool isupper = true)
{
    std::string result;
    while (number)
    {
        int remainder = number % k;
        result += remainder < 10 ? (remainder + '0') : (isupper ? 'A' + remainder - 10 : 'a' + remainder - 10);
        number /= k;
    }
    std::reverse(result.begin(), result.end());

    return result.empty() ? "0" : result;
}

void test1()
{
    try
    {
        int k;
        std::cin >> k;
        std::string num;
        std::cin >> num;
        std::cout << kthToTen(num, k) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void test2()
{
    long long num;
    std::cin >> num;

    std::cout << "2\t" << tenToKth(num, 2) << std::endl;
    std::cout << "2\t" << tenToKth(num, 2, false) << std::endl;
    std::cout << "8\t" << tenToKth(num, 8) << std::endl;
    std::cout << "8\t" << tenToKth(num, 8, false) << std::endl;
    std::cout << "16\t" << tenToKth(num, 16) << std::endl;
    std::cout << "16\t" << tenToKth(num, 16, false) << std::endl;
}

int main()
{
#ifdef TEST_1
    test1();
#elif defined(TEST_2)
    test2();
#endif
    return 0;
}
