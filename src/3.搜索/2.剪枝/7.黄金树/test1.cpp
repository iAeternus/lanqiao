/**
 * https://www.lanqiao.cn/problems/4494/learning/?page=1&first_category_id=1&name=%E9%BB%84%E9%87%91%E6%A0%91
 * 
 * 按黄金指数规则深搜二叉树，如果黄金指数为 0，累加
*/
/*
sample input
9
1 3 5 6 2 3 3 3 2
2 3
4 5
-1 6
-1 -1
7 -1
8 -1
-1 -1
9 -1
-1 -1
sample output
5
*/
#include <bits/stdc++.h>

const int N = 1e5 + 9;
int n, w[N];

struct Tree
{
    int left, right;
};

Tree tree[N];
int ans;

void dfs(int dep, int exp)
{
    if(!exp) ans += w[dep];
    if(tree[dep].left != -1) dfs(tree[dep].left, exp + 1);
    if(tree[dep].right != -1) dfs(tree[dep].right, exp - 1);
}

int main()
{
    std::cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> w[i];
    }
    for(int i = 1; i <= n; ++i)
    {
        int l, r;
        std::cin >> l >> r;
        tree[i] = {l, r};
    }

    dfs(1, 0);

    std::cout << ans << std::endl;

    return 0;
}
