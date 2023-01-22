#include <string>
#include <bits/stdc++.h>

using std::string;

/** 8. String to Integer (atoi) */
class Solution
{
public:
    int myAtoi(string s)
    {
        int index = 0;
        long output = 0;
        bool negative = false;

        while (index < s.size() - 1 && s[index] == ' ')
            index++;

        if (s[index] == '+')
            index++;
        else if (s[index] == '-')
        {
            negative = true;
            index++;
        }

        while (index < s.size())
        {
            const int digit = s[index] - '0';
            if (digit < 0 || digit > 9)
                break;
            output = output * 10 + digit;
            if (output > INT_MAX)
                return negative ? INT_MIN : INT_MAX;
            index++;
        }

        return negative ? -output : output;
    }
};