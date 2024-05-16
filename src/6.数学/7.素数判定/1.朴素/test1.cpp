#include <bits/stdc++.h>

bool isPrime(int num) {
    if(num < 2) {
        return false;
    }
    for(int i = 2; i <= num / i; ++i) { // 等价于 i * i <= n，防止溢出，快于 sqrt(num)
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    for(int i = 0; i <= 1000; ++i) {
        if(isPrime(i)) {
            std::cout << i << ' ';
        }
    }
    return 0;
}