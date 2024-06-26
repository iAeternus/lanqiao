/**
 * 字典树（Trie树），其中每个节点上可以存储（当然也可以不存储）一些变量用于表示该字符串的数量
 * 每条边表示一个字符
 * 从根节点到当前节点的简单路径就是一条字符串
 * 初始时，只有一个节点 1(作为根节点)
 * 
 * 算法解决的问题
 *      现在，我给你 n 个单词,然后进行 q 次询问，每一次询问一个单词 b ，问你 b 是否出现在 n 个单词中
*/
#include <bits/stdc++.h>

const int N = 1e3 + 7;

int next[N][27]; // next[i][0]表示从结点 i 出发，边 a 的下一个节点索引
int cnt[N]; // cnt[i]表示以节点 i 结尾的字符串数量
int idx = 2; // 内存池，用于动态开点

// 将长度为 n 的字符串 s 插入到 trie 中
void insert(const char* s) {
    int x = 1; // 当前位置，从 1 往下走
    for(int i = 0; s[i]; ++i) {
        if(!next[x][s[i] - 'a']) {
            // x 不存在 s[i] 的边，新建
            next[x][s[i] - 'a'] = idx++;
        }
        x = next[x][s[i] - 'a']; // x 移动到新点上
    }
    ++cnt[x];
}

// 判断某个字符串在 trie 中的出现次数
int check(const char* s) {
    int x = 1;
    for(int i = 0; s[i]; ++i) {
        x = next[x][s[i] - 'a'];
    }
    return cnt[x];
}

int main()
{
    insert("abc");
    insert("abc");
    insert("abb");
    insert("bca");
    insert("bc");
    std::cout << check("abc") << std::endl; // 2
    std::cout << check("ab") << std::endl; // 0
    std::cout << check("bc") << std::endl; // 1
    std::cout << check("cb") << std::endl; // 0
    return 0;
}