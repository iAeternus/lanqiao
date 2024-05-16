#include <iostream>

int main()
{
    int x1 = 1, x2 = 2;

    auto max1 = [=](int a, int b) {
        std::cout << x1 << x2;
        return a < b ? b : a;
    };

    std::cout << max1(1, 2);

}