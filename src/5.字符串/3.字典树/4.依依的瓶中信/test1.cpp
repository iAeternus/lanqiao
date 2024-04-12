/**
 * https://www.lanqiao.cn/problems/3751/learning/?page=1&first_category_id=1&name=%E4%BE%9D%E4%BE%9D%E7%9A%84%E7%93%B6%E4%B8%AD%E4%BF%A1
 */
/*
sample input
3
abc
ab
bc
sample output
2
2
0
*/
#include <bits/stdc++.h>

const int N = 1e4 + 9;
int next[N][27], cnt[N], idx = 2;
std::string s[N];

void insert(const std::string& s) {
    int cur = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (!next[cur][s[i] - 'a']) {
            next[cur][s[i] - 'a'] = idx++;
        }
        cur = next[cur][s[i] - 'a'];
        ++cnt[cur];
    }
}

int check(const std::string& s) {
    int cur = 1, ans = 0;
    for(int i = 1; i < s.size(); ++i) {
        cur = next[cur][s[i] - 'a'];
        if(cnt[cur] != 1) {
            ans = i;
        } else {
            break;
        }
    }
    return ans; // 自己本身就是某个子串的前缀，返回自己的长度
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> s[i];
        s[i] = '0' + s[i];
        insert(s[i]);
    }

    for(int i = 1; i <= n; ++i) {
        std::cout << check(s[i]) << std::endl;
    }

    return 0;
}