#include <bits/stdc++.h>

const int N = 1e5 + 7;
int n, m;
std::string mp[N];
int cnt_i, cnt_t;
bool tag = false;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m || mp[x][y] == '0') return;
    if(mp[x][y] >= '2' && mp[x][y] <= '9') tag = true;
    mp[x][y] = '0';
    for(int i = 0; i < 4; ++i)
    {
        dfs(x + dx[i], y + dy[i]);
    }
}

int main()
{
    std::cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        std::cin >> mp[i];
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(mp[i][j] > '0')
            {
                ++cnt_i;
                tag = false;
                dfs(i, j);
                if(tag) ++cnt_t;
            }
        }
    }

    std::cout << cnt_i << ' ' << cnt_t << std::endl;

    return 0;
}