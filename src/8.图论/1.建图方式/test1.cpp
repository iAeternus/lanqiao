// 链式前向星 存储图
/*
sample input
5 7
1 2 1
2 3 2
3 4 3
1 3 4
4 1 5
1 5 6
4 5 7
sample output
1 //以1为起点的边的集合
1 5 6
1 3 4
1 2 1

2 //以2为起点的边的集合
2 3 2

3 //以3为起点的边的集合
3 4 3

4  //以4为起点的边的集合
4 5 7
4 1 5

5 //以5为起点的边不存在
*/
#include <bits/stdc++.h>

#define MAX_N 1005

int n, m, cnt;  // n 个点，m 条边

struct Edge {
    int to;           // 边终点
    int next;         // 同起点的上一条边的编号
    int weight;       // 边权
} edges[MAX_N << 1];  // 边集

// head[i] 表示以 i 为起点的最后一条边在边集数组中的位置
// 为了好遍历，初始化为 -1，充当终止条件
int head[MAX_N];

// 初始化图
void init() {
    for (int i = 0; i <= n; ++i) {
        head[i] = -1;
    }
    cnt = 0;
}

// 添加边
void add_edge(int from, int to, int weight) {
    edges[cnt].to = to;          // 设置终点
    edges[cnt].weight = weight;  // 设置边权
    // 以 from 为起点的最后一条边的编号，就是与这个边同起点的上一条边的编号
    edges[cnt].next = head[from];
    // 更新以 from 为起点的最后一条边的编号
    head[from] = cnt++;
}

// 遍历以 from 节点为起点的所有边
void for_each(int from, const std::function<void(int)>& func) {
    // 首先 i 为以 from 为起点的最后一条边的编号，每次遍历到同起点的上一条边的编号直到 i == -1
    for (int i = head[from]; i != -1; i = edges[i].next) {
        func(i);
    }
}

int main() 
{
    std::cin >> n >> m;
    init();
    int from, to, weight;
    // 输入 m 条边
    for (int i = 1; i <= m; ++i) {
        std::cin >> from >> to >> weight;
        add_edge(from, to, weight);
        // add_edge(to, from, weight); // 加双向边（可选）
    }

    // 遍历 n 个起点
    for (int i = 1; i <= n; ++i) {
        std::cout << i << std::endl;
        for_each(i, [](int from) {
            printf("%d %d %d\n", from, edges[from].to, edges[from].weight);
        });
    }

    return 0;
}