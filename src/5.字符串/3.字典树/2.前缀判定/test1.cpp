/**
 * https://www.lanqiao.cn/problems/1204/learning/?page=1&first_category_id=1&problem_id=1204
*/
/*
sample input
5 3
aaa
aba
aabbaa
abbbbb
cdd
aabba
abc
abab
sample output
Y
N
N
*/
#include <bits/stdc++.h>

const int N = 2e6 + 7;
int next[N][27];
int cnt[N];
int idx = 2;

int n, m;

void insert(char s[]) {
    int x = 1;
    for(int i = 0; s[i]; ++i) {
        if(!next[x][s[i] - 'a']) {
            next[x][s[i] - 'a'] = idx++;
        }
        x = next[x][s[i] - 'a'];
    }
    ++cnt[x];
}

bool check(char s[]) {
    int x = 1;
    for(int i = 0; s[i]; ++i) {
        x = next[x][s[i] - 'a'];
    }
    return x; // x 只要不为 0，就说明找到了
}

int main()
{
    std::cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        char s[N];
        std::cin >> s;
        insert(s); // 将字符串挂载在树下
    }

    for(int i = 0; i < n; ++i) {
        std::cout << cnt[i] << ' ';
    }
    std::cout << std::endl;

    for(int i = 1; i <= m; ++i) {
        char s[N];
        std::cin >> s;
        std::cout << (check(s) ? "Y" : "N") << std::endl;
    }

    return 0;
}