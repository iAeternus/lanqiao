#include <bits/stdc++.h>

void select_sort(int a[], int n)
{
    for(int i = n - 1; i >= 0; --i)
    {
        int min_index = 0;
        for(int j = 0; j <= i; ++j)
        {
            if(a[j] < a[min_index]) // 降序
            {
                min_index = j;
            }
        }
        std::swap(a[min_index], a[i]);
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

    select_sort(a, n);

    for(int i = 0; i < n; ++i)
    {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}