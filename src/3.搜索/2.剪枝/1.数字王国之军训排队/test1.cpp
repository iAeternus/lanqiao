/**
 * https://www.lanqiao.cn/problems/2942/learning/?page=1&first_category_id=1&problem_id=2942
 * 
 * 关于最少能分成几队，需要枚举队伍个数 [1, 10]，使用 dfs 寻找最小的满足条件的队伍数
*/
/*
sample input
4
2 3 4 4
sample output
3
*/
#include <bits/stdc++.h>

const int N = 15;
int n, a[N];

// 第 i 行存储对于第 i 个人能配对的队友有哪些
std::vector<int> v[N];

/**
 * 不剪枝的版本，在收集结果处校验合法性，性能较差
 * cnt 分成 cnt 队
 * dep 搜索深度
 * 返回在 cnt 队下能否正确分组
*/
bool dfs(int cnt, int dep)
{
    if(dep == n + 1)
    {
        // 判断结果的合法性
        for(int k = 1; k <= cnt; ++k) // 对于每一个人
        {
            // 枚举其所有队友
            for(int i = 0; i < v[k].size(); ++i)
            {
                for(int j = i + 1; j < v[k].size(); ++j)
                {
                    if(v[k][j] % v[k][i] == 0) return false;
                }
            }
        }
        return true;
    }

    for(int i = 1; i <= cnt; ++i)
    {
        // 给这个人添加队友
        v[i].push_back(a[dep]);
        if(dfs(cnt, dep + 1)) return true;
        // 回溯
        v[i].pop_back();
    }

    // 都不满足，返回 false
    return false;
}

int main()
{
    std::cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
    }
    std::sort(a + 1, a + n + 1);

    for(int i = 1; i <= n; ++i)
    {
        // 只要满足，即为最小
        if(dfs(i, 1))
        {
            std::cout << i << std::endl;
            break;
        }
    }

    return 0;
}
