/**
 * rmq 问题
 * 给定数组 nums 和 q 次询问，每次询问 [l, r] 之间的最小值
 * 使用倍增和dp的思想
 *
 * dp[i][j]: 从 i 开始连续 2^j 个数的最小值为 dp[i][j]
 *
 * dp
 *      dp[i][j] = min(dp[i][j - 1], dp[i + 2^(j-1)][j - 1])
 *
 * for j 1 -> log2(n)
 *      for i 1 -> n - 2^j + 1
 *
 * base case
 *      dp[i][0] = nums[i]
 *
 * 对于每次询问，只需查 min(dp[l][k], dp[r - 2^k + 1][k])
 * k = log2(r - l + 1)
 * 显然两段区间覆盖了整个询问的范围
 */
#include <cstdio> // 对于 1e5 以上的输入不建议使用 cin
#include <vector>
#include <cmath>

#define MAX_N 110000
#define ll long long
int n, nums[MAX_N], dp[MAX_N][40];

int query(int l, int r)
{
    int k = (int)log2(r - l + 1);
    return std::min(dp[l][k], dp[r - (1 << k) + 1][k]);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &nums[i]), dp[i][0] = nums[i];
    }

    int k = (int)log2(n);
    for (int j = 1; j <= k; ++j)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        {
            dp[i][j] = std::min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }

    int q;
    scanf("%d", &q);
    while (q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", query(l, r));
    }

    return 0;
}