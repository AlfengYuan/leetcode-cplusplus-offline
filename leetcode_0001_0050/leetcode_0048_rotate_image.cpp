#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size() / 2; i++)
        {
            vector<int> tmp;
            int row = matrix.size() - i;
            int col = i;
            
            while(row > i)
            {
                tmp.push_back(matrix[--row][col]);
            }

            while(col < matrix.size() - i -1)
            {
                tmp.push_back(matrix[row][++col]);
            }

            while(row < matrix.size() - i -1)
            {
                tmp.push_back(matrix[++row][col]);
            }

            while(col > i)
            {
                tmp.push_back(matrix[row][--col]);
            }

            row = i, col = i;
            vector<int>::iterator iter = tmp.begin();
            while(col < matrix.size() - i)
            {
                matrix[row][col++] = *iter++;
            }

            col--;
            while(row < matrix.size() - i -1)
            {
                matrix[++row][col] = *iter++;
            }

            while(col > i)
            {
                matrix[row][--col] = *iter++;
            }

            while(row > i)
            {
                matrix[--row][col] = *iter++;
            }

            tmp.clear();
        }
    }
};

int main(int argc, char *argv[])
{
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    Solution solution = Solution();
    solution.rotate(matrix); 

    cout << "[";
    for(int i = 0 ; i<matrix.size(); i++)
    {
        cout << "[";
        for(int j = 0; j<matrix[i].size(); j++)
        {
            cout << matrix[i][j] << ", ";
        }
        cout << "], ";
    }
    cout << "]" << endl;
    return 0;
}