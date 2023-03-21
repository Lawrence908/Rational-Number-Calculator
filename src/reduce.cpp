#include <iostream>

using namespace std;


int gcd (int a, int b) {
    int q;
    int r = 1;
    while (r != 0) {
        q = a / b;
        r = a - (q * b);
        if (r == 0)
            return abs(b);
        a = b;
        b = r;
    }
    return 0;
}