/*
回文日期
题目描述
2020 年春节期间，有一个特殊的日期引起了大家的注意：2020 年 2 月 2 日。
因为如果将这个日期按 “yyyymmdd” 的格式写成一个 8 位数是 20200202，恰好是一个回文数。
我们称这样的日期是回文日期。

有人表示 20200202 是 “千年一遇” 的特殊日子。
对此小明很不认同，因为不到 2 年之后就是下一个回文日期：20211202 即 2021 年 12 月 2 日。

也有人表示 20200202 并不仅仅是一个回文日期，还是一个 ABABBABA 型的回文日期。
对此小明也不认同，因为大约 100 年后就能遇到下一个 ABABBABA 型的回文日期：21211212 即 2121 年 12 月 12 日。
算不上 “千年一遇”，顶多算 “千年两遇”。

给定一个 8 位数的日期，请你计算该日期之后下一个回文日期和下一个 ABABBABA 型的回文日期各是哪一天。

输入描述
输入包含一个八位整数 N，表示日期。

对于所有评测用例，10000101≤N≤89991231，保证 N 是一个合法日期的 8 位数表示。

输出描述
输出两行，每行 1 个八位数。第一行表示下一个回文日期，第二行表示下一个 ABABBABA 型的回文日期。

输入输出样例
示例
输入
20200202

输出
20211202
21211212

运行限制
最大运行时间：1s
最大运行内存: 256M
*/
#include <iostream>
#include <string>
#include <algorithm>

bool isLeapYear(int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0; 
}

int strToInt(const std::string& str)
{
    int result = 0;
    int carry = 1;
    for(int i = str.size() - 1; i >= 0; --i)
    {
        result += (str[i] - '0') * carry;
        carry *= 10;
    }
    return result;
}

std::string toString(int num)
{
    std::string str;
    while(num > 0)
    {
        str += num % 10 + '0';
        num /= 10;
    }
    while(str.length() < 8) str += '0';
    std::reverse(str.begin(), str.end());
    return str;
}

bool isValidDate(const std::string& str)
{
    const int dates[2][12] = {
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    };

    int year = strToInt(str.substr(3));
    int month = strToInt(str.substr(4, 2));
    int day = strToInt(str.substr(6, 2));

    return month > 0 && month <= 12 && day > 0 && day <= dates[isLeapYear(year)][month];
}

bool isCircal(const std::string& str)
{
    std::string temp = str;
    std::reverse(temp.begin(), temp.end());
    return str == temp;
}

bool isABABBABA(const std::string& str)
{
    return isCircal(str) && str[0] == str[2] && str[1] == str[3];
}

int main()
{
    int num;
    std::cin >> num;

    bool tag1 = false, tag2 = false;

    while(!tag1 || !tag2)
    {
        ++num;
        std::string str = toString(num);
        if(isValidDate(str))
        {
            if(!tag1 && isCircal(str))
            {
                std::cout << str << std::endl;
                tag1 = true;
            }

            if(!tag2 && isABABBABA(str))
            {
                std::cout << str << std::endl;
                tag2 = true;
            }
        }
    }

    return 0;
}