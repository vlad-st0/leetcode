#include <string>

using std::string;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        if (a.size() > b.size())
        {
            b = string(a.size() - b.size(), '0') + b;
        }
        else if (a.size() < b.size())
        {
            a = string(b.size() - a.size(), '0') + a;
        }
        int n = a.size() - 1;
        int carry = 0;
        while (n >= 0)
        {
            int sum = carry + (a[n] - '0') + (b[n] - '0');
            carry = sum > 1;
            a[n--] = sum % 2 + '0';
        }
        return carry != 0 ? "1" + a : a;
    }
};