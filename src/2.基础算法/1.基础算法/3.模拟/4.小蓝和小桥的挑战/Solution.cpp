/*
https://www.lanqiao.cn/problems/3238/learning/?page=1&first_category_id=1&sort=students_count&name=%E5%B0%8F%E8%93%9D%E5%92%8C%E5%B0%8F%E6%A1%A5%E7%9A%84%E6%8C%91%E6%88%98
*/
#include <iostream>
#include <vector>

int main()
{
    int t, n;
    std::cin >> t;
    
    while(t--)
    {
        int result = 0, sum = 0;
        std::cin >> n;
        std::vector<int> nums(n);
        for(int i = 0; i < n; ++i)
        {
            std::cin >> nums[i];
            if(nums[i] == 0)
            {
                ++nums[i];
                ++result;
            }
            sum += nums[i];
        }

        // 和为 0，需额外操作
        std::cout << (sum ? result : ++result) << std::endl;
    }
    return 0;
}