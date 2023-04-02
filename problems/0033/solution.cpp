#include <vector>

using std::vector;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int i;
        for (i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
                return i;
            if (nums[i] > target)
                break;
        }
        for (int j = nums.size() - 1; j > i; j--)
        {
            if (nums[j] == target)
                return j;
            if (nums[j] < target || nums[i] < nums[j])
                break;
        }
        return -1;
    }
};