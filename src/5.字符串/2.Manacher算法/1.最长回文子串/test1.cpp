/**
 * https://www.lanqiao.cn/problems/1225/learning/?page=1&first_category_id=1&problem_id=1225
*/
/*
sample input
aa1ABA1b
sample output
5
*/
#include <bits/stdc++.h>

const int N = 1e6 + 9;
char s[N];
int p[N]; // 转化后的字符串中第 i 个字符的回文半径为 p[i]

int main()
{
    std::cin >> s + 1; int n = strlen(s + 1);

    // init
    for(int i = 2 * n + 1; i >= 1; --i) {
        s[i] = (i & 1) ? '#' : s[i >> 1];
    }
    s[0] = '^'; s[2 * n + 2] = '$';
    
    // 初始都从 0 开始
    int C = 0, R = 0; // C-回文中心 R-最长回文串右端点
    for(int i = 1; i <= 2 * n + 1; ++i) {
        // i 必须在 R 范围内
        p[i] = i < R ? std::min(R - i, p[2 * C - i]) : 1;
        // 如果 p[i] 还可以更大，持续更新
        while(s[i + p[i]] == s[i - p[i]]) {
            ++p[i];
        }
        // 如果此时 i 可以作为更好的 C，就替换
        if(i + p[i] > R) {
            C = i;
            R = i + p[i];
        }
    }

    int ans = 0;
    for(int i = 1; i <= 2 * n + 1; ++i) {
        // 转化后的字符串中回文半径为 p[i]，说明转换前的回文串长度为 p[i] - 1
        ans = std::max(ans, p[i] - 1);
    }

    std::cout << ans << std::endl;

    return 0;
}