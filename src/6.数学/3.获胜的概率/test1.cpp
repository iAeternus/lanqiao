/**
 * https://www.lanqiao.cn/problems/3978/learning/?page=1&first_category_id=1&name=%E8%8E%B7%E8%83%9C%E7%9A%84%E6%A6%82%E7%8E%87
 *
 * p[i][j]: j 将花给到 i 的概率为 p[i][j]
 * 玩一轮游戏就相当于概率矩阵 p 与自己相乘
 * k 轮游戏，就是概率矩阵的 k 次方，使用矩阵快速幂
 *
 * 概率可根据费马小定理，对概率取模等于乘以分母的逆元
 */
/*
sample input
4 1
2 2 4
1 2
2 2 4
1 1
sample output
0
500000004
0
500000004
*/
#include <bits/stdc++.h>

using ull = unsigned long long;

const int mod = 1e9 + 7;

class Matrix {
   public:
    int row, col;
    ull matrix[11][11];

    /**
     * tag 为 true时，初始化为单位矩阵
     */
    Matrix(int r = 10, int c = 10, bool tag = false) {
        row = r;
        col = c;
        memset(matrix, 0, sizeof(matrix));

        if (tag) {
            int min = std::min(row, col);
            for (int i = 0; i < min; ++i) {
                matrix[i][i] = 1;
            }
        }
    }
};

// 矩阵乘法
Matrix operator*(const Matrix& m1, const Matrix& m2) {
    Matrix ans;
    for (int i = 0; i < m1.row; ++i) {
        for (int j = 0; j < m2.col; ++j) {
            for (int k = 0; k < m1.col; ++k) {
                ull tmp = m1.matrix[i][k] * m2.matrix[k][j] % mod;
                ans.matrix[i][j] = (ans.matrix[i][j] + tmp) % mod;
            }
        }
    }
    return ans;
}

// 标量快速幂
ull quick_pow(ull base, ull power) {
    ull ans = 1;
    while (power) {
        if (power & 1) {
            ans = ans * base % mod;
            --power;
        }
        power >>= 1;
        base = base * base % mod;
    }
    return ans % mod;
}

// 矩阵快速幂
Matrix matrix_pow(Matrix base, ull power) {
    Matrix ans(base.row, base.row, true);
    while (power) {
        if (power & 1) {
            ans = ans * base;
            --power;
        }
        power >>= 1;
        base = base * base;
    }
    return ans;
}

int main() {
    int n;
    ull k;
    std::cin >> n >> k;

    Matrix p;  // 概率矩阵 p

    for (int i = 1; i <= n; ++i) {
        int t;
        std::cin >> t;
        ull q = quick_pow(t, mod - 2);  // 乘以分母（喜欢的人数）的逆元
        for (int j = 1; j <= t; ++j) {
            int like;
            std::cin >> like;
            p.matrix[like - 1][i - 1] = q;  // 下标从 0 开始
        }
    }

    Matrix tmp = matrix_pow(p, k);  // 玩 k 轮游戏

    for (int i = 0; i < n; ++i) {
        std::cout << tmp.matrix[i][0] << std::endl;  // 0 号玩家给到 i 号玩家的概率
    }

    return 0;
}