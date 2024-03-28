#include <bits/stdc++.h>

int n0, n1, n;
int min = 1e9;
int min_b, min_g;
bool tag = false;

int main()
{
    std::cin >> n0 >> n1 >> n;
    for(int i = 1; i < n; ++i)
    {
        int boy = i, girl = n - i;
        if(n0 % boy == 0 && n1 % girl == 0)
        {
            if(n0 / boy != 1 && n1 / girl != 1)
            {
                int diff = abs(n0 / boy - n1 / girl);
                if(diff < min)
                {
                    min = diff;
                    min_b = boy;
                    min_g = girl;
                    tag = true;
                }
            }
        }
    }

    if(tag)
    {
        std::cout << min_b << ' ' << min_g << std::endl;
    }
    else
    {
        std::cout << "No Solution" << std::endl;
    }

    return 0;
}