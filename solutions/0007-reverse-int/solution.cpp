#include <bits/stdc++.h>

class Solution
{
public:
    int reverse(int x)
    {
        const bool negative = x < 0;
        if (negative)
        {
            if (x == INT_MIN)
                return 0;
            x = -x;
        }

        int ans = 0;
        while (x > 0)
        {
            if (ans > INT_MAX / 10)
                return 0;
            ans = ans * 10 + x % 10;
            x /= 10;
        }

        return negative ? -ans : ans;
    }
};