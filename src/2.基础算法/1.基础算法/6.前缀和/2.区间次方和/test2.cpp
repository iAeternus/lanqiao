/*
sample input
5 3
1 2 3 4 5
1 3 2
2 4 3
3 5 1
sample output
14
99
12
*/
#include <bits/stdc++.h>

using ll = long long;

const int N = 1e5 + 9;
const int mod = 1e9 + 7;
ll prefix[N][6], a[N];

int main()
{
    int n, m;
    std::cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        for(int j = 1; j <= 5; ++j) {
            prefix[i][j] = prefix[i - 1][j] + pow(a[i], j);
        }
    }

    while(m--) {
        int l, r, k;
        std::cin >> l >> r >> k;
        std::cout << (prefix[r][k] - prefix[l - 1][k]) % mod << std::endl;
    }

    return 0;
}