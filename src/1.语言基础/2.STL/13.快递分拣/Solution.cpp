/*
题目描述
蓝桥王国的每个快递都包含两个参数：1.快递单号 2.快递城市。
小李是蓝桥王国的一名快递员，每天的快递分拣让他苦不堪言。
于是他想要你帮他设计一个程序用于快递的分拣（将不同快递按城市信息分开）。

输入描述
输入第一行包含一个整数N，表示快递的个数。
接下来第2~N+1行每行包含一个字符串 S和一个字符串P，分别快递单号以及快递对应的城市。
1≤N≤10，保证数据量不超过10。
输出描述
输出共若干行。按城市的输入顺序依次输出城市的名称以及城市的快递个数，以及该城市的所有快递单号（单号按照输入顺序排序）。

输入输出样例
示例
输入
10 
10124214 北京
12421565  上海
sdafasdg213 天津
fasdfga124 北京
145252  上海
235wtdfsg 济南
3242356fgdfsg 成都
23423 武汉  
23423565f 沈阳
1245dfwfs 成都

输出
北京 2
10124214
fasdfga124
上海 2
12421565
145252
天津 1
sdafasdg213
济南 1
235wtdfsg
成都 2
3242356fgdfsg 
1245dfwfs 
武汉 1
23423
沈阳 1
23423565f 

运行限制
最大运行时间：1s
最大运行内存: 256M
*/
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::string> cities;
    std::unordered_map<std::string, std::vector<std::string>> map;
    for(int i = 0; i < n; ++i)
    {
        std::string s, p;
        std::cin >> s >> p;

        if(map.count(p) == 0)
        {
            cities.push_back(p);
        }

        map[p].push_back(s);
    }

    for(const auto& i : cities)
    {
        std::cout << i << ' ' << map[i].size() << std::endl;
        for(const auto& j : map[i])
        {
            std::cout << j << std::endl;
        }
    }

    return 0;
}