#include <iostream>
#include <algorithm>

int main()
{
    int nums[4] = {1, 2, 3, 4};

    int index = 1;
    bool tag = true;
    while(tag)
    {
        std::cout << index++ << '\t';
        for(int i = 0; i < 4; ++i)
        {
            std::cout << nums[i] << ' ';
        }
        std::cout << '\n';

        tag = std::next_permutation(nums, nums + 4); // 获取下一个排列，如果要全排列，初始为升序
    }

    std::cout << "====================================\n";

    nums[0] = 4, nums[1] = 3, nums[2] = 2, nums[3] = 1;
    index = 1;
    tag = true;
    while(tag)
    {
        std::cout << index++ << '\t';
        for(int i = 0; i < 4; ++i)
        {
            std::cout << nums[i] << ' ';
        }
        std::cout << '\n';

        tag = std::prev_permutation(nums, nums + 4); // 获取上一个排列，如果要全排列，初始为降序
    }
}