/**
 * https://www.lanqiao.cn/problems/3008/learning/?page=1&first_category_id=1&problem_id=3008
 * 
 * cnt[i]: 乘积为 i 的三元组的个数
 * dfs 维护 dep 深度、st 上一条边的长度、mul 现有边长的乘积，sum 现有边长的和
 * 对 cnt 求前缀和应对询问
*/
/*
sample input
4
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

const int N = 1e6 + 9;
int cnt[N], prefix[N];

/**
 * 剪枝的版本，对 i 的上限进行剪枝
*/
void dfs(int dep, int st, int mul, int sum)
{
    // 剪枝：对于 mul 超过 1e6 的情况，不予考虑
    if(mul > 1e6) return;

    if(dep == 4)
    {
        cnt[mul]++;
        return;
    }
    
    int loop = pow(1e6 / mul, 1.0 / (4 - dep)) + 3;

    // 遍历所有可能的边长，新边长必须大于老边长
    for(int i = st + 1; i < (dep == 3 ? sum : loop); ++i) // TODO
    {
        dfs(dep + 1, i, mul * i, sum + i);
    }
}

int main()
{
    // 计算出所有满足条件的三元组
    dfs(1, 0, 1, 0);

    // 对 cnt 求前缀和
    for(int i = 1; i <= 1e6; ++i)
    {
        prefix[i] = prefix[i - 1] + cnt[i];
    }

    int t;
    std::cin >> t;
    while(t--)
    {
        int l, r;
        std::cin >> l >> r;
        std::cout << prefix[r] - prefix[l - 1] << std::endl;
    }

    return 0;
}