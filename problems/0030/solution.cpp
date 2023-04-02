#include <string>
#include <vector>
#include <unordered_map>

using std::string;
using std::unordered_map;
using std::vector;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        unordered_map<string, int> dict;
        for (auto &w : words)
            dict[w]++;
        vector<int> res;
        int n = s.size(), m = words[0].size(), w = words.size();

        for (int k = 0; k < m; k++)
        {
            unordered_map<string, int> seen;
            int left = k, currLen = 0;
            for (int i = left; i + m <= n; i += m)
            {
                string temp = s.substr(i, m);
                if (!(dict.count(temp)))
                {
                    seen.clear();
                    currLen = 0;
                    left = i + m;
                }
                else
                {
                    seen[temp]++;
                    currLen++;
                    if (seen[temp] > dict[temp])
                    {
                        while (seen[temp] > dict[temp])
                        {
                            string temp1 = s.substr(left, m);
                            seen[temp1]--;
                            currLen--;
                            left += m;
                        }
                    }
                }
                if (currLen == w)
                {
                    res.push_back(left);
                    seen[s.substr(left, m)]--;
                    currLen--;
                    left += m;
                }
            }
        }
        return res;
    }
};

// time limit exceeded at one of the last test case
// class Solution
// {
// public:
//     vector<int> findSubstring(string s, vector<string> &words)
//     {
//         vector<int> result = {};
//         sort(words.begin(), words.end());
//         do
//         {
//             string permutation;
//             for (auto w : words)
//                 permutation += w;
//             size_t search = s.find(permutation);
//             while (search != string::npos)
//             {
//                 result.push_back(search);
//                 search = s.find(permutation, search + 1);
//             }
//         } while (next_permutation(words.begin(), words.end()));

//         return result;
//     }
// };
