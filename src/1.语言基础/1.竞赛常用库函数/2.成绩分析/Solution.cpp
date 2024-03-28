/*
成绩分析
题目描述
小蓝给学生们组织了一场考试，卷面总分为100分，每个学生的得分都是一个0到100的整数。
请计算这次考试的最高分、最低分和平均分。

输入描述
输入的第一行包含一个整数 n (1≤ n ≤104)，表示考试人数。
接下来 n 行，每行包含一个0至100的整数，表示一个学生的得分。

输出描述
输出三行。
第一行包含一个整数，表示最高分。
第二行包含一个整数，表示最低分。
第三行包含一个实数，四舍五入保留正好两位小数，表示平均分。

输入输出样例
示例
输入
7
80
92
56
74
88
99
10
输出
99
10
71.29
*/
#include <iostream>
#include <vector>
#include <iomanip>

int max_elements(const std::vector<int>& nums)
{
    int max = nums[0];
    for(int i = 1; i < nums.size(); ++i)
    {
        if(max < nums[i])
        {
            max = nums[i];
        }
    }
    return max;
}

int min_elements(const std::vector<int>& nums)
{
    int min = nums[0];
    for(int i = 1; i < nums.size(); ++i)
    {
        if(min > nums[i])
        {
            min = nums[i];
        }
    }
    return min;
}

double ave(const std::vector<int>& nums)
{
    int sum = 0;
    for(const auto& it : nums)
    {
        sum += it;
    }
    return 1.0 * sum / nums.size();
}

int main()
{
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for(int i = 0; i < n; ++i)
    {
        std::cin >> nums[i];
    }
    
    std::cout << max_elements(nums) << std::endl;
    std::cout << min_elements(nums) << std::endl;
    std::cout << std::fixed << std::setprecision(2) << ave(nums) << std::endl;

    return 0;
}