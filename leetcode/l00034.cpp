class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result {-1, -1};
        int left = 0, right = nums.size()-1;
        while(left <= right){
            if(nums[left] == target){
                result[0] = left;
            }
            else{
                left++;
            }

            if(nums[right] == target){
                result[1] = right;
            }else {
                right--;
            }

            if(result[0] != -1 && result[1] != -1) return result;
        }

        return result;

    }
};