/**
 * https://www.lanqiao.cn/problems/8617/learning/?page=1&first_category_id=1&name=LCA
 * https://www.lanqiao.cn/problems/4385/learning/?page=1&first_category_id=1&name=LCA
 * 
 * n 个点，q次询问，询问 a、b 两节点的最近公共祖先
 * 以下给出图的邻接表的一种极简实现
 * -------------------------------------
 * fa[i][j]: 顶点 i 的第 2^j 个父亲的索引为 fa[i][j]
 * 
 * fa[i][j] = fa[fa[i][j - 1]][j - 1]
 * -------------------------------------
 * sample input
 *  5
 *  1 2
 *  1 3
 *  2 4
 *  2 5
 *  3
 *  4 5
 *  3 4
 *  3 5
 * sample output
 *  2
 *  1
 *  1
*/
#include <iostream>

#define MAX_N 110000
int n, q;
int nodes[MAX_N], cnt; // cnt 表示边的编号

struct Edge
{
    int from, to;
} edges[MAX_N << 1]; // 无向图中边集大小为点集的两倍

// 添加边
void add(int from, int to)
{
    // 初始化边
    edges[++cnt].from = nodes[from];
    edges[cnt].to = to;
    // 设置边
    nodes[from] = cnt;
}

// depth-每个顶点对应的深度
int depth[MAX_N], fa[MAX_N][30]; 

void dfs(int son, int father)
{
    // 设置儿子的深度
    depth[son] = depth[father] + 1;
    // 设置儿子的父亲
    fa[son][0] = father;
    // 遍历儿子的所有邻接结点
    for(int i = nodes[son]; i; i = edges[i].from)
    {
        int v = edges[i].to; // 儿子节点的孩子
        if(v != father)
        {
            dfs(v, son);
        }
    }
}

// 求节点 x,y 的最近公共组先
int lca(int x, int y)
{
    // 始终聚焦深度小的节点
    if(depth[x] < depth[y])
        std::swap(x, y);

    for(int i = 20; i >= 0; --i)
    {
        // 如果x的第2^i个父亲的深度大于 y的深度，继续往上跳
        if(depth[fa[x][i]] >= depth[y])
        {
            x = fa[x][i];
        }
    }
    // 情况一：跳到最后发现 x,y 重合，直接返回 x 为结果
    if(x == y)
        return x;

    // 情况二：跳到最后发现 x,y 拥有同一个父亲，这个父亲就是结果
    for(int i = 20; i >= 0; --i)
    {
        if(fa[x][i] != fa[y][i])
        {
            x = fa[x][i];
            y = fa[y][i];
        }
    }

    return fa[x][0];
}

int main()
{
    std::cin >> n;
    int a, b;
    for(int i = 1; i <= n - 1; ++i)
    {
        std::cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1, 0); // 使用深搜初始化 depth 和 fa

    for(int j = 1; j <= 20; ++j)
    {
        for(int i = 1; i <= n; ++i)
        {
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
        }
    }

    std::cin >> q;
    for(int i = 0; i < q; ++i)
    {
        std::cin >> a >> b;
        std::cout << lca(a, b) << std::endl;
    }

    return 0;
}