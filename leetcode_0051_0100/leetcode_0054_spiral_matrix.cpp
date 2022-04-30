#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int height = matrix.size();
        int width = matrix[0].size();
        int circle = min(width, height);
        for(int i = 0; i<circle / 2; ++i)
        {
            int row = i;
            int col = i;

            while(col < matrix[row].size() - i)
            {
                res.push_back(matrix[row][col++]);
            }
            col--;

            while(row < matrix.size() - i -1)
            {
                res.push_back(matrix[++row][col]);
            }

            while(col > i)
            {
                res.push_back(matrix[row][--col]);
            }

            while(row > i+1)
            {
                res.push_back(matrix[--row][col]);
            }
        }

        if(circle % 2 != 0)
        {
            int row = circle / 2, col = circle / 2, i = circle / 2;
            if(width > height)
            {
                while(col < matrix[row].size() - i)
                {
                    res.push_back(matrix[row][col++]);
                }
            }
            else
            {
                while(row < matrix.size() - i)
                {
                    res.push_back(matrix[row++][col]);
                }

            }
        }

        return res;

    }
};

int main(int argc, char *argv[])
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution solution = Solution();
    vector<int> res = solution.spiralOrder(matrix);
    cout << "[";
    for(int &i: res)
    {
        cout << i << ", ";
    }
    cout << "]" << endl;
    return 0;
}
            
            