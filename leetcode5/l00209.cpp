class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int sum = 0;
        int res = nums.size()+1;
        while(right <= nums.size()){
            if(sum >= target){
                res = min(res, right-left);
                sum -= nums[left++];
            }else if(sum < target){
                if(right==nums.size()) break;
                sum += nums[right++];
            } 
        }

        if(res > nums.size()) return 0;
        return res;

    }
};