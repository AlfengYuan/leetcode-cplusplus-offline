// class Solution {
//     int res = INT_MAX;
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         dfs(triangle, 0, 0, 0);
//         return res;
//     }

//     void dfs(vector<vector<int>>& triangle, int i, int j, int sum){
//         if(i == triangle.size()){
//             res = min(res, sum);
//             return;
//         }

//         for(int x = 0; x<=1; x++){
//             int a = i + 1;
//             int b = j + x;
//             dfs(triangle, a, b, sum + triangle[i][j]);
//         }
//     }
// };

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        if(rows==1) return triangle[0][0];
        for(int i = 1; i<triangle.size(); i++){
            for(int j = 0; j < triangle[i].size(); j++){
                if(j > 0 && j < triangle[i].size()-1){
                    triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
                }else if(j==0){
                    triangle[i][j] += triangle[i-1][j];
                }else if(j==triangle[i].size()-1){
                    triangle[i][j] += triangle[i-1][j-1];
                }
            }
        }

        return *min_element(triangle[rows-1].begin(), triangle[rows-1].end());
    }
};