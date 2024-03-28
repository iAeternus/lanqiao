#include <bits/stdc++.h>

void bucket_sort(int a[], int n, int range) // [0, range)
{
    int buckets[range] = {0}; // 1000 代表值域
    for(int i = 0; i < n; ++i)
    {
        ++buckets[a[i]];
    }

    int index = 0;
    for(int i = 0; i < range; ++i)
    {
        for(int j = 0; j < buckets[i]; ++j)
        {
            a[index++] = i;
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

    bucket_sort(a, n, 1000);

    for(int i = 0; i < n; ++i)
    {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}