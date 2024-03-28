/*
小明和完美序列
问题描述
小明又新学了一个概念，叫做完美序列。一个仅包含数字序列被称为完美序列，
当且仅当数字序列中每个数字出现的次数等于这个数字。比如（1),(2,2,3,3,3)。
空序列也算。现在小明得到了一个数字序列，他想知道最少要删除多少个数字才能使得这个数字序列成为一个完美序列。

输入格式
输入包括两行。
第一行一个整数n，表示数字序列中数字的个数。
第二行，包括 n个整数，是数字序列中具体的每个数字。

输出格式
输出一个整数，表示最少要删除的数字个数。

样例输入
6
3 3 3 1 13 15
样例输出
2
*/
#include <iostream>
#include <map>
#include <vector>

int main()
{
    std::map<int, int> map; // 键-数字 值-数字出现的次数
    std::vector<int> nums;

    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        std::cin >> x;
        if (!map.count(x)) // x 不存在于 map 中
        {
            map.insert(std::make_pair(x, 1));
            nums.push_back(x);
        }
        else // 计数加一
        {
            map[x]++;
        }
    }

    int ans = 0;
    for (const auto &it : nums)
    {
        if (map[it] < it) // 次数小于数字，要把这个数全部删掉
        {
            ans += map[it];
        }
        else if (map[it] > it) // 此时就要将次数减去数字表示要删除几个数字
        {
            ans += map[it] - it;
        }
    }

    std::cout << ans << '\n';
    return 0;
}