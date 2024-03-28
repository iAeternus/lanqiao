/**
 * https://www.lanqiao.cn/problems/1508/learning/?page=1&first_category_id=1&problem_id=1508
*/
/*
sample input
5
sample output
10

sample input
8
sample output
92
*/
#include <bits/stdc++.h>

const int N = 15;
int n, ans;
int vis[N][N]; // 存储棋盘上的位置被几个皇后占用

void dfs(int dep)
{
    if(dep == n + 1)
    {
        ++ans;
        return;
    }

    for(int i = 1; i <= n; ++i)
    {
        // 剪枝，该位置不能有皇后
        if(vis[dep][i]) continue;

        // 修改状态
        for(int _i = 1; _i <= n; ++_i) vis[_i][i]++; // 列
        for(int _i = dep, _j = i; _i >= 1 && _j >= 1; --_i, --_j) vis[_i][_j]++;
        for(int _i = dep, _j = i; _i <= n && _j >= 1; ++_i, --_j) vis[_i][_j]++;
        for(int _i = dep, _j = i; _i >= 1 && _j <= n; --_i, ++_j) vis[_i][_j]++;
        for(int _i = dep, _j = i; _i <= n && _j <= n; ++_i, ++_j) vis[_i][_j]++;

        // 递归
        dfs(dep + 1);

        // 回溯
        for(int _i = 1; _i <= n; ++_i) vis[_i][i]--; // 列
        for(int _i = dep, _j = i; _i >= 1 && _j >= 1; --_i, --_j) vis[_i][_j]--;
        for(int _i = dep, _j = i; _i <= n && _j >= 1; ++_i, --_j) vis[_i][_j]--;
        for(int _i = dep, _j = i; _i >= 1 && _j <= n; --_i, ++_j) vis[_i][_j]--;
        for(int _i = dep, _j = i; _i <= n && _j <= n; ++_i, ++_j) vis[_i][_j]--;
    }
}

int main()
{
    std::cin >> n;
    dfs(1);
    std::cout << ans << std::endl;
    return 0;
}