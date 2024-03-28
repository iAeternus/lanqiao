/*
https://www.lanqiao.cn/problems/3419/learning/?page=1&first_category_id=1&problem_id=3419
-------------------------------------------------------------------------------------------------
将 L 看做 1，Q 看做 -1，当且仅当某个区间的和为 0 时，字符串是平衡的，枚举区间，找最大
*/
#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string str;
    std::cin >> str;

    std::vector<int> prefix(str.length(), 0);
    for(int i = 0; i < str.length(); ++i)
    {
        prefix[i] = prefix[i - 1] + (str[i] == 'L' ? 1 : -1);
    }

    int result = 0;
    for(int l = 0; l < prefix.size(); ++l)
    {
        for(int r = 0; r < prefix.size(); ++r)
        {
            if(prefix[r] - prefix[l - 1] == 0)
            {
                result = std::max(result, r - l + 1);
            }
        }
    }

    std::cout << result << std::endl;

    return 0;
}

