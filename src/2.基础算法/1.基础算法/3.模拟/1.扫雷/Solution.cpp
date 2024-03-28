/*
扫雷
题目描述
在一个n行m 列的方格图上有一些位置有地雷，另外一些位置为空。
请为每个空位置标一个整数，表示周围八个相邻的方格中有多少个地雷。

输入描述
输入的第一行包含两个整数n,m。
第2行到第n+1行每行包含m个整数，相邻整数之间用一个空格分隔。如果对应的整数为0，表示这一格没有地雷。
如果对应的整数为1，表示这一格有地雷。
其中，1≤n,m≤ 100分钟后还是在当天。

输出描述
输出n行，每行m个整数，相邻整数之间用空格分隔。
对于没有地雷的方格，输出这格周围的地雷数量。对于有地雷的方格，输出9。

输入输出样例
示例输入
3 4
0 1 0 0
1 0 1 0
0 0 1 0
示例输出
2 9 2 1
9 4 9 2
1 3 9 2
*/
#include <iostream>
#include <vector>

bool isValid(int n, int m, int a, int b)
{
    return a >= 0 && a < n && b >= 0 && b < m;
}

int getCnt(const std::vector<std::vector<int>> &board, int i, int j)
{
    if (board[i][j] == 1)
        return 9;

    int cnt = 0;
    for (int a = i - 1; a <= i + 1; ++a)
    {
        for (int b = j - 1; b <= j + 1; ++b)
        {
            if (isValid(board.size(), board[0].size(), a, b))
            {
                if (board[a][b] == 1)
                {
                    ++cnt;
                }
            }
        }
    }
    return cnt;
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> board(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> board[i][j];
        }
    }

    std::vector<std::vector<int>> result(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            result[i][j] = getCnt(board, i, j);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << result[i][0];
        for (int j = 1; j < m; ++j)
        {
            std::cout << ' ' << result[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}