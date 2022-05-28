/*solution from [https://blog.lichangao.com/daily_practice/leetcode/overview/question_summary.html]*/
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
    bool rows[9][9], cols[9][9], cells[3][3][9];
public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(cells, 0, sizeof(cells));

        for(int i = 0; i<9; i++)
        {
            for(int j = 0; j<9; j++)
            {
                if(board[i][j] == '.') continue;
                int t = board[i][j] - '1';
                rows[i][t] = cols[j][t] = cells[i / 3][j / 3][t] = true;
            }
        }

        dfs(board, 0, 0);
    }

    bool dfs(vector<vector<char>> &board, int x, int y)
    {
        if(y == 9) x++, y = 0;
        if(x == 9) return true;
        if(board[x][y] != '.') return dfs(board, x, y+1);

        for(int i = 0; i<9; i++)
        {
            if(rows[x][i] || cols[y][i] || cells[x/3][y/3][i]) continue;
            board[x][y] = i + '1';
            rows[x][i] = cols[y][i] = cells[x/3][y/3][i] = true;
            
            if(dfs(board, x, y+1)) return true;

            rows[x][i] = cols[y][i] = cells[x/3][y/3][i] = false;
            board[x][y] = '.';
        }
        return false;
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
    solution.solveSudoku(board);
    cout << "[";
    for(int i = 0; i<9; i++)
    {
        cout << "["; 
        for(int j = 0; j<9; j++)
        {
            cout << board[i][j] << ", ";
        }
        cout << "]," << endl;;
    }
    cout << "]";
    return 0;
}