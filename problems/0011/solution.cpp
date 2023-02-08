#include <vector>

using std::max;
using std::vector;

/** 11. Container With Most Water */
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        // optimization for large inputs
        // std::ios_base::sync_with_stdio(false);
        // std::cin.tie(nullptr);
        
        int result = 0, i = 0, j = height.size() - 1;
        while (i < j)
        {
            if (height[i] > height[j])
                result = max(result, (j - i) * height[j--]);
            else
                result = max(result, (j - i) * height[i++]);
        }
        return result;
    }
};