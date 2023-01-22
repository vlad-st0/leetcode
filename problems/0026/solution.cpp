#include <vector>

/** 26. Remove Duplicates from Sorted Array */
class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        int i = 0;
        for (int j = 1; j < nums.size(); j++)
            if (nums[i] != nums[j])
                nums[++i] = nums[j];
        return i + 1;
    }
};