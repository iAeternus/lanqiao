/**
 * https://www.lanqiao.cn/problems/182/learning/?page=1&first_category_id=1&problem_id=182
 * 
 * n 个点，每个点出度为 1，单向，求最大的环
 * 
 * 跑 dfs 求最大环，维护一个时间戳 dfn 描述当前遍历到了第几个节点，
 * 如果发现遍历到了比当前小的时间戳，说明遇到了环，环的大小为 当前时间戳 - 遍历到的时间戳 + 1，
 * 
 * 为了避免走到之前的环里去，维护一个最小时间戳 dfnmin，
 * 如果发现遍历到了比 mindfn 小的时间戳，说明重复遍历了
*/
/*
sample input
9
3 4 2 5 3 8 4 6 9
sample output
4
*/
#include <bits/stdc++.h>

const int N = 1e5 + 9;
// dfn 保存的时间戳
// mindfn 阶段最小时间戳
// idx 当前时间戳
int n, a[N], dfn[N], mindfn, idx;

int dfs(int x)
{
    // 赋予新的时间戳
    dfn[x] = ++idx;

    if(dfn[a[x]]) // 遍历到已被赋值的时间戳
    {
        // 这个时间戳满足最小时间戳的要求
        if(dfn[a[x]] >= mindfn) return dfn[x] - dfn[a[x]] + 1;
        // 否则无效
        return 0;
    }

    return dfs(a[x]);
}

int main()
{
    std::cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
    }

    // 图不一定联通，所以要遍历每个节点开展 dfs
    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(!dfn[i]) // 没有赋时间戳
        {
            mindfn = idx + 1;
            ans = std::max(ans, dfs(i));
        }
    }

    std::cout << ans << std::endl;

    return 0;
}