class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<int> temp;
        for(int col = 0; col < matrix[0].size(); col++){
            for(int row = matrix.size()-1; row >= 0; row--){
                temp.push_back(matrix[row][col]);
            }
        }

        int i = 0;
        for(int row = 0; row < matrix.size(); row++){
            for(int col = 0; col < matrix[row].size(); col++){
                matrix[row][col] = temp[i++];
            }
        }
    }
};