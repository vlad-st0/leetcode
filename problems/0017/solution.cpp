#include <vector>
#include <string>
#include <map>

using std::map;
using std::string;
using std::vector;

/** 17. Letter Combinations of a Phone Number */
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};

        int total = 1;
        for (int i = 0; i < digits.size(); i++)
            total *= digitMap[digits[i]].size();

        vector<string> result(total);
        vector<int> seen(digits.size(), 0);

        for (int i = 0; i < total; i++)
        {
            result[i] = getStringFromMap(digits, seen);

            int index = digits.size() - 1;
            while (index >= 0)
            {
                if (seen[index] + 1 >= digitMap[digits[index]].size())
                {
                    seen[index] = 0;
                    index--;
                }
                else
                {
                    seen[index]++;
                    break;
                }
            }
        }

        return result;
    }

    string getStringFromMap(string digits, vector<int> seen)
    {
        string s;
        for (int i = 0; i < seen.size(); i++)
            s += digitMap[digits[i]][seen[i]];
        return s;
    }

    map<char, vector<char>> digitMap = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}},
    };
};

// #include <iostream>

// using std::cout;

// int main()
// {
//     auto sol = new Solution();
//     auto a = sol->letterCombinations("23");
//     for (auto b : a)
//     {
//         cout << b << '\n';
//     }
//     return 0;
// }