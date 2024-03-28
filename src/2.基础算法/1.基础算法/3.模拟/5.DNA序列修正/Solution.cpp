/*
https://www.lanqiao.cn/problems/3904/learning/?page=1&first_category_id=1&sort=students_count&name=DNA%E5%BA%8F%E5%88%97%E4%BF%AE%E6%AD%A3
*/
#include <iostream>
#include <string>
#include <map>

int find(const std::string& s1, const std::string& s2, int i, int a, int b)
{
    while(i < s1.length())
    {
        if(s1[i] == b && s2[i] == a) // 反过来相等，寻找可以交换的地方
        {
            return i;
        }
        ++i;
    }
    return -1;
}

int main()
{
    int n;
    std::cin >> n;

    std::string s1, s2;
    std::cin >> s1 >> s2;

    std::map<char, char> map = {{'A', 'T'}, {'C', 'G'}, {'T', 'A'}, {'G', 'C'}};

    for(int i = 0; i < s1.length(); ++i)
    {
        s1[i] = map[s1[i]];
    }

    int cnt = 0;
    for(int i = 0; i < n; ++i)
    {
        if(s1[i] != s2[i])
        {
            int tmp = find(s1, s2, i, s1[i], s2[i]);
            if(tmp != -1) // 找到了，可以交换
            {
                std::swap(s2[i], s2[tmp]);
            }
            else // 没找到，只能替换
            {
                s2[i] = s1[i];
            }
            ++cnt;
        }
    }

    std::cout << cnt << std::endl;

    return 0;
}