/**
 * https://www.lanqiao.cn/problems/3205/learning/?page=1&first_category_id=1&name=%E5%B0%8F%E6%98%8E%E7%9A%84%E7%B4%A0%E6%95%B0%E5%AF%B9
*/
/*
sample input 1
5
sample output 1
2

sample input 2
20
sample output 2
8
*/
#include <bits/stdc++.h>

using ll = long long;
const int N = 1e5 + 9;

std::bitset<N> vis; // true-筛掉 false-留下来的素数
std::vector<ll> primes;

// 埃氏筛法
void init(int n) {
    vis[0] = vis[1] = true;
    for(int i = 2; i <= n / i; ++i) {
        if(!vis[i]) {
            for(int j = i * i; j <= n; j += i) {
                vis[j] = true;
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            primes.push_back(i);
        }
    }
}

int main()
{
    int n;
    std::cin >> n;
    init(n);

    int ans = 0;
    for(int i = 0; i < primes.size(); ++i) {
        for(int j = 0; j < i; ++j) {
            if(!vis[primes[i] - primes[j]]) {
                ++ans;
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}