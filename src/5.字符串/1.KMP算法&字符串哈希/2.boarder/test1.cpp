/**
 * https://www.lanqiao.cn/problems/3160/learning/?page=1&first_category_id=1&name=boarder
 */
/*
sample input
abcdabcd
sample output
2
*/
// 本题考查对next数组含义的理解
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;

char T[N], S[N];  // T是文本串,S是模式串
int nex[N];       // next数组表示失配时模式串指针移动到什么位置
int n, n1;        // n为文本串长度,n1为模式串长度

void get_next(int n)  // 对文本串T求其next数组,获取最短循环节的长度
{
    nex[0] = nex[1] = 0;
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && T[i] != T[j + 1])
            j = nex[j];
        if (T[i] == T[j + 1])
            j++;
        nex[i] = j;
    }
}

int KMP(int t_length, int s_length)  // 在文本串T中匹配模式串S,记录匹配成功的次数
{
    int ans = 0;
    for (int i = 1, j = 0; i <= t_length; i++) {
        while (j && T[i] != S[j + 1])
            j = nex[j];
        if (T[i] == S[j + 1])
            j++;
        if (j == s_length)
            ans++;
    }
    if (n % ans == 0)
        return ans;
    // 若匹配成功的次数能被文本串的长度整除,说明该文本串可以由ans个模式串构成
    else
        return 1;  // 不能整除,说明该模式串(循环节)不能构成原文本串,只能返回1
}

int main() {
    cin >> T + 1;       // 输入文本串,下标从1开始
    n = strlen(T + 1);  // 计算文本串长度

    get_next(n);  // 对文本串求next数组
    // 若T=ababab,则next数组为 0 0 1 2 3 4,开头有两个0,说明最短循环节长度为2
    n1 = n - nex[n];  // 求最短循环节的长度
    for (int i = 1; i <= n1; i++)
        S[i] = T[i];       // 将最短循环节作为模式串  
    cout << KMP(n, n1) << endl; // 在文本串中匹配模式串,记录匹配成功的次数
    return 0;
}