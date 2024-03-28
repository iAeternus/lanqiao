/*
反转字符串中的字符

题目描述
实现一个算法来实现反转字符数组的功能。反转的要求如下：
1．将字符数组的字符进行反转，例如［' b ','',' a ',']变成[' r ',' a ','',' b '].
2．将字符数组替换为反转后的数组。
输入描述
读入一行字符串，长度不超过100，字符串可能含有空格。
输出描述
输出一行字符串，该字符串为读入字符串的反转字符串。

输入输出样例
示例
输入
b ar
输出
ra b
*/
#include <iostream>
#include <string>

void solve(std::string& str)
{
    int n = str.size() >> 1;
    for(int i = 0; i < n; ++i)
    {
        std::swap(str[i], str[str.size() - i - 1]);
    }
}

int main()
{
    std::string str;

    std::getline(std::cin, str);
    solve(str);
    std::cout << str << std::endl;

    return 0;
}