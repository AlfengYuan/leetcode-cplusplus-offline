class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows(matrix.size(), 0);
        vector<int> cols(matrix[0].size(), 0);
        for(int i = 0; i<rows.size(); i++)
        {
            for(int j = 0; j<cols.size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }

        for(int i = 0; i<rows.size(); i++)
        {
            for(int j = 0; j<cols.size(); j++)
            {
                if(rows[i] || cols[j]) matrix[i][j] = 0;
            }
        }
    }

};