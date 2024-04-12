/**
 * https://www.lanqiao.cn/problems/3755/learning/?page=1&first_category_id=1&name=%E5%B0%8F%E8%93%9D%E7%9A%84%E7%A5%9E%E7%A7%98%E5%9B%BE%E4%B9%A6%E9%A6%86
 */
/*
sample input
5 2
ababc
ababd
aba
ab
a
abab
ccc
sample output
2
0
*/
#include <bits/stdc++.h>

const int N = 1e5 + 10;
int next[N][26], cnt[N], idx;

void insert(const std::string& s) {
    int n = s.length();
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (!next[pos][s[i] - 'a'])
            next[pos][s[i] - 'a'] = ++idx;
        pos = next[pos][s[i] - 'a'];
        cnt[pos]++;
    }
}

int check(const std::string& s) {
    int n = s.length();
    int pos = 0;
    // 查询到s字符串在字典树的末尾
    for (int i = 0; i < n; i++) {
        if (!next[pos][s[i] - 'a'])
            return 0;
        pos = next[pos][s[i] - 'a'];
    }
    return cnt[pos];
}

int main() {
    int n, m;
    std::cin >> n >> m;
    // 构建字典树
    for (int i = 1; i <= n; i++) {
        std::string s;
        std::cin >> s;
        insert(s);
    }
    // 开始查询
    for (int i = 1; i <= m; i++) {
        std::string s;
        std::cin >> s;
        std::cout << check(s) << '\n';
    }

    return 0;
}