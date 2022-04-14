/*
    Euclid's Algorithm

    An algorithm to get the greatest common divisor of two numbers.
*/

#include <iostream>

int gcd(int a, int b)
{
    // Replace the larger number with the remainder gotten when it is divided
    // by the smaller number. We do this until the remainder is zero.
    while (a != 0 && b != 0)
    {
        if (a > b)
        {
            a %= b;
        }
        else
        {
            b %= a;
        }
    }

    // At this point, one of the numbers is our gcd, and the other one is 0
    // (the one that forced the while loop to end). The variable 'ans' is our gcd.
    int ans = a != 0 ? a : b;
    return ans;
}

int main()
{
    int a = 50;
    int b = 30;

    std::cout << "gcd(" << a << ", " << b << ") = " << gcd(a, b) << std::endl;

    return 0;
}