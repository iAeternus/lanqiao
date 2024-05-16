#include <cmath>
#include <iostream>

#define eps 1e-6
using ll = long long;

double quick_pow(double base, double power) {
    double ans = 1.0;
    while (fabs(power) >= eps) {
        if (fmod(power, 2) == 1) {
            ans = ans * base;
            --power;
        }
        power /= 2;
        base = base * base;
    }
    return ans;
}

// ll quick_pow(ll base, ll power) {
//     ll ans = 1;
//     while (power) {
//         if (power & 1) {
//             ans = ans * base;
//             --power;
//         }
//         power >>= 1;
//         base = base * base;
//     }
//     return ans;
// }

int main() {
    // std::cout << quick_pow(2, 0.5) << std::endl;
    for (ll i = 1; i <= 10; ++i) {
        std::cout << quick_pow(2, i) << std::endl;
    }
    return 0;
}