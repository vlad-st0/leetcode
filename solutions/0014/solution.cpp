#include <string>
#include <vector>

using std::string;

/** 14. Longest Common Prefix */
class Solution
{
public:
    string longestCommonPrefix(std::vector<string> &strings)
    {
        string prefix = strings[0];

        for (int i = 1; i < strings.size(); i++)
        {
            int len = std::min(prefix.length(), strings[i].length());
            string temp = "";
            for (int j = 0; j < len; j++)
            {
                if (prefix[j] != strings[i][j])
                    break;
                temp += prefix[j];
            }
            prefix = temp;
        }

        return prefix;
    }
};