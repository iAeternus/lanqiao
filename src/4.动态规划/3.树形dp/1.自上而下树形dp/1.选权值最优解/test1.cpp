/**
 * 给定有根树，每个节点有权值 ai，要选择一些点使得权值最大，且一个点被选中时，其所有儿子均不能选，问最大值
 * 
 * dp[i][0]: 不选当前点最大值为 dp[i][0]
 * dp[i][1]: 选择当前点最大值为 dp[i][1]
 * 
 * dp[i][0] = sum_son(max(dp[v][0], dp[v][1]))
 * dp[i][1] = sum_son(dp[v][0])
 * 
 * get max(dp[1][0], dp[1][1])
*/
#include <bits/stdc++.h>

const int MAX_N = 110000;
int n, weight[MAX_N];

struct Edge {
    int next, to;
} edges[MAX_N << 1];

int head[MAX_N], cnt;
int dp[MAX_N][2];

void add(int from, int to)
{
    edges[cnt].to = to;
    edges[cnt].next = head[from];
    head[from] = cnt++;
}

void dfs(int u, int fa)
{
    for(int i = head[u]; i; i = edges[i].next)
    {
        int v = edges[i].to;
        if(v == fa) continue;
        // 代表 v 这个儿子的状态已经被处理好了
        dfs(v, u);
        // 代表 u 这个节点不选，那 v 可选可不选
        dp[u][0] += std::max(dp[v][0], dp[v][1]);
        // 代表 u 这个节点选了，那 v 不能选
        dp[u][1] += dp[v][0];
    }
}

int main()
{
    std::cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> weight[i];
        dp[i][1] = weight[i];
    }

    for(int i = 1; i <= n; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        add(u, v);
        add(v, u);
    }

    dfs(1, 0);

    std::cout << std::max(dp[1][0], dp[1][1]) << std::endl;

    return 0;
}