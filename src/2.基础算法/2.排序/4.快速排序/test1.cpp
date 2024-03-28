#include <bits/stdc++.h>

int partition(int a[], int l, int r)
{
    int pivot = a[r];
    int i = l, j = r;
    while(i < j) // 升序
    {
        while(i < j && a[i] <= pivot) ++i;
        while(i < j && a[j] >= pivot) --j;
        i < j ? std::swap(a[i], a[j]) : std::swap(a[i], a[r]);
    }
}

void quick_sort(int a[], int l, int r)
{
    if(l >= r)
        return;
    int mid = partition(a, l, r);
    quick_sort(a, l, mid - 1);
    quick_sort(a, mid + 1, r);
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

    quick_sort(a, 0, n - 1);

    for(int i = 0; i < n; ++i)
    {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}