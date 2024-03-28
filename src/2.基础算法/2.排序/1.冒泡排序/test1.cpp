#include <bits/stdc++.h>

void bubble_sort(int a[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n - i - 1; ++j)
        {
            if(a[j + 1] > a[j]) // 降序
            {
                std::swap(a[j], a[j + 1]);
            }
        }
    }
}

int main()
{
    int n = 1000;
    int a[n];
    srand((unsigned)time(0));

    for(int i = 0; i < n; ++i)
    {
        a[i] = rand() % 1000;
    }

    bubble_sort(a, n);

    for(int i = 0; i < n; ++i)
    {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}