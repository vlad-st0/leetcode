#include <string>
#include <algorithm>

/** 3. Longest Substring Without Repeating Characters */
class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int len = 0;
        int repeat[128] = {0};
        for (int j = 0, i = 0, c = 0; j < s.size(); j++)
        {
            c = int(s[j]);
            i = std::max(repeat[c], i);
            len = std::max(len, j - i + 1);
            repeat[c] = j + 1;
        }
        return len;
    }
};