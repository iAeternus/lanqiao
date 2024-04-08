/**
 * https://www.lanqiao.cn/problems/532/learning/?page=1&first_category_id=1&problem_id=532
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int w, n;
    std::cin >> w >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < arr.size(); ++i)
    {
        std::cin >> arr[i];
    }

    std::sort(arr.begin(), arr.end());

    int left = 0, right = arr.size() - 1;
    int cnt = 0;
    while (left <= right)
    {
        ++cnt;
        if (arr[left] + arr[right] <= w)
        {
            ++left;
            --right;
        }
        else
        {
            --right;
        }
    }

    std::cout << cnt << std::endl;

    return 0;
}