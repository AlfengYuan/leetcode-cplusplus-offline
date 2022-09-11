class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int left = 0, right = matrix.size()-1;
        int rows = matrix.size(), cols = matrix[0].size();
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(matrix[mid][0] < target && matrix[mid][cols-1] > target)
            {
                int col_left = 0, col_right = cols - 1;
                while(col_left <= col_right)
                {
                    int col_mid = (col_left + col_right) / 2;
                    if(matrix[mid][col_mid] == target)
                    {
                        return true;
                    }
                    else if(matrix[mid][col_mid] < target)
                    {
                        col_left = col_mid + 1;
                    }
                    else
                    {
                        col_right = col_mid - 1;
                    }
                }
                return false;
            }
            else if(matrix[mid][0] == target || matrix[mid][cols-1] == target)
            {
                return true;
            }
            else if(matrix[mid][0] > target)
            {
                right = mid -1;
            }
            else if(matrix[mid][cols-1] < target)
            {
                left = mid + 1;
            }
        }

        return false;

    }
};