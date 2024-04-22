class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        else if(nums.size() == 2) return max(nums[0], nums[1]);
        else{
            vector<int> f(nums.size(), 0);
            f[0] = nums[0];
            f[1] = max(nums[0], nums[1]);
            for(int i = 2; i<nums.size(); i++){
                f[i] = max(f[i-2] + nums[i], f[i-1]);
            }
            return f[nums.size()-1];
        }

        return -1;;

    }
};