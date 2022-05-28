/*solution from [https://blog.lichangao.com/daily_practice/leetcode/overview/question_summary.html]*/
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ex[9];
        for(int i = 0; i<9; i++)
        {
            memset(ex, 0, sizeof(ex));
            for(int j = 0; j<9; j++)
            {
                if(board[i][j] == '.') continue;
                int t = board[i][j] - '1';
                if(ex[t]) return false;
                ex[t] = true;
            }
        }

        for(int i = 0; i<9; i++)
        {
            memset(ex, 0, sizeof(ex));
            for(int j = 0; j<9; j++)
            {
                if(board[j][i] == '.') continue;
                int t = board[j][i] - '1';
                if(ex[t]) return false;
                ex[t] = true;
            }
        }

        for(int i = 0; i<9; i+=3)
        {
            for(int j = 0; j<9; j+=3)
            {
                memset(ex, 0, sizeof(ex));
                for(int x = 0; x<3; x++)
                {
                    for(int y = 0; y<3; y++)
                    {
                        if(board[i+x][j+y] == '.') continue;
                        int t = board[i+x][j+y] - '1';
                        if(ex[t]) return false;
                        ex[t] = true;
                    }
                }
            }
        }
        return true;
    }
};

int main(int argc, char *argv[])
{
    vector<vector<char>> board = {                     \
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
    };

    Solution solution = Solution();
    bool result = solution.isValidSudoku(board);
    if(result)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    return 0;
}