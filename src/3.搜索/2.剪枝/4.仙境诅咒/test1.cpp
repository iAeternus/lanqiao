/**
 * https://www.lanqiao.cn/problems/3935/learning/?page=1&first_category_id=1&name=%E4%BB%99%E5%A2%83%E8%AF%85%E5%92%92
*/
/*
sample input
5
0 0
1 1
0 1
1 0
2 2
1
sample output
1
1
1
1
0
*/
#include <bits/stdc++.h>

const int N = 1e3 + 9;
int n;
double d;
int x[N], y[N];
bool vis[N] = {false};

double point_dis_sqr(int x1, int y1, int x2, int y2)
{
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

void dfs(int dep)
{
    vis[dep] = true;
    for(int i = 1; i <= n; ++i)
    {
        if(vis[i]) continue;
        if(point_dis_sqr(x[dep], y[dep], x[i], y[i]) <= d * d)
        {
            dfs(i);
        }
    }
}

int main()
{
    std::cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> x[i] >> y[i];
    }
    std::cin >> d;

    dfs(1);

    for(int i = 1; i <= n; ++i)
    {
        std::cout << vis[i] << std::endl;
    }

    return 0;
}