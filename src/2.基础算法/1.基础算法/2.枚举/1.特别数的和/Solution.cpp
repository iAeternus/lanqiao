/*
蓝桥杯2019 C/C++B组
特别数的和
【题目描述】

小明对数位中含有 2、0、1、9 的数字很感兴趣（不包括前导 0），在 1 到 40 中这样的数包括 1、2、9、10 至 32、39 和40，共 28 个，
他们的和是 574。 请问，在 1 到 n 中，所有这样的数的和是多少？

【输入格式】
输入一行包含整数 n（1≤n≤1e4 ）

【输出描述】
输出一行，包含一个整数，表示满足条件的数的和。

示例
输入
40
输出
574
*/
#include <iostream>
#include <vector>

bool isSpecial(int num)
{
    std::vector<int> bytes;

    while(num > 0)
    {
        bytes.push_back(num % 10);
        num /= 10;
    }

    for(const auto& byte : bytes)
    {
        if(byte == 2 || byte == 0 || byte == 1 || byte == 9)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    std::cin >> n;

    int sum = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(isSpecial(i))
        {
            sum += i;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}