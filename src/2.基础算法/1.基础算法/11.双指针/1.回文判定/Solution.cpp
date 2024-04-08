/**
 * https://www.lanqiao.cn/problems/1371/learning/?page=1&first_category_id=1&problem_id=1371
*/
#include <iostream>
#include <string>

bool is_palindromic_string(const std::string& str)
{
    int left = 0, right = str.length() - 1;
    while(left <= right)
    {
        if(str[left] != str[right])
        {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

int main()
{
    std::string str;
    std::cin >> str;
    std::cout << (is_palindromic_string(str) ? 'Y' : 'N') << std::endl;
    return 0;
}