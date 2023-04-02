#include <vector>

using std::vector;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<vector<bool>> lines(9, vector<bool>(9, true));
        vector<vector<bool>> cols(9, vector<bool>(9, true));
        vector<vector<bool>> boxes(9, vector<bool>(9, true));
        for (int i = 0; i < 9; i++)
        {
            const int boxI = i / 3 * 3;
            for (int j = 0; j < 9; j++)
            {
                const auto c = board[i][j];
                if (c == '.')
                    continue;
                const int num = c - '0';
                if (!lines[i][num])
                    return false;
                lines[i][num] = false;
                if (!cols[j][num])
                    return false;
                cols[j][num] = false;
                const int boxIndex = boxI + j / 3;
                if (!boxes[boxIndex][num])
                    return false;
                boxes[boxIndex][num] = false;
            }
        }
        return true;
    }
};