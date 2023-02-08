#include <vector>
#include <bits/stdc++.h>

using std::sort;
using std::vector;

/** 15. 3Sum */
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int i = 0;
        while (i < nums.size() - 2)
        {
            if (nums[i] > 0)
                return result;
            int l = i + 1, r = nums.size() - 1;
            while (l < r)
            {
                int sum = nums[l] + nums[r] + nums[i];
                if (sum == 0)
                {
                    result.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                    continue;
                }

                if (sum < 0)
                    l++;
                else
                    r--;
            }
            i++;
            while (i < nums.size() - 2 && nums[i - 1] == nums[i])
                i++;
        }
        return result;
    }
};