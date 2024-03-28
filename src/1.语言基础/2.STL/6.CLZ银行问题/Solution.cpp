/*
CLZ银行问题
题目描述
CLZ 银行只有两个接待窗口，VIP 窗口和普通窗口，VIP 用户进入 VIP 窗口排队，剩下的进入普通窗口排队。
现有 MM 次操作，操作有四种类型，如下：

IN name V：表示一名叫 name 的用户到 VIP 窗口排队
OUT V：表示 VIP 窗口队头的用户离开排队
IN name N：表示一名叫 name 的用户到普通窗口排队
OUT N：表示普通窗口队头的用户离开排队
求 MM 次操作结束后 VIP 窗口队列和普通窗口队列中的姓名。

输入描述
第一行是一个整数 M（1≤M≤1000），表示一共有 M 次操作。
第二行到第 M+1 行输入操作，格式如下：

IN name V
OUT V
IN name N
OUT N

输出描述
输出 M 次操作后 VIP 窗口队列和普通窗口队列中的姓名（从头到尾），先输出 VIP 窗口队列后输出普通窗口队列。

输入输出样例
示例 1
输入
5
IN xiaoming N
IN Adel V
IN laozhao N
OUT N
IN CLZ V
输出
Adel
CLZ
laozhao
运行限制
最大运行时间：1s
最大运行内存: 128M
*/
#include <iostream>
#include <queue>
#include <string>

int main()
{
    int m;
    std::cin >> m;

    std::string op, name, state;
    std::queue<std::string> vip, normal;
    for (int i = 0; i < m; ++i)
    {
        std::cin >> op;

        if (op == "IN")
        {
            std::cin >> name >> state;
            if (state == "V")
            {
                vip.push(name);
            }
            else // N
            {
                normal.push(name);
            }
        }
        else // OUT
        {
            std::cin >> state;
            if (state == "V")
            {
                vip.pop();
            }
            else // N
            {
                normal.pop();
            }
        }
    }

    while (!vip.empty())
    {
        std::cout << vip.front() << std::endl;
        vip.pop();
    }

    while (!normal.empty())
    {
        std::cout << normal.front() << std::endl;
        normal.pop();
    }

    return 0;
}