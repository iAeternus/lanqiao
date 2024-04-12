/**
 * https://www.lanqiao.cn/problems/1550/learning/?page=1&first_category_id=1&name=%E7%9F%A9%E9%98%B5%E7%9B%B8%E4%B9%98
*/
/*
sample input
2 1 3
1
2
1 2 3
sample output
1 2 3
2 4 6
*/
#include <bits/stdc++.h>

const int N = 105;
int A[N][N], B[N][N], C[N][N];
int n, m, k;

int main()
{
    std::cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            std::cin >> A[i][j];
        }
    }
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= k; ++j) {
            std::cin >> B[i][j];
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= k; ++j) {
            for(int t = 1; t <= m; ++t) {
                C[i][j] += A[i][t] * B[t][j];
            }
            std::cout << C[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}