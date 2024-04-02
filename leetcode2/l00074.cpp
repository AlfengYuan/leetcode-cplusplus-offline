class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m-1;
        while(left < right){
            int mid = (left + right) / 2;
            if(matrix[mid][n-1] == target){
                return true;
            }else if(matrix[mid][n-1] > target){
                right = mid;
            }else{
                left = mid + 1;
            }
        }

        int ll = 0, lr = n-1;
        while(ll < lr){
            int mid = (ll + lr) / 2;
            if(matrix[left][mid] == target){
                return true;
            }else if(matrix[left][mid] > target){
                lr = mid;
            }else{
                ll = mid + 1;
            }
        }
        if(ll==lr && matrix[left][ll] == target) return true;


        return false;
    }
};