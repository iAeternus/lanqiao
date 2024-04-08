#include <iostream>
#include <vector>

template <class T, class Compare = std::less<T>>  
T *lower_bound(T *first, T *last, const T &val, Compare comp = Compare())  
{  
    if (first >= last)  
    {  
        return last;  
    }  
  
    T *left = first;  
    T *right = last;  
    while (left < right)  
    {  
        size_t mid_index = (left + ((right - left) >> 1)) - first;  
        T *mid = first + mid_index;  
  
        if (comp(*mid, val))  
        {  
            left = mid + 1;  
        }  
        else  
        {  
            right = mid;  
        }  
    }  
  
    if (comp(*left, val))  
    {  
        return left;  
    }  
    else  
    {  
        return (left == first) ? last : left - 1;  
    }  
}

template <class T, class Compare = std::less<T>>  
T *upper_bound(T *first, T *last, const T &val, Compare comp = Compare())  
{  
    if (first >= last)  
    {  
        return last;  
    }  
  
    T *left = first;  
    T *right = last;  
    while (left < right)  
    {  
        size_t mid_index = (left + ((right - left) >> 1)) - first;  
        T *mid = first + mid_index;  
  
        if (comp(*mid, val))  
        {  
            left = mid + 1;  
        }  
        else  
        {  
            right = mid;  
        }  
    }  
  
    // right now points to the first element greater than or equal to val,  
    // or last if all elements are less than or equal to val.  
    if (comp(val, *right))  
    {  
        return right; // If val is less than *right, right is the upper bound.  
    }  
    else  
    {  
        return (left == right) ? right : left; // If val is equal to *right, either left or right is the upper bound.  
    }  
}

int main()
{
    long long nums[] = {1, 2, 3, 4, 5, 6, 6, 7, 8};
    size_t size = sizeof(nums) / sizeof(long long);

    std::cout << *lower_bound<long long>(nums, nums + size, 6) << std::endl;
    std::cout << *upper_bound<long long>(nums, nums + size, 6) << std::endl;

    return 0;
}