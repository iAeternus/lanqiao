#include <bits/stdc++.h>

const int N = 1000;
int a[N], tmp[N];

void merge_sort(int a[], int l, int r)
{
    if(l >= r)
        return;
    int mid = l - (l - r) / 2; // (l + r) / 2
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);

    int pl = l, pr = mid + 1, pb = l;
    while(pl <= mid || pr <= r)
    { 
        if(pl > mid) tmp[pb++] = a[pr++]; // 左半边已经放完
        else if(pr > r) tmp[pb++] = a[pl++]; // 右半边已经放完
        else
        {
            // 两边都有元素，取最小的放进 p 里
            if(a[pl] < a[pr]) tmp[pb++] = a[pl++];
            else tmp[pb++] = a[pr++];
        }
    }
    
    // 复制回去
    for(int i = l; i <= r; ++i)
    {
        a[i] = tmp[i];
    }
}

int main()
{
    srand((unsigned)time(0));

    for(int i = 0; i < N; ++i)
    {
        a[i] = rand() % 1000;
    }

    merge_sort(a, 0, N - 1);

    for(int i = 0; i < N; ++i)
    {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}