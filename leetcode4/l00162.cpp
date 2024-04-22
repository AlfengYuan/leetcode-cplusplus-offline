class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        int res = 0;
        for(int i = 0; i<nums.size(); i++){
            bool left = (i == 0 ? true: nums[i] > nums[i-1]);
            bool right = (i==nums.size()-1 ? true : nums[i] > nums[i+1]);
            if( left && right && nums[i] > nums[res]){
                res = i;
            }
        }
        return res;
    }
};