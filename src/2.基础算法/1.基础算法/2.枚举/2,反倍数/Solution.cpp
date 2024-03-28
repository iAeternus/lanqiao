/*
【问题描述】
给定三个整数 a, b, c ，如果一个整数既不是 a 的整数倍也不是 b 的整数倍还不是 c 的整数倍，则这个数称为反倍数。
请问在1 至 n 中有多少个反倍数。

【输入格式】
输入的第一行包含一个整数 n。
第二行包含三个整数 a, b, c，相邻两个数之间用一个空格分隔。

【样例输出】
输出一行包含一个整数，表示答案。

【样例输入】
30
2 3 6

【样例输出】
10

【样例说明】
以下这些数满足要求：1, 5, 7, 11, 13, 17, 19, 23, 25,

【评测用例规模与约定】
对于40% 的评测用例，1 ≤ n ≤ 10000。
对于 80% 的评测用例，1 ≤ n ≤ 10^5。
对于所有评测用例，1 ≤ n ≤ 10^6，1 ≤ a ≤ n，1 ≤ b ≤ n，1 ≤ c ≤ n
*/
#include <iostream>

bool judge(int num, int a, int b, int c)
{
    return num % a && num % b && num % c;
}

int main()
{
    int n, a, b, c;
    std::cin >> n >> a >> b >> c;

    int cnt = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(judge(i, a, b, c))
        {
            ++cnt;
        }
    }

    std::cout << cnt << std::endl;

    return 0;
}