#include <vector>

class Solution
{
public:
    int removeElement(std::vector<int> &nums, int val)
    {
        int i = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] != val)
            {
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};