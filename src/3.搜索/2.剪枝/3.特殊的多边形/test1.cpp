/**
 * https://www.lanqiao.cn/problems/3075/learning/?page=1&first_category_id=1&name=%E7%89%B9%E6%AE%8A%E7%9A%84%E5%A4%9A%E8%BE%B9%E5%BD%A2
*/
/*
sample input
4 3
1 10
30 50
60 200
200 400
sample output
0
1
18
32
*/
#include <bits/stdc++.h>

const int N = 1e5 + 7;
int cnt[N], prefix[N], n;

/**
 * 剪枝的版本，对 i 的上限进行剪枝
*/
void dfs(int dep, int st, int mul, int sum)
{
    // 剪枝：对于 mul 超过 1e6 的情况，不予考虑
    if(mul > 1e5) return;

    if(dep == n + 1)
    {
        cnt[mul]++;
        return;
    }
    
    int up = pow(1e5 / mul, 1.0 / (n - dep + 1)) + 3;
    int loop = dep == n ? std::min(sum, up) : up;

    // 遍历所有可能的边长，新边长必须大于老边长
    for(int i = st + 1; i < loop; ++i) // TODO
    {
        dfs(dep + 1, i, mul * i, sum + i);
    }
}

int main()
{
    int t;
    std::cin >> t >> n; 

    // 计算出所有满足条件的三元组
    dfs(1, 0, 1, 0);

    // 对 cnt 求前缀和
    for(int i = 1; i <= 1e5; ++i)
    {
        prefix[i] = prefix[i - 1] + cnt[i];
    }

    
    while(t--)
    {
        int l, r;
        std::cin >> l >> r;
        std::cout << prefix[r] - prefix[l - 1] << std::endl;
    }

    return 0;
}