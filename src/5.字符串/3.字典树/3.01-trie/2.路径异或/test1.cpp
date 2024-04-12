/**
 * 给定一棵树和树上的边权，求两点之间路径异或值的最大值
 * 
 * 求出从根节点到其他节点简单路径上的异或值，计算该数组的两数异或的最大值即为答案
 * 因为路径上重复的部分异或为 0
 */
#include <bits/stdc++.h>

const int N = 1e3 + 9;
int next[N][2], val[N], idx = 2;
int n, head[N], cnt;

struct Edges {
    int next, to, weight;
} edges[N << 1];

void add(int from, int to, int weight) {
    edges[cnt].to = to;
    edges[cnt].weight = weight;
    edges[cnt].next = head[from];
    head[from] = cnt++;
}

int xo[N]; // xo[i]记录从根节点到节点 i 简单路径上的异或值

void dfs(int x, int fa) {
    for(int i = head[x]; i; i = edges[i].next) {
        int v = edges[i].to;
        if(v == fa) continue;
        xo[v] = xo[x] ^ edges[i].weight;
        dfs(v, x);
    }
}

void insert(int num) {
    int cur = 1;
    for(int i = 31; i >= 0; --i) {
        int pos = (num >> i) & 1;
        if(!next[cur][pos]) {
            next[cur][pos] = idx++;
        }
        cur = next[cur][pos];
    }
    val[cur] = num;
}

int check(int num) {
    int cur = 1;
    for(int i = 31; i >= 0; --i) {
        int pos = (num >> i) & 1;
        if(next[cur][pos ^ 1]) {
            cur = next[cur][pos ^ 1];
        } else {
            cur = next[cur][pos];
        }
    }
    return val[cur];
}

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    dfs(1, 0);

    for(int i = 1; i <= n; ++i) {
        insert(xo[i]);
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        ans = std::max(ans, check(xo[i]));
    }

    std::cout << ans << std::endl;

    return 0;
}