#include <vector>

using std::vector;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        const int N = nums1.size() + nums2.size();
        int index = 0, i = 0, j = 0, arr[N];

        while (i < nums1.size() && j < nums2.size())
            arr[index++] = (nums1[i] < nums2[j]) ? nums1[i++] : nums2[j++];

        while (i < nums1.size())
            arr[index++] = nums1[i++];

        while (j < nums2.size())
            arr[index++] = nums2[j++];

        return N % 2 ? arr[N / 2] : (arr[N / 2] + arr[N / 2 - 1]) / 2.0;
    }
};