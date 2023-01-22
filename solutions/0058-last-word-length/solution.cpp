#include <string>

class Solution
{
public:
    int lengthOfLastWord(std::string s)
    {
        bool wordFound = false;
        int result = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
            {
                wordFound = true;
                result++;
            }
            else if (wordFound)
            {
                break;
            }
        }
        return result;
    }
};