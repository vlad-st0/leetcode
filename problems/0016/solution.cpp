#include <vector>
#include <bits/stdc++.h>

using std::sort;
using std::vector;

/** 16. 3Sum Closest */
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int i = 0, closest = INT_MAX, min = INT_MAX;

        while (i < nums.size() - 2)
        {
            int l = i + 1, r = nums.size() - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > target)
                    r--;
                else if (sum < target)
                    l++;
                else
                    return sum;

                if (abs(target - sum) < min)
                {
                    min = abs(target - sum);
                    closest = sum;
                }
            }
            i++;
            while (i < nums.size() - 2 && nums[i - 1] == nums[i])
                i++;
        }
        return closest;
    }
};