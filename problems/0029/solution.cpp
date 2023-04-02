#include <bits/stdc++.h>

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        long long ans = (long)dividend / (long)divisor;
        if (ans >= INT_MAX)
            return INT_MAX;
        else if (ans <= INT_MIN)
            return INT_MIN;
        else
            return (int)ans;
        return 0;
    }

    // no long
    // int divide(int dividend, int divisor)
    // {
    //     if (divisor == 1)
    //         return dividend;
    //     if (divisor == -1)
    //     {
    //         if (dividend == INT_MIN)
    //             return INT_MAX;
    //         return -dividend;
    //     }
    //     int rep = 0;
    //     int sign = 1;
    //     unsigned int dd = abs(dividend), dv = abs(divisor);
    //     if (dividend < 0)
    //         sign *= -1;
    //     if (divisor < 0)
    //         sign *= -1;
    //     while (dd - dv >= 0)
    //     {
    //         rep++;
    //         dd -= dv;
    //     }
    //     return sign * rep;
    // }
};