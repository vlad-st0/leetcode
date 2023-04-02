#include <vector>
#include <string>
#include <set>

using std::set;
using std::string;
using std::vector;

/** 22. Generate Parentheses */
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        generate(result, n, 0, 0, "");
        return result;
    }

    void generate(vector<string> &result, int n, int open, int close, string str)
    {
        if (str.size() == n * 2)
        {
            result.push_back(str);
            return;
        }
        if (open < n)
            generate(result, n, open + 1, close, str + '(');
        if (close < open)
            generate(result, n, open, close + 1, str + ')');
    }
};