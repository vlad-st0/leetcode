#include <string>
#include <map>
#include <vector>

/** 20. Valid Parentheses */
class Solution
{
public:
    bool isValid(std::string s)
    {
        if (s.length() % 2 == 1)
            return false;
        std::vector<char> order = {};

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                order.push_back(s[i]);
                continue;
            }
            if (order.size() > 0 && map.at(s[i]) == order.back())
            {
                order.pop_back();
                continue;
            }
            return false;
        }
        return order.size() == 0;
    }

    std::map<char, char> map{
        {')', '('},
        {']', '['},
        {'}', '{'},
    };
};