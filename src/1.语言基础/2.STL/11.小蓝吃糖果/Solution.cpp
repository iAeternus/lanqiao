/*
小蓝吃糖果
题目描述
小蓝有 n 种糖果，每种数量已知。
小蓝不喜欢连续 2 次吃同样的糖果。问有没有可行的吃糖方案。

输入描述
第一行是整数 n(0<n<1000000)。
第二行包含 n 个数，表示 n 种糖果的数量

输出描述
输出一行，包含一个 Yes 或 no。

输入输出样例
示例
输入
3
4 1 1
输出
No

运行限制

最大运行时间：1s
最大运行内存: 256M
------------------------------------
每次取最多的两个，相减放入优先队列中，直到出现 0
*/
#include <iostream>
#include <queue>

int main()
{
    int n;
    std::cin >> n;

    int cnt;
    std::priority_queue<int> queue;
    for(int i = 0; i < n; ++i)
    {
        std::cin >> cnt;
        queue.push(cnt);
    }

    while(queue.size() > 1)
    {
        int a = queue.top(); queue.pop();
        int b = queue.top(); queue.pop();

        queue.push(a - b);
    }
    std::cout << (queue.top() <= 1 ? "Yes" : "No") << std::endl;
    return 0;
}