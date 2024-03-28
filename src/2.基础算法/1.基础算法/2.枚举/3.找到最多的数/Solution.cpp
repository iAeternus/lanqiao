/*
找到最多的数 

问题描述
在一个nxm的矩阵中，有一个数字出现了超过一半的次数，请设计一个高效算法找到这个数字。

输入格式
输入第一行包含两个整数n和m，表示矩阵的大小（1≤n,m ≤ 10^3).
接下来 n行，每行包含 m个正整数，表示矩阵中的元素。

输出格式
输出一个整数，表示矩阵中出现次数超过一半的数字。

样例输入
3 3
1 2 3
2 2 2
1 2 2

样例输出
2

资源限制
时间限制：1.0s 内存限制：512.0MB
*/
#include <iostream>
#include <map>

int main()
{
    int n, m;
    std::cin >> n >> m;
    
    int temp;
    int size = n * m;
    std::map<int, int> map; // 键-数字 值-数字出现的次数
    for(int i = 0; i < size; ++i)
    {
        std::cin >> temp;
        ++map[temp];
    }

    for(const auto& [x, y] : map)
    {
        if(y > size / 2)
        {
            std::cout << x << std::endl;
            break;
        }
    }

    return 0;
}