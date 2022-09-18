class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows == 0) return result;
        result.push_back({1});
        if(numRows == 1) return result;
        result.push_back({1, 1});
        if(numRows == 2) return result;
        for(int i = 2; i<numRows; i++)
        {
            vector<int> tmp(i+1, 1);
            for(int j = 1; j<i; j++ )
            {
                tmp[j] = result[i-1][j-1] + result[i-1][j];
            }
            result.push_back(tmp);
        }
        return result;
    }
};