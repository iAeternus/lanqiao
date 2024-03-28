/*
给定一个正整数n(n>0)。找到任何一个满足以下条件的整数 s，或者报告没有这样的数字：
在s的十进制表示中：
    s >0
    s 由 n位数字组成
    s 中没有任何数字等于 0
    s 不能被它的任何一个数字整除

输入包含多个测试用例。
输入的第一行包含一个整数 t(1≤t≤400)，表示测试用例的数量。
接下来的 t 行描述了每个测试用例。
每个测试用例包含一个正整数n(1≤n≤10^5)。
保证所有测试用例中 n的总和不超过 10^5。
----------------------------------------------------------
构造法求特解
    1.令 S 的末位为 3
    2.令 S 的高位全为 2
    3.若 S 的高 n - 1 位位数(n - 1)是 3 的倍数，就将 S 的最高位换成一个质数(5/7)
*/
#include <iostream>
#include <cmath>

int func(int n)
{
    int s = 3, carry = 20;
    for(int i = 0; i < n - 1; ++i)
    {
        s += carry;
        carry *= 10;
    }

    if((n - 1) % 3 == 0)
    {
        s += 3 * pow(10, n - 1);   
    }

    return s;
}

bool check(int s, int n)
{
    if(s < 0) return false;
    
    int cnt = 0;
    bool tag = false;
    int copy = s;
    while(!tag && s)
    {
        int item = s % 10;
        tag = !item || !(copy % item);
        s /= 10;
        ++cnt;
    }
    if(cnt != n || tag) return false;

    return true;
}

int main()
{
    int t;
    std::cin >> t;
    int n;
    for(int i = 0; i < t; ++i)
    {
        std::cin >> n;
        int s = func(n);
        std::cout << s << "\tcheck: " << (check(s, n) ? "true" : "false") << std::endl;
    }
    return 0;
}