#include <string>
#include <map>

class Solution
{
public:
    int romanToInt(std::string s)
    {
        int len = s.length();
        int result = map.at(s[len - 1]);
        for (int i = 1; i < len; i++)
        {
            int num = map.at(s[i - 1]);
            if (num < map.at(s[i]))
            {
                result -= num;
            }
            else
            {
                result += num;
            }
        }
        return result;
    }

    std::map<char, int> map{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};
};