#include <string>

using std::string;

/** 28. Find the Index of the First Occurrence in a String */
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        const int q = needle.size();
        const int n = haystack.size() - q + 1;
        for (int i = 0; i < n; i++)
        {
            int k = 0;
            while (k < q && haystack[i + k] == needle[k])
                k++;
            if (k == q)
                return i;
        }
        return -1;
    }
};