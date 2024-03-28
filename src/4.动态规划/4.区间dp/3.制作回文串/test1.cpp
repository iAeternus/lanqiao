/**
 * https://www.lanqiao.cn/problems/1547/learning/?page=1&first_category_id=1&problem_id=1547
 *
 * dp[i][j]: 把区间 [i, j] 变成回文串所需的最小花费为 dp[i][j]
 *
 * base case
 * dp[i][i] = 0
 *
 * dp
 * if str[i] == str[j] // 相等，缩小范围
 *      dp[i][j] = dp[i + 1][j - 1]
 * else // 不等，分 删去最左字符 和 将最左字符添加到末尾 两种选择，取最小花费
 *      dp[i][j] = min(dp[i + 1][j] + costs[i].remove, dp[i][j - 1] + costs[i].insert)
 */
/*
sample input
3 4
abcb
a 1000 1100
b 350 700
c 200 800
sample output
900
*/
#include <bits/stdc++.h>

struct Cost {
    int insert, remove;
};

const int N = 2e3 + 9;
int n, m, dp[N][N];
std::string str;
Cost costs[30];

int main() {
    std::cin >> n >> m >> str;
    for (int i = 1; i <= n; ++i) {
        char ch;
        std::cin >> ch;
        std::cin >> costs[ch - 'a'].insert >> costs[ch - 'a'].remove;
    }

    memset(dp, 127, sizeof(dp));
    for (int i = 0; i <= m; ++i) {
        dp[i][i] = 0;
    }

    for (int len = 2; len <= m; ++len) {
        for (int i = 0; i + len - 1 < m; ++i) {
            int j = i + len - 1;
            if (str[i] == str[j]) {
                if (len == 2) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            } else {
                dp[i][j] = std::min(dp[i + 1][j] + std::min(costs[str[i] - 'a'].remove, costs[str[i] - 'a'].insert),
                                    dp[i][j - 1] + std::min(costs[str[j] - 'a'].insert, costs[str[j] - 'a'].remove));
            }
        }
    }

    std::cout << dp[0][m - 1] << std::endl;

    return 0;
}