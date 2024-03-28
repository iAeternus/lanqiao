/**
 * https://www.lanqiao.cn/problems/4234/learning/?page=1&first_category_id=1&name=%E5%B0%8F%E6%80%82%E7%88%B1%E6%B0%B4%E6%B4%BC
 * 
 * dfs 找大水洼即可，遍历地图以更改起始点找到最大值
*/
/*
sample input
3 3
1 2 0
3 4 0
0 0 5
sample output
10
*/
#include <bits/stdc++.h>

using ll = long long;
const int N = 105;
int n, m;
int mp[N][N], vis[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
ll tmp, ans;

void dfs(int x, int y)
{
    if(x < 1 || x > n || y < 1 || y > m) return;
    if(!mp[x][y] || vis[x][y]) return;
    vis[x][y] = 1;
    tmp += mp[x][y];
    for(int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        dfs(nx, ny);
    }
}

int main()
{
    std::cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            std::cin >> mp[i][j];
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(!mp[i][j] || vis[i][j]) continue;

            tmp = 0;
            dfs(i, j);

            ans = std::max(ans, tmp);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
