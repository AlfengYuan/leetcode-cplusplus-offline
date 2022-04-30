#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int iter = 1;
        for(int i = 0; i<n/2; ++i)
        {
            int row = i, col = i;
            while(col < n - i)
            {
                res[row][col++] = iter++;
            }

            col--;
            while(row < n - i -1)
            {
                res[++row][col] = iter++;
            }

            while(col > i)
            {
                res[row][--col] = iter++;
            }

            while(row > i+1)
            {
                res[--row][col] = iter++;
            }
        }

        if(n % 2 != 0) res[n/2][n/2] = iter;
        
        return res;
    }
};

int main(int argc, char *argv[])
{
    int n = 3;
    Solution solution = Solution();
    vector<vector<int>> res = solution.generateMatrix(3);
    cout << "[";
    for(vector<int> &vec : res)
    {
        cout << "[";
        for(int &i : vec)
        {
            cout << i << ", ";
        }
        cout << "], ";
    }
    cout << "]" << endl;
    return 0;
}