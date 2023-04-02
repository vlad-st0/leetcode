#include <vector>
#include <map>

using std::map;
using std::vector;

/** 1. Two Sum */
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> diff;
        for (int i = 0; i < nums.size(); i++)
        {
            if (diff.find(target - nums[i]) != diff.end())
                return {diff[target - nums[i]], i};
            diff[nums[i]] = i;
        }
        return {};
    }
};