/**
 * https://www.lanqiao.cn/problems/4360/learning/?page=1&first_category_id=1&name=%E4%B8%B2%E5%8F%98%E6%8D%A2
*/
#include <bits/stdc++.h>

const int N = 10;
int n, k;
std::string s, t;

struct Change
{
    int op, x, y;  
};

Change changes[N];
int vis[N];

void oper(std::string& str, Change change, bool flag)
{
    if(flag)
    {
        if(change.op == 1)
        {
            str[change.x] = (str[change.x] - '0' + change.y) % 10 + '0';
        }
        else if(change.op == 2)
        {
            std::swap(str[change.x], str[change.y]);
        }
    }
    else
    {
        if(change.op == 1)
        {
            str[change.x] = (str[change.x] - '0' - change.y + 10) % 10 + '0';
        }
        else if(change.op == 2)
        {
            std::swap(str[change.x], str[change.y]);
        }
    }
}

bool dfs(int dep)
{
    if(s == t) return true;
    if(dep == k + 1) return false;

    for(int i = 1; i <= k; ++i)
    {
        if(vis[i]) continue;

        vis[i] = 1;
        oper(s, changes[i], true);
        if(dfs(dep + 1)) return true;
        vis[i] = 0;
        oper(s, changes[i], false);
    }

    return false;
}

int main()
{
    std::cin >> n >> s >> t >> k;
    for(int i = 1; i <= k; ++i)
    {
        std::cin >> changes[i].op >> changes[i].x >> changes[i].y;
    }

    std::cout << (dfs(1) ? "Yes" : "No") << std::endl;

    return 0;
}