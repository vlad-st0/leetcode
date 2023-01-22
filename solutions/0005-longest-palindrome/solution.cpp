#include <string>

using std::string;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int start = 0, max = 1;

        for (int i = 1; i < s.size(); i++)
        {
            const char ch = s[i];
            int hi = i, lo = i;

            while (lo > 0 && s[lo - 1] == ch)
                lo--;
            while (hi < s.size() - 1 && s[hi + 1] == ch)
            {
                hi++;
                i++;
            }

            while (lo > 0 && hi < s.size() - 1 && s[lo - 1] == s[hi + 1])
            {
                hi++;
                lo--;
            }

            if (max < hi - lo + 1)
            {
                start = lo;
                max = hi - lo + 1;
            }
        }

        return s.substr(start, max);
    }
};
