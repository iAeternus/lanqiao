#include <bits/stdc++.h>

std::string str;
int n;

int main()
{
    std::cin >> str >> n;
    while(n--)
    {
        int l, r;
        std::string l_str, r_str;
        std::cin >> l >> r >> l_str >> r_str;
        --l; --r; // //对应字符串下标做一个自减操作

        std::string cut = str.substr(l, r - l + 1);
        str.erase(l, r - l + 1);

        size_t pos = str.find(l_str + r_str);
        if(pos != str.npos)
        {
            str = str.substr(0, pos + l_str.size()) + cut + str.substr(pos + l_str.size());
        }
        else
        {
            str += cut;
        }
    }

    std::cout << str << std::endl;

    return 0;
}