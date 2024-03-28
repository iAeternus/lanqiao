/**
 * https://www.lanqiao.cn/problems/178/learning/?page=1&first_category_id=1&problem_id=178
 *
 * dfs 给不同的岛屿染上不同的颜色，淹没后 总颜色数 - 剩下的颜色数 即为结果
 */
/*
sample input
7
.......
.##....
.##....
....##.
..####.
...###.
.......
sample output
1
*/
#include <bits/stdc++.h>

const int N = 1e3 + 5;

int n;
char mp[N][N];
// col 颜色数组
// scc 当前颜色编号
int col[N][N], scc;
// vis 有哪些颜色剩下来了
bool vis[N * N];

// 偏移方向
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// 为岛屿染上颜色
void dfs(int i, int j)
{
    col[i][j] = scc;
    for(int k = 0; k < 4; ++k)
    {
        int x = i + dx[k], y = j + dy[k];
        if(col[x][y] || mp[x][y] == '.') continue;
        dfs(x, y);
    }
}

int main()
{
    std::cin >> n;
    for(int i = 1; i <= n; ++i) std::cin >> mp[i] + 1; // 输入字符数组

    // 为所有岛屿染上颜色
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (col[i][j] || mp[i][j] == '.') continue;
            ++scc;
            dfs(i, j);
        }
    }

    int ans = 0; // 淹没的岛屿个数
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if(mp[i][j] == '.') continue;

            // 当该点四个方向都不是海，该点一定会剩下来
            bool tag = true;
            for(int k = 0; tag && k < 4; ++k)
            {
                int x = i + dx[k], y = j + dy[k];
                if(mp[x][y] == '.') tag = false;
            }
            // 如果当前陆地会被保留下来
            if(tag)
            {
                // 如果当前颜色没出现过，计入答案
                if(!vis[col[i][j]]) ++ans;
                // 标记已遍历过的颜色
                vis[col[i][j]] = true;
            }
        }
    }

    std::cout << scc - ans << std::endl; // 剩余的岛屿个数

    return 0;
}