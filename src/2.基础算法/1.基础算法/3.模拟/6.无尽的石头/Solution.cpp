/*
https://www.lanqiao.cn/problems/3766/learning/?page=1&first_category_id=1&sort=students_count&name=%E6%97%A0%E5%B0%BD%E7%9A%84%E7%9F%B3%E5%A4%B4
*/
#include <iostream>

int getSum(int num)
{
    int sum = 0;
    while(num)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int count(int num)
{
    int start = 1, cnt = 0;
    while(start != num)
    {
        if(start > num) 
        {
            return -1;
        }
        start += getSum(start);
        ++cnt;
    }
    return cnt;
}

int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        int num;
        std::cin >> num;
        std::cout << count(num) << std::endl;
    }
    return 0;
}