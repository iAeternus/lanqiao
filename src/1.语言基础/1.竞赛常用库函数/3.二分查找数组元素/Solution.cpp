/*
二分查找数组元素

题目描述
给定一个数组，其采用如下代码定义：
int data[200];
for(i = 0 ; i < 200 ; i ++) data[i] = 4 * i + 6;
先给定某个数（在 data数组中），请你求出它在数组中的位置。

输入描述
输入一个待查找的整数（该整数一定在数组data中）。

输出描述
输出该整数在数组中的指标。

输入输出样例
示例 1
输入
262
输出
64

示例 2
输入
438
输出
108

示例 3
输入
774
输出
192
-------------------------------------------------------------
std::lower_bound(start, end, target)，返回 [start, end) 中第一个大于等于 target 元素的地址
std::upper_bound(start, end, target)，返回 [start, end) 中第一个大于 target 元素的地址

                upper_bound
                    |
eg:1 2 3  8  8 8 8  9  10 13
          |       
     lower_bound
*/
#include <iostream>
#include <algorithm>

int main()
{
    int data[200];
    for (int i = 0; i < 200; i++)
    {
        data[i] = 4 * i + 6;
    }
    int target;
    std::cin >> target;

    std::cout << (std::lower_bound(data, data + 200, target) - data) << std::endl;

    return 0;
}