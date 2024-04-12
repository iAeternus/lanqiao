/**
 * https://www.lanqiao.cn/problems/1180/learning/?page=1&first_category_id=1&name=%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0%E5%88%97
 */
/*
sample input
6
1
2
3
4
5
1000000000
sample output
1
1
2
3
5
21
*/
#include <bits/stdc++.h>

using ull = unsigned long long;

const ull mod = 1e9 + 7;

ull m1[2][2] = {
    {0, 1},
};

ull m2[2][2] = {
    {0, 1},
    {1, 1},
};

class Matrix {
   public:
    int row, col;
    ull matrix[3][3];

    Matrix(int row = 2, int col = 2, bool tag = false) : row(row), col(col) {
        memset(matrix, 0, sizeof(matrix));
        if (tag) {
            int min = std::min(row, col);
            for (int i = 0; i < min; ++i) {
                matrix[i][i] = 1;
            }
        }
    }

    Matrix(ull matrix[2][2]) : row(2), col(2) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                this->matrix[i][j] = matrix[i][j];
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

ull fib(ull n) {
    Matrix F1(m1);
    Matrix A(m2);

    Matrix tmp = matrix_pow(A, n - 1); // A^(n - 1)
    Matrix Fn = F1 * tmp; // F1 * A^(n - 1)
    return Fn.matrix[0][1];
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        ull n;
        std::cin >> n;
        // fib(n);
        std::cout << fib(n) << std::endl;
    }
    return 0;
}