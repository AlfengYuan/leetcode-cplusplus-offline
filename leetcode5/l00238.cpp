class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size(), 1);
        vector<int> suf(nums.size(), 1);
        for(int i = 1; i<nums.size(); i++){
            pre[i] = pre[i-1] * nums[i-1];
        }

        for(int j = suf.size()-2; j>=0; j--){
            suf[j] = suf[j+1] * nums[j+1];
        }

        for(int i = 0; i<nums.size(); i++){
            nums[i] = pre[i] * suf[i];
        }

        return nums;

    }
};