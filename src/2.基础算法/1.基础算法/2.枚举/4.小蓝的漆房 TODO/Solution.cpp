/*
小蓝的漆房 
小蓝是一位有名的漆匠，他的朋友小桥有一个漆房，里面有一条长长的走廊，走廊两旁有许多相邻的房子，每间房子最初被涂上了一种颜色。
小桥来找小蓝，想让他把整个走廊都涂成同一个颜色。小蓝告诉小桥，他每天只能涂一段长度为k 的区间。
对于每个区间，他可以选择将其中的房子重新涂上任何一种颜色，或者保持原来的颜色不变。
小桥想知道小蓝至少要涂几天，才能让整个走廊变得美丽。
请帮助小桥解决这个问题。

输入格式
第一行包含一个整数t(1≤100)，表示测试用例的数量。
每个测试用例的第一行包含两个整数n和k(1≤k≤n ≤10e4)，第二行包含n个整数
a1,a2,…,an(1≤ai≤60)，分别表示每个房子最初的颜色。
保证所有测试用例中 n的总和不超过10e4。

输出格式
对于每个测试用例，输出一个整数，表示小蓝需要涂漆的最少天数。

输入输出样例
样例输入
2
5 2
1 1 2 2 1
6 2
1 2 2 3 3 3
样例输出
1
2
*/
#include <iostream>
#include <map>
#include <vector>
#include <cmath>

int runOnce(int t)
{
    int n, k;
    std::cin >> n >> k;

    int x;
    std::map<int, int> map; // 键-数字 值-数字出现的次数
    std::vector<int> nums;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> x;
        if (!map.count(x))
        {
            map.insert(std::make_pair(x, 1));
            nums.push_back(x);
        }
        else
        {
            ++map[x];
        }
    }

    int maxCnt = 0;
    for (const auto& it : nums)
    {
        if (map[it] > maxCnt)
        {
            maxCnt = map[it];
        }
    }

    return (int)(n - maxCnt + k - 1) / k;
}

int main()
{
    int t;
    std::cin >> t;

    std::vector<int> results;
    for (int i = 0; i < t; ++i)
    {
        results.push_back(runOnce(t));
    }

    for(const auto& result : results)
    {
        std::cout << result << std::endl;
    }

    return 0;
}