#include <cstdlib>

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x < 2)
        {
            return x;
        }

        double y = x;
        double z = (y + (x / y)) / 2;

        while (std::abs(y - z) > 0)
        {
            y = z;
            z = (y + (x / y)) / 2;
        }
        return z;
    }
};