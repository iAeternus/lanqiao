/*
https://www.lanqiao.cn/problems/760/learning/?page=1&first_category_id=1&sort=students_count&problem_id=760
*/
#include <iostream>

#define N 20
int nums[N];

int dfs(int depth)
{
    int cnt = 1; // 包含原本的数，不做操作
    for(int i = 1; i <= nums[depth - 1] / 2; ++i) // 遍历树层
    {
        nums[depth] = i;
        cnt += dfs(depth + 1);
    }
    return cnt;
}

int main()
{
    int n;
    std::cin >> n;
    
    nums[0] = n;
    std::cout << dfs(1) << std::endl;

    return 0;
}