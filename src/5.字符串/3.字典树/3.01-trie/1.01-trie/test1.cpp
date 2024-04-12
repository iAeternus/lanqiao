/**
 * 问题：给定数组nums，求 nums[i] ^ nums[j] 的最大值
 * 
 * 01-trie是一课二叉字典树，左 0 右 1
 * 求 nums[i] ^ nums[j] 的最大值，即求从最高位起（最高位占的权重最大）与 nums[i] 异或结果为 1 的分支
*/
/*
sample input
5
13 3 7 1 6
sample output
11
*/
#include <bits/stdc++.h>

const int N = 2e5 + 7;
int next[N][2];
int cnt[N];
int idx = 2;

int nums[N], n;

void insert(int num) {
    int cur = 1;
    for(int i = 31; i >= 0; --i) {
        int pos = (num >> i) & 1;
        if(!next[cur][pos]) {
            next[cur][pos] = idx++;
        }
        cur = next[cur][pos];
    }
    cnt[cur] = num;
}

int check(int num) {
    int cur = 1;
    for(int i = 31; i >= 0; --i) {
        int pos = (num >> i) & 1;
        if(next[cur][pos ^ 1]) { // 找不同的分支，因为与不同异或为 1
            cur = next[cur][pos ^ 1];
        } else {
            cur = next[cur][pos];
        }
    }
    return cnt[cur];
}

int main()
{
    std::cin >> n;
    for(int i = 1; i <= n; ++i) {
        std::cin >> nums[i];
        insert(nums[i]);
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        ans = std::max(ans, check(nums[i]));
    }

    std::cout << ans << std::endl;

    return 0;
}