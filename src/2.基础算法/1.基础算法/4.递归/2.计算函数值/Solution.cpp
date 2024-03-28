/*
https://www.lanqiao.cn/courses/21965/learning/?id=1149563&compatibility=false
*/
#include <iostream>

int s(int n)
{
    if(n == 0) return 1;
    else if(n & 1) return s(n - 1) + 1;
    else return s(n / 2);
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << s(n) << std::endl;
    return 0;
}