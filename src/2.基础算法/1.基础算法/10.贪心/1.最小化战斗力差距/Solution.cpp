/**
 * https://www.lanqiao.cn/problems/3412/learning/?page=1&first_category_id=1&problem_id=3412
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for(int i = 0; i < arr.size(); ++i)
    {
        std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());
    
    int min = arr[1] - arr[0];
    for(int i = 2; i < arr.size(); ++i)
    {
        min = std::min(min, arr[i] - arr[i - 1]);
    }

    std::cout << min << std::endl;
    
    return 0;
}