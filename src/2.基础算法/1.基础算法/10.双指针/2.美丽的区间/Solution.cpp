/**
 * https://www.lanqiao.cn/problems/1372/learning/?page=1&first_category_id=1&problem_id=1372
*/
#include <iostream>
#include <vector>

int solve(const std::vector<int>& nums, int S)
{
    int min_len = nums.size() + 1;
    int fast = -1, sum = 0;
    for(int slow = 0; slow < nums.size(); ++slow)
    {
        while(slow > fast || fast < nums.size() && sum < S)
        {
            sum += nums[++fast]; // 区间扩大
        }

        if(sum >= S)
        {
            min_len = std::min(min_len, fast - slow + 1);
        }
        sum -= nums[slow]; // 区间缩小
    }
    return min_len > nums.size() ? 0 : min_len;
}

int main()
{
    int n, S;
    std::cin >> n >> S;
    std::vector<int> nums(n);
    for(int i = 0; i < n; ++i)
    {
        std::cin >> nums[i];
    }

    std::cout << solve(nums, S) << std::endl;

    return 0;
}