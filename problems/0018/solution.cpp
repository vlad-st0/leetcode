#include <vector>
#include <bits/stdc++.h>

using std::sort;
using std::vector;

/** 18. 4Sum */
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        const int n = nums.size();
        for (int i = 0; i < n - 3; i++)
        {
            if (i && nums[i - 1] == nums[i])
                continue;
            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && nums[j - 1] == nums[j])
                    continue;
                int l = j + 1;
                int r = n - 1;
                while (l < r)
                {
                    long long int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target)
                    {
                        result.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        while (l < r && nums[l] == nums[l - 1])
                            l++;
                        while (l < r && nums[r] == nums[r + 1])
                            r--;
                    }
                    else if (sum < target)
                        l++;
                    else
                        r--;
                }
            }
        }
        return result;
    }
};