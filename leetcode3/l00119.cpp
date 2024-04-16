class Solution {
public:
    vector<int> getRow(int rowIndex) {
        return generate(rowIndex+1)[rowIndex];
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        for(int i = 1; i<numRows; i++){
            vector<int> curr(i+1, 1);
            for(int j = 1; j < i; j++){
                curr[j] = res[i-1][j-1] + res[i-1][j];
            }
            res.push_back(curr);
        }

        return res;
    }
};