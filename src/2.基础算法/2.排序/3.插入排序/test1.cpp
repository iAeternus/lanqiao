#include <bits/stdc++.h>

void insertion_sort(int a[], int n)
{
    for(int i = 1; i < n; ++i)
    {
        int val = a[i], j;
        for(j = i; j > 0 && val < a[j - 1]; --j) // 升序
        {
            a[j] = a[j - 1];
        }
        a[j] = val;
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

    insertion_sort(a, n);

    for(int i = 0; i < n; ++i)
    {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}