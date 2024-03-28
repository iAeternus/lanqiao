#include <iostream>
#include <cstring>
#include <bitset>
#include <vector>
#include <algorithm> // reverse unique

#define TEST_4

/**
 * @brief memset
 * @param ptr 指向要设置值的内存块的指针
 * @param value 要设置的值，通常是一个整数（8位二进制数）
 * @param num 要设置的字节数（Byte）
 * @note memset 将 ptr 指向的内存块的前 num 个字节设置为 value 的值
 * @return 函数返回指向 ptr 的指针
 * 
 * @note 对于非 char 类型的内存块，设置可能会导致未定义的行为
*/
void test_memset()
{
    int arr[5];
    memset(arr, 0, sizeof(arr));
    for(int i = 0; i < 5; ++i)
    {
        std::cout << arr[i] << '\n';
    }

    std::cout << "=================================================\n";

    memset(arr, 1, sizeof(arr));
    for(int i = 0; i < 5; ++i)
    {
        std::cout << arr[i] << " = " << std::bitset<32>(arr[i]) << '\n';
    }

    std::cout << "=================================================\n";

    memset(arr, 0x3f, sizeof(arr));
    for(int i = 0; i < 5; ++i)
    {
        std::cout << arr[i] << " = " << std::bitset<32>(arr[i]) << '\n';
    }
}

/**
 * @brief swap(T& a, T& b)
*/
void test_swap()
{
    int a = 10;
    int b = 20;
    std::swap(a, b);
    std::cout << a << ' ' << b << std::endl;
}

/**
 * @brief reverse 反转容器中元素顺序的函数
*/
void test_reverse()
{
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::reverse(arr.begin(), arr.end());
    for(int it : arr)
    {
        std::cout << it << std::endl;
    }
}

/**
 * @brief unique 取出容器中 相邻 重复元素的函数
 * @return 返回一个指向去重后范围的尾后迭代器，一般要去重后的数组需要删除返回值后面的元素
 * @note 时间复杂度 O(n)
 * @note 该函数只能去重相邻的重复，如果不相邻，先排序再去重
*/
void test_unique()
{
    std::vector<int> arr = {1, 1, 2, 2, 3, 3, 3, 4, 4, 5};

    auto it = std::unique(arr.begin(), arr.end());
    arr.erase(it, arr.end());

    for(int iter : arr)
    {
        std::cout << iter << std::endl;
    }
    
    std::cout << "=================================================\n";

    int a[] = {3, 1, 2, 2, 3};

    std::sort(a, a + 5);
    int n = std::unique(a, a + 5) - a;
    for(int i = 0; i < n; ++i)
    {
        std::cout << a[i] << std::endl;
    }
}

int main()
{
#ifdef TEST_1
    test_memset();
#elif defined(TEST_2)
    test_swap();
#elif defined(TEST_3)
    test_reverse();
#elif defined(TEST_4)
    test_unique();
#endif
    return 0;
}