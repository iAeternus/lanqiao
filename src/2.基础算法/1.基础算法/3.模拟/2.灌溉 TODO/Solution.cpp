/*
灌溉 
题目描述
小蓝负责花园的灌溉工作。
花园可以看成一个 n行m 列的方格图形。中间有一部分位置上安装有出水管。
小蓝可以控制一个按钮同时打开所有的出水管，打开时，有出水管的位置可以被认为已经灌溉好。
每经过一分钟，水就会向四面扩展一个方格，被扩展到的方格可以被认为已经灌溉好。
即如果前一分钟某一个方格被灌溉好，则下一分钟它上下左右的四个方格也被灌溉好。
给定花园水管的位置，请问 k 分钟后，有多少个方格被灌溉好？

输入描述
输入的第一行包含两个整数n,m。
第二行包含一个整数t，表示出水管的数量。
接下来t行描述出水管的位置，其中第i行包含两个数r,c表示第 r行第c列有一个排水管。
接下来一行包含一个整数k。
其中，1≤n,m≤100,1≤t≤10,1≤k≤100。

输出描述
输出一个整数，表示答案

样例
输入
3 6
2
2 2
3 4
1
输出
9
------------------------------------------
用两个二维数组模拟当前和后一分钟的灌溉情况
*/
#include <iostream>
#include <vector>

enum state
{
    not_irrigated, // 未灌溉
    irrigated, // 已灌溉
    outlet_pipes, // 出水管
};

bool isValid(int n, int m, int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

void update(std::vector<std::vector<int>>& now, std::vector<std::vector<int>>& next)
{
    int n = now.size();
    int m = now[0].size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (now[i][j] == outlet_pipes)
            {
                if (i >= 1) next[i - 1][j] = irrigated;
                if (i < n - 1) next[i + 1][j] = irrigated;
                if (j >= 1) next[i][j - 1] = irrigated;
                if (j < m - 1) next[i][j + 1] = irrigated;
            }
        }
    }
}

void printNow(const std::vector<std::vector<int>>& now)
{
    for (int i = 0; i < now.size(); ++i)
    {
        for (int j = 0; j < now[i].size(); ++j)
        {
            std::cout << now[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int main()
{
    int n, m, t;
    std::cin >> n >> m >> t;

    std::vector<std::vector<int>> now(n, std::vector<int>(m, not_irrigated));
    std::vector<std::vector<int>> next(n, std::vector<int>(m, not_irrigated));
    for (int i = 0; i < t; ++i)
    {
        int row, col;
        std::cin >> row >> col;
        --row, --col;
        now[row][col] = outlet_pipes;
        next[row][col] = outlet_pipes;
    }

    int k;
    std::cin >> k;

    for (int i = 0; i < k; ++i)
    {
        update(now, next);
        now = next;
        //printNow(now);
        //std::cout << "================================================\n";
    }

    int cnt = 0;
    for (int i = 0; i < now.size(); ++i)
    {
        for (int j = 0; j < now[i].size(); ++j)
        {
            if (now[i][j] != not_irrigated)
            {
                ++cnt;
            }
        }
    }

    std::cout << cnt << std::endl;

    return 0;
}
