#include <string>

using std::string;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        int row = 0;
        bool asc = true;
        string rows[numRows];

        for (int i = 0; i < s.size(); i++)
        {
            rows[row].push_back(s[i]);
            if (row == numRows - 1)
                asc = false;
            else if (row == 0)
                asc = true;
            if (asc)
                row++;
            else
                row--;
        }

        string result = "";
        for (int i = 0; i < numRows; i++)
            result += rows[i];
        return result;
    }
};
