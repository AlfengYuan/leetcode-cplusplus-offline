class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int end = 0;
        for(int i = 0; i<nums.size()-1; i++){
            if(i <= end){
                end = max(end, i + nums[i]);
                if(end >= nums.size()-1) return true;
            }else{
                return false;
            }
        }

        return false;
    }
};